/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 */


#include "common.h"
#include "bitpackinghelpers.h"
#include "simdbitpackinghelpers.h"
#include "delta.h"
#include "util.h"
#include "synthetic.h"
#include "binarypacking.h"
#include "simdbinarypacking.h"
#include "simdfastpfor.h"
#include "variablebyte.h"
#include "compositecodec.h"
#include "codecfactory.h"

using namespace std;
using namespace SIMDCompressionLib;

struct dataarray {
    dataarray() : name(), data() {}
    string name;
    vector<uint32_t> data;
};


void testSmall(vector<shared_ptr<IntegerCODEC>> codecs) {
    vector<uint32_t> data;
    data.push_back(1U);
    data.push_back(3U);
    data.push_back(5U);
    data.push_back(15U + 1024U);
    data.push_back(21U + 1024U);

    for (shared_ptr<IntegerCODEC> codec : codecs) {
        vector<uint32_t> dirtycopy(data);
        vector<uint32_t> compressedbuffer(data.size() + 1024);
        vector<uint32_t> recoverybuffer(data.size() + 1024);
        size_t nvalue = compressedbuffer.size();
        codec->encodeArray(dirtycopy.data(), dirtycopy.size(), compressedbuffer.data(), nvalue);
        size_t recoveredvalues = recoverybuffer.size();
        codec->decodeArray(compressedbuffer.data(), nvalue, recoverybuffer.data(), recoveredvalues);
        recoverybuffer.resize(recoveredvalues);
        if (data != recoverybuffer) {
            cout << "Problem with  " << codec->name() << endl;
            for (size_t i = 0; i < data.size(); ++i)
                cout << i << " " << data[i] << " " << recoverybuffer[i] << endl;
            throw std::logic_error("bug");
        }
    }
}


void sillyunittest(vector<dataarray> datas, vector<uint32_t> &compressedbuffer,
                   vector<uint32_t> &recoverybuffer, IntegerCODEC &codec) {
    for (vector<dataarray>::const_iterator i = datas.begin() ;
            i != datas.end() ; ++i) {
        const vector<uint32_t> &data = i->data;
        vector<uint32_t> dirtycopy(data);
        size_t nvalue  = compressedbuffer.size();
        codec.encodeArray(dirtycopy.data(), dirtycopy.size(), compressedbuffer.data(), nvalue);
        size_t recoveredvalues = recoverybuffer.size();
        codec.decodeArray(compressedbuffer.data(), nvalue, recoverybuffer.data(), recoveredvalues);
        recoverybuffer.resize(recoveredvalues);
        if (data != recoverybuffer) {
            cout << "Problem with  " << codec.name() << endl;
            size_t howmany = 0;
            for (size_t i = 0; i < data.size(); ++i) {
                if (data[i] != recoverybuffer[i]) {
                    if (++howmany > 5) {
                        cout << "..." << endl;
                        break;
                    }
                    cout << i << " " << data[i] << " " << recoverybuffer[i] << endl;
                }
            }
            throw std::logic_error("bug");
        }
    }
    cout.flush();
}

void unittrivial(bool deltacode, vector<shared_ptr<IntegerCODEC>> &allcodecs, const uint32_t S) {
    const uint32_t N = 1U << S;
    vector<dataarray> datas;
    dataarray X;
    vector <uint32_t> d(N);
    for (uint32_t k = 0; k < N; ++k)
        d[k] = k;
    X.data = d;
    if (deltacode)
        delta(0u, X.data.data(), X.data.size());

    ostringstream convert;
    convert << N;
    X.name = convert.str();
    datas.push_back(X);
    vector<uint32_t> compressedbuffer;
    compressedbuffer.resize(N * 2);
    vector<uint32_t> recoverybuffer;
    recoverybuffer.resize(N);
    for (auto i : allcodecs)
        sillyunittest(datas, compressedbuffer, recoverybuffer, *i);
}


void unit(bool deltacode, vector<shared_ptr<IntegerCODEC>> &allcodecs, const uint32_t S , int seed) {
    const uint32_t N = 1U << S;
    ClusteredDataGenerator cdg(seed);

    vector<dataarray> datas;
    uint32_t NUMBER = 1;// Increase as needed
    for (uint32_t gap = 1; gap + S <= 31; gap += 1) {
        for (uint32_t T = 0; T < NUMBER; ++T) {
            dataarray X;
            X.data = cdg.generateClustered(N, 1U << (gap + S));

            if (deltacode) delta(0u, X.data.data(), X.data.size());

            ostringstream convert;
            convert << gap;
            X.name =  convert.str();
            datas.push_back(X);
        }

    }
    vector<uint32_t> compressedbuffer;
    compressedbuffer.resize(N * 2);
    vector<uint32_t> recoverybuffer;
    recoverybuffer.resize(N);
    for (auto i : allcodecs)
        sillyunittest(datas, compressedbuffer, recoverybuffer, *i);
}



