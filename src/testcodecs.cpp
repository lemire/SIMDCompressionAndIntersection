#include <unordered_map>
#include "synthetic.h"
#include "binarypacking.h"
#include "simdbinarypacking.h"
#include "simdfastpfor.h"
#include "timer.h"
#include "delta.h"
#include "variablebyte.h"
#include "compositecodec.h"
#include "codecfactory.h"

using namespace SIMDCompressionLib;

struct dataarray {
  dataarray() : name(), data() {}
  string name;
  vector<vector<uint32_t>> data;
};

class EntropyRecorder {
public:
  EntropyRecorder() : counter(), totallength(0) {}

  void clear() {
    counter.clear();
    totallength = 0;
  }
  void eat(const uint32_t *in, const size_t length) {
    if (length == 0)
      return;
    totallength += length;
    for (uint32_t k = 0; k < length; ++k, ++in) {
      maptype::iterator i = counter.find(*in);
      if (i != counter.end())
        i->second += 1;
      else
        counter[*in] = 1;
    }
  }

  double computeShannon() {
    double total = 0;
    for (maptype::iterator i = counter.begin(); i != counter.end(); ++i) {
      const double x = static_cast<double>(i->second);
      total += x / static_cast<double>(totallength) *
               log(static_cast<double>(totallength) / x) / log(2.0);
    }
    return total;
  }

  __attribute__((pure)) double computeDataBits() {
    double total = 0;
    for (maptype::const_iterator i = counter.begin(); i != counter.end(); ++i) {
      total += static_cast<double>(i->second) /
               static_cast<double>(totallength) *
               static_cast<double>(gccbits(i->first));
    }
    return total;
  }
  typedef unordered_map<uint32_t, size_t> maptype;
  maptype counter;
  size_t totallength;
};

void sillybenchmark(vector<dataarray> datas, vector<uint32_t> &compressedbuffer,
                    vector<uint32_t> &recoverybuffer, IntegerCODEC &codec) {
  cout << "#benchmarking " << CODECFactory::getName(codec)
       << endl; // codec.name()
  WallClockTimer z;
  double packtime, unpacktime;
  cout << "#name , bits/int , coding speed (mis) , decoding speed (mis)"
       << endl;
  for (vector<dataarray>::const_iterator it = datas.begin(); it != datas.end();
       ++it) {
    const vector<vector<uint32_t>> &data = it->data;
    vector<uint32_t> membuffer;
    packtime = 0;
    unpacktime = 0;
    double compsize = 0;
    double intcounter = 0;
    // dry run
    for (const vector<uint32_t> &D : data) {
      vector<uint32_t> dirtycopy(D);
      size_t nvalue = compressedbuffer.size();
#ifdef USE_ALIGNED
      codec.encodeArray(dirtycopy.data(), dirtycopy.size(),
                        compressedbuffer.data(), nvalue);
#else
      codec.encodeArray(dirtycopy.data() + 1,
                        dirtycopy.size() - 1, // use unaligned address
                        compressedbuffer.data(), nvalue);
#endif
      size_t recoveredvalues = recoverybuffer.size();
      codec.decodeArray(compressedbuffer.data(), nvalue, recoverybuffer.data(),
                        recoveredvalues);
#ifdef USE_ALIGNED
      if (recoveredvalues != dirtycopy.size())
        throw runtime_error("bug");
#else
      if (recoveredvalues != dirtycopy.size() - 1)
        throw runtime_error("bug");
#endif
    }
    // actual run
    for (const vector<uint32_t> &D : data) {
      vector<uint32_t> dirtycopy(D);
      intcounter += static_cast<double>(dirtycopy.size());
      size_t nvalue = compressedbuffer.size();
      z.reset();
#ifdef USE_ALIGNED
      codec.encodeArray(dirtycopy.data(), dirtycopy.size(),
                        compressedbuffer.data(), nvalue);
#else
      codec.encodeArray(dirtycopy.data() + 1,
                        dirtycopy.size() - 1, // use unaligned address
                        compressedbuffer.data(), nvalue);
#endif
      packtime += static_cast<double>(z.split());
      compsize += static_cast<double>(nvalue);
      size_t recoveredvalues = recoverybuffer.size();
      double bestunpacktime = std::numeric_limits<double>::infinity();
      for (int t = 0; t < 5; ++t) {
        z.reset();
        codec.decodeArray(compressedbuffer.data(), nvalue,
                          recoverybuffer.data(), recoveredvalues);
        double tup = static_cast<double>(z.split());
        if (tup < bestunpacktime)
          bestunpacktime = tup;
      }
      unpacktime += bestunpacktime;

#ifdef USE_ALIGNED
      if (recoveredvalues != dirtycopy.size())
        throw runtime_error("bug");
#else
      if (recoveredvalues != dirtycopy.size() - 1)
        throw runtime_error("bug");
#endif
    }
    cout << std::setprecision(4) << it->name << "\t"
         << (static_cast<double>(compsize) * 32.0 / intcounter) << "\t"
         << intcounter / static_cast<double>(packtime) << "\t"
         << intcounter / static_cast<double>(unpacktime) << endl;
  }
  cout << endl;
}

