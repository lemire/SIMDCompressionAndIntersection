#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "codecfactory.h"

#ifdef _MSC_VER
#include <windows.h>

__int64 freq;

typedef __int64 time_snap_t;

static time_snap_t time_snap(void) {
  __int64 now;

  QueryPerformanceCounter((LARGE_INTEGER *)&now);

  return (__int64)((now * 1000000) / freq);
}
#define TIME_SNAP_FMT "%I64d"
#else
#define time_snap clock
#define TIME_SNAP_FMT "%lu"
typedef clock_t time_snap_t;
#endif

int uint32_cmp(const void *a, const void *b) {
  const uint32_t *ia = (const uint32_t *)a;
  const uint32_t *ib = (const uint32_t *)b;
  if (*ia < *ib)
    return -1;
  else if (*ia > *ib)
    return 1;
  return 0;
}

template <typename T> int benchmarkSelect() {
  T codec;
  static const size_t N = 256;
  uint32_t buffer[N];
  uint32_t backbuffer[N];
  uint32_t b;
  time_snap_t S1, S2, S3;
  size_t i;
  printf("# benchmarking select %s \n", codec.name().c_str());
  srand(0);

  /* this test creates delta encoded buffers with different bits, then
   * performs lower bound searches for each key */
  for (b = 0; b <= 32; b++) {
    uint32_t out[N * 2];
    uint32_t prev = 0;
    /* initialize the buffer */
    for (i = 0; i < N; i++) {
      buffer[i] = ((uint32_t)rand());
      if (b < 32)
        buffer[i] %= (1 << b);
    }
    for (i = 0; i < N; i++) {
      buffer[i] = buffer[i] + prev;
      prev = buffer[i];
    }
    qsort(buffer, N, sizeof(uint32_t), uint32_cmp);

    for (i = 0; i < N; i++) {
      out[i] = 0; /* memset would do too */
    }

    /* delta-encode to 'i' bits */
    size_t nvalue = 2 * N;

    codec.encodeArray(buffer, N, out, nvalue);

    S1 = time_snap();
    for (i = 0; i < N * 10; i++) {
      uint32_t valretrieved = codec.select(out, i % N);
      if (valretrieved != buffer[i % N]) {
        printf("# Bug\n");
        return -1;
      }
    }
    S2 = time_snap();
    for (i = 0; i < N * 10; i++) {
      size_t recovlength = N;
      codec.decodeArray(out, nvalue, backbuffer, recovlength);
      if (backbuffer[i % N] != buffer[i % N]) {
        printf("# Bug\n");
        return -1;
      }
    }
    S3 = time_snap();
    printf("# bit width = %d, fast select function time = " TIME_SNAP_FMT
           ", naive time = " TIME_SNAP_FMT ", following line is in millions of "
                                           "operation per second, last line is "
                                           "decompression speed  \n",
           b, (S2 - S1), (S3 - S2));
    printf("%d %f %f %f %f \n", b, N * 10.0 / (S2 - S1), N * 10.0 / (S3 - S2),
           nvalue * 32.0 / N, N * 10.0 * N / (S3 - S2));
  }
  printf("\n\n");
  return 0;
}

/* adapted from wikipedia */
int binary_search(uint32_t *A, uint32_t key, int imin, int imax) {
  int imid;
  imax--;
  while (imin + 1 < imax) {
    imid = imin + ((imax - imin) / 2);

    if (A[imid] > key) {
      imax = imid;
    } else if (A[imid] < key) {
      imin = imid;
    } else {
      return imid;
    }
  }
  return imax;
}

/* adapted from wikipedia */
int lower_bound(uint32_t *A, uint32_t key, int imin, int imax) {
  int imid;
  imax--;
  while (imin + 1 < imax) {
    imid = imin + ((imax - imin) / 2);

    if (A[imid] >= key) {
      imax = imid;
    } else if (A[imid] < key) {
      imin = imid;
    }
  }
  if (A[imin] >= key)
    return imin;
  return imax;
}

