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


template <class DeltaHelper, bool ArrayDispatch>
struct SIMDBlockPacker {
    typedef SIMDDeltaProcessor<DeltaHelper, SIMDBlockSize>  DeltaProcessor;
    static void  unpackblock(const uint32_t *in,  uint32_t *out,  const uint32_t bit, __m128i &initoffset) {
        if (ArrayDispatch)
            ArrayDispatch::SIMDunpack(reinterpret_cast<const __m128i *>(in), out, bit);
        else
            simdunpack(reinterpret_cast<const __m128i *>(in), out, bit);
        if (bit < 32) {
            initoffset = DeltaProcessor::runPrefixSum(initoffset, out);
        } else {
            initoffset = _mm_load_si128(reinterpret_cast<__m128i *>(out + SIMDBlockSize - 4));
        }
    }

    static uint32_t maxbits(const uint32_t *in,  __m128i &initoffset) {
        const __m128i *pin = reinterpret_cast<const __m128i *>(in);
        __m128i newvec = _mm_load_si128(pin);
        __m128i accumulator =  DeltaHelper::Delta(newvec , initoffset);
        __m128i oldvec = newvec;
        for (uint32_t k = 1; 4 * k < SIMDBlockSize; ++k) {
            newvec = _mm_load_si128(pin + k);
            accumulator = _mm_or_si128(accumulator, DeltaHelper::Delta(newvec , oldvec));
            oldvec = newvec;
        }
        initoffset = oldvec;
        return maxbitas32int(accumulator);
    }

    static void  packblockwithoutmask(uint32_t *in, uint32_t *out,  const uint32_t bit, __m128i &initoffset) {
        __m128i nextoffset = _mm_load_si128(reinterpret_cast<__m128i *>(in + SIMDBlockSize - 4));
        if (bit < 32)
            DeltaProcessor::runDelta(initoffset, in);
        if (ArrayDispatch)
            ArrayDispatch::SIMDpackwithoutmask(in, reinterpret_cast<__m128i *>(out), bit);
        else
            simdpackwithoutmask(in, reinterpret_cast<__m128i *>(out), bit);
        initoffset = nextoffset;
    }

    static string name()  {
        if (ArrayDispatch)
            return string("SIMDBlockPackerAD+") + DeltaHelper::name();
        else
            return string("SIMDBlockPacker+") + DeltaHelper::name();
    }

};


template <class DeltaHelper, bool ArrayDispatch = true>
struct SIMDIntegratedBlockPacker {

    static void  unpackblock(const uint32_t *in,  uint32_t *out,  const uint32_t bit, __m128i &initoffset) {
        if (ArrayDispatch)
            initoffset = IntegratedArrayDispatch<DeltaHelper>::SIMDiunpack(initoffset, reinterpret_cast<const __m128i *>(in), out,
                         bit);
        else
            initoffset = SIMDiunpack<DeltaHelper>(initoffset, reinterpret_cast<const __m128i *>(in), out, bit);
    }


    static uint32_t maxbits(const uint32_t *in,  __m128i &initoffset) {
        const __m128i *pin = reinterpret_cast<const __m128i *>(in);
        __m128i newvec = _mm_load_si128(pin);
        __m128i accumulator =  DeltaHelper::Delta(newvec , initoffset);
        __m128i oldvec = newvec;
        for (uint32_t k = 1; 4 * k < SIMDBlockSize; ++k) {
            newvec = _mm_load_si128(pin + k);
            accumulator = _mm_or_si128(accumulator, DeltaHelper::Delta(newvec , oldvec));
            oldvec = newvec;
        }
        initoffset = oldvec;
        return maxbitas32int(accumulator);
    }

    static void  packblockwithoutmask(uint32_t *in, uint32_t *out,  const uint32_t bit, __m128i &initoffset) {
        __m128i nextoffset = _mm_load_si128(reinterpret_cast<__m128i *>(in + SIMDBlockSize - 4));
        if (ArrayDispatch)
            IntegratedArrayDispatch<DeltaHelper>::SIMDipackwithoutmask(initoffset, in, reinterpret_cast<__m128i *>(out), bit);
        else
            SIMDipackwithoutmask<DeltaHelper>(initoffset, in, reinterpret_cast<__m128i *>(out), bit);
        initoffset = nextoffset;
    }

