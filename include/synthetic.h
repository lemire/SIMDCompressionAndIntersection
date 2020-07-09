/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire
 */

#ifndef SIMDCompressionAndIntersection_SYNTHETIC_H_
#define SIMDCompressionAndIntersection_SYNTHETIC_H_

#include "common.h"
#include "util.h"
#include "mersenne.h"
#include "intersection.h"
#include "boolarray.h"

namespace SIMDCompressionLib {

using namespace std;

vector<uint32_t> generateArray(uint32_t N, const uint32_t mask = 0xFFFFFFFFU) {
  vector<uint32_t> ans(N);
  for (size_t k = 0; k < N; ++k)
    ans[k] = rand() & mask;
  return ans;
}

vector<uint32_t> generateArray32(uint32_t N,
                                 const uint32_t mask = 0xFFFFFFFFU) {
  vector<uint32_t> ans(N);
  for (size_t k = 0; k < N; ++k)
    ans[k] = rand() & mask;
  return ans;
}

class UniformDataGenerator {
public:
  UniformDataGenerator(uint32_t seed = static_cast<uint32_t>(time(NULL)))
      : rand(seed) {}

  void negate(vector<uint32_t> &in, vector<uint32_t> &out, uint32_t Max) {
    out.resize(Max - in.size());
    in.push_back(Max);
    uint32_t i = 0;
    size_t c = 0;
    for (size_t j = 0; j < in.size(); ++j) {
      const uint32_t v = in[j];
      for (; i < v; ++i)
        out[c++] = i;
      ++i;
    }
    assert(c == out.size());
  }

  /**
   * fill the vector with N numbers uniformly picked from  from 0 to Max, not
   * including Max
   * if it is not possible, an exception is thrown
   */
  vector<uint32_t> generateUniformHash(uint32_t N, uint32_t Max,
                                       vector<uint32_t> &ans) {
    if (Max < N)
      throw runtime_error(
          "can't generate enough distinct elements in small interval");
    ans.clear();
    if (N == 0)
      return ans; // nothing to do
    ans.reserve(N);
    assert(Max >= 1);
    unordered_set<uint32_t> s;
    while (s.size() < N)
      s.insert(rand.getValue(Max - 1));
    ans.assign(s.begin(), s.end());
    sort(ans.begin(), ans.end());
    assert(N == ans.size());
    return ans;
  }

  void generateUniformBitmap(uint32_t N, uint32_t Max, vector<uint32_t> &ans) {
    if (Max < N)
      throw runtime_error(
          "can't generate enough distinct elements in small interval");
    assert(Max >= 1);
    BoolArray bs(Max);
    uint32_t card = 0;
    while (card < N) {
      uint32_t v = rand.getValue(Max - 1);
      if (!bs.get(v)) {
        bs.set(v);
        ++card;
      }
    }
    ans.resize(N);
    bs.toArray(ans);
  }

  void fastgenerateUniform(uint32_t N, uint32_t Max, vector<uint32_t> &ans) {
    if (2 * N > Max) {
      vector<uint32_t> buf(N);
      fastgenerateUniform(Max - N, Max, buf);
      negate(buf, ans, Max);
      return;
    }
    if (N * 1024 > Max) {
      generateUniformBitmap(N, Max, ans);
    }
    generateUniformHash(N, Max, ans);
  }

  // Max value is excluded from range
  vector<uint32_t> generate(uint32_t N, uint32_t Max) {
    vector<uint32_t> ans;
    ans.reserve(N);
    fastgenerateUniform(N, Max, ans);
    return ans;
  }
  ZRandom rand;
};

/*
 * Reference: Vo Ngoc Anh and Alistair Moffat. 2010. Index compression using
 * 64-bit words. Softw. Pract. Exper.40, 2 (February 2010), 131-147.
 */
class ClusteredDataGenerator {
public:
  vector<uint32_t> buffer;
  UniformDataGenerator unidg;
  ClusteredDataGenerator(uint32_t seed = static_cast<uint32_t>(time(NULL)))
      : buffer(), unidg(seed) {}

