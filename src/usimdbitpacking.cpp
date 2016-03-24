/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire
 */
#include "simdbitpacking.h"

namespace SIMDCompressionLib {
using namespace std;

/**
 * This is generated from simdbitpacking.cpp by replacing _mm_load_si128 with
 * _mm_loadu_si128
 * and _mm_storeu_si128 by _mm_storeu_si128.
 */

void __uSIMD_fastpackwithoutmask0(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  (void)_in;
  (void)out;
}

void __uSIMD_fastpackwithoutmask1(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask2(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask3(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 3 - 1);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 3 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask5(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 3);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 1);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask6(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask7(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 3);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 5);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 1);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask9(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 3);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 7);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 1);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 5);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask10(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask11(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 1);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 3);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 5);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 7);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 9);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask12(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask13(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 7);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 1);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 9);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 3);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 11);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 5);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask14(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask15(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 13);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 11);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 9);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 7);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 5);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 3);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 1);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask17(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 1);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 3);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 5);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 7);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 9);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 11);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 13);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 15);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask18(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask19(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 18);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 5);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 11);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 17);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 3);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 9);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 15);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 1);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 7);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 13);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask20(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask21(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 20);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 9);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 19);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 18);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 7);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 17);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 5);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 15);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 3);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 13);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 1);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 11);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask22(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 18);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 20);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 18);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 20);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask23(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 5);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 19);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 1);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 15);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 20);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 11);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 7);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 21);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 3);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 17);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 22);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 13);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 18);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 9);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask24(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask25(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 18);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 11);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 22);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 15);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 1);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 19);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 5);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 23);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 9);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 20);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 13);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 24);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 17);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 3);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 21);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 7);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask26(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 20);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 22);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 24);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 18);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 20);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 22);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 24);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 18);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask27(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 22);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 17);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 7);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 24);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 19);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 9);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 26);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 21);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 11);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 1);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 23);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 18);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 13);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 3);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 25);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 20);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 15);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 5);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask28(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask29(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 26);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 23);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 20);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 17);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 11);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 5);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 28);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 25);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 22);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 19);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 13);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 7);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 1);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 27);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 24);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 21);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 18);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 15);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 9);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 3);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask30(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 28);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 26);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 24);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 22);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 20);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 18);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 28);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 26);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 24);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 22);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 20);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 18);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask31(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 30);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 29);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 28);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 27);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 26);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 25);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 24);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 23);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 22);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 21);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 20);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 19);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 18);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 17);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 16);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 15);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 14);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 13);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 12);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 11);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 10);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 9);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 8);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 7);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 6);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 5);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 4);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 3);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 2);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 1);
  InReg = _mm_loadu_si128(++in);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask32(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpackwithoutmask4(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg;

  for (uint32_t outer = 0; outer < 4; ++outer) {
    InReg = _mm_loadu_si128(in);
    OutReg = InReg;

    InReg = _mm_loadu_si128(in + 1);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));

    InReg = _mm_loadu_si128(in + 2);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));

    InReg = _mm_loadu_si128(in + 3);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));

    InReg = _mm_loadu_si128(in + 4);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));

    InReg = _mm_loadu_si128(in + 5);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));

    InReg = _mm_loadu_si128(in + 6);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));

    InReg = _mm_loadu_si128(in + 7);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_storeu_si128(out, OutReg);
    ++out;

    in += 8;
  }
}

void __uSIMD_fastpackwithoutmask8(const uint32_t *__restrict__ _in,
                                  __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg;

  for (uint32_t outer = 0; outer < 8; ++outer) {
    InReg = _mm_loadu_si128(in);
    OutReg = InReg;

    InReg = _mm_loadu_si128(in + 1);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));

    InReg = _mm_loadu_si128(in + 2);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));

    InReg = _mm_loadu_si128(in + 3);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_storeu_si128(out, OutReg);
    ++out;

    in += 4;
  }
}

void __uSIMD_fastpackwithoutmask16(const uint32_t *__restrict__ _in,
                                   __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;
  __m128i InReg;

  for (uint32_t outer = 0; outer < 16; ++outer) {
    InReg = _mm_loadu_si128(in);
    OutReg = InReg;

    InReg = _mm_loadu_si128(in + 1);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_storeu_si128(out, OutReg);
    ++out;

    in += 2;
  }
}

void __uSIMD_fastpack0(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  (void)_in;
  (void)out;
}

