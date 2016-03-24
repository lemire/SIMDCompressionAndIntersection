/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Leonid Boytsov, Nathan Kurz and Daniel Lemire
 */

#ifndef SIMDCompressionAndIntersection_DELTA_H_
#define SIMDCompressionAndIntersection_DELTA_H_

#include "common.h"

namespace SIMDCompressionLib {

/**
 * To avoid crazy dependencies, this header should not
 * include any other header file.
 */

template <class T> void delta(const T initoffset, T *data, const size_t size) {
  if (size == 0)
    return; // nothing to do
  if (size > 1)
    for (size_t i = size - 1; i > 0; --i) {
      data[i] -= data[i - 1];
    }
  data[0] -= initoffset;
}

template <size_t size, class T> void delta(const T initoffset, T *data) {
  if (size == 0)
    return; // nothing to do
  if (size > 1)
    for (size_t i = size - 1; i > 0; --i) {
      data[i] -= data[i - 1];
    }
  data[0] -= initoffset;
}

template <class T>
void inverseDelta(const T initoffset, T *data, const size_t size) {
  if (size == 0)
    return; // nothing to do
  data[0] += initoffset;
  const size_t UnrollQty = 4;
  const size_t sz0 =
      (size / UnrollQty) * UnrollQty; // equal to 0, if size < UnrollQty
  size_t i = 1;
  if (sz0 >= UnrollQty) {
    T a = data[0];
    for (; i < sz0 - UnrollQty; i += UnrollQty) {
      a = data[i] += a;
      a = data[i + 1] += a;
      a = data[i + 2] += a;
      a = data[i + 3] += a;
    }
  }
  for (; i != size; ++i) {
    data[i] += data[i - 1];
  }
}
template <size_t size, class T> void inverseDelta(const T initoffset, T *data) {
  if (size == 0)
    return; // nothing to do
  data[0] += initoffset;
  const size_t UnrollQty = 4;
  const size_t sz0 =
      (size / UnrollQty) * UnrollQty; // equal to 0, if size < UnrollQty
  size_t i = 1;
  if (sz0 >= UnrollQty) {
    T a = data[0];
    for (; i < sz0 - UnrollQty; i += UnrollQty) {
      a = data[i] += a;
      a = data[i + 1] += a;
      a = data[i + 2] += a;
      a = data[i + 3] += a;
    }
  }
  for (; i != size; ++i) {
    data[i] += data[i - 1];
  }
}

} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_DELTA_H_ */
