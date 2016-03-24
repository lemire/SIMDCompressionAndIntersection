/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Leonid Boytsov, Nathan Kurz and Daniel Lemire
 */

#ifndef SIMDCompressionAndIntersection_BITPACKINGHELPERS_H_
#define SIMDCompressionAndIntersection_BITPACKINGHELPERS_H_

#include "bitpacking.h"
#include "integratedbitpacking.h"
#include "delta.h"
#include "util.h"

namespace SIMDCompressionLib {

struct BitPackingHelpers {
  const static unsigned BlockSize = 32;

  static void inline fastunpack(const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out,
                                const uint32_t bit) {
    // Could have used function pointers instead of switch.
    // Switch calls do offer the compiler more opportunities for optimization in
    // theory. In this case, it makes no difference with a good compiler.
    switch (bit) {
    case 0:
      __fastunpack0(in, out);
      break;
    case 1:
      __fastunpack1(in, out);
      break;
    case 2:
      __fastunpack2(in, out);
      break;
    case 3:
      __fastunpack3(in, out);
      break;
    case 4:
      __fastunpack4(in, out);
      break;
    case 5:
      __fastunpack5(in, out);
      break;
    case 6:
      __fastunpack6(in, out);
      break;
    case 7:
      __fastunpack7(in, out);
      break;
    case 8:
      __fastunpack8(in, out);
      break;
    case 9:
      __fastunpack9(in, out);
      break;
    case 10:
      __fastunpack10(in, out);
      break;
    case 11:
      __fastunpack11(in, out);
      break;
    case 12:
      __fastunpack12(in, out);
      break;
    case 13:
      __fastunpack13(in, out);
      break;
    case 14:
      __fastunpack14(in, out);
      break;
    case 15:
      __fastunpack15(in, out);
      break;
    case 16:
      __fastunpack16(in, out);
      break;
    case 17:
      __fastunpack17(in, out);
      break;
    case 18:
      __fastunpack18(in, out);
      break;
    case 19:
      __fastunpack19(in, out);
      break;
    case 20:
      __fastunpack20(in, out);
      break;
    case 21:
      __fastunpack21(in, out);
      break;
    case 22:
      __fastunpack22(in, out);
      break;
    case 23:
      __fastunpack23(in, out);
      break;
    case 24:
      __fastunpack24(in, out);
      break;
    case 25:
      __fastunpack25(in, out);
      break;
    case 26:
      __fastunpack26(in, out);
      break;
    case 27:
      __fastunpack27(in, out);
      break;
    case 28:
      __fastunpack28(in, out);
      break;
    case 29:
      __fastunpack29(in, out);
      break;
    case 30:
      __fastunpack30(in, out);
      break;
    case 31:
      __fastunpack31(in, out);
      break;
    case 32:
      __fastunpack32(in, out);
      break;
    default:
      break;
    }
  }

  static void inline fastpack(const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out, const uint32_t bit) {
    // Could have used function pointers instead of switch.
    // Switch calls do offer the compiler more opportunities for optimization in
    // theory. In this case, it makes no difference with a good compiler.
    switch (bit) {
    case 0:
      __fastpack0(in, out);
      break;
    case 1:
      __fastpack1(in, out);
      break;
    case 2:
      __fastpack2(in, out);
      break;
    case 3:
      __fastpack3(in, out);
      break;
    case 4:
      __fastpack4(in, out);
      break;
    case 5:
      __fastpack5(in, out);
      break;
    case 6:
      __fastpack6(in, out);
      break;
    case 7:
      __fastpack7(in, out);
      break;
    case 8:
      __fastpack8(in, out);
      break;
    case 9:
      __fastpack9(in, out);
      break;
    case 10:
      __fastpack10(in, out);
      break;
    case 11:
      __fastpack11(in, out);
      break;
    case 12:
      __fastpack12(in, out);
      break;
    case 13:
      __fastpack13(in, out);
      break;
    case 14:
      __fastpack14(in, out);
      break;
    case 15:
      __fastpack15(in, out);
      break;
    case 16:
      __fastpack16(in, out);
      break;
    case 17:
      __fastpack17(in, out);
      break;
    case 18:
      __fastpack18(in, out);
      break;
    case 19:
      __fastpack19(in, out);
      break;
    case 20:
      __fastpack20(in, out);
      break;
    case 21:
      __fastpack21(in, out);
      break;
    case 22:
      __fastpack22(in, out);
      break;
    case 23:
      __fastpack23(in, out);
      break;
    case 24:
      __fastpack24(in, out);
      break;
    case 25:
      __fastpack25(in, out);
      break;
    case 26:
      __fastpack26(in, out);
      break;
    case 27:
      __fastpack27(in, out);
      break;
    case 28:
      __fastpack28(in, out);
      break;
    case 29:
      __fastpack29(in, out);
      break;
    case 30:
      __fastpack30(in, out);
      break;
    case 31:
      __fastpack31(in, out);
      break;
    case 32:
      __fastpack32(in, out);
      break;
    default:
      break;
    }
  }