int test1(intersectionfunction f, bool testwriteback) {

    const uint32_t firstpost[13] = {27181,35350,39241,39277,39278,44682,64706,120447,120450,159274,159290,173895,173942,
                                   };
    const uint32_t secondpost[13] = {25369,28789,28790,28792,28794,28797,37750,42317,68797,68877,68881,68990,85488};
    vector < uint32_t > inter(13);
    size_t s = f(firstpost, 13, secondpost, 13, inter.data());
    inter.resize(s);
    vector < uint32_t > correct(13);
    size_t cs = classicalintersection(firstpost, 13, secondpost, 13,
                                      correct.data());
    correct.resize(cs);
    if (inter != correct) {
        cout << inter.size() << " " << correct.size() << endl;
        for (size_t i = 0; (i < inter.size()) && (i < correct.size()); ++i)
            cout << i << " " << inter[i] << " " << correct[i] << endl;
        return 1;
    }
    if (!testwriteback)
        return 0;
    vector < uint32_t > inter2(firstpost, firstpost + 13);
    size_t s2 = f(inter2.data(), 13, secondpost, 13, inter2.data());
    inter2.resize(s2);
    if (inter2 != correct)
        return 2;
    return 0;

}

int test2(intersectionfunction f) {
    const uint32_t firstpost[5] = { 12635, 12921, 12923, 12924,
                                    12926
                                  };

    const uint32_t secondpost[173] = { 3756, 11996, 12044, 12049, 12109, 12128,
                                       12131, 12141, 12142, 12150, 12154, 12160, 12167, 12168, 12172,
                                       12177, 12201, 12208, 12215, 12216, 12223, 12228, 12232, 12233,
                                       12234, 12235, 12236, 12240, 12241, 12242, 12243, 12254, 12255,
                                       12256, 12257, 12259, 12260, 12261, 12262, 12264, 12265, 12266,
                                       12275, 12295, 12471, 12482, 12486, 12508, 12509, 12510, 12511,
                                       12512, 12530, 12536, 12572, 12573, 12589, 12607, 12609, 12611,
                                       12630, 12631, 12632, 12633, 12634, 12635, 12636, 12653, 12655,
                                       12657, 12668, 12672, 12685, 12702, 12716, 12721, 12741, 12745,
                                       12750, 12755, 12757, 12761, 12765, 12767, 12768, 12794, 12802,
                                       12803, 12823, 12842, 12851, 12871, 12891, 12893, 12894, 12895,
                                       12896, 12897, 12915, 12917, 12918, 12919, 12920, 12921, 12922,
                                       12923, 12924, 12925, 12927, 12929, 12932, 12933, 12934, 12935,
                                       12936, 12937, 12938, 12939, 12942, 12946, 12951, 12955, 12963,
                                       12972, 13011, 13013, 13014, 13015, 13017, 13032, 13033, 13036,
                                       13042, 13050, 13051, 13052, 13057, 13058, 13060, 13090, 13120,
                                       13132, 13136, 13147, 13185, 13191, 13192, 13193, 13194, 13195,
                                       13198, 13202, 13205, 13219, 13228, 13230, 13232, 13233, 13238,
                                       13240, 13246, 13248, 13277, 13278, 13281, 13282, 13283, 13284,
                                       13291, 13320, 13338, 13346, 13347
                                     };
    vector < uint32_t > inter(173);
    size_t s = f(firstpost, 5, secondpost, 173, inter.data());
    inter.resize(s);
    vector < uint32_t > correct(173);
    size_t cs = classicalintersection(firstpost, 5, secondpost, 173,
                                      correct.data());
    correct.resize(cs);
    if (inter != correct) {
        cout << inter.size() << " " << correct.size() << endl;
        cout<<" correct answer:"<<endl;
        for (size_t i = 0; i < correct.size(); ++i)
            cout << i << " " << correct[i] << endl;
        cout<<" bad answer:"<<endl;
        for (size_t i = 0; i < inter.size(); ++i)
            cout << i << " " << inter[i] << endl;
        return 1;
    }
    return 0;

}


