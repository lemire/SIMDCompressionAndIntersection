#include "frameofreference.h"

static __m128i *simdpackFOR_length(uint32_t initvalue, const uint32_t *in,
                                   int length, __m128i *out,
                                   const uint32_t bit) {
  int k;
  int inwordpointer;
  __m128i P;
  uint32_t firstpass;
  __m128i offset;
  if (bit == 0)
    return out; /* nothing to do */
  if (bit == 32) {
    memcpy(out, in, length * sizeof(uint32_t));
    return (__m128i *)((uint32_t *)out + length);
  }
  offset = _mm_set1_epi32(initvalue);
  inwordpointer = 0;
  P = _mm_setzero_si128();
  for (k = 0; k < length / 4; ++k) {
    __m128i value =
        _mm_sub_epi32(_mm_loadu_si128(((const __m128i *)in + k)), offset);
    P = _mm_or_si128(P, _mm_slli_epi32(value, inwordpointer));
    firstpass = sizeof(uint32_t) * 8 - inwordpointer;
    if (bit < firstpass) {
      inwordpointer += bit;
    } else {
      _mm_storeu_si128(out++, P);
      P = _mm_srli_epi32(value, firstpass);
      inwordpointer = bit - firstpass;
    }
  }
  if (length % 4 != 0) {
    uint32_t buffer[4];
    __m128i value;
    for (k = 0; k < (length % 4); ++k) {
      buffer[k] = in[length / 4 * 4 + k];
    }
    for (k = (length % 4); k < 4; ++k) {
      buffer[k] = 0;
    }
    value = _mm_sub_epi32(_mm_loadu_si128((__m128i *)buffer), offset);
    P = _mm_or_si128(P, _mm_slli_epi32(value, inwordpointer));
    firstpass = sizeof(uint32_t) * 8 - inwordpointer;
    if (bit < firstpass) {
      inwordpointer += bit;
    } else {
      _mm_storeu_si128(out++, P);
      P = _mm_srli_epi32(value, firstpass);
      inwordpointer = bit - firstpass;
    }
  }
  if (inwordpointer != 0) {
    _mm_storeu_si128(out++, P);
  }
  return out;
}

static const __m128i *simdunpackFOR_length(uint32_t initvalue,
                                           const __m128i *in, int length,
                                           uint32_t *out, const uint32_t bit) {
  int k;
  __m128i maskbits;
  int inwordpointer;
  __m128i P;
  __m128i offset;
  if (length == 0)
    return in;
  if (bit == 0) {
    for (k = 0; k < length; ++k) {
      out[k] = initvalue;
    }
    return in;
  }
  if (bit == 32) {
    memcpy(out, in, length * sizeof(uint32_t));
    return (const __m128i *)((const uint32_t *)in + length);
  }
  offset = _mm_set1_epi32(initvalue);
  maskbits = _mm_set1_epi32((1 << bit) - 1);
  inwordpointer = 0;
  P = _mm_loadu_si128((__m128i *)in);
  ++in;
  for (k = 0; k < length / 4; ++k) {
    __m128i answer = _mm_srli_epi32(P, inwordpointer);
    const uint32_t firstpass = sizeof(uint32_t) * 8 - inwordpointer;
    if (bit < firstpass) {
      inwordpointer += bit;
    } else {
      P = _mm_loadu_si128((__m128i *)in);
      ++in;
      answer = _mm_or_si128(_mm_slli_epi32(P, firstpass), answer);
      inwordpointer = bit - firstpass;
    }
    answer = _mm_and_si128(maskbits, answer);
    _mm_storeu_si128((__m128i *)out, _mm_add_epi32(answer, offset));
    out += 4;
  }
  if (length % 4 != 0) {
    uint32_t buffer[4];
    __m128i answer = _mm_srli_epi32(P, inwordpointer);
    const uint32_t firstpass = sizeof(uint32_t) * 8 - inwordpointer;
    if (bit < firstpass) {
      inwordpointer += bit;
    } else {
      P = _mm_loadu_si128((__m128i *)in);
      ++in;
      answer = _mm_or_si128(_mm_slli_epi32(P, firstpass), answer);
      inwordpointer = bit - firstpass;
    }
    answer = _mm_and_si128(maskbits, answer);
    _mm_storeu_si128((__m128i *)buffer, _mm_add_epi32(answer, offset));
    for (k = 0; k < (length % 4); ++k) {
      *out = buffer[k];
      ++out;
    }
  }
  return in;
}

static uint32_t *pack1_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 1;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 3;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 5;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 7;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 9;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 11;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 13;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 15;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 17;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 19;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 21;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 23;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 25;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 27;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 29;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 31;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack2_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack3_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 3;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 9;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 15;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 21;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 27;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (3 - 1);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 1;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 7;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 13;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 19;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 25;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 31;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (3 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 5;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 11;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 17;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 23;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 29;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack4_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack5_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 5;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 15;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 25;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (5 - 3);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 3;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 13;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 23;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (5 - 1);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 1;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 11;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 21;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 31;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (5 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 9;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 19;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 29;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (5 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 7;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 17;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 27;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack6_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (6 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (6 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (6 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (6 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack7_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 7;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 21;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (7 - 3);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 3;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 17;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 31;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (7 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 13;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 27;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (7 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 9;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 23;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (7 - 5);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 5;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 19;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (7 - 1);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 1;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 15;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 29;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (7 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 11;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 25;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack8_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack9_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 9;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 27;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (9 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 13;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 31;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (9 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 17;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (9 - 3);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 3;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 21;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (9 - 7);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 7;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 25;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (9 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 11;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 29;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (9 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 15;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (9 - 1);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 1;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 19;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (9 - 5);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 5;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 23;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack10_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (10 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (10 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (10 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (10 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (10 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (10 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (10 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (10 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack11_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 11;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (11 - 1);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 1;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 23;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (11 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 13;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (11 - 3);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 3;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 25;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (11 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 15;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (11 - 5);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 5;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 27;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (11 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 17;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (11 - 7);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 7;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 29;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (11 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 19;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (11 - 9);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 9;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 31;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (11 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 21;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack12_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (12 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (12 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (12 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (12 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (12 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (12 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (12 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (12 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack13_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 13;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (13 - 7);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 7;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (13 - 1);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 1;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 27;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (13 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 21;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (13 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 15;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (13 - 9);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 9;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (13 - 3);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 3;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 29;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (13 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 23;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (13 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 17;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (13 - 11);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 11;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (13 - 5);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 5;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 31;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (13 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 25;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (13 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 19;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack14_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (14 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (14 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (14 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (14 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (14 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (14 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (14 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (14 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (14 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (14 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (14 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (14 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack15_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 15;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (15 - 13);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 13;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (15 - 11);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 11;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (15 - 9);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 9;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (15 - 7);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 7;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (15 - 5);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 5;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (15 - 3);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 3;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (15 - 1);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 1;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 31;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (15 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 29;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (15 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 27;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (15 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 25;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (15 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 23;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (15 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 21;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (15 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 19;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (15 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 17;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack16_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack17_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 17;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (17 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 19;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (17 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 21;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (17 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 23;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (17 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 25;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (17 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 27;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (17 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 29;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (17 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 31;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (17 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (17 - 1);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 1;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (17 - 3);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 3;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (17 - 5);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 5;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (17 - 7);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 7;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (17 - 9);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 9;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (17 - 11);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 11;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (17 - 13);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 13;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (17 - 15);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 15;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack18_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (18 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (18 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (18 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (18 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (18 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (18 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (18 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (18 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (18 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (18 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (18 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (18 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (18 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (18 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (18 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (18 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack19_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 19;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 25;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 31;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 18);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 5);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 5;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 11);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 11;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 17);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 17;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 23;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 29;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 3);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 3;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 9);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 9;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 15);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 15;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 21;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 27;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 1);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 1;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 7);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 7;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (19 - 13);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 13;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack20_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (20 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (20 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (20 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (20 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (20 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (20 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (20 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (20 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (20 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (20 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (20 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (20 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (20 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (20 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (20 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (20 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack21_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 21;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 31;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 20);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 9);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 9;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 19);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 19;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 29;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 18);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 7);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 7;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 17);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 17;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 27;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 5);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 5;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 15);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 15;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 25;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 3);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 3;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 13);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 13;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 23;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 1);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 1;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (21 - 11);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 11;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack22_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 18);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 20);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 18);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 20);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (22 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack23_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 23;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 5);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 5;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 19);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 19;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 1);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 1;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 15);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 15;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 29;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 20);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 11);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 11;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 25;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 7);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 7;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 21);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 21;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 3);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 3;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 17);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 17;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 31;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 22);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 13);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 13;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 27;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 18);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (23 - 9);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 9;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack24_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack25_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 25;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 18);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 11);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 11;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 29;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 22);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 15);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 15;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 1);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 1;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 19);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 19;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 5);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 5;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 23);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 23;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 9);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 9;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 27;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 20);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 13);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 13;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 31;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 24);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 17);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 17;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 3);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 3;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 21);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 21;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (25 - 7);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 7;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack26_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 20);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 22);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 24);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 18);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 20);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 22);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 24);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 18);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (26 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack27_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 27;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 22);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 17);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 17;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 7);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 7;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 29;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 24);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 19);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 19;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 9);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 9;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 31;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 26);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 21);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 21;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 11);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 11;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 1);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 1;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 23);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 23;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 18);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 13);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 13;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 3);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 3;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 25);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 25;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 20);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 15);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 15;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (27 - 5);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 5;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack28_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 24);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 20);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 24);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 20);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 24);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 20);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 24);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 20);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (28 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack29_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 29;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 26);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 23);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 23;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 20);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 17);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 17;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 11);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 11;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 5);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 5;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 31;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 28);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 25);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 25;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 22);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 19);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 19;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 13);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 13;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 7);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 7;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 1);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 1;
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 27);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 27;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 24);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 21);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 21;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 18);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 15);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 15;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 9);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 9;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (29 - 3);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 3;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack30_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 28);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 26);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 24);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 22);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 20);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 18);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++out;
  ++in;
  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 28);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 26);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 24);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 22);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 20);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 18);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (30 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack31_32(uint32_t base, const uint32_t *in, uint32_t *out) {

  *out = static_cast<uint32_t>((*in) - base);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 31;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 30);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 30;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 29);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 29;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 28);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 28;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 27);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 27;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 26);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 26;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 25);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 25;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 24);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 24;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 23);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 23;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 22);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 22;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 21);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 21;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 20);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 20;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 19);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 19;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 18);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 18;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 17);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 17;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 16);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 16;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 15);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 15;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 14);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 14;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 13);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 13;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 12);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 12;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 11);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 11;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 10);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 10;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 9);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 9;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 8);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 8;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 7);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 7;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 6);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 6;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 5);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 5;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 4);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 4;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 3);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 3;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 2);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 2;
  ++out;
  *out = static_cast<uint32_t>((*in) - base) >> (31 - 1);
  ++in;
  *out |= static_cast<uint32_t>((*in) - base) << 1;
  ++out;
  ++in;

  return out;
}

static uint32_t *pack32_32(uint32_t, const uint32_t *in, uint32_t *out) {
  memcpy(out, in, 32 * sizeof(uint32_t));
  return out + 32;
}

