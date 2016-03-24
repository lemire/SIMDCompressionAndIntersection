/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef SIMDCompressionAndIntersection_VARIABLEBYTE_H_
#define SIMDCompressionAndIntersection_VARIABLEBYTE_H_
#include "common.h"
#include "codecs.h"
#include "util.h"

namespace SIMDCompressionLib {

/***
 * VariableByte and VByte are basically identical, except that
 * one uses 0..0..0..1 to indicate 4 whereas the other one uses 1..1..1..0.
 * The latter is maybe more common.
 */

template <bool delta> class VariableByte : public IntegerCODEC {
public:
  void encodeArray(uint32_t *in, const size_t length, uint32_t *out,
                   size_t &nvalue) {
    uint8_t *bout = reinterpret_cast<uint8_t *>(out);
    const uint8_t *const initbout = reinterpret_cast<uint8_t *>(out);
    size_t bytenvalue = nvalue * sizeof(uint32_t);
    encodeToByteArray(in, length, bout, bytenvalue);
    bout += bytenvalue;
    while (needPaddingTo32Bits(bout)) {
      *bout++ = 0;
    }
    const size_t storageinbytes = bout - initbout;
    assert((storageinbytes % 4) == 0);
    nvalue = storageinbytes / 4;
  }

  // write one compressed integer (without differential coding)
  // returns the number of bytes written
  size_t encodeOneIntegerToByteArray(uint32_t val, uint8_t *bout) {
    const uint8_t *const initbout = bout;
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
    return bout - initbout;
  }

  void encodeToByteArray(uint32_t *in, const size_t length, uint8_t *bout,
                         size_t &nvalue) {
    const uint8_t *const initbout = bout;
    uint32_t prev = 0;
    for (size_t k = 0; k < length; ++k) {
      const uint32_t val = delta ? in[k] - prev : in[k];
      if (delta)
        prev = in[k];
      /**
       * Code below could be shorter. Whether it could be faster
       * depends on your compiler and machine.
       */
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
    nvalue = bout - initbout;
  }

  const uint32_t *decodeArray(const uint32_t *in, const size_t length,
                              uint32_t *out, size_t &nvalue) {
    decodeFromByteArray((const uint8_t *)in, length * sizeof(uint32_t), out,
                        nvalue);
    return in + length;
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

  const uint8_t *decodeFromByteArray(const uint8_t *inbyte, const size_t length,
                                     uint32_t *out, size_t &nvalue) {
    uint32_t prev = 0;
    if (length == 0) {
      nvalue = 0;
      return inbyte; // abort
    }
    const uint8_t *const endbyte = inbyte + length;
    const uint32_t *const initout(out);
    // this assumes that there is a value to be read

    while (endbyte > inbyte + 5) {
      if (delta) {
        uint8_t c;
        uint32_t v;

        c = inbyte[0];
        v = c & 0x7F;
        if (c >= 128) {
          inbyte += 1;
          *out++ = (prev = v + prev);
          continue;
        }

        c = inbyte[1];
        v |= (c & 0x7F) << 7;
        if (c >= 128) {
          inbyte += 2;
          *out++ = (prev = v + prev);
          continue;
        }

        c = inbyte[2];
        v |= (c & 0x7F) << 14;
        if (c >= 128) {
          inbyte += 3;
          *out++ = (prev = v + prev);
          continue;
        }

        c = inbyte[3];
        v |= (c & 0x7F) << 21;
        if (c >= 128) {
          inbyte += 4;
          *out++ = (prev = v + prev);
          continue;
        }

        c = inbyte[4];
        inbyte += 5;
        v |= (c & 0x0F) << 28;
        *out++ = (prev = v + prev);
      } else {
        uint8_t c;
        uint32_t v;

        c = inbyte[0];
        v = c & 0x7F;
        if (c >= 128) {
          inbyte += 1;
          *out++ = v;
          continue;
        }

        c = inbyte[1];
        v |= (c & 0x7F) << 7;
        if (c >= 128) {
          inbyte += 2;
          *out++ = v;
          continue;
        }

        c = inbyte[2];
        v |= (c & 0x7F) << 14;
        if (c >= 128) {
          inbyte += 3;
          *out++ = v;
          continue;
        }

        c = inbyte[3];
        v |= (c & 0x7F) << 21;
        if (c >= 128) {
          inbyte += 4;
          *out++ = v;
          continue;
        }

        c = inbyte[4];
        inbyte += 5;
        v |= (c & 0x0F) << 28;
        *out++ = v;
      }
    }
    while (endbyte > inbyte) {
      unsigned int shift = 0;
      for (uint32_t v = 0; endbyte > inbyte; shift += 7) {
        uint8_t c = *inbyte++;
        v += ((c & 127) << shift);
        if ((c & 128)) {
          *out++ = delta ? (prev = v + prev) : v;
          break;
        }
      }
    }
    nvalue = out - initout;
    return inbyte;
  }

  // Performs a lower bound find in the encoded array.
  // length is the size of the compressed input
  // Returns the index
  size_t findLowerBound(const uint32_t *in, const size_t length, uint32_t key,
                        uint32_t *presult) {
    uint32_t prev = 0;
    if (length == 0) {
      return 0; // abort
    }
    const uint8_t *inbyte = reinterpret_cast<const uint8_t *>(in);
    const uint8_t *const endbyte =
        reinterpret_cast<const uint8_t *>(in + length);
    size_t i = 0;
    // this assumes that there is a value to be read

    while (endbyte > inbyte + 5) {
      if (delta) {
        uint8_t c;
        uint32_t v;

        c = inbyte[0];
        v = c & 0x7F;
        if (c >= 128) {
          inbyte += 1;
          prev = v + prev;
          if (prev >= key) {
            *presult = prev;
            return i;
          }
          i++;
          continue;
        }

        c = inbyte[1];
        v |= (c & 0x7F) << 7;
        if (c >= 128) {
          inbyte += 2;
          prev = v + prev;
          if (prev >= key) {
            *presult = prev;
            return i;
          }
          i++;
          continue;
        }

        c = inbyte[2];
        v |= (c & 0x7F) << 14;
        if (c >= 128) {
          inbyte += 3;
          prev = v + prev;
          if (prev >= key) {
            *presult = prev;
            return i;
          }
          i++;
          continue;
        }

        c = inbyte[3];
        v |= (c & 0x7F) << 21;
        if (c >= 128) {
          inbyte += 4;
          prev = v + prev;
          if (prev >= key) {
            *presult = prev;
            return i;
          }
          i++;
          continue;
        }

        c = inbyte[4];
        inbyte += 5;
        v |= (c & 0x0F) << 28;
        prev = v + prev;
        if (prev >= key) {
          *presult = prev;
          return i;
        }
        i++;
      } else {
        uint8_t c;
        uint32_t v;

        c = inbyte[0];
        v = c & 0x7F;
        if (c >= 128) {
          inbyte += 1;
          if (v >= key) {
            *presult = v;
            return i;
          }
          i++;
          continue;
        }

        c = inbyte[1];
        v |= (c & 0x7F) << 7;
        if (c >= 128) {
          inbyte += 2;
          if (v >= key) {
            *presult = v;
            return i;
          }
          i++;
          continue;
        }

        c = inbyte[2];
        v |= (c & 0x7F) << 14;
        if (c >= 128) {
          inbyte += 3;
          if (v >= key) {
            *presult = v;
            return i;
          }
          i++;
          continue;
        }

        c = inbyte[3];
        v |= (c & 0x7F) << 21;
        if (c >= 128) {
          inbyte += 4;
          if (v >= key) {
            *presult = v;
            return i;
          }
          i++;
          continue;
        }

        c = inbyte[4];
        inbyte += 5;
        v |= (c & 0x0F) << 28;
        if (v >= key) {
          *presult = v;
          return i;
        }
        i++;
      }
    }
    while (endbyte > inbyte) {
      unsigned int shift = 0;
      for (uint32_t v = 0; endbyte > inbyte; shift += 7) {
        uint8_t c = *inbyte++;
        v += ((c & 127) << shift);
        if ((c & 128)) {
          if (delta) {
            prev = v + prev;
            if (prev >= key) {
              *presult = prev;
              return i;
            }
          } else {
            if (v >= key) {
              *presult = v;
              return i;
            }
          }
          i++;
          break;
        }
      }
    }
    return i;
  }

  // append a key. Keys must be in sorted order. We assume that there is
  // enough room and that delta encoding was used.
  // Returns the new size of the compressed array *in bytes*
  size_t appendToByteArray(uint8_t *in, const size_t bytesize,
                           uint32_t previous_key, uint32_t key) {
    assert(delta); // no performance impact expected.
    uint8_t *byteininit = (uint8_t *)in;
    uint8_t *bytein = (uint8_t *)in + bytesize;
    bytein += encodeOneIntegerToByteArray(key - previous_key, bytein);
    return bytein - byteininit;
  }

  // insert the key in sorted order. We assume that there is enough room and
  // that delta encoding was used.
  size_t insert(uint32_t *in, const size_t length, uint32_t key) {
    size_t bytesize = length * 4;
    bytesize -= paddingBytes(in, length);
    uint8_t *bytein = (uint8_t *)in;
    uint8_t *byteininit = bytein;
    size_t bl = insertInByteArray(bytein, bytesize, key);
    bytein += bl;

    while (needPaddingTo32Bits(bytein)) {
      *bytein++ = 0;
    }
    size_t storageinbytes = bytein - byteininit;
    assert((storageinbytes % 4) == 0);
    return storageinbytes / 4;
  }

  // insert the key in sorted order. We assume that there is enough room and
  // that delta encoding was used.
  // the new size is returned
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
      if (c >= 128) {
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
      if (c >= 128) {
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
      if (c >= 128) {
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
      if (c >= 128) {
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
        if ((c & 128)) {
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

  // Returns a decompressed value in an encoded array
  // could be greatly optimized in the non-differential coding case: currently
  // just for delta coding
  uint32_t select(uint32_t *in, size_t index) {
    assert(delta);
    uint32_t prev = 0;
    size_t i = 0;
    const uint8_t *inbyte = reinterpret_cast<const uint8_t *>(in);
    while (i <= index) {
      uint8_t c;
      uint32_t v;

      c = inbyte[0];
      v = c & 0x7F;
      if (c >= 128) {
        inbyte += 1;
        prev = v + prev;
        i++;
        continue;
      }

      c = inbyte[1];
      v |= (c & 0x7F) << 7;
      if (c >= 128) {
        inbyte += 2;
        prev = v + prev;
        i++;
        continue;
      }

      c = inbyte[2];
      v |= (c & 0x7F) << 14;
      if (c >= 128) {
        inbyte += 3;
        prev = v + prev;
        i++;
        continue;
      }

      c = inbyte[3];
      v |= (c & 0x7F) << 21;
      if (c >= 128) {
        inbyte += 4;
        prev = v + prev;
        i++;
        continue;
      }

      c = inbyte[4];
      inbyte += 5;
      v |= (c & 0x0F) << 28;
      prev = v + prev;
      i++;
    }
    assert(i == index + 1);
    return prev;
  }

  string name() const {
    if (delta)
      return "VariableByteDelta";
    else
      return "VariableByte";
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

  template <uint32_t i> uint8_t extract7bits(const uint32_t val) {
    return static_cast<uint8_t>((val >> (7 * i)) & ((1U << 7) - 1));
  }

  template <uint32_t i> uint8_t extract7bitsmaskless(const uint32_t val) {
    return static_cast<uint8_t>((val >> (7 * i)));
  }
};

template <bool delta> class VByte : public IntegerCODEC {
public:
  void encodeArray(uint32_t *in, const size_t length, uint32_t *out,
                   size_t &nvalue) {
    uint8_t *bout = reinterpret_cast<uint8_t *>(out);
    const uint8_t *const initbout = reinterpret_cast<uint8_t *>(out);
    size_t bytenvalue = nvalue * sizeof(uint32_t);
    encodeToByteArray(in, length, bout, bytenvalue);
    bout += bytenvalue;
    while (needPaddingTo32Bits(bout)) {
      *bout++ = 0xFF;
    }
    const size_t storageinbytes = bout - initbout;
    assert((storageinbytes % 4) == 0);
    nvalue = storageinbytes / 4;
  }

  void encodeToByteArray(uint32_t *in, const size_t length, uint8_t *bout,
                         size_t &nvalue) {
    uint32_t prev = 0;
    const uint8_t *const initbout = bout;
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
    nvalue = bout - initbout;
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

  // determine how many padding bytes were used
  int paddingBytes(const uint32_t *in, const size_t length) {
    if (length == 0)
      return 0;
    uint32_t lastword = in[length - 1];
    lastword = ~lastword;
    if (lastword < (1U << 8)) {
      return 3;
    } else if (lastword < (1U << 16)) {
      return 2;
    } else if (lastword < (1U << 24)) {
      return 1;
    }
    return 0;
  }

  const uint32_t *decodeArray(const uint32_t *in, const size_t length,
                              uint32_t *out, size_t &nvalue) {
    decodeFromByteArray((const uint8_t *)in, length * sizeof(uint32_t), out,
                        nvalue);
    return in + length;
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

  const uint8_t *decodeFromByteArray(const uint8_t *inbyte, const size_t length,
                                     uint32_t *out, size_t &nvalue) {
    uint32_t prev = 0;
    if (length == 0) {
      nvalue = 0;
      return inbyte; // abort
    }
    const uint8_t *const endbyte = inbyte + length;
    const uint32_t *const initout(out);
    // this assumes that there is a value to be read

    while (endbyte > inbyte + 5) {
      if (delta) {
        uint8_t c;
        uint32_t v;

        c = inbyte[0];
        v = c & 0x7F;
        if (c < 128) {
          inbyte += 1;
          *out++ = (prev = v + prev);
          continue;
        }

        c = inbyte[1];
        v |= (c & 0x7F) << 7;
        if (c < 128) {
          inbyte += 2;
          *out++ = (prev = v + prev);
          continue;
        }

        c = inbyte[2];
        v |= (c & 0x7F) << 14;
        if (c < 128) {
          inbyte += 3;
          *out++ = (prev = v + prev);
          continue;
        }

        c = inbyte[3];
        v |= (c & 0x7F) << 21;
        if (c < 128) {
          inbyte += 4;
          *out++ = (prev = v + prev);
          continue;
        }

        c = inbyte[4];
        inbyte += 5;
        v |= (c & 0x0F) << 28;
        *out++ = (prev = v + prev);
      } else {
        uint8_t c;
        uint32_t v;

        c = inbyte[0];
        v = c & 0x7F;
        if (c < 128) {
          inbyte += 1;
          *out++ = v;
          continue;
        }

        c = inbyte[1];
        v |= (c & 0x7F) << 7;
        if (c < 128) {
          inbyte += 2;
          *out++ = v;
          continue;
        }

        c = inbyte[2];
        v |= (c & 0x7F) << 14;
        if (c < 128) {
          inbyte += 3;
          *out++ = v;
          continue;
        }

        c = inbyte[3];
        v |= (c & 0x7F) << 21;
        if (c < 128) {
          inbyte += 4;
          *out++ = v;
          continue;
        }

        c = inbyte[4];
        inbyte += 5;
        v |= (c & 0x0F) << 28;
        *out++ = v;
      }
    }
    while (endbyte > inbyte) {
      unsigned int shift = 0;
      for (uint32_t v = 0; endbyte > inbyte; shift += 7) {
        uint8_t c = *inbyte++;
        v += ((c & 127) << shift);
        if ((c < 128)) {
          *out++ = delta ? (prev = v + prev) : v;
          break;
        }
      }
    }
    nvalue = out - initout;
    return inbyte;
  }

  // Performs a lower bound find in the encoded array.
  // length is the size of the compressed input
  // Returns the index and the value found (presult)
  size_t findLowerBound(const uint32_t *in, const size_t length, uint32_t key,
                        uint32_t *presult) {
    uint32_t prev = 0;
    if (length == 0) {
      return 0; // abort
    }
    size_t i = 0;
    const uint8_t *inbyte = reinterpret_cast<const uint8_t *>(in);
    const uint8_t *const endbyte =
        reinterpret_cast<const uint8_t *>(in + length);
    // this assumes that there is a value to be read

    while (endbyte > inbyte + 5) {
      if (delta) {
        uint8_t c;
        uint32_t v;

        c = inbyte[0];
        v = c & 0x7F;
        if (c < 128) {
          inbyte += 1;
          prev = v + prev;
          if (prev >= key) {
            *presult = prev;
            return i;
          }
          i++;
          continue;
        }

        c = inbyte[1];
        v |= (c & 0x7F) << 7;
        if (c < 128) {
          inbyte += 2;
          prev = v + prev;
          if (prev >= key) {
            *presult = prev;
            return i;
          }
          i++;
          continue;
        }

        c = inbyte[2];
        v |= (c & 0x7F) << 14;
        if (c < 128) {
          inbyte += 3;
          prev = v + prev;
          if (prev >= key) {
            *presult = prev;
            return i;
          }
          i++;
          continue;
        }

        c = inbyte[3];
        v |= (c & 0x7F) << 21;
        if (c < 128) {
          inbyte += 4;
          prev = v + prev;
          if (prev >= key) {
            *presult = prev;
            return i;
          }
          i++;
          continue;
        }

        c = inbyte[4];
        inbyte += 5;
        v |= (c & 0x0F) << 28;
        prev = v + prev;
        if (prev >= key) {
          *presult = prev;
          return i;
        }
        i++;
      } else {
        uint8_t c;
        uint32_t v;

        c = inbyte[0];
        v = c & 0x7F;
        if (c < 128) {
          inbyte += 1;
          if (v >= key) {
            *presult = v;
            return i;
          }
          i++;
          continue;
        }

        c = inbyte[1];
        v |= (c & 0x7F) << 7;
        if (c < 128) {
          inbyte += 2;
          if (v >= key) {
            *presult = v;
            return i;
          }
          i++;
          continue;
        }

        c = inbyte[2];
        v |= (c & 0x7F) << 14;
        if (c < 128) {
          inbyte += 3;
          if (v >= key) {
            *presult = v;
            return i;
          }
          i++;
          continue;
        }

        c = inbyte[3];
        v |= (c & 0x7F) << 21;
        if (c < 128) {
          inbyte += 4;
          if (v >= key) {
            *presult = v;
            return i;
          }
          i++;
          continue;
        }

        c = inbyte[4];
        inbyte += 5;
        v |= (c & 0x0F) << 28;
        if (v >= key) {
          *presult = v;
          return i;
        }
        i++;
      }
    }
    while (endbyte > inbyte) {
      unsigned int shift = 0;
      for (uint32_t v = 0; endbyte > inbyte; shift += 7) {
        uint8_t c = *inbyte++;
        v += ((c & 127) << shift);
        if ((c < 128)) {
          if (delta) {
            prev = v + prev;
            if (prev >= key) {
              *presult = prev;
              return i;
            }
          } else {
            if (v >= key) {
              *presult = v;
              return i;
            }
          }
          i++;
          break;
        }
      }
    }
    return i;
  }

  // append a key. Keys must be in sorted order. We assume that there is
  // enough room and that delta encoding was used.
  /*size_t append(uint32_t *in, const size_t length, uint32_t previous_key,
                  uint32_t key) {
      size_t bytesize = (length * 4) - paddingBytes(in, length);
      uint8_t *byteininit = (uint8_t *)in;
      uint8_t *bytein = (uint8_t *)in + bytesize;
      bytein += encodeOneIntegerToByteArray(key - previous_key, bytein);
      while (needPaddingTo32Bits(bytein)) {
          *bytein++ = 0xFF;
      }
      size_t storageinbytes = bytein - byteininit;
      assert((storageinbytes % 4) == 0);
      return storageinbytes / 4;
  }*/

  // append a key. Keys must be in sorted order. We assume that there is
  // enough room and that delta encoding was used.
  // Returns the new size of the compressed array *in bytes*
  size_t appendToByteArray(uint8_t *in, const size_t bytesize,
                           uint32_t previous_key, uint32_t key) {
    assert(delta); // no performance impact expected.
    uint8_t *byteininit = (uint8_t *)in;
    uint8_t *bytein = (uint8_t *)in + bytesize;
    bytein += encodeOneIntegerToByteArray(key - previous_key, bytein);
    return bytein - byteininit;
  }

  // insert the key in sorted order. We assume that there is enough room
  // and that delta encoding was used.
  size_t insert(uint32_t *in, const size_t length, uint32_t key) {
    assert(delta);
    size_t bytesize = length * 4;
    bytesize -= paddingBytes(in, length);
    uint8_t *bytein = (uint8_t *)in;
    uint8_t *byteininit = bytein;
    bytein += insertInByteArray(bytein, bytesize, key);

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

  // Returns a decompressed value in an encoded array
  // could be greatly optimized in the non-differential coding case: currently
  // just for delta coding
  uint32_t select(uint32_t *in, size_t index) {
    assert(delta);
    uint32_t prev = 0;
    size_t i = 0;
    const uint8_t *inbyte = reinterpret_cast<const uint8_t *>(in);

    while (i <= index) {
      uint8_t c;
      uint32_t v;

      c = inbyte[0];
      v = c & 0x7F;
      if (c < 128) {
        inbyte += 1;
        prev = v + prev;
        ++i;
        continue;
      }

      c = inbyte[1];
      v |= (c & 0x7F) << 7;
      if (c < 128) {
        inbyte += 2;
        prev = v + prev;
        ++i;
        continue;
      }

      c = inbyte[2];
      v |= (c & 0x7F) << 14;
      if (c < 128) {
        inbyte += 3;
        prev = v + prev;
        ++i;
        continue;
      }

      c = inbyte[3];
      v |= (c & 0x7F) << 21;
      if (c < 128) {
        inbyte += 4;
        prev = v + prev;
        ++i;
        continue;
      }

      c = inbyte[4];
      inbyte += 5;
      v |= (c & 0x0F) << 28;
      prev = v + prev;
      ++i;
    }
    assert(i == index + 1);
    return prev;
  }

  std::string name() const {
    if (delta)
      return "VByteDelta";
    else
      return "VByte";
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

  template <uint32_t i> uint8_t extract7bits(const uint32_t val) {
    return static_cast<uint8_t>((val >> (7 * i)) & ((1U << 7) - 1));
  }

  template <uint32_t i> uint8_t extract7bitsmaskless(const uint32_t val) {
    return static_cast<uint8_t>((val >> (7 * i)));
  }
};

} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_VARIABLEBYTE_H_ */
