/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire
 */
#include "simdbitpacking.h"

namespace SIMDCompressionLib {
using namespace std;

void __SIMD_fastpackwithoutmask0(const uint32_t *__restrict__,
                                 __m128i *__restrict__) {}
void __SIMD_fastpack0(const uint32_t *__restrict__, __m128i *__restrict__) {}
/**
 * Rest of the code is borrowed from the fastpfor project (file of the same
 * name)
 * with the removal of a few functions at the end and removal of the  prefix.
 * Also
 * functions are no longer static.
 */

void __SIMD_fastpackwithoutmask1(const uint32_t *__restrict__ _in,
                                 __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask2(const uint32_t *__restrict__ _in,
                                 __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask3(const uint32_t *__restrict__ _in,
                                 __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 3 - 1);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 3 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask5(const uint32_t *__restrict__ _in,
                                 __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 3);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 1);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask6(const uint32_t *__restrict__ _in,
                                 __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask7(const uint32_t *__restrict__ _in,
                                 __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 3);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 5);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 1);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask9(const uint32_t *__restrict__ _in,
                                 __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 3);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 7);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 1);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 5);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask10(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask11(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 1);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 3);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 5);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 7);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 9);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask12(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask13(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 7);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 1);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 9);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 3);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 11);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 5);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask14(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask15(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 13);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 11);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 9);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 7);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 5);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 3);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 1);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask17(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 1);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 3);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 5);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 7);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 9);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 11);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 13);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 15);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask18(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask19(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 5);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 11);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 17);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 3);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 9);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 15);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 1);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 7);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 13);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask20(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask21(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 9);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 19);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 7);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 17);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 5);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 15);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 3);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 13);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 1);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 11);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask22(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask23(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 5);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 19);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 1);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 15);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 11);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 7);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 21);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 3);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 17);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 13);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 9);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask24(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask25(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 11);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 15);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 1);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 19);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 5);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 23);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 9);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 13);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 17);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 3);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 21);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 7);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask26(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask27(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 17);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 7);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 19);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 9);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 21);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 11);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 1);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 23);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 13);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 3);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 25);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 15);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 5);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask28(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask29(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 23);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 17);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 11);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 5);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 25);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 19);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 13);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 7);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 1);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 27);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 21);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 15);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 9);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 3);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask30(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask31(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 29);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 27);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 25);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 23);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 21);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 19);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 17);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 15);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 13);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 11);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 9);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 7);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 5);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 3);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 1);
  InReg = MM_LOAD_SI_128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask32(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpackwithoutmask4(const uint32_t *__restrict__ _in,
                                 __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg;

  for (uint32_t outer = 0; outer < 4; ++outer) {
    InReg = MM_LOAD_SI_128(in);
    OutReg = InReg;

    InReg = MM_LOAD_SI_128(in + 1);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));

    InReg = MM_LOAD_SI_128(in + 2);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));

    InReg = MM_LOAD_SI_128(in + 3);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));

    InReg = MM_LOAD_SI_128(in + 4);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));

    InReg = MM_LOAD_SI_128(in + 5);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));

    InReg = MM_LOAD_SI_128(in + 6);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));

    InReg = MM_LOAD_SI_128(in + 7);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    MM_STORE_SI_128(out, OutReg);
    ++out;

    in += 8;
  }
}

void __SIMD_fastpackwithoutmask8(const uint32_t *__restrict__ _in,
                                 __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg;

  for (uint32_t outer = 0; outer < 8; ++outer) {
    InReg = MM_LOAD_SI_128(in);
    OutReg = InReg;

    InReg = MM_LOAD_SI_128(in + 1);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));

    InReg = MM_LOAD_SI_128(in + 2);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));

    InReg = MM_LOAD_SI_128(in + 3);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    MM_STORE_SI_128(out, OutReg);
    ++out;

    in += 4;
  }
}

void __SIMD_fastpackwithoutmask16(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg;

  for (uint32_t outer = 0; outer < 16; ++outer) {
    InReg = MM_LOAD_SI_128(in);
    OutReg = InReg;

    InReg = MM_LOAD_SI_128(in + 1);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    MM_STORE_SI_128(out, OutReg);
    ++out;

    in += 2;
  }
}