static const uint32_t *unpack1_32(uint32_t base, const uint32_t *in,
                                  uint32_t *out) {

  *out = ((*in) >> 0) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 1) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 2) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 3) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 4) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 5) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 6) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 7) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 8) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 9) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 10) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 11) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 12) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 13) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 14) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 15) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 16) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 17) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 18) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 19) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 20) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 21) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 22) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 23) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 24) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 25) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 26) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 27) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 28) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 29) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 30) & 1;
  *out += base;
  out++;
  *out = ((*in) >> 31);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack2_32(uint32_t base, const uint32_t *in,
                                  uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 14) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 18) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 20) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 22) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 24) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 26) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 28) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 14) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 18) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 20) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 22) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 24) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 26) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 28) % (1U << 2);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack3_32(uint32_t base, const uint32_t *in,
                                  uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 3) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 9) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 15) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 18) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 21) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 24) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 27) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 1)) << (3 - 1);
  *out += base;
  out++;
  *out = ((*in) >> 1) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 7) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 13) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 19) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 22) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 25) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 28) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 31);
  ++in;
  *out |= ((*in) % (1U << 2)) << (3 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 5) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 11) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 14) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 17) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 20) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 23) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 26) % (1U << 3);
  *out += base;
  out++;
  *out = ((*in) >> 29);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack4_32(uint32_t base, const uint32_t *in,
                                  uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 20) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 24) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 20) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 24) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 20) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 24) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 20) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 24) % (1U << 4);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack5_32(uint32_t base, const uint32_t *in,
                                  uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 5) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 15) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 20) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 25) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 3)) << (5 - 3);
  *out += base;
  out++;
  *out = ((*in) >> 3) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 13) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 18) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 23) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 1)) << (5 - 1);
  *out += base;
  out++;
  *out = ((*in) >> 1) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 11) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 21) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 26) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 31);
  ++in;
  *out |= ((*in) % (1U << 4)) << (5 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 9) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 14) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 19) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 24) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 29);
  ++in;
  *out |= ((*in) % (1U << 2)) << (5 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 7) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 17) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 22) % (1U << 5);
  *out += base;
  out++;
  *out = ((*in) >> 27);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack6_32(uint32_t base, const uint32_t *in,
                                  uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 18) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 24) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 4)) << (6 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 22) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 2)) << (6 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 14) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 20) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 18) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 24) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 4)) << (6 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 22) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 2)) << (6 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 14) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 20) % (1U << 6);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack7_32(uint32_t base, const uint32_t *in,
                                  uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 7) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 14) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 21) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 3)) << (7 - 3);
  *out += base;
  out++;
  *out = ((*in) >> 3) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 17) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 24) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 31);
  ++in;
  *out |= ((*in) % (1U << 6)) << (7 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 13) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 20) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 27);
  ++in;
  *out |= ((*in) % (1U << 2)) << (7 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 9) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 23) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 5)) << (7 - 5);
  *out += base;
  out++;
  *out = ((*in) >> 5) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 19) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 1)) << (7 - 1);
  *out += base;
  out++;
  *out = ((*in) >> 1) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 15) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 22) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 29);
  ++in;
  *out |= ((*in) % (1U << 4)) << (7 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 11) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 18) % (1U << 7);
  *out += base;
  out++;
  *out = ((*in) >> 25);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack8_32(uint32_t base, const uint32_t *in,
                                  uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 8);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack9_32(uint32_t base, const uint32_t *in,
                                  uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 9) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 18) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 27);
  ++in;
  *out |= ((*in) % (1U << 4)) << (9 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 13) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 22) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 31);
  ++in;
  *out |= ((*in) % (1U << 8)) << (9 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 17) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 3)) << (9 - 3);
  *out += base;
  out++;
  *out = ((*in) >> 3) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 21) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 7)) << (9 - 7);
  *out += base;
  out++;
  *out = ((*in) >> 7) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 25);
  ++in;
  *out |= ((*in) % (1U << 2)) << (9 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 11) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 20) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 29);
  ++in;
  *out |= ((*in) % (1U << 6)) << (9 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 15) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 1)) << (9 - 1);
  *out += base;
  out++;
  *out = ((*in) >> 1) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 19) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 5)) << (9 - 5);
  *out += base;
  out++;
  *out = ((*in) >> 5) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 14) % (1U << 9);
  *out += base;
  out++;
  *out = ((*in) >> 23);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack10_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 20) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 8)) << (10 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 18) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 6)) << (10 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 4)) << (10 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 14) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 2)) << (10 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 20) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 8)) << (10 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 18) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 6)) << (10 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 4)) << (10 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 14) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 2)) << (10 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 10);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack11_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 11) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 1)) << (11 - 1);
  *out += base;
  out++;
  *out = ((*in) >> 1) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 23);
  ++in;
  *out |= ((*in) % (1U << 2)) << (11 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 13) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 3)) << (11 - 3);
  *out += base;
  out++;
  *out = ((*in) >> 3) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 14) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 25);
  ++in;
  *out |= ((*in) % (1U << 4)) << (11 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 15) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 5)) << (11 - 5);
  *out += base;
  out++;
  *out = ((*in) >> 5) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 27);
  ++in;
  *out |= ((*in) % (1U << 6)) << (11 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 17) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 7)) << (11 - 7);
  *out += base;
  out++;
  *out = ((*in) >> 7) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 18) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 29);
  ++in;
  *out |= ((*in) % (1U << 8)) << (11 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 19) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 9)) << (11 - 9);
  *out += base;
  out++;
  *out = ((*in) >> 9) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 20) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 31);
  ++in;
  *out |= ((*in) % (1U << 10)) << (11 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 11);
  *out += base;
  out++;
  *out = ((*in) >> 21);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack12_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 4)) << (12 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 8)) << (12 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 4)) << (12 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 8)) << (12 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 4)) << (12 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 8)) << (12 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 4)) << (12 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 8)) << (12 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 12);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack13_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 13) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 7)) << (13 - 7);
  *out += base;
  out++;
  *out = ((*in) >> 7) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 1)) << (13 - 1);
  *out += base;
  out++;
  *out = ((*in) >> 1) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 14) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 27);
  ++in;
  *out |= ((*in) % (1U << 8)) << (13 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 21);
  ++in;
  *out |= ((*in) % (1U << 2)) << (13 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 15) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 9)) << (13 - 9);
  *out += base;
  out++;
  *out = ((*in) >> 9) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 3)) << (13 - 3);
  *out += base;
  out++;
  *out = ((*in) >> 3) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 29);
  ++in;
  *out |= ((*in) % (1U << 10)) << (13 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 23);
  ++in;
  *out |= ((*in) % (1U << 4)) << (13 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 17) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 11)) << (13 - 11);
  *out += base;
  out++;
  *out = ((*in) >> 11) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 5)) << (13 - 5);
  *out += base;
  out++;
  *out = ((*in) >> 5) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 18) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 31);
  ++in;
  *out |= ((*in) % (1U << 12)) << (13 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 25);
  ++in;
  *out |= ((*in) % (1U << 6)) << (13 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 13);
  *out += base;
  out++;
  *out = ((*in) >> 19);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack14_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 14) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 10)) << (14 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 6)) << (14 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 2)) << (14 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 12)) << (14 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 8)) << (14 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 4)) << (14 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 14) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 10)) << (14 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 6)) << (14 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 2)) << (14 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 12)) << (14 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 8)) << (14 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 4)) << (14 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 14);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack15_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 15) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 13)) << (15 - 13);
  *out += base;
  out++;
  *out = ((*in) >> 13) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 11)) << (15 - 11);
  *out += base;
  out++;
  *out = ((*in) >> 11) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 9)) << (15 - 9);
  *out += base;
  out++;
  *out = ((*in) >> 9) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 7)) << (15 - 7);
  *out += base;
  out++;
  *out = ((*in) >> 7) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 5)) << (15 - 5);
  *out += base;
  out++;
  *out = ((*in) >> 5) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 3)) << (15 - 3);
  *out += base;
  out++;
  *out = ((*in) >> 3) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 1)) << (15 - 1);
  *out += base;
  out++;
  *out = ((*in) >> 1) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 16) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 31);
  ++in;
  *out |= ((*in) % (1U << 14)) << (15 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 29);
  ++in;
  *out |= ((*in) % (1U << 12)) << (15 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 27);
  ++in;
  *out |= ((*in) % (1U << 10)) << (15 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 25);
  ++in;
  *out |= ((*in) % (1U << 8)) << (15 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 23);
  ++in;
  *out |= ((*in) % (1U << 6)) << (15 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 21);
  ++in;
  *out |= ((*in) % (1U << 4)) << (15 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 19);
  ++in;
  *out |= ((*in) % (1U << 2)) << (15 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 15);
  *out += base;
  out++;
  *out = ((*in) >> 17);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack16_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack17_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 17);
  *out += base;
  out++;
  *out = ((*in) >> 17);
  ++in;
  *out |= ((*in) % (1U << 2)) << (17 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 17);
  *out += base;
  out++;
  *out = ((*in) >> 19);
  ++in;
  *out |= ((*in) % (1U << 4)) << (17 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 17);
  *out += base;
  out++;
  *out = ((*in) >> 21);
  ++in;
  *out |= ((*in) % (1U << 6)) << (17 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 17);
  *out += base;
  out++;
  *out = ((*in) >> 23);
  ++in;
  *out |= ((*in) % (1U << 8)) << (17 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 17);
  *out += base;
  out++;
  *out = ((*in) >> 25);
  ++in;
  *out |= ((*in) % (1U << 10)) << (17 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 17);
  *out += base;
  out++;
  *out = ((*in) >> 27);
  ++in;
  *out |= ((*in) % (1U << 12)) << (17 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 17);
  *out += base;
  out++;
  *out = ((*in) >> 29);
  ++in;
  *out |= ((*in) % (1U << 14)) << (17 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14) % (1U << 17);
  *out += base;
  out++;
  *out = ((*in) >> 31);
  ++in;
  *out |= ((*in) % (1U << 16)) << (17 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 1)) << (17 - 1);
  *out += base;
  out++;
  *out = ((*in) >> 1) % (1U << 17);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 3)) << (17 - 3);
  *out += base;
  out++;
  *out = ((*in) >> 3) % (1U << 17);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 5)) << (17 - 5);
  *out += base;
  out++;
  *out = ((*in) >> 5) % (1U << 17);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 7)) << (17 - 7);
  *out += base;
  out++;
  *out = ((*in) >> 7) % (1U << 17);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 9)) << (17 - 9);
  *out += base;
  out++;
  *out = ((*in) >> 9) % (1U << 17);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 11)) << (17 - 11);
  *out += base;
  out++;
  *out = ((*in) >> 11) % (1U << 17);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 13)) << (17 - 13);
  *out += base;
  out++;
  *out = ((*in) >> 13) % (1U << 17);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 15)) << (17 - 15);
  *out += base;
  out++;
  *out = ((*in) >> 15);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack18_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 18);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 4)) << (18 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 18);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 8)) << (18 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 18);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 12)) << (18 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 18);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 16)) << (18 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 2)) << (18 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 18);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 6)) << (18 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 18);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 10)) << (18 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 18);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 14)) << (18 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 18);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 4)) << (18 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 18);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 8)) << (18 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 18);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 12)) << (18 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 18);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 16)) << (18 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 2)) << (18 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 18);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 6)) << (18 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 18);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 10)) << (18 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 18);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 14)) << (18 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack19_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 19);
  *out += base;
  out++;
  *out = ((*in) >> 19);
  ++in;
  *out |= ((*in) % (1U << 6)) << (19 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 19);
  *out += base;
  out++;
  *out = ((*in) >> 25);
  ++in;
  *out |= ((*in) % (1U << 12)) << (19 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12) % (1U << 19);
  *out += base;
  out++;
  *out = ((*in) >> 31);
  ++in;
  *out |= ((*in) % (1U << 18)) << (19 - 18);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 5)) << (19 - 5);
  *out += base;
  out++;
  *out = ((*in) >> 5) % (1U << 19);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 11)) << (19 - 11);
  *out += base;
  out++;
  *out = ((*in) >> 11) % (1U << 19);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 17)) << (19 - 17);
  *out += base;
  out++;
  *out = ((*in) >> 17);
  ++in;
  *out |= ((*in) % (1U << 4)) << (19 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 19);
  *out += base;
  out++;
  *out = ((*in) >> 23);
  ++in;
  *out |= ((*in) % (1U << 10)) << (19 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 19);
  *out += base;
  out++;
  *out = ((*in) >> 29);
  ++in;
  *out |= ((*in) % (1U << 16)) << (19 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 3)) << (19 - 3);
  *out += base;
  out++;
  *out = ((*in) >> 3) % (1U << 19);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 9)) << (19 - 9);
  *out += base;
  out++;
  *out = ((*in) >> 9) % (1U << 19);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 15)) << (19 - 15);
  *out += base;
  out++;
  *out = ((*in) >> 15);
  ++in;
  *out |= ((*in) % (1U << 2)) << (19 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 19);
  *out += base;
  out++;
  *out = ((*in) >> 21);
  ++in;
  *out |= ((*in) % (1U << 8)) << (19 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 19);
  *out += base;
  out++;
  *out = ((*in) >> 27);
  ++in;
  *out |= ((*in) % (1U << 14)) << (19 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14);
  ++in;
  *out |= ((*in) % (1U << 1)) << (19 - 1);
  *out += base;
  out++;
  *out = ((*in) >> 1) % (1U << 19);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 7)) << (19 - 7);
  *out += base;
  out++;
  *out = ((*in) >> 7) % (1U << 19);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 13)) << (19 - 13);
  *out += base;
  out++;
  *out = ((*in) >> 13);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack20_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 8)) << (20 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 20);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 16)) << (20 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 4)) << (20 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 20);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 12)) << (20 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 8)) << (20 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 20);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 16)) << (20 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 4)) << (20 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 20);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 12)) << (20 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 8)) << (20 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 20);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 16)) << (20 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 4)) << (20 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 20);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 12)) << (20 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 8)) << (20 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 20);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 16)) << (20 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 4)) << (20 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 20);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 12)) << (20 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack21_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 21);
  *out += base;
  out++;
  *out = ((*in) >> 21);
  ++in;
  *out |= ((*in) % (1U << 10)) << (21 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10) % (1U << 21);
  *out += base;
  out++;
  *out = ((*in) >> 31);
  ++in;
  *out |= ((*in) % (1U << 20)) << (21 - 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 9)) << (21 - 9);
  *out += base;
  out++;
  *out = ((*in) >> 9) % (1U << 21);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 19)) << (21 - 19);
  *out += base;
  out++;
  *out = ((*in) >> 19);
  ++in;
  *out |= ((*in) % (1U << 8)) << (21 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 21);
  *out += base;
  out++;
  *out = ((*in) >> 29);
  ++in;
  *out |= ((*in) % (1U << 18)) << (21 - 18);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 7)) << (21 - 7);
  *out += base;
  out++;
  *out = ((*in) >> 7) % (1U << 21);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 17)) << (21 - 17);
  *out += base;
  out++;
  *out = ((*in) >> 17);
  ++in;
  *out |= ((*in) % (1U << 6)) << (21 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 21);
  *out += base;
  out++;
  *out = ((*in) >> 27);
  ++in;
  *out |= ((*in) % (1U << 16)) << (21 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 5)) << (21 - 5);
  *out += base;
  out++;
  *out = ((*in) >> 5) % (1U << 21);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 15)) << (21 - 15);
  *out += base;
  out++;
  *out = ((*in) >> 15);
  ++in;
  *out |= ((*in) % (1U << 4)) << (21 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 21);
  *out += base;
  out++;
  *out = ((*in) >> 25);
  ++in;
  *out |= ((*in) % (1U << 14)) << (21 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14);
  ++in;
  *out |= ((*in) % (1U << 3)) << (21 - 3);
  *out += base;
  out++;
  *out = ((*in) >> 3) % (1U << 21);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 13)) << (21 - 13);
  *out += base;
  out++;
  *out = ((*in) >> 13);
  ++in;
  *out |= ((*in) % (1U << 2)) << (21 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 21);
  *out += base;
  out++;
  *out = ((*in) >> 23);
  ++in;
  *out |= ((*in) % (1U << 12)) << (21 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out |= ((*in) % (1U << 1)) << (21 - 1);
  *out += base;
  out++;
  *out = ((*in) >> 1) % (1U << 21);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 11)) << (21 - 11);
  *out += base;
  out++;
  *out = ((*in) >> 11);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack22_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 22);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 12)) << (22 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out |= ((*in) % (1U << 2)) << (22 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 22);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 14)) << (22 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14);
  ++in;
  *out |= ((*in) % (1U << 4)) << (22 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 22);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 16)) << (22 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 6)) << (22 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 22);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 18)) << (22 - 18);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 8)) << (22 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 22);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 20)) << (22 - 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 10)) << (22 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 22);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 12)) << (22 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out |= ((*in) % (1U << 2)) << (22 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 22);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 14)) << (22 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14);
  ++in;
  *out |= ((*in) % (1U << 4)) << (22 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 22);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 16)) << (22 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 6)) << (22 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 22);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 18)) << (22 - 18);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 8)) << (22 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 22);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 20)) << (22 - 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 10)) << (22 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack23_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 23);
  *out += base;
  out++;
  *out = ((*in) >> 23);
  ++in;
  *out |= ((*in) % (1U << 14)) << (23 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14);
  ++in;
  *out |= ((*in) % (1U << 5)) << (23 - 5);
  *out += base;
  out++;
  *out = ((*in) >> 5) % (1U << 23);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 19)) << (23 - 19);
  *out += base;
  out++;
  *out = ((*in) >> 19);
  ++in;
  *out |= ((*in) % (1U << 10)) << (23 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10);
  ++in;
  *out |= ((*in) % (1U << 1)) << (23 - 1);
  *out += base;
  out++;
  *out = ((*in) >> 1) % (1U << 23);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 15)) << (23 - 15);
  *out += base;
  out++;
  *out = ((*in) >> 15);
  ++in;
  *out |= ((*in) % (1U << 6)) << (23 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 23);
  *out += base;
  out++;
  *out = ((*in) >> 29);
  ++in;
  *out |= ((*in) % (1U << 20)) << (23 - 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 11)) << (23 - 11);
  *out += base;
  out++;
  *out = ((*in) >> 11);
  ++in;
  *out |= ((*in) % (1U << 2)) << (23 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 23);
  *out += base;
  out++;
  *out = ((*in) >> 25);
  ++in;
  *out |= ((*in) % (1U << 16)) << (23 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 7)) << (23 - 7);
  *out += base;
  out++;
  *out = ((*in) >> 7) % (1U << 23);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 21)) << (23 - 21);
  *out += base;
  out++;
  *out = ((*in) >> 21);
  ++in;
  *out |= ((*in) % (1U << 12)) << (23 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out |= ((*in) % (1U << 3)) << (23 - 3);
  *out += base;
  out++;
  *out = ((*in) >> 3) % (1U << 23);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 17)) << (23 - 17);
  *out += base;
  out++;
  *out = ((*in) >> 17);
  ++in;
  *out |= ((*in) % (1U << 8)) << (23 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8) % (1U << 23);
  *out += base;
  out++;
  *out = ((*in) >> 31);
  ++in;
  *out |= ((*in) % (1U << 22)) << (23 - 22);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 13)) << (23 - 13);
  *out += base;
  out++;
  *out = ((*in) >> 13);
  ++in;
  *out |= ((*in) % (1U << 4)) << (23 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 23);
  *out += base;
  out++;
  *out = ((*in) >> 27);
  ++in;
  *out |= ((*in) % (1U << 18)) << (23 - 18);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 9)) << (23 - 9);
  *out += base;
  out++;
  *out = ((*in) >> 9);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack24_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 16)) << (24 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 8)) << (24 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 16)) << (24 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 8)) << (24 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 16)) << (24 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 8)) << (24 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 16)) << (24 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 8)) << (24 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 16)) << (24 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 8)) << (24 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 16)) << (24 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 8)) << (24 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 16)) << (24 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 8)) << (24 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 16)) << (24 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 8)) << (24 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack25_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 25);
  *out += base;
  out++;
  *out = ((*in) >> 25);
  ++in;
  *out |= ((*in) % (1U << 18)) << (25 - 18);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 11)) << (25 - 11);
  *out += base;
  out++;
  *out = ((*in) >> 11);
  ++in;
  *out |= ((*in) % (1U << 4)) << (25 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 25);
  *out += base;
  out++;
  *out = ((*in) >> 29);
  ++in;
  *out |= ((*in) % (1U << 22)) << (25 - 22);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 15)) << (25 - 15);
  *out += base;
  out++;
  *out = ((*in) >> 15);
  ++in;
  *out |= ((*in) % (1U << 8)) << (25 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out |= ((*in) % (1U << 1)) << (25 - 1);
  *out += base;
  out++;
  *out = ((*in) >> 1) % (1U << 25);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 19)) << (25 - 19);
  *out += base;
  out++;
  *out = ((*in) >> 19);
  ++in;
  *out |= ((*in) % (1U << 12)) << (25 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out |= ((*in) % (1U << 5)) << (25 - 5);
  *out += base;
  out++;
  *out = ((*in) >> 5) % (1U << 25);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 23)) << (25 - 23);
  *out += base;
  out++;
  *out = ((*in) >> 23);
  ++in;
  *out |= ((*in) % (1U << 16)) << (25 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 9)) << (25 - 9);
  *out += base;
  out++;
  *out = ((*in) >> 9);
  ++in;
  *out |= ((*in) % (1U << 2)) << (25 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 25);
  *out += base;
  out++;
  *out = ((*in) >> 27);
  ++in;
  *out |= ((*in) % (1U << 20)) << (25 - 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 13)) << (25 - 13);
  *out += base;
  out++;
  *out = ((*in) >> 13);
  ++in;
  *out |= ((*in) % (1U << 6)) << (25 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6) % (1U << 25);
  *out += base;
  out++;
  *out = ((*in) >> 31);
  ++in;
  *out |= ((*in) % (1U << 24)) << (25 - 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 17)) << (25 - 17);
  *out += base;
  out++;
  *out = ((*in) >> 17);
  ++in;
  *out |= ((*in) % (1U << 10)) << (25 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10);
  ++in;
  *out |= ((*in) % (1U << 3)) << (25 - 3);
  *out += base;
  out++;
  *out = ((*in) >> 3) % (1U << 25);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 21)) << (25 - 21);
  *out += base;
  out++;
  *out = ((*in) >> 21);
  ++in;
  *out |= ((*in) % (1U << 14)) << (25 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14);
  ++in;
  *out |= ((*in) % (1U << 7)) << (25 - 7);
  *out += base;
  out++;
  *out = ((*in) >> 7);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack26_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 26);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 20)) << (26 - 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 14)) << (26 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14);
  ++in;
  *out |= ((*in) % (1U << 8)) << (26 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out |= ((*in) % (1U << 2)) << (26 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 26);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 22)) << (26 - 22);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 16)) << (26 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 10)) << (26 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10);
  ++in;
  *out |= ((*in) % (1U << 4)) << (26 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 26);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 24)) << (26 - 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 18)) << (26 - 18);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 12)) << (26 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out |= ((*in) % (1U << 6)) << (26 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 26);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 20)) << (26 - 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 14)) << (26 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14);
  ++in;
  *out |= ((*in) % (1U << 8)) << (26 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out |= ((*in) % (1U << 2)) << (26 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 26);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 22)) << (26 - 22);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 16)) << (26 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 10)) << (26 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10);
  ++in;
  *out |= ((*in) % (1U << 4)) << (26 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 26);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 24)) << (26 - 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 18)) << (26 - 18);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 12)) << (26 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out |= ((*in) % (1U << 6)) << (26 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack27_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 27);
  *out += base;
  out++;
  *out = ((*in) >> 27);
  ++in;
  *out |= ((*in) % (1U << 22)) << (27 - 22);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 17)) << (27 - 17);
  *out += base;
  out++;
  *out = ((*in) >> 17);
  ++in;
  *out |= ((*in) % (1U << 12)) << (27 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out |= ((*in) % (1U << 7)) << (27 - 7);
  *out += base;
  out++;
  *out = ((*in) >> 7);
  ++in;
  *out |= ((*in) % (1U << 2)) << (27 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 27);
  *out += base;
  out++;
  *out = ((*in) >> 29);
  ++in;
  *out |= ((*in) % (1U << 24)) << (27 - 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 19)) << (27 - 19);
  *out += base;
  out++;
  *out = ((*in) >> 19);
  ++in;
  *out |= ((*in) % (1U << 14)) << (27 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14);
  ++in;
  *out |= ((*in) % (1U << 9)) << (27 - 9);
  *out += base;
  out++;
  *out = ((*in) >> 9);
  ++in;
  *out |= ((*in) % (1U << 4)) << (27 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4) % (1U << 27);
  *out += base;
  out++;
  *out = ((*in) >> 31);
  ++in;
  *out |= ((*in) % (1U << 26)) << (27 - 26);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 21)) << (27 - 21);
  *out += base;
  out++;
  *out = ((*in) >> 21);
  ++in;
  *out |= ((*in) % (1U << 16)) << (27 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 11)) << (27 - 11);
  *out += base;
  out++;
  *out = ((*in) >> 11);
  ++in;
  *out |= ((*in) % (1U << 6)) << (27 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6);
  ++in;
  *out |= ((*in) % (1U << 1)) << (27 - 1);
  *out += base;
  out++;
  *out = ((*in) >> 1) % (1U << 27);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 23)) << (27 - 23);
  *out += base;
  out++;
  *out = ((*in) >> 23);
  ++in;
  *out |= ((*in) % (1U << 18)) << (27 - 18);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 13)) << (27 - 13);
  *out += base;
  out++;
  *out = ((*in) >> 13);
  ++in;
  *out |= ((*in) % (1U << 8)) << (27 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out |= ((*in) % (1U << 3)) << (27 - 3);
  *out += base;
  out++;
  *out = ((*in) >> 3) % (1U << 27);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 25)) << (27 - 25);
  *out += base;
  out++;
  *out = ((*in) >> 25);
  ++in;
  *out |= ((*in) % (1U << 20)) << (27 - 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 15)) << (27 - 15);
  *out += base;
  out++;
  *out = ((*in) >> 15);
  ++in;
  *out |= ((*in) % (1U << 10)) << (27 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10);
  ++in;
  *out |= ((*in) % (1U << 5)) << (27 - 5);
  *out += base;
  out++;
  *out = ((*in) >> 5);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack28_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 28);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 24)) << (28 - 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 20)) << (28 - 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 16)) << (28 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 12)) << (28 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out |= ((*in) % (1U << 8)) << (28 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out |= ((*in) % (1U << 4)) << (28 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 28);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 24)) << (28 - 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 20)) << (28 - 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 16)) << (28 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 12)) << (28 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out |= ((*in) % (1U << 8)) << (28 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out |= ((*in) % (1U << 4)) << (28 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 28);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 24)) << (28 - 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 20)) << (28 - 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 16)) << (28 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 12)) << (28 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out |= ((*in) % (1U << 8)) << (28 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out |= ((*in) % (1U << 4)) << (28 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 28);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 24)) << (28 - 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 20)) << (28 - 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 16)) << (28 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 12)) << (28 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out |= ((*in) % (1U << 8)) << (28 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out |= ((*in) % (1U << 4)) << (28 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack29_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 29);
  *out += base;
  out++;
  *out = ((*in) >> 29);
  ++in;
  *out |= ((*in) % (1U << 26)) << (29 - 26);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 23)) << (29 - 23);
  *out += base;
  out++;
  *out = ((*in) >> 23);
  ++in;
  *out |= ((*in) % (1U << 20)) << (29 - 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 17)) << (29 - 17);
  *out += base;
  out++;
  *out = ((*in) >> 17);
  ++in;
  *out |= ((*in) % (1U << 14)) << (29 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14);
  ++in;
  *out |= ((*in) % (1U << 11)) << (29 - 11);
  *out += base;
  out++;
  *out = ((*in) >> 11);
  ++in;
  *out |= ((*in) % (1U << 8)) << (29 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out |= ((*in) % (1U << 5)) << (29 - 5);
  *out += base;
  out++;
  *out = ((*in) >> 5);
  ++in;
  *out |= ((*in) % (1U << 2)) << (29 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2) % (1U << 29);
  *out += base;
  out++;
  *out = ((*in) >> 31);
  ++in;
  *out |= ((*in) % (1U << 28)) << (29 - 28);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 25)) << (29 - 25);
  *out += base;
  out++;
  *out = ((*in) >> 25);
  ++in;
  *out |= ((*in) % (1U << 22)) << (29 - 22);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 19)) << (29 - 19);
  *out += base;
  out++;
  *out = ((*in) >> 19);
  ++in;
  *out |= ((*in) % (1U << 16)) << (29 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 13)) << (29 - 13);
  *out += base;
  out++;
  *out = ((*in) >> 13);
  ++in;
  *out |= ((*in) % (1U << 10)) << (29 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10);
  ++in;
  *out |= ((*in) % (1U << 7)) << (29 - 7);
  *out += base;
  out++;
  *out = ((*in) >> 7);
  ++in;
  *out |= ((*in) % (1U << 4)) << (29 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4);
  ++in;
  *out |= ((*in) % (1U << 1)) << (29 - 1);
  *out += base;
  out++;
  *out = ((*in) >> 1) % (1U << 29);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 27)) << (29 - 27);
  *out += base;
  out++;
  *out = ((*in) >> 27);
  ++in;
  *out |= ((*in) % (1U << 24)) << (29 - 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 21)) << (29 - 21);
  *out += base;
  out++;
  *out = ((*in) >> 21);
  ++in;
  *out |= ((*in) % (1U << 18)) << (29 - 18);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 15)) << (29 - 15);
  *out += base;
  out++;
  *out = ((*in) >> 15);
  ++in;
  *out |= ((*in) % (1U << 12)) << (29 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out |= ((*in) % (1U << 9)) << (29 - 9);
  *out += base;
  out++;
  *out = ((*in) >> 9);
  ++in;
  *out |= ((*in) % (1U << 6)) << (29 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6);
  ++in;
  *out |= ((*in) % (1U << 3)) << (29 - 3);
  *out += base;
  out++;
  *out = ((*in) >> 3);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack30_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 30);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 28)) << (30 - 28);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 26)) << (30 - 26);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 24)) << (30 - 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 22)) << (30 - 22);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 20)) << (30 - 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 18)) << (30 - 18);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 16)) << (30 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 14)) << (30 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14);
  ++in;
  *out |= ((*in) % (1U << 12)) << (30 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out |= ((*in) % (1U << 10)) << (30 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10);
  ++in;
  *out |= ((*in) % (1U << 8)) << (30 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out |= ((*in) % (1U << 6)) << (30 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6);
  ++in;
  *out |= ((*in) % (1U << 4)) << (30 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4);
  ++in;
  *out |= ((*in) % (1U << 2)) << (30 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2);
  ++in;
  *out += base;
  out++;
  *out = ((*in) >> 0) % (1U << 30);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 28)) << (30 - 28);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 26)) << (30 - 26);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 24)) << (30 - 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 22)) << (30 - 22);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 20)) << (30 - 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 18)) << (30 - 18);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 16)) << (30 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 14)) << (30 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14);
  ++in;
  *out |= ((*in) % (1U << 12)) << (30 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out |= ((*in) % (1U << 10)) << (30 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10);
  ++in;
  *out |= ((*in) % (1U << 8)) << (30 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out |= ((*in) % (1U << 6)) << (30 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6);
  ++in;
  *out |= ((*in) % (1U << 4)) << (30 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4);
  ++in;
  *out |= ((*in) % (1U << 2)) << (30 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack31_32(uint32_t base, const uint32_t *in,
                                   uint32_t *out) {

  *out = ((*in) >> 0) % (1U << 31);
  *out += base;
  out++;
  *out = ((*in) >> 31);
  ++in;
  *out |= ((*in) % (1U << 30)) << (31 - 30);
  *out += base;
  out++;
  *out = ((*in) >> 30);
  ++in;
  *out |= ((*in) % (1U << 29)) << (31 - 29);
  *out += base;
  out++;
  *out = ((*in) >> 29);
  ++in;
  *out |= ((*in) % (1U << 28)) << (31 - 28);
  *out += base;
  out++;
  *out = ((*in) >> 28);
  ++in;
  *out |= ((*in) % (1U << 27)) << (31 - 27);
  *out += base;
  out++;
  *out = ((*in) >> 27);
  ++in;
  *out |= ((*in) % (1U << 26)) << (31 - 26);
  *out += base;
  out++;
  *out = ((*in) >> 26);
  ++in;
  *out |= ((*in) % (1U << 25)) << (31 - 25);
  *out += base;
  out++;
  *out = ((*in) >> 25);
  ++in;
  *out |= ((*in) % (1U << 24)) << (31 - 24);
  *out += base;
  out++;
  *out = ((*in) >> 24);
  ++in;
  *out |= ((*in) % (1U << 23)) << (31 - 23);
  *out += base;
  out++;
  *out = ((*in) >> 23);
  ++in;
  *out |= ((*in) % (1U << 22)) << (31 - 22);
  *out += base;
  out++;
  *out = ((*in) >> 22);
  ++in;
  *out |= ((*in) % (1U << 21)) << (31 - 21);
  *out += base;
  out++;
  *out = ((*in) >> 21);
  ++in;
  *out |= ((*in) % (1U << 20)) << (31 - 20);
  *out += base;
  out++;
  *out = ((*in) >> 20);
  ++in;
  *out |= ((*in) % (1U << 19)) << (31 - 19);
  *out += base;
  out++;
  *out = ((*in) >> 19);
  ++in;
  *out |= ((*in) % (1U << 18)) << (31 - 18);
  *out += base;
  out++;
  *out = ((*in) >> 18);
  ++in;
  *out |= ((*in) % (1U << 17)) << (31 - 17);
  *out += base;
  out++;
  *out = ((*in) >> 17);
  ++in;
  *out |= ((*in) % (1U << 16)) << (31 - 16);
  *out += base;
  out++;
  *out = ((*in) >> 16);
  ++in;
  *out |= ((*in) % (1U << 15)) << (31 - 15);
  *out += base;
  out++;
  *out = ((*in) >> 15);
  ++in;
  *out |= ((*in) % (1U << 14)) << (31 - 14);
  *out += base;
  out++;
  *out = ((*in) >> 14);
  ++in;
  *out |= ((*in) % (1U << 13)) << (31 - 13);
  *out += base;
  out++;
  *out = ((*in) >> 13);
  ++in;
  *out |= ((*in) % (1U << 12)) << (31 - 12);
  *out += base;
  out++;
  *out = ((*in) >> 12);
  ++in;
  *out |= ((*in) % (1U << 11)) << (31 - 11);
  *out += base;
  out++;
  *out = ((*in) >> 11);
  ++in;
  *out |= ((*in) % (1U << 10)) << (31 - 10);
  *out += base;
  out++;
  *out = ((*in) >> 10);
  ++in;
  *out |= ((*in) % (1U << 9)) << (31 - 9);
  *out += base;
  out++;
  *out = ((*in) >> 9);
  ++in;
  *out |= ((*in) % (1U << 8)) << (31 - 8);
  *out += base;
  out++;
  *out = ((*in) >> 8);
  ++in;
  *out |= ((*in) % (1U << 7)) << (31 - 7);
  *out += base;
  out++;
  *out = ((*in) >> 7);
  ++in;
  *out |= ((*in) % (1U << 6)) << (31 - 6);
  *out += base;
  out++;
  *out = ((*in) >> 6);
  ++in;
  *out |= ((*in) % (1U << 5)) << (31 - 5);
  *out += base;
  out++;
  *out = ((*in) >> 5);
  ++in;
  *out |= ((*in) % (1U << 4)) << (31 - 4);
  *out += base;
  out++;
  *out = ((*in) >> 4);
  ++in;
  *out |= ((*in) % (1U << 3)) << (31 - 3);
  *out += base;
  out++;
  *out = ((*in) >> 3);
  ++in;
  *out |= ((*in) % (1U << 2)) << (31 - 2);
  *out += base;
  out++;
  *out = ((*in) >> 2);
  ++in;
  *out |= ((*in) % (1U << 1)) << (31 - 1);
  *out += base;
  out++;
  *out = ((*in) >> 1);
  ++in;
  *out += base;
  out++;

  return in;
}

static const uint32_t *unpack32_32(uint32_t, const uint32_t *in,
                                   uint32_t *out) {
  memcpy(out, in, 32 * sizeof(uint32_t));
  return in + 32;
}

typedef const uint32_t *(*unpackfnc)(uint32_t, const uint32_t *, uint32_t *);

typedef uint32_t *(*packfnc)(uint32_t, const uint32_t *, uint32_t *);

static uint32_t *nullpacker(uint32_t, const uint32_t *, uint32_t *out) {
  return out;
}

static const uint32_t *nullunpacker(uint32_t base, const uint32_t *in,
                                    uint32_t *out) {
  for (int k = 0; k < 32; ++k) {
    out[k] = base;
  }
  return in;
}

static unpackfnc unpack32[33] = {
    nullunpacker, unpack1_32,  unpack2_32,  unpack3_32,  unpack4_32,
    unpack5_32,   unpack6_32,  unpack7_32,  unpack8_32,  unpack9_32,
    unpack10_32,  unpack11_32, unpack12_32, unpack13_32, unpack14_32,
    unpack15_32,  unpack16_32, unpack17_32, unpack18_32, unpack19_32,
    unpack20_32,  unpack21_32, unpack22_32, unpack23_32, unpack24_32,
    unpack25_32,  unpack26_32, unpack27_32, unpack28_32, unpack29_32,
    unpack30_32,  unpack31_32, unpack32_32};

static packfnc pack32[33] = {
    nullpacker, pack1_32,  pack2_32,  pack3_32,  pack4_32,  pack5_32,
    pack6_32,   pack7_32,  pack8_32,  pack9_32,  pack10_32, pack11_32,
    pack12_32,  pack13_32, pack14_32, pack15_32, pack16_32, pack17_32,
    pack18_32,  pack19_32, pack20_32, pack21_32, pack22_32, pack23_32,
    pack24_32,  pack25_32, pack26_32, pack27_32, pack28_32, pack29_32,
    pack30_32,  pack31_32, pack32_32};

static uint32_t bits(const uint32_t v) {
  return v == 0 ? 0 : 32 - __builtin_clz(v);
}

uint32_t *SIMDCompressionLib::FrameOfReference::compress_length(
    const uint32_t *in, uint32_t length, uint32_t *out) {
  if (length == 0)
    return out;
  uint32_t m = in[0];
  uint32_t M = in[0];
  for (uint32_t i = 1; i < length; ++i) {
    if (in[i] > M)
      M = in[i];
    if (in[i] < m)
      m = in[i];
  }
  int b = bits(static_cast<uint32_t>(M - m));

  out[0] = m;
  ++out;
  out[0] = M;
  ++out;
  uint32_t k = 0;
  for (; k + 32 <= length; k += 32, in += 32) {
    out = pack32[b](m, in, out);
  }
  // we could pack the rest, but we don't  bother
  for (; k < length; ++k, in++, out++) {
    out[0] = in[0];
  }
  return out;
}

const uint32_t *SIMDCompressionLib::FrameOfReference::uncompress_length(
    const uint32_t *in, uint32_t *out, uint32_t nvalue) {
  if (nvalue == 0)
    return out;
  uint32_t m = in[0];
  ++in;
  uint32_t M = in[0];
  ++in;
  int b = bits(static_cast<uint32_t>(M - m));
  for (uint32_t k = 0; k < nvalue / 32; ++k) {
    unpack32[b](m, in + b * k, out + 32 * k);
  }
  out = out + nvalue / 32 * 32;
  in = in + nvalue / 32 * b;
  // we could pack the rest, but we don't  bother
  for (uint32_t k = nvalue / 32 * 32; k < nvalue; ++k, in++, out++) {
    out[0] = in[0];
  }
  return in;
}

size_t SIMDCompressionLib::FrameOfReference::append(
    uint8_t *inbyte, const size_t currentcompressedsizeinbytes,
    uint32_t value) {
  if (currentcompressedsizeinbytes == 0) {
    size_t nvalue = 16; // 16 is arbitrary
    encodeArray(&value, 1, (uint32_t *)inbyte, nvalue);
    return nvalue * sizeof(uint32_t);
  }
  uint32_t *in = (uint32_t *)inbyte;

  uint32_t nvalue = *in;
  in[0] += 1; // incrementing!
  in++;

  uint32_t m = in[0];
  uint32_t M = in[1];

  int b = bits(static_cast<uint32_t>(M - m));
  if ((value < m) || (value > M)) { // should be unlikely
    uint32_t newm = m;
    uint32_t newM = M;

    if (value < m) {
      newm = value;
    }
    if (value > M) {
      newM = value;
    }
    int newb = bits(static_cast<uint32_t>(newM - newm));
    if ((newb != b) || (value < m)) { // unlucky path
      vector<uint32_t> buffer(nvalue + 1);
      uncompress_length(in, buffer.data(), nvalue);
      buffer[nvalue] = value;
      uint32_t *newin = compress_length(buffer.data(), nvalue + 1, in);
      return (newin - in + 1) * sizeof(uint32_t);
    } else { // only max changed
      in[1] = newM;
      M = newM; // probably unnecessary
    }
  }
  // add one
  in += 2;
  uint32_t headersize = 3;
  uint32_t index = nvalue;
  if (b == 32) {
    in[index] = value;
    return (index + 1 + headersize) * sizeof(uint32_t);
  }
  uint32_t oldpackedlength = nvalue / 32 * 32;
  uint32_t newpackedlength = (nvalue + 1) / 32 * 32;
  uint32_t packedsizeinwords = oldpackedlength * b / 32;
  in[packedsizeinwords + index - oldpackedlength] = value;
  if (oldpackedlength == newpackedlength) {
    return (headersize + (packedsizeinwords + index - oldpackedlength)) *
           sizeof(uint32_t);
  }
  // we now have exactly 32 to pack
  uint32_t buffer[32];
  memcpy(buffer, in + packedsizeinwords,
         32 * sizeof(uint32_t)); // copy to a safe buffer
  uint32_t *out = pack32[b](m, buffer, in + packedsizeinwords);
  return (out - in + headersize) * sizeof(uint32_t);
}

struct selectmetadata {
  uint32_t m;
  const uint32_t *in;
  uint32_t b;
  uint32_t length;
};

static uint32_t fastselect(selectmetadata *s, size_t index) {
  if (s->b == 32) {
    return s->in[index];
  }
  uint32_t packedlength = s->length / 32 * 32;
  if (index > packedlength) {
    uint32_t packedsizeinwords = packedlength * s->b / 32;
    return s->in[packedsizeinwords + index - packedlength];
  }
  const int bitoffset = static_cast<uint32_t>(index) * s->b; /* how many bits */
  const int firstword = bitoffset / 32;
  const int secondword = (bitoffset + s->b - 1) / 32;
  const uint32_t firstpart = s->in[firstword] >> (bitoffset % 32);
  const uint32_t mask = (1 << s->b) - 1;
  if (firstword == secondword) {
    /* easy common case*/
    return s->m + (firstpart & mask);
  } else {
    /* harder case where we need to combine two words */
    const uint32_t secondpart = s->in[firstword + 1];
    const int usablebitsinfirstword = 32 - (bitoffset % 32);
    return s->m + ((firstpart | (secondpart << usablebitsinfirstword)) & mask);
  }
}

// Performs a lower bound find in the encoded array.
// Returns the index
size_t findlowerbound(const uint32_t *in, uint32_t key, uint32_t *presult) {
  selectmetadata s;
  s.length = *in;
  in++;
  s.m = *in;
  ++in;
  uint32_t M = *in;
  ++in;
  s.b = bits(M - s.m);
  s.in = in;

  int count = s.length;
  int begin = 0;
  uint32_t val;
  while (count > 0) {
    int step = count / 2;
    val = fastselect(&s, begin + step);
    if (val < key) {
      begin += step + 1;
      count -= step + 1;
    } else
      count = step;
  }
  *presult = fastselect(&s, begin);
  return begin;
}

/***
 * BEGIN OF linear search
 */

static int search1_32(uint32_t base, const uint32_t *in, uint32_t target,
                      uint32_t *decoded) {

  *decoded = ((*in) >> 0) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 1) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 2) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 3) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 4) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 5) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 6) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 7) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 8) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 9) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 10) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 11) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 12) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 13) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 14) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 15) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 16) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 17) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 18) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 19) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 20) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 21) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 22) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 23) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 24) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 25) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 26) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 27) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 28) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 29) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 30) & 1;
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 31);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search2_32(uint32_t base, const uint32_t *in, uint32_t target,
                      uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 2) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 4) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 6) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 8) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 10) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 12) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 14) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 16) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 18) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 20) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 22) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 24) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 26) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 28) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 0) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 2) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 4) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 6) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 8) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 10) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 12) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 14) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 16) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 18) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 20) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 22) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 24) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 26) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 28) % (1U << 2);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search3_32(uint32_t base, const uint32_t *in, uint32_t target,
                      uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 3) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 6) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 9) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 12) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 15) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 18) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 21) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 24) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 27) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 1)) << (3 - 1);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 1) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 4) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 7) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 10) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 13) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 16) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 19) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 22) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 25) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 28) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 31);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (3 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 2) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 5) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 8) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 11) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 14) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 17) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 20) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 23) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 26) % (1U << 3);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 29);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search4_32(uint32_t base, const uint32_t *in, uint32_t target,
                      uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 4) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 8) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 12) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 16) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 20) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 24) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 0) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 4) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 8) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 12) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 16) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 20) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 24) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 0) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 4) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 8) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 12) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 16) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 20) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 24) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 0) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 4) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 8) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 12) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 16) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 20) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 24) % (1U << 4);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search5_32(uint32_t base, const uint32_t *in, uint32_t target,
                      uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 5) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 10) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 15) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 20) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 25) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 3)) << (5 - 3);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 3) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 8) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 13) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 18) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 23) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 1)) << (5 - 1);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 1) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 6) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 11) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 16) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 21) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 26) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 31);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (5 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 4) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 9) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 14) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 19) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 24) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 29);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (5 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 2) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 7) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 12) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 17) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 22) % (1U << 5);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 27);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search6_32(uint32_t base, const uint32_t *in, uint32_t target,
                      uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 6) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 12) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 18) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 24) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (6 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 4) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 10) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 16) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 22) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (6 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 2) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 8) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 14) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 20) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 0) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 6) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 12) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 18) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 24) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (6 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 4) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 10) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 16) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 22) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (6 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 2) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 8) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 14) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 20) % (1U << 6);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search7_32(uint32_t base, const uint32_t *in, uint32_t target,
                      uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 7) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 14) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 21) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 3)) << (7 - 3);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 3) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 10) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 17) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 24) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 31);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (7 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 6) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 13) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 20) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 27);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (7 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 2) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 9) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 16) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 23) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 5)) << (7 - 5);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 5) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 12) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 19) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 1)) << (7 - 1);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 1) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 8) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 15) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 22) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 29);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (7 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 4) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 11) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 18) % (1U << 7);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 25);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search8_32(uint32_t base, const uint32_t *in, uint32_t target,
                      uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 8) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 16) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 0) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 8) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 16) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 0) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 8) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 16) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 0) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 8) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 16) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 0) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 8) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 16) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 0) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 8) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 16) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 0) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 8) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 16) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 0) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 8) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 16) % (1U << 8);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search9_32(uint32_t base, const uint32_t *in, uint32_t target,
                      uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 9) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 18) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 27);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (9 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 4) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 13) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 22) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 31);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (9 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 8) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 17) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 3)) << (9 - 3);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 3) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 12) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 21) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 7)) << (9 - 7);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 7) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 16) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 25);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (9 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 2) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 11) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 20) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 29);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (9 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 6) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 15) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 1)) << (9 - 1);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 1) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 10) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 19) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 5)) << (9 - 5);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 5) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 14) % (1U << 9);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 23);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search10_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 10) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 20) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (10 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 8) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 18) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (10 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 6) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 16) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (10 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 4) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 14) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (10 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 2) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 12) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 0) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 10) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 20) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (10 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 8) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 18) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (10 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 6) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 16) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (10 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 4) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 14) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (10 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 2) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 12) % (1U << 10);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search11_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 11) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 1)) << (11 - 1);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 1) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 12) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 23);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (11 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 2) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 13) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 3)) << (11 - 3);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 3) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 14) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 25);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (11 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 4) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 15) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 5)) << (11 - 5);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 5) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 16) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 27);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (11 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 6) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 17) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 7)) << (11 - 7);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 7) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 18) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 29);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (11 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 8) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 19) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 9)) << (11 - 9);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 9) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 20) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 31);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (11 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 10) % (1U << 11);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 21);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search12_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 12) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (12 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 4) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 16) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (12 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 8) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 0) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 12) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (12 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 4) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 16) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (12 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 8) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 0) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 12) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (12 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 4) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 16) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (12 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 8) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 0) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 12) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (12 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 4) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 16) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (12 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 8) % (1U << 12);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search13_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 13) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 7)) << (13 - 7);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 7) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 1)) << (13 - 1);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 1) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 14) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 27);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (13 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 8) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 21);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (13 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 2) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 15) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 9)) << (13 - 9);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 9) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 3)) << (13 - 3);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 3) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 16) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 29);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (13 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 10) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 23);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (13 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 4) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 17) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 11)) << (13 - 11);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 11) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 5)) << (13 - 5);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 5) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 18) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 31);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (13 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 12) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 25);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (13 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 6) % (1U << 13);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 19);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search14_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 14) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (14 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 10) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (14 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 6) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (14 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 2) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 16) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (14 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 12) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (14 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 8) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (14 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 4) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 0) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 14) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (14 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 10) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (14 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 6) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (14 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 2) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 16) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (14 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 12) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (14 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 8) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (14 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 4) % (1U << 14);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search15_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 15) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 13)) << (15 - 13);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 13) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 11)) << (15 - 11);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 11) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 9)) << (15 - 9);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 9) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 7)) << (15 - 7);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 7) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 5)) << (15 - 5);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 5) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 3)) << (15 - 3);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 3) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 1)) << (15 - 1);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 1) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 16) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 31);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (15 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 14) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 29);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (15 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 12) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 27);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (15 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 10) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 25);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (15 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 8) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 23);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (15 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 6) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 21);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (15 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 4) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 19);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (15 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 2) % (1U << 15);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 17);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search16_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 16);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 0) % (1U << 16);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 0) % (1U << 16);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 0) % (1U << 16);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 0) % (1U << 16);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 0) % (1U << 16);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 0) % (1U << 16);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 0) % (1U << 16);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 0) % (1U << 16);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 0) % (1U << 16);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 0) % (1U << 16);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 0) % (1U << 16);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 0) % (1U << 16);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 0) % (1U << 16);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 0) % (1U << 16);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 0) % (1U << 16);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search17_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 17);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 17);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (17 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 2) % (1U << 17);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 19);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (17 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 4) % (1U << 17);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 21);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (17 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 6) % (1U << 17);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 23);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (17 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 8) % (1U << 17);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 25);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (17 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 10) % (1U << 17);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 27);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (17 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 12) % (1U << 17);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 29);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (17 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 14) % (1U << 17);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 31);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (17 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 1)) << (17 - 1);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 1) % (1U << 17);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 3)) << (17 - 3);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 3) % (1U << 17);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 5)) << (17 - 5);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 5) % (1U << 17);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 7)) << (17 - 7);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 7) % (1U << 17);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 9)) << (17 - 9);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 9) % (1U << 17);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 11)) << (17 - 11);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 11) % (1U << 17);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 13)) << (17 - 13);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 13) % (1U << 17);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 15)) << (17 - 15);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 15);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search18_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 18);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (18 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 4) % (1U << 18);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (18 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 8) % (1U << 18);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (18 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 12) % (1U << 18);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (18 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (18 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 2) % (1U << 18);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (18 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 6) % (1U << 18);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (18 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 10) % (1U << 18);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (18 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 14);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 0) % (1U << 18);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (18 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 4) % (1U << 18);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (18 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 8) % (1U << 18);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (18 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 12) % (1U << 18);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (18 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (18 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 2) % (1U << 18);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (18 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 6) % (1U << 18);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (18 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 10) % (1U << 18);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (18 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 14);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search19_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 19);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 19);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (19 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 6) % (1U << 19);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 25);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (19 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 12) % (1U << 19);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 31);
  ++in;
  *decoded |= ((*in) % (1U << 18)) << (19 - 18);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 5)) << (19 - 5);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 5) % (1U << 19);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 11)) << (19 - 11);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 11) % (1U << 19);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 17)) << (19 - 17);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 17);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (19 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 4) % (1U << 19);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 23);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (19 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 10) % (1U << 19);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 29);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (19 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 3)) << (19 - 3);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 3) % (1U << 19);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 9)) << (19 - 9);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 9) % (1U << 19);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 15)) << (19 - 15);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 15);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (19 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 2) % (1U << 19);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 21);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (19 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 8) % (1U << 19);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 27);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (19 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 14);
  ++in;
  *decoded |= ((*in) % (1U << 1)) << (19 - 1);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 1) % (1U << 19);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 7)) << (19 - 7);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 7) % (1U << 19);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 13)) << (19 - 13);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 13);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search20_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 20);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (20 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 8) % (1U << 20);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (20 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (20 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 4) % (1U << 20);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (20 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 0) % (1U << 20);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (20 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 8) % (1U << 20);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (20 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (20 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 4) % (1U << 20);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (20 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 0) % (1U << 20);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (20 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 8) % (1U << 20);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (20 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (20 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 4) % (1U << 20);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (20 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 0) % (1U << 20);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (20 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 8) % (1U << 20);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (20 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (20 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 4) % (1U << 20);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (20 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search21_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 21);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 21);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (21 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 10) % (1U << 21);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 31);
  ++in;
  *decoded |= ((*in) % (1U << 20)) << (21 - 20);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 9)) << (21 - 9);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 9) % (1U << 21);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 19)) << (21 - 19);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 19);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (21 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 8) % (1U << 21);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 29);
  ++in;
  *decoded |= ((*in) % (1U << 18)) << (21 - 18);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 7)) << (21 - 7);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 7) % (1U << 21);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 17)) << (21 - 17);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 17);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (21 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 6) % (1U << 21);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 27);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (21 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 5)) << (21 - 5);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 5) % (1U << 21);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 15)) << (21 - 15);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 15);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (21 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 4) % (1U << 21);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 25);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (21 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 14);
  ++in;
  *decoded |= ((*in) % (1U << 3)) << (21 - 3);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 3) % (1U << 21);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 13)) << (21 - 13);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 13);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (21 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 2) % (1U << 21);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 23);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (21 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded |= ((*in) % (1U << 1)) << (21 - 1);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 1) % (1U << 21);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 11)) << (21 - 11);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 11);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search22_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 22);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (22 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (22 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 2) % (1U << 22);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (22 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 14);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (22 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 4) % (1U << 22);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (22 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (22 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 6) % (1U << 22);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 18)) << (22 - 18);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (22 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 8) % (1U << 22);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 20)) << (22 - 20);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (22 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 10);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 0) % (1U << 22);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (22 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (22 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 2) % (1U << 22);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (22 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 14);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (22 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 4) % (1U << 22);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (22 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (22 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 6) % (1U << 22);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 18)) << (22 - 18);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (22 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 8) % (1U << 22);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 20)) << (22 - 20);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (22 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 10);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search23_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 23);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 23);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (23 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 14);
  ++in;
  *decoded |= ((*in) % (1U << 5)) << (23 - 5);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 5) % (1U << 23);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 19)) << (23 - 19);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 19);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (23 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 10);
  ++in;
  *decoded |= ((*in) % (1U << 1)) << (23 - 1);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 1) % (1U << 23);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 15)) << (23 - 15);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 15);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (23 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 6) % (1U << 23);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 29);
  ++in;
  *decoded |= ((*in) % (1U << 20)) << (23 - 20);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 11)) << (23 - 11);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 11);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (23 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 2) % (1U << 23);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 25);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (23 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 7)) << (23 - 7);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 7) % (1U << 23);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 21)) << (23 - 21);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 21);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (23 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded |= ((*in) % (1U << 3)) << (23 - 3);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 3) % (1U << 23);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 17)) << (23 - 17);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 17);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (23 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 8) % (1U << 23);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 31);
  ++in;
  *decoded |= ((*in) % (1U << 22)) << (23 - 22);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 13)) << (23 - 13);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 13);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (23 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 4) % (1U << 23);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 27);
  ++in;
  *decoded |= ((*in) % (1U << 18)) << (23 - 18);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 9)) << (23 - 9);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 9);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search24_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 24);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (24 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (24 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 0) % (1U << 24);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (24 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (24 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 0) % (1U << 24);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (24 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (24 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 0) % (1U << 24);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (24 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (24 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 0) % (1U << 24);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (24 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (24 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 0) % (1U << 24);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (24 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (24 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 0) % (1U << 24);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (24 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (24 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 0) % (1U << 24);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (24 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (24 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search25_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 25);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 25);
  ++in;
  *decoded |= ((*in) % (1U << 18)) << (25 - 18);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 11)) << (25 - 11);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 11);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (25 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 4) % (1U << 25);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 29);
  ++in;
  *decoded |= ((*in) % (1U << 22)) << (25 - 22);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 15)) << (25 - 15);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 15);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (25 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded |= ((*in) % (1U << 1)) << (25 - 1);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 1) % (1U << 25);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 19)) << (25 - 19);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 19);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (25 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded |= ((*in) % (1U << 5)) << (25 - 5);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 5) % (1U << 25);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 23)) << (25 - 23);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 23);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (25 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 9)) << (25 - 9);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 9);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (25 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 2) % (1U << 25);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 27);
  ++in;
  *decoded |= ((*in) % (1U << 20)) << (25 - 20);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 13)) << (25 - 13);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 13);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (25 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 6) % (1U << 25);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 31);
  ++in;
  *decoded |= ((*in) % (1U << 24)) << (25 - 24);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 17)) << (25 - 17);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 17);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (25 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 10);
  ++in;
  *decoded |= ((*in) % (1U << 3)) << (25 - 3);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 3) % (1U << 25);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 21)) << (25 - 21);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 21);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (25 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 14);
  ++in;
  *decoded |= ((*in) % (1U << 7)) << (25 - 7);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 7);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search26_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 26);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 20)) << (26 - 20);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (26 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 14);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (26 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (26 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 2) % (1U << 26);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 22)) << (26 - 22);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (26 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (26 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 10);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (26 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 4) % (1U << 26);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 24)) << (26 - 24);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 18)) << (26 - 18);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (26 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (26 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 6);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 0) % (1U << 26);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 20)) << (26 - 20);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (26 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 14);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (26 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (26 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 2) % (1U << 26);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 22)) << (26 - 22);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (26 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (26 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 10);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (26 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 4) % (1U << 26);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 24)) << (26 - 24);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 18)) << (26 - 18);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (26 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (26 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 6);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search27_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 27);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 27);
  ++in;
  *decoded |= ((*in) % (1U << 22)) << (27 - 22);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 17)) << (27 - 17);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 17);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (27 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded |= ((*in) % (1U << 7)) << (27 - 7);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 7);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (27 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 2) % (1U << 27);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 29);
  ++in;
  *decoded |= ((*in) % (1U << 24)) << (27 - 24);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 19)) << (27 - 19);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 19);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (27 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 14);
  ++in;
  *decoded |= ((*in) % (1U << 9)) << (27 - 9);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 9);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (27 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 4) % (1U << 27);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 31);
  ++in;
  *decoded |= ((*in) % (1U << 26)) << (27 - 26);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 21)) << (27 - 21);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 21);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (27 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 11)) << (27 - 11);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 11);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (27 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 6);
  ++in;
  *decoded |= ((*in) % (1U << 1)) << (27 - 1);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 1) % (1U << 27);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 23)) << (27 - 23);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 23);
  ++in;
  *decoded |= ((*in) % (1U << 18)) << (27 - 18);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 13)) << (27 - 13);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 13);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (27 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded |= ((*in) % (1U << 3)) << (27 - 3);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 3) % (1U << 27);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 25)) << (27 - 25);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 25);
  ++in;
  *decoded |= ((*in) % (1U << 20)) << (27 - 20);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 15)) << (27 - 15);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 15);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (27 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 10);
  ++in;
  *decoded |= ((*in) % (1U << 5)) << (27 - 5);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 5);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search28_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 28);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 24)) << (28 - 24);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 20)) << (28 - 20);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (28 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (28 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (28 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (28 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 4);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 0) % (1U << 28);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 24)) << (28 - 24);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 20)) << (28 - 20);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (28 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (28 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (28 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (28 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 4);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 0) % (1U << 28);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 24)) << (28 - 24);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 20)) << (28 - 20);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (28 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (28 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (28 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (28 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 4);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 0) % (1U << 28);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 24)) << (28 - 24);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 20)) << (28 - 20);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (28 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (28 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (28 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (28 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 4);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search29_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 29);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 29);
  ++in;
  *decoded |= ((*in) % (1U << 26)) << (29 - 26);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 23)) << (29 - 23);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 23);
  ++in;
  *decoded |= ((*in) % (1U << 20)) << (29 - 20);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 17)) << (29 - 17);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 17);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (29 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 14);
  ++in;
  *decoded |= ((*in) % (1U << 11)) << (29 - 11);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 11);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (29 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded |= ((*in) % (1U << 5)) << (29 - 5);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 5);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (29 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 2) % (1U << 29);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 31);
  ++in;
  *decoded |= ((*in) % (1U << 28)) << (29 - 28);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 25)) << (29 - 25);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 25);
  ++in;
  *decoded |= ((*in) % (1U << 22)) << (29 - 22);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 19)) << (29 - 19);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 19);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (29 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 13)) << (29 - 13);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 13);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (29 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 10);
  ++in;
  *decoded |= ((*in) % (1U << 7)) << (29 - 7);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 7);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (29 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 4);
  ++in;
  *decoded |= ((*in) % (1U << 1)) << (29 - 1);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 1) % (1U << 29);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 27)) << (29 - 27);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 27);
  ++in;
  *decoded |= ((*in) % (1U << 24)) << (29 - 24);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 21)) << (29 - 21);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 21);
  ++in;
  *decoded |= ((*in) % (1U << 18)) << (29 - 18);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 15)) << (29 - 15);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 15);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (29 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded |= ((*in) % (1U << 9)) << (29 - 9);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 9);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (29 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 6);
  ++in;
  *decoded |= ((*in) % (1U << 3)) << (29 - 3);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 3);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search30_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 30);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 28)) << (30 - 28);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 26)) << (30 - 26);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 24)) << (30 - 24);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 22)) << (30 - 22);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 20)) << (30 - 20);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 18)) << (30 - 18);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (30 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (30 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 14);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (30 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (30 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 10);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (30 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (30 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 6);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (30 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 4);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (30 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 2);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 0) % (1U << 30);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 28)) << (30 - 28);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 26)) << (30 - 26);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 24)) << (30 - 24);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 22)) << (30 - 22);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 20)) << (30 - 20);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 18)) << (30 - 18);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (30 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (30 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 14);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (30 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (30 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 10);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (30 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (30 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 6);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (30 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 4);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (30 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 2);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search31_32(uint32_t base, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {

  *decoded = ((*in) >> 0) % (1U << 31);
  *decoded += base;
  if (*decoded >= target)
    return 0;
  *decoded = ((*in) >> 31);
  ++in;
  *decoded |= ((*in) % (1U << 30)) << (31 - 30);
  *decoded += base;
  if (*decoded >= target)
    return 1;
  *decoded = ((*in) >> 30);
  ++in;
  *decoded |= ((*in) % (1U << 29)) << (31 - 29);
  *decoded += base;
  if (*decoded >= target)
    return 2;
  *decoded = ((*in) >> 29);
  ++in;
  *decoded |= ((*in) % (1U << 28)) << (31 - 28);
  *decoded += base;
  if (*decoded >= target)
    return 3;
  *decoded = ((*in) >> 28);
  ++in;
  *decoded |= ((*in) % (1U << 27)) << (31 - 27);
  *decoded += base;
  if (*decoded >= target)
    return 4;
  *decoded = ((*in) >> 27);
  ++in;
  *decoded |= ((*in) % (1U << 26)) << (31 - 26);
  *decoded += base;
  if (*decoded >= target)
    return 5;
  *decoded = ((*in) >> 26);
  ++in;
  *decoded |= ((*in) % (1U << 25)) << (31 - 25);
  *decoded += base;
  if (*decoded >= target)
    return 6;
  *decoded = ((*in) >> 25);
  ++in;
  *decoded |= ((*in) % (1U << 24)) << (31 - 24);
  *decoded += base;
  if (*decoded >= target)
    return 7;
  *decoded = ((*in) >> 24);
  ++in;
  *decoded |= ((*in) % (1U << 23)) << (31 - 23);
  *decoded += base;
  if (*decoded >= target)
    return 8;
  *decoded = ((*in) >> 23);
  ++in;
  *decoded |= ((*in) % (1U << 22)) << (31 - 22);
  *decoded += base;
  if (*decoded >= target)
    return 9;
  *decoded = ((*in) >> 22);
  ++in;
  *decoded |= ((*in) % (1U << 21)) << (31 - 21);
  *decoded += base;
  if (*decoded >= target)
    return 10;
  *decoded = ((*in) >> 21);
  ++in;
  *decoded |= ((*in) % (1U << 20)) << (31 - 20);
  *decoded += base;
  if (*decoded >= target)
    return 11;
  *decoded = ((*in) >> 20);
  ++in;
  *decoded |= ((*in) % (1U << 19)) << (31 - 19);
  *decoded += base;
  if (*decoded >= target)
    return 12;
  *decoded = ((*in) >> 19);
  ++in;
  *decoded |= ((*in) % (1U << 18)) << (31 - 18);
  *decoded += base;
  if (*decoded >= target)
    return 13;
  *decoded = ((*in) >> 18);
  ++in;
  *decoded |= ((*in) % (1U << 17)) << (31 - 17);
  *decoded += base;
  if (*decoded >= target)
    return 14;
  *decoded = ((*in) >> 17);
  ++in;
  *decoded |= ((*in) % (1U << 16)) << (31 - 16);
  *decoded += base;
  if (*decoded >= target)
    return 15;
  *decoded = ((*in) >> 16);
  ++in;
  *decoded |= ((*in) % (1U << 15)) << (31 - 15);
  *decoded += base;
  if (*decoded >= target)
    return 16;
  *decoded = ((*in) >> 15);
  ++in;
  *decoded |= ((*in) % (1U << 14)) << (31 - 14);
  *decoded += base;
  if (*decoded >= target)
    return 17;
  *decoded = ((*in) >> 14);
  ++in;
  *decoded |= ((*in) % (1U << 13)) << (31 - 13);
  *decoded += base;
  if (*decoded >= target)
    return 18;
  *decoded = ((*in) >> 13);
  ++in;
  *decoded |= ((*in) % (1U << 12)) << (31 - 12);
  *decoded += base;
  if (*decoded >= target)
    return 19;
  *decoded = ((*in) >> 12);
  ++in;
  *decoded |= ((*in) % (1U << 11)) << (31 - 11);
  *decoded += base;
  if (*decoded >= target)
    return 20;
  *decoded = ((*in) >> 11);
  ++in;
  *decoded |= ((*in) % (1U << 10)) << (31 - 10);
  *decoded += base;
  if (*decoded >= target)
    return 21;
  *decoded = ((*in) >> 10);
  ++in;
  *decoded |= ((*in) % (1U << 9)) << (31 - 9);
  *decoded += base;
  if (*decoded >= target)
    return 22;
  *decoded = ((*in) >> 9);
  ++in;
  *decoded |= ((*in) % (1U << 8)) << (31 - 8);
  *decoded += base;
  if (*decoded >= target)
    return 23;
  *decoded = ((*in) >> 8);
  ++in;
  *decoded |= ((*in) % (1U << 7)) << (31 - 7);
  *decoded += base;
  if (*decoded >= target)
    return 24;
  *decoded = ((*in) >> 7);
  ++in;
  *decoded |= ((*in) % (1U << 6)) << (31 - 6);
  *decoded += base;
  if (*decoded >= target)
    return 25;
  *decoded = ((*in) >> 6);
  ++in;
  *decoded |= ((*in) % (1U << 5)) << (31 - 5);
  *decoded += base;
  if (*decoded >= target)
    return 26;
  *decoded = ((*in) >> 5);
  ++in;
  *decoded |= ((*in) % (1U << 4)) << (31 - 4);
  *decoded += base;
  if (*decoded >= target)
    return 27;
  *decoded = ((*in) >> 4);
  ++in;
  *decoded |= ((*in) % (1U << 3)) << (31 - 3);
  *decoded += base;
  if (*decoded >= target)
    return 28;
  *decoded = ((*in) >> 3);
  ++in;
  *decoded |= ((*in) % (1U << 2)) << (31 - 2);
  *decoded += base;
  if (*decoded >= target)
    return 29;
  *decoded = ((*in) >> 2);
  ++in;
  *decoded |= ((*in) % (1U << 1)) << (31 - 1);
  *decoded += base;
  if (*decoded >= target)
    return 30;
  *decoded = ((*in) >> 1);
  ++in;
  *decoded += base;
  if (*decoded >= target)
    return 31;
  return -1;
}

static int search32_32(uint32_t, const uint32_t *in, uint32_t target,
                       uint32_t *decoded) {
  for (int k = 0; k < 32; ++k) {
    if (in[k] >= target) {
      *decoded = in[k];
      return k;
    }
  }
  return -1;
}

static int searchlinearfor(uint32_t base, const uint32_t *in, uint32_t bit,
                           uint32_t target, uint32_t *presult) {
  switch (bit) {
  case 0:
    if (target < base)
      return -1;
    else {
      *presult = base;
      return 0;
    }

  case 1:
    return search1_32(base, in, target, presult);

  case 2:
    return search2_32(base, in, target, presult);

  case 3:
    return search3_32(base, in, target, presult);

  case 4:
    return search4_32(base, in, target, presult);

  case 5:
    return search5_32(base, in, target, presult);

  case 6:
    return search6_32(base, in, target, presult);

  case 7:
    return search7_32(base, in, target, presult);

  case 8:
    return search8_32(base, in, target, presult);

  case 9:
    return search9_32(base, in, target, presult);

  case 10:
    return search10_32(base, in, target, presult);

  case 11:
    return search11_32(base, in, target, presult);

  case 12:
    return search12_32(base, in, target, presult);

  case 13:
    return search13_32(base, in, target, presult);

  case 14:
    return search14_32(base, in, target, presult);

  case 15:
    return search15_32(base, in, target, presult);

  case 16:
    return search16_32(base, in, target, presult);

  case 17:
    return search17_32(base, in, target, presult);

  case 18:
    return search18_32(base, in, target, presult);

  case 19:
    return search19_32(base, in, target, presult);

  case 20:
    return search20_32(base, in, target, presult);

  case 21:
    return search21_32(base, in, target, presult);

  case 22:
    return search22_32(base, in, target, presult);

  case 23:
    return search23_32(base, in, target, presult);

  case 24:
    return search24_32(base, in, target, presult);

  case 25:
    return search25_32(base, in, target, presult);

  case 26:
    return search26_32(base, in, target, presult);

  case 27:
    return search27_32(base, in, target, presult);

  case 28:
    return search28_32(base, in, target, presult);

  case 29:
    return search29_32(base, in, target, presult);

  case 30:
    return search30_32(base, in, target, presult);

  case 31:
    return search31_32(base, in, target, presult);

  case 32:
    return search32_32(base, in, target, presult);

  default:
    break;
  }
  return (-1);
}

/***
 * END OF linear search
 */

size_t findlower_linear(const uint32_t *in, uint32_t key, uint32_t *presult) {
  selectmetadata s;
  s.length = *in;
  in++;
  s.m = *in;
  ++in;
  uint32_t M = *in;
  ++in;
  s.b = bits(M - s.m);
  s.in = in;

  for (uint32_t k = 0, offset = 0; k < s.length; k += 32, offset += s.b) {
    if (32 + k > s.length) {
      for (uint32_t z = 0; z < s.length - k; ++z) {
        if (*(s.in + offset + z) >= key) {
          *presult = *(s.in + offset + z);
          return k + z;
        }
      }
      return -1;
    }

    int x = searchlinearfor(s.m, s.in + offset, s.b, key, presult);
    if (x >= 0) {
      return k + x;
    }
  }
  return -1;
}

// Performs a lower bound find in the encoded array.
// Returns the index
size_t SIMDCompressionLib::FrameOfReference::findLowerBound(const uint32_t *in,
                                                            const size_t,
                                                            uint32_t key,
                                                            uint32_t *presult) {
  const bool USES_BINARY = true;
  if (USES_BINARY) {
    return findlowerbound(in, key, presult);
  } else {
    return findlower_linear(in, key, presult);
  }
}

// Returns a decompressed value in an encoded array
uint32_t SIMDCompressionLib::FrameOfReference::select(const uint32_t *in,
                                                      size_t index) {
  uint32_t length = *in;
  in++;
  uint32_t m = *in;
  ++in;
  uint32_t M = *in;
  ++in;
  uint32_t b = bits(M - m);
  if (b == 32) {
    return in[index];
  }
  uint32_t packedlength = length / 32 * 32;
  if (index > packedlength) {
    uint32_t packedsizeinwords = packedlength * b / 32;
    return in[packedsizeinwords + index - packedlength];
  }
  const int bitoffset = static_cast<uint32_t>(index) * b; /* how many bits  */
  const int firstword = bitoffset / 32;
  const int secondword = (bitoffset + b - 1) / 32;
  const uint32_t firstpart = in[firstword] >> (bitoffset % 32);
  const uint32_t mask = (1 << b) - 1;
  if (firstword == secondword) {
    /* easy common case*/
    return m + (firstpart & mask);
  } else {
    /* harder case where we need to combine two words */
    const uint32_t secondpart = in[firstword + 1];
    const int usablebitsinfirstword = 32 - (bitoffset % 32);
    return m + ((firstpart | (secondpart << usablebitsinfirstword)) & mask);
  }
}

/********************************
 * SIMD VERSION FOLLOWS
 ********************************
 ********************************
 ********************************/

static __m128i iunpackFOR0(__m128i initOffset, const __m128i *_in,
                           uint32_t *_out) {
  __m128i *out = (__m128i *)(_out);
  int i;
  (void)_in;
  for (i = 0; i < 8; ++i) {
    _mm_storeu_si128(out++, initOffset);
    _mm_storeu_si128(out++, initOffset);
    _mm_storeu_si128(out++, initOffset);
    _mm_storeu_si128(out++, initOffset);
  }

  return initOffset;
}

static void ipackFOR0(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  (void)initOffset;
  (void)_in;
  (void)out;
}

static void ipackFOR1(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR2(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR3(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 3 - 1);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 3 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR4(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR5(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 3);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 1);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 5 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR6(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 6 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR7(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 3);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 5);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 1);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 7 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR8(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR9(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 3);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 7);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 1);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 9 - 5);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR10(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 10 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR11(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 1);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 3);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 5);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 7);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 9);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 11 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR12(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 12 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR13(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 7);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 1);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 9);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 3);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 11);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 5);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 13 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR14(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 14 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR15(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 13);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 11);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 9);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 7);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 5);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 3);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 1);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 15 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR16(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR17(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 1);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 3);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 5);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 7);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 9);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 11);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 13);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 17 - 15);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR18(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 18 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR19(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 18);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 5);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 11);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 17);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 3);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 9);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 15);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 1);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 7);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 19 - 13);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR20(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 20 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR21(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 20);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 9);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 19);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 18);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 7);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 17);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 5);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 15);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 3);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 13);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 1);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 21 - 11);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR22(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 18);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 20);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 18);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 20);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 22 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR23(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 5);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 19);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 1);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 15);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 20);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 11);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 7);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 21);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 3);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 17);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 22);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 13);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 18);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 23 - 9);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR24(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 24 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR25(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 18);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 11);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 22);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 15);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 1);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 19);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 5);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 23);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 9);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 20);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 13);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 24);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 17);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 3);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 21);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 25 - 7);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR26(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 20);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 22);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 24);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 18);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 20);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 22);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 24);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 18);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 26 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR27(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 22);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 17);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 7);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 24);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 19);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 9);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 26);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 21);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 11);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 1);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 23);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 18);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 13);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 3);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 25);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 20);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 15);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 27 - 5);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR28(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 24);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 20);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 28 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR29(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 26);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 23);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 20);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 17);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 11);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 5);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 28);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 25);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 22);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 19);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 13);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 7);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 1);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 27);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 24);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 21);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 18);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 15);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 9);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 29 - 3);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR30(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 28);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 26);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 24);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 22);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 20);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 18);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 28);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 26);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 24);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 22);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 20);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 18);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 30 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR31(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i CurrIn = _mm_loadu_si128(in);
  __m128i InReg = _mm_sub_epi32(CurrIn, initOffset);
  OutReg = InReg;
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 30);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 29);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 28);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 27);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 26);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 25);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 24);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 23);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 22);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 21);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 20);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 19);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 18);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 17);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 16);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 15);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 14);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 13);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 12);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 11);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 10);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 9);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 8);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 7);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 6);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 5);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 4);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 3);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 2);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
  _mm_storeu_si128(out, OutReg);

  ++out;
  OutReg = _mm_srli_epi32(InReg, 31 - 1);
  ++in;
  CurrIn = _mm_loadu_si128(in);
  InReg = _mm_sub_epi32(CurrIn, initOffset);

  OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
  _mm_storeu_si128(out, OutReg);
}