  /*assumes that integers fit in the prescribed number of bits*/
  static void inline fastpackwithoutmask(const uint32_t *__restrict__ in,
                                         uint32_t *__restrict__ out,
                                         const uint32_t bit) {
    // Could have used function pointers instead of switch.
    // Switch calls do offer the compiler more opportunities for optimization in
    // theory. In this case, it makes no difference with a good compiler.
    switch (bit) {
    case 0:
      __fastpackwithoutmask0(in, out);
      break;
    case 1:
      __fastpackwithoutmask1(in, out);
      break;
    case 2:
      __fastpackwithoutmask2(in, out);
      break;
    case 3:
      __fastpackwithoutmask3(in, out);
      break;
    case 4:
      __fastpackwithoutmask4(in, out);
      break;
    case 5:
      __fastpackwithoutmask5(in, out);
      break;
    case 6:
      __fastpackwithoutmask6(in, out);
      break;
    case 7:
      __fastpackwithoutmask7(in, out);
      break;
    case 8:
      __fastpackwithoutmask8(in, out);
      break;
    case 9:
      __fastpackwithoutmask9(in, out);
      break;
    case 10:
      __fastpackwithoutmask10(in, out);
      break;
    case 11:
      __fastpackwithoutmask11(in, out);
      break;
    case 12:
      __fastpackwithoutmask12(in, out);
      break;
    case 13:
      __fastpackwithoutmask13(in, out);
      break;
    case 14:
      __fastpackwithoutmask14(in, out);
      break;
    case 15:
      __fastpackwithoutmask15(in, out);
      break;
    case 16:
      __fastpackwithoutmask16(in, out);
      break;
    case 17:
      __fastpackwithoutmask17(in, out);
      break;
    case 18:
      __fastpackwithoutmask18(in, out);
      break;
    case 19:
      __fastpackwithoutmask19(in, out);
      break;
    case 20:
      __fastpackwithoutmask20(in, out);
      break;
    case 21:
      __fastpackwithoutmask21(in, out);
      break;
    case 22:
      __fastpackwithoutmask22(in, out);
      break;
    case 23:
      __fastpackwithoutmask23(in, out);
      break;
    case 24:
      __fastpackwithoutmask24(in, out);
      break;
    case 25:
      __fastpackwithoutmask25(in, out);
      break;
    case 26:
      __fastpackwithoutmask26(in, out);
      break;
    case 27:
      __fastpackwithoutmask27(in, out);
      break;
    case 28:
      __fastpackwithoutmask28(in, out);
      break;
    case 29:
      __fastpackwithoutmask29(in, out);
      break;
    case 30:
      __fastpackwithoutmask30(in, out);
      break;
    case 31:
      __fastpackwithoutmask31(in, out);
      break;
    case 32:
      __fastpackwithoutmask32(in, out);
      break;
    default:
      break;
    }
  }

