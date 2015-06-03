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
void simdvbyteinit(void);
size_t masked_vbyte_read_loop(const uint8_t* in, uint32_t* out, uint64_t length);
size_t masked_vbyte_read_loop_delta(const uint8_t* in, uint32_t* out, uint64_t length, uint32_t  prev);
size_t masked_vbyte_read_loop_fromcompressedsize(const uint8_t* in, uint32_t* out,
		size_t inputsize);
size_t masked_vbyte_read_loop_fromcompressedsize_delta(const uint8_t* in, uint32_t* out,
		size_t inputsize, uint32_t  prev);
//size_t read_ints(const uint8_t* in, uint32_t* out, int length) ;
//size_t read_ints_delta(const uint8_t* in, uint32_t* out, int length, uint32_t  prev) ;
uint32_t masked_vbyte_select_delta(const uint8_t *in, uint64_t length,
                uint32_t prev, size_t slot);
int masked_vbyte_search_delta(const uint8_t *in, uint64_t length, uint32_t prev,
                uint32_t key, uint32_t *presult);
}


/**
 * This is a SIMD-accelerated version that is byte-by-byte format compatible with
 * AltVariableByte (that is, standard vbyte).
 */
template<bool delta>
class MaskedVByte: public IntegerCODEC {
public:
    MaskedVByte() {
    	simdvbyteinit();
    }

    void encodeArray(uint32_t *in, const size_t length, uint32_t *out,
                     size_t &nvalue) {
        const uint8_t * const initbout = reinterpret_cast<uint8_t *> (out);
        *out = static_cast<uint32_t>(length);
        out++;
        uint8_t * bout = reinterpret_cast<uint8_t *> (out);
        uint32_t prev = 0;
        for (size_t k = 0; k < length; ++k) {

            const uint32_t val = delta ? (in[k] - prev) : in[k];
            if(delta) prev = in[k];
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
        nvalue = storageinbytes/4;
    }

    const uint32_t * decodeArray(const uint32_t *in, const size_t length,
            uint32_t *out, size_t & nvalue) {
        uint32_t num_ints = *in;
        in++;
        if (length == 0) {
            nvalue = 0;
            return in;//abort
        }
        const uint8_t * inbyte = reinterpret_cast<const uint8_t *> (in);
        if(delta) {
        	uint32_t prev = 0;
            inbyte += masked_vbyte_read_loop_delta(inbyte, out, num_ints, prev);
        } else
            inbyte += masked_vbyte_read_loop(inbyte, out, num_ints);
        nvalue = num_ints;
        inbyte = padTo32bits(inbyte);
        return reinterpret_cast<const uint32_t *> (inbyte);
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
        return (masked_vbyte_search_delta((uint8_t *)in, num_ints,
                    0, key, presult));
    }

    std::string name() const {
    	if (delta)
    	            return "MaskedVByteDelta";
    	        else
    	            return "MaskedVByte";
    }

private:
    template<uint32_t i>
    uint8_t extract7bits(const uint32_t val) {
        return static_cast<uint8_t>((val >>(7 * i)) & ((1U << 7) - 1));
    }

    template<uint32_t i>
    uint8_t extract7bitsmaskless(const uint32_t val) {
        return static_cast<uint8_t>((val >>(7 * i)));
    }

};


// this version differs from MaskedVByte in that it does not write out the
// number of integers compressed as part of a header.
template<bool delta>
class HeadlessMaskedVByte: public IntegerCODEC {
public:
	HeadlessMaskedVByte() {
    	simdvbyteinit();
    }

    void encodeArray(uint32_t *in, const size_t length, uint32_t *out,
                     size_t &nvalue) {
    	const uint8_t * const initbout = reinterpret_cast<uint8_t *> (out);
        uint8_t * bout = reinterpret_cast<uint8_t *> (out);
        uint32_t prev = 0;
        for (size_t k = 0; k < length; ++k) {
            const uint32_t val = delta ? (in[k] - prev) : in[k];
            if(delta) prev = in[k];
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
            *bout++ =  0xFFU;;
        }
        const size_t storageinbytes = bout - initbout;
        nvalue = storageinbytes/4;
    }

    const uint32_t * decodeArray(const uint32_t *in, const size_t length,
            uint32_t *out, size_t & nvalue) {
        if (length == 0) {
            nvalue = 0;
            return in;//abort
        }
        const uint8_t * inbyte = reinterpret_cast<const uint8_t *> (in);
        if(delta) {
        	uint32_t prev = 0;
        	nvalue = masked_vbyte_read_loop_fromcompressedsize_delta(inbyte, out, length * 4, prev);
        } else {
        	nvalue = masked_vbyte_read_loop_fromcompressedsize(inbyte, out, length * 4);
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
    template<uint32_t i>
    uint8_t extract7bits(const uint32_t val) {
        return static_cast<uint8_t>((val >>(7 * i)) & ((1U << 7) - 1));
    }

    template<uint32_t i>
    uint8_t extract7bitsmaskless(const uint32_t val) {
        return static_cast<uint8_t>((val >>(7 * i)));
    }

};

} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_SIMDVARIABLEBYTE_H_ */
