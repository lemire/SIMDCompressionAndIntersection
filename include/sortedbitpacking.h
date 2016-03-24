/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef SIMDCompressionAndIntersection_SORTEDBITPACKING_H_
#define SIMDCompressionAndIntersection_SORTEDBITPACKING_H_

#include "common.h"
#include "simdbitpacking.h"
#include "bitpackinghelpers.h"

namespace SIMDCompressionLib {

template <class T> CONST_FUNCTION static T *padTo128bits(T *inbyte) {
  return reinterpret_cast<T *>((reinterpret_cast<uintptr_t>(inbyte) + 15) &
                               ~15);
}

/**
 * This is a minimalist class that allows you to store data
 * in one of 32 "stores". Each store is for
 * integers having bit width 1, 2..., 32 respectively.
 *
 * Design by D. Lemire
 */
class BasicSortedBitPacker {
public:
  enum { DEFAULTSIZE = 128 }; // should be a multiple of 128
  uint32_t buffer[32];

  static string name() { return "uBSBP"; }

  BasicSortedBitPacker() {
    for (uint32_t i = 0; i < 32; ++i) {
      data[i] = new uint32_t[DEFAULTSIZE];
      memset(data[i], 0, DEFAULTSIZE * sizeof(uint32_t));
      actualsizes[i] = DEFAULTSIZE;
    }
    clear();
  }

  void reset() {
    for (uint32_t i = 0; i < 32; ++i) {
      delete[] data[i];
      data[i] = new uint32_t[DEFAULTSIZE];
      memset(data[i], 0, DEFAULTSIZE * sizeof(uint32_t));
      actualsizes[i] = DEFAULTSIZE;
    }
    clear();
  }

  ~BasicSortedBitPacker() { free(); }
  void free() {
    clear();
    for (uint32_t i = 0; i < 32; ++i)
      if (data[i] != NULL) {
        delete[] data[i];
        data[i] = NULL;
        actualsizes[i] = 0;
      }
  }
  void directAppend(uint32_t i, uint32_t val) { data[i][sizes[i]++] = val; }

  const uint32_t *get(int i) { return data[i]; }

  void ensureCapacity(int i, uint32_t datatoadd) {
    if (sizes[i] + datatoadd > actualsizes[i]) {
      actualsizes[i] = (sizes[i] + datatoadd + 127) / 128 * 128 *
                       2; // so we always get a multiple of 128
      uint32_t *tmp = new uint32_t[actualsizes[i]];
      for (uint32_t j = 0; j < sizes[i]; ++j)
        tmp[j] = data[i][j];
      delete[] data[i];
      data[i] = tmp;
    }
  }

  void clear() {
    for (uint32_t i = 0; i < 32; ++i)
      sizes[i] = 0; // memset "might" be faster.
  }

  uint32_t *write(uint32_t *out) {
    uint32_t bitmap = 0;
    for (uint32_t k = 1; k < 32; ++k) {
      if (sizes[k] != 0)
        bitmap |= (1U << k);
    }
    *(out++) = bitmap;

    for (uint32_t k = 1; k < 32; ++k) {
      if (sizes[k] != 0) {
        *out = sizes[k];
        out++;
        uint32_t j = 0;
        for (; j + 128 <= sizes[k]; j += 128) {
          usimdpackwithoutmask(&data[k][j], reinterpret_cast<__m128i *>(out),
                               k + 1);
          out += 4 * (k + 1);
        }
        // falling back on scalar
        for (; j < sizes[k]; j += 32) {
          BitPackingHelpers::fastpackwithoutmask(&data[k][j], out, k + 1);
          out += k + 1;
        }
        out -= (j - sizes[k]) * (k + 1) / 32;
      }
    }
    return out;
  }
  const uint32_t *read(const uint32_t *in) {
    clear();
    const uint32_t bitmap = *(in++);

    for (uint32_t k = 1; k < 32; ++k) {
      if ((bitmap & (1U << k)) != 0) {
        sizes[k] = *in++;
        if (actualsizes[k] < sizes[k]) {
          delete[] data[k];
          actualsizes[k] = (sizes[k] + 127) / 128 * 128;
          data[k] = new uint32_t[actualsizes[k]];
        }
        uint32_t j = 0;
        for (; j + 128 <= sizes[k]; j += 128) {

          usimdunpack(reinterpret_cast<const __m128i *>(in), &data[k][j],
                      k + 1);
          in += 4 * (k + 1);
        }
        for (; j + 31 < sizes[k]; j += 32) {
          BitPackingHelpers::fastunpack(in, &data[k][j], k + 1);
          in += k + 1;
        }
        uint32_t remaining = sizes[k] - j;
        memcpy(buffer, in, (remaining * (k + 1) + 31) / 32 * sizeof(uint32_t));
        uint32_t *bpointer = buffer;
        in += ((sizes[k] + 31) / 32 * 32 - j) / 32 * (k + 1);
        for (; j < sizes[k]; j += 32) {
          BitPackingHelpers::fastunpack(bpointer, &data[k][j], k + 1);
          bpointer += k + 1;
        }
        in -= (j - sizes[k]) * (k + 1) / 32;
      }
    }
    return in;
  }

  // for debugging
  void sanityCheck() {
    for (uint32_t k = 0; k < 32; ++k) {
      if (sizes[k] > actualsizes[k]) {
        cerr << "overflow at " << k << endl;
        throw runtime_error("bug");
      }
      if (sizes[k] != 0) {
        cout << "k=" << k << endl;
        uint32_t mask = 0u;
        for (uint32_t j = 0; j < sizes[k]; ++j) {
          cout << data[k][j] << " ";
          mask |= data[k][j];
        }
        cout << endl;

        if (gccbits(mask) > k + 1) {
          cerr << "At " << (k + 1) << " we have " << gccbits(mask) << endl;
          throw runtime_error("bug");
        }
      }
    }
  }

  bool equals(const BasicSortedBitPacker &o) {
    for (uint32_t k = 0; k < 32; ++k) {
      if (sizes[k] != o.sizes[k]) {
        return false;
      }
      for (uint32_t j = 0; j < sizes[k]; ++j)
        if (data[k][j] != o.data[k][j]) {
          return false;
        }
    }
    return true;
  }

private:
  uint32_t *data[32];
  uint32_t sizes[32];
  uint32_t actualsizes[32];

  // we don't want anyone to start copying this class
  BasicSortedBitPacker(const BasicSortedBitPacker &);
  BasicSortedBitPacker &operator=(const BasicSortedBitPacker &);
};

} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_SORTEDBITPACKING_H_ */
