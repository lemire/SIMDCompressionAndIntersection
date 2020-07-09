/*
 * The idea here is to successively grab arrays from a data file.
 * The arrays are compressed (optionally using blocks of various size)
 * to RAM and the repeatedly uncompressed.
 */

#include <unistd.h>

#include "common.h"
#include "util.h"
#include "timer.h"
#include "maropuparser.h"
#include "codecfactory.h"

// https://code.google.com/p/likwid/wiki/LikwidPerfCtr#Using_the_marker_API
#ifdef LIKWID_MARKERS // see 'make likwidramtocache' for compiler flags
#include <likwid.h>
#endif

using namespace SIMDCompressionLib;

void printusage(char *prog) {
#ifdef LIKWID_MARKERS
  cout << "example: likwid -m -C 1 -g BRANCH " << prog
       << " input.bin scheme1 scheme2 ..." << endl;
  cout
      << " You can use the -l <num> flag to process only the first <num> arrays"
      << endl;
#else
  cout << " Try " << prog << "  input.bin scheme1 scheme2 ..." << endl;
  cout
      << " You can use the -l <num> flag to process only the first <num> arrays"
      << endl;
#endif
}

struct stats {
  stats()
      : VolumeDecoded(0), BytesDecoded(0), TimeDecoding(0), NumberOfArrays(0) {}
  uint64_t VolumeDecoded;  // how many ints we decoded
  uint64_t BytesDecoded;   // how many bytes these ints used
  uint64_t TimeDecoding;   // how much time it took
  uint64_t NumberOfArrays; // how many arrays were compressed
};

void simplecompress(shared_ptr<IntegerCODEC> c, vector<uint32_t> &buffer,
                    vector<uint32_t> &obuffer) {
  obuffer.resize(buffer.size() * 2); // allocate lots of memory
  size_t lo = obuffer.size();
  c->encodeArray(buffer.data(), buffer.size(), obuffer.data(), lo);
  obuffer.resize(lo);
}

void blockedcompress(shared_ptr<IntegerCODEC> c, vector<uint32_t> &buffer,
                     vector<uint32_t> &obuffer, uint32_t blocksize) {
  if (blocksize == 0) {
    throw runtime_error("null blocksize...bug?");
  }
  obuffer.resize(buffer.size() * 2); // allocate lots of memory
  size_t inpos = 0;
  size_t outcounter = 0;
  size_t outpos = (buffer.size() + blocksize - 1) / blocksize;

  while (inpos < buffer.size()) {
    size_t l = buffer.size() - inpos;
    if (l > blocksize)
      l = blocksize;
    size_t lo = obuffer.size() - outpos;
    c->encodeArray(buffer.data() + inpos, l, obuffer.data() + outpos, lo);
    obuffer[outcounter++] = (uint32_t)lo; // saving compressed length
    outpos += lo;
    inpos += l;
  }
  obuffer.resize(outpos);
  obuffer.shrink_to_fit();
}

// alternative to processArray for sanity checking
void simpleProcessArray(map<shared_ptr<IntegerCODEC>, stats> &mystats,
                        vector<vector<uint32_t>> &mbuffer,
                        vector<vector<uint32_t>> &mobuffer, uint32_t &bogus) {
  vector<uint32_t> l1buf;
  WallClockTimer z;
  mobuffer.resize(mbuffer.size());
  for (auto p = mystats.begin(); p != mystats.end(); ++p) {
    shared_ptr<IntegerCODEC> codec = p->first;
    stats &s = p->second;
    for (size_t K = 0; K < mbuffer.size(); ++K) {
      vector<uint32_t> &buffer = mbuffer[K];
      if (l1buf.size() < buffer.size())
        l1buf.resize(buffer.size());
      vector<uint32_t> &obuffer = mobuffer[K];
      vector<uint32_t> bufcopy(
          buffer); // we make a copy so that no funny business can happen
      simplecompress(codec, bufcopy, obuffer);
      s.VolumeDecoded += buffer.size();
      s.BytesDecoded += obuffer.size() * sizeof(uint32_t);
    }
    // now we benchmark
    // we first materialize everything in a cache-friendly manner
    size_t howmany = mbuffer.size();
    vector<uint32_t *> datap(howmany);
    vector<size_t> datal(howmany);
    for (size_t K = 0; K < howmany; ++K) {
      datap[K] = mobuffer[K].data();
      datal[K] = mobuffer[K].size();
    }

    z.reset();
    for (size_t K = 0; K < howmany; ++K) {
      s.NumberOfArrays++;
      size_t l = l1buf.size();
      codec->decodeArray(datap[K], datal[K], l1buf.data(), l);
      bogus += l1buf[0];
    }
    uint64_t timespent = z.split();
    s.TimeDecoding += timespent;
  }
}

