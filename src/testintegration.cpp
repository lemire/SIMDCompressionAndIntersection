/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 */

#include "common.h"
#include "util.h"
#include "timer.h"
#include "bitpackinghelpers.h"
#include "simdbitpackinghelpers.h"
#include "delta.h"
#include "synthetic.h"

using namespace std;
using namespace SIMDCompressionLib;

vector<uint32_t> maskedcopy(const vector<uint32_t> &in, const uint32_t bit) {
  vector<uint32_t> out(in);
  if (bit == 32)
    return out;
  for (auto i = out.begin(); i != out.end(); ++i) {
    *i = *i % (1U << bit);
  }
  return out;
}

template <class container32bit>
bool equalOnFirstBits(const container32bit &data,
                      const container32bit &recovered, uint32_t bit) {
  if (bit == 32) {
    return data == recovered;
  }
  for (uint32_t k = 0; k < data.size(); ++k) {
    if (data[k] % (1U << bit) != recovered[k] % (1U << bit)) {
      cout << " They differ at k = " << k << " data[k]= " << data[k]
           << " recovered[k]=" << recovered[k] << endl;
      return false;
    }
  }
  return true;
}

uint32_t mask(uint32_t bit) {
  if (bit == 32)
    return 0xFFFFFFFFU;
  return (1U << bit) - 1;
}

template <class Helper>
void simplebenchmark(uint32_t N = 1U << 16, uint32_t T = 1U << 9) {
  T = T + 1; // we have a warming up pass
  uint32_t bogus = 0;
  vector<uint32_t> data(N);
  vector<uint32_t> compressed(N);
  vector<uint32_t> icompressed(N);
  vector<uint32_t> recovered(N);
  WallClockTimer z;
  double unpacktime;
  double iunpacktime;

  cout << "#million of integers per second: higher is better" << endl;
  cout << "#bit,  unpack,iunpack" << endl;

  for (uint32_t bitindex = 0; bitindex < 32; ++bitindex) {
    uint32_t bit = bitindex + 1;
    vector<uint32_t> initdata(N);
    for (size_t i = 0; 4 * i < data.size(); i += 4) {
      initdata[i] = random(bit) + (i >= 4 ? initdata[i - 4] : 0);
      for (size_t j = 1; j < 4; ++j) {
        initdata[i + j] = initdata[i];
      }
    }

    const vector<uint32_t> refdata = initdata;
    vector<uint32_t>().swap(initdata);

    icompressed.clear();
    // 4 * N should be enough for all  schemes
    icompressed.resize(4 * N, 0);
    compressed.clear();
    // 4 * N should be enough for all  schemes
    compressed.resize(4 * N, 0);
    recovered.clear();
    recovered.resize(N, 0);

    if (needPaddingTo128Bits(recovered.data())) {
      throw logic_error("Array is not aligned on 128 bit boundary!");
    }
    if (needPaddingTo128Bits(icompressed.data())) {
      throw logic_error("Array is not aligned on 128 bit boundary!");
    }
    if (needPaddingTo128Bits(compressed.data())) {
      throw logic_error("Array is not aligned on 128 bit boundary!");
    }
    if (needPaddingTo128Bits(refdata.data())) {
      throw logic_error("Array is not aligned on 128 bit boundary!");
    }

    for (uint32_t repeat = 0; repeat < 1; ++repeat) {

      unpacktime = 0;

      iunpacktime = 0;

      for (uint32_t t = 0; t <= T; ++t) {

        assert(data.size() == refdata.size());
        fill(icompressed.begin(), icompressed.end(), 0);
        fill(recovered.begin(), recovered.end(), 0);
        memcpy(data.data(), refdata.data(),
               data.size() * sizeof(uint32_t)); // memcpy can be slow
        Helper::pack(data.data(), data.size(), icompressed.data(), bit);
        z.reset();
        Helper::unpack(icompressed.data(), refdata.size(), recovered.data(),
                       bit);
        if (t > 0) // we don't count the first run
          unpacktime += static_cast<double>(z.split());
        if (!equalOnFirstBits(refdata, recovered, bit)) {
          cout << " Bug 1a " << bit << endl;
          return;
        }
        memcpy(data.data(), refdata.data(),
               data.size() * sizeof(uint32_t)); // memcpy can be slow
        Helper::pack(data.data(), data.size(), icompressed.data(), bit);

        z.reset();
        Helper::iunpack(icompressed.data(), refdata.size(), recovered.data(),
                        bit);
        if (t > 0) // we don't count the first run
          iunpacktime += static_cast<double>(z.split());
        if (!equalOnFirstBits(refdata, recovered, bit)) {
          cout << " Bug 2 " << bit << endl;
          return;
        }
      }

      cout << std::setprecision(4) << bit << "\t\t";
      cout << "\t\t" << N * (T - 1) / (unpacktime) << "\t\t";

      cout << "\t\t" << N * (T - 1) / (iunpacktime);

      cout << endl;
    }
  }
  cout << "# ignore this " << bogus << endl;
}

int main() {

  cout << "# SIMD bit-packing (regular) cache-to-cache 2^12" << endl;
  simplebenchmark<SIMDBitPackingHelpers<RegularDeltaSIMD>>(1U << 12, 1U << 14);
  cout << endl;
  cout << "# SIMD bit-packing (coarse delta 2) cache-to-cache 2^12" << endl;
  simplebenchmark<SIMDBitPackingHelpers<CoarseDelta2SIMD>>(1U << 12, 1U << 14);
  cout << endl;

  cout << "# SIMD bit-packing (coarse max 4) cache-to-cache 2^12" << endl;
  simplebenchmark<SIMDBitPackingHelpers<Max4DeltaSIMD>>(1U << 12, 1U << 14);
  cout << endl;

  cout << "# SIMD bit-packing (coarse delta 4) cache-to-cache 2^12" << endl;
  simplebenchmark<SIMDBitPackingHelpers<CoarseDelta4SIMD>>(1U << 12, 1U << 14);
  cout << endl;

  cout << "# Scalar cache-to-cache 2^12" << endl;
  simplebenchmark<BitPackingHelpers>(1U << 12, 1U << 14);
  cout << endl;

  return 0;
}
