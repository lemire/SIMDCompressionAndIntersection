/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 */
#

#include <unistd.h>
#include <unordered_map>

#include "common.h"
#include "maropuparser.h"
#include "util.h"
#include "delta.h"
#include "budgetedpostingcollector.h"

using namespace SIMDCompressionLib;

void message(const char *prog) {
  cerr << " usage : " << prog << "  maropubinaryfile querylogfile" << endl;
}

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

int main(int argc, char **argv) {
  size_t maxLinesToProcess = numeric_limits<size_t>::max();

  size_t memBudget = 1024ULL * 1024 * 1024 * 2; // 2GB ought to be enough
  bool bIncludeOnePostQuery = false;

  int c;
  while ((c = getopt(argc, argv, "ob:l:h")) != -1) {
    switch (c) {
    case 'o':
      bIncludeOnePostQuery = true;
      break;
    case 'b':
      memBudget = 1024ULL * 1024 * 1024 * atol(optarg);
      break;
    case 'l':
      maxLinesToProcess = atol(optarg);
      break;
    case 'h':
      message(argv[0]);
      return 0;
    default:
      message(argv[0]);
      return -1;
    }
  }

  if (optind + 1 >= argc) {
    message(argv[0]);
    return -1;
  }
  cout << "# Memory budget for uncompressed postings: " << setprecision(2)
       << static_cast<double>(memBudget) / 1024.0 / 1024.0 / 1024.0 << "GB"
       << endl;
  cout << "# Maximum number of queries: " << maxLinesToProcess << endl;
  cout << "# Do we include one-word queries: "
       << (bIncludeOnePostQuery ? "yes" : "no") << endl;
  string postFileName = argv[optind];
  string logFileName = argv[optind + 1];
  ifstream logFile(logFileName.c_str());
  if (!logFile.is_open()) {
    cerr << " Couldn't open query log file " << logFileName << endl;
    message(argv[0]);
    return -1;
  }
  cout << "# Parsing query file " << logFileName << endl;

  logFile.exceptions(ios::badbit); // will throw an exception if something goes
                                   // wrong, saves us the trouble of checking
                                   // the IO status

  EntropyRecorder er;
  cout << "# Loading posting lists from " << postFileName
       << "... please be patient." << endl;
  BudgetedPostingCollector uncompPosts(postFileName, memBudget);
  cout << "# Found " << uncompPosts.getMaxPostQty() << " posting lists."
       << endl;
  string line;
  size_t skippedQty = 0, lineQty = 0;

  vector<uint32_t> oneQueryPostIds; // buffer where a single query is stored

  for (; (static_cast<size_t>(lineQty - skippedQty) < maxLinesToProcess) &&
         logFile && getline(logFile, line);
       ++lineQty) {
    stringstream lineStr(line);

    oneQueryPostIds.clear();

    {
      uint32_t id;
      while (lineStr >> id) {
        if (uncompPosts.valid(id))
          oneQueryPostIds.emplace_back(id);
      }
    }
    if (oneQueryPostIds.empty() ||
        ((!bIncludeOnePostQuery) && (oneQueryPostIds.size() == 1))) {
      skippedQty++;
      continue;
    }
    if (!uncompPosts.loadPostings(
            oneQueryPostIds)) { // we couldn't load them all in
      uncompPosts.clear();
      assert(uncompPosts.getMemUsed() == 0);
      if (!uncompPosts.loadPostings(oneQueryPostIds)) {
        cerr << "Cannot load postings for the query '" << line
             << "' after all postings are deleted. Perhaps, the memory budget "
                "is too small."
             << endl;
        cerr << "Aborting!" << endl;
        return -1;
      }
    }

    for (uint32_t id : oneQueryPostIds) {
      vector<uint32_t> buffer = uncompPosts.getOnePost(id);
      delta(0U, buffer.data(), buffer.size());
      er.eat(buffer.data(), buffer.size());
    }
  }
  logFile.close(); // we are done

  cout << "# next line is shannon entropy and data bits" << endl;
  cout << er.computeShannon() << "\t" << er.computeDataBits() << endl;
}