  static void inline integratedfastunpack(const uint32_t initoffset,
                                          const uint32_t *__restrict__ in,
                                          uint32_t *__restrict__ out,
                                          const uint32_t bit) {
    // Could have used function pointers instead of switch.
    // Switch calls do offer the compiler more opportunities for optimization in
    // theory. In this case, it makes no difference with a good compiler.
    switch (bit) {
    case 0:
      __integratedfastunpack0(initoffset, in, out);
      break;
    case 1:
      __integratedfastunpack1(initoffset, in, out);
      break;
    case 2:
      __integratedfastunpack2(initoffset, in, out);
      break;
    case 3:
      __integratedfastunpack3(initoffset, in, out);
      break;
    case 4:
      __integratedfastunpack4(initoffset, in, out);
      break;
    case 5:
      __integratedfastunpack5(initoffset, in, out);
      break;
    case 6:
      __integratedfastunpack6(initoffset, in, out);
      break;
    case 7:
      __integratedfastunpack7(initoffset, in, out);
      break;
    case 8:
      __integratedfastunpack8(initoffset, in, out);
      break;
    case 9:
      __integratedfastunpack9(initoffset, in, out);
      break;
    case 10:
      __integratedfastunpack10(initoffset, in, out);
      break;
    case 11:
      __integratedfastunpack11(initoffset, in, out);
      break;
    case 12:
      __integratedfastunpack12(initoffset, in, out);
      break;
    case 13:
      __integratedfastunpack13(initoffset, in, out);
      break;
    case 14:
      __integratedfastunpack14(initoffset, in, out);
      break;
    case 15:
      __integratedfastunpack15(initoffset, in, out);
      break;
    case 16:
      __integratedfastunpack16(initoffset, in, out);
      break;
    case 17:
      __integratedfastunpack17(initoffset, in, out);
      break;
    case 18:
      __integratedfastunpack18(initoffset, in, out);
      break;
    case 19:
      __integratedfastunpack19(initoffset, in, out);
      break;
    case 20:
      __integratedfastunpack20(initoffset, in, out);
      break;
    case 21:
      __integratedfastunpack21(initoffset, in, out);
      break;
    case 22:
      __integratedfastunpack22(initoffset, in, out);
      break;
    case 23:
      __integratedfastunpack23(initoffset, in, out);
      break;
    case 24:
      __integratedfastunpack24(initoffset, in, out);
      break;
    case 25:
      __integratedfastunpack25(initoffset, in, out);
      break;
    case 26:
      __integratedfastunpack26(initoffset, in, out);
      break;
    case 27:
      __integratedfastunpack27(initoffset, in, out);
      break;
    case 28:
      __integratedfastunpack28(initoffset, in, out);
      break;
    case 29:
      __integratedfastunpack29(initoffset, in, out);
      break;
    case 30:
      __integratedfastunpack30(initoffset, in, out);
      break;
    case 31:
      __integratedfastunpack31(initoffset, in, out);
      break;
    case 32:
      __integratedfastunpack32(initoffset, in, out);
      break;
    default:
      break;
    }
  }

  /*assumes that integers fit in the prescribed number of bits*/
  static void inline integratedfastpackwithoutmask(
      const uint32_t initoffset, const uint32_t *__restrict__ in,
      uint32_t *__restrict__ out, const uint32_t bit) {
    // Could have used function pointers instead of switch.
    // Switch calls do offer the compiler more opportunities for optimization in
    // theory. In this case, it makes no difference with a good compiler.
    switch (bit) {
    case 0:
      __integratedfastpack0(initoffset, in, out);
      break;
    case 1:
      __integratedfastpack1(initoffset, in, out);
      break;
    case 2:
      __integratedfastpack2(initoffset, in, out);
      break;
    case 3:
      __integratedfastpack3(initoffset, in, out);
      break;
    case 4:
      __integratedfastpack4(initoffset, in, out);
      break;
    case 5:
      __integratedfastpack5(initoffset, in, out);
      break;
    case 6:
      __integratedfastpack6(initoffset, in, out);
      break;
    case 7:
      __integratedfastpack7(initoffset, in, out);
      break;
    case 8:
      __integratedfastpack8(initoffset, in, out);
      break;
    case 9:
      __integratedfastpack9(initoffset, in, out);
      break;
    case 10:
      __integratedfastpack10(initoffset, in, out);
      break;
    case 11:
      __integratedfastpack11(initoffset, in, out);
      break;
    case 12:
      __integratedfastpack12(initoffset, in, out);
      break;
    case 13:
      __integratedfastpack13(initoffset, in, out);
      break;
    case 14:
      __integratedfastpack14(initoffset, in, out);
      break;
    case 15:
      __integratedfastpack15(initoffset, in, out);
      break;
    case 16:
      __integratedfastpack16(initoffset, in, out);
      break;
    case 17:
      __integratedfastpack17(initoffset, in, out);
      break;
    case 18:
      __integratedfastpack18(initoffset, in, out);
      break;
    case 19:
      __integratedfastpack19(initoffset, in, out);
      break;
    case 20:
      __integratedfastpack20(initoffset, in, out);
      break;
    case 21:
      __integratedfastpack21(initoffset, in, out);
      break;
    case 22:
      __integratedfastpack22(initoffset, in, out);
      break;
    case 23:
      __integratedfastpack23(initoffset, in, out);
      break;
    case 24:
      __integratedfastpack24(initoffset, in, out);
      break;
    case 25:
      __integratedfastpack25(initoffset, in, out);
      break;
    case 26:
      __integratedfastpack26(initoffset, in, out);
      break;
    case 27:
      __integratedfastpack27(initoffset, in, out);
      break;
    case 28:
      __integratedfastpack28(initoffset, in, out);
      break;
    case 29:
      __integratedfastpack29(initoffset, in, out);
      break;
    case 30:
      __integratedfastpack30(initoffset, in, out);
      break;
    case 31:
      __integratedfastpack31(initoffset, in, out);
      break;
    case 32:
      __integratedfastpack32(initoffset, in, out);
      break;
    default:
      break;
    }
  }