static void ipackFOR32(__m128i initOffset, const uint32_t *_in, __m128i *out) {
  const __m128i *in = (const __m128i *)(_in);
  __m128i OutReg;

  __m128i InReg = _mm_loadu_si128(in);
  (void)initOffset;

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);

  ++out;
  ++in;
  InReg = _mm_loadu_si128(in);

  OutReg = InReg;
  _mm_storeu_si128(out, OutReg);
}

static __m128i iunpackFOR1(__m128i initOffset, const __m128i *in,
                           uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 1) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR2(__m128i initOffset, const __m128i *in,
                           uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 2) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR3(__m128i initOffset, const __m128i *in,
                           uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 3) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 3 - 1), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 3 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR4(__m128i initOffset, const __m128i *in,
                           uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 4) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR5(__m128i initOffset, const __m128i *in,
                           uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 5) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 5 - 3), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 5 - 1), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 5 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 5 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR6(__m128i initOffset, const __m128i *in,
                           uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 6) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 6 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 6 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 6 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 6 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR7(__m128i initOffset, const __m128i *in,
                           uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 7) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 3), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 5), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 1), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 7 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR8(__m128i initOffset, const __m128i *in,
                           uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 8) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR9(__m128i initOffset, const __m128i *in,
                           uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 9) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 3), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 7), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 1), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 9 - 5), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR10(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 10) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 10 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR11(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 11) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 1), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 3), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 5), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 7), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 9), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 11 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR12(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 12) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 12 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR13(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 13) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 7), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 1), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 9), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 3), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 11), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 5), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 13 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR14(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 14) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 14 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR15(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 15) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 13), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 11), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 9), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 7), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 5), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 3), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 1), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 15 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR16(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 16) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR17(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 17) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 1), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 3), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 5), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 7), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 9), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 11), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 13), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 17 - 15), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR18(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 18) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 18 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR19(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 19) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 18), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 5), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 11), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 17), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 3), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 9), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 15), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 1), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 7), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 19 - 13), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR20(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 20) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 20 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR21(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 21) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 20), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 9), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 19), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 18), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 7), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 17), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 5), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 15), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 3), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 13), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 1), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 21 - 11), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR22(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 22) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 18), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 20), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 18), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 20), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 22 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR23(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 23) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 5), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 19), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 1), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 15), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 20), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 11), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 7), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 21), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 3), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 17), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 22), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 13), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 18), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 23 - 9), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR24(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 24) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 24 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR25(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 25) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 18), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 11), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 22), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 15), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 1), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 19), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 5), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 23), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 9), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 20), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 13), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 24), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 17), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 3), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 21), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 25 - 7), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR26(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 26) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 20), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 22), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 24), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 18), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 20), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 22), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 24), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 18), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 26 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR27(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 27) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 22), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 17), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 7), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 24), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 19), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 9), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 26), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 21), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 11), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 1), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 23), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 18), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 13), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 3), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 25), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 20), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 15), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 27 - 5), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR28(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 28) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 24), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 20), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 24), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 20), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 24), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 20), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 24), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 20), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 28 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR29(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 29) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 26), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 23), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 20), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 17), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 11), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 5), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 28), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 25), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 22), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 19), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 13), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 7), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 1), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 27), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 24), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 21), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 18), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 15), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 9), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 29 - 3), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR30(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 30) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 28), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 26), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 24), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 22), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 20), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 18), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 28), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 26), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 24), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 22), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 20), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 18), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 30 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR31(__m128i initOffset, const __m128i *in,
                            uint32_t *_out) {

  __m128i *out = (__m128i *)(_out);
  __m128i InReg = _mm_loadu_si128(in);
  __m128i OutReg;
  __m128i tmp;
  const __m128i mask = _mm_set1_epi32((1U << 31) - 1);

  tmp = InReg;
  OutReg = _mm_and_si128(tmp, mask);
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 31);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 30), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 30);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 29), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 29);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 28), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 28);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 27), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 27);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 26), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 26);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 25), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 25);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 24), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 24);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 23), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 23);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 22), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 22);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 21), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 21);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 20), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 20);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 19), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 19);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 18), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 18);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 17), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 17);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 16), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 16);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 15), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 15);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 14), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 14);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 13), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 13);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 12), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 12);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 11), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 11);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 10), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 10);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 9), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 9);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 8), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 8);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 7), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 7);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 6), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 6);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 5), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 5);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 4), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 4);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 3), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 3);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 2), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 2);
  OutReg = tmp;
  ++in;
  InReg = _mm_loadu_si128(in);
  OutReg =
      _mm_or_si128(OutReg, _mm_and_si128(_mm_slli_epi32(InReg, 31 - 1), mask));

  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  tmp = _mm_srli_epi32(InReg, 1);
  OutReg = tmp;
  OutReg = _mm_add_epi32(OutReg, initOffset);
  _mm_storeu_si128(out++, OutReg);

  return initOffset;
}