int test3(intersectionfunction f) {

    vector<uint32_t> firstpost;
    vector<uint32_t> secondpost;
    vector<uint32_t> trueinter;

    for(uint32_t i = 10; i < 31; ++i) {
        firstpost.push_back((1U<<i) | 3U);
        trueinter.push_back((1U<<i) | 3U);
        for(uint32_t j = 3; j< 1000; j+=11) {
            secondpost.push_back((1U<<i) | j);
        }
        firstpost.push_back((1U<<i) | 1001U);
    }
    vector < uint32_t > inter(firstpost.size());
    size_t s = f(firstpost.data(), firstpost.size(), secondpost.data(), secondpost.size(), inter.data());
    inter.resize(s);
    if(inter != trueinter) {
        cout << inter.size() << " " << trueinter.size() << endl;
        for (size_t i = 0; (i < inter.size()) && (i < trueinter.size()); ++i)
            cout << i << " " << inter[i] << " " << trueinter[i] << endl;
        return 1;

        return 1;
    }
    return 0;
}



void tellmeaboutmachine() {
    cout << "number of bytes in ostream::pos_type = "
         << sizeof(ostream::pos_type) << endl;
    cout << "number of bytes in size_t = " << sizeof(size_t) << endl;
    cout << "number of bytes in int = " << sizeof(int) << endl;
    cout << "number of bytes in long = " << sizeof(long) << endl;
#if  __LITTLE_ENDIAN__
    cout << "you have little endian machine" << endl;
#endif
#if  __BIG_ENDIAN__
    cout << "you have a big endian machine" << endl;
#endif
#if __CHAR_BIT__
    if (__CHAR_BIT__ != 8)
        cout << "on your machine, chars don't have 8bits???" << endl;
#endif
#if __GNUG__
    cout << "GNU GCC compiler detected." << endl;
#else
    cout << "Non-GCC compiler." << endl;
#endif
}

template<typename T>
void testFindSimple() {
	T codec;
    const int max = 256;
    uint32_t ints[max];
    for (int i = 0; i < max; i++)
        ints[i] = i;

    // encode in a buffer
    vector<uint32_t> compressedbuffer(max * sizeof(uint32_t) + 1024);
    size_t nvalue  = compressedbuffer.size();
    codec.encodeArray(ints, max, compressedbuffer.data(), nvalue);

    uint32_t k = 0;
    for (int i = 0; i < max; i++) {
        int pos = codec.findLowerBound(compressedbuffer.data(), max, i, &k);
        if (k != (uint32_t)i && pos != i) {
            cout << codec.name() << "::findLowerBoundDelta failed with "
                 << i << endl;
            throw std::logic_error("bug");
        }
    }

    cout << codec.name() << "::findLowerBoundDelta ok" << endl;
}

template<typename T>
void testFindAdvanced() {
	T codec;
    const int max = 2944;
    uint32_t ints[max];
    // print random seed to make the test reproducable
    time_t t = ::time(0);
    cout << "Seed is " << t << endl;
    ::srand(t);

    // initialize
    for (int i = 0; i < max; i++)
        ints[i] = 1 + i * 2;

    // encode in a buffer
    vector<uint32_t> compressedbuffer(max * sizeof(uint32_t) + 1024);
    size_t nvalue  = compressedbuffer.size();
    codec.encodeArray(ints, max, compressedbuffer.data(), nvalue);

    uint32_t k1 = 0;
    uint32_t k2 = 0;
    for (int i = 0; i < max * 2; i++) {
        int pos1 = codec.findLowerBound(compressedbuffer.data(), max, i, &k1);
        uint32_t *it = std::lower_bound(&ints[0], &ints[max], i);
        int pos2 = it - &ints[0];
        k2 = *it;
        // key not found?
        if (it == &ints[max] && pos1 != max) {
            cout << codec.name() << "::findLowerBoundDelta failed at line "
                 << __LINE__ << " (i = " << i << ")" << endl;
            throw std::logic_error("bug");
        }
        // otherwise make sure both results are equal
        if (k1 != k2) {
            cout << codec.name() << "::findLowerBoundDelta failed at line "
                 << __LINE__ << " (i = " << i << ")" << endl;
            throw std::logic_error("bug");
        }
        if (pos1 != pos2) {
            cout << codec.name() << "::findLowerBoundDelta failed at line "
                 << __LINE__ << " (i = " << i << ")" << endl;
            throw std::logic_error("bug");
        }
    }

    cout << codec.name() << "::findLowerBoundDelta ok" << endl;
}



