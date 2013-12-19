/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef CODECFACTORY_H_
#define CODECFACTORY_H_

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
#include "fastpfor.h"
#include "simdfastpfor.h"
#include "variablebyte.h"

using namespace std;

typedef VariableByte<true>  leftovercodec;

static std::map<string, shared_ptr<IntegerCODEC> > initializefactory() {
    std::map < string, shared_ptr<IntegerCODEC> > schemes;

    schemes["fastpfor"] = shared_ptr<IntegerCODEC> (
            new CompositeCodec<FastPFor<true> ,
            leftovercodec > ());


    schemes["copy"] = shared_ptr<IntegerCODEC> (new JustCopy());

    schemes["varint"] = shared_ptr<IntegerCODEC> (new VariableByte<true> ());
    schemes["s-fastpfor-4"] = shared_ptr<IntegerCODEC> (
            new CompositeCodec<SIMDFastPFor<CoarseDelta4SIMD> , leftovercodec > ());

    schemes["s-fastpfor-m"]
            = shared_ptr<IntegerCODEC> (
                    new CompositeCodec<SIMDFastPFor<Max4DeltaSIMD> ,
                            VariableByte<true> > ());
    schemes["s-fastpfor-1"] = shared_ptr<IntegerCODEC> (
            new CompositeCodec<SIMDFastPFor<RegularDeltaSIMD> , leftovercodec > ());
    schemes["s-fastpfor-2"] = shared_ptr<IntegerCODEC> (
            new CompositeCodec<SIMDFastPFor<CoarseDelta2SIMD> , leftovercodec > ());

    schemes["bp32"] = shared_ptr<IntegerCODEC> (
            new CompositeCodec<BinaryPacking<BasicBlockPacker> , VariableByte<
                    true> > ());
    schemes["ibp32"] = shared_ptr<IntegerCODEC> (
            new CompositeCodec<BinaryPacking<IntegratedBlockPacker> ,
            leftovercodec > ());

    schemes["s-bp128+d1"] = shared_ptr<IntegerCODEC> (
            new CompositeCodec < SIMDBinaryPacking<SIMDBlockPacker<
                    RegularDeltaSIMD, true> > , leftovercodec > ());
    schemes["s-bp128+d2"] = shared_ptr<IntegerCODEC> (
            new CompositeCodec < SIMDBinaryPacking<SIMDBlockPacker<
                    CoarseDelta2SIMD, true> >, leftovercodec > ());
    schemes["s-bp128+d4"] = shared_ptr<IntegerCODEC> (
            new CompositeCodec < SIMDBinaryPacking<SIMDBlockPacker<
                    CoarseDelta4SIMD, true> >, leftovercodec > ());
    schemes["s-bp128+dm"] = shared_ptr<IntegerCODEC> (
            new CompositeCodec < SIMDBinaryPacking<SIMDBlockPacker<
                    Max4DeltaSIMD, true> >, leftovercodec > ());

    schemes["s-bp128-1"] = shared_ptr<IntegerCODEC> (
            new CompositeCodec < SIMDBinaryPacking<SIMDIntegratedBlockPacker<
                    RegularDeltaSIMD, true> >, leftovercodec > ());
    schemes["s-bp128-2"] = shared_ptr<IntegerCODEC> (
            new CompositeCodec < SIMDBinaryPacking<SIMDIntegratedBlockPacker<
                    CoarseDelta2SIMD, true> >, leftovercodec > ());
    schemes["s-bp128-4"] = shared_ptr<IntegerCODEC> (
            new CompositeCodec < SIMDBinaryPacking<SIMDIntegratedBlockPacker<
                    CoarseDelta4SIMD, true> >, leftovercodec > ());
    schemes["s-bp128-m"] = shared_ptr<IntegerCODEC> (
            new CompositeCodec < SIMDBinaryPacking<SIMDIntegratedBlockPacker<
                    Max4DeltaSIMD, true> >, leftovercodec > ());

    return schemes;
}



class CODECFactory {
public:
    static map<string, shared_ptr<IntegerCODEC> > scodecmap;
    static shared_ptr<IntegerCODEC> defaultptr;

    // hacked for convenience
    static vector<shared_ptr<IntegerCODEC> > allSchemes() {
        vector < shared_ptr<IntegerCODEC> > ans;
        for (auto i = scodecmap.begin(); i != scodecmap.end(); ++i) {
            ans.push_back(i->second);
        }
        return ans;
    }

    static vector<string> allNames() {
        vector < string > ans;
        for (auto i = scodecmap.begin(); i != scodecmap.end(); ++i) {
            ans.push_back(i->first);
        }
        return ans;
    }

    /**
     * This function tries to determine whether the
     * input is modified during compression.
     */
    static bool modifiesInputDuringCompression(IntegerCODEC & v) {
        vector<uint32_t> test;
        const uint32_t N = 2049;
        for(uint32_t k = 0; k < N; ++k)
            test.emplace_back(k);
        vector<uint32_t> out(N+1024);
        size_t outsize = out.size();
        v.encodeArray(test.data(),N,out.data(),outsize);
        for(uint32_t k = 0; k < N; ++k)
            if(test[k] != k) return true;
        return false; // granted this is not full-proof, but is ok in our context
    }

    static string getName(IntegerCODEC & v) {
        for(auto i = scodecmap.begin(); i != scodecmap.end() ; ++i) {
            if(i->second.get() == &v )
                return i->first;
        }
        return "UNKNOWN";
    }

    static bool valid(string name) {
        return  (scodecmap.find(name) != scodecmap.end()) ;
    }

    static shared_ptr<IntegerCODEC> & getFromName(string name) {
        if (scodecmap.find(name) == scodecmap.end()) {
            cerr << "name " << name << " does not refer to a CODEC." << endl;
            cerr << "possible choices:" << endl;
            for (auto i = scodecmap.begin(); i != scodecmap.end(); ++i) {
                cerr << static_cast<string> (i->first) << endl;// useless cast, but just to be clear
            }
            return defaultptr;
        }
        return scodecmap[name];
    }

};

map<string, shared_ptr<IntegerCODEC> > CODECFactory::scodecmap =
        initializefactory();

shared_ptr<IntegerCODEC> CODECFactory::defaultptr = shared_ptr<IntegerCODEC>(nullptr);
#endif /* CODECFACTORY_H_ */
