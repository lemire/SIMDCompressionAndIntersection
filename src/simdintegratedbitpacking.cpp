
/**
* This code is released under the
* Apache License Version 2.0 http://www.apache.org/licenses/.
*
*/
#include "simdintegratedbitpacking.h"

namespace SIMDCompressionLib {

template <class DeltaHelper>
__m128i iunpack0(__m128i initOffset, const __m128i *, uint32_t *_out) {
  __m128i *out = reinterpret_cast<__m128i *>(_out);
  static const __m128i zero = _mm_set1_epi32(0);

  for (unsigned i = 0; i < 8; ++i) {
    initOffset = DeltaHelper::PrefixSum(zero, initOffset);
    MM_STORE_SI_128(out++, initOffset);
    initOffset = DeltaHelper::PrefixSum(zero, initOffset);
    MM_STORE_SI_128(out++, initOffset);
    initOffset = DeltaHelper::PrefixSum(zero, initOffset);
    MM_STORE_SI_128(out++, initOffset);
    initOffset = DeltaHelper::PrefixSum(zero, initOffset);
    MM_STORE_SI_128(out++, initOffset);
  }

  return initOffset;
}

template <class DeltaHelper>
void ipackwithoutmask0(__m128i, const uint32_t *, __m128i *) {}

template <class DeltaHelper>
void ipack0(__m128i, const uint32_t *, __m128i *) {}

template <class DeltaHelper>
void ipackwithoutmask1(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack1(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(1U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask2(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack2(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(3U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask3(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 3 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 3 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack3(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(7U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 3 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 3 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask4(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack4(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(15U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask5(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack5(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(31U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask6(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack6(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(63U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask7(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack7(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(127U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask8(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack8(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(255U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask9(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack9(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(511U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask10(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack10(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(1023U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask11(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack11(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(2047U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask12(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack12(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(4095U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask13(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack13(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(8191U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask14(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack14(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(16383U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask15(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack15(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(32767U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask16(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack16(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(65535U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask17(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 15);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack17(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(131071U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 15);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask18(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack18(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(262143U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask19(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 17);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 15);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack19(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(524287U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 17);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 15);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask20(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack20(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(1048575U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask21(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 19);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 17);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 15);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack21(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(2097151U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 19);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 17);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 15);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask22(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack22(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(4194303U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask23(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 19);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 15);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 21);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 17);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack23(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(8388607U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 19);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 15);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 21);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 17);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask24(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack24(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(16777215U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask25(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 15);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 19);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 23);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 17);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 21);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack25(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(33554431U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 15);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 19);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 23);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 17);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 21);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask26(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack26(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(67108863U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask27(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 17);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 19);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 26);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 21);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 23);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 25);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 15);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack27(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(134217727U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 17);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 19);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 26);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 21);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 23);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 25);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 15);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask28(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack28(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(268435455U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask29(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 26);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 23);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 17);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 28);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 25);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 19);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 27);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 21);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 15);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack29(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(536870911U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 26);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 23);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 17);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 28);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 25);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 19);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 27);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 21);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 15);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask30(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 28);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 26);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 28);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 26);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack30(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(1073741823U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 28);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 26);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 28);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 26);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask31(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 30);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 29);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 28);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 27);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 26);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 25);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 23);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 21);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 19);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 17);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 15);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = DeltaHelper::Delta(CurrIn, initOffset);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack31(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  const __m128i mask = _mm_set1_epi32(2147483647U);
  ;

  __m128i CurrIn = MM_LOAD_SI_128(in);
  __m128i InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;
  OutReg = InReg;
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 30);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 29);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 28);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 27);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 26);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 25);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 24);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 23);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 22);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 21);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 20);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 19);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 18);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 17);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 16);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 15);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 14);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 13);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 12);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 11);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 10);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 9);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 8);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 7);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 6);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 5);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 4);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 3);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 2);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  MM_STORE_SI_128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 1);
  ++in;
  CurrIn = MM_LOAD_SI_128(in);
  InReg = _mm_and_si128(DeltaHelper::Delta(CurrIn, initOffset), mask);
  initOffset = CurrIn;

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipackwithoutmask32(__m128i /* initOffset */, const uint32_t *_in,
                        __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i InReg = MM_LOAD_SI_128(in);
  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
void ipack32(__m128i /* initOffset */, const uint32_t *_in, __m128i *out) {
  const __m128i *in = reinterpret_cast<const __m128i *>(_in);
  __m128i OutReg;

  __m128i InReg = MM_LOAD_SI_128(in);
  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);

  ++out;
  ++in;
  InReg = MM_LOAD_SI_128(in);

  OutReg = InReg;
  MM_STORE_SI_128(out, OutReg);
}