template<typename T>
void testInsert() {
	T codec;
	const int max = 256;
	srand(0);
	uint32_t ints[max];
	for (int i = 0; i < max; i++)
		ints[i] = rand();
	// encode in a buffer
	vector < uint32_t > compressedbuffer(max * sizeof(uint32_t) + 1024);
	vector < uint32_t > decomp(max);
	vector < uint32_t > sofar;

	size_t currentsize = 0;
	for (int i = 0; i < max; i++) {
		currentsize = codec.insert(compressedbuffer.data(), currentsize, ints[i]);
		size_t howmany = decomp.size();
		codec.decodeArray(compressedbuffer.data(),currentsize,decomp.data(),howmany);
		sofar.push_back(ints[i]);
		std::sort(sofar.begin(),sofar.end());
		if(howmany != sofar.size())
			cout << howmany << " " <<sofar.size() << " " << i <<endl;
		assert(howmany == sofar.size());
		for(size_t j = 0; j < howmany; ++j) {
			if(decomp[j] != sofar[j]) {
				cout << codec.name() << "::insert failed with i = " << i << ", j = " << j << endl;
				for(size_t j = 0; j < howmany; ++j) {
					cout << j << " -->  stored: " << decomp[j] << " correct: " << sofar[j] << endl;
				}
				for(size_t j = 0; j < currentsize * 4; ++j) {
					cout << (uint32_t)(((uint8_t *) compressedbuffer.data()) [j]) << " ";
				}
				cout << endl;

				throw std::logic_error("bug");
			}
		}
	}

	cout << codec.name() << "::insert ok" << endl;
}


template<typename T>
void testSelectSimple() {
	T codec;
    const int max = 256;
    uint32_t ints[max];
    for (int i = 0; i < max; i++)
        ints[i] = i;
     // encode in a buffer
    vector<uint32_t> compressedbuffer(max * sizeof(uint32_t) + 1024);
    size_t nvalue  = compressedbuffer.size();
    codec.encodeArray(ints, max, compressedbuffer.data(), nvalue);

    compressedbuffer.resize(nvalue);
    compressedbuffer.shrink_to_fit();
    for (int i = 0; i < max; i++) {

        uint32_t k = codec.select(compressedbuffer.data(), i);
        if (k != (uint32_t)i) {
            cout << codec.name() << "::select failed with " << i << endl;
            throw std::logic_error("bug");
        }
    }

    cout << codec.name() << "::select ok" << endl;
}


template<typename T>
void testSelectSimpleOdd() {
	T codec;
    const int max = 259;
    uint32_t ints[max];
    for (int i = 0; i < max; i++)
        ints[i] = i;

    // encode in a buffer
    vector<uint32_t> compressedbuffer(max * sizeof(uint32_t) + 1024);
    size_t nvalue  = compressedbuffer.size();
    codec.encodeArray(ints, max, compressedbuffer.data(), nvalue);
    compressedbuffer.resize(nvalue);
    compressedbuffer.shrink_to_fit();
    for (int i = 0; i < max; i++) {
        cout << i << " = " << codec.select(compressedbuffer.data(), i) << endl;

    }
    for (int i = 0; i < max; i++) {
    	cout<<"hell select "<<i<<endl;
        uint32_t k = codec.select(compressedbuffer.data(), i);
        if (k != (uint32_t)i) {
            cout << codec.name() << "::odd select failed with " << i << " got back "<< k << endl;
            throw std::logic_error("bug");
        }
    }

    cout << codec.name() << "::select ok" << endl;
}

template<typename T>
void testSelectAdvanced() {
	T codec;
    const int max = 2944;
    uint32_t ints[max];
    // print random seed to make the test reproducable
    time_t t = ::time(0);
    cout << "Seed is " << t << endl;
    ::srand(t);

    // fill array with "random" values
    for (int i = 0; i < max; i++)
        ints[i] = 1 + i * 2;
    std::random_shuffle(&ints[0], &ints[max]);

    // encode in a buffer
    vector<uint32_t> compressedbuffer(max * sizeof(uint32_t) + 1024);
    size_t nvalue  = compressedbuffer.size();
    codec.encodeArray(ints, max, compressedbuffer.data(), nvalue);

    uint32_t k1, k2;
    for (int i = 0; i < max; i++) {
        k1 = codec.select(compressedbuffer.data(),  i);
        k2 = (uint32_t)ints[i];

        if (k1 != k2) {
        	cout << "max = " << max << endl;
        	cout << "got back " << k1 << endl;

        	for (int j = 0; j <= i; j++) {//shit
            	cout<<j<<"-->"<<ints[j]<<" "<<endl;
            }

        	cout << codec.name() << "::selectDelta failed at line "
                 << __LINE__ << " (i = " << i << ")" << endl;
            throw std::logic_error("bug");
        }
    }

    cout << codec.name() << "::selectDelta ok" << endl;
}

