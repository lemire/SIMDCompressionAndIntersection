/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 */
#

#include <unistd.h>

#include "common.h"
#include "util.h"
#include "timer.h"
#include "synthetic.h"

using namespace SIMDCompressionLib;

void printusage() {
  cout << "This generate a file containing arrays. Each array is "
          "written as a sequence of 32-bit unsigned integers (sorted) "
          "preceded by a length indicated as a 32-bit unsigned integer. "
       << endl;
  cout << "Flags: " << endl;
  cout << "-u : uniform (as opposed to clustered) " << endl;
  cout << "-N : length of arrays " << endl;
  cout << "-m : how many arrays " << endl;
  cout << "-R : range in bits (e.g., 31 means 31-bit integers) " << endl;
  cout << " Try ./simplesynth -m 4214 -N 10000 test.bin" << endl;
}

int main(int argc, char **argv) {
  size_t howmany = 1000; // default on 1000 arrays
  uint32_t N = 1024;     // default on arrays having 1024 ints
  size_t range = 30;     // default on arrays spanning 30 bits
  bool cluster = true;   // default on clustered data
  ClusteredDataGenerator cdg;
  UniformDataGenerator udg;

  int c;
  while ((c = getopt(argc, argv, "huN:m:R:")) != -1)
    switch (c) {
    case 'u':
      cluster = false;
      break;
    case 'N':
      N = atoi(optarg);
      if (N < 1) {
        printusage();
        return -1;
      }
      break;
    case 'h':
      printusage();
      return 0;
    case 'm':
      howmany = atoi(optarg);
      if (howmany < 1) {
        printusage();
        return -1;
      }
      break;
    case 'R':
      range = atoi(optarg);
      if ((range < 1) or (range >= 32)) {
        printusage();
        return -1;
      }
      break;
    default:
      abort();
    }
  if (optind >= argc) {
    printusage();
    return -1;
  }
  uint32_t Max = 1U << range;
  if (N > Max) {
    printusage();
    return -1;
  }
  string ofilename = argv[optind];
  FILE *fd = ::fopen(ofilename.c_str(), "wb");
  if (fd == NULL) {
    cout << " could not open " << ofilename << " for writing..." << endl;
    return -1;
  }
  cout << " generating " << (cluster ? "cluster" : "uniform") << " " << howmany
       << " arrays of length = " << N << " over " << range << " bits to file "
       << ofilename << endl;
  WallClockTimer z;
  for (size_t i = 0; i < howmany; ++i) {
    vector<uint32_t> array =
        cluster ? cdg.generate(N, Max) : udg.generate(N, Max);
    assert(array.size() == N);
    if (fwrite(&N, sizeof(N), 1, fd) != 1) {
      cerr << "aborting" << endl;
      ::fclose(fd);
      return -1;
    }
    if (fwrite(array.data(), sizeof(uint32_t) * N, 1, fd) != 1) {
      cerr << "aborting" << endl;
      ::fclose(fd);
      return -1;
    }
    if (i % 1000 == 0) {
      cout << ".";
      cout.flush();
    }
  }
  cout << endl;
  long ti = z.split();
  cout << " Written " << howmany << " arrays of " << N << " integers" << endl;
  if (ti > 0) {
    double speed = static_cast<double>(howmany * N) / static_cast<double>(ti);
    cout << " Speed: " << speed << " mis " << endl;
  }
}
