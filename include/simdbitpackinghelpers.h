/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Leonid Boytsov, Nathan Kurz and Daniel Lemire
 */

#ifndef SIMDCompressionAndIntersection_SIMD_BITPACKING_HELPERS_H_
#define SIMDCompressionAndIntersection_SIMD_BITPACKING_HELPERS_H_

#include "common.h"
#include "simdbitpacking.h"
#include "usimdbitpacking.h"
#include "simdintegratedbitpacking.h"
#include "delta.h"
#include "util.h"

namespace SIMDCompressionLib {

const size_t SIMDBlockSize = 128;

void SIMD_nullunpacker32(const __m128i *__restrict__,
                         uint32_t *__restrict__ out) {
  memset(out, 0, 32 * 4 * 4);
}
void uSIMD_nullunpacker32(const __m128i *__restrict__,
                          uint32_t *__restrict__ out) {
  memset(out, 0, 32 * 4 * 4);
}

void simdunpack(const __m128i *__restrict__ in, uint32_t *__restrict__ out,
                const uint32_t bit) {
  switch (bit) {
  case 0:
    SIMD_nullunpacker32(in, out);
    return;

  case 1:
    __SIMD_fastunpack1(in, out);
    return;

  case 2:
    __SIMD_fastunpack2(in, out);
    return;

  case 3:
    __SIMD_fastunpack3(in, out);
    return;

  case 4:
    __SIMD_fastunpack4(in, out);
    return;

  case 5:
    __SIMD_fastunpack5(in, out);
    return;

  case 6:
    __SIMD_fastunpack6(in, out);
    return;

  case 7:
    __SIMD_fastunpack7(in, out);
    return;

  case 8:
    __SIMD_fastunpack8(in, out);
    return;

  case 9:
    __SIMD_fastunpack9(in, out);
    return;

  case 10:
    __SIMD_fastunpack10(in, out);
    return;

  case 11:
    __SIMD_fastunpack11(in, out);
    return;

  case 12:
    __SIMD_fastunpack12(in, out);
    return;

  case 13:
    __SIMD_fastunpack13(in, out);
    return;

  case 14:
    __SIMD_fastunpack14(in, out);
    return;

  case 15:
    __SIMD_fastunpack15(in, out);
    return;

  case 16:
    __SIMD_fastunpack16(in, out);
    return;

  case 17:
    __SIMD_fastunpack17(in, out);
    return;

  case 18:
    __SIMD_fastunpack18(in, out);
    return;

  case 19:
    __SIMD_fastunpack19(in, out);
    return;

  case 20:
    __SIMD_fastunpack20(in, out);
    return;

  case 21:
    __SIMD_fastunpack21(in, out);
    return;

  case 22:
    __SIMD_fastunpack22(in, out);
    return;

  case 23:
    __SIMD_fastunpack23(in, out);
    return;

  case 24:
    __SIMD_fastunpack24(in, out);
    return;

  case 25:
    __SIMD_fastunpack25(in, out);
    return;

  case 26:
    __SIMD_fastunpack26(in, out);
    return;

  case 27:
    __SIMD_fastunpack27(in, out);
    return;

  case 28:
    __SIMD_fastunpack28(in, out);
    return;

  case 29:
    __SIMD_fastunpack29(in, out);
    return;

  case 30:
    __SIMD_fastunpack30(in, out);
    return;

  case 31:
    __SIMD_fastunpack31(in, out);
    return;

  case 32:
    __SIMD_fastunpack32(in, out);
    return;

  default:
    break;
  }
  throw std::logic_error("number of bits is unsupported");
}

/*assumes that integers fit in the prescribed number of bits*/
void simdpackwithoutmask(const uint32_t *__restrict__ in,
                         __m128i *__restrict__ out, const uint32_t bit) {
  switch (bit) {
  case 0:
    return;

  case 1:
    __SIMD_fastpackwithoutmask1(in, out);
    return;

  case 2:
    __SIMD_fastpackwithoutmask2(in, out);
    return;

  case 3:
    __SIMD_fastpackwithoutmask3(in, out);
    return;

  case 4:
    __SIMD_fastpackwithoutmask4(in, out);
    return;

  case 5:
    __SIMD_fastpackwithoutmask5(in, out);
    return;

  case 6:
    __SIMD_fastpackwithoutmask6(in, out);
    return;

  case 7:
    __SIMD_fastpackwithoutmask7(in, out);
    return;

  case 8:
    __SIMD_fastpackwithoutmask8(in, out);
    return;

  case 9:
    __SIMD_fastpackwithoutmask9(in, out);
    return;

  case 10:
    __SIMD_fastpackwithoutmask10(in, out);
    return;

  case 11:
    __SIMD_fastpackwithoutmask11(in, out);
    return;

  case 12:
    __SIMD_fastpackwithoutmask12(in, out);
    return;

  case 13:
    __SIMD_fastpackwithoutmask13(in, out);
    return;

  case 14:
    __SIMD_fastpackwithoutmask14(in, out);
    return;

  case 15:
    __SIMD_fastpackwithoutmask15(in, out);
    return;

  case 16:
    __SIMD_fastpackwithoutmask16(in, out);
    return;

  case 17:
    __SIMD_fastpackwithoutmask17(in, out);
    return;

  case 18:
    __SIMD_fastpackwithoutmask18(in, out);
    return;

  case 19:
    __SIMD_fastpackwithoutmask19(in, out);
    return;

  case 20:
    __SIMD_fastpackwithoutmask20(in, out);
    return;

  case 21:
    __SIMD_fastpackwithoutmask21(in, out);
    return;

  case 22:
    __SIMD_fastpackwithoutmask22(in, out);
    return;

  case 23:
    __SIMD_fastpackwithoutmask23(in, out);
    return;

  case 24:
    __SIMD_fastpackwithoutmask24(in, out);
    return;

  case 25:
    __SIMD_fastpackwithoutmask25(in, out);
    return;

  case 26:
    __SIMD_fastpackwithoutmask26(in, out);
    return;

  case 27:
    __SIMD_fastpackwithoutmask27(in, out);
    return;

  case 28:
    __SIMD_fastpackwithoutmask28(in, out);
    return;

  case 29:
    __SIMD_fastpackwithoutmask29(in, out);
    return;

  case 30:
    __SIMD_fastpackwithoutmask30(in, out);
    return;

  case 31:
    __SIMD_fastpackwithoutmask31(in, out);
    return;

  case 32:
    __SIMD_fastpackwithoutmask32(in, out);
    return;

  default:
    break;
  }
  throw std::logic_error("number of bits is unsupported");
}

/*assumes that integers fit in the prescribed number of bits*/
void simdpack(const uint32_t *__restrict__ in, __m128i *__restrict__ out,
              const uint32_t bit) {
  switch (bit) {
  case 0:
    return;

  case 1:
    __SIMD_fastpack1(in, out);
    return;

  case 2:
    __SIMD_fastpack2(in, out);
    return;

  case 3:
    __SIMD_fastpack3(in, out);
    return;

  case 4:
    __SIMD_fastpack4(in, out);
    return;

  case 5:
    __SIMD_fastpack5(in, out);
    return;

  case 6:
    __SIMD_fastpack6(in, out);
    return;

  case 7:
    __SIMD_fastpack7(in, out);
    return;

  case 8:
    __SIMD_fastpack8(in, out);
    return;

  case 9:
    __SIMD_fastpack9(in, out);
    return;

  case 10:
    __SIMD_fastpack10(in, out);
    return;

  case 11:
    __SIMD_fastpack11(in, out);
    return;

  case 12:
    __SIMD_fastpack12(in, out);
    return;

  case 13:
    __SIMD_fastpack13(in, out);
    return;

  case 14:
    __SIMD_fastpack14(in, out);
    return;

  case 15:
    __SIMD_fastpack15(in, out);
    return;

  case 16:
    __SIMD_fastpack16(in, out);
    return;

  case 17:
    __SIMD_fastpack17(in, out);
    return;

  case 18:
    __SIMD_fastpack18(in, out);
    return;

  case 19:
    __SIMD_fastpack19(in, out);
    return;

  case 20:
    __SIMD_fastpack20(in, out);
    return;

  case 21:
    __SIMD_fastpack21(in, out);
    return;

  case 22:
    __SIMD_fastpack22(in, out);
    return;

  case 23:
    __SIMD_fastpack23(in, out);
    return;

  case 24:
    __SIMD_fastpack24(in, out);
    return;

  case 25:
    __SIMD_fastpack25(in, out);
    return;

  case 26:
    __SIMD_fastpack26(in, out);
    return;

  case 27:
    __SIMD_fastpack27(in, out);
    return;

  case 28:
    __SIMD_fastpack28(in, out);
    return;

  case 29:
    __SIMD_fastpack29(in, out);
    return;

  case 30:
    __SIMD_fastpack30(in, out);
    return;

  case 31:
    __SIMD_fastpack31(in, out);
    return;

  case 32:
    __SIMD_fastpack32(in, out);
    return;

  default:
    break;
  }
  throw std::logic_error("number of bits is unsupported");
}

void usimdunpack(const __m128i *__restrict__ in, uint32_t *__restrict__ out,
                 const uint32_t bit) {
  switch (bit) {
  case 0:
    uSIMD_nullunpacker32(in, out);
    return;

  case 1:
    __uSIMD_fastunpack1(in, out);
    return;

  case 2:
    __uSIMD_fastunpack2(in, out);
    return;

  case 3:
    __uSIMD_fastunpack3(in, out);
    return;

  case 4:
    __uSIMD_fastunpack4(in, out);
    return;

  case 5:
    __uSIMD_fastunpack5(in, out);
    return;

  case 6:
    __uSIMD_fastunpack6(in, out);
    return;

  case 7:
    __uSIMD_fastunpack7(in, out);
    return;

  case 8:
    __uSIMD_fastunpack8(in, out);
    return;

  case 9:
    __uSIMD_fastunpack9(in, out);
    return;

  case 10:
    __uSIMD_fastunpack10(in, out);
    return;

  case 11:
    __uSIMD_fastunpack11(in, out);
    return;

  case 12:
    __uSIMD_fastunpack12(in, out);
    return;

  case 13:
    __uSIMD_fastunpack13(in, out);
    return;

  case 14:
    __uSIMD_fastunpack14(in, out);
    return;

  case 15:
    __uSIMD_fastunpack15(in, out);
    return;

  case 16:
    __uSIMD_fastunpack16(in, out);
    return;

  case 17:
    __uSIMD_fastunpack17(in, out);
    return;

  case 18:
    __uSIMD_fastunpack18(in, out);
    return;

  case 19:
    __uSIMD_fastunpack19(in, out);
    return;

  case 20:
    __uSIMD_fastunpack20(in, out);
    return;

  case 21:
    __uSIMD_fastunpack21(in, out);
    return;

  case 22:
    __uSIMD_fastunpack22(in, out);
    return;

  case 23:
    __uSIMD_fastunpack23(in, out);
    return;

  case 24:
    __uSIMD_fastunpack24(in, out);
    return;

  case 25:
    __uSIMD_fastunpack25(in, out);
    return;

  case 26:
    __uSIMD_fastunpack26(in, out);
    return;

  case 27:
    __uSIMD_fastunpack27(in, out);
    return;

  case 28:
    __uSIMD_fastunpack28(in, out);
    return;

  case 29:
    __uSIMD_fastunpack29(in, out);
    return;

  case 30:
    __uSIMD_fastunpack30(in, out);
    return;

  case 31:
    __uSIMD_fastunpack31(in, out);
    return;

  case 32:
    __uSIMD_fastunpack32(in, out);
    return;

  default:
    break;
  }
  throw std::logic_error("number of bits is unsupported");
}

/*assumes that integers fit in the prescribed number of bits*/
void usimdpackwithoutmask(const uint32_t *__restrict__ in,
                          __m128i *__restrict__ out, const uint32_t bit) {
  switch (bit) {
  case 0:
    return;

  case 1:
    __uSIMD_fastpackwithoutmask1(in, out);
    return;

  case 2:
    __uSIMD_fastpackwithoutmask2(in, out);
    return;

  case 3:
    __uSIMD_fastpackwithoutmask3(in, out);
    return;

  case 4:
    __uSIMD_fastpackwithoutmask4(in, out);
    return;

  case 5:
    __uSIMD_fastpackwithoutmask5(in, out);
    return;

  case 6:
    __uSIMD_fastpackwithoutmask6(in, out);
    return;

  case 7:
    __uSIMD_fastpackwithoutmask7(in, out);
    return;

  case 8:
    __uSIMD_fastpackwithoutmask8(in, out);
    return;

  case 9:
    __uSIMD_fastpackwithoutmask9(in, out);
    return;

  case 10:
    __uSIMD_fastpackwithoutmask10(in, out);
    return;

  case 11:
    __uSIMD_fastpackwithoutmask11(in, out);
    return;

  case 12:
    __uSIMD_fastpackwithoutmask12(in, out);
    return;

  case 13:
    __uSIMD_fastpackwithoutmask13(in, out);
    return;

  case 14:
    __uSIMD_fastpackwithoutmask14(in, out);
    return;

  case 15:
    __uSIMD_fastpackwithoutmask15(in, out);
    return;

  case 16:
    __uSIMD_fastpackwithoutmask16(in, out);
    return;

  case 17:
    __uSIMD_fastpackwithoutmask17(in, out);
    return;

  case 18:
    __uSIMD_fastpackwithoutmask18(in, out);
    return;

  case 19:
    __uSIMD_fastpackwithoutmask19(in, out);
    return;

  case 20:
    __uSIMD_fastpackwithoutmask20(in, out);
    return;

  case 21:
    __uSIMD_fastpackwithoutmask21(in, out);
    return;

  case 22:
    __uSIMD_fastpackwithoutmask22(in, out);
    return;

  case 23:
    __uSIMD_fastpackwithoutmask23(in, out);
    return;

  case 24:
    __uSIMD_fastpackwithoutmask24(in, out);
    return;

  case 25:
    __uSIMD_fastpackwithoutmask25(in, out);
    return;

  case 26:
    __uSIMD_fastpackwithoutmask26(in, out);
    return;

  case 27:
    __uSIMD_fastpackwithoutmask27(in, out);
    return;

  case 28:
    __uSIMD_fastpackwithoutmask28(in, out);
    return;

  case 29:
    __uSIMD_fastpackwithoutmask29(in, out);
    return;

  case 30:
    __uSIMD_fastpackwithoutmask30(in, out);
    return;

  case 31:
    __uSIMD_fastpackwithoutmask31(in, out);
    return;

  case 32:
    __uSIMD_fastpackwithoutmask32(in, out);
    return;

  default:
    break;
  }
  throw std::logic_error("number of bits is unsupported");
}

void usimdpack(const uint32_t *__restrict__ in, __m128i *__restrict__ out,
               const uint32_t bit) {
  switch (bit) {
  case 0:
    return;

  case 1:
    __uSIMD_fastpack1(in, out);
    return;

  case 2:
    __uSIMD_fastpack2(in, out);
    return;

  case 3:
    __uSIMD_fastpack3(in, out);
    return;

  case 4:
    __uSIMD_fastpack4(in, out);
    return;

  case 5:
    __uSIMD_fastpack5(in, out);
    return;

  case 6:
    __uSIMD_fastpack6(in, out);
    return;

  case 7:
    __uSIMD_fastpack7(in, out);
    return;

  case 8:
    __uSIMD_fastpack8(in, out);
    return;

  case 9:
    __uSIMD_fastpack9(in, out);
    return;

  case 10:
    __uSIMD_fastpack10(in, out);
    return;

  case 11:
    __uSIMD_fastpack11(in, out);
    return;

  case 12:
    __uSIMD_fastpack12(in, out);
    return;

  case 13:
    __uSIMD_fastpack13(in, out);
    return;

  case 14:
    __uSIMD_fastpack14(in, out);
    return;

  case 15:
    __uSIMD_fastpack15(in, out);
    return;

  case 16:
    __uSIMD_fastpack16(in, out);
    return;

  case 17:
    __uSIMD_fastpack17(in, out);
    return;

  case 18:
    __uSIMD_fastpack18(in, out);
    return;

  case 19:
    __uSIMD_fastpack19(in, out);
    return;

  case 20:
    __uSIMD_fastpack20(in, out);
    return;

  case 21:
    __uSIMD_fastpack21(in, out);
    return;

  case 22:
    __uSIMD_fastpack22(in, out);
    return;

  case 23:
    __uSIMD_fastpack23(in, out);
    return;

  case 24:
    __uSIMD_fastpack24(in, out);
    return;

  case 25:
    __uSIMD_fastpack25(in, out);
    return;

  case 26:
    __uSIMD_fastpack26(in, out);
    return;

  case 27:
    __uSIMD_fastpack27(in, out);
    return;

  case 28:
    __uSIMD_fastpack28(in, out);
    return;

  case 29:
    __uSIMD_fastpack29(in, out);
    return;

  case 30:
    __uSIMD_fastpack30(in, out);
    return;

  case 31:
    __uSIMD_fastpack31(in, out);
    return;

  case 32:
    __uSIMD_fastpack32(in, out);
    return;

  default:
    break;
  }
  throw std::logic_error("number of bits is unsupported");
}

namespace ArrayDispatch {
typedef void (*unpackingfunction)(const __m128i *, uint32_t *);
typedef void (*packingfunction)(const uint32_t *, __m128i *);

constexpr unpackingfunction unpack[33] = {
    SIMD_nullunpacker32, __SIMD_fastunpack1,  __SIMD_fastunpack2,
    __SIMD_fastunpack3,  __SIMD_fastunpack4,  __SIMD_fastunpack5,
    __SIMD_fastunpack6,  __SIMD_fastunpack7,  __SIMD_fastunpack8,
    __SIMD_fastunpack9,  __SIMD_fastunpack10, __SIMD_fastunpack11,
    __SIMD_fastunpack12, __SIMD_fastunpack13, __SIMD_fastunpack14,
    __SIMD_fastunpack15, __SIMD_fastunpack16, __SIMD_fastunpack17,
    __SIMD_fastunpack18, __SIMD_fastunpack19, __SIMD_fastunpack20,
    __SIMD_fastunpack21, __SIMD_fastunpack22, __SIMD_fastunpack23,
    __SIMD_fastunpack24, __SIMD_fastunpack25, __SIMD_fastunpack26,
    __SIMD_fastunpack27, __SIMD_fastunpack28, __SIMD_fastunpack29,
    __SIMD_fastunpack30, __SIMD_fastunpack31, __SIMD_fastunpack32};

ALWAYS_INLINE
void SIMDunpack(const __m128i *__restrict__ in, uint32_t *__restrict__ out,
                const uint32_t bit) {
  return unpack[bit](in, out);
}

constexpr packingfunction packwithoutmask[33] = {
    __SIMD_fastpackwithoutmask0,  __SIMD_fastpackwithoutmask1,
    __SIMD_fastpackwithoutmask2,  __SIMD_fastpackwithoutmask3,
    __SIMD_fastpackwithoutmask4,  __SIMD_fastpackwithoutmask5,
    __SIMD_fastpackwithoutmask6,  __SIMD_fastpackwithoutmask7,
    __SIMD_fastpackwithoutmask8,  __SIMD_fastpackwithoutmask9,
    __SIMD_fastpackwithoutmask10, __SIMD_fastpackwithoutmask11,
    __SIMD_fastpackwithoutmask12, __SIMD_fastpackwithoutmask13,
    __SIMD_fastpackwithoutmask14, __SIMD_fastpackwithoutmask15,
    __SIMD_fastpackwithoutmask16, __SIMD_fastpackwithoutmask17,
    __SIMD_fastpackwithoutmask18, __SIMD_fastpackwithoutmask19,
    __SIMD_fastpackwithoutmask20, __SIMD_fastpackwithoutmask21,
    __SIMD_fastpackwithoutmask22, __SIMD_fastpackwithoutmask23,
    __SIMD_fastpackwithoutmask24, __SIMD_fastpackwithoutmask25,
    __SIMD_fastpackwithoutmask26, __SIMD_fastpackwithoutmask27,
    __SIMD_fastpackwithoutmask28, __SIMD_fastpackwithoutmask29,
    __SIMD_fastpackwithoutmask30, __SIMD_fastpackwithoutmask31,
    __SIMD_fastpackwithoutmask32};

ALWAYS_INLINE
void SIMDpackwithoutmask(const uint32_t *__restrict__ in,
                         __m128i *__restrict__ out, const uint32_t bit) {
  packwithoutmask[bit](in, out);
}
constexpr packingfunction pack[33] = {
    __SIMD_fastpack0,  __SIMD_fastpack1,  __SIMD_fastpack2,  __SIMD_fastpack3,
    __SIMD_fastpack4,  __SIMD_fastpack5,  __SIMD_fastpack6,  __SIMD_fastpack7,
    __SIMD_fastpack8,  __SIMD_fastpack9,  __SIMD_fastpack10, __SIMD_fastpack11,
    __SIMD_fastpack12, __SIMD_fastpack13, __SIMD_fastpack14, __SIMD_fastpack15,
    __SIMD_fastpack16, __SIMD_fastpack17, __SIMD_fastpack18, __SIMD_fastpack19,
    __SIMD_fastpack20, __SIMD_fastpack21, __SIMD_fastpack22, __SIMD_fastpack23,
    __SIMD_fastpack24, __SIMD_fastpack25, __SIMD_fastpack26, __SIMD_fastpack27,
    __SIMD_fastpack28, __SIMD_fastpack29, __SIMD_fastpack30, __SIMD_fastpack31,
    __SIMD_fastpack32};

ALWAYS_INLINE
void SIMDpack(const uint32_t *__restrict__ in, __m128i *__restrict__ out,
              const uint32_t bit) {
  pack[bit](in, out);
}

constexpr unpackingfunction Uunpack[33] = {
    uSIMD_nullunpacker32, __uSIMD_fastunpack1,  __uSIMD_fastunpack2,
    __uSIMD_fastunpack3,  __uSIMD_fastunpack4,  __uSIMD_fastunpack5,
    __uSIMD_fastunpack6,  __uSIMD_fastunpack7,  __uSIMD_fastunpack8,
    __uSIMD_fastunpack9,  __uSIMD_fastunpack10, __uSIMD_fastunpack11,
    __uSIMD_fastunpack12, __uSIMD_fastunpack13, __uSIMD_fastunpack14,
    __uSIMD_fastunpack15, __uSIMD_fastunpack16, __uSIMD_fastunpack17,
    __uSIMD_fastunpack18, __uSIMD_fastunpack19, __uSIMD_fastunpack20,
    __uSIMD_fastunpack21, __uSIMD_fastunpack22, __uSIMD_fastunpack23,
    __uSIMD_fastunpack24, __uSIMD_fastunpack25, __uSIMD_fastunpack26,
    __uSIMD_fastunpack27, __uSIMD_fastunpack28, __uSIMD_fastunpack29,
    __uSIMD_fastunpack30, __uSIMD_fastunpack31, __uSIMD_fastunpack32};

ALWAYS_INLINE
void uSIMDunpack(const __m128i *__restrict__ in, uint32_t *__restrict__ out,
                 const uint32_t bit) {
  return Uunpack[bit](in, out);
}

constexpr packingfunction Upackwithoutmask[33] = {
    __uSIMD_fastpackwithoutmask0,  __uSIMD_fastpackwithoutmask1,
    __uSIMD_fastpackwithoutmask2,  __uSIMD_fastpackwithoutmask3,
    __uSIMD_fastpackwithoutmask4,  __uSIMD_fastpackwithoutmask5,
    __uSIMD_fastpackwithoutmask6,  __uSIMD_fastpackwithoutmask7,
    __uSIMD_fastpackwithoutmask8,  __uSIMD_fastpackwithoutmask9,
    __uSIMD_fastpackwithoutmask10, __uSIMD_fastpackwithoutmask11,
    __uSIMD_fastpackwithoutmask12, __uSIMD_fastpackwithoutmask13,
    __uSIMD_fastpackwithoutmask14, __uSIMD_fastpackwithoutmask15,
    __uSIMD_fastpackwithoutmask16, __uSIMD_fastpackwithoutmask17,
    __uSIMD_fastpackwithoutmask18, __uSIMD_fastpackwithoutmask19,
    __uSIMD_fastpackwithoutmask20, __uSIMD_fastpackwithoutmask21,
    __uSIMD_fastpackwithoutmask22, __uSIMD_fastpackwithoutmask23,
    __uSIMD_fastpackwithoutmask24, __uSIMD_fastpackwithoutmask25,
    __uSIMD_fastpackwithoutmask26, __uSIMD_fastpackwithoutmask27,
    __uSIMD_fastpackwithoutmask28, __uSIMD_fastpackwithoutmask29,
    __uSIMD_fastpackwithoutmask30, __uSIMD_fastpackwithoutmask31,
    __uSIMD_fastpackwithoutmask32};

ALWAYS_INLINE
void uSIMDpackwithoutmask(const uint32_t *__restrict__ in,
                          __m128i *__restrict__ out, const uint32_t bit) {
  Upackwithoutmask[bit](in, out);
}
constexpr packingfunction Upack[33] = {
    __uSIMD_fastpack0,  __uSIMD_fastpack1,  __uSIMD_fastpack2,
    __uSIMD_fastpack3,  __uSIMD_fastpack4,  __uSIMD_fastpack5,
    __uSIMD_fastpack6,  __uSIMD_fastpack7,  __uSIMD_fastpack8,
    __uSIMD_fastpack9,  __uSIMD_fastpack10, __uSIMD_fastpack11,
    __uSIMD_fastpack12, __uSIMD_fastpack13, __uSIMD_fastpack14,
    __uSIMD_fastpack15, __uSIMD_fastpack16, __uSIMD_fastpack17,
    __uSIMD_fastpack18, __uSIMD_fastpack19, __uSIMD_fastpack20,
    __uSIMD_fastpack21, __uSIMD_fastpack22, __uSIMD_fastpack23,
    __uSIMD_fastpack24, __uSIMD_fastpack25, __uSIMD_fastpack26,
    __uSIMD_fastpack27, __uSIMD_fastpack28, __uSIMD_fastpack29,
    __uSIMD_fastpack30, __uSIMD_fastpack31, __uSIMD_fastpack32};

ALWAYS_INLINE
void uSIMDpack(const uint32_t *__restrict__ in, __m128i *__restrict__ out,
               const uint32_t bit) {
  Upack[bit](in, out);
}
}

template <class DeltaHelper> struct SIMDBitPackingHelpers {

  static void pack(uint32_t *in, const size_t Qty, uint32_t *out,
                   const uint32_t bit) {
    if (Qty % SIMDBlockSize) {
      throw std::logic_error("Incorrect # of entries.");
    }
    if (SIMDBlockSize % 32) {
      throw std::logic_error("Incorrect SIMDBlockSize.");
    }
    __m128i initoffset = _mm_set1_epi32(0);

    for (size_t k = 0; k < Qty / SIMDBlockSize; ++k) {
      __m128i nextoffset = MM_LOAD_SI_128(reinterpret_cast<__m128i *>(
          (in + k * SIMDBlockSize + SIMDBlockSize - 4)));

      if (bit < 32)
        SIMDDeltaProcessor<DeltaHelper, SIMDBlockSize>::runDelta(
            initoffset, in + k * SIMDBlockSize);
      simdpack(in + k * SIMDBlockSize,
               reinterpret_cast<__m128i *>(out + SIMDBlockSize * k * bit / 32),
               bit);
      initoffset = nextoffset;
    }
  }

  static void unpack(const uint32_t *in, size_t Qty, uint32_t *out,
                     const uint32_t bit) {
    if (Qty % SIMDBlockSize) {
      throw std::logic_error("Incorrect # of entries.");
    }
    __m128i initoffset = _mm_set1_epi32(0);

    for (size_t k = 0; k < Qty / SIMDBlockSize; ++k) {
      simdunpack(
          reinterpret_cast<const __m128i *>(in + SIMDBlockSize * k * bit / 32),
          out + k * SIMDBlockSize, bit);
      if (bit < 32) {
        initoffset =
            SIMDDeltaProcessor<DeltaHelper, SIMDBlockSize>::runPrefixSum(
                initoffset, out + k * SIMDBlockSize);
      }
    }
  }

  static void packwithoutmask(uint32_t *in, const size_t Qty, uint32_t *out,
                              const uint32_t bit) {
    if (Qty % SIMDBlockSize) {
      throw std::logic_error("Incorrect # of entries.");
    }
    __m128i initoffset = _mm_set1_epi32(0);

    for (size_t k = 0; k < Qty / SIMDBlockSize; ++k) {
      __m128i nextoffset = MM_LOAD_SI_128(reinterpret_cast<__m128i *>(
          (in + k * SIMDBlockSize + SIMDBlockSize - 4)));
      if (bit < 32)
        SIMDDeltaProcessor<DeltaHelper, SIMDBlockSize>::runDelta(
            initoffset, in + k * SIMDBlockSize);
      simdpackwithoutmask(
          in + k * SIMDBlockSize,
          reinterpret_cast<__m128i *>(out + SIMDBlockSize * k * bit / 32), bit);
      initoffset = nextoffset;
    }
  }

  static void ipack(const uint32_t *in, const size_t Qty, uint32_t *_out,
                    const uint32_t bit) {
    if (Qty % SIMDBlockSize) {
      throw std::logic_error("Incorrect # of entries.");
    }
    __m128i *out = reinterpret_cast<__m128i *>(_out);
    __m128i initoffset = _mm_set1_epi32(0U);
    ;

    for (size_t k = 0; k < Qty / SIMDBlockSize; ++k) {
      SIMDipack<DeltaHelper>(initoffset, in + k * SIMDBlockSize, out + k * bit,
                             bit);
      initoffset = MM_LOAD_SI_128(reinterpret_cast<const __m128i *>(
          in + k * SIMDBlockSize + SIMDBlockSize - 4));
      // memcpy(&initoffset, (in+k*SIMDBlockSize+SIMDBlockSize - 4), sizeof
      // initoffset);// Daniel: memcpy looks like a hack
    }
  }

  static void ipackwithoutmask(const uint32_t *in, const size_t Qty,
                               uint32_t *_out, const uint32_t bit) {
    if (Qty % SIMDBlockSize) {
      throw std::logic_error("Incorrect # of entries.");
    }
    __m128i *out = reinterpret_cast<__m128i *>(_out);
    __m128i initoffset = _mm_set1_epi32(0U);
    ;

    for (size_t k = 0; k < Qty / SIMDBlockSize; ++k) {
      SIMDipackwithoutmask<DeltaHelper>(initoffset, in + k * SIMDBlockSize,
                                        out + k * bit, bit);
      initoffset = MM_LOAD_SI_128(reinterpret_cast<const __m128i *>(
          in + k * SIMDBlockSize + SIMDBlockSize - 4));
      // memcpy(&initoffset, (in+k*SIMDBlockSize+SIMDBlockSize - 4), sizeof
      // initoffset);// Daniel: memcpy looks like a hack
    }
  }

  static void iunpack(const uint32_t *_in, size_t Qty, uint32_t *out,
                      const uint32_t bit) {
    if (Qty % SIMDBlockSize) {
      throw std::logic_error("Incorrect # of entries.");
    }
    const __m128i *in = reinterpret_cast<const __m128i *>(_in);

    __m128i initoffset = _mm_set1_epi32(0U);
    ;

    for (size_t k = 0; k < Qty / SIMDBlockSize; ++k) {
      initoffset = SIMDiunpack<DeltaHelper>(initoffset, in + k * bit,
                                            out + k * SIMDBlockSize, bit);
    }
  }

  // this is not expected to be useful, only for benchmarking
  static void ipatchedunpack(const uint32_t *_in, size_t Qty, uint32_t *out,
                             const uint32_t bit) {
    if (Qty % SIMDBlockSize) {
      throw std::logic_error("Incorrect # of entries.");
    }
    const __m128i *in = reinterpret_cast<const __m128i *>(_in);

    __m128i initoffset = _mm_set1_epi32(0U);
    ;

    for (size_t k = 0; k < Qty / SIMDBlockSize; ++k) {
      initoffset = SIMDipatchedunpack<DeltaHelper>(
          initoffset, in + k * bit, out + k * SIMDBlockSize,
          reinterpret_cast<const __m128i *>(out + k * SIMDBlockSize), bit);
    }
  }

  static void CheckMaxDiff(const std::vector<uint32_t> &refdata, unsigned bit) {
    for (size_t i = 4; i < refdata.size(); ++i) {
      if (gccbits(refdata[i] - refdata[i - 4]) > bit)
        throw std::runtime_error("bug");
    }
  }
};

} // namespace SIMDCompressionLib

#endif