static __m128i iunpackFOR32(__m128i initvalue, const __m128i *in,
                            uint32_t *_out) {
  __m128i *mout = (__m128i *)_out;
  __m128i invec;
  size_t k;
  (void)initvalue;
  for (k = 0; k < 128 / 4; ++k) {
    invec = _mm_loadu_si128(in++);
    _mm_storeu_si128(mout++, invec);
  }
  return invec;
}

void simdpackFOR(uint32_t initvalue, const uint32_t *in, __m128i *out,
                 const uint32_t bit) {
  __m128i initOffset = _mm_set1_epi32(initvalue);
  switch (bit) {
  case 0:
    ipackFOR0(initOffset, in, out);
    break;

  case 1:
    ipackFOR1(initOffset, in, out);
    break;

  case 2:
    ipackFOR2(initOffset, in, out);
    break;

  case 3:
    ipackFOR3(initOffset, in, out);
    break;

  case 4:
    ipackFOR4(initOffset, in, out);
    break;

  case 5:
    ipackFOR5(initOffset, in, out);
    break;

  case 6:
    ipackFOR6(initOffset, in, out);
    break;

  case 7:
    ipackFOR7(initOffset, in, out);
    break;

  case 8:
    ipackFOR8(initOffset, in, out);
    break;

  case 9:
    ipackFOR9(initOffset, in, out);
    break;

  case 10:
    ipackFOR10(initOffset, in, out);
    break;

  case 11:
    ipackFOR11(initOffset, in, out);
    break;

  case 12:
    ipackFOR12(initOffset, in, out);
    break;

  case 13:
    ipackFOR13(initOffset, in, out);
    break;

  case 14:
    ipackFOR14(initOffset, in, out);
    break;

  case 15:
    ipackFOR15(initOffset, in, out);
    break;

  case 16:
    ipackFOR16(initOffset, in, out);
    break;

  case 17:
    ipackFOR17(initOffset, in, out);
    break;

  case 18:
    ipackFOR18(initOffset, in, out);
    break;

  case 19:
    ipackFOR19(initOffset, in, out);
    break;

  case 20:
    ipackFOR20(initOffset, in, out);
    break;

  case 21:
    ipackFOR21(initOffset, in, out);
    break;

  case 22:
    ipackFOR22(initOffset, in, out);
    break;

  case 23:
    ipackFOR23(initOffset, in, out);
    break;

  case 24:
    ipackFOR24(initOffset, in, out);
    break;

  case 25:
    ipackFOR25(initOffset, in, out);
    break;

  case 26:
    ipackFOR26(initOffset, in, out);
    break;

  case 27:
    ipackFOR27(initOffset, in, out);
    break;

  case 28:
    ipackFOR28(initOffset, in, out);
    break;

  case 29:
    ipackFOR29(initOffset, in, out);
    break;

  case 30:
    ipackFOR30(initOffset, in, out);
    break;

  case 31:
    ipackFOR31(initOffset, in, out);
    break;

  case 32:
    ipackFOR32(initOffset, in, out);
    break;

  default:
    break;
  }
}