    static string name()  {
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
template <class BlockPacker>
class SIMDBinaryPacking: public IntegerCODEC {
public:
    static const uint32_t CookiePadder = 123456;// just some made up number
    static const uint32_t MiniBlockSize = 128;
    static const uint32_t HowManyMiniBlocks = 16;
    static const uint32_t BlockSize = MiniBlockSize;//HowManyMiniBlocks * MiniBlockSize;



    void encodeArray(uint32_t *in, const size_t length, uint32_t *out,
                     size_t &nvalue) {
        checkifdivisibleby(length, BlockSize);
        const uint32_t *const initout(out);
        if (needPaddingTo128Bits(out)
            or needPaddingTo128Bits(in)) throw
            std::runtime_error("alignment issue: pointers should be aligned on 128-bit boundaries");
        *out++ = static_cast<uint32_t>(length);
        while (needPaddingTo128Bits(out)) *out++ = CookiePadder;
        uint32_t Bs[HowManyMiniBlocks];
        __m128i init = _mm_set1_epi32(0);
        const uint32_t *const final = in + length;
        for (; in + HowManyMiniBlocks * MiniBlockSize
             <= final; in += HowManyMiniBlocks * MiniBlockSize) {
            __m128i tmpinit = init;
            for (uint32_t i = 0; i < HowManyMiniBlocks; ++i) {
                Bs[i] = BlockPacker::maxbits(in + i * MiniBlockSize, tmpinit);
            }
            *out++ = (Bs[0] << 24) | (Bs[1] << 16) | (Bs[2] << 8)
                     | Bs[3];
            *out++ = (Bs[4] << 24) | (Bs[5] << 16) | (Bs[6] << 8)
                     | Bs[7];
            *out++ = (Bs[8] << 24) | (Bs[9] << 16) | (Bs[10] << 8)
                     | Bs[11];
            *out++ = (Bs[12] << 24) | (Bs[13] << 16) | (Bs[14] << 8)
                     | Bs[15];
            for (uint32_t i = 0; i < HowManyMiniBlocks; ++i) {
                BlockPacker::packblockwithoutmask(in + i * MiniBlockSize, out, Bs[i], init);
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
            *out++ = (Bs[0] << 24) | (Bs[1] << 16) | (Bs[2] << 8)
                     | Bs[3];
            *out++ = (Bs[4] << 24) | (Bs[5] << 16) | (Bs[6] << 8)
                     | Bs[7];
            *out++ = (Bs[8] << 24) | (Bs[9] << 16) | (Bs[10] << 8)
                     | Bs[11];
            *out++ = (Bs[12] << 24) | (Bs[13] << 16) | (Bs[14] << 8)
                     | Bs[15];
            for (uint32_t i = 0; i < howmany; ++i) {
                BlockPacker::packblockwithoutmask(in + i * MiniBlockSize, out, Bs[i], init);
                out += MiniBlockSize / 32 * Bs[i];
            }
            in += howmany * MiniBlockSize;
            assert(in == final);
        }
        nvalue = out - initout;
    }

    const uint32_t *decodeArray(const uint32_t *in, const size_t /*length*/,
                                uint32_t *out, size_t &nvalue) {
        if (needPaddingTo128Bits(out)
            or needPaddingTo128Bits(in)) throw
            std::runtime_error("alignment issue: pointers should be aligned on 128-bit boundaries");
        const uint32_t actuallength = *in++;
        while (needPaddingTo128Bits(in)) {
            if (in[0] != CookiePadder) throw logic_error("SIMDBinaryPacking alignment issue.");
            ++in;
        }
        const uint32_t *const initout(out);
        uint32_t Bs[HowManyMiniBlocks];
        __m128i init = _mm_set1_epi32(0);
        for (; out < initout + actuallength / (HowManyMiniBlocks * MiniBlockSize) *HowManyMiniBlocks * MiniBlockSize ;
             out += HowManyMiniBlocks * MiniBlockSize) {
            for (uint32_t i = 0; i < 4 ; ++i, ++in) {
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
            for (uint32_t i = 0; i < 4 ; ++i, ++in) {
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
            assert(out ==  initout + actuallength);
        }
        nvalue = out - initout;
        return in;
    }

    string name() const {
        ostringstream convert;
        convert << "SIMDBinaryPacking" << "With" << BlockPacker::name() << MiniBlockSize;
        return convert.str();
    }

};

} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_SIMDBINARYPACKING_H_ */