template <typename T, size_t N = 256> int benchmarkSearch() {
  T codec;
  uint32_t buffer[N];
  uint32_t backbuffer[N];
  uint32_t out[N * 2];
  uint32_t result, initial = 0;
  uint32_t b, i;
  time_snap_t S1, S2, S3;
  printf("# benchmarking search %s N=%lu \n", codec.name().c_str(), N);
  srand(0);

  /* this test creates delta encoded buffers with different bits, then
   * performs lower bound searches for each key */
  for (b = 0; b <= 32; b++) {
    uint32_t prev = initial;
    /* initialize the buffer */
    for (i = 0; i < N; i++) {
      buffer[i] = ((uint32_t)rand());
      if (b < 32)
        buffer[i] %= (1 << b);
    }
    for (i = 0; i < N; i++) {
      buffer[i] = buffer[i] + prev;
      prev = buffer[i];
    }

    qsort(buffer, N, sizeof(uint32_t), uint32_cmp);

    for (i = 0; i < N; i++) {
      out[i] = 0; /* memset would do too */
    }
    size_t nvalue = N * 2;

    codec.encodeArray(buffer, N, out, nvalue);
    {
      size_t recovlength = N;
      codec.decodeArray(out, nvalue, backbuffer, recovlength);
      assert(recovlength == N);
      for (size_t k = 0; k < N; k++) {
        assert(backbuffer[k] == buffer[k]);
      }
    }
    S1 = time_snap();
    for (i = 0; i < N * 10; i++) {
      uint32_t pseudorandomkey = buffer[i % N];
      result = 0;
      size_t pos = codec.findLowerBound(out, (uint32_t)nvalue, pseudorandomkey, &result);
      if ((result < pseudorandomkey) || (buffer[pos] != result)) {
        printf("bug A: pseudorandomkey = %u result = %u  buffer[%zu] = %u .\n",
               pseudorandomkey, result, pos, buffer[pos]);
        return -1;
      } else if (pos > 0) {
        if (buffer[pos - 1] >= pseudorandomkey) {
          printf("bug B.\n");
          return -1;
        }
      }
    }
    S2 = time_snap();
    for (i = 0; i < N * 10; i++) {
      int pos;
      uint32_t pseudorandomkey = buffer[i % N];
      size_t recovlength = N;
      codec.decodeArray(out, nvalue, backbuffer, recovlength);
      pos = lower_bound(backbuffer, pseudorandomkey, 0, N);
      result = backbuffer[pos];

      if ((result < pseudorandomkey) || (buffer[pos] != result)) {
        printf("bug C.\n");
        return -1;
      } else if (pos > 0) {
        if (buffer[pos - 1] >= pseudorandomkey) {
          printf("bug D.\n");
          return -1;
        }
      }
    }
    S3 = time_snap();
    printf("# bit width = %d, fast search function time = " TIME_SNAP_FMT
           ", naive time = " TIME_SNAP_FMT
           ", following line is in millions of operation per second \n",
           b, (S2 - S1), (S3 - S2));
    printf("%d %f %f %f \n", b, N * 10.0 / (S2 - S1), N * 10.0 / (S3 - S2),
           nvalue * 32.0 / N);
  }
  printf("\n\n");
  return 0;
}