void processArray(map<pair<uint32_t, shared_ptr<IntegerCODEC>>, stats> &mystats,
                  vector<vector<uint32_t>> &mbuffer,
                  vector<vector<uint32_t>> &mobuffer, uint32_t &bogus) {
  vector<uint32_t> l1buf;
  WallClockTimer z;
  size_t inpos, outpos, outcounter;
  mobuffer.resize(mbuffer.size());
  for (auto p = mystats.begin(); p != mystats.end(); ++p) {
    shared_ptr<IntegerCODEC> codec = p->first.second;
    stats &s = p->second;
    uint32_t blocksize = p->first.first;
    l1buf.resize(blocksize);
    for (size_t K = 0; K < mbuffer.size(); ++K) {
      vector<uint32_t> &buffer = mbuffer[K];
      vector<uint32_t> &obuffer = mobuffer[K];
      vector<uint32_t> bufcopy(
          buffer); // we make a copy so that no funny business can happen
      blockedcompress(codec, bufcopy, obuffer, blocksize);
      s.VolumeDecoded += buffer.size();
      s.BytesDecoded += obuffer.size() * sizeof(uint32_t);
      // we first do it without recording results to make sure no funny
      // buffering issues
      // are at play and to check the answer
      inpos = 0;
      for (outpos = (buffer.size() + blocksize - 1) / blocksize, outcounter = 0;
           outpos < obuffer.size(); outpos += obuffer[outcounter++]) {
        size_t l = blocksize;
        codec->decodeArray(obuffer.data() + outpos, obuffer[outcounter],
                           l1buf.data(), l);
        // we check that we decoded the right values
        size_t expectedl = buffer.size() - inpos;
        if (expectedl > blocksize)
          expectedl = blocksize;
        if (l != expectedl)
          throw runtime_error("failed to recover right length");
        for (size_t k = 0; k < l; ++k)
          if (l1buf[k] != buffer[k + inpos]) {
            for (size_t KK = 0; KK < l; ++KK)
              cout << KK << ": expected is " << buffer[KK + inpos]
                   << ", actual is " << l1buf[KK] << endl;
            throw runtime_error("bug decoded values do not match");
          }
        inpos += l;
      }
    }
    // now we benchmark for real knowing that the result will be sound
    size_t howmany = mbuffer.size();
    vector<uint32_t *> datap(howmany);
    vector<uint32_t *> counts(howmany);
    vector<size_t> datal(howmany);
    for (size_t K = 0; K < howmany; ++K) {
      counts[K] = mobuffer[K].data();
      datap[K] =
          mobuffer[K].data() + (mbuffer[K].size() + blocksize - 1) / blocksize;
      datal[K] =
          mobuffer[K].size() - (mbuffer[K].size() + blocksize - 1) / blocksize;
    }
    z.reset();
    for (size_t K = 0; K < howmany; ++K) {
      uint32_t *obuffer = datap[K];
      uint32_t *counters = counts[K];
      size_t thiscompressedlength = datal[K];
      s.NumberOfArrays++;
      for (outcounter = 0; outcounter < thiscompressedlength;) {
        size_t l = blocksize;
        codec->decodeArray(obuffer + outcounter, *counters, l1buf.data(), l);
        bogus += l1buf[0];
        outcounter += *counters;
        counters++;
      }
      if (thiscompressedlength != outcounter)
        cerr << "bug?" << endl;
    }
    uint64_t timespent = z.split();
    s.TimeDecoding += timespent;
  }
}

