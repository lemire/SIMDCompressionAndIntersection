/*
 * varintgb.h
 *
 *  Created on: Jul 25, 2013
 *      Author: lemire
 */

#ifndef SIMDCompressionAndIntersection_VARINTGB_H_
#define SIMDCompressionAndIntersection_VARINTGB_H_

#include "common.h"
#include "codecs.h"
#include "variablebyte.h"

namespace SIMDCompressionLib {

using namespace std;




/**
 * Group VarInt.
 *
 * Implemented and designed by D. Lemire based on a talk by Jeff Dean (Google),
 * optimized by N. Kurz.
 */

template<bool delta=false>
class VarIntGB: public IntegerCODEC {
public:

    void encodeArray(uint32_t *in, const size_t length, uint32_t *out,
            size_t &nvalue) {
        uint32_t prev = 0; // for delta

        uint8_t * bout = reinterpret_cast<uint8_t *> (out);
        const uint8_t * const initbout = reinterpret_cast<uint8_t *> (out);
        *out = static_cast<uint32_t>(length);
        bout += 4;

        size_t k = 0;
        for (; k + 3 < length;) {
            uint8_t * keyp = bout++;
            *keyp = 0;
            for (int j = 0; j < 8; j += 2, ++k) {
                const uint32_t val = delta ? in[k] - prev : in[k];
                if (delta)
                    prev = in[k];
                if (val < (1U << 8)) {
                    *bout++ = static_cast<uint8_t> (val);
                } else if (val < (1U << 16)) {
                    *bout++ = static_cast<uint8_t> (val);
                    *bout++ = static_cast<uint8_t> (val >> 8);
                    *keyp |= static_cast<uint8_t>(1 << j);
                } else if (val < (1U << 24)) {
                    *bout++ = static_cast<uint8_t> (val);
                    *bout++ = static_cast<uint8_t> (val >> 8);
                    *bout++ = static_cast<uint8_t> (val >> 16);
                    *keyp |= static_cast<uint8_t>(2 << j);
                } else {
                    // the compiler will do the right thing
                    *reinterpret_cast<uint32_t *> (bout) = val;
                    bout += 4;
                    *keyp |= static_cast<uint8_t>(3 << j);
                }
            }
        }
        if (k < length) {
            uint8_t * keyp = bout++;
            *keyp = 0;
            for (int j = 0; k < length && j < 8; j += 2, ++k) {
                const uint32_t val = delta ? in[k] - prev : in[k];
                if (delta) prev = in[k];
                if (val < (1U << 8)) {
                    *bout++ = static_cast<uint8_t> (val);
                } else if (val < (1U << 16)) {
                    *bout++ = static_cast<uint8_t> (val);
                    *bout++ = static_cast<uint8_t> (val >> 8);
                    *keyp |= static_cast<uint8_t>(1 << j);
                } else if (val < (1U << 24)) {
                    *bout++ = static_cast<uint8_t> (val);
                    *bout++ = static_cast<uint8_t> (val >> 8);
                    *bout++ = static_cast<uint8_t> (val >> 16);
                    *keyp |= static_cast<uint8_t>(2 << j);
                } else {
                    // the compiler will do the right thing
                    *reinterpret_cast<uint32_t *> (bout) = val;
                    bout += 4;
                    *keyp |= static_cast<uint8_t>(3 << j);
                }
            }
        }
        while (needPaddingTo32Bits(bout)) {
            *bout++ = 0;
        }
        const size_t storageinbytes = bout - initbout;
        assert((storageinbytes % 4) == 0);
        nvalue = storageinbytes / 4;
    }