template <typename T> int benchmarkInsert() {
  T codec;
  const int max = 256;
  srand(0);
  time_snap_t S1, S2, S3;
  printf("# benchmarking insert %s \n", codec.name().c_str());
  // encode in a buffer
  std::vector<uint32_t> compressedbuffer1(max * sizeof(uint32_t) + 1024);
  std::vector<uint32_t> compressedbuffer2(max * sizeof(uint32_t) + 1024);

  std::vector<uint32_t> buffer(max);
  std::vector<uint32_t> backbuffer(max);

  for (int b = 0; b <= 32; b++) {
    compressedbuffer1.resize(compressedbuffer1.capacity());
    compressedbuffer1[0] = 0; // required for streamvbyte
    compressedbuffer1[1] = 0;
    compressedbuffer2[0] = 0;
    compressedbuffer2[1] = 0;
    compressedbuffer2.resize(compressedbuffer2.capacity());

    /* initialize the buffer */
    for (int i = 0; i < max; i++) {
      buffer[i] = ((uint32_t)rand());
      if (b < 32)
        buffer[i] %= (1 << b);
    }
    S1 = time_snap();

    size_t currentsize1 = 0;
    for (int i = 0; i < max; i++) {
      currentsize1 =
          codec.insert(compressedbuffer1.data(), (uint32_t)currentsize1, buffer[i]);
    }
    S2 = time_snap();

    size_t currentsize2 = 0;
    for (int i = 0; i < max; i++) {
      size_t recovlength = backbuffer.size();
      codec.decodeArray(compressedbuffer2.data(), currentsize2,
                        backbuffer.data(), recovlength);
      auto it = lower_bound(backbuffer.begin(),
                            backbuffer.begin() + recovlength, buffer[i]);
      backbuffer.insert(it, buffer[i]);
      currentsize2 = compressedbuffer2.size();
      codec.encodeArray(backbuffer.data(), recovlength + 1,
                        compressedbuffer2.data(), currentsize2);
    }
    S3 = time_snap();

    printf("# bit width = %d, fast insert function time = " TIME_SNAP_FMT
           ", naive time = " TIME_SNAP_FMT " \n",
           b, (S2 - S1), (S3 - S2));
    printf("%d " TIME_SNAP_FMT " " TIME_SNAP_FMT " \n", b, (S2 - S1),
           (S3 - S2));
    if (currentsize1 != currentsize2) {
      printf("bug A: %u != %u\n", (uint32_t)currentsize1,
             (uint32_t)currentsize2);
      return -1;
    }
    compressedbuffer1.resize(currentsize1);
    compressedbuffer2.resize(currentsize2);
    if (compressedbuffer1 != compressedbuffer2) {
      printf("bug B\n");
      return -1;
    }
  }

  printf("\n\n");
  return 0;
}

// same as testAppend<>, but uses encodeByteArray/decodeByteArray
// to avoid padding
template <typename T> int benchmarkAppendToByteArray() {
  T codec;
  const int max = 256;
  srand(0);
  time_snap_t S1, S2, S3;
  printf("# benchmarking insert %s \n", codec.name().c_str());
  // encode in a buffer
  std::vector<uint32_t> compressedbuffer1(max * sizeof(uint32_t) + 1024);
  std::vector<uint32_t> compressedbuffer2(max * sizeof(uint32_t) + 1024);

  std::vector<uint32_t> buffer(max);
  std::vector<uint32_t> backbuffer(max);

  for (int b = 0; b <= 32; b++) {
    compressedbuffer1.resize(compressedbuffer1.capacity());
    compressedbuffer1[0] = 0; // required for streamvbyte
    compressedbuffer1[1] = 0;
    compressedbuffer2[0] = 0;
    compressedbuffer2[1] = 0;
    compressedbuffer2.resize(compressedbuffer2.capacity());

    /* initialize the buffer */
    for (int i = 0; i < max; i++) {
      buffer[i] = ((uint32_t)rand());
      if (b < 32)
        buffer[i] %= (1 << b);
    }
    S1 = time_snap();

    size_t currentsize1 = 0;
    for (int i = 0; i < max; i++) {
      currentsize1 = codec.appendToByteArray(
          (uint8_t *)compressedbuffer1.data(), currentsize1,
          i == 0 ? 0 : buffer[i - 1], buffer[i]);
    }
    S2 = time_snap();

    size_t currentsize2 = 0;
    for (int i = 0; i < max; i++) {
      size_t recovlength = backbuffer.size();
      codec.decodeArray(compressedbuffer2.data(), currentsize2,
                        backbuffer.data(), recovlength);
      backbuffer[recovlength] = buffer[i];
      currentsize2 = compressedbuffer2.size();
      codec.encodeArray(backbuffer.data(), recovlength + 1,
                        compressedbuffer2.data(), currentsize2);
    }
    S3 = time_snap();

    printf("# bit width = %d, fast append function time = " TIME_SNAP_FMT
           ", naive time = " TIME_SNAP_FMT " \n",
           b, (S2 - S1), (S3 - S2));
    printf("%d " TIME_SNAP_FMT " " TIME_SNAP_FMT " \n", b, (S2 - S1),
           (S3 - S2));
  }

  printf("\n\n");
  return 0;
}

