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

void printusage() {
  cout << " Try ./compress -s nameofscheme input.bin output.bin" << endl;
}

int main(int argc, char **argv) {
  string scheme;
  int c;
  while ((c = getopt(argc, argv, "s:h")) != -1)
    switch (c) {
    case 's':
      scheme = optarg;
      break;
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

    shared_ptr<IntegerCODEC> schemeptr = CODECFactory::getFromName(scheme);
    if (schemeptr.get() == NULL)
      return -1;

    MaropuGapReader reader(ifilename);
    if (!reader.open()) {
      cout << " could not open " << ifilename << " for reading..." << endl;
      return -1;
    }
    FILE *fd = ::fopen(ofilename.c_str(), "wb");
    if (fd == NULL) {
      cout << " could not open " << ofilename << " for writing..." << endl;
      return -1;
    }
    cout << "Compressing content from " << ifilename << " to " << ofilename
         << " using " << scheme << endl;
    vector<uint32_t> buffer;

    // write a format version number
    uint32_t VERSION = 1;
    if (fwrite(&VERSION, sizeof(VERSION), 1, fd) != 1) {
      cerr << "aborting" << endl;
      ::fclose(fd);
      reader.close();
      return -1;
    }
    // store the scheme identifier
    uint32_t schemesize = static_cast<uint32_t>(scheme.size() * sizeof(char));
    if (fwrite(&schemesize, sizeof(schemesize), 1, fd) != 1) {
      cerr << "aborting" << endl;
      ::fclose(fd);
      reader.close();
      return -1;
    }

    if (fwrite(scheme.c_str(), scheme.size() * sizeof(char), 1, fd) != 1) {
      cerr << "aborting" << endl;
      ::fclose(fd);
      reader.close();
      return -1;
    }
    vector<uint32_t> obuffer(1024);
    size_t numberofarrays = 0;
    size_t volume = 0;
    size_t volumeout = 0;
    WallClockTimer z;
    while (reader.loadIntegers(buffer)) {
      if (obuffer.size() < buffer.size() + 1024) {
        obuffer.resize(buffer.size() + 1024);
      }
      size_t outsize = obuffer.size();
      schemeptr->encodeArray(buffer.data(), buffer.size(), obuffer.data(),
                             outsize);
      uint32_t osize = static_cast<uint32_t>(outsize);
      if (fwrite(&osize, sizeof(uint32_t), 1, fd) != 1) {
        cerr << "aborting" << endl;
        ::fclose(fd);
        return -1;
      }
      uint32_t insize = static_cast<uint32_t>(buffer.size());
      if (fwrite(&insize, sizeof(uint32_t), 1, fd) != 1) {
        cerr << "aborting" << endl;
        ::fclose(fd);
        return -1;
      }
      if (fwrite(obuffer.data(), sizeof(uint32_t) * outsize, 1, fd) != 1) {
        cerr << "aborting" << endl;
        ::fclose(fd);
        return -1;
      }
      volumeout += sizeof(osize) + sizeof(insize) + sizeof(uint32_t) * outsize;
      volume += buffer.size();
      if (numberofarrays % 1000 == 0) {
        cout << ".";
        cout.flush();
      }
      ++numberofarrays;
    }
    cout << endl;
    long ti = z.split();
    cout << "Wrote " << numberofarrays << " arrays " << endl;
    cout << "Compressed " << volume << " integers " << endl;
    if (volume > 0)
      cout << "Bits per int : "
           << (8.0 * static_cast<double>(volumeout)) /
                  static_cast<double>(volume)
           << endl;
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
