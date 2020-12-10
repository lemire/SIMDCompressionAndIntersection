/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 */

#include "codecfactory.h"

namespace SIMDCompressionLib {

std::map<string, shared_ptr<IntegerCODEC>> initializefactory() {
  std::map<string, shared_ptr<IntegerCODEC>> schemes;
#ifdef __SSSE3__
  schemes["varintg8iu"] = shared_ptr<IntegerCODEC>(new VarIntG8IU<true>());
#endif /* __SSSE3__ */
  schemes["fastpfor"] = shared_ptr<IntegerCODEC>(
          new CompositeCodec<FastPFor<8, true>, leftovercodec>());

  schemes["copy"] = shared_ptr<IntegerCODEC>(new JustCopy());
  schemes["varint"] = shared_ptr<IntegerCODEC>(new VariableByte<true>());
  schemes["vbyte"] = shared_ptr<IntegerCODEC>(new VByte<true>());
  schemes["maskedvbyte"] = shared_ptr<IntegerCODEC>(new MaskedVByte<true>());
  schemes["streamvbyte"] = shared_ptr<IntegerCODEC>(new StreamVByteD1());
  schemes["frameofreference"] =
          shared_ptr<IntegerCODEC>(new FrameOfReference());

  schemes["simdframeofreference"] =
          shared_ptr<IntegerCODEC>(new SIMDFrameOfReference());

  schemes["varintgb"] = std::shared_ptr<IntegerCODEC>(new VarIntGB<true>());

  schemes["s4-fastpfor-d4"] = shared_ptr<IntegerCODEC>(
          new CompositeCodec<SIMDFastPFor<8, CoarseDelta4SIMD>, leftovercodec>());
  schemes["s4-fastpfor-dm"] = shared_ptr<IntegerCODEC>(
          new CompositeCodec<SIMDFastPFor<8, Max4DeltaSIMD>, VariableByte<true>>());
  schemes["s4-fastpfor-d1"] = shared_ptr<IntegerCODEC>(
          new CompositeCodec<SIMDFastPFor<8, RegularDeltaSIMD>, leftovercodec>());
  schemes["s4-fastpfor-d2"] = shared_ptr<IntegerCODEC>(
          new CompositeCodec<SIMDFastPFor<8, CoarseDelta2SIMD>, leftovercodec>());

  schemes["bp32"] = shared_ptr<IntegerCODEC>(
          new CompositeCodec<BinaryPacking<BasicBlockPacker>,
          VariableByte<true>>());
  schemes["ibp32"] = shared_ptr<IntegerCODEC>(
          new CompositeCodec<BinaryPacking<IntegratedBlockPacker>,
          leftovercodec>());

  schemes["s4-bp128-d1-ni"] = shared_ptr<IntegerCODEC>(
          new CompositeCodec<
          SIMDBinaryPacking<SIMDBlockPacker<RegularDeltaSIMD, true>>,
          leftovercodec>());
  schemes["s4-bp128-d2-ni"] = shared_ptr<IntegerCODEC>(
          new CompositeCodec<
          SIMDBinaryPacking<SIMDBlockPacker<CoarseDelta2SIMD, true>>,
          leftovercodec>());
  schemes["s4-bp128-d4-ni"] = shared_ptr<IntegerCODEC>(
          new CompositeCodec<
          SIMDBinaryPacking<SIMDBlockPacker<CoarseDelta4SIMD, true>>,
          leftovercodec>());
  schemes["s4-bp128-dm-ni"] = shared_ptr<IntegerCODEC>(
          new CompositeCodec<
          SIMDBinaryPacking<SIMDBlockPacker<Max4DeltaSIMD, true>>,
          leftovercodec>());

  schemes["s4-bp128-d1"] = shared_ptr<IntegerCODEC>(
          new CompositeCodec<
          SIMDBinaryPacking<SIMDIntegratedBlockPacker<RegularDeltaSIMD, true>>,
          leftovercodec>());
  schemes["s4-bp128-d2"] = shared_ptr<IntegerCODEC>(
          new CompositeCodec<
          SIMDBinaryPacking<SIMDIntegratedBlockPacker<CoarseDelta2SIMD, true>>,
          leftovercodec>());
  schemes["s4-bp128-d4"] = shared_ptr<IntegerCODEC>(
          new CompositeCodec<
          SIMDBinaryPacking<SIMDIntegratedBlockPacker<CoarseDelta4SIMD, true>>,
          leftovercodec>());
  schemes["s4-bp128-dm"] = shared_ptr<IntegerCODEC>(
          new CompositeCodec<
          SIMDBinaryPacking<SIMDIntegratedBlockPacker<Max4DeltaSIMD, true>>,
          leftovercodec>());
  schemes["for"] = shared_ptr<IntegerCODEC>(new ForCODEC());
  return schemes;
}


map<string, shared_ptr<IntegerCODEC>> CODECFactory::scodecmap =
        initializefactory();

shared_ptr<IntegerCODEC> CODECFactory::defaultptr =
        shared_ptr<IntegerCODEC>(nullptr);

}