void simdunpackFOR(uint32_t initvalue, const __m128i *in, uint32_t *out,
                   const uint32_t bit) {
  __m128i initOffset = _mm_set1_epi32(initvalue);
  switch (bit) {
  case 0:
    iunpackFOR0(initOffset, in, out);
    break;

  case 1:
    iunpackFOR1(initOffset, in, out);
    break;

  case 2:
    iunpackFOR2(initOffset, in, out);
    break;

  case 3:
    iunpackFOR3(initOffset, in, out);
    break;

  case 4:
    iunpackFOR4(initOffset, in, out);
    break;

  case 5:
    iunpackFOR5(initOffset, in, out);
    break;

  case 6:
    iunpackFOR6(initOffset, in, out);
    break;

  case 7:
    iunpackFOR7(initOffset, in, out);
    break;

  case 8:
    iunpackFOR8(initOffset, in, out);
    break;

  case 9:
    iunpackFOR9(initOffset, in, out);
    break;

  case 10:
    iunpackFOR10(initOffset, in, out);
    break;

  case 11:
    iunpackFOR11(initOffset, in, out);
    break;

  case 12:
    iunpackFOR12(initOffset, in, out);
    break;

  case 13:
    iunpackFOR13(initOffset, in, out);
    break;

  case 14:
    iunpackFOR14(initOffset, in, out);
    break;

  case 15:
    iunpackFOR15(initOffset, in, out);
    break;

  case 16:
    iunpackFOR16(initOffset, in, out);
    break;

  case 17:
    iunpackFOR17(initOffset, in, out);
    break;

  case 18:
    iunpackFOR18(initOffset, in, out);
    break;

  case 19:
    iunpackFOR19(initOffset, in, out);
    break;

  case 20:
    iunpackFOR20(initOffset, in, out);
    break;

  case 21:
    iunpackFOR21(initOffset, in, out);
    break;

  case 22:
    iunpackFOR22(initOffset, in, out);
    break;

  case 23:
    iunpackFOR23(initOffset, in, out);
    break;

  case 24:
    iunpackFOR24(initOffset, in, out);
    break;

  case 25:
    iunpackFOR25(initOffset, in, out);
    break;

  case 26:
    iunpackFOR26(initOffset, in, out);
    break;

  case 27:
    iunpackFOR27(initOffset, in, out);
    break;

  case 28:
    iunpackFOR28(initOffset, in, out);
    break;

  case 29:
    iunpackFOR29(initOffset, in, out);
    break;

  case 30:
    iunpackFOR30(initOffset, in, out);
    break;

  case 31:
    iunpackFOR31(initOffset, in, out);
    break;

  case 32:
    iunpackFOR32(initOffset, in, out);
    break;

  default:
    break;
  }
}

