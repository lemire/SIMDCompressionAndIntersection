/**
 * (c) Part of the copyright is to Indeed.com
 * Licensed under the Apache License Version 2.0
 */

/*
 * Based on an initial design by Jeff Plaisance and
 * improved by Nathan Kurz.
 */

#ifndef SIMDCompressionAndIntersection_SIMDVARIABLEBYTE_H_
#define SIMDCompressionAndIntersection_SIMDVARIABLEBYTE_H_

#include "common.h"
#include "codecs.h"
#include "util.h"

namespace SIMDCompressionLib {

extern "C" {
size_t masked_vbyte_read_loop(const uint8_t *in, uint32_t *out,
                              uint64_t length);
size_t masked_vbyte_read_loop_delta(const uint8_t *in, uint32_t *out,
                                    uint64_t length, uint32_t prev);
size_t masked_vbyte_read_loop_fromcompressedsize(const uint8_t *in,
                                                 uint32_t *out,
                                                 size_t inputsize);
size_t masked_vbyte_read_loop_fromcompressedsize_delta(const uint8_t *in,
                                                       uint32_t *out,
                                                       size_t inputsize,
                                                       uint32_t prev);
// size_t read_ints(const uint8_t* in, uint32_t* out, int length) ;
// size_t read_ints_delta(const uint8_t* in, uint32_t* out, int length, uint32_t
// prev) ;
uint32_t masked_vbyte_select_delta(const uint8_t *in, uint64_t length,
                                   uint32_t prev, size_t slot);
int masked_vbyte_search_delta(const uint8_t *in, uint64_t length, uint32_t prev,
                              uint32_t key, uint32_t *presult);
}

/**
 * This is a SIMD-accelerated version that is byte-by-byte format compatible
 * with
 * the VByte codec (that is, standard vbyte).
 */
template <bool delta> class MaskedVByte : public IntegerCODEC {
public:
  MaskedVByte() {}

  void encodeArray(uint32_t *in, const size_t length, uint32_t *out,
                   size_t &nvalue) {
    const uint8_t *const initbout = reinterpret_cast<uint8_t *>(out);
    *out = static_cast<uint32_t>(length);
    out++;
    uint8_t *bout = reinterpret_cast<uint8_t *>(out);
    uint32_t prev = 0;
    for (size_t k = 0; k < length; ++k) {

      const uint32_t val = delta ? (in[k] - prev) : in[k];
      if (delta)
        prev = in[k];
      /**
       * Code below could be shorter. Whether it could be faster
       * depends on your compiler and machine.
       */
      if (val < (1U << 7)) {
        *bout = val & 0x7F;
        ++bout;
      } else if (val < (1U << 14)) {
        *bout = static_cast<uint8_t>((val & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(val >> 7);
        ++bout;
      } else if (val < (1U << 21)) {
        *bout = static_cast<uint8_t>((val & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(((val >> 7) & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(val >> 14);
        ++bout;
      } else if (val < (1U << 28)) {
        *bout = static_cast<uint8_t>((val & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(((val >> 7) & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(((val >> 14) & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(val >> 21);
        ++bout;
      } else {
        *bout = static_cast<uint8_t>((val & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(((val >> 7) & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(((val >> 14) & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(((val >> 21) & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(val >> 28);
        ++bout;
      }
    }
    while (needPaddingTo32Bits(bout)) {
      *bout++ = 0xff;
    }
    const size_t storageinbytes = bout - initbout;
    nvalue = storageinbytes / 4;
  }

  const uint32_t *decodeArray(const uint32_t *in, const size_t length,
                              uint32_t *out, size_t &nvalue) {
    nvalue = *in;
    const uint8_t *inbyte =
        decodeFromByteArray((const uint8_t *)in, length, out, nvalue);
    inbyte = padTo32bits(inbyte);
    return reinterpret_cast<const uint32_t *>(inbyte);
  }

  // Same as above, but operates on byte arrays (uint8_t *) and avoids
  // the padding at the end
  const uint8_t *decodeFromByteArray(const uint8_t *in,
                                     const size_t /* length */, uint32_t *out,
                                     size_t &nvalue) {
    nvalue = *(uint32_t *)in;
    in += sizeof(uint32_t);
    if (nvalue == 0) {
      return in; // abort
    }
    if (delta) {
      uint32_t prev = 0;
      in += masked_vbyte_read_loop_delta(in, out, nvalue, prev);
    } else
      in += masked_vbyte_read_loop(in, out, nvalue);
    return in;
  }

  // append a key. Keys must be in sorted order. We assume that there is
  // enough room and that delta encoding was used.
  // Returns the new size of the compressed array *in bytes*
  size_t appendToByteArray(uint8_t *in, size_t bytesize, uint32_t previous_key,
                           uint32_t key) {
    uint32_t num_ints = *(uint32_t *)in;
    if (bytesize == 0)
      bytesize = 4;
    uint8_t *bytein = in + bytesize;
    bytein += encodeOneIntegerToByteArray(key - previous_key, bytein);
    *(uint32_t *)in = num_ints + 1;
    return bytein - in;
  }

  // Returns a decompressed value in a delta-encoded array
  // only supported for delta encoded data (TODO)
  uint32_t select(uint32_t *in, size_t index) {
    assert(delta == true);
    uint32_t num_ints = *in;
    in++;
    return (masked_vbyte_select_delta((uint8_t *)in, num_ints, 0, index));
  }

  // Performs a lower bound find in the delta-encoded array.
  // Returns the index
  // length is the size of the compressed input
  // only supported for delta encoded data (TODO)
  size_t findLowerBound(const uint32_t *in, const size_t /*length*/,
                        uint32_t key, uint32_t *presult) {
    assert(delta == true);
    uint32_t num_ints = *in;
    in++;
    return (
        masked_vbyte_search_delta((uint8_t *)in, num_ints, 0, key, presult));
  }
  // insert the key in sorted order. We assume that there is enough room
  // and that delta encoding was used.
  size_t insert(uint32_t *in, const size_t length, uint32_t key) {
    assert(delta);
    size_t bytesize = length * 4;
    bytesize -= paddingBytes(in, length);
    uint8_t *bytein = (uint8_t *)in;
    uint8_t *byteininit = bytein;
    bytein += insert(bytein, bytesize, key);

    while (needPaddingTo32Bits(bytein)) {
      *bytein++ = 0xFF;
    }
    size_t storageinbytes = bytein - byteininit;
    assert((storageinbytes % 4) == 0);
    return storageinbytes / 4;
  }

  // insert the key in sorted order. We assume that there is enough room and
  // that delta encoding was used.
  // the new size (in *byte) is returned
  size_t insertInByteArray(uint8_t *inbyte, const size_t length, uint32_t key) {
    uint32_t prev = 0;
    assert(delta);
    const uint8_t *const endbyte =
        reinterpret_cast<const uint8_t *>(inbyte + length);
    // this assumes that there is a value to be read

    while (endbyte > inbyte + 5) {
      uint8_t c;
      uint32_t v;

      c = inbyte[0];
      v = c & 0x7F;
      if (c < 128) {
        inbyte += 1;
        prev = v + prev;
        if (prev >= key) {
          return length +
                 __insert(inbyte, prev - v, key, prev, endbyte - inbyte);
        }
        continue;
      }

      c = inbyte[1];
      v |= (c & 0x7F) << 7;
      if (c < 128) {
        inbyte += 2;
        prev = v + prev;
        if (prev >= key) {
          return length +
                 __insert(inbyte, prev - v, key, prev, endbyte - inbyte);
        }
        continue;
      }

      c = inbyte[2];
      v |= (c & 0x7F) << 14;
      if (c < 128) {
        inbyte += 3;
        prev = v + prev;
        if (prev >= key) {
          return length +
                 __insert(inbyte, prev - v, key, prev, endbyte - inbyte);
        }
        continue;
      }

      c = inbyte[3];
      v |= (c & 0x7F) << 21;
      if (c < 128) {
        inbyte += 4;
        prev = v + prev;
        if (prev >= key) {
          return length +
                 __insert(inbyte, prev - v, key, prev, endbyte - inbyte);
        }
        continue;
      }

      c = inbyte[4];
      inbyte += 5;
      v |= (c & 0x0F) << 28;
      prev = v + prev;
      if (prev >= key) {
        return length + __insert(inbyte, prev - v, key, prev, endbyte - inbyte);
      }
    }
    while (endbyte > inbyte) {
      unsigned int shift = 0;
      for (uint32_t v = 0; endbyte > inbyte; shift += 7) {
        uint8_t c = *inbyte++;
        v += ((c & 127) << shift);
        if ((c < 128)) {
          prev = v + prev;
          if (prev >= key) {
            return length +
                   __insert(inbyte, prev - v, key, prev, endbyte - inbyte);
          }
          break;
        }
      }
    }
    // if we make it here, then we need to append
    assert(key >= prev);
    return length + encodeOneIntegerToByteArray(key - prev, inbyte);
  }

  std::string name() const {
    if (delta)
      return "MaskedVByteDelta";
    else
      return "MaskedVByte";
  }

private:
  // convenience function used by insert, writes key and newvalue to compressed
  // stream, and return
  // extra storage used, pointer should be right after where nextvalue is right
  // now
  size_t __insert(uint8_t *in, uint32_t previous, uint32_t key,
                  uint32_t nextvalue, size_t followingbytes) {
    assert(nextvalue >= key);
    assert(key >= previous);
    size_t oldstorage = storageCost(nextvalue - previous);
    size_t newstorage =
        storageCost(nextvalue - key) + storageCost(key - previous);
    assert(newstorage >= oldstorage);
    if (newstorage > oldstorage)
      std::memmove(in + newstorage - oldstorage, in, followingbytes);
    uint8_t *newin = in - oldstorage;
    newin += encodeOneIntegerToByteArray(key - previous, newin);
    newin += encodeOneIntegerToByteArray(nextvalue - key, newin);
    assert(newin == in + newstorage - oldstorage);
    return newstorage - oldstorage;
  }

  // how many bytes are required to store this integer?
  int storageCost(uint32_t val) {
    if (val < (1U << 7)) {
      return 1;
    } else if (val < (1U << 14)) {
      return 2;
    } else if (val < (1U << 21)) {
      return 3;
    } else if (val < (1U << 28)) {
      return 4;
    } else {
      return 5;
    }
  }

  template <uint32_t i> uint8_t extract7bits(const uint32_t val) {
    return static_cast<uint8_t>((val >> (7 * i)) & ((1U << 7) - 1));
  }

  template <uint32_t i> uint8_t extract7bitsmaskless(const uint32_t val) {
    return static_cast<uint8_t>((val >> (7 * i)));
  }

  // determine how many padding bytes were used
  int paddingBytes(const uint32_t *in, const size_t length) {
    if (length == 0)
      return 0;
    uint32_t lastword = in[length - 1];
    if (lastword < (1U << 8)) {
      return 3;
    } else if (lastword < (1U << 16)) {
      return 2;
    } else if (lastword < (1U << 24)) {
      return 1;
    }
    return 0;
  }

  // write one compressed integer (without differential coding)
  // returns the number of bytes written
  size_t encodeOneIntegerToByteArray(uint32_t val, uint8_t *bout) {
    const uint8_t *const initbout = bout;
    if (val < (1U << 7)) {
      *bout = val & 0x7F;
      ++bout;
    } else if (val < (1U << 14)) {
      *bout = static_cast<uint8_t>((val & 0x7F) | (1U << 7));
      ++bout;
      *bout = static_cast<uint8_t>(val >> 7);
      ++bout;
    } else if (val < (1U << 21)) {
      *bout = static_cast<uint8_t>((val & 0x7F) | (1U << 7));
      ++bout;
      *bout = static_cast<uint8_t>(((val >> 7) & 0x7F) | (1U << 7));
      ++bout;
      *bout = static_cast<uint8_t>(val >> 14);
      ++bout;
    } else if (val < (1U << 28)) {
      *bout = static_cast<uint8_t>((val & 0x7F) | (1U << 7));
      ++bout;
      *bout = static_cast<uint8_t>(((val >> 7) & 0x7F) | (1U << 7));
      ++bout;
      *bout = static_cast<uint8_t>(((val >> 14) & 0x7F) | (1U << 7));
      ++bout;
      *bout = static_cast<uint8_t>(val >> 21);
      ++bout;
    } else {
      *bout = static_cast<uint8_t>((val & 0x7F) | (1U << 7));
      ++bout;
      *bout = static_cast<uint8_t>(((val >> 7) & 0x7F) | (1U << 7));
      ++bout;
      *bout = static_cast<uint8_t>(((val >> 14) & 0x7F) | (1U << 7));
      ++bout;
      *bout = static_cast<uint8_t>(((val >> 21) & 0x7F) | (1U << 7));
      ++bout;
      *bout = static_cast<uint8_t>(val >> 28);
      ++bout;
    }
    return bout - initbout;
  }
};

// this version differs from MaskedVByte in that it does not write out the
// number of integers compressed as part of a header.
template <bool delta> class HeadlessMaskedVByte : public IntegerCODEC {
public:
  HeadlessMaskedVByte() {}

  void encodeArray(uint32_t *in, const size_t length, uint32_t *out,
                   size_t &nvalue) {
    const uint8_t *const initbout = reinterpret_cast<uint8_t *>(out);
    uint8_t *bout = reinterpret_cast<uint8_t *>(out);
    uint32_t prev = 0;
    for (size_t k = 0; k < length; ++k) {
      const uint32_t val = delta ? (in[k] - prev) : in[k];
      if (delta)
        prev = in[k];
      /**
       * Code below could be shorter. Whether it could be faster
       * depends on your compiler and machine.
       */
      if (val < (1U << 7)) {
        *bout = val & 0x7F;
        ++bout;
      } else if (val < (1U << 14)) {
        *bout = static_cast<uint8_t>((val & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(val >> 7);
        ++bout;
      } else if (val < (1U << 21)) {
        *bout = static_cast<uint8_t>((val & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(((val >> 7) & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(val >> 14);
        ++bout;
      } else if (val < (1U << 28)) {
        *bout = static_cast<uint8_t>((val & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(((val >> 7) & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(((val >> 14) & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(val >> 21);
        ++bout;
      } else {
        *bout = static_cast<uint8_t>((val & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(((val >> 7) & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(((val >> 14) & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(((val >> 21) & 0x7F) | (1U << 7));
        ++bout;
        *bout = static_cast<uint8_t>(val >> 28);
        ++bout;
      }
    }
    while (needPaddingTo32Bits(bout)) {
      *bout++ = 0xFFU;
      ;
    }
    const size_t storageinbytes = bout - initbout;
    nvalue = storageinbytes / 4;
  }

  const uint32_t *decodeArray(const uint32_t *in, const size_t length,
                              uint32_t *out, size_t &nvalue) {
    if (length == 0) {
      nvalue = 0;
      return in; // abort
    }
    const uint8_t *inbyte = reinterpret_cast<const uint8_t *>(in);
    if (delta) {
      uint32_t prev = 0;
      nvalue = masked_vbyte_read_loop_fromcompressedsize_delta(
          inbyte, out, length * 4, prev);
    } else {
      nvalue =
          masked_vbyte_read_loop_fromcompressedsize(inbyte, out, length * 4);
    }

    return in + length;
  }

  std::string name() const {
    if (delta)
      return "HeadlessMaskedVByteDelta";
    else
      return "HeadlessMaskedVByte";
  }

private:
  template <uint32_t i> uint8_t extract7bits(const uint32_t val) {
    return static_cast<uint8_t>((val >> (7 * i)) & ((1U << 7) - 1));
  }

  template <uint32_t i> uint8_t extract7bitsmaskless(const uint32_t val) {
    return static_cast<uint8_t>((val >> (7 * i)));
  }
};

} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_SIMDVARIABLEBYTE_H_ */
