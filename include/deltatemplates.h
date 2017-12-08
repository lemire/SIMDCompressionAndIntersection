/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Leonid Boytsov, Nathan Kurz and Daniel Lemire
 */

#ifndef SIMDCompressionAndIntersection_DELTATEMPLATES_H_
#define SIMDCompressionAndIntersection_DELTATEMPLATES_H_

#include "common.h"

namespace SIMDCompressionLib {

/**
 * To avoid crazy dependencies, this header should not
 * include any other header file.
 */

/**
 * The structs RegularDeltaSIMD, NoDelta, CoarseDelta4SIMD, CoarseDelta2SIMD,
 * Max4DeltaSIMD
 * are used in templates to specify which type of differential encoding to use
 * (if any).
 *
 * See SIMDDeltaProcessor
 */

struct RegularDeltaSIMD {
  // Folklore code, unknown origin of this idea
  ALWAYS_INLINE
  static __m128i PrefixSum(__m128i curr, __m128i prev) {
    const __m128i _tmp1 = _mm_add_epi32(_mm_slli_si128(curr, 8), curr);
    const __m128i _tmp2 = _mm_add_epi32(_mm_slli_si128(_tmp1, 4), _tmp1);
    return _mm_add_epi32(_tmp2, _mm_shuffle_epi32(prev, 0xff));
  }

  ALWAYS_INLINE
  static __m128i Delta(__m128i curr, __m128i prev) {
    return _mm_sub_epi32(curr, _mm_alignr_epi8(curr, prev, 12));
    // for older processors (pre-SSSE3): 
    //return _mm_sub_epi32(
    //    curr, _mm_or_si128(_mm_slli_si128(curr, 4), _mm_srli_si128(prev, 12)));
  }

  static bool usesDifferentialEncoding() { return true; }

  static std::string name() { return "Delta1"; }
};

struct NoDelta {
  ALWAYS_INLINE
  static __m128i PrefixSum(__m128i curr, __m128i) { return curr; }
  ALWAYS_INLINE
  static __m128i Delta(__m128i curr, __m128i) { return curr; }

  static bool usesDifferentialEncoding() { return false; }
  static std::string name() { return "NoDelta"; }
};

struct CoarseDelta4SIMD {
  ALWAYS_INLINE
  // Proposed and implemented by L. Boytosv
  static __m128i PrefixSum(__m128i curr, __m128i prev) {
    return _mm_add_epi32(curr, prev);
  }
  ALWAYS_INLINE
  static __m128i Delta(__m128i curr, __m128i prev) {
    return _mm_sub_epi32(curr, prev);
  }

  static bool usesDifferentialEncoding() { return true; }

  static std::string name() { return "Delta4"; }
};

struct CoarseDelta2SIMD {
  ALWAYS_INLINE
  // Proposed and implemented by L. Boytosv
  static __m128i PrefixSum(__m128i curr, __m128i prev) {
    const __m128i _tmp1 = _mm_add_epi32(_mm_slli_si128(curr, 8), curr);
    return _mm_add_epi32(_tmp1,
                         _mm_shuffle_epi32(prev, _MM_SHUFFLE(3, 2, 3, 2)));
  }
  ALWAYS_INLINE
  static __m128i Delta(__m128i curr, __m128i prev) {
    return _mm_sub_epi32(
        curr, _mm_or_si128(_mm_slli_si128(curr, 8), _mm_srli_si128(prev, 8)));
  }
  static bool usesDifferentialEncoding() { return true; }

  static std::string name() { return "Delta2"; }
};

struct Max4DeltaSIMD {
  ALWAYS_INLINE
  // The idea is due to N. Kurz
  static __m128i PrefixSum(__m128i curr, __m128i prev) {
    return _mm_add_epi32(curr, _mm_shuffle_epi32(prev, 0xff));
  }
  ALWAYS_INLINE
  static __m128i Delta(__m128i curr, __m128i prev) {
    return _mm_sub_epi32(curr, _mm_shuffle_epi32(prev, 0xff));
  }
  static std::string name() { return "DeltaM4"; }

  static bool usesDifferentialEncoding() { return true; }
};

/**
 * Wrapper around  the structs RegularDeltaSIMD, NoDelta, CoarseDelta4SIMD,
 * CoarseDelta2SIMD, Max4DeltaSIMD
 * to compute differential encoding and prefix sums.
 */
template <class DeltaHelper, size_t TotalQty> struct SIMDDeltaProcessor {
  static __m128i runPrefixSum(__m128i initOffset, uint32_t *pData) {
    const size_t QtyDivBy4 = TotalQty / 4;
    // The block should contain 8N 32-bit integers, where N is some integer
    assert(QtyDivBy4 % 2 == 0);

    __m128i *pCurr = reinterpret_cast<__m128i *>(pData);
    const __m128i *pEnd = pCurr + QtyDivBy4;

    // Leonid Boytsov: manual loop unrolling may be crucial here.
    while (pCurr < pEnd) {
      initOffset = DeltaHelper::PrefixSum(MM_LOAD_SI_128(pCurr), initOffset);
      MM_STORE_SI_128(pCurr++, initOffset);

      initOffset = DeltaHelper::PrefixSum(MM_LOAD_SI_128(pCurr), initOffset);
      MM_STORE_SI_128(pCurr++, initOffset);
    }

    return initOffset;
  }

  static void runDelta(__m128i initOffset, uint32_t *pData) {
    const size_t QtyDivBy4 = TotalQty / 4;
    // The block should contain 8N 32-bit integers, where N is some integer
    assert(QtyDivBy4 && QtyDivBy4 % 2 == 0);
    __m128i *pCurr = reinterpret_cast<__m128i *>(pData) + QtyDivBy4 - 1;
    __m128i *pStart = reinterpret_cast<__m128i *>(pData);
    __m128i a = MM_LOAD_SI_128(pCurr);
    // Leonid Boytsov: manual loop unrolling may be crucial here.
    while (pCurr > pStart + 1) {
      __m128i b = MM_LOAD_SI_128(pCurr - 1);
      MM_STORE_SI_128(pCurr, DeltaHelper::Delta(a, b));
      a = b;
      --pCurr;

      b = MM_LOAD_SI_128(pCurr - 1);
      MM_STORE_SI_128(pCurr, DeltaHelper::Delta(a, b));
      a = b;
      --pCurr;
    }

    __m128i b = MM_LOAD_SI_128(pStart);
    MM_STORE_SI_128(pStart + 1, DeltaHelper::Delta(a, b));
    a = b;

    MM_STORE_SI_128(pStart, DeltaHelper::Delta(a, initOffset));
  }
};

} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_DELTATEMPLATES_H_ */