void __SIMD_fastpack1(const uint32_t *__restrict__ _in,
                      __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 1) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack2(const uint32_t *__restrict__ _in,
                      __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 2) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack3(const uint32_t *__restrict__ _in,
                      __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 3) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 3 - 1);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 3 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack5(const uint32_t *__restrict__ _in,
                      __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 5) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 3);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 1);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack6(const uint32_t *__restrict__ _in,
                      __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 6) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack7(const uint32_t *__restrict__ _in,
                      __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 7) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 3);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 5);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 1);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack9(const uint32_t *__restrict__ _in,
                      __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 9) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 3);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 7);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 1);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 5);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack10(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 10) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack11(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 11) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 1);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 3);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 5);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 7);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 9);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack12(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 12) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack13(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 13) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 7);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 1);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 9);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 3);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 11);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 5);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack14(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 14) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack15(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 15) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 13);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 11);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 9);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 7);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 5);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 3);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 1);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack17(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 17) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 1);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 3);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 5);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 7);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 9);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 11);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 13);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 15);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack18(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 18) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack19(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 19) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 18);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 5);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 11);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 17);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 3);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 9);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 15);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 1);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 7);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 13);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack20(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 20) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack21(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 21) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 20);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 9);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 19);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 18);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 7);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 17);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 5);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 15);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 3);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 13);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 1);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 11);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack22(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 22) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 18);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 20);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 18);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 20);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack23(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 23) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 5);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 19);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 1);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 15);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 20);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 11);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 7);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 21);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 3);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 17);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 22);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 13);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 18);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 9);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack24(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 24) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack25(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 25) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 18);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 11);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 22);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 15);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 1);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 19);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 5);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 23);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 9);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 20);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 13);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 24);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 17);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 3);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 21);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 7);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack26(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 26) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 20);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 22);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 24);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 18);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 20);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 22);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 24);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 18);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack27(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 27) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 22);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 17);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 7);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 24);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 19);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 9);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 26);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 21);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 11);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 1);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 23);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 18);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 13);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 3);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 25);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 20);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 15);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 5);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack28(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 28) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack29(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 29) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 26);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 23);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 20);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 17);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 11);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 5);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 28);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 25);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 22);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 19);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 13);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 7);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 1);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 27);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 24);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 21);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 18);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 15);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 9);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 3);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack30(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 30) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 28);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 26);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 24);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 22);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 20);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 18);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 28);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 26);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 24);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 22);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 20);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 18);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack31(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 31) - 1);

  __m128i InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 30);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 29);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 28);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 27);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 26);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 25);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 24);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 23);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 22);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 21);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 20);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 19);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 18);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 17);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 16);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 15);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 14);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 13);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 12);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 11);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 10);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 9);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 8);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 7);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 6);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 5);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 4);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 3);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 2);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  MM_STORE_SI_128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 1);
  InReg = _mm_and_si128(MM_LOAD_SI_128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack32(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i InReg = MM_LOAD_SI_128(in);
  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
  ++out;
  InReg = MM_LOAD_SI_128(++in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
}

void __SIMD_fastpack4(const uint32_t *__restrict__ _in,
                      __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg, InReg;
  const __m128i mask = _mm_set1_epi32((1U << 4) - 1);

  for (uint32_t outer = 0; outer < 4; ++outer) {
    InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
    OutReg = InReg;

    InReg = _mm_and_si128(MM_LOAD_SI_128(in + 1), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));

    InReg = _mm_and_si128(MM_LOAD_SI_128(in + 2), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));

    InReg = _mm_and_si128(MM_LOAD_SI_128(in + 3), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));

    InReg = _mm_and_si128(MM_LOAD_SI_128(in + 4), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));

    InReg = _mm_and_si128(MM_LOAD_SI_128(in + 5), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));

    InReg = _mm_and_si128(MM_LOAD_SI_128(in + 6), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));

    InReg = _mm_and_si128(MM_LOAD_SI_128(in + 7), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    MM_STORE_SI_128(out, OutReg);
    ++out;

    in += 8;
  }
}

void __SIMD_fastpack8(const uint32_t *__restrict__ _in,
                      __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg, InReg;
  const __m128i mask = _mm_set1_epi32((1U << 8) - 1);

  for (uint32_t outer = 0; outer < 8; ++outer) {
    InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
    OutReg = InReg;

    InReg = _mm_and_si128(MM_LOAD_SI_128(in + 1), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));

    InReg = _mm_and_si128(MM_LOAD_SI_128(in + 2), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));

    InReg = _mm_and_si128(MM_LOAD_SI_128(in + 3), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    MM_STORE_SI_128(out, OutReg);
    ++out;

    in += 4;
  }
}

