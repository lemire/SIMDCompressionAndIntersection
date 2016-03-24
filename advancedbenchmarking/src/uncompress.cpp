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
#include "maropuparser.h"
#include "codecfactory.h"

using namespace SIMDCompressionLib;

void printusage() { cout << " Try ./uncompress input.bin output.bin" << endl; }

int main(int argc, char **argv) {
  string scheme;
  int c;
  while ((c = getopt(argc, argv, "h")) != -1)
    switch (c) {
    case 'h':
      printusage();
      return 0;
    default:
      abort();
    }
  if (optind + 1 >= argc) {
    printusage();
    return -1;
  }
  try {
    string ifilename = argv[optind];
    string ofilename = argv[optind + 1];
    FILE *fd = ::fopen(ifilename.c_str(), "rb");
    if (fd == NULL) {
      cerr << " can't open " << ifilename << endl;
      return -1;
    }
    FILE *fdout = ::fopen(ofilename.c_str(), "wb");
    if (fdout == NULL) {
      cerr << " can't open " << ofilename << endl;
      ::fclose(fd);
      return -1;
    }
    cout << "uncompressing " << ifilename << " to " << ofilename << endl;
    uint32_t version;
    size_t result = fread(&version, sizeof(version), 1, fd);
    cout << "compressed file format version = " << version << endl;
    if (result != 1) {
      cerr << "wrong version" << endl;
      ::fclose(fd);
      ::fclose(fdout);
      return -1;
    }
    uint32_t schemesize;
    result = fread(&schemesize, sizeof(schemesize), 1, fd);
    if (result != 1) {
      ::fclose(fd);
      ::fclose(fdout);
      return -1;
    }
    vector<char> b(schemesize + 1);
    result = fread(b.data(), schemesize * sizeof(char), 1, fd);
    if (result != 1) {
      ::fclose(fd);
      ::fclose(fdout);
      return -1;
    }
    string schemename(b.data());
    cout << " data was compressed using " << schemename << endl;
    shared_ptr<IntegerCODEC> schemeptr = CODECFactory::getFromName(schemename);
    if (schemeptr.get() == NULL) {
      return -1;
    }
    vector<uint32_t> buffer, obuffer;
    size_t i = 0;
    size_t volume = 0;
    WallClockTimer z;
    while (true) {
      uint32_t csize;
      result = fread(&csize, sizeof(uint32_t), 1, fd);
      if (result != 1) {
        break;
      }
      uint32_t osize;
      result = fread(&osize, sizeof(uint32_t), 1, fd);
      if (result != 1) {
        break;
      }
      obuffer.resize(osize);
      buffer.resize(csize);
      result = fread(buffer.data(), sizeof(uint32_t) * csize, 1, fd);
      if (result != 1) {
        break;
      }
      size_t sosize(osize);
      schemeptr->decodeArray(buffer.data(), buffer.size(), obuffer.data(),
                             sosize);
      assert(sosize == osize);
      if (fwrite(&osize, sizeof(osize), 1, fdout) != 1) {
        cerr << "aborting" << endl;
        ::fclose(fd);
        ::fclose(fdout);
        return -1;
      }
      if (fwrite(obuffer.data(), sizeof(uint32_t) * osize, 1, fdout) != 1) {
        cerr << "aborting" << endl;
        ::fclose(fd);
        ::fclose(fdout);
        return -1;
      }

      if (i % 1000 == 0) {
        cout << ".";
        cout.flush();
      }
      volume += osize;
      ++i;
    }
    cout << endl;
    long ti = z.split();

    cout << " Uncompressed " << i << " arrays and " << volume << " integers "
         << endl;
    ::fclose(fd);
    ::fclose(fdout);
    if (ti > 0) {
      double speed = static_cast<double>(volume) / static_cast<double>(ti);
      cout << " Speed: " << speed << " mis " << endl;
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
