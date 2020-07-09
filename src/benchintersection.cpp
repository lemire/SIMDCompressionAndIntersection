/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 */

#include <unistd.h>
#include "synthetic.h"
#include "timer.h"
#include "intersection.h"

// https://code.google.com/p/likwid/wiki/LikwidPerfCtr#Using_the_marker_API
#ifdef LIKWID_MARKERS // see 'make likwidintersection' for compiler flags
#include <likwid.h>
#endif

using namespace SIMDCompressionLib;

/**
 * Goal: have the largest array count about 4M terms (this
 * matches our experiments), and vary the size of the
 * smallest array vary from 1*4M to 1/1000*4M (or so).
 *
 * Set the size of the intersection to 30% of the lesser
 * array. (Again, this matches our real data...)
 *
 * To match our clueweb, we use a range of values in [0,2**26).
 */
template <class generator>
pair<vector<uint32_t>, vector<uint32_t>>
getNaivePair(generator gen, uint32_t minlength, uint32_t Max, float sizeratio,
             float intersectionratio) {
  if (sizeratio < 1)
    throw runtime_error("sizeratio should be larger or equal to 1");
  if (intersectionratio < 0)
    throw runtime_error("intersectionratio should be positive");
  if (intersectionratio > 1)
    throw runtime_error("intersectionratio cannot be larger than 1");
  const uint32_t maxlenth =
      static_cast<uint32_t>(round(static_cast<float>(minlength) * sizeratio));
  if (maxlenth > Max)
    throw runtime_error(
        "I can't generate an array so large in such a small range.");
  if (maxlenth < minlength)
    throw runtime_error("something went wrong, possibly an overflow.");
  // we basically assume that, if we do nothing, intersections are very small
  const uint32_t intersize = static_cast<uint32_t>(
      round(static_cast<float>(minlength) * intersectionratio));

  vector<uint32_t> inter = gen.generate(intersize, Max);
  vector<uint32_t> smallest =
      unite(gen.generate(static_cast<uint32_t>(minlength - inter.size()), Max),
            inter);
  vector<uint32_t> largest = unite(
      gen.generate(static_cast<uint32_t>(maxlenth - inter.size()), Max), inter);
  vector<uint32_t> intersection = intersect(smallest, largest);
  if (largest.size() > smallest.size())
    return pair<vector<uint32_t>, vector<uint32_t>>(smallest, largest);
  return pair<vector<uint32_t>, vector<uint32_t>>(largest, smallest);
}

/**
 * Silly function.
 */
uint16_t _high16(uint32_t x) { return static_cast<uint16_t>(x >> 16); }
/**
 * Another function.
 */
uint16_t _low16(uint32_t x) { return static_cast<uint16_t>(x); }

/**
 * From Schlegel et al., Fast Sorted-Set Intersection using SIMD Instructions
 */
// A - sorted array
// s_a - size of A
// R - partitioned sorted array
size_t partition(const uint32_t *A, const size_t s_a, uint16_t *R,
                 const size_t /*Rlength*/) {
  uint16_t high = 0;
  int partition_length = 0;
  size_t partition_size_position = 1;
  size_t counter = 0;
  size_t p = 0;
  if (p < s_a) {
    uint16_t chigh = _high16(A[p]); // upper dword
    uint16_t clow = _low16(A[p]);   // lower dword
    if (chigh == 0) {
      R[counter++] = chigh; // partition prefix
      R[counter++] = 0;     // reserve place for partition size
      R[counter++] = clow;  // write the first element
      partition_length = 1; // reset counters
      high = chigh;
      ++p;
    }
  }
  for (; p < s_a; p++) {
    uint16_t chigh = _high16(A[p]); // upper dword
    uint16_t clow = _low16(A[p]);   // lower dword
    if (chigh == high && p != 0) {  // add element to the current partition
      R[counter++] = clow;
      partition_length++;
    } else {                // start new partition
      R[counter++] = chigh; // partition prefix
      R[counter++] = 0;     // reserve place for partition size
      R[counter++] = clow;  // write the first element
      R[partition_size_position] =
          static_cast<uint16_t>(partition_length - 1); // store "-1"
      partition_length = 1;                            // reset counters
      partition_size_position = counter - 2;
      high = chigh;
    }
  }
  R[partition_size_position] = static_cast<uint16_t>(partition_length - 1);

  return counter;
}