void __uSIMD_fastpack1(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 1) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack2(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 2) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack3(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 3) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 3 - 1);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 3 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack5(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 5) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 3);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 1);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack6(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 6) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack7(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 7) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 3);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 5);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 1);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack9(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 9) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 3);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 7);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 1);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 5);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack10(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 10) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack11(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 11) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 1);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 3);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 5);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 7);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 9);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack12(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 12) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack13(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 13) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 7);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 1);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 9);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 3);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 11);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 5);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack14(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 14) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack15(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 15) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 13);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 11);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 9);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 7);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 5);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 3);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 1);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack17(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 17) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 1);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 3);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 5);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 7);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 9);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 11);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 13);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 15);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack18(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 18) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack19(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 19) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 18);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 5);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 11);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 17);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 3);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 9);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 15);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 1);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 7);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 13);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack20(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 20) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack21(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 21) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 20);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 9);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 19);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 18);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 7);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 17);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 5);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 15);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 3);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 13);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 1);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 11);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack22(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 22) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 18);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 20);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 18);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 20);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack23(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 23) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 5);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 19);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 1);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 15);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 20);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 11);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 7);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 21);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 3);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 17);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 22);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 13);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 18);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 9);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack24(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 24) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack25(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 25) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 18);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 11);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 22);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 15);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 1);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 19);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 5);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 23);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 9);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 20);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 13);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 24);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 17);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 3);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 21);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 7);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack26(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 26) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 20);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 22);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 24);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 18);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 20);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 22);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 24);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 18);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack27(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 27) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 22);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 17);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 7);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 24);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 19);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 9);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 26);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 21);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 11);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 1);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 23);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 18);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 13);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 3);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 25);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 20);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 15);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 5);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack28(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 28) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack29(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 29) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 26);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 23);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 20);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 17);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 11);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 5);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 28);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 25);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 22);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 19);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 13);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 7);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 1);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 27);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 24);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 21);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 18);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 15);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 9);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 3);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack30(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 30) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 28);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 26);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 24);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 22);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 20);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 18);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 28);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 26);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 24);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 22);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 20);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 18);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack31(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32((1U << 31) - 1);

  __m128i InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
  OutReg = InReg;
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 30);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 29);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 28);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 27);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 26);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 25);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 24);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 23);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 22);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 21);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 20);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 19);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 18);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 17);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 16);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 15);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 14);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 13);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 12);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 11);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 10);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 9);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 8);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 7);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 6);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 5);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 4);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 3);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 2);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  _mm_storeu_si128(out, OutReg);
  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 1);
  InReg = _mm_and_si128(_mm_loadu_si128(++in), mask);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack32(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i InReg = _mm_loadu_si128(in);
  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
  ++out;
  InReg = _mm_loadu_si128(++in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
}

void __uSIMD_fastpack4(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg, InReg;
  const __m128i mask = _mm_set1_epi32((1U << 4) - 1);

  for (uint32_t outer = 0; outer < 4; ++outer) {
    InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
    OutReg = InReg;

    InReg = _mm_and_si128(_mm_loadu_si128(in + 1), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));

    InReg = _mm_and_si128(_mm_loadu_si128(in + 2), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));

    InReg = _mm_and_si128(_mm_loadu_si128(in + 3), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));

    InReg = _mm_and_si128(_mm_loadu_si128(in + 4), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));

    InReg = _mm_and_si128(_mm_loadu_si128(in + 5), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));

    InReg = _mm_and_si128(_mm_loadu_si128(in + 6), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));

    InReg = _mm_and_si128(_mm_loadu_si128(in + 7), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_storeu_si128(out, OutReg);
    ++out;

    in += 8;
  }
}

void __uSIMD_fastpack8(const uint32_t *__restrict__ _in,
                       __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg, InReg;
  const __m128i mask = _mm_set1_epi32((1U << 8) - 1);

  for (uint32_t outer = 0; outer < 8; ++outer) {
    InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
    OutReg = InReg;

    InReg = _mm_and_si128(_mm_loadu_si128(in + 1), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));

    InReg = _mm_and_si128(_mm_loadu_si128(in + 2), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));

    InReg = _mm_and_si128(_mm_loadu_si128(in + 3), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_storeu_si128(out, OutReg);
    ++out;

    in += 4;
  }
}

void __uSIMD_fastpack16(const uint32_t *__restrict__ _in,
                        __m128i *__restrict__ out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg, InReg;
  const __m128i mask = _mm_set1_epi32((1U << 16) - 1);

  for (uint32_t outer = 0; outer < 16; ++outer) {
    InReg = _mm_and_si128(_mm_loadu_si128(in), mask);
    OutReg = InReg;

    InReg = _mm_and_si128(_mm_loadu_si128(in + 1), mask);
    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_storeu_si128(out, OutReg);
    ++out;

    in += 2;
  }
}