void distributionOfDeltas(const uint32_t *in, const size_t length,
                          std::map<uint32_t, double> &counter) {
  uint32_t prev = 0;
  for (size_t k = 0; k < length; ++k, ++in) {
    uint32_t delta = in[0] - prev;
    prev = in[0];
    std::map<uint32_t, double>::iterator i = counter.find(delta);
    if (i != counter.end())
      i->second += 1;
    else
      counter[delta] = 1;
  }
}
double entropy(std::map<uint32_t, double> &counter) {
  double length = 0;
  for (std::map<uint32_t, double>::iterator i = counter.begin();
       i != counter.end(); ++i) {
    length += i->second;
  }
  if (length < 1)
    return 0;
  double total = 0;
  for (std::map<uint32_t, double>::iterator i = counter.begin();
       i != counter.end(); ++i) {
    double x = i->second;
    if (x < 1)
      continue;
    total += x / length * log(length / x) / log(2.0);
  }
  return total;
}
int main(int argc, char **argv) {
  vector<uint32_t> blocksizes = {32,   64,   128,   256,   512,   1024,   2048,
                                 4096, 8192, 16384, 32768, 65536, 1048576};
  vector<shared_ptr<IntegerCODEC>> schemes;
  int c;
  size_t MAX_ARRAYS = std::numeric_limits<size_t>::max();
  size_t VOLUME = 1024; // 1024 MB or 1 GB
  while ((c = getopt(argc, argv, "r:l:")) != -1) {
    switch (c) {
    case 'l':
      MAX_ARRAYS = atoi(optarg);
      if (MAX_ARRAYS < 1) {
        cerr << " MAX_ARRAYS param needs to be within [1,infty)." << endl;
        printusage(argv[0]);
        return -1;
      }
      break;
    case 'v':
      VOLUME = atoi(optarg);
      if (VOLUME < 1) {
        cerr << " VOLUME param needs to be within [1,infty). (In MB.)" << endl;
        printusage(argv[0]);
        return -1;
      }
      break;
    case 'h':
      printusage(argv[0]);
      return 0;
    default:
      printusage(argv[0]);
      return -1;
    }
  }
  if (optind + 2 > argc) {
    printusage(argv[0]);
    return -1;
  }
#ifdef LIKWID_MARKERS
  char currentMarker[64];
  likwid_markerInit();
#endif
  uint32_t bogus = 0;
  map<pair<uint32_t, shared_ptr<IntegerCODEC>>, stats> mystats;
  map<shared_ptr<IntegerCODEC>, stats> mysimplestats;

  try {
    string ifilename = argv[optind];
    for (int k = optind + 1; k < argc; ++k) {
      shared_ptr<IntegerCODEC> s = CODECFactory::getFromName(argv[k]);
      if (s.get() == NULL)
        return -1;
      schemes.push_back(s);
      for (size_t z = 0; z < blocksizes.size(); ++z) {
        stats S;
        mystats[make_pair(blocksizes[z], s)] = S;
      }
      stats Ss;
      mysimplestats[s] = Ss;
    }

    MaropuGapReader reader(ifilename);
    if (!reader.open()) {
      cout << " could not open " << ifilename << " for reading..." << endl;
      return -1;
    }
    cout << "# Compressing content from " << ifilename << " ";
    cout.flush();
    vector<vector<uint32_t>> buffer;
    vector<vector<uint32_t>> obuffer;
    size_t numberofarrays = 0;
    std::map<uint32_t, double> counter;
    vector<uint32_t> b;
    size_t howmanyints = 0;
    size_t longestarray = 0;
    size_t shortestarray = ~((size_t)0);
    size_t buffermaxsize = 0;
    size_t bufferminsize = ~((size_t)0);
    size_t buffercurrentsize = 0;
    while (reader.loadIntegers(b)) {
      howmanyints += b.size();
      if (longestarray < b.size())
        longestarray = b.size();
      if (shortestarray > b.size())
        shortestarray = b.size();
      buffercurrentsize += b.size();
      distributionOfDeltas(b.data(), b.size(), counter);
      buffer.push_back(b);
      if (buffercurrentsize > VOLUME * 1024 * 1024 / 4) { // VOLUME is in MB
        if (buffermaxsize < buffercurrentsize)
          buffermaxsize = buffercurrentsize;
        if (bufferminsize > buffercurrentsize)
          bufferminsize = buffercurrentsize;
        buffercurrentsize = 0;
#ifdef LIKWID_MARKERS
        snprintf(currentMarker, sizeof(currentMarker), "all");
        likwid_markerStartRegion(currentMarker);
#endif
        processArray(mystats, buffer, obuffer, bogus);
        simpleProcessArray(mysimplestats, buffer, obuffer, bogus);
#ifdef LIKWID_MARKERS
        likwid_markerStopRegion(currentMarker);
#endif
        buffer.clear();
      }
      if (numberofarrays % 1000 == 0) {
        cout << ".";
        cout.flush();
      }
      ++numberofarrays;
      if (numberofarrays == MAX_ARRAYS)
        break;
    }
    if (buffer.size() > 0) {
      if (buffermaxsize < buffercurrentsize)
        buffermaxsize = buffercurrentsize;
      if (bufferminsize > buffercurrentsize)
        bufferminsize = buffercurrentsize;
      buffercurrentsize = 0;
#ifdef LIKWID_MARKERS
      snprintf(currentMarker, sizeof(currentMarker), "all");
      likwid_markerStartRegion(currentMarker);
#endif
      processArray(mystats, buffer, obuffer, bogus);
      simpleProcessArray(mysimplestats, buffer, obuffer, bogus);
#ifdef LIKWID_MARKERS
      likwid_markerStopRegion(currentMarker);
#endif
      buffer.clear();
    }
    cout << endl;
    cout << "# Entropy of deltas " << entropy(counter) << endl;
    cout << "# Processed " << numberofarrays << " arrays " << endl;
    cout << "# Processed " << howmanyints << " integers " << endl;
    cout << "# Average array length is " << howmanyints / numberofarrays
         << " integers " << endl;
    cout << "# Smallest array has " << shortestarray << " integers " << endl;
    cout << "# Longest array has " << longestarray << " integers " << endl;
    cout << "# Smallest buffer size " << bufferminsize * 4.0 / (1024.0 * 1024)
         << " MB " << endl;
    cout << "# Largest buffer size " << buffermaxsize * 4.0 / (1024.0 * 1024)
         << " MB " << endl;
    cout << "# in-memory volume tops at " << VOLUME
         << " MB (can be smaller if not enough data)" << endl;
    cout << "# ignore: " << bogus << endl;
    cout << "# blocksize -- scheme -- decoding speed (mis) -- bits per int"
         << endl;
    for (auto p = mystats.begin(); p != mystats.end(); ++p) {
      uint32_t blocksize = p->first.first;
      shared_ptr<IntegerCODEC> codec = p->first.second;
      stats &s = p->second;
      if (s.NumberOfArrays != numberofarrays)
        throw runtime_error("bug");
      string codecname = CODECFactory::getName(*codec);
      cout << left << setw(10) << blocksize << setw(30) << left << codecname
           << setw(20) << left << round(static_cast<double>(s.VolumeDecoded) /
                                        static_cast<double>(s.TimeDecoding))
           << setw(20) << left
           << static_cast<double>(s.BytesDecoded) * 8.0 /
                  static_cast<double>(s.VolumeDecoded)
           << endl;
    }
    for (auto p = mysimplestats.begin(); p != mysimplestats.end(); ++p) {
      shared_ptr<IntegerCODEC> codec = p->first;
      stats &s = p->second;
      string codecname = CODECFactory::getName(*codec);
      cout << left << setw(10) << "-1" << setw(30) << left << codecname
           << setw(20) << left << round(static_cast<double>(s.VolumeDecoded) /
                                        static_cast<double>(s.TimeDecoding))
           << setw(20) << left
           << static_cast<double>(s.BytesDecoded) * 8.0 /
                  static_cast<double>(s.VolumeDecoded)
           << endl;
    }
  } catch (const exception &e) {
    cerr << "Run-time error: " << e.what() << endl;
    return -1;
  } catch (...) {
    cerr << "Unknown exception caught, terminating..." << endl;
    return -1;
  }
#ifdef LIKWID_MARKERS
  likwid_markerClose();
#endif

  return 0;
}