template <class DeltaHelper>
__m128i iunpack1(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 1) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack2(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 2) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack3(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 3) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 3 - 1), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 3 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack4(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 4) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack5(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 5) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 5 - 3), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 5 - 1), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 5 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 5 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack6(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 6) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 6 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 6 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 6 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 6 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack7(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 7) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 3), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 5), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 1), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack8(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 8) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack9(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 9) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 3), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 7), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 1), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 5), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack10(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 10) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack11(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 11) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 1), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 3), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 5), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 7), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 9), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack12(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 12) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack13(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 13) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 7), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 1), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 9), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 3), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 11), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 5), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack14(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 14) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack15(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 15) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 13), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 11), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 9), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 7), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 5), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 3), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 1), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack16(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 16) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack17(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 17) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 1), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 3), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 5), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 7), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 9), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 11), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 13), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 15), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack18(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 18) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack19(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 19) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 18), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 5), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 11), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 17), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 3), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 9), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 15), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 1), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 7), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 13), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack20(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 20) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack21(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 21) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 20), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 9), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 19), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 18), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 7), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 17), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 5), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 15), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 3), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 13), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 1), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 11), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack22(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 22) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 18), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 20), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 18), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 20), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack23(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 23) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 5), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 19), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 1), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 15), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 20), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 11), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 7), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 21), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 3), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 17), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 22), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 13), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 18), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 9), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack24(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 24) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack25(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 25) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 18), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 11), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 22), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 15), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 1), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 19), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 5), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 23), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 9), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 20), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 13), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 24), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 17), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 3), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 21), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 7), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack26(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 26) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 20), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 22), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 24), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 18), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 20), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 22), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 24), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 18), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack27(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 27) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 22), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 17), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 7), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 24), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 19), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 9), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 26), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 21), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 11), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 1), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 23), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 18), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 13), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 3), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 25), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 20), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 15), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 5), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack28(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 28) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 24), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 20), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 24), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 20), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 24), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 20), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 24), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 20), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack29(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 29) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 26), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 23), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 20), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 17), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 11), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 5), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 28), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 25), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 22), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 19), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 13), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 7), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 1), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 27), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 24), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 21), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 18), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 15), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 9), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 3), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack30(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 30) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 28), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 26), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 24), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 22), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 20), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 18), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 28), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 26), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 24), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 22), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 20), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 18), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack31(__m128i initOffset, const __m128i *in, uint32_t *_out) {

  __m128i *out = reinterpret_cast<__m128i *>(_out);
  __m128i InReg = MM_LOAD_SI_128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 31) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 30), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 29), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 28), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 27), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 26), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 25), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 24), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 23), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 22), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 21), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 20), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 19), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 18), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 17), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 16), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 15), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 14), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 13), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 12), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 11), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 10), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 9), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 8), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 7), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 6), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 5), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 4), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 3), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 2), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = tmp;
  ++in;
  InReg = MM_LOAD_SI_128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 1), mask));

  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = tmp;
  OutReg = DeltaHelper::PrefixSum(OutReg, initOffset);
  initOffset = OutReg;
  MM_STORE_SI_128(out++, OutReg);

  return initOffset;
}

template <class DeltaHelper>
__m128i iunpack32(__m128i, const __m128i *in, uint32_t *_out) {
  __m128i *mout = reinterpret_cast<__m128i *>(_out);
  __m128i invec;
  for (size_t k = 0; k < 128 / 4; ++k) {
    invec = MM_LOAD_SI_128(in++);
    MM_STORE_SI_128(mout++, invec);
  }
  return invec;
}

