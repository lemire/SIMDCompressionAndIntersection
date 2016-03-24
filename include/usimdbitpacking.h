/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire
 */
#ifndef SIMDCompressionAndIntersection_USIMDBITPACKING_H_
#define SIMDCompressionAndIntersection_USIMDBITPACKING_H_

#include "common.h"

namespace SIMDCompressionLib {

void __uSIMD_fastunpack1(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack2(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack3(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack4(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack5(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack6(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack7(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack8(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack9(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack10(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack11(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack12(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack13(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack14(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack15(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack16(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack17(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack18(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack19(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack20(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack21(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack22(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack23(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack24(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack25(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack26(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack27(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack28(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack29(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack30(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack31(const __m128i *__restrict__, uint32_t *__restrict__);
void __uSIMD_fastunpack32(const __m128i *__restrict__, uint32_t *__restrict__);

void __uSIMD_fastpackwithoutmask0(const uint32_t *__restrict__,
                                  __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask1(const uint32_t *__restrict__,
                                  __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask2(const uint32_t *__restrict__,
                                  __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask3(const uint32_t *__restrict__,
                                  __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask4(const uint32_t *__restrict__,
                                  __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask5(const uint32_t *__restrict__,
                                  __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask6(const uint32_t *__restrict__,
                                  __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask7(const uint32_t *__restrict__,
                                  __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask8(const uint32_t *__restrict__,
                                  __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask9(const uint32_t *__restrict__,
                                  __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask10(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask11(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask12(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask13(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask14(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask15(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask16(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask17(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask18(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask19(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask20(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask21(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask22(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask23(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask24(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask25(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask26(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask27(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask28(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask29(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask30(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask31(const uint32_t *__restrict__,
                                   __m128i *__restrict__);
void __uSIMD_fastpackwithoutmask32(const uint32_t *__restrict__,
                                   __m128i *__restrict__);

void __uSIMD_fastpack0(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack1(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack2(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack3(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack4(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack5(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack6(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack7(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack8(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack9(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack10(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack11(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack12(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack13(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack14(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack15(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack16(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack17(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack18(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack19(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack20(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack21(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack22(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack23(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack24(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack25(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack26(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack27(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack28(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack29(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack30(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack31(const uint32_t *__restrict__, __m128i *__restrict__);
void __uSIMD_fastpack32(const uint32_t *__restrict__, __m128i *__restrict__);

} // namespace SIMDCompressionLib

#endif /* SIMDBITPACKING_H_ */
