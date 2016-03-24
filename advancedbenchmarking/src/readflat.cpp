#include <unistd.h>
#include <fstream>
#include <vector>

#include "common.h"
#include "util.h"
#include "timer.h"
#include "maropuparser.h"
#include "codecfactory.h"

using namespace SIMDCompressionLib;

void printusage(char *prog) {
  cout << "Usage: " << prog << " <uncompressed postings in the flat format>"
       << endl;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printusage(argv[1]);
    return -1;
  }

  try {
    string postFileName = argv[1];

    MaropuGapReader reader(postFileName);
    if (!reader.open()) {
      cout << " could not open " << postFileName << " for reading..." << endl;
      return -1;
    }

    off_t pos;
    uint32_t qty;
    uint32_t postId = 0;

    while (reader.readNextPosAndQty(pos, qty)) {
      cout << "id: " << postId << " qty: " << qty << "offset: " << pos << endl;
      postId++;
      if ((reader.getPos() - pos) != (qty + 1) * 4) {
        cerr << "Internal error: unpexected diff in offsets!" << endl;
        return -1;
      }
    }

  } catch (const exception &e) {
    cerr << "Run-time error: " << e.what() << endl;
    return -1;
  } catch (...) {
    cerr << "Unknown exception caught, terminating..." << endl;
    return -1;
  }

  return 0;
}