void __SIMD_fastpack16(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg, InReg;
  const __m128i mask = _mm_set1_epi32((1U << 16) - 1);

  for (uint32_t outer = 0; outer < 16; ++outer) {
    InReg = _mm_and_si128(MM_LOAD_SI_128(in), mask);
    OutReg = InReg;

    InReg = _mm_and_si128(MM_LOAD_SI_128(in + 1), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    MM_STORE_SI_128(out, OutReg);
    ++out;

    in += 2;
  }
}

void __SIMD_fastunpack1(const __m128i *__restrict__ in,
                        uint32_t *__restrict__ _out) {
  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg1 = MM_LOAD_SI_128(in);
  __m128i InReg2 = InReg1;
  __m128i OutReg1, OutReg2, OutReg3, OutReg4;
  const __m128i mask = _mm_set1_epi32(1);

  unsigned shift = 0;

  for (unsigned i = 0; i < 8; ++i) {
    OutReg1 = _mm_and_si128(_mm_srli_epi32(InReg1, shift++), mask);
    OutReg2 = _mm_and_si128(_mm_srli_epi32(InReg2, shift++), mask);
    OutReg3 = _mm_and_si128(_mm_srli_epi32(InReg1, shift++), mask);
    OutReg4 = _mm_and_si128(_mm_srli_epi32(InReg2, shift++), mask);
    MM_STORE_SI_128(out++, OutReg1);
    MM_STORE_SI_128(out++, OutReg2);
    MM_STORE_SI_128(out++, OutReg3);
    MM_STORE_SI_128(out++, OutReg4);
  }
}

void __SIMD_fastunpack2(const __m128i *__restrict__ in,
                        uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 2) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 22), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 26), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 28), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 22), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 26), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 28), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack3(const __m128i *__restrict__ in,
                        uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 3) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 15), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 21), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 27), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 3 - 1), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 13), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 19), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 22), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 25), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 28), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 3 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 17), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 23), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 26), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack4(const __m128i *__restrict__ in,
                        uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 4) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack5(const __m128i *__restrict__ in,
                        uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 5) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 15), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 25), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 5 - 3), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 13), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 23), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 5 - 1), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 21), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 26), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 5 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 19), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 5 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 17), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 22), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack6(const __m128i *__restrict__ in,
                        uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 6) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 6 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 22), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 6 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 6 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 22), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 6 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack7(const __m128i *__restrict__ in,
                        uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 7) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 21), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 3), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 17), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 13), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 23), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 5), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 19), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 1), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 15), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 22), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack8(const __m128i *__restrict__ in,
                        uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 8) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack9(const __m128i *__restrict__ in,
                        uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 9) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 13), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 22), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 17), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 3), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 21), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 7), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 15), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 1), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 19), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 5), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack10(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 10) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack11(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 11) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 1), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 13), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 3), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 15), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 5), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 17), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 7), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 19), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 9), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack12(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 12) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack13(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 13) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 13), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 7), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 1), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 15), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 9), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 3), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 17), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 11), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 5), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack14(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 14) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack15(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 15) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 15), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 13), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 13), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 11), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 9), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 7), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 5), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 3), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 1), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack16(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 16) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack17(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 17) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 1), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 3), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 5), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 7), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 9), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 11), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 13), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 13), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 15), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 15);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack18(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 18) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack19(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 19) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 18), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 5), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 11), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 17), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 3), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 9), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 15), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 15);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 1), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 7), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 13), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 13);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack20(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 20) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack21(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 21) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 20), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 9), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 19), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 18), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 7), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 17), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 5), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 15), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 15);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 3), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 13), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 13);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 1), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 11), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 11);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack22(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 22) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 18), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 20), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 18), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 20), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack23(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 23) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 5), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 19), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 1), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 15), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 15);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 20), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 11), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 11);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 7), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 21), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 3), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 17), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 22), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 13), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 13);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 18), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 9), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 9);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack24(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 24) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack25(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 25) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 18), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 11), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 11);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 22), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 15), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 15);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 1), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 19), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 5), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 23), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 9), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 9);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 20), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 13), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 13);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 24), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 17), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 3), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 21), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 7), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 7);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack26(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 26) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 20), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 22), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 24), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 18), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 6);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 20), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 22), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 24), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 18), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 6);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack27(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 27) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 22), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 17), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 7), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 7);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 24), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 19), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 9), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 9);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 26), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 21), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 11), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 11);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 1), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 23), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 18), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 13), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 13);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 3), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 25), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 20), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 15), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 15);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 5), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 5);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack28(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 28) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 24), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 20), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 4);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 24), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 20), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 4);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 24), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 20), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 4);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 24), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 20), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 4);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack29(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 29) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 26), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 23), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 20), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 17), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 11), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 11);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 5), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 5);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 28), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 25), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 22), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 19), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 13), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 13);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 7), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 7);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 1), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 27), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 24), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 21), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 18), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 15), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 15);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 9), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 9);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 3), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 3);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack30(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 30) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 28), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 26), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 24), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 22), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 20), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 18), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 2);
  InReg = MM_LOAD_SI_128(++in);

  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 28), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 26), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 24), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 22), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 20), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 18), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 2);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack31(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 31) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 30), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 29), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 28), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 27), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 26), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 25), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 24), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 23), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 22), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 21), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 20), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 19), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 18), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 17), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 16), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 15), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 15);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 14), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 13), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 13);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 12), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 11), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 11);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 10), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 9), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 9);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 8), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 7), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 7);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 6), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 6);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 5), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 5);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 4), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 4);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 3), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 3);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 2), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 2);
  InReg = MM_LOAD_SI_128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 1), mask));
  MM_STORE_SI_128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 1);
  MM_STORE_SI_128(out++, OutReg);
}

void __SIMD_fastunpack32(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {
  __m128i *out = reinterpret_cast<__m128i *>(_out);
  for (uint32_t outer = 0; outer < 32; ++outer) {
    MM_STORE_SI_128(out++, MM_LOAD_SI_128(in++));
  }
}

} // namespace SIMDCompressionLib