void __uSIMD_fastunpack1(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {
  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg1 = _mm_loadu_si128(in);
  __m128i InReg2 = InReg1;
  __m128i OutReg1, OutReg2, OutReg3, OutReg4;
  const __m128i mask = _mm_set1_epi32(1);

  unsigned shift = 0;

  for (unsigned i = 0; i < 8; ++i) {
    OutReg1 = _mm_and_si128(_mm_srli_epi32(InReg1, shift++), mask);
    OutReg2 = _mm_and_si128(_mm_srli_epi32(InReg2, shift++), mask);
    OutReg3 = _mm_and_si128(_mm_srli_epi32(InReg1, shift++), mask);
    OutReg4 = _mm_and_si128(_mm_srli_epi32(InReg2, shift++), mask);
    _mm_storeu_si128(out++, OutReg1);
    _mm_storeu_si128(out++, OutReg2);
    _mm_storeu_si128(out++, OutReg3);
    _mm_storeu_si128(out++, OutReg4);
  }
}

void __uSIMD_fastunpack2(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 2) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 22), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 26), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 28), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 22), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 26), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 28), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack3(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 3) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 15), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 21), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 27), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 3 - 1), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 13), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 19), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 22), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 25), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 28), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 3 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 17), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 23), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 26), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack4(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 4) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack5(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 5) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 15), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 25), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 5 - 3), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 13), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 23), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 5 - 1), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 21), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 26), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 5 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 19), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 5 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 17), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 22), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack6(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 6) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 6 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 22), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 6 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 6 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 22), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 6 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack7(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 7) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 21), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 3), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 17), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 24), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 13), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 23), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 5), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 19), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 1), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 15), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 22), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack8(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 8) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack9(const __m128i *__restrict__ in,
                         uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 9) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 13), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 22), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 17), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 3), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 21), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 7), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 15), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 1), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 19), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 5), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack10(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 10) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack11(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 11) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 1), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 13), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 3), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 15), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 5), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 17), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 7), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 19), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 9), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 20), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack12(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 12) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack13(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 13) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 13), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 7), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 1), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 15), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 9), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 3), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 17), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 11), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 5), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 18), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack14(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 14) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack15(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 15) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 15), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 13), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 13), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 11), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 9), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 7), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 5), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 3), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 1), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 16), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack16(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 16) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack17(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 17) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 14), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 1), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 3), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 5), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 7), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 9), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 11), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 13), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 13), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 15), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 15);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack18(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 18) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack19(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 19) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 12), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 18), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 5), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 11), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 11), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 17), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 3), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 9), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 15), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 15);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 1), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 7), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 13), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 13);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack20(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 20) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack21(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 21) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 10), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 20), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 9), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 9), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 19), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 18), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 7), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 17), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 5), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 15), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 15);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 3), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 13), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 13);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 1), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 11), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 11);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack22(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 22) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 18), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 20), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 18), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 20), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack23(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 23) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 5), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 19), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 1), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 15), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 15);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 20), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 11), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 11);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 7), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 7), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 21), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 3), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 17), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 8), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 22), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 13), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 13);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 18), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 9), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 9);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack24(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 24) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack25(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 25) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 18), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 11), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 11);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 22), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 15), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 15);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 1), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 19), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 5), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 5), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 23), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 9), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 9);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 20), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 13), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 13);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 6), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 24), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 17), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 3), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 21), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 7), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 7);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack26(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 26) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 20), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 22), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 24), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 18), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 6);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 20), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 22), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 24), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 18), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 6);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack27(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 27) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 22), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 17), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 7), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 7);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 24), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 19), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 9), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 9);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 4), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 26), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 21), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 11), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 11);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 6);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 1), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 23), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 18), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 13), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 13);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 3), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 3), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 25), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 20), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 15), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 15);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 5), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 5);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack28(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 28) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 24), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 20), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 4);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 24), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 20), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 4);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 24), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 20), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 4);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 24), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 20), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 4);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack29(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 29) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 26), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 23), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 20), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 17), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 11), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 11);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 5), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 5);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 2), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 28), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 25), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 22), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 19), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 13), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 13);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 7), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 7);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 4);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 1), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(_mm_srli_epi32(InReg, 1), mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 27), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 24), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 21), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 18), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 15), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 15);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 9), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 9);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 6);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 3), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 3);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack30(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 30) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 28), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 26), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 24), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 22), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 20), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 18), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 6);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 4);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 2);
  InReg = _mm_loadu_si128(++in);

  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 28), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 26), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 24), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 22), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 20), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 18), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 6);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 4);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 2);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack31(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  const __m128i mask = _mm_set1_epi32((1U << 31) - 1);

  OutReg = _mm_and_si128(InReg, mask);
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 31);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 30), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 30);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 29), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 29);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 28), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 28);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 27), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 27);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 26), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 26);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 25), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 25);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 24), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 24);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 23), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 23);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 22), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 22);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 21), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 21);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 20), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 20);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 19), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 19);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 18), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 18);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 17), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 17);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 16), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 16);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 15), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 15);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 14), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 14);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 13), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 13);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 12), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 12);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 11), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 11);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 10), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 10);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 9), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 9);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 8), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 8);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 7), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 7);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 6), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 6);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 5), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 5);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 4), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 4);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 3), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 3);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 2), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 2);
  InReg = _mm_loadu_si128(++in);

  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 1), mask));
  _mm_storeu_si128(out++, OutReg);

  OutReg = _mm_srli_epi32(InReg, 1);
  _mm_storeu_si128(out++, OutReg);
}

void __uSIMD_fastunpack32(const __m128i *__restrict__ in,
                          uint32_t *__restrict__ _out) {
  __m128i *out = reinterpret_cast<__m128i *>(_out);
  for (uint32_t outer = 0; outer < 32; ++outer) {
    _mm_storeu_si128(out++, _mm_loadu_si128(in++));
  }
}

} // namespace SIMDCompressionLib