// Returns a decompressed value in an encoded array
uint32_t SIMDCompressionLib::SIMDFrameOfReference::select(const uint32_t *in,
                                                          size_t index) {
  // uint32_t length = *in;
  in++;
  uint32_t m = *in;
  ++in;
  uint32_t M = *in;
  ++in;
  uint32_t bit = bits(M - m);
  if (bit == 32) {
    return in[index];
  }
  in += index / 128 * 4 * bit;
  const int slot = index % 128;
  const int lane = slot % 4;               /* we have 4 interleaved lanes */
  const int bitsinlane = (slot / 4) * bit; /* how many bits in lane */
  const int firstwordinlane = bitsinlane / 32;
  const int secondwordinlane = (bitsinlane + bit - 1) / 32;
  const uint32_t firstpart =
      in[4 * firstwordinlane + lane] >> (bitsinlane % 32);
  const uint32_t mask = (1 << bit) - 1;
  if (firstwordinlane == secondwordinlane) {
    /* easy common case*/
    return m + (firstpart & mask);
  } else {
    /* harder case where we need to combine two words */
    const uint32_t secondpart = in[4 * firstwordinlane + 4 + lane];
    const int usablebitsinfirstword = 32 - (bitsinlane % 32);
    return m + ((firstpart | (secondpart << usablebitsinfirstword)) & mask);
  }
}

