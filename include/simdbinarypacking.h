/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef SIMDCompressionAndIntersection_SIMDBINARYPACKING_H_
#define SIMDCompressionAndIntersection_SIMDBINARYPACKING_H_

#include "codecs.h"
#include "simdbitpackinghelpers.h"
#include "util.h"

namespace SIMDCompressionLib {

extern "C" {

/* searches "bit" 128-bit vectors from "in" (= 128 encoded integers) for the
* first encoded uint32 value
 * which is >= |key|, and returns its position. It is assumed that the values
 * stored are in sorted order.
 * The encoded key is stored in "*presult". If no value is larger or equal to
* the key,
* 128 is returned */
int simdsearchd1(__m128i *initOffset, const __m128i *in, uint32_t bit,
                 uint32_t key, uint32_t *presult);

/**
 * Simply scan, updating initOffset as it proceeds.
 */
void simdscand1(__m128i *initOffset, const __m128i *in, uint32_t bit);

/* returns the value stored at the specified "slot". */
uint32_t simdselectd1(__m128i *initOffset, const __m128i *in, uint32_t bit,
                      int slot);
}

template <class DeltaHelper, bool ArrayDispatch> struct SIMDBlockPacker {
  typedef SIMDDeltaProcessor<DeltaHelper, SIMDBlockSize> DeltaProcessor;
  static void unpackblock(const uint32_t *in, uint32_t *out, const uint32_t bit,
                          __m128i &initoffset) {
    if (ArrayDispatch)
      ArrayDispatch::SIMDunpack(reinterpret_cast<const __m128i *>(in), out,
                                bit);
    else
      simdunpack(reinterpret_cast<const __m128i *>(in), out, bit);
    if (bit < 32) {
      initoffset = DeltaProcessor::runPrefixSum(initoffset, out);
    } else {
      initoffset =
          MM_LOAD_SI_128(reinterpret_cast<__m128i *>(out + SIMDBlockSize - 4));
    }
  }

  static uint32_t maxbits(const uint32_t *in, __m128i &initoffset) {
    const __m128i *pin = reinterpret_cast<const __m128i *>(in);
    __m128i newvec = MM_LOAD_SI_128(pin);
    __m128i accumulator = DeltaHelper::Delta(newvec, initoffset);
    __m128i oldvec = newvec;
    for (uint32_t k = 1; 4 * k < SIMDBlockSize; ++k) {
      newvec = MM_LOAD_SI_128(pin + k);
      accumulator =
          _mm_or_si128(accumulator, DeltaHelper::Delta(newvec, oldvec));
      oldvec = newvec;
    }
    initoffset = oldvec;
    return maxbitas32int(accumulator);
  }

  static void packblockwithoutmask(uint32_t *in, uint32_t *out,
                                   const uint32_t bit, __m128i &initoffset) {
    __m128i nextoffset =
        MM_LOAD_SI_128(reinterpret_cast<__m128i *>(in + SIMDBlockSize - 4));
    if (bit < 32)
      DeltaProcessor::runDelta(initoffset, in);
    if (ArrayDispatch)
      ArrayDispatch::SIMDpackwithoutmask(in, reinterpret_cast<__m128i *>(out),
                                         bit);
    else
      simdpackwithoutmask(in, reinterpret_cast<__m128i *>(out), bit);
    initoffset = nextoffset;
  }

  static string name() {
    if (ArrayDispatch)
      return string("SIMDBlockPackerAD+") + DeltaHelper::name();
    else
      return string("SIMDBlockPacker+") + DeltaHelper::name();
  }
};

template <class DeltaHelper, bool ArrayDispatch = true>
struct SIMDIntegratedBlockPacker {

  static void unpackblock(const uint32_t *in, uint32_t *out, const uint32_t bit,
                          __m128i &initoffset) {
    if (ArrayDispatch)
      initoffset = IntegratedArrayDispatch<DeltaHelper>::SIMDiunpack(
          initoffset, reinterpret_cast<const __m128i *>(in), out, bit);
    else
      initoffset = SIMDiunpack<DeltaHelper>(
          initoffset, reinterpret_cast<const __m128i *>(in), out, bit);
  }

  static uint32_t maxbits(const uint32_t *in, __m128i &initoffset) {
    const __m128i *pin = reinterpret_cast<const __m128i *>(in);
    __m128i newvec = MM_LOAD_SI_128(pin);
    __m128i accumulator = DeltaHelper::Delta(newvec, initoffset);
    __m128i oldvec = newvec;
    for (uint32_t k = 1; 4 * k < SIMDBlockSize; ++k) {
      newvec = MM_LOAD_SI_128(pin + k);
      accumulator =
          _mm_or_si128(accumulator, DeltaHelper::Delta(newvec, oldvec));
      oldvec = newvec;
    }
    initoffset = oldvec;
    return maxbitas32int(accumulator);
  }

