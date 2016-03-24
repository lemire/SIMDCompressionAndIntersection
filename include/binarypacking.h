/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef SIMDCompressionAndIntersection_BINARYPACKING_H_
#define SIMDCompressionAndIntersection_BINARYPACKING_H_

#include "codecs.h"
#include "bitpackinghelpers.h"
#include "util.h"

namespace SIMDCompressionLib {

struct BasicBlockPacker {
  static void inline unpackblock(const uint32_t *in, uint32_t *out,
                                 const uint32_t bit, uint32_t &initoffset) {
    BitPackingHelpers::fastunpack(in, out, bit);
    if (bit < 32)
      inverseDelta<BitPackingHelpers::BlockSize>(initoffset, out);
    initoffset = *(out + BitPackingHelpers::BlockSize - 1);
  }

  static uint32_t maxbits(const uint32_t *in, uint32_t &initoffset) {
    uint32_t accumulator = in[0] - initoffset;
    for (uint32_t k = 1; k < BitPackingHelpers::BlockSize; ++k) {
      accumulator |= in[k] - in[k - 1];
    }
    initoffset = in[BitPackingHelpers::BlockSize - 1];
    return gccbits(accumulator);
  }

  static void inline packblockwithoutmask(uint32_t *in, uint32_t *out,
                                          const uint32_t bit,
                                          uint32_t &initoffset) {
    const uint32_t nextoffset = *(in + BitPackingHelpers::BlockSize - 1);
    if (bit < 32)
      delta<BitPackingHelpers::BlockSize>(initoffset, in);
    BitPackingHelpers::fastpackwithoutmask(in, out, bit);
    initoffset = nextoffset;
  }
  static string name() { return "BasicBlockPacker"; }
};

struct NoDeltaBlockPacker {
  static void inline unpackblock(const uint32_t *in, uint32_t *out,
                                 const uint32_t bit, uint32_t &) {
    BitPackingHelpers::fastunpack(in, out, bit);
  }
  static void inline packblockwithoutmask(uint32_t *in, uint32_t *out,
                                          const uint32_t bit, uint32_t &) {
    BitPackingHelpers::fastpackwithoutmask(in, out, bit);
  }

  static uint32_t maxbits(const uint32_t *in, uint32_t &) {
    uint32_t accumulator = 0;
    for (uint32_t k = 0; k < BitPackingHelpers::BlockSize; ++k) {
      accumulator |= in[k];
    }
    return gccbits(accumulator);
  }

  static string name() { return "NoDeltaBlockPacker"; }
};

struct IntegratedBlockPacker {
  PURE_FUNCTION
  static uint32_t maxbits(const uint32_t *in, uint32_t &initoffset) {
    uint32_t accumulator = in[0] - initoffset;
    for (uint32_t k = 1; k < BitPackingHelpers::BlockSize; ++k) {
      accumulator |= in[k] - in[k - 1];
    }
    initoffset = in[BitPackingHelpers::BlockSize - 1];
    return gccbits(accumulator);
  }

