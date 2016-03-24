/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef SIMDCompressionAndIntersection_CODECFACTORY_H_
#define SIMDCompressionAndIntersection_CODECFACTORY_H_

#include "common.h"
#include "codecs.h"
#include "common.h"
#include "compositecodec.h"
#include "bitpackinghelpers.h"
#include "simdbitpackinghelpers.h"
#include "delta.h"
#include "util.h"
#include "synthetic.h"
#include "binarypacking.h"
#include "simdbinarypacking.h"
#include "simdvariablebyte.h"
#include "fastpfor.h"
#include "simdfastpfor.h"
#include "variablebyte.h"
#include "varintgb.h"
#include "streamvariablebyte.h"
#include "VarIntG8IU.h" // warning: patented scheme
#include "frameofreference.h"
#include "forcodec.h"

namespace SIMDCompressionLib {

using namespace std;

typedef VariableByte<true> leftovercodec;

static std::map<string, shared_ptr<IntegerCODEC>> initializefactory() {
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

class CODECFactory {
public:
  static map<string, shared_ptr<IntegerCODEC>> scodecmap;
  static shared_ptr<IntegerCODEC> defaultptr;

  // hacked for convenience
  static vector<shared_ptr<IntegerCODEC>> allSchemes() {
    vector<shared_ptr<IntegerCODEC>> ans;
    for (auto i = scodecmap.begin(); i != scodecmap.end(); ++i) {
      ans.push_back(i->second);
    }
    return ans;
  }

  static vector<string> allNames() {
    vector<string> ans;
    for (auto i = scodecmap.begin(); i != scodecmap.end(); ++i) {
      ans.push_back(i->first);
    }
    return ans;
  }

  /**
   * This function tries to determine whether the
   * input is modified during compression.
   */
  static bool modifiesInputDuringCompression(IntegerCODEC &v) {
    vector<uint32_t> test;
    const uint32_t N = 2049;
    for (uint32_t k = 0; k < N; ++k)
      test.emplace_back(k);
    vector<uint32_t> out(N + 1024);
    size_t outsize = out.size();
    v.encodeArray(test.data(), N, out.data(), outsize);
    for (uint32_t k = 0; k < N; ++k)
      if (test[k] != k)
        return true;
    return false; // granted this is not full-proof, but is ok in our context
  }

  static string getName(IntegerCODEC &v) {
    for (auto i = scodecmap.begin(); i != scodecmap.end(); ++i) {
      if (i->second.get() == &v)
        return i->first;
    }
    return "UNKNOWN";
  }

  static bool valid(string name) {
    return (scodecmap.find(name) != scodecmap.end());
  }

  static shared_ptr<IntegerCODEC> &getFromName(string name) {
    if (scodecmap.find(name) == scodecmap.end()) {
      cerr << "name " << name << " does not refer to a CODEC." << endl;
      cerr << "possible choices:" << endl;
      for (auto i = scodecmap.begin(); i != scodecmap.end(); ++i) {
        cerr << static_cast<string>(i->first)
             << endl; // useless cast, but just to be clear
      }
      return defaultptr;
    }
    return scodecmap[name];
  }
};

map<string, shared_ptr<IntegerCODEC>> CODECFactory::scodecmap =
    initializefactory();

shared_ptr<IntegerCODEC> CODECFactory::defaultptr =
    shared_ptr<IntegerCODEC>(nullptr);
} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_CODECFACTORY_H_ */