  // Max value is excluded from range
  template <class iterator>
  void fillUniform(iterator begin, iterator end, uint32_t Min, uint32_t Max) {
    unidg.fastgenerateUniform(static_cast<uint32_t>(end - begin), Max - Min,
                              buffer);
    for (size_t k = 0; k < buffer.size(); ++k)
      *(begin + k) = Min + buffer[k];
  }

  // Max value is excluded from range
  // throws exception if impossible
  template <class iterator>
  void fillClustered(iterator begin, iterator end, uint32_t Min, uint32_t Max) {
    const uint32_t N = static_cast<uint32_t>(end - begin);
    const uint32_t range = Max - Min;
    if (range < N)
      throw runtime_error("can't generate that many in small interval.");
    assert(range >= N);
    if ((range == N) or (N < 10)) {
      fillUniform(begin, end, Min, Max);
      return;
    }
    const uint32_t cut = N / 2 + unidg.rand.getValue(range - N);
    assert(cut >= N / 2);
    assert(Max - Min - cut >= N - N / 2);
    const double p = unidg.rand.getDouble();
    assert(p <= 1);
    assert(p >= 0);
    if (p <= 0.25) {
      fillUniform(begin, begin + N / 2, Min, Min + cut);
      fillClustered(begin + N / 2, end, Min + cut, Max);
    } else if (p <= 0.5) {
      fillClustered(begin, begin + N / 2, Min, Min + cut);
      fillUniform(begin + N / 2, end, Min + cut, Max);
    } else {
      fillClustered(begin, begin + N / 2, Min, Min + cut);
      fillClustered(begin + N / 2, end, Min + cut, Max);
    }
  }

  // Max value is excluded from range
  vector<uint32_t> generate(uint32_t N, uint32_t Max) {
    return generateClustered(N, Max);
  }

  // Max value is excluded from range
  vector<uint32_t> generateClustered(uint32_t N, uint32_t Max) {
    vector<uint32_t> ans(N);
    fillClustered(ans.begin(), ans.end(), 0, Max);
    return ans;
  }
};

class ZipfianGenerator {
public:
  uint32_t n;
  double zetan, theta;
  vector<double> proba;

  ZRandom rand;
  ZipfianGenerator(uint32_t seed = static_cast<uint32_t>(time(NULL)))
      : n(0), zetan(0), theta(0), proba(n), rand(seed) {}

  void init(int _items, double _zipfianconstant = 1.0) {
    n = _items;
    if (_items == 0)
      throw runtime_error("no items?");
    theta = _zipfianconstant;
    if (theta > 0) {
      zetan = 1 / zeta(n, theta);
      proba.clear();
      proba.resize(n, 0);
      proba[0] = zetan;
      for (uint32_t i = 1; i < n; ++i)
        proba[i] = proba[i - 1] + zetan / pow(i + 1, theta);
    } else {
      proba.resize(n, 1.0 / n);
    }
  }

  void seed(uint32_t s) { rand.seed(s); }

  ZipfianGenerator(int _items, double _zipfianconstant,
                   uint32_t seed = static_cast<uint32_t>(time(NULL)))
      : n(_items), zetan(0), theta(_zipfianconstant), proba(n), rand(seed) {
    init(_items, _zipfianconstant);
  }