  static void inline packblockwithoutmask(const uint32_t *in, uint32_t *out,
                                          const uint32_t bit,
                                          uint32_t &initoffset) {
    BitPackingHelpers::integratedfastpackwithoutmask(initoffset, in, out, bit);
    initoffset = *(in + BitPackingHelpers::BlockSize - 1);
  }
  static void inline unpackblock(const uint32_t *in, uint32_t *out,
                                 const uint32_t bit, uint32_t &initoffset) {
    BitPackingHelpers::integratedfastunpack(initoffset, in, out, bit);
    initoffset = *(out + BitPackingHelpers::BlockSize - 1);
  }
  static string name() { return "IntegratedBlockPacker"; }
};

template <class BlockPacker> class BinaryPacking : public IntegerCODEC {
public:
  static const uint32_t MiniBlockSize = 32;
  static const uint32_t HowManyMiniBlocks = 4;
  static const uint32_t BlockSize =
      MiniBlockSize; // HowManyMiniBlocks * MiniBlockSize;
  static const uint32_t bits32 = 8;

  void encodeArray(uint32_t *in, const size_t length, uint32_t *out,
                   size_t &nvalue) {
    checkifdivisibleby(length, BlockSize);
    const uint32_t *const initout(out);
    *out++ = static_cast<uint32_t>(length);
    uint32_t Bs[HowManyMiniBlocks];
    uint32_t init = 0;
    const uint32_t *const final = in + length;
    for (; in + HowManyMiniBlocks * MiniBlockSize <= final;
         in += HowManyMiniBlocks * MiniBlockSize) {
      uint32_t tmpinit = init;
      for (uint32_t i = 0; i < HowManyMiniBlocks; ++i) {
        Bs[i] = BlockPacker::maxbits(in + i * MiniBlockSize, tmpinit);
      }
      *out++ = (Bs[0] << 24) | (Bs[1] << 16) | (Bs[2] << 8) | Bs[3];
      for (uint32_t i = 0; i < HowManyMiniBlocks; ++i) {
        BlockPacker::packblockwithoutmask(in + i * MiniBlockSize, out, Bs[i],
                                          init);
        out += Bs[i];
      }
    }
    if (in < final) {
      size_t howmany = (final - in) / MiniBlockSize;
      uint32_t tmpinit = init;
      memset(&Bs[0], 0, HowManyMiniBlocks * sizeof(uint32_t));
      for (uint32_t i = 0; i < howmany; ++i) {
        Bs[i] = BlockPacker::maxbits(in + i * MiniBlockSize, tmpinit);
      }
      *out++ = (Bs[0] << 24) | (Bs[1] << 16) | (Bs[2] << 8) | Bs[3];
      for (uint32_t i = 0; i < howmany; ++i) {
        BlockPacker::packblockwithoutmask(in + i * MiniBlockSize, out, Bs[i],
                                          init);
        out += Bs[i];
      }
    }
    nvalue = out - initout;
  }

  const uint32_t *decodeArray(const uint32_t *in, const size_t /*length*/,
                              uint32_t *out, size_t &nvalue) {
    const uint32_t actuallength = *in++;
    checkifdivisibleby(actuallength, BlockSize);
    const uint32_t *const initout(out);
    uint32_t Bs[HowManyMiniBlocks];
    uint32_t init = 0;
    for (; out < initout +
                     actuallength / (HowManyMiniBlocks * MiniBlockSize) *
                         HowManyMiniBlocks * MiniBlockSize;
         out += HowManyMiniBlocks * MiniBlockSize) {
      Bs[0] = static_cast<uint8_t>(in[0] >> 24);
      Bs[1] = static_cast<uint8_t>(in[0] >> 16);
      Bs[2] = static_cast<uint8_t>(in[0] >> 8);
      Bs[3] = static_cast<uint8_t>(in[0]);
      ++in;
      for (uint32_t i = 0; i < HowManyMiniBlocks; ++i) {
        BlockPacker::unpackblock(in, out + i * MiniBlockSize, Bs[i], init);
        in += Bs[i];
      }
    }
    if (out < initout + actuallength) {
      size_t howmany = (initout + actuallength - out) / MiniBlockSize;
      Bs[0] = static_cast<uint8_t>(in[0] >> 24);
      Bs[1] = static_cast<uint8_t>(in[0] >> 16);
      Bs[2] = static_cast<uint8_t>(in[0] >> 8);
      Bs[3] = static_cast<uint8_t>(in[0]);
      ++in;
      for (uint32_t i = 0; i < howmany; ++i) {
        BlockPacker::unpackblock(in, out + i * MiniBlockSize, Bs[i], init);
        in += Bs[i];
      }
      out += howmany * MiniBlockSize;
    }
    nvalue = out - initout;
    return in;
  }

  string name() const {
    ostringstream convert;
    convert << "BinaryPacking"
            << "With" << BlockPacker::name() << MiniBlockSize;
    return convert.str();
  }
};

} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_BINARYPACKING_H_ */