void benchmark(const uint32_t S, vector<shared_ptr<IntegerCODEC>> &allcodecs) {
  const uint32_t N = 1U << S;
  cout << "####################################################################"
          "######"
       << endl;
  cout << "# Warning: this microbench is sensitive to background processes."
       << endl;
  cout << "#          You may need to repeat the test over several minutes or "
          "hours"
       << endl;
  cout << "#          if you cannot get exclusive access to the CPU and its "
          "cache."
       << endl;
  cout << "####################################################################"
          "######"
       << endl;
  cout << "# using arrays of size " << N << endl;
  ClusteredDataGenerator cdg(0); // used fixed seed to lower variance
  vector<dataarray> datas;
  cout << "# generating data...";
  cout << endl;
  int Times = static_cast<int>(
      round(40.0 * static_cast<double>(1U << 16) / static_cast<double>(N)));
  if (Times == 0)
    Times = 1;
  cout << "# Generating " << Times << " array for each gap, volume is "
       << Times * N << " ints" << endl;
  for (uint32_t gap = 1; gap + S <= 31; gap += 1) {
    dataarray X;
    EntropyRecorder er;
    for (int k = 0; k < Times; ++k) {
      X.data.push_back(cdg.generateClustered(N, 1U << (gap + S)));
      vector<uint32_t> copy(X.data.back());
      delta(0U, copy.data(), copy.size());
      er.eat(copy.data(), copy.size());
    }
    cout << "# entropy of " << gap << " is " << er.computeShannon() << endl;
    ostringstream convert;
    convert << gap;
    X.name = convert.str();
    datas.push_back(X);
  }
  vector<uint32_t> compressedbuffer;
  compressedbuffer.resize(N * 2);
  vector<uint32_t> recoverybuffer;
  recoverybuffer.resize(N);
  for (auto i : allcodecs)
    sillybenchmark(datas, compressedbuffer, recoverybuffer, *i);
}

void displayUsage() {
  cout << "run as testcodecs nameofcodec1 nameofcodec2 ..." << endl;
  cout << "where codecs are:" << endl;
  vector<string> all = CODECFactory::allNames();
  for (auto i = all.begin(); i != all.end(); ++i) {
    cout << *i << endl;
  }
}
int main(int argc, char **argv) {
  if (argc <= 1) {
    displayUsage();
    return -1;
  }
  vector<shared_ptr<IntegerCODEC>> allcodecs;
  for (int k = 1; k < argc; ++k) {
    shared_ptr<IntegerCODEC> p = CODECFactory::getFromName(argv[k]);
    if (p.get() == NULL)
      return -2;
    allcodecs.push_back(p);
  }
  benchmark(16, allcodecs);
  return 0;
}
