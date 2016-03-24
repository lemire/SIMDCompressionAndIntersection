/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 */
#include <unistd.h>
#include <sstream>

#include "common.h"
#include "util.h"
#include "timer.h"
#include "maropuparser.h"

using namespace SIMDCompressionLib;

uint32_t FakeCheckSum(const uint32_t *p, size_t qty) {
  return std::accumulate(p, p + qty, 0);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <flat file>" << endl;
    return 1;
  }

  try {
    string postFileName = argv[1];

    cout << "# Computing statistics of posting lists from " << postFileName
         << "... please be patient." << endl;

    size_t totalQty = 0;

    MaropuGapReader grpRead(postFileName);

    if (!grpRead.open()) {
      cerr << "Can't open '" << postFileName << "' for reading" << endl;
      return 1;
    }

    size_t wordQty = 0;
    off_t pos = 0;
    uint32_t qty = 0;
    while (grpRead.readNextPosAndQty(pos, qty)) {
      ++wordQty;
      totalQty += qty;
    }
    cout << "Final stat, # of words: " << wordQty
         << " total # of postings: " << totalQty << endl;

  } catch (const exception &e) {
    cerr << "Run-time error: " << e.what() << endl;
    return -1;
  } catch (...) {
    cerr << "Unknown exception caught, terminating..." << endl;
    return -1;
  }

  return 0;
}