static uint32_t simdfastselect(const uint32_t *in, int b, uint32_t m,
                               size_t index) {
  // if (b == 32) {
  //	return in[index];
  //}
  const int lane = index % 4; /* we have 4 interleaved lanes */
  const int bitsinlane =
      static_cast<uint32_t>(index / 4) * b; /* how many bits in lane */
  const int firstwordinlane = bitsinlane / 32;
  const int secondwordinlane = (bitsinlane + b - 1) / 32;
  const uint32_t firstpart =
      in[4 * firstwordinlane + lane] >> (bitsinlane % 32);
  const uint32_t mask = (1 << b) - 1;
  if (firstwordinlane == secondwordinlane) {
    /* easy common case*/
    return m + (firstpart & mask);
  } else {
    /* harder case where we need to combine two words */
    const uint32_t secondpart = in[4 * firstwordinlane + 4 + lane];
    const int usablebitsinfirstword = 32 - (bitsinlane % 32);
    return m + ((firstpart | (secondpart << usablebitsinfirstword)) & mask);
  }
}

// Performs a lower bound find in the encoded array.
// Returns the index
size_t SIMDCompressionLib::SIMDFrameOfReference::findLowerBound(
    const uint32_t *in, const size_t, uint32_t key, uint32_t *presult) {
  uint32_t length = *in;
  in++;
  uint32_t m = *in;
  ++in;
  uint32_t M = *in;
  ++in;
  uint32_t b = bits(M - m);
  uint32_t count = length;
  uint32_t begin = 0;
  uint32_t val;
  if (b == 32) { // we handle the special case separately
    while (count > 0) {
      uint32_t step = count / 2;
      val = in[begin + step];
      if (val < key) {
        begin += step + 1;
        count -= step + 1;
      } else
        count = step;
    }
    *presult = in[begin];
    return begin;
  }
  while (count > 0) {
    uint32_t step = count / 2;
    val = simdfastselect(in, b, m, begin + step);
    if (val < key) {
      begin += step + 1;
      count -= step + 1;
    } else
      count = step;
  }
  *presult = simdfastselect(in, b, m, begin);
  return begin;
}