  double zeta(int nn, double ttheta) {
    double sum = 0;
    for (long i = 0; i < nn; i++) {
      sum += 1 / (pow(i + 1, ttheta));
    }
    return sum;
  }
  int nextInt() {
    // Map z to the value
    const double u = rand.getDouble();
    return static_cast<int>(lower_bound(proba.begin(), proba.end(), u) -
                            proba.begin());
  }
};

vector<uint32_t> generateZipfianArray32(uint32_t N, double power,
                                        const uint32_t mask = 0xFFFFFFFFU) {
  vector<uint32_t> ans(N);
  ZipfianGenerator zipf;
  const uint32_t MAXVALUE = 1U << 22;
  zipf.init(mask > MAXVALUE - 1 ? MAXVALUE : mask + 1, power);
  for (size_t k = 0; k < N; ++k)
    ans[k] = zipf.nextInt();
  return ans;
}

size_t unite(const uint32_t *set1, const size_t length1, const uint32_t *set2,
             const size_t length2, uint32_t *out) {
  size_t pos = 0;
  size_t k1 = 0, k2 = 0;
  if (0 == length1) {
    for (size_t k = 0; k < length2; ++k)
      out[k] = set2[k];
    return length2;
  }
  if (0 == length2) {
    for (size_t k = 0; k < length1; ++k)
      out[k] = set1[k];
    return length1;
  }
  while (true) {
    if (set1[k1] < set2[k2]) {
      out[pos++] = set1[k1];
      ++k1;
      if (k1 >= length1) {
        for (; k2 < length2; ++k2)
          out[pos++] = set2[k2];
        break;
      }
    } else if (set1[k1] == set2[k2]) {
      out[pos++] = set1[k1];
      ++k1;
      ++k2;
      if (k1 >= length1) {
        for (; k2 < length2; ++k2)
          out[pos++] = set2[k2];
        break;
      }
      if (k2 >= length2) {
        for (; k1 < length1; ++k1)
          out[pos++] = set1[k1];
        break;
      }
    } else { // if (set1[k1]>set2[k2]) {
      out[pos++] = set2[k2];
      ++k2;
      if (k2 >= length2) {
        for (; k1 < length1; ++k1)
          out[pos++] = set1[k1];
        break;
      }
    }
  }
  return pos;
}

vector<uint32_t> unite(const vector<uint32_t> &x, const vector<uint32_t> &y) {
  vector<uint32_t> ans(x.size() + y.size());
  ans.resize(unite(x.data(), x.size(), y.data(), y.size(), ans.data()));
  return ans;
}

size_t classicalintersection(const uint32_t *set1, const size_t length1,
                             const uint32_t *set2, const size_t length2,
                             uint32_t *out) {
  if ((0 == length1) or (0 == length2))
    return 0;
  size_t answer = 0;
  size_t k1 = 0, k2 = 0;
  while (true) {
    if (set1[k1] < set2[k2]) {
      ++k1;
      if (k1 == length1)
        return answer;
    } else if (set2[k2] < set1[k1]) {
      ++k2;
      if (k2 == length2)
        return answer;
    } else {
      // (set2[k2] == set1[k1])
      out[answer++] = set1[k1];
      ++k1;
      if (k1 == length1)
        break;
      ++k2;
      if (k2 == length2)
        break;
    }
  }
  return answer;
}

vector<uint32_t> intersect(const vector<uint32_t> &x,
                           const vector<uint32_t> &y) {
  vector<uint32_t> ans(x.size() + y.size());
  ans.resize(classicalintersection(x.data(), x.size(), y.data(), y.size(),
                                   ans.data()));
  return ans;
}
/**
 * Generate a pair of arrays. One small, one larger.
 *
 *  minlength: length of the smallest of the two arrays
 *  Max is the largest possible value
 *  sizeratio * minlength : length of the largest of the two arrays
 *  intersectionratio * minlength : length of the intersection
 */
template <class generator>
pair<vector<uint32_t>, vector<uint32_t>>
getPair(generator gen, uint32_t minlength, uint32_t Max, float sizeratio,
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

  if (abs(static_cast<double>(intersection.size()) /
              static_cast<double>(smallest.size()) -
          intersectionratio) > 0.05)
    throw runtime_error("Bad intersection ratio. Fix me.");

  if (abs(static_cast<double>(largest.size()) /
              static_cast<double>(smallest.size()) -
          sizeratio) > 0.05)
    throw runtime_error("Bad size ratio. Fix me.");
  return pair<vector<uint32_t>, vector<uint32_t>>(smallest, largest);
}

} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_SYNTHETIC_H_ */
