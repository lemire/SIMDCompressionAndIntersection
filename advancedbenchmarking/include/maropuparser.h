/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef SIMDCompressionAndIntersection_MAROPUPARSER_H_
#define SIMDCompressionAndIntersection_MAROPUPARSER_H_

#include <stdexcept>
#include <sstream>

#include <stdio.h>

#include "common.h"

using namespace std;

/**
 * This is just a bit of code to parse the binary files provided by the
 * Maropu-Open-Coders library at
 * http://integerencoding.isti.cnr.it/?page_id=8
 *
 * (Despite the name, this does not necessarily reads gaps.)
 *
 * Note that due to use of strerror this code may be thread-unsafe!
 *
 */
class MaropuGapReader {
public:
  MaropuGapReader(const string &filename) : mFilename(filename), fd(NULL) {}

  /**
   * The copy constructor will assign the same file name,
   * but the newly constructed object won't be opened.
   */
  MaropuGapReader(const MaropuGapReader &mgr)
      : mFilename(mgr.mFilename), fd(NULL) {}

  /**
   * Assignment will close the current reader, and change
   * the file name. You need to reopen the reader after the assignment.
   */
  MaropuGapReader &operator=(const MaropuGapReader &mgr) {
    close();
    mFilename = mgr.mFilename;
    return *this;
  }

  ~MaropuGapReader() { close(); }

  // @daniel: should we worry about our code being compilable on 32-bit
  // machines?
  // if so, we need to add -D_FILE_OFFSET_BITS=64 to the makefile
  // Daniel: it would seem odd to consider 32-bit machines when we assume AVX
  // support!
  off_t getPos() {
    errno = 0;
    off_t res = ftello(fd);
    if (res < 0) {
      stringstream err;
      err << "Error getting file position, IO status: " << strerror(errno);
      throw runtime_error(err.str());
    }
    return res;
  }

  void setPos(off_t pos) {
    errno = 0;
    off_t res = fseeko(fd, pos, SEEK_SET);
    if (res < 0) {
      stringstream err;
      err << "Error setting file position, IO status: " << strerror(errno);
      throw runtime_error(err.str());
    }
  }

  /*
   * Return false if no more data can be loaded.
   * Throw an exception in the case of IO error.
   */
  template <class container> bool loadIntegers(container &buffer) {
    uint32_t qty = 0;
    if (!ReadQty(qty))
      return false; // EOF
    buffer.resize(qty);
    errno = 0;
    size_t result = fread(buffer.data(), sizeof(uint32_t), buffer.size(), fd);
    if (result != buffer.size()) {
      if (!errno) {
        // If we can't read, the file maybe truncated, i.e., corrupt
        throw runtime_error("The file appears to be truncated/corrupt!");
      }
      stringstream err;
      err << "Error reading from file, IO status: " << strerror(errno);
      throw runtime_error(err.str());
    }
    return true;
  }

  /*
   * Return false if no more data can be loaded.
   * Throw an exception in the case of IO error.
   */
  bool readNextPosAndQty(off_t &pos, uint32_t &qty) {
    pos = getPos();
    if (!ReadQty(qty))
      return false; // EOF
    setPos(getPos() + qty * sizeof(uint32_t));
    return true;
  }

  /**
  * We must call open before we can use this class  meaningfully.
  */
  bool open() {
    close();
    fd = ::fopen(mFilename.c_str(), "rb");
    if (fd == NULL) {
      return false;
    }
    setvbuf(fd, NULL, _IOFBF, 1024 * 4); // large buffer
    return true;
  }

  void close() {
    if (fd != NULL) {
      ::fclose(fd);
      fd = NULL;
    }
  }

private:
  /*
   * Returns false on EOF.
   * Throws an exception in the case of IO error.
   */
  bool ReadQty(uint32_t &qty) {
    qty = 0;
    if (fd == NULL) {
      throw runtime_error("You forgot to open the file.");
    }
    errno = 0;
    size_t result = fread(&qty, sizeof(qty), 1, fd);
    if (errno) {
      stringstream err;
      err << "Error opening file, IO status: " << strerror(errno);
      throw runtime_error(err.str());
    }
    if (result != 1) {
      return false;
    }
    if (qty > 1 << 29) {
      cout << "warning: reading a very large array (" << qty
           << " integers) : is your input file in the right format?" << endl;
    }
    return true;
  }

  string mFilename;
  FILE *fd;
};

#endif /* SIMDCompressionAndIntersection_MAROPUPARSER_H_ */
