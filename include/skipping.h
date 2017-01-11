/*
 * This is a simple implementation of a skipping data structure and algorithms similar to
 * what is described in
 *
 * Sanders and Transier, Intersection in Integer Inverted Indices, ALENEX 2007,  2007.
 *
 * As suggested in their conclusion, we leave the higher-level structure uncompressed. We also
 * use differential coding.
 * 
 * To paraphrase Sanders and Transier...
 *
 * In addition to a delta-encoded compressed list, a top-level data structure stores 
 * every B-th element of N in t together with its position in the main list (B is a tuning 
 * parameter). We can now run any  search algorithm on t and then scan only the pieces of 
 * the main list that might contain an element to be located.
 *
 * In our implementation, we assume that B is a power of two and use 1 << BlockSizeLog as
 * the block size.
 *
 * Sanders and Transier's proposal is similar in spirit to the skipping
 * structure proposed in
 *
 * Moffat, A., Zobel, J.: Self-indexing inverted files for fast text retrieval.
 * ACM Transactions on Information Systems 14 (1996).
 *
 *
 *      Author: Daniel Lemire
 */

#ifndef SIMDCompressionAndIntersection_SKIPPING_H_
#define SIMDCompressionAndIntersection_SKIPPING_H_

#include "common.h"

namespace SIMDCompressionLib {

class Skipping {
public:
  Skipping(uint32_t BS, const uint32_t *data, uint32_t length)
      : BlockSizeLog(BS), mainbuffer(), highbuffer(), Length(0) {
    if ((BlockSizeLog == 0) && (BlockSizeLog >= 32))
      throw runtime_error("please use a reasonable BlockSizeLog");
    load(data, length); // cheap constructor
  }

  ~Skipping() {}

  size_t storageInBytes() const {
    return mainbuffer.size() * sizeof(uint8_t) +
           highbuffer.size() * sizeof(higharraypair) +
           sizeof(Length); // rough estimates (good enough)
  }

  uint32_t decompress(uint32_t *out) const {
    const uint8_t *bout = mainbuffer.data();
    uint32_t pos = 0;

    uint32_t val = 0;
    for (uint32_t k = 0; k < Length; ++k) {
      bout = decode(bout, val);
      out[pos++] = val;
    }
    return pos;
  }

  /**
   * Intersects the current Skipping structure with a (small) uncompressed array
   * and
   * writes the answer to out.
   */
  uint32_t intersect(const uint32_t *smallarray, uint32_t length,
                     uint32_t *out) const {
    uint32_t intersectsize = 0;
    const uint8_t *largemainpointer = mainbuffer.data();
    uint32_t largemainval = 0;
    largemainpointer = decode(largemainpointer, largemainval);
    uint32_t x = 0;
    for (uint32_t k = 0; k < length; ++k) {
      uint32_t val = smallarray[k];
      // if the last value of the current block is too small, skip the block
      // entirely
      if (highbuffer[x >> BlockSizeLog].first < val) {
        do {
          x = ((x >> BlockSizeLog) + 1) << BlockSizeLog;
          if (x >= Length) {
            return intersectsize;
          }
        } while (highbuffer[x >> BlockSizeLog].first < val);
        largemainpointer =
            mainbuffer.data() + highbuffer[x >> BlockSizeLog].second;
        largemainval = highbuffer[(x >> BlockSizeLog) - 1].first;
        largemainpointer = decode(largemainpointer, largemainval);
      }
      // at this point, we have that the last value of the current block is >=
      // val
      // this means that we shall decode at most one block before giving up
      while (largemainval < val) {
        ++x;
        if (x >= Length) {
          return intersectsize;
        }
        largemainpointer = decode(largemainpointer, largemainval);
      }
      if (largemainval == val) {
        out[intersectsize++] = val;
      }
    }
    return intersectsize;
  }
  uint32_t intersect(const Skipping &otherlarger, uint32_t *out) const {
    // we assume that "this" is the smallest of the two
    if (otherlarger.Length < Length)
      return otherlarger.intersect(*this, out);
    if (Length == 0)
      return 0; // special silly case
    assert(otherlarger.Length >= Length);
    assert(otherlarger.Length > 0);
    uint32_t intersectsize = 0;

    const uint8_t *inbyte = mainbuffer.data();
    const uint8_t *const endbyte = mainbuffer.data() + mainbuffer.size();
    const uint8_t *largemainpointer = otherlarger.mainbuffer.data();
    uint32_t largemainval = 0;
    largemainpointer = decode(largemainpointer, largemainval);
    uint32_t val = 0; // where I put decoded values
    uint32_t x = 0;
    while (endbyte > inbyte) {
      inbyte = decode(inbyte, val);
      // if the last value of the current block is too small, skip the block
      // entirely
      if (otherlarger.highbuffer[x >> otherlarger.BlockSizeLog].first < val) {
        do {
          x = ((x >> otherlarger.BlockSizeLog) + 1) << otherlarger.BlockSizeLog;
          if (x >= otherlarger.Length) {
            return intersectsize;
          }
        } while (otherlarger.highbuffer[x >> otherlarger.BlockSizeLog].first <
                 val);
        largemainpointer =
            otherlarger.mainbuffer.data() +
            otherlarger.highbuffer[x >> otherlarger.BlockSizeLog].second;
        largemainval =
            otherlarger.highbuffer[(x >> otherlarger.BlockSizeLog) - 1].first;
        largemainpointer = decode(largemainpointer, largemainval);
      }
      // at this point, we have that the last value of the current block is >=
      // val
      // this means that we shall decode at most one block before giving up
      while (largemainval < val) {
        ++x;
        if (x >= otherlarger.Length) {
          return intersectsize;
        }
        largemainpointer = decode(largemainpointer, largemainval);
      }
      if (largemainval == val) {
        out[intersectsize++] = val;
      }
    }
    return intersectsize;
  }