    const uint32_t * decodeArray(const uint32_t *in, const size_t length,
            uint32_t *out, size_t & nvalue) {
        uint32_t prev = 0; // for delta

        const uint8_t * inbyte = reinterpret_cast<const uint8_t *> (in);
        nvalue = *in;
        inbyte += 4;

        const uint8_t * const endbyte = reinterpret_cast<const uint8_t *> (in
                + length);
        const uint32_t * const endout(out + nvalue);
        uint32_t val;

        while (endbyte > inbyte + 1 + 4 * 4) {
        	inbyte = delta ? decodeGroupVarIntDelta(inbyte, &prev, out) :
        			decodeGroupVarInt(inbyte, out);
            out+=4;
        }
        while (endbyte > inbyte) {
            uint8_t key = *inbyte++;
            for (int k = 0; out < endout and k < 4; k++) {
                const uint32_t howmanybyte = key & 3;
                key=static_cast<uint8_t>(key>>2);
                val = static_cast<uint32_t> (*inbyte++);
                if (howmanybyte >= 1) {
                    val |= (static_cast<uint32_t> (*inbyte++) << 8) ;
                    if (howmanybyte >= 2) {
                        val |= (static_cast<uint32_t> (*inbyte++) << 16) ;
                        if (howmanybyte >= 3) {
                            val |= (static_cast<uint32_t> (*inbyte++) << 24);
                        }
                    }
                }
                prev = (delta ? prev : 0) + val;
                *out++ = prev;
            }
            assert(inbyte <= endbyte);
        }
        inbyte = padTo32bits(inbyte);
        return reinterpret_cast<const uint32_t *> (inbyte);
    }

    // Performs a lower bound find in the delta-encoded array.
    // Returns the index
    int findLowerBoundDelta(const uint32_t *in, const size_t length,
                    uint32_t key, uint32_t *presult) {
        assert(delta == true);
        const uint8_t *inbyte = reinterpret_cast<const uint8_t *> (in);
        uint32_t out[4] = {0};
        int i = 0;
        uint32_t initial = 0;
        uint32_t nvalue = *in;
        inbyte += 4; // skip nvalue

        const uint8_t *const endbyte = reinterpret_cast<const uint8_t *> (in
                    + length);

        while (endbyte > inbyte + 1 + 4 * 4) {
            inbyte = decodeGroupVarIntDelta(inbyte, &initial, out);
            if (key <= out[3]) {
                if (key <= out[0]) {
                    *presult = out[0];
                    return (i + 0);
                }
                if (key <= out[1]) {
                    *presult = out[1];
                    return (i + 1);
                }
                if (key <= out[2]) {
                    *presult = out[2];
                    return (i + 2);
                }
                *presult = out[3];
                return (i + 3);
            }
            i += 4;
        }

        while (endbyte > inbyte && nvalue > 0) {
            uint32_t *p = &out[0];
            nvalue = nvalue - 1 - i;
            inbyte = decodeSingleVarintDelta(inbyte, &initial, &p, &nvalue);
            assert(inbyte <= endbyte);
            if (key <= out[0]) {
                *presult = out[0];
                return (i + 0);
            }
            if (nvalue > 0 && key <= out[1]) {
                *presult = out[1];
                return (i + 1);
            }
            if (nvalue > 1 && key <= out[2]) {
                *presult = out[2];
                return (i + 2);
            }
            if (nvalue > 2 && key <= out[3]) {
                *presult = out[3];
                return (i + 3);
            }
            i += nvalue;
          }
          *presult = key + 1;
          return (i);
      }

      // Returns a decompressed value in a delta-encoded array
      uint32_t selectDelta(uint32_t *in, const size_t length, int index) {
        assert(delta == true);
        assert(index < length);

        const uint8_t *inbyte = reinterpret_cast<const uint8_t *> (in);
        uint32_t out[4];
        int i = 0;
        uint32_t initial = 0;
        uint32_t nvalue = *in;
        inbyte += 4; // skip nvalue

        const uint8_t *const endbyte = reinterpret_cast<const uint8_t *> (in
                  + length);

        while (endbyte > inbyte + 1 + 4 * 4) {
            inbyte = decodeGroupVarIntDelta(inbyte, &initial, out);
            i += 4;
            if (i > index)
                return (out[index - (i - 4)]);
        }
        while (endbyte > inbyte) {
            uint32_t *p = &out[0];
            nvalue = nvalue - 1 - i;
            inbyte = decodeSingleVarintDelta(inbyte, &initial, &p, &nvalue);
            assert(inbyte <= endbyte);
            if (index == i)
                return (out[0]);
            if (nvalue > 1 && index == i + 1)
                return (out[1]);
            if (nvalue > 2 && index == i + 2)
                return (out[2]);
            if (nvalue > 3 && index == i + 3)
                return (out[3]);
            i += nvalue;
        }
        return (0);
    }