const static __m128i shuffle_mask16[256] = {
    _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                  -1),
    _mm_setr_epi8(0, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(8, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(6, 7, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                  -1),
    _mm_setr_epi8(0, 1, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(6, 7, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 6, 7, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 6, 7, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 6, 7, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 6, 7, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 6, 7, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 6, 7, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 10, 11, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(8, 9, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(6, 7, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 6, 7, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 6, 7, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 6, 7, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 6, 7, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 6, 7, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, -1, -1, -1, -1),
    _mm_setr_epi8(12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                  -1),
    _mm_setr_epi8(0, 1, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(6, 7, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 6, 7, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 6, 7, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 6, 7, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 6, 7, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 6, 7, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 6, 7, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 12, 13, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(8, 9, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 8, 9, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 8, 9, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 8, 9, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 8, 9, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 8, 9, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 8, 9, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 8, 9, 12, 13, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(6, 7, 8, 9, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 6, 7, 8, 9, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 6, 7, 8, 9, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 6, 7, 8, 9, 12, 13, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 6, 7, 8, 9, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 6, 7, 8, 9, 12, 13, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 6, 7, 8, 9, 12, 13, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, -1, -1, -1, -1),
    _mm_setr_epi8(10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                  -1),
    _mm_setr_epi8(0, 1, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(6, 7, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 6, 7, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 6, 7, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 6, 7, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 6, 7, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 6, 7, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 6, 7, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 13, -1, -1, -1, -1),
    _mm_setr_epi8(8, 9, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 8, 9, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 8, 9, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 8, 9, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 8, 9, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 8, 9, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 8, 9, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 8, 9, 10, 11, 12, 13, -1, -1, -1, -1),
    _mm_setr_epi8(6, 7, 8, 9, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 6, 7, 8, 9, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 6, 7, 8, 9, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 6, 7, 8, 9, 10, 11, 12, 13, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 6, 7, 8, 9, 10, 11, 12, 13, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, -1, -1),
    _mm_setr_epi8(14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                  -1),
    _mm_setr_epi8(0, 1, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(6, 7, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 6, 7, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 6, 7, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 6, 7, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 6, 7, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 6, 7, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 6, 7, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(8, 9, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 8, 9, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 8, 9, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 8, 9, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 8, 9, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 8, 9, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 8, 9, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 8, 9, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(6, 7, 8, 9, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 6, 7, 8, 9, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 6, 7, 8, 9, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 6, 7, 8, 9, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 6, 7, 8, 9, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 6, 7, 8, 9, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 6, 7, 8, 9, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                  -1),
    _mm_setr_epi8(0, 1, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(6, 7, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 6, 7, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 6, 7, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 6, 7, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 6, 7, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 6, 7, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 6, 7, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 10, 11, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(8, 9, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 8, 9, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 8, 9, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 8, 9, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 8, 9, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 8, 9, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 8, 9, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 8, 9, 10, 11, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(6, 7, 8, 9, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 6, 7, 8, 9, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 6, 7, 8, 9, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 6, 7, 8, 9, 10, 11, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 6, 7, 8, 9, 10, 11, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 6, 7, 8, 9, 10, 11, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 14, 15, -1, -1),
    _mm_setr_epi8(12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                  -1),
    _mm_setr_epi8(0, 1, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(6, 7, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 6, 7, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 6, 7, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 6, 7, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 6, 7, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 6, 7, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 6, 7, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 12, 13, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(8, 9, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 8, 9, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 8, 9, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 8, 9, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 8, 9, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 8, 9, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 8, 9, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 8, 9, 12, 13, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(6, 7, 8, 9, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 6, 7, 8, 9, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 6, 7, 8, 9, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 6, 7, 8, 9, 12, 13, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 6, 7, 8, 9, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 6, 7, 8, 9, 12, 13, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 14, 15, -1, -1),
    _mm_setr_epi8(10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                  -1),
    _mm_setr_epi8(0, 1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(6, 7, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 6, 7, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 6, 7, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 6, 7, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 6, 7, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 6, 7, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 6, 7, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 13, 14, 15, -1, -1),
    _mm_setr_epi8(8, 9, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(4, 5, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1),
    _mm_setr_epi8(6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(2, 3, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1),
    _mm_setr_epi8(4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1),
    _mm_setr_epi8(0, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1),
    _mm_setr_epi8(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1),
    _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)};

/**
 * From Schlegel et al., Fast Sorted-Set Intersection using SIMD Instructions
 *
 * Close to the original
 */
static size_t _original_intersect_vector16(const uint16_t *A, const uint16_t *B,
                                           const size_t s_a, const size_t s_b,
                                           uint16_t *C) {
  size_t count = 0;
  size_t i_a = 0, i_b = 0;

  const size_t st_a = (s_a / 8) * 8;
  const size_t st_b = (s_b / 8) * 8;
  __m128i v_a, v_b;
  if ((i_a < st_a) and (i_b < st_b)) {
    v_a = _mm_loadu_si128((const __m128i *)&A[i_a]);
    v_b = _mm_loadu_si128((const __m128i *)&B[i_b]);
    while (true) {
        const __m128i res_v = _mm_cmpestrm(
            v_b, 16, v_a, 16,
            _SIDD_UWORD_OPS | _SIDD_CMP_EQUAL_ANY | _SIDD_BIT_MASK);
        const int r = _mm_extract_epi32(res_v, 0);
        __m128i p = _mm_shuffle_epi8(v_a, shuffle_mask16[r]);
        _mm_storeu_si128((__m128i *)&C[count], p);
        count += _mm_popcnt_u32(r);
        const uint16_t a_max = A[i_a + 7];
        const uint16_t b_max = B[i_b + 7];
        if (a_max <= b_max) {
          i_a += 8;
          if (i_a == st_a)
            break;
          v_a = _mm_loadu_si128((const __m128i *)&A[i_a]);
        }
        if (b_max <= a_max) {
          i_b += 8;
          if (i_b == st_b)
            break;
          v_b = _mm_loadu_si128((const __m128i *)&B[i_b]);
        }
    }
  }
  // intersect the tail using scalar intersection
  while (i_a < s_a && i_b < s_b) {
    if (A[i_a] < B[i_b]) {
      i_a++;
    } else if (B[i_b] < A[i_a]) {
      i_b++;
    } else {
      C[count] = A[i_a];
      count++;
      i_a++;
      i_b++;
    }
  }

  return count;
}

/**
 * From Schlegel et al., Fast Sorted-Set Intersection using SIMD Instructions
 *
 * Optimized by D. Lemire on May 3rd 2013
 */
static size_t _intersect_vector16(const uint16_t *A, const uint16_t *B,
                                  const size_t s_a, const size_t s_b,
                                  uint16_t *C) {
  size_t count = 0;
  size_t i_a = 0, i_b = 0;

  const size_t st_a = (s_a / 8) * 8;
  const size_t st_b = (s_b / 8) * 8;
  __m128i v_a, v_b;
  if ((i_a < st_a) and (i_b < st_b)) {
    v_a = _mm_loadu_si128((const __m128i *)&A[i_a]);
    v_b = _mm_loadu_si128((const __m128i *)&B[i_b]);
    while ((A[i_a] == 0) or (B[i_b] == 0)) {
      const __m128i res_v =
          _mm_cmpestrm(v_b, 8, v_a, 8,
                       _SIDD_UWORD_OPS | _SIDD_CMP_EQUAL_ANY | _SIDD_BIT_MASK);
      const int r = _mm_extract_epi32(res_v, 0);
      __m128i p = _mm_shuffle_epi8(v_a, shuffle_mask16[r]);
      _mm_storeu_si128((__m128i *)&C[count], p);
      count += _mm_popcnt_u32(r);
      const uint16_t a_max = A[i_a + 7];
      const uint16_t b_max = B[i_b + 7];
      if (a_max <= b_max) {
        i_a += 8;
        if (i_a == st_a)
          break;
        v_a = _mm_loadu_si128((const __m128i *)&A[i_a]);
      }
      if (b_max <= a_max) {
        i_b += 8;
        if (i_b == st_b)
          break;
        v_b = _mm_loadu_si128((const __m128i *)&B[i_b]);
      }
    }
    if ((i_a < st_a) and (i_b < st_b))
      while (true) {
        const __m128i res_v = _mm_cmpistrm(
            v_b, v_a, _SIDD_UWORD_OPS | _SIDD_CMP_EQUAL_ANY | _SIDD_BIT_MASK);
        const int r = _mm_extract_epi32(res_v, 0);
        __m128i p = _mm_shuffle_epi8(v_a, shuffle_mask16[r]);
        _mm_storeu_si128((__m128i *)&C[count], p);
        count += _mm_popcnt_u32(r);
        const uint16_t a_max = A[i_a + 7];
        const uint16_t b_max = B[i_b + 7];
        if (a_max <= b_max) {
          i_a += 8;
          if (i_a == st_a)
            break;
          v_a = _mm_loadu_si128((const __m128i *)&A[i_a]);
        }
        if (b_max <= a_max) {
          i_b += 8;
          if (i_b == st_b)
            break;
          v_b = _mm_loadu_si128((const __m128i *)&B[i_b]);
        }
      }
  }
  // intersect the tail using scalar intersection
  while (i_a < s_a && i_b < s_b) {
    if (A[i_a] < B[i_b]) {
      i_a++;
    } else if (B[i_b] < A[i_a]) {
      i_b++;
    } else {
      C[count] = A[i_a];
      count++;
      i_a++;
      i_b++;
    }
  }

  return count;
}

static size_t _intersectV1_vector16(const uint16_t *A, const uint16_t *B,
                                    const size_t s_a, const size_t s_b,
                                    uint16_t *C) {
  if (s_a > s_b)
    return _intersectV1_vector16(B, A, s_b, s_a, C);
  size_t count = 0;
  size_t i_a = 0, i_b = 0;
  const size_t st_a = s_a;
  const size_t st_b = (s_b / 8) * 8;
  __m128i v_b;
  if ((i_a < st_a) and (i_b < st_b)) {
    v_b = _mm_loadu_si128((const __m128i *)&B[i_b]);
    while (true) {
      const __m128i v_a = _mm_set1_epi16(A[i_a]);
      const __m128i F0 = _mm_cmpeq_epi16(v_a, v_b);
#ifdef __SSE4_1__
      if (_mm_testz_si128(F0, F0)) {
#else
      if (!_mm_movemask_epi8(F0)) {
#endif
      } else {
        C[count] = A[i_a];
        count++;
      }
      ++i_a;
      if (i_a == st_a)
        goto FINISH_SCALAR;
      if (B[i_b + 7] < A[i_a]) {
        i_b += 8;
        if (i_b == st_b)
          goto FINISH_SCALAR;
        v_b = _mm_loadu_si128((const __m128i *)&B[i_b]);
      }
    }
  }
FINISH_SCALAR:
  // intersect the tail using scalar intersection
  while (i_a < s_a && i_b < s_b) {
    if (A[i_a] < B[i_b]) {
      i_a++;
    } else if (B[i_b] < A[i_a]) {
      i_b++;
    } else {
      C[count] = A[i_a];
      count++;
      i_a++;
      i_b++;
    }
  }

  return count;
}

static size_t _intersectscalar_vector16(const uint16_t *A, const uint16_t *B,
                                        const size_t s_a, const size_t s_b,
                                        uint16_t *C) {
  // intersect the tail using scalar intersection
  size_t count = 0, i_a = 0, i_b = 0;
  while (i_a < s_a && i_b < s_b) {
    if (A[i_a] < B[i_b]) {
      i_a++;
    } else if (B[i_b] < A[i_a]) {
      i_b++;
    } else {
      C[count] = A[i_a];
      count++;
      i_a++;
      i_b++;
    }
  }

  return count;
}

size_t intersect_partitionedV1(const uint16_t *A, const size_t s_a,
                               const uint16_t *B, const size_t s_b,
                               uint16_t *C) {
  size_t i_a = 0, i_b = 0;
  size_t counter = 0;
  while (i_a < s_a && i_b < s_b) {
    if (A[i_a] < B[i_b]) {
      do {
        i_a += static_cast<size_t>(A[i_a + 1]) + 2 + 1;
        if (i_a >= s_a)
          goto end;
      } while (A[i_a] < B[i_b]);
    }
    if (B[i_b] < A[i_a]) {
      do {
        i_b += static_cast<size_t>(B[i_b + 1]) + 2 + 1;
        if (i_b >= s_b)
          goto end;
      } while (B[i_b] < A[i_a]);
    } else {
      size_t partition_size = _intersectV1_vector16(
          &A[i_a + 2], &B[i_b + 2], static_cast<size_t>(A[i_a + 1]) + 1,
          static_cast<size_t>(B[i_b + 1]) + 1, &C[counter + 1]);
      C[counter++] = (uint16_t) partition_size; // write partition size
      counter += partition_size;
      i_a += static_cast<size_t>(A[i_a + 1]) + 2 + 1;
      i_b += static_cast<size_t>(B[i_b + 1]) + 2 + 1;
    }
  }
end:
  return counter;
}

size_t intersect_partitionedscalar(const uint16_t *A, const size_t s_a,
                                   const uint16_t *B, const size_t s_b,
                                   uint16_t *C) {
  size_t i_a = 0, i_b = 0;
  size_t counter = 0;
  while (i_a < s_a && i_b < s_b) {
    if (A[i_a] < B[i_b]) {
      do {
        i_a += static_cast<size_t>(A[i_a + 1]) + 2 + 1;
        if (i_a >= s_a)
          goto end;
      } while (A[i_a] < B[i_b]);
    }
    if (B[i_b] < A[i_a]) {
      do {
        i_b += static_cast<size_t>(B[i_b + 1]) + 2 + 1;
        if (i_b >= s_b)
          goto end;
      } while (B[i_b] < A[i_a]);
    } else {
      size_t partition_size = _intersectscalar_vector16(
          &A[i_a + 2], &B[i_b + 2], static_cast<size_t>(A[i_a + 1]) + 1,
          static_cast<size_t>(B[i_b + 1]) + 1, &C[counter + 1]);
      C[counter++] = (uint16_t) partition_size; // write partition size
      counter += partition_size;
      i_a += static_cast<size_t>(A[i_a + 1]) + 2 + 1;
      i_b += static_cast<size_t>(B[i_b + 1]) + 2 + 1;
    }
  }
end:
  return counter;
}
/**
 * Version optimized by D. Lemire of
 * From Schlegel et al., Fast Sorted-Set Intersection using SIMD Instructions
 */
size_t intersect_partitioned(const uint16_t *A, const size_t s_a,
                             const uint16_t *B, const size_t s_b, uint16_t *C) {
  size_t i_a = 0, i_b = 0;
  size_t counter = 0;
  while (i_a < s_a && i_b < s_b) {
    if (A[i_a] < B[i_b]) {
      do {
        i_a += static_cast<size_t>(A[i_a + 1]) + 2 + 1;
        if (i_a >= s_a)
          goto end;
      } while (A[i_a] < B[i_b]);
    }
    if (B[i_b] < A[i_a]) {
      do {
        i_b += static_cast<size_t>(B[i_b + 1]) + 2 + 1;
        if (i_b >= s_b)
          goto end;
      } while (B[i_b] < A[i_a]);
    } else {
      size_t partition_size = _intersect_vector16(
          &A[i_a + 2], &B[i_b + 2], static_cast<size_t>(A[i_a + 1]) + 1,
          static_cast<size_t>(B[i_b + 1]) + 1, &C[counter + 1]);
      C[counter++] = (uint16_t) partition_size; // write partition size
      counter += partition_size;
      i_a += static_cast<size_t>(A[i_a + 1]) + 2 + 1;
      i_b += static_cast<size_t>(B[i_b + 1]) + 2 + 1;
    }
  }
end:
  return counter;
}
size_t original_intersect_partitioned(const uint16_t *A, const size_t s_a,
                                      const uint16_t *B, const size_t s_b,
                                      uint16_t *C) {
  size_t i_a = 0, i_b = 0;
  size_t counter = 0;
  while (i_a < s_a && i_b < s_b) {
    if (A[i_a] < B[i_b]) {
      do {
        i_a += static_cast<size_t>(A[i_a + 1]) + 2 + 1;
        if (i_a >= s_a)
          goto end;
      } while (A[i_a] < B[i_b]);
    }
    if (B[i_b] < A[i_a]) {
      do {
        i_b += static_cast<size_t>(B[i_b + 1]) + 2 + 1;
        if (i_b >= s_b)
          goto end;
      } while (B[i_b] < A[i_a]);
    } else {
      size_t partition_size = _original_intersect_vector16(
          &A[i_a + 2], &B[i_b + 2], static_cast<size_t>(A[i_a + 1]) + 1,
          static_cast<size_t>(B[i_b + 1]) + 1, &C[counter + 1]);
      C[counter++] = (uint16_t) partition_size; // write partition size
      counter += partition_size;
      i_a += static_cast<size_t>(A[i_a + 1]) + 2 + 1;
      i_b += static_cast<size_t>(B[i_b + 1]) + 2 + 1;
    }
  }
end:
  return counter;
}

void printusage() {
#ifdef LIKWID_MARKERS
  cout << "example: likwid -m -C 1 -g BRANCH ./likwidintersection -u > "
          "uniform.out"
       << endl;
#else
  cout << " -u switches to uniform distribution" << endl;
#endif
}

int main(int argc, char **argv) {
  size_t howmany = 0;
  size_t loop = 3;
  bool uniform = false;
  uint32_t Big = 22;
  float intersectionratio = 0.3f;
  uint32_t MaxBit = 26;
  int c;
  while ((c = getopt(argc, argv, "uns:m:R:M:S:l:h")) != -1)
    switch (c) {
    case 'h':
      printusage();
      return 0;
    case 'S':
      Big = atoi(optarg);
      break;
    case 'R':
      intersectionratio = (float)atof(optarg);
      break;
    case 'M':
      MaxBit = atoi(optarg);
      if (MaxBit < 1) {
        printusage();
        return -1;
      }
      break;
    case 'm':
      howmany = atoi(optarg);
      if (howmany < 1) {
        printusage();
        return -1;
      }
      break;
    case 'l':
      loop = atoi(optarg);
      if (loop < 1) {
        printusage();
        return -1;
      }
      break;
    case 'u':
      uniform = true;
      break;
    default:
      abort();
    }
  if (howmany == 0) {
    howmany = 5;
  }
  cout << "# howmany : " << howmany << endl;
  cout << "# loop : " << loop << endl;
  cout << "# distribution : " << (uniform ? "uniform" : "clustered") << endl;
  cout << "# Big : " << Big << endl;
  cout << "# intersectionratio : " << intersectionratio << endl;
  cout << "# MaxBit : " << MaxBit << endl;
  UniformDataGenerator udg;
  ClusteredDataGenerator cdg;
  WallClockTimer z;
  size_t bogus = 0;
  vector<uint32_t> buffer(2 * (1U << Big));
#ifdef LIKWID_MARKERS
  char currentMarker[64];
  likwid_markerInit();
#endif

  cout << "# size-ratio\t";
  for (string intername : IntersectionFactory::allNames()) {
    cout << intername << "\t";
  }
  cout << " partioned (Schlegel et al.: improved, original) 16-bitV1 "
          "16-bitscalar ";
  cout << "relative-intersection-size " << endl;

  for (double ir = 1.001; ir <= 10000; ir = ir * sqrt(1.9)) {
    vector<pair<vector<uint32_t>, vector<uint32_t>>> data(howmany);
    uint32_t smallsize =
        static_cast<uint32_t>(round(static_cast<float>(1 << Big) / ir));
    cout << "#generating data...";
    cout.flush();
    for (size_t k = 0; k < howmany; ++k) {
      data[k] = uniform ? getNaivePair(udg, smallsize, 1U << MaxBit, (float)ir,
                                       intersectionratio)
                        : getNaivePair(cdg, smallsize, 1U << MaxBit, (float)ir,
                                       intersectionratio);
    }
    cout << "ok." << endl;
    cout << "#partitions...";
    vector<pair<vector<uint16_t>, vector<uint16_t>>> datapart(howmany);
    for (size_t k = 0; k < howmany; ++k) {
      vector<uint16_t> part1(data[k].first.size() * 4);
      size_t p1length = partition(data[k].first.data(), data[k].first.size(),
                                  part1.data(), part1.size());
      part1.resize(p1length);
      part1.shrink_to_fit();
      vector<uint16_t> part2(data[k].second.size() * 4);
      size_t p2length = partition(data[k].second.data(), data[k].second.size(),
                                  part2.data(), part2.size());
      part2.resize(p2length);
      part2.shrink_to_fit();
      datapart[k] = make_pair(part1, part2);
    }
    cout << "ok." << endl;

    cout << ir << "\t";
    float aratio = 0.0f;
    for (string intername : IntersectionFactory::allNames()) {
      intersectionfunction interfnc =
          IntersectionFactory::getFromName(intername);
      size_t volume = 0;
#ifdef LIKWID_MARKERS
      snprintf(currentMarker, sizeof(currentMarker), "%s %.2f",
               intername.c_str(), ir);
      likwid_markerStartRegion(currentMarker);
#endif
      z.reset();
      for (size_t k = 0; k < data.size(); ++k) {
        volume += (data[k].first.size() + data[k].second.size()) * loop;
        for (size_t L = 0; L < loop; ++L) {
          aratio = interfnc(data[k].first.data(), (data[k].first).size(),
                            data[k].second.data(), (data[k].second).size(),
                            buffer.data());
          bogus += size_t(aratio);
        }
      }
      cout << setw(10) << setprecision(5)
           << (volume / (static_cast<double>(z.split()))) << "\t";
#ifdef LIKWID_MARKERS
      likwid_markerStopRegion(currentMarker);
#endif
    }
    z.reset();
    size_t volume = 0;
    for (size_t k = 0; k < data.size(); ++k) {
      volume += (data[k].first.size() + data[k].second.size()) * loop;
      for (size_t L = 0; L < loop; ++L) {
        aratio = intersect_partitioned(
            datapart[k].first.data(), (datapart[k].first).size(),
            datapart[k].second.data(), (datapart[k].second).size(),
            (uint16_t *)buffer.data());
        bogus += size_t(aratio);
      }
    }
    cout << setw(10) << setprecision(5)
         << (volume / (static_cast<double>(z.split()))) << "\t";
    z.reset();
    volume = 0;
    for (size_t k = 0; k < data.size(); ++k) {
      volume += (data[k].first.size() + data[k].second.size()) * loop;
      for (size_t L = 0; L < loop; ++L) {
        aratio = original_intersect_partitioned(
            datapart[k].first.data(), (datapart[k].first).size(),
            datapart[k].second.data(), (datapart[k].second).size(),
            (uint16_t *)buffer.data());
        bogus += size_t(aratio);
      }
    }
    cout << setw(10) << setprecision(5)
         << (volume / (static_cast<double>(z.split()))) << "\t";
    z.reset();
    volume = 0;
    for (size_t k = 0; k < data.size(); ++k) {
      volume += (data[k].first.size() + data[k].second.size()) * loop;
      for (size_t L = 0; L < loop; ++L) {
        aratio = intersect_partitionedV1(
            datapart[k].first.data(), (datapart[k].first).size(),
            datapart[k].second.data(), (datapart[k].second).size(),
            (uint16_t *)buffer.data());
        bogus += size_t(aratio);
      }
    }
    cout << setw(10) << setprecision(5)
         << (volume / (static_cast<double>(z.split()))) << "\t";
    z.reset();
    volume = 0;
    for (size_t k = 0; k < data.size(); ++k) {
      volume += (data[k].first.size() + data[k].second.size()) * loop;
      for (size_t L = 0; L < loop; ++L) {
        aratio = intersect_partitionedscalar(
            datapart[k].first.data(), (datapart[k].first).size(),
            datapart[k].second.data(), (datapart[k].second).size(),
            (uint16_t *)buffer.data());
        bogus += size_t(aratio);
      }
    }
    cout << setw(10) << setprecision(5)
         << (volume / (static_cast<double>(z.split()))) << "\t";
    cout << "\t\t" << aratio / smallsize;
    cout << endl;
  }
#ifdef LIKWID_MARKERS
  likwid_markerClose();
#endif

  cout << "# bogus = " << bogus << endl;
}
