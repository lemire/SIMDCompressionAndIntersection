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


} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_CODECFACTORY_H_ */
