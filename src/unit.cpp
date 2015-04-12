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

void testgroupvarintfind() {
  const int max = 300;
  VarIntGB<true> codec;
  uint32_t ints[max];
  for (int i = 0; i < max; i++)
    ints[i] = i;

  // encode in a buffer
  vector<uint32_t> compressedbuffer(max * sizeof(uint32_t) + 1024);
  size_t nvalue  = compressedbuffer.size();
  codec.encodeArray(ints, max, compressedbuffer.data(), nvalue);

  uint32_t k;
  for (int i = 0; i < max; i++) {
    int pos = codec.findLowerBoundDelta(compressedbuffer.data(), max, i, &k);
    if (k != (uint32_t)i && pos != i) {
      cout << "GroupVarInt::findLowerBoundDelta failed with " << i << endl;
      throw std::logic_error("bug");
    }
  }

  cout << "GroupVarInt::findLowerBoundDelta ok" << endl;
}

void testgroupvarintselect() {
  const int max = 300;
  VarIntGB<true> codec;
  uint32_t ints[max];
  for (int i = 0; i < max; i++)
    ints[i] = i;

  // encode in a buffer
  vector<uint32_t> compressedbuffer(max * sizeof(uint32_t) + 1024);
  size_t nvalue  = compressedbuffer.size();
  codec.encodeArray(ints, max, compressedbuffer.data(), nvalue);

  for (int i = 0; i < max; i++) {
    uint32_t k = codec.selectDelta(compressedbuffer.data(), max, i);
    if (k != (uint32_t)i) {
      cout << "GroupVarInt::select failed with " << i << endl;
      throw std::logic_error("bug");
    }
  }

  cout << "GroupVarInt::select ok" << endl;
}

int main() {
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

    testgroupvarintselect();
    testgroupvarintfind();

    tellmeaboutmachine();

    cout << "Code is probably ok." << endl;
}
