/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Leonid Boytsov, Nathan Kurz and Daniel Lemire
 */

#ifndef SIMDCompressionAndIntersection_SIMD_INTEGRATED_BITPACKING_H
#define SIMDCompressionAndIntersection_SIMD_INTEGRATED_BITPACKING_H

/**
 * To avoid crazy dependencies, this header should not
 * include any other header beside delta.h.
 */
#include "deltatemplates.h"

namespace SIMDCompressionLib {

template <class DeltaHelper>
__m128i iunpack0(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack0(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack0(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask0(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack1(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack1(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack1(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask1(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack2(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack2(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack2(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask2(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack3(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack3(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack3(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask3(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack4(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack4(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack4(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask4(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack5(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack5(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack5(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask5(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack6(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack6(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack6(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask6(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack7(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack7(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack7(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask7(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack8(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack8(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack8(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask8(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack9(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack9(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack9(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask9(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack10(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack10(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack10(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask10(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack11(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack11(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack11(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask11(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack12(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack12(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack12(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask12(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack13(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack13(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack13(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask13(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack14(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack14(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack14(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask14(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack15(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack15(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack15(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask15(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack16(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack16(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack16(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask16(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack17(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack17(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack17(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask17(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack18(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack18(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack18(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask18(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack19(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack19(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack19(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask19(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack20(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack20(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack20(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask20(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack21(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack21(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack21(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask21(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack22(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack22(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack22(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask22(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack23(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack23(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack23(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask23(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack24(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack24(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack24(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask24(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack25(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack25(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack25(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask25(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack26(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack26(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack26(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask26(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack27(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack27(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack27(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask27(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack28(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack28(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack28(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask28(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack29(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack29(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack29(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask29(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack30(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack30(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack30(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask30(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack31(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack31(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack31(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask31(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper>
__m128i iunpack32(__m128i, const __m128i *, uint32_t *);
template <class DeltaHelper>
__m128i ipatchedunpack32(__m128i, const __m128i *, uint32_t *, const __m128i *);
template <class DeltaHelper> void ipack32(__m128i, const uint32_t *, __m128i *);
template <class DeltaHelper>
void ipackwithoutmask32(__m128i, const uint32_t *, __m128i *);

typedef __m128i (*integratedunpackingfunction)(__m128i, const __m128i *,
                                               uint32_t *);
typedef __m128i (*integratedpatchedunpackingfunction)(__m128i, const __m128i *,
                                                      uint32_t *,
                                                      const __m128i *);

typedef void (*integratedpackingfunction)(__m128i, const uint32_t *, __m128i *);

template <class DeltaHelper> struct IntegratedArrayDispatch {
  static integratedunpackingfunction unpack[33];

  static inline __m128i SIMDiunpack(__m128i initOffset, const __m128i *in,
                                    uint32_t *out, const uint32_t bit) {
    return unpack[bit](initOffset, in, out);
  }
  static integratedpatchedunpackingfunction patchedunpack[33];

  static inline __m128i SIMDipatchedunpack(__m128i initOffset,
                                           const __m128i *in, uint32_t *out,
                                           const __m128i *patchedbuffer,
                                           const uint32_t bit) {
    return patchedunpack[bit](initOffset, in, out, patchedbuffer);
  }
  static integratedpackingfunction packwithoutmask[33];

  static inline void SIMDipackwithoutmask(__m128i initOffset,
                                          const uint32_t *in, __m128i *out,
                                          const uint32_t bit) {
    packwithoutmask[bit](initOffset, in, out);
  }
  static integratedpackingfunction pack[33];

  static inline void SIMDipack(__m128i initOffset, const uint32_t *in,
                               __m128i *out, const uint32_t bit) {
    pack[bit](initOffset, in, out);
  }
};

template <class DeltaHelper>
integratedunpackingfunction IntegratedArrayDispatch<DeltaHelper>::unpack[33] = {
    iunpack0<DeltaHelper>,  iunpack1<DeltaHelper>,  iunpack2<DeltaHelper>,
    iunpack3<DeltaHelper>,  iunpack4<DeltaHelper>,  iunpack5<DeltaHelper>,
    iunpack6<DeltaHelper>,  iunpack7<DeltaHelper>,  iunpack8<DeltaHelper>,
    iunpack9<DeltaHelper>,  iunpack10<DeltaHelper>, iunpack11<DeltaHelper>,
    iunpack12<DeltaHelper>, iunpack13<DeltaHelper>, iunpack14<DeltaHelper>,
    iunpack15<DeltaHelper>, iunpack16<DeltaHelper>, iunpack17<DeltaHelper>,
    iunpack18<DeltaHelper>, iunpack19<DeltaHelper>, iunpack20<DeltaHelper>,
    iunpack21<DeltaHelper>, iunpack22<DeltaHelper>, iunpack23<DeltaHelper>,
    iunpack24<DeltaHelper>, iunpack25<DeltaHelper>, iunpack26<DeltaHelper>,
    iunpack27<DeltaHelper>, iunpack28<DeltaHelper>, iunpack29<DeltaHelper>,
    iunpack30<DeltaHelper>, iunpack31<DeltaHelper>, iunpack32<DeltaHelper>};

template <class DeltaHelper>
integratedpatchedunpackingfunction
    IntegratedArrayDispatch<DeltaHelper>::patchedunpack[33] = {
        ipatchedunpack0<DeltaHelper>,  ipatchedunpack1<DeltaHelper>,
        ipatchedunpack2<DeltaHelper>,  ipatchedunpack3<DeltaHelper>,
        ipatchedunpack4<DeltaHelper>,  ipatchedunpack5<DeltaHelper>,
        ipatchedunpack6<DeltaHelper>,  ipatchedunpack7<DeltaHelper>,
        ipatchedunpack8<DeltaHelper>,  ipatchedunpack9<DeltaHelper>,
        ipatchedunpack10<DeltaHelper>, ipatchedunpack11<DeltaHelper>,
        ipatchedunpack12<DeltaHelper>, ipatchedunpack13<DeltaHelper>,
        ipatchedunpack14<DeltaHelper>, ipatchedunpack15<DeltaHelper>,
        ipatchedunpack16<DeltaHelper>, ipatchedunpack17<DeltaHelper>,
        ipatchedunpack18<DeltaHelper>, ipatchedunpack19<DeltaHelper>,
        ipatchedunpack20<DeltaHelper>, ipatchedunpack21<DeltaHelper>,
        ipatchedunpack22<DeltaHelper>, ipatchedunpack23<DeltaHelper>,
        ipatchedunpack24<DeltaHelper>, ipatchedunpack25<DeltaHelper>,
        ipatchedunpack26<DeltaHelper>, ipatchedunpack27<DeltaHelper>,
        ipatchedunpack28<DeltaHelper>, ipatchedunpack29<DeltaHelper>,
        ipatchedunpack30<DeltaHelper>, ipatchedunpack31<DeltaHelper>,
        ipatchedunpack32<DeltaHelper>};

template <class DeltaHelper>
integratedpackingfunction
    IntegratedArrayDispatch<DeltaHelper>::packwithoutmask[33] = {
        ipackwithoutmask0<DeltaHelper>,  ipackwithoutmask1<DeltaHelper>,
        ipackwithoutmask2<DeltaHelper>,  ipackwithoutmask3<DeltaHelper>,
        ipackwithoutmask4<DeltaHelper>,  ipackwithoutmask5<DeltaHelper>,
        ipackwithoutmask6<DeltaHelper>,  ipackwithoutmask7<DeltaHelper>,
        ipackwithoutmask8<DeltaHelper>,  ipackwithoutmask9<DeltaHelper>,
        ipackwithoutmask10<DeltaHelper>, ipackwithoutmask11<DeltaHelper>,
        ipackwithoutmask12<DeltaHelper>, ipackwithoutmask13<DeltaHelper>,
        ipackwithoutmask14<DeltaHelper>, ipackwithoutmask15<DeltaHelper>,
        ipackwithoutmask16<DeltaHelper>, ipackwithoutmask17<DeltaHelper>,
        ipackwithoutmask18<DeltaHelper>, ipackwithoutmask19<DeltaHelper>,
        ipackwithoutmask20<DeltaHelper>, ipackwithoutmask21<DeltaHelper>,
        ipackwithoutmask22<DeltaHelper>, ipackwithoutmask23<DeltaHelper>,
        ipackwithoutmask24<DeltaHelper>, ipackwithoutmask25<DeltaHelper>,
        ipackwithoutmask26<DeltaHelper>, ipackwithoutmask27<DeltaHelper>,
        ipackwithoutmask28<DeltaHelper>, ipackwithoutmask29<DeltaHelper>,
        ipackwithoutmask30<DeltaHelper>, ipackwithoutmask31<DeltaHelper>,
        ipackwithoutmask32<DeltaHelper>};

template <class DeltaHelper>
integratedpackingfunction IntegratedArrayDispatch<DeltaHelper>::pack[33] = {
    ipack0<DeltaHelper>,  ipack1<DeltaHelper>,  ipack2<DeltaHelper>,
    ipack3<DeltaHelper>,  ipack4<DeltaHelper>,  ipack5<DeltaHelper>,
    ipack6<DeltaHelper>,  ipack7<DeltaHelper>,  ipack8<DeltaHelper>,
    ipack9<DeltaHelper>,  ipack10<DeltaHelper>, ipack11<DeltaHelper>,
    ipack12<DeltaHelper>, ipack13<DeltaHelper>, ipack14<DeltaHelper>,
    ipack15<DeltaHelper>, ipack16<DeltaHelper>, ipack17<DeltaHelper>,
    ipack18<DeltaHelper>, ipack19<DeltaHelper>, ipack20<DeltaHelper>,
    ipack21<DeltaHelper>, ipack22<DeltaHelper>, ipack23<DeltaHelper>,
    ipack24<DeltaHelper>, ipack25<DeltaHelper>, ipack26<DeltaHelper>,
    ipack27<DeltaHelper>, ipack28<DeltaHelper>, ipack29<DeltaHelper>,
    ipack30<DeltaHelper>, ipack31<DeltaHelper>, ipack32<DeltaHelper>};

template <class DeltaHelper>
inline __m128i SIMDiunpack(__m128i initOffset, const __m128i *in, uint32_t *out,
                           const uint32_t bit) {
  switch (bit) {
  case 0:
    return iunpack0<DeltaHelper>(initOffset, in, out);

  case 1:
    return iunpack1<DeltaHelper>(initOffset, in, out);

  case 2:
    return iunpack2<DeltaHelper>(initOffset, in, out);

  case 3:
    return iunpack3<DeltaHelper>(initOffset, in, out);

  case 4:
    return iunpack4<DeltaHelper>(initOffset, in, out);

  case 5:
    return iunpack5<DeltaHelper>(initOffset, in, out);

  case 6:
    return iunpack6<DeltaHelper>(initOffset, in, out);

  case 7:
    return iunpack7<DeltaHelper>(initOffset, in, out);

  case 8:
    return iunpack8<DeltaHelper>(initOffset, in, out);

  case 9:
    return iunpack9<DeltaHelper>(initOffset, in, out);

  case 10:
    return iunpack10<DeltaHelper>(initOffset, in, out);

  case 11:
    return iunpack11<DeltaHelper>(initOffset, in, out);

  case 12:
    return iunpack12<DeltaHelper>(initOffset, in, out);

  case 13:
    return iunpack13<DeltaHelper>(initOffset, in, out);

  case 14:
    return iunpack14<DeltaHelper>(initOffset, in, out);

  case 15:
    return iunpack15<DeltaHelper>(initOffset, in, out);

  case 16:
    return iunpack16<DeltaHelper>(initOffset, in, out);

  case 17:
    return iunpack17<DeltaHelper>(initOffset, in, out);

  case 18:
    return iunpack18<DeltaHelper>(initOffset, in, out);

  case 19:
    return iunpack19<DeltaHelper>(initOffset, in, out);

  case 20:
    return iunpack20<DeltaHelper>(initOffset, in, out);

  case 21:
    return iunpack21<DeltaHelper>(initOffset, in, out);

  case 22:
    return iunpack22<DeltaHelper>(initOffset, in, out);

  case 23:
    return iunpack23<DeltaHelper>(initOffset, in, out);

  case 24:
    return iunpack24<DeltaHelper>(initOffset, in, out);

  case 25:
    return iunpack25<DeltaHelper>(initOffset, in, out);

  case 26:
    return iunpack26<DeltaHelper>(initOffset, in, out);

  case 27:
    return iunpack27<DeltaHelper>(initOffset, in, out);

  case 28:
    return iunpack28<DeltaHelper>(initOffset, in, out);

  case 29:
    return iunpack29<DeltaHelper>(initOffset, in, out);

  case 30:
    return iunpack30<DeltaHelper>(initOffset, in, out);

  case 31:
    return iunpack31<DeltaHelper>(initOffset, in, out);

  case 32:
    return iunpack32<DeltaHelper>(initOffset, in, out);

  default:
    break;
  }
  throw std::logic_error("number of bits is unsupported");
}

template <class DeltaHelper>
inline __m128i SIMDipatchedunpack(__m128i initOffset, const __m128i *in,
                                  uint32_t *out, const __m128i *patchedbuffer,
                                  const uint32_t bit) {
  switch (bit) {
  case 0:
    return ipatchedunpack0<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 1:
    return ipatchedunpack1<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 2:
    return ipatchedunpack2<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 3:
    return ipatchedunpack3<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 4:
    return ipatchedunpack4<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 5:
    return ipatchedunpack5<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 6:
    return ipatchedunpack6<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 7:
    return ipatchedunpack7<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 8:
    return ipatchedunpack8<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 9:
    return ipatchedunpack9<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 10:
    return ipatchedunpack10<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 11:
    return ipatchedunpack11<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 12:
    return ipatchedunpack12<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 13:
    return ipatchedunpack13<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 14:
    return ipatchedunpack14<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 15:
    return ipatchedunpack15<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 16:
    return ipatchedunpack16<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 17:
    return ipatchedunpack17<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 18:
    return ipatchedunpack18<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 19:
    return ipatchedunpack19<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 20:
    return ipatchedunpack20<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 21:
    return ipatchedunpack21<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 22:
    return ipatchedunpack22<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 23:
    return ipatchedunpack23<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 24:
    return ipatchedunpack24<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 25:
    return ipatchedunpack25<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 26:
    return ipatchedunpack26<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 27:
    return ipatchedunpack27<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 28:
    return ipatchedunpack28<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 29:
    return ipatchedunpack29<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 30:
    return ipatchedunpack30<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 31:
    return ipatchedunpack31<DeltaHelper>(initOffset, in, out, patchedbuffer);

  case 32:
    return ipatchedunpack32<DeltaHelper>(initOffset, in, out, patchedbuffer);

  default:
    break;
  }
  throw std::logic_error("number of bits is unsupported");
}

/*assumes that integers fit in the prescribed number of bits*/
template <class DeltaHelper>
void SIMDipackwithoutmask(__m128i initOffset, const uint32_t *in, __m128i *out,
                          const uint32_t bit) {
  switch (bit) {
  case 0:
    return;

  case 1:
    ipackwithoutmask1<DeltaHelper>(initOffset, in, out);
    return;

  case 2:
    ipackwithoutmask2<DeltaHelper>(initOffset, in, out);
    return;

  case 3:
    ipackwithoutmask3<DeltaHelper>(initOffset, in, out);
    return;

  case 4:
    ipackwithoutmask4<DeltaHelper>(initOffset, in, out);
    return;

  case 5:
    ipackwithoutmask5<DeltaHelper>(initOffset, in, out);
    return;

  case 6:
    ipackwithoutmask6<DeltaHelper>(initOffset, in, out);
    return;

  case 7:
    ipackwithoutmask7<DeltaHelper>(initOffset, in, out);
    return;

  case 8:
    ipackwithoutmask8<DeltaHelper>(initOffset, in, out);
    return;

  case 9:
    ipackwithoutmask9<DeltaHelper>(initOffset, in, out);
    return;

  case 10:
    ipackwithoutmask10<DeltaHelper>(initOffset, in, out);
    return;

  case 11:
    ipackwithoutmask11<DeltaHelper>(initOffset, in, out);
    return;

  case 12:
    ipackwithoutmask12<DeltaHelper>(initOffset, in, out);
    return;

  case 13:
    ipackwithoutmask13<DeltaHelper>(initOffset, in, out);
    return;

  case 14:
    ipackwithoutmask14<DeltaHelper>(initOffset, in, out);
    return;

  case 15:
    ipackwithoutmask15<DeltaHelper>(initOffset, in, out);
    return;

  case 16:
    ipackwithoutmask16<DeltaHelper>(initOffset, in, out);
    return;

  case 17:
    ipackwithoutmask17<DeltaHelper>(initOffset, in, out);
    return;

  case 18:
    ipackwithoutmask18<DeltaHelper>(initOffset, in, out);
    return;

  case 19:
    ipackwithoutmask19<DeltaHelper>(initOffset, in, out);
    return;

  case 20:
    ipackwithoutmask20<DeltaHelper>(initOffset, in, out);
    return;

  case 21:
    ipackwithoutmask21<DeltaHelper>(initOffset, in, out);
    return;

  case 22:
    ipackwithoutmask22<DeltaHelper>(initOffset, in, out);
    return;

  case 23:
    ipackwithoutmask23<DeltaHelper>(initOffset, in, out);
    return;

  case 24:
    ipackwithoutmask24<DeltaHelper>(initOffset, in, out);
    return;

  case 25:
    ipackwithoutmask25<DeltaHelper>(initOffset, in, out);
    return;

  case 26:
    ipackwithoutmask26<DeltaHelper>(initOffset, in, out);
    return;

  case 27:
    ipackwithoutmask27<DeltaHelper>(initOffset, in, out);
    return;

  case 28:
    ipackwithoutmask28<DeltaHelper>(initOffset, in, out);
    return;

  case 29:
    ipackwithoutmask29<DeltaHelper>(initOffset, in, out);
    return;

  case 30:
    ipackwithoutmask30<DeltaHelper>(initOffset, in, out);
    return;

  case 31:
    ipackwithoutmask31<DeltaHelper>(initOffset, in, out);
    return;

  case 32:
    ipackwithoutmask32<DeltaHelper>(initOffset, in, out);
    return;

  default:
    break;
  }
  throw std::logic_error("number of bits is unsupported");
}

template <class DeltaHelper>
void SIMDipack(__m128i initOffset, const uint32_t *in, __m128i *out,
               const uint32_t bit) {
  switch (bit) {
  case 0:
    return;

  case 1:
    ipack1<DeltaHelper>(initOffset, in, out);
    return;

  case 2:
    ipack2<DeltaHelper>(initOffset, in, out);
    return;

  case 3:
    ipack3<DeltaHelper>(initOffset, in, out);
    return;

  case 4:
    ipack4<DeltaHelper>(initOffset, in, out);
    return;

  case 5:
    ipack5<DeltaHelper>(initOffset, in, out);
    return;

  case 6:
    ipack6<DeltaHelper>(initOffset, in, out);
    return;

  case 7:
    ipack7<DeltaHelper>(initOffset, in, out);
    return;

  case 8:
    ipack8<DeltaHelper>(initOffset, in, out);
    return;

  case 9:
    ipack9<DeltaHelper>(initOffset, in, out);
    return;

  case 10:
    ipack10<DeltaHelper>(initOffset, in, out);
    return;

  case 11:
    ipack11<DeltaHelper>(initOffset, in, out);
    return;

  case 12:
    ipack12<DeltaHelper>(initOffset, in, out);
    return;

  case 13:
    ipack13<DeltaHelper>(initOffset, in, out);
    return;

  case 14:
    ipack14<DeltaHelper>(initOffset, in, out);
    return;

  case 15:
    ipack15<DeltaHelper>(initOffset, in, out);
    return;

  case 16:
    ipack16<DeltaHelper>(initOffset, in, out);
    return;

  case 17:
    ipack17<DeltaHelper>(initOffset, in, out);
    return;

  case 18:
    ipack18<DeltaHelper>(initOffset, in, out);
    return;

  case 19:
    ipack19<DeltaHelper>(initOffset, in, out);
    return;

  case 20:
    ipack20<DeltaHelper>(initOffset, in, out);
    return;

  case 21:
    ipack21<DeltaHelper>(initOffset, in, out);
    return;

  case 22:
    ipack22<DeltaHelper>(initOffset, in, out);
    return;

  case 23:
    ipack23<DeltaHelper>(initOffset, in, out);
    return;

  case 24:
    ipack24<DeltaHelper>(initOffset, in, out);
    return;

  case 25:
    ipack25<DeltaHelper>(initOffset, in, out);
    return;

  case 26:
    ipack26<DeltaHelper>(initOffset, in, out);
    return;

  case 27:
    ipack27<DeltaHelper>(initOffset, in, out);
    return;

  case 28:
    ipack28<DeltaHelper>(initOffset, in, out);
    return;

  case 29:
    ipack29<DeltaHelper>(initOffset, in, out);
    return;

  case 30:
    ipack30<DeltaHelper>(initOffset, in, out);
    return;

  case 31:
    ipack31<DeltaHelper>(initOffset, in, out);
    return;

  case 32:
    ipack32<DeltaHelper>(initOffset, in, out);
    return;

  default:
    break;
  }
  throw std::logic_error("number of bits is unsupported");
}

} // namespace SIMDCompressionLib

#endif