    const uint32_t mask[4] = { 0xFF, 0xFFFF, 0xFFFFFF, 0xFFFFFFFF };

    const uint8_t* decodeGroupVarInt(const uint8_t* in, uint32_t* out) {
	       const uint32_t sel = *in++;
    	   if(sel == 0) {
    	       out[0] = static_cast<uint32_t> (in[0]);
    	       out[1] = static_cast<uint32_t> (in[1]);
    	       out[2] = static_cast<uint32_t> (in[2]);
    	       out[3] = static_cast<uint32_t> (in[3]);
    	       return in + 4;
    	    }
    	    const uint32_t sel1 = (sel & 3);
    	    *out++ = *((uint32_t*)(in)) & mask[sel1];
    	    in += sel1 + 1;
    	    const uint32_t sel2 = ((sel >> 2) & 3);
    	    *out++ = *((uint32_t*)(in)) & mask[sel2];
    	    in += sel2 + 1;
    	    const uint32_t sel3 = ((sel >> 4) & 3);
    	    *out++ = *((uint32_t*)(in)) & mask[sel3];
    	    in += sel3 + 1;
    	    const uint32_t sel4 = (sel >> 6);
    	    *out++ = *((uint32_t*)(in)) & mask[sel4];
    	    in += sel4 + 1;
    	    return in;
    }

    const uint8_t* decodeGroupVarIntDelta(const uint8_t* in, uint32_t * val, uint32_t* out) {
    	    const uint32_t sel = *in++;
    	    if(sel == 0) {
    	    	out[0] = (* val += static_cast<uint32_t> (in[0]));
    	    	out[1] = (* val += static_cast<uint32_t> (in[1]));
    	    	out[2] = (* val += static_cast<uint32_t> (in[2]));
    	    	out[3] = (* val += static_cast<uint32_t> (in[3]));
    	    	return in + 4;
    	    }
    	    const uint32_t sel1 = (sel & 3);
    	    *val += *((uint32_t*)(in)) & mask[sel1];
    	    *out++ = *val;
    	    in += sel1 + 1;
    	    const uint32_t sel2 = ((sel >> 2) & 3);
    	    *val += *((uint32_t*)(in)) & mask[sel2];
    	    *out++ = *val;
    	    in += sel2 + 1;
    	    const uint32_t sel3 = ((sel >> 4) & 3);
    	    *val += *((uint32_t*)(in)) & mask[sel3];
    	    *out++ = *val;
    	    in += sel3 + 1;
    	    const uint32_t sel4 = (sel >> 6);
    	    *val += *((uint32_t*)(in)) & mask[sel4];
    	    *out++ = *val;
    	    in += sel4 + 1;
      	    return in;
    }

    const uint8_t *decodeSingleVarintDelta(const uint8_t *inbyte,
                    uint32_t *initial, uint32_t **out, uint32_t *count) {
        uint32_t val;
        uint32_t k, key = *inbyte++;
        for (k = 0; k < *count && k < 4; k++) {
            const uint32_t howmanybyte = key & 3;
            key = static_cast<uint8_t>(key>>2);
            val = static_cast<uint32_t> (*inbyte++);
            if (howmanybyte >= 1) {
                val |= (static_cast<uint32_t> (*inbyte++) << 8) ;
                if (howmanybyte >= 2) {
                    val |= (static_cast<uint32_t> (*inbyte++) << 16) ;
                    if (howmanybyte >= 3) {
                        val |= (static_cast<uint32_t> (*inbyte++) << 24);
                    }
                }
            }
          *initial += val;
          **out = *initial;
          (*out)++;
      }
      *count = k;
      return (inbyte);
    }

    string name() const {
        if(delta)
            return "varintgbdelta";
        else
            return "varintgb";
    }

};









} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_VARINTGB_H_ */