int main() {
    testInsert<StreamVByteD1>();
	testInsert<VarIntGB<true>>();
    testInsert<VariableByte<true>>();
    testInsert<VByte<true>>();


    testSelectSimple<ForCODEC>();
    testSelectSimple<SIMDFrameOfReference>();
    testSelectSimple<FrameOfReference>();
    testSelectSimple<VarIntGB<true>>();
    testSelectSimple<MaskedVByte<true>>();
    testSelectSimple<VariableByte<true>>();
    testSelectSimple<VByte<true>>();
    testSelectSimple<SIMDBinaryPacking<SIMDIntegratedBlockPacker<
                                    RegularDeltaSIMD, true>>>();
    testSelectSimple<StreamVByteD1>();

    testSelectSimpleOdd<SIMDFrameOfReference>();
    testSelectSimpleOdd<FrameOfReference>();
    testSelectSimpleOdd<ForCODEC>();
    testSelectSimpleOdd<VarIntGB<true>>();
    testSelectSimpleOdd<MaskedVByte<true>>();
    testSelectSimpleOdd<VariableByte<true>>();
    testSelectSimpleOdd<VByte<true>>();
    testSelectSimpleOdd<StreamVByteD1>();

    testSelectAdvanced<SIMDFrameOfReference>();
    testSelectAdvanced<FrameOfReference>();
    testSelectAdvanced<ForCODEC>();
    testSelectAdvanced<VarIntGB<true>>();
    testSelectAdvanced<MaskedVByte<true>>();
    testSelectAdvanced<VariableByte<true>>();
    testSelectAdvanced<VByte<true>>();
    testSelectAdvanced<SIMDBinaryPacking<SIMDIntegratedBlockPacker<
                                    RegularDeltaSIMD, true>>>();
    testSelectAdvanced<StreamVByteD1>();

    testFindSimple<SIMDFrameOfReference>();
    testFindSimple<FrameOfReference>();
    testFindSimple<ForCODEC>();
    testFindSimple<VarIntGB<true>>();
    testFindSimple<MaskedVByte<true>>();
    testFindSimple<VariableByte<true>>();
    testFindSimple<VByte<true>>();
    testFindSimple<SIMDBinaryPacking<SIMDIntegratedBlockPacker<
                                    RegularDeltaSIMD, true>>>();
    testFindSimple<StreamVByteD1>();

    testFindAdvanced<SIMDFrameOfReference>();
    testFindAdvanced<FrameOfReference>();
    testFindAdvanced<ForCODEC>();
    testFindAdvanced<VarIntGB<true>>();
    testFindAdvanced<MaskedVByte<true>>();
    testFindAdvanced<VariableByte<true>>();
    testFindAdvanced<VByte<true>>();
    testFindAdvanced<SIMDBinaryPacking<SIMDIntegratedBlockPacker<
                                    RegularDeltaSIMD, true>>>();
    testFindAdvanced<StreamVByteD1>();

    for (string n : IntersectionFactory::allNames()) {
        int error = 0;
        intersectionfunction interfnc = IntersectionFactory::getFromName(
                                            n);
        cout<<"testing "<<n<<" ... ";
        cout.flush();
        int code;
        if((code = test1(interfnc,false))==0)
            cout<<"ok ";
        else {
            cout<<" Error"<<code<<" ";
            ++error;
        }
        if((code = test2(interfnc))==0)
            cout<<"ok ";
        else {
            cout<<" Error"<<code<<endl;
            ++error;
        }
        if((code = test3(interfnc))==0)
            cout<<"ok"<<endl;
        else {
            cout<<" Error"<<code<<endl;
            ++error;
        }
        assert(error == 0);

    }

    vector<shared_ptr<IntegerCODEC>> allcodecs = CODECFactory::allSchemes();

    testSmall(allcodecs);


    for (int k = 0; k < 10; ++k) {
        cout << k << " ";
        cout.flush();
        unittrivial(true, allcodecs, 10);
        unittrivial(false, allcodecs, 10);
        unit(true, allcodecs, 10, 1374809627);
        unit(false, allcodecs, 10, 1374809627);
    }
    cout << endl;

    for (int k = 0; k < 10; ++k) {
        cout << k << " ";
        cout.flush();
        unit(true, allcodecs, 14, 1374809627);
        unit(false, allcodecs, 14, 1374809627);
    }
    cout << endl;

    for (int k = 0; k < 100; ++k) {
        cout << k << " ";
        cout.flush();
        unit(false, allcodecs, 7, 1374809652 + k);
        unit(true, allcodecs, 7, 1374809652 + k);
    }
    cout << endl;

    tellmeaboutmachine();

    cout << "Code is probably ok." << endl;
}