  static void inline ipackwithoutmask(const uint32_t *in, const size_t Qty,
                                      uint32_t *out, const uint32_t bit) {
    if (Qty % BlockSize) {
      throw std::logic_error("Incorrect # of entries.");
    }
    uint32_t initoffset = 0;

    for (size_t k = 0; k < Qty / BlockSize; ++k) {
      integratedfastpackwithoutmask(initoffset, in + k * BlockSize,
                                    out + k * bit, bit);
      initoffset = *(in + k * BlockSize + BlockSize - 1);
    }
  }

  static void inline pack(uint32_t *in, const size_t Qty, uint32_t *out,
                          const uint32_t bit) {
    if (Qty % BlockSize) {
      throw std::logic_error("Incorrect # of entries.");
    }
    uint32_t initoffset = 0;

    for (size_t k = 0; k < Qty / BlockSize; ++k) {
      const uint32_t nextoffset = *(in + k * BlockSize + BlockSize - 1);
      if (bit < 32)
        delta<BlockSize>(initoffset, in + k * BlockSize);
      fastpack(in + k * BlockSize, out + k * bit, bit);
      initoffset = nextoffset;
    }
  }

  static void inline packWithoutDelta(uint32_t *in, const size_t Qty,
                                      uint32_t *out, const uint32_t bit) {
    for (size_t k = 0; k < Qty / BlockSize; ++k) {
      fastpack(in + k * BlockSize, out + k * bit, bit);
    }
  }

  static void inline unpack(const uint32_t *in, const size_t Qty, uint32_t *out,
                            const uint32_t bit) {
    if (Qty % BlockSize) {
      throw std::logic_error("Incorrect # of entries.");
    }
    uint32_t initoffset = 0;

    for (size_t k = 0; k < Qty / BlockSize; ++k) {
      fastunpack(in + k * bit, out + k * BlockSize, bit);
      if (bit < 32)
        inverseDelta<BlockSize>(initoffset, out + k * BlockSize);
      initoffset = *(out + k * BlockSize + BlockSize - 1);
    }
  }

  static void inline unpackWithoutDelta(const uint32_t *in, const size_t Qty,
                                        uint32_t *out, const uint32_t bit) {
    for (size_t k = 0; k < Qty / BlockSize; ++k) {
      fastunpack(in + k * bit, out + k * BlockSize, bit);
    }
  }

  static void inline packwithoutmask(uint32_t *in, const size_t Qty,
                                     uint32_t *out, const uint32_t bit) {
    if (Qty % BlockSize) {
      throw std::logic_error("Incorrect # of entries.");
    }
    uint32_t initoffset = 0;

    for (size_t k = 0; k < Qty / BlockSize; ++k) {
      const uint32_t nextoffset = *(in + k * BlockSize + BlockSize - 1);
      if (bit < 32)
        delta<BlockSize>(initoffset, in + k * BlockSize);
      fastpackwithoutmask(in + k * BlockSize, out + k * bit, bit);
      initoffset = nextoffset;
    }
  }

  static void inline packwithoutmaskWithoutDelta(uint32_t *in, const size_t Qty,
                                                 uint32_t *out,
                                                 const uint32_t bit) {
    for (size_t k = 0; k < Qty / BlockSize; ++k) {
      fastpackwithoutmask(in + k * BlockSize, out + k * bit, bit);
    }
  }

  static void inline iunpack(const uint32_t *in, const size_t Qty,
                             uint32_t *out, const uint32_t bit) {
    if (Qty % BlockSize) {
      throw std::logic_error("Incorrect # of entries.");
    }

    uint32_t initoffset = 0;
    for (size_t k = 0; k < Qty / BlockSize; ++k) {
      integratedfastunpack(initoffset, in + k * bit, out + k * BlockSize, bit);
      initoffset = *(out + k * BlockSize + BlockSize - 1);
    }
  }

  /*static void GenRandom(std::vector<uint32_t>& data, int b) {
      data[0] = random(b);

      for(size_t i = 1 ; i < data.size() ; ++i )
          data[i] = random(b) + data[i-1];
  }*/

  static void CheckMaxDiff(const std::vector<uint32_t> &refdata, unsigned bit) {
    for (size_t i = 1; i < refdata.size(); ++i) {
      if (gccbits(refdata[i] - refdata[i - 1]) > bit)
        throw std::runtime_error("bug");
    }
  }
};

} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_BITPACKINGHELPERS_H_ */