using namespace SIMDCompressionLib;
int main() {
  int r = 0;
#ifdef _MSC_VER
  QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
#endif

  r = benchmarkInsert<SIMDCompressionLib::StreamVByteD1>();
  if (r < 0)
    return r;
  r = benchmarkInsert<SIMDCompressionLib::VarIntGB<true>>();
  if (r < 0)
    return r;
  r = benchmarkInsert<SIMDCompressionLib::VariableByte<true>>();
  if (r < 0)
    return r;
  r = benchmarkInsert<SIMDCompressionLib::VByte<true>>();
  if (r < 0)
    return r;

  r = benchmarkSearch<SIMDCompressionLib::SIMDFrameOfReference>();
  if (r < 0)
    return r;
  r = benchmarkSearch<SIMDCompressionLib::FrameOfReference>();
  if (r < 0)
    return r;
  r = benchmarkSearch<SIMDCompressionLib::ForCODEC>();
  if (r < 0)
    return r;
  r = benchmarkSearch<SIMDCompressionLib::VarIntGB<true>>();
  if (r < 0)
    return r;
  r = benchmarkSearch<SIMDCompressionLib::MaskedVByte<true>>();
  if (r < 0)
    return r;
  r = benchmarkSearch<SIMDCompressionLib::VariableByte<true>>();
  if (r < 0)
    return r;
  r = benchmarkSearch<SIMDCompressionLib::VByte<true>>();
  if (r < 0)
    return r;
  r = benchmarkSearch<
      SIMDBinaryPacking<SIMDIntegratedBlockPacker<RegularDeltaSIMD, true>>>();
  if (r < 0)
    return r;
  r = benchmarkSearch<SIMDCompressionLib::StreamVByteD1>();
  if (r < 0)
    return r;

  r = benchmarkSelect<SIMDCompressionLib::SIMDFrameOfReference>();
  if (r < 0)
    return r;
  r = benchmarkSelect<SIMDCompressionLib::FrameOfReference>();
  if (r < 0)
    return r;
  r = benchmarkSelect<SIMDCompressionLib::ForCODEC>();
  if (r < 0)
    return r;
  r = benchmarkSelect<SIMDCompressionLib::VarIntGB<true>>();
  if (r < 0)
    return r;
  r = benchmarkSelect<SIMDCompressionLib::MaskedVByte<true>>();
  if (r < 0)
    return r;
  r = benchmarkSelect<SIMDCompressionLib::VariableByte<true>>();
  if (r < 0)
    return r;
  r = benchmarkSelect<SIMDCompressionLib::VByte<true>>();
  if (r < 0)
    return r;
  r = benchmarkSelect<
      SIMDBinaryPacking<SIMDIntegratedBlockPacker<RegularDeltaSIMD, true>>>();
  if (r < 0)
    return r;
  r = benchmarkSelect<SIMDCompressionLib::StreamVByteD1>();
  if (r < 0)
    return r;

  r = benchmarkAppendToByteArray<SIMDCompressionLib::SIMDFrameOfReference>();
  if (r < 0)
    return r;
  r = benchmarkAppendToByteArray<SIMDCompressionLib::FrameOfReference>();
  if (r < 0)
    return r;
  r = benchmarkAppendToByteArray<SIMDCompressionLib::ForCODEC>();
  if (r < 0)
    return r;
  r = benchmarkAppendToByteArray<SIMDCompressionLib::VarIntGB<true>>();
  if (r < 0)
    return r;
  r = benchmarkAppendToByteArray<SIMDCompressionLib::MaskedVByte<true>>();
  if (r < 0)
    return r;
  r = benchmarkAppendToByteArray<SIMDCompressionLib::VariableByte<true>>();
  if (r < 0)
    return r;
  r = benchmarkAppendToByteArray<SIMDCompressionLib::VByte<true>>();
  if (r < 0)
    return r;
  r = benchmarkAppendToByteArray<SIMDCompressionLib::StreamVByteD1>();
  if (r < 0)
    return r;

  r = benchmarkSearch<SIMDCompressionLib::VarIntGB<true>, 128>();
  if (r < 0)
    return r;
  return 0;
}
