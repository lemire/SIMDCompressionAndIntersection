/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */
#ifndef SIMDCompressionAndIntersection_INTEGRATEDBITPACKING
#define SIMDCompressionAndIntersection_INTEGRATEDBITPACKING
#include <stdint.h>
#include "platform.h"

namespace SIMDCompressionLib {

void __integratedfastunpack0(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out);
void __integratedfastunpack1(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out);
void __integratedfastunpack2(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out);
void __integratedfastunpack3(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out);
void __integratedfastunpack4(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out);
void __integratedfastunpack5(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out);
void __integratedfastunpack6(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out);
void __integratedfastunpack7(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out);
void __integratedfastunpack8(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out);
void __integratedfastunpack9(const uint32_t initoffset,
                             const uint32_t *__restrict__ in,
                             uint32_t *__restrict__ out);
void __integratedfastunpack10(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack11(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack12(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack13(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack14(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack15(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack16(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack17(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack18(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack19(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack20(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack21(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack22(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack23(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack24(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack25(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack26(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack27(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack28(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack29(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack30(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack31(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);
void __integratedfastunpack32(const uint32_t initoffset,
                              const uint32_t *__restrict__ in,
                              uint32_t *__restrict__ out);

void __integratedfastpack0(const uint32_t initoffset,
                           const uint32_t *__restrict__ in,
                           uint32_t *__restrict__ out);
void __integratedfastpack1(const uint32_t initoffset,
                           const uint32_t *__restrict__ in,
                           uint32_t *__restrict__ out);
void __integratedfastpack2(const uint32_t initoffset,
                           const uint32_t *__restrict__ in,
                           uint32_t *__restrict__ out);
void __integratedfastpack3(const uint32_t initoffset,
                           const uint32_t *__restrict__ in,
                           uint32_t *__restrict__ out);
void __integratedfastpack4(const uint32_t initoffset,
                           const uint32_t *__restrict__ in,
                           uint32_t *__restrict__ out);
void __integratedfastpack5(const uint32_t initoffset,
                           const uint32_t *__restrict__ in,
                           uint32_t *__restrict__ out);
void __integratedfastpack6(const uint32_t initoffset,
                           const uint32_t *__restrict__ in,
                           uint32_t *__restrict__ out);
void __integratedfastpack7(const uint32_t initoffset,
                           const uint32_t *__restrict__ in,
                           uint32_t *__restrict__ out);
void __integratedfastpack8(const uint32_t initoffset,
                           const uint32_t *__restrict__ in,
                           uint32_t *__restrict__ out);
void __integratedfastpack9(const uint32_t initoffset,
                           const uint32_t *__restrict__ in,
                           uint32_t *__restrict__ out);
void __integratedfastpack10(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack11(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack12(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack13(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack14(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack15(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack16(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack17(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack18(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack19(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack20(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack21(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack22(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack23(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack24(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack25(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack26(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack27(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack28(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack29(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack30(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack31(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);
void __integratedfastpack32(const uint32_t initoffset,
                            const uint32_t *__restrict__ in,
                            uint32_t *__restrict__ out);

} // namespace SIMDCompressionLib

#endif // SIMDCompressionAndIntersection_INTEGRATEDBITPACKING