template __m128i iunpack0<RegularDeltaSIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack0<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask0<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack1<RegularDeltaSIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack1<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask1<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack2<RegularDeltaSIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack2<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask2<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack3<RegularDeltaSIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack3<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask3<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack4<RegularDeltaSIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack4<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask4<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack5<RegularDeltaSIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack5<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask5<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack6<RegularDeltaSIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack6<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask6<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack7<RegularDeltaSIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack7<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask7<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack8<RegularDeltaSIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack8<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask8<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack9<RegularDeltaSIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack9<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask9<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack10<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack10<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask10<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack11<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack11<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask11<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack12<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack12<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask12<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack13<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack13<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask13<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack14<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack14<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask14<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack15<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack15<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask15<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack16<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack16<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask16<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack17<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack17<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask17<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack18<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack18<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask18<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack19<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack19<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask19<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack20<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack20<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask20<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack21<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack21<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask21<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack22<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack22<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask22<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack23<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack23<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask23<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack24<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack24<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask24<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack25<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack25<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask25<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack26<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack26<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask26<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack27<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack27<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask27<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack28<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack28<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask28<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack29<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack29<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask29<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack30<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack30<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask30<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack31<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack31<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask31<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack32<RegularDeltaSIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack32<RegularDeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask32<RegularDeltaSIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack0<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack0<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask0<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack1<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack1<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask1<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack2<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack2<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask2<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack3<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack3<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask3<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack4<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack4<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask4<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack5<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack5<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask5<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack6<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack6<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask6<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack7<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack7<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask7<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack8<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack8<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask8<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack9<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack9<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask9<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack10<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack10<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask10<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack11<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack11<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask11<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack12<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack12<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask12<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack13<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack13<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask13<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack14<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack14<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask14<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack15<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack15<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask15<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack16<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack16<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask16<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack17<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack17<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask17<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack18<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack18<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask18<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack19<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack19<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask19<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack20<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack20<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask20<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack21<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack21<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask21<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack22<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack22<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask22<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack23<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack23<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask23<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack24<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack24<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask24<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack25<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack25<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask25<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack26<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack26<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask26<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack27<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack27<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask27<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack28<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack28<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask28<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack29<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack29<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask29<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack30<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack30<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask30<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack31<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack31<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask31<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack32<CoarseDelta4SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack32<CoarseDelta4SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask32<CoarseDelta4SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack0<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack0<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask0<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack1<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack1<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask1<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack2<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack2<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask2<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack3<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack3<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask3<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack4<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack4<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask4<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack5<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack5<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask5<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack6<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack6<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask6<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack7<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack7<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask7<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack8<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack8<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask8<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack9<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                            uint32_t *);
template void ipack9<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask9<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                  __m128i *);

template __m128i iunpack10<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack10<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask10<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack11<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack11<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask11<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack12<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack12<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask12<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack13<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack13<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask13<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack14<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack14<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask14<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack15<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack15<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask15<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack16<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack16<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask16<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack17<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack17<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask17<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack18<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack18<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask18<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack19<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack19<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask19<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack20<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack20<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask20<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack21<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack21<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask21<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack22<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack22<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask22<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack23<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack23<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask23<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack24<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack24<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask24<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack25<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack25<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask25<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack26<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack26<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask26<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack27<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack27<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask27<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack28<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack28<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask28<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack29<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack29<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask29<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack30<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack30<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask30<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack31<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack31<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask31<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack32<CoarseDelta2SIMD>(__m128i, const __m128i *,
                                             uint32_t *);
template void ipack32<CoarseDelta2SIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask32<CoarseDelta2SIMD>(__m128i, const uint32_t *,
                                                   __m128i *);

template __m128i iunpack0<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack0<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask0<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                               __m128i *);

template __m128i iunpack1<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack1<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask1<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                               __m128i *);

template __m128i iunpack2<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack2<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask2<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                               __m128i *);

template __m128i iunpack3<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack3<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask3<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                               __m128i *);

template __m128i iunpack4<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack4<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask4<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                               __m128i *);

template __m128i iunpack5<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack5<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask5<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                               __m128i *);

template __m128i iunpack6<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack6<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask6<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                               __m128i *);

template __m128i iunpack7<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack7<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask7<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                               __m128i *);

template __m128i iunpack8<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack8<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask8<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                               __m128i *);

template __m128i iunpack9<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack9<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask9<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                               __m128i *);

template __m128i iunpack10<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack10<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask10<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack11<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack11<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask11<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack12<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack12<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask12<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack13<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack13<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask13<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack14<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack14<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask14<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack15<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack15<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask15<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack16<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack16<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask16<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack17<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack17<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask17<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack18<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack18<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask18<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack19<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack19<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask19<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack20<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack20<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask20<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack21<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack21<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask21<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack22<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack22<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask22<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack23<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack23<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask23<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack24<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack24<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask24<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack25<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack25<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask25<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack26<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack26<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask26<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack27<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack27<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask27<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack28<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack28<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask28<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack29<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack29<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask29<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack30<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack30<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask30<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack31<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack31<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask31<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

template __m128i iunpack32<Max4DeltaSIMD>(__m128i, const __m128i *, uint32_t *);
template void ipack32<Max4DeltaSIMD>(__m128i, const uint32_t *, __m128i *);
template void ipackwithoutmask32<Max4DeltaSIMD>(__m128i, const uint32_t *,
                                                __m128i *);

} // namespace SIMDCompressionLib