  static void packblockwithoutmask(uint32_t *in, uint32_t *out,
                                   const uint32_t bit, __m128i &initoffset) {
    __m128i nextoffset =
        MM_LOAD_SI_128(reinterpret_cast<__m128i *>(in + SIMDBlockSize - 4));
    if (ArrayDispatch)
      IntegratedArrayDispatch<DeltaHelper>::SIMDipackwithoutmask(
          initoffset, in, reinterpret_cast<__m128i *>(out), bit);
    else
      SIMDipackwithoutmask<DeltaHelper>(initoffset, in,
                                        reinterpret_cast<__m128i *>(out), bit);
    initoffset = nextoffset;
  }

  static string name() {
    if (ArrayDispatch)
      return string("SIMDIntegratedBlockPackerAD+") + DeltaHelper::name();
    else
      return string("SIMDIntegratedBlockPacker+") + DeltaHelper::name();
  }
};

/**
 *
 *
 * Code data in miniblocks of 128 integers.
 * To preserve alignment, we regroup
 * 8 such miniblocks into a block of 8 * 128 = 1024
 * integers.
 *
 */
template <class BlockPacker> class SIMDBinaryPacking : public IntegerCODEC {
public:
#ifdef USE_ALIGNED
  static const uint32_t CookiePadder = 123456; // just some made up number
#endif
  static const uint32_t MiniBlockSize = 128;
  static const uint32_t HowManyMiniBlocks = 16;
  static const uint32_t BlockSize =
      MiniBlockSize; // HowManyMiniBlocks * MiniBlockSize;

  void encodeArray(uint32_t *in, const size_t length, uint32_t *out,
                   size_t &nvalue) {
    checkifdivisibleby(length, BlockSize);
    const uint32_t *const initout(out);
#ifdef USE_ALIGNED
    if (needPaddingTo128Bits(out) or needPaddingTo128Bits(in))
      throw std::runtime_error(
          "alignment issue: pointers should be aligned on 128-bit boundaries");
#endif
    *out++ = static_cast<uint32_t>(length);
#ifdef USE_ALIGNED
    while (needPaddingTo128Bits(out))
      *out++ = CookiePadder;
#endif
    uint32_t Bs[HowManyMiniBlocks];
    __m128i init = _mm_set1_epi32(0);
    const uint32_t *const final = in + length;
    for (; in + HowManyMiniBlocks * MiniBlockSize <= final;
         in += HowManyMiniBlocks * MiniBlockSize) {
      __m128i tmpinit = init;
      for (uint32_t i = 0; i < HowManyMiniBlocks; ++i) {
        Bs[i] = BlockPacker::maxbits(in + i * MiniBlockSize, tmpinit);
      }
      *out++ = (Bs[0] << 24) | (Bs[1] << 16) | (Bs[2] << 8) | Bs[3];
      *out++ = (Bs[4] << 24) | (Bs[5] << 16) | (Bs[6] << 8) | Bs[7];
      *out++ = (Bs[8] << 24) | (Bs[9] << 16) | (Bs[10] << 8) | Bs[11];
      *out++ = (Bs[12] << 24) | (Bs[13] << 16) | (Bs[14] << 8) | Bs[15];
      for (uint32_t i = 0; i < HowManyMiniBlocks; ++i) {
        BlockPacker::packblockwithoutmask(in + i * MiniBlockSize, out, Bs[i],
                                          init);
        out += MiniBlockSize / 32 * Bs[i];
      }
    }
    if (in < final) {
      const size_t howmany = (final - in) / MiniBlockSize;
      __m128i tmpinit = init;
      memset(&Bs[0], 0, HowManyMiniBlocks * sizeof(uint32_t));
      for (uint32_t i = 0; i < howmany; ++i) {
        Bs[i] = BlockPacker::maxbits(in + i * MiniBlockSize, tmpinit);
      }
      *out++ = (Bs[0] << 24) | (Bs[1] << 16) | (Bs[2] << 8) | Bs[3];
      *out++ = (Bs[4] << 24) | (Bs[5] << 16) | (Bs[6] << 8) | Bs[7];
      *out++ = (Bs[8] << 24) | (Bs[9] << 16) | (Bs[10] << 8) | Bs[11];
      *out++ = (Bs[12] << 24) | (Bs[13] << 16) | (Bs[14] << 8) | Bs[15];
      for (uint32_t i = 0; i < howmany; ++i) {
        BlockPacker::packblockwithoutmask(in + i * MiniBlockSize, out, Bs[i],
                                          init);
        out += MiniBlockSize / 32 * Bs[i];
      }
      in += howmany * MiniBlockSize;
      assert(in == final);
    }
    nvalue = out - initout;
  }

  const uint32_t *decodeArray(const uint32_t *in, const size_t /*length*/,
                              uint32_t *out, size_t &nvalue) {
#ifdef USE_ALIGNED
    if (needPaddingTo128Bits(out) or needPaddingTo128Bits(in))
      throw std::runtime_error(
          "alignment issue: pointers should be aligned on 128-bit boundaries");
#endif
    const uint32_t actuallength = *in++;
#ifdef USE_ALIGNED
    while (needPaddingTo128Bits(in)) {
      if (in[0] != CookiePadder)
        throw logic_error("SIMDBinaryPacking alignment issue.");
      ++in;
    }
#endif
    const uint32_t *const initout(out);
    uint32_t Bs[HowManyMiniBlocks];
    __m128i init = _mm_set1_epi32(0);
    for (; out < initout +
                     actuallength / (HowManyMiniBlocks * MiniBlockSize) *
                         HowManyMiniBlocks * MiniBlockSize;
         out += HowManyMiniBlocks * MiniBlockSize) {
      for (uint32_t i = 0; i < 4; ++i, ++in) {
        Bs[0 + 4 * i] = static_cast<uint8_t>(in[0] >> 24);
        Bs[1 + 4 * i] = static_cast<uint8_t>(in[0] >> 16);
        Bs[2 + 4 * i] = static_cast<uint8_t>(in[0] >> 8);
        Bs[3 + 4 * i] = static_cast<uint8_t>(in[0]);
      }
      for (uint32_t i = 0; i < HowManyMiniBlocks; ++i) {
        BlockPacker::unpackblock(in, out + i * MiniBlockSize, Bs[i], init);
        in += MiniBlockSize / 32 * Bs[i];
      }
    }

    if (out < initout + actuallength) {
      const size_t howmany = (initout + actuallength - out) / MiniBlockSize;
      for (uint32_t i = 0; i < 4; ++i, ++in) {
        Bs[0 + 4 * i] = static_cast<uint8_t>(in[0] >> 24);
        Bs[1 + 4 * i] = static_cast<uint8_t>(in[0] >> 16);
        Bs[2 + 4 * i] = static_cast<uint8_t>(in[0] >> 8);
        Bs[3 + 4 * i] = static_cast<uint8_t>(in[0]);
      }
      for (uint32_t i = 0; i < howmany; ++i) {
        BlockPacker::unpackblock(in, out + i * MiniBlockSize, Bs[i], init);
        in += MiniBlockSize / 32 * Bs[i];
      }
      out += howmany * MiniBlockSize;
      assert(out == initout + actuallength);
    }
    nvalue = out - initout;
    return in;
  }

  // Returns a decompressed value in an encoded array
  // could be greatly optimized in the non-differential coding case: currently
  // just for delta coding
  // WARNING: THIS IMPLEMENTATION WILL ONLY PROVIDE THE CORRECT RESULT
  // WHEN USING REGULAR (D1) DIFFERENTIAL CODING.	 TODO: Generalize the
  // support. TODO: Should check the type.
  uint32_t select(uint32_t *in, size_t index) {
#ifdef USE_ALIGNED
    if (needPaddingTo128Bits(in))
      throw std::runtime_error(
          "alignment issue: pointers should be aligned on 128-bit boundaries");
#endif
    const uint32_t actuallength = *in++;
#ifdef USE_ALIGNED
    while (needPaddingTo128Bits(in)) {
      if (in[0] != CookiePadder)
        throw logic_error("SIMDBinaryPacking alignment issue.");
      ++in;
    }
#endif
    uint32_t Bs[HowManyMiniBlocks];
    __m128i init = _mm_set1_epi32(0);
    size_t runningindex = 0;
    for (; runningindex < actuallength / (HowManyMiniBlocks * MiniBlockSize) *
                              HowManyMiniBlocks * MiniBlockSize;) {
      for (uint32_t i = 0; i < 4; ++i, ++in) {
        Bs[0 + 4 * i] = static_cast<uint8_t>(in[0] >> 24);
        Bs[1 + 4 * i] = static_cast<uint8_t>(in[0] >> 16);
        Bs[2 + 4 * i] = static_cast<uint8_t>(in[0] >> 8);
        Bs[3 + 4 * i] = static_cast<uint8_t>(in[0]);
      }
      for (uint32_t i = 0; i < HowManyMiniBlocks; ++i) {
        if (runningindex + 128 > index) {
          return simdselectd1(&init, (const __m128i *)in, Bs[i],
                              static_cast<int>(index - runningindex));
        }
        simdscand1(&init, (const __m128i *)in, Bs[i]);
        runningindex += MiniBlockSize;
        in += MiniBlockSize / 32 * Bs[i];
      }
    }

    if (runningindex < actuallength) {
      const size_t howmany = (actuallength - runningindex) / MiniBlockSize;
      for (uint32_t i = 0; i < 4; ++i, ++in) {
        Bs[0 + 4 * i] = static_cast<uint8_t>(in[0] >> 24);
        Bs[1 + 4 * i] = static_cast<uint8_t>(in[0] >> 16);
        Bs[2 + 4 * i] = static_cast<uint8_t>(in[0] >> 8);
        Bs[3 + 4 * i] = static_cast<uint8_t>(in[0]);
      }
      for (uint32_t i = 0; i < howmany; ++i) {
        if (runningindex + 128 > index) {
          return simdselectd1(&init, (const __m128i *)in, Bs[i],
                              static_cast<int>(index - runningindex));
        }
        simdscand1(&init, (const __m128i *)in, Bs[i]);
        runningindex += MiniBlockSize;
        in += MiniBlockSize / 32 * Bs[i];
      }
    }
    return static_cast<uint32_t>(runningindex);
  }

  // Performs a lower bound find in the encoded array.
  // Returns the index
  // WARNING: THIS IMPLEMENTATION WILL ONLY PROVIDE THE CORRECT RESULT
  // WHEN USING REGULAR (D1) DIFFERENTIAL CODING.	 TODO: Generalize the
  // support. TODO: Should check the type.
  size_t findLowerBound(const uint32_t *in, const size_t /*length*/,
                        uint32_t key, uint32_t *presult) {
#ifdef USE_ALIGNED
    if (needPaddingTo128Bits(in))
      throw std::runtime_error(
          "alignment issue: pointers should be aligned on 128-bit boundaries");
#endif
    const uint32_t actuallength = *in++;
#ifdef USE_ALIGNED
    while (needPaddingTo128Bits(in)) {
      if (in[0] != CookiePadder)
        throw logic_error("SIMDBinaryPacking alignment issue.");
      ++in;
    }
#endif
    uint32_t Bs[HowManyMiniBlocks];
    __m128i init = _mm_set1_epi32(0);
    size_t runningindex = 0;
    for (; runningindex < actuallength / (HowManyMiniBlocks * MiniBlockSize) *
                              HowManyMiniBlocks * MiniBlockSize;) {
      for (uint32_t i = 0; i < 4; ++i, ++in) {
        Bs[0 + 4 * i] = static_cast<uint8_t>(in[0] >> 24);
        Bs[1 + 4 * i] = static_cast<uint8_t>(in[0] >> 16);
        Bs[2 + 4 * i] = static_cast<uint8_t>(in[0] >> 8);
        Bs[3 + 4 * i] = static_cast<uint8_t>(in[0]);
      }
      for (uint32_t i = 0; i < HowManyMiniBlocks; ++i) {
        size_t index =
            simdsearchd1(&init, (const __m128i *)in, Bs[i], key, presult);
        runningindex += index;
        if (index < MiniBlockSize)
          return runningindex;
        in += MiniBlockSize / 32 * Bs[i];
      }
    }

    if (runningindex < actuallength) {
      const size_t howmany = (actuallength - runningindex) / MiniBlockSize;
      for (uint32_t i = 0; i < 4; ++i, ++in) {
        Bs[0 + 4 * i] = static_cast<uint8_t>(in[0] >> 24);
        Bs[1 + 4 * i] = static_cast<uint8_t>(in[0] >> 16);
        Bs[2 + 4 * i] = static_cast<uint8_t>(in[0] >> 8);
        Bs[3 + 4 * i] = static_cast<uint8_t>(in[0]);
      }
      for (uint32_t i = 0; i < howmany; ++i) {
        size_t index =
            simdsearchd1(&init, (const __m128i *)in, Bs[i], key, presult);
        runningindex += index;
        if (index < MiniBlockSize)
          return runningindex;
        in += MiniBlockSize / 32 * Bs[i];
      }
    }
    return runningindex;
  }

  string name() const {
    ostringstream convert;
    convert << "SIMDBinaryPacking"
            << "With" << BlockPacker::name() << MiniBlockSize;
    return convert.str();
  }
};

} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_SIMDBINARYPACKING_H_ */