static uint32_t minasint(const __m128i accumulator) {
  const __m128i _tmp1 = _mm_min_epu32(
      _mm_srli_si128(accumulator, 8),
      accumulator); /* (A,B,C,D) xor (0,0,A,B) = (A,B,C xor A,D xor B)*/
  const __m128i _tmp2 =
      _mm_min_epu32(_mm_srli_si128(_tmp1, 4),
                    _tmp1); /*  (A,B,C xor A,D xor B) xor  (0,0,0,C xor A)*/
  return _mm_cvtsi128_si32(_tmp2);
}

static uint32_t maxasint(const __m128i accumulator) {
  const __m128i _tmp1 = _mm_max_epu32(
      _mm_srli_si128(accumulator, 8),
      accumulator); /* (A,B,C,D) xor (0,0,A,B) = (A,B,C xor A,D xor B)*/
  const __m128i _tmp2 =
      _mm_max_epu32(_mm_srli_si128(_tmp1, 4),
                    _tmp1); /*  (A,B,C xor A,D xor B) xor  (0,0,0,C xor A)*/
  return _mm_cvtsi128_si32(_tmp2);
}

static void simdmaxmin_length(const uint32_t *in, uint32_t length,
                              uint32_t *getmin, uint32_t *getmax) {
  uint32_t lengthdividedby4 = length / 4;
  uint32_t offset = lengthdividedby4 * 4;
  uint32_t k;
  *getmin = 0xFFFFFFFF;
  *getmax = 0;
  if (lengthdividedby4 > 0) {
    const __m128i *pin = (const __m128i *)(in);
    __m128i minaccumulator = _mm_loadu_si128(pin);
    __m128i maxaccumulator = minaccumulator;
    k = 1;
    for (; 4 * k < lengthdividedby4 * 4; ++k) {
      __m128i newvec = _mm_loadu_si128(pin + k);
      minaccumulator = _mm_min_epu32(minaccumulator, newvec);
      maxaccumulator = _mm_max_epu32(maxaccumulator, newvec);
    }
    *getmin = minasint(minaccumulator);
    *getmax = maxasint(maxaccumulator);
  }
  for (k = offset; k < length; ++k) {
    if (in[k] < *getmin)
      *getmin = in[k];
    if (in[k] > *getmax)
      *getmax = in[k];
  }
}

uint32_t *SIMDCompressionLib::SIMDFrameOfReference::simd_compress_length(
    const uint32_t *in, uint32_t length, uint32_t *out) {
  if (length == 0)
    return out;
  uint32_t m, M;
  simdmaxmin_length(in, length, &m, &M);
  int b = bits(static_cast<uint32_t>(M - m));
  out[0] = m;
  ++out;
  out[0] = M;
  ++out;
  uint32_t k = 0;
  for (; k + 128 <= length; k += 128, in += 128) {
    simdpackFOR(m, in, (__m128i *)out, b);
    out += b * 4;
  }
  if (length != k)
    out = (uint32_t *)simdpackFOR_length(m, in, length - k, (__m128i *)out, b);
  in += length - k;

  return out;
}

size_t SIMDCompressionLib::SIMDFrameOfReference::append(
    uint8_t *inbyte, const size_t currentcompressedsizeinbytes,
    uint32_t value) {
  if (currentcompressedsizeinbytes == 0) {
    size_t nvalue = 16; // 16 is arbitrary
    encodeArray(&value, 1, (uint32_t *)inbyte, nvalue);
    return nvalue * sizeof(uint32_t);
  }
  uint32_t *in = (uint32_t *)inbyte;

  uint32_t nvalue = *in;
  in[0] += 1; // incrementing!
  in++;

  uint32_t m = in[0];
  uint32_t M = in[1];

  int b = bits(static_cast<uint32_t>(M - m));
  if ((value < m) || (value > M)) { // should be unlikely
    uint32_t newm = m;
    uint32_t newM = M;

    if (value < m) {
      newm = value;
    }
    if (value > M) {
      newM = value;
    }
    int newb = bits(static_cast<uint32_t>(newM - newm));
    if ((newb != b) || (value < m)) { // unlucky path
      vector<uint32_t> buffer(nvalue + 1);
      simd_uncompress_length(in, buffer.data(), nvalue);
      buffer[nvalue] = value;
      uint32_t *newin = simd_compress_length(buffer.data(), nvalue + 1, in);
      return (newin - in + 1) * sizeof(uint32_t);
    } else { // only max changed
      in[1] = newM;
      M = newM; // probably unnecessary
    }
  }
  // add one
  in += 2;
  uint32_t headersize = 3;

  // Appending values one by one defeats the purpose of
  // vectorization which is best for in-bulk processing.
  // So we are not going to waste too much time trying to
  // optimize the code here. We just try to avoid
  // obviously unnecessary processing.

  uint32_t buffer[128];
  size_t oldhowmanyfull = nvalue / 128;
  uint32_t *const newin = in + 4 * b * oldhowmanyfull;
  size_t need_decoding = nvalue - oldhowmanyfull * 128;
  simdunpackFOR_length(m, (__m128i *)newin, static_cast<int>(need_decoding),
                       buffer, b);

  buffer[need_decoding] = value;

  uint32_t *out = (uint32_t *)simdpackFOR_length(
      m, buffer, static_cast<int>(need_decoding + 1), (__m128i *)newin, b);

  return (out - in + headersize) * sizeof(uint32_t);
}

/*
 * Not sure what this was for?
 *
uint32_t * simd_compress_length_sorted(const uint32_t * in, uint32_t length,
uint32_t * out) {
    if(length == 0) return out;
    uint32_t m = in[0];
    uint32_t M = in[length - 1];
    int b = bits(static_cast<uint32_t>(M-m));
    out[0] = m;
    ++out;
    out[0] = M;
    ++out;
    uint32_t k = 0;
    for(; k+128<=length; k+=128,in+=128) {
        simdpackFOR(m,  in, (__m128i *)    out, b);
        out += b * 4;
    }
    if(length != k) out = (uint32_t *) simdpackFOR_length(m, in, length - k ,
(__m128i *) out,b);
    in += length - k;

    return out;
}*/

const uint32_t *
SIMDCompressionLib::SIMDFrameOfReference::simd_uncompress_length(
    const uint32_t *in, uint32_t *out, uint32_t nvalue) {
  if (nvalue == 0)
    return out;
  uint32_t m = in[0];
  ++in;
  uint32_t M = in[0];
  ++in;
  int b = bits(static_cast<uint32_t>(M - m));
  for (uint32_t k = 0; k < nvalue / 128; ++k) {
    simdunpackFOR(m, (const __m128i *)(in + 4 * b * k), out + 128 * k, b);
  }
  out = out + nvalue / 128 * 128;
  in = in + nvalue / 128 * 4 * b;
  if ((nvalue % 128) != 0)
    in = (const uint32_t *)simdunpackFOR_length(
        m, (__m128i *)in, nvalue - nvalue / 128 * 128, out, b);

  return in;
}