  uint32_t BlockSizeLog;
  vector<uint8_t> mainbuffer;
  typedef pair<uint32_t, uint32_t> higharraypair;

  typedef vector<higharraypair> higharray;
  higharray highbuffer;
  uint32_t Length;

  // please don't use the default constructor...

  Skipping() : BlockSizeLog(0), mainbuffer(), highbuffer(), Length(0) {}

private:
  Skipping(const Skipping &);

  // making it private on purpose
  Skipping &operator=(const Skipping &);

  void load(const uint32_t *data, uint32_t length);

  template <uint32_t i> uint8_t extract7bits(const uint32_t val) {
    return static_cast<uint8_t>((val >> (7 * i)) & ((1U << 7) - 1));
  }

  template <uint32_t i> uint8_t extract7bitsmaskless(const uint32_t val) {
    return static_cast<uint8_t>((val >> (7 * i)));
  }
  static inline const uint8_t *decode(const uint8_t *buffer, uint32_t &prev) {
    // manually unrolled for performance
    uint32_t v = 0;
    uint8_t c = *buffer++;
    v += (c & 127);
    if ((c & 128)) {
      prev += v;
      return buffer;
    }
    c = *buffer++;
    v += ((c & 127) << 7);
    if ((c & 128)) {
      prev += v;
      return buffer;
    }
    c = *buffer++;
    v += ((c & 127) << 14);
    if ((c & 128)) {
      prev += v;
      return buffer;
    }
    c = *buffer++;
    v += ((c & 127) << 21);
    if ((c & 128)) {
      prev += v;
      return buffer;
    }
    c = *buffer++;
    v += ((c & 127) << 30);
    prev += v;
    return buffer;
  }
};

void Skipping::load(const uint32_t *data, uint32_t len) {
  assert(numeric_limits<uint32_t>::max() <
         (numeric_limits<size_t>::max() / 5)); // check for overflow
  Length = len;
  if (Length == 0)
    return; // nothing to do
  uint32_t BlockNumber = (Length + (1 << BlockSizeLog) - 1) /
                         (1 << BlockSizeLog); // count full blocks
  assert(BlockNumber << BlockSizeLog >= Length);
  highbuffer.resize(BlockNumber);
  mainbuffer.resize(5 * Length);
  uint8_t *bout = mainbuffer.data();
  uint8_t *const boutinit = bout;
  uint32_t prev = 0;
  for (uint32_t k = 0; k < BlockNumber; ++k) {
    const uint32_t howmany = (((k + 1) << BlockSizeLog) > Length)
                                 ? Length - (k << BlockSizeLog)
                                 : 1 << BlockSizeLog;
    highbuffer[k] = make_pair(data[(k << BlockSizeLog) + howmany - 1],
                              static_cast<uint32_t>(bout - boutinit));
    for (uint32_t x = 0; x < howmany; ++x) {
      const uint32_t v = data[x + (k << BlockSizeLog)];
      const uint32_t val = v - prev;
      prev = v;
      if (val < (1U << 7)) {
        *bout = static_cast<uint8_t>(val | (1U << 7));
        ++bout;
      } else if (val < (1U << 14)) {
        *bout = extract7bits<0>(val);
        ++bout;
        *bout = extract7bitsmaskless<1>(val) | (1U << 7);
        ++bout;
      } else if (val < (1U << 21)) {
        *bout = extract7bits<0>(val);
        ++bout;
        *bout = extract7bits<1>(val);
        ++bout;
        *bout = extract7bitsmaskless<2>(val) | (1U << 7);
        ++bout;
      } else if (val < (1U << 28)) {
        *bout = extract7bits<0>(val);
        ++bout;
        *bout = extract7bits<1>(val);
        ++bout;
        *bout = extract7bits<2>(val);
        ++bout;
        *bout = extract7bitsmaskless<3>(val) | (1U << 7);
        ++bout;
      } else {
        *bout = extract7bits<0>(val);
        ++bout;
        *bout = extract7bits<1>(val);
        ++bout;
        *bout = extract7bits<2>(val);
        ++bout;
        *bout = extract7bits<3>(val);
        ++bout;
        *bout = extract7bitsmaskless<4>(val) | (1U << 7);
        ++bout;
      }
    }
  }
  mainbuffer.resize(static_cast<uint32_t>(bout - boutinit));
  mainbuffer.shrink_to_fit();
}

} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_SKIPPING_H_ */
