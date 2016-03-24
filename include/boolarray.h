/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 */

#ifndef SIMDCompressionAndIntersection_BOOLARRAY_H_
#define SIMDCompressionAndIntersection_BOOLARRAY_H_

#include "common.h"

namespace SIMDCompressionLib {

using namespace std;

static inline int numberOfTrailingZeros(uint64_t x) {
  if (x == 0)
    return 64;
  return __builtin_ctzl(x);
}

class BoolArray {
public:
  vector<uint64_t> buffer;
  size_t sizeinbits;
  BoolArray(const size_t n, const uint64_t initval = 0)
      : buffer(n / 64 + (n % 64 == 0 ? 0 : 1), initval), sizeinbits(n) {}

  BoolArray() : buffer(), sizeinbits(0) {}

  BoolArray(const BoolArray &ba)
      : buffer(ba.buffer), sizeinbits(ba.sizeinbits) {}

  void inplaceIntersect(const BoolArray &other) {
    assert(other.buffer.size() == buffer.size());
    for (size_t i = 0; i < buffer.size(); ++i)
      buffer[i] &= other.buffer[i];
  }

  // this is no faster because the compiler will vectorize
  // inplaceIntersect automagically?
  void SIMDinplaceIntersect(const BoolArray &other) {
    assert(other.buffer.size() == buffer.size());
    __m128i *bin = reinterpret_cast<__m128i *>(buffer.data());
    const __m128i *bo = reinterpret_cast<const __m128i *>(other.buffer.data());
    for (size_t i = 0; i < buffer.size() / 2; ++i) {
      __m128i p1 = MM_LOAD_SI_128(bin + i);
      __m128i p2 = MM_LOAD_SI_128(bo + i);
      __m128i andp1p2 = _mm_and_si128(p1, p2);
      _mm_storeu_si128(bin + i, andp1p2);
    }
    for (size_t i = buffer.size() / 2 * 2; i < buffer.size(); ++i)
      buffer[i] &= other.buffer[i];
  }

  void intersect(const BoolArray &other, BoolArray &output) {
    assert(other.buffer.size() == buffer.size());
    output.buffer.resize(buffer.size());
    for (size_t i = 0; i < buffer.size(); ++i)
      output.buffer[i] = buffer[i] & other.buffer[i];
  }

  // this is no faster because the compiler will vectorize
  // intersect automagically?
  void SIMDintersect(const BoolArray &other, BoolArray &output) {
    assert(other.buffer.size() == buffer.size());
    output.buffer.resize(buffer.size());
    const __m128i *bin = reinterpret_cast<const __m128i *>(buffer.data());
    const __m128i *bo = reinterpret_cast<const __m128i *>(other.buffer.data());
    __m128i *bout = reinterpret_cast<__m128i *>(output.buffer.data());

    for (size_t i = 0; i < buffer.size() / 2; ++i) {
      __m128i p1 = MM_LOAD_SI_128(bin + i);
      __m128i p2 = MM_LOAD_SI_128(bo + i);
      __m128i andp1p2 = _mm_and_si128(p1, p2);
      _mm_storeu_si128(bout + i, andp1p2);
    }
    for (size_t i = buffer.size() / 2 * 2; i < buffer.size(); ++i)
      output.buffer[i] = buffer[i] & other.buffer[i];
  }

  void setSizeInBits(const size_t sizeib) { sizeinbits = sizeib; }

  /**
   * Write out this bitmap to a vector as a list of integers corresponding
   * to set bits. The caller should have allocated enough memory.
   */
  void toArray(vector<uint32_t> &ans) {
    uint32_t pos = 0;
    for (uint32_t k = 0; k < buffer.size(); ++k) {
      uint64_t myword = buffer[k];
      while (myword != 0) {
        int ntz = __builtin_ctzl(myword);
        ans[pos++] = k * 64 + ntz;
        myword ^= (1ll << ntz);
      }
    }
    ans.resize(pos);
  }

  /**
   * This is a version of toArray where we write to a pointer.
   * Returns the number of written ints.
   */
  size_t toInts(uint32_t *out) {
    size_t pos = 0;
    for (uint32_t k = 0; k < buffer.size(); ++k) {
      const uint64_t myword = buffer[k];
      for (int offset = 0; offset < 64; ++offset) {
        if ((myword >> offset) == 0)
          break;
        offset += numberOfTrailingZeros((myword >> offset));
        out[pos++] = 64 * k + offset;
      }
    }
    return pos;
  }
  BoolArray &operator=(const BoolArray &x) {
    this->buffer = x.buffer;
    this->sizeinbits = x.sizeinbits;
    return *this;
  }

  /**
   * set to true (whether it was already set to true or not)
   *
   * This is an expensive (random access) API, you really ought to
   * prepare a new word and then append it.
   */
  ALWAYS_INLINE
  void set(const size_t pos) {
    buffer[pos / 64] |= (static_cast<uint64_t>(1) << (pos % 64));
  }

  /**
   * set to false (whether it was already set to false or not)
   *
   * This is an expensive (random access) API, you really ought to
   * prepare a new word and then append it.
   */
  ALWAYS_INLINE
  void unset(const size_t pos) {
    buffer[pos / 64] |= ~(static_cast<uint64_t>(1) << (pos % 64));
  }

  /**
   * true of false? (set or unset)
   */
  ALWAYS_INLINE
  bool get(const size_t pos) const {
    return (buffer[pos / 64] & (static_cast<uint64_t>(1) << (pos % 64))) != 0;
  }

  /**
   * set all bits to 0
   */
  void reset() {
    memset(buffer.data(), 0,
           sizeof(uint64_t) *
               buffer.size()); // memset can be slow, does it matter?
    sizeinbits = 0;
  }

  size_t sizeInBits() const { return sizeinbits; }

  size_t sizeInBytes() const { return buffer.size() * sizeof(uint64_t); }

  /**
   * Return memory usage of a bitmap spanning n bits
   */
  static size_t sizeInBytes(size_t n) {
    size_t buffersize = n / 64 + (n % 64 == 0 ? 0 : 1);
    return buffersize * sizeof(uint64_t);
  }

  ~BoolArray() {}
};

} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_BOOLARRAY_H_ */
