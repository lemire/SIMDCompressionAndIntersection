/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire
 */
#ifndef SIMDCompressionAndIntersection_SIMDBITPACKING_H_
#define SIMDCompressionAndIntersection_SIMDBITPACKING_H_

#include "common.h"

namespace SIMDCompressionLib {

void __SIMD_fastunpack1(const __m128i *, uint32_t *);
void __SIMD_fastunpack2(const __m128i *, uint32_t *);
void __SIMD_fastunpack3(const __m128i *, uint32_t *);
void __SIMD_fastunpack4(const __m128i *, uint32_t *);
void __SIMD_fastunpack5(const __m128i *, uint32_t *);
void __SIMD_fastunpack6(const __m128i *, uint32_t *);
void __SIMD_fastunpack7(const __m128i *, uint32_t *);
void __SIMD_fastunpack8(const __m128i *, uint32_t *);
void __SIMD_fastunpack9(const __m128i *, uint32_t *);
void __SIMD_fastunpack10(const __m128i *, uint32_t *);
void __SIMD_fastunpack11(const __m128i *, uint32_t *);
void __SIMD_fastunpack12(const __m128i *, uint32_t *);
void __SIMD_fastunpack13(const __m128i *, uint32_t *);
void __SIMD_fastunpack14(const __m128i *, uint32_t *);
void __SIMD_fastunpack15(const __m128i *, uint32_t *);
void __SIMD_fastunpack16(const __m128i *, uint32_t *);
void __SIMD_fastunpack17(const __m128i *, uint32_t *);
void __SIMD_fastunpack18(const __m128i *, uint32_t *);
void __SIMD_fastunpack19(const __m128i *, uint32_t *);
void __SIMD_fastunpack20(const __m128i *, uint32_t *);
void __SIMD_fastunpack21(const __m128i *, uint32_t *);
void __SIMD_fastunpack22(const __m128i *, uint32_t *);
void __SIMD_fastunpack23(const __m128i *, uint32_t *);
void __SIMD_fastunpack24(const __m128i *, uint32_t *);
void __SIMD_fastunpack25(const __m128i *, uint32_t *);
void __SIMD_fastunpack26(const __m128i *, uint32_t *);
void __SIMD_fastunpack27(const __m128i *, uint32_t *);
void __SIMD_fastunpack28(const __m128i *, uint32_t *);
void __SIMD_fastunpack29(const __m128i *, uint32_t *);
void __SIMD_fastunpack30(const __m128i *, uint32_t *);
void __SIMD_fastunpack31(const __m128i *, uint32_t *);
void __SIMD_fastunpack32(const __m128i *, uint32_t *);

void __SIMD_fastpackwithoutmask0(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask1(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask2(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask3(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask4(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask5(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask6(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask7(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask8(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask9(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask10(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask11(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask12(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask13(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask14(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask15(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask16(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask17(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask18(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask19(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask20(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask21(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask22(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask23(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask24(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask25(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask26(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask27(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask28(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask29(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask30(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask31(const uint32_t *, __m128i *);
void __SIMD_fastpackwithoutmask32(const uint32_t *, __m128i *);

void __SIMD_fastpack0(const uint32_t *, __m128i *);
void __SIMD_fastpack1(const uint32_t *, __m128i *);
void __SIMD_fastpack2(const uint32_t *, __m128i *);
void __SIMD_fastpack3(const uint32_t *, __m128i *);
void __SIMD_fastpack4(const uint32_t *, __m128i *);
void __SIMD_fastpack5(const uint32_t *, __m128i *);
void __SIMD_fastpack6(const uint32_t *, __m128i *);
void __SIMD_fastpack7(const uint32_t *, __m128i *);
void __SIMD_fastpack8(const uint32_t *, __m128i *);
void __SIMD_fastpack9(const uint32_t *, __m128i *);
void __SIMD_fastpack10(const uint32_t *, __m128i *);
void __SIMD_fastpack11(const uint32_t *, __m128i *);
void __SIMD_fastpack12(const uint32_t *, __m128i *);
void __SIMD_fastpack13(const uint32_t *, __m128i *);
void __SIMD_fastpack14(const uint32_t *, __m128i *);
void __SIMD_fastpack15(const uint32_t *, __m128i *);
void __SIMD_fastpack16(const uint32_t *, __m128i *);
void __SIMD_fastpack17(const uint32_t *, __m128i *);
void __SIMD_fastpack18(const uint32_t *, __m128i *);
void __SIMD_fastpack19(const uint32_t *, __m128i *);
void __SIMD_fastpack20(const uint32_t *, __m128i *);
void __SIMD_fastpack21(const uint32_t *, __m128i *);
void __SIMD_fastpack22(const uint32_t *, __m128i *);
void __SIMD_fastpack23(const uint32_t *, __m128i *);
void __SIMD_fastpack24(const uint32_t *, __m128i *);
void __SIMD_fastpack25(const uint32_t *, __m128i *);
void __SIMD_fastpack26(const uint32_t *, __m128i *);
void __SIMD_fastpack27(const uint32_t *, __m128i *);
void __SIMD_fastpack28(const uint32_t *, __m128i *);
void __SIMD_fastpack29(const uint32_t *, __m128i *);
void __SIMD_fastpack30(const uint32_t *, __m128i *);
void __SIMD_fastpack31(const uint32_t *, __m128i *);
void __SIMD_fastpack32(const uint32_t *, __m128i *);

} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_SIMDBITPACKING_H_ */
