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
        uint8_t * bout = reinterpret_cast<uint8_t *> (out);
        const uint8_t * const initbout = reinterpret_cast<uint8_t *> (out);
        *out = static_cast<uint32_t>(length);
        bout += 4;
        bout = headlessEncode(in,length,0,bout);


        while (needPaddingTo32Bits(bout)) {
            *bout++ = 0;
        }
        const size_t storageinbytes = bout - initbout;
        assert((storageinbytes % 4) == 0);
        nvalue = storageinbytes / 4;
    }

    const uint32_t * decodeArray(const uint32_t *in, const size_t length,
                                 uint32_t *out, size_t & nvalue) {
		if(length == 0) {
			nvalue = 0;
			return in;
		}
        const uint8_t * inbyte = reinterpret_cast<const uint8_t *> (in);
        nvalue = *in;
        inbyte += 4;
        size_t decoded  = headlessDecode(inbyte, (length - 1 )* sizeof(uint32_t),0,out,nvalue);
        assert(decoded == nvalue);
        return in + length;
    }



    // insert the key in sorted order. We assume that there is enough room and that delta encoding was used.
    size_t insert(uint32_t *in, const size_t length, uint32_t key) {
    	size_t bytesize = length * 4;
    	uint8_t * bytein = (uint8_t *) in;
    	uint8_t * byteininit = bytein;
    	size_t bl = insert(bytein, bytesize,  key);
		bytein += bl;

        while (needPaddingTo32Bits(bytein)) {
        	*bytein++ = 0;
        }
        size_t storageinbytes = bytein - byteininit;
        assert((storageinbytes % 4) == 0);
        return storageinbytes / 4;
    }

    // insert the key in sorted order. We assume that there is enough room and that delta encoding was used.
    // the new size is returned
	size_t insert(uint8_t *inbyte, size_t length, uint32_t key) {
		if(length == 0) {
			*((uint32_t *) inbyte) =  0;
			length = 4;
		}
		uint8_t * finalinbyte = inbyte + length;
		const uint8_t * const initinbyte = inbyte;
		uint32_t nvalue = *((uint32_t *) inbyte);
		*((uint32_t *) inbyte) =  nvalue + 1; // incrementing
		inbyte += 4; // skip nvalue
		assert(delta);
		uint32_t initial = 0;
		size_t i = 0;
		while (i + 3 < nvalue) {
			uint32_t copyinitial = initial;
			const uint8_t * const newinbyte = scanGroupVarIntDelta(inbyte, &copyinitial);
			if (copyinitial >= key) {
				goto finish;
			}
			inbyte = (uint8_t *) newinbyte;
			initial = copyinitial;
			i += 4;
		}
		finish:
		assert(finalinbyte >= inbyte);
		assert(i<=nvalue);
		// we are using brute force here, by decoding everything to a buffer and then reencoding.
		uint32_t * tmpbuffer = new uint32_t[nvalue - i + 1];
		assert(tmpbuffer);
		tmpbuffer[0] = key;
		if (nvalue != i) {
			size_t decoded = headlessDecode(inbyte, finalinbyte - inbyte,initial,
					tmpbuffer + 1,nvalue - i);
			assert(decoded == nvalue - i);
			sortinfirstvalue(tmpbuffer,nvalue - i);
		}
		const uint8_t * const newfinalinbyte = headlessEncode(tmpbuffer,
				nvalue - i + 1, initial, inbyte);
		delete[] tmpbuffer;
		return newfinalinbyte - initinbyte;
	}


	// Performs a lower bound find in the encoded array.
    // Returns the index
    // assumes delta coding was used
	size_t findLowerBound(const uint32_t *in, const size_t length, uint32_t key,
			uint32_t *presult) {
		const uint8_t *inbyte = reinterpret_cast<const uint8_t *>(in);
		uint32_t out[4] = { 0 };
		assert(delta);
		size_t i = 0;
		uint32_t initial = 0;
		uint32_t nvalue = *in;

		inbyte += 4; // skip nvalue

		const uint8_t * const endbyte = reinterpret_cast<const uint8_t *>(in
				+ length);
		while (i + 3 < nvalue) {
			uint32_t gap1, gap2, gap3, gap4;
			uint32_t gap12, gap34;

			const uint32_t sel = *inbyte++;
			if (sel == 0) {
				gap1 = static_cast<uint32_t>(inbyte[0]);
				gap2 = static_cast<uint32_t>(inbyte[1]);
				gap12 = gap1 + gap2;
				gap3 = static_cast<uint32_t>(inbyte[2]);
				gap4 = static_cast<uint32_t>(inbyte[3]);
				gap34 = gap3 + gap4;
				inbyte += 4;
			} else {
				const uint32_t sel1 = (sel & 3);
				gap1 = *(reinterpret_cast<const uint32_t*>(inbyte))
						& mask[sel1];
				inbyte += sel1 + 1;
				const uint32_t sel2 = ((sel >> 2) & 3);
				gap2 = *(reinterpret_cast<const uint32_t*>(inbyte))
						& mask[sel2];
				gap12 = gap1 + gap2;
				inbyte += sel2 + 1;
				const uint32_t sel3 = ((sel >> 4) & 3);
				gap3 = *(reinterpret_cast<const uint32_t*>(inbyte))
						& mask[sel3];
				inbyte += sel3 + 1;
				const uint32_t sel4 = (sel >> 6);
				gap4 = *(reinterpret_cast<const uint32_t*>(inbyte))
						& mask[sel4];
				gap34 = gap3 + gap4;
				inbyte += sel4 + 1;
			}
			initial += gap12 + gap34;
			if (key <= initial) {
				if (key <= initial - gap34 - gap2) {
					*presult = initial - gap34 - gap2;
					return (i + 0);
				}
				if (key <= initial - gap34) {
					*presult = initial - gap34;
					return (i + 1);
				}
				if (key <= initial - gap4) {
					*presult = initial - gap4;
					return (i + 2);
				}
				*presult = initial;
				return (i + 3);
			}
			i += 4;
		}
		if (endbyte > inbyte && nvalue > i) {
			uint32_t tnvalue = nvalue - 1 - i;
			inbyte = decodeCarefully(inbyte, &initial, out, tnvalue);
			assert(inbyte <= endbyte);
			if (key <= out[0]) {
				*presult = out[0];
				return (i + 0);
			}
			if (tnvalue > 0 && key <= out[1]) {
				*presult = out[1];
				return (i + 1);
			}
			if (tnvalue > 1 && key <= out[2]) {
				*presult = out[2];
				return (i + 2);
			}
			if (tnvalue > 2 && key <= out[3]) {
				*presult = out[3];
				return (i + 3);
			}

		}
		assert(false);
		*presult = key + 1;
		return (i);
	}


    // Returns a decompressed value in an encoded array
    // This code has been optimized for delta-encoded arrays (TODO: optimize for the regular case).
    uint32_t select(uint32_t *in, size_t index) {
        const uint8_t *inbyte = reinterpret_cast<const uint8_t *> (in);
        uint32_t out[4];
        size_t i = 0;
        uint32_t initial = 0;
        uint32_t nvalue = *in;
        inbyte += 4; // skip nvalue
        if(index + 3 < nvalue) {// this common case can be done with fewer branches
            while(i + 4 <= index) {
                inbyte = delta ? scanGroupVarIntDelta(inbyte, &initial) :
                         scanGroupVarInt(inbyte); // note: delta known at compile time: this is not a branch
                i += 4;
            }
            inbyte = delta ? decodeGroupVarIntDelta(inbyte, &initial, out) :
                     decodeGroupVarInt(inbyte, out); // note: delta known at compile time: this is not a branch
            return (out[index - i]);
        }// else
        // we finish with the uncommon case
        while (i + 3 < index) { // a single branch will do for this case (bulk of the computation)
            inbyte = delta ? scanGroupVarIntDelta(inbyte, &initial) :
                     scanGroupVarInt(inbyte);
            i += 4;
        }
        // lots of branching ahead...
        while (i + 3 < nvalue) {
            inbyte = delta ? decodeGroupVarIntDelta(inbyte, &initial, out) :
                     decodeGroupVarInt(inbyte, out);
            i += 4;
            if (i > index)
                return (out[index - (i - 4)]);
        }
        {
        	nvalue = nvalue - i;
            inbyte = decodeCarefully(inbyte, &initial, out, nvalue);
            if (index == i)
                return (out[0]);
            if (nvalue > 1 && index == i + 1)
                return (out[1]);
            if (nvalue > 2 && index == i + 2)
                return (out[2]);
            if (nvalue > 3 && index == i + 3)
                return (out[3]);
        }
        assert(false);// we should never get here
        return (0);
    }


    string name() const {
        if(delta)
            return "varintgbdelta";
        else
            return "varintgb";
    }

	uint8_t * headlessEncode(uint32_t *in, const size_t length,uint32_t prev,
			uint8_t * bout) {
		size_t k = 0;
		for (; k + 3 < length; k += 4) {
			uint8_t * keyp = bout++;
			*keyp = 0;
			{
				const uint32_t val = delta ? in[k] - prev : in[k];
				if (delta)
					prev = in[k];
				if (val < (1U << 8)) {
					*bout++ = static_cast<uint8_t>(val);
				} else if (val < (1U << 16)) {
					*bout++ = static_cast<uint8_t>(val);
					*bout++ = static_cast<uint8_t>(val >> 8);
					*keyp = static_cast<uint8_t>(1);
				} else if (val < (1U << 24)) {
					*bout++ = static_cast<uint8_t>(val);
					*bout++ = static_cast<uint8_t>(val >> 8);
					*bout++ = static_cast<uint8_t>(val >> 16);
					*keyp = static_cast<uint8_t>(2);
				} else {
					// the compiler will do the right thing
					*reinterpret_cast<uint32_t *>(bout) = val;
					bout += 4;
					*keyp = static_cast<uint8_t>(3);
				}
			}
			{
				const uint32_t val = delta ? in[k + 1] - prev : in[k + 1];
				if (delta)
					prev = in[k + 1];
				if (val < (1U << 8)) {
					*bout++ = static_cast<uint8_t>(val);
				} else if (val < (1U << 16)) {
					*bout++ = static_cast<uint8_t>(val);
					*bout++ = static_cast<uint8_t>(val >> 8);
					*keyp |= static_cast<uint8_t>(1 << 2);
				} else if (val < (1U << 24)) {
					*bout++ = static_cast<uint8_t>(val);
					*bout++ = static_cast<uint8_t>(val >> 8);
					*bout++ = static_cast<uint8_t>(val >> 16);
					*keyp |= static_cast<uint8_t>(2 << 2);
				} else {
					// the compiler will do the right thing
					*reinterpret_cast<uint32_t *>(bout) = val;
					bout += 4;
					*keyp |= static_cast<uint8_t>(3 << 2);
				}
			}
			{
				const uint32_t val = delta ? in[k + 2] - prev : in[k + 2];
				if (delta)
					prev = in[k + 2];
				if (val < (1U << 8)) {
					*bout++ = static_cast<uint8_t>(val);
				} else if (val < (1U << 16)) {
					*bout++ = static_cast<uint8_t>(val);
					*bout++ = static_cast<uint8_t>(val >> 8);
					*keyp |= static_cast<uint8_t>(1 << 4);
				} else if (val < (1U << 24)) {
					*bout++ = static_cast<uint8_t>(val);
					*bout++ = static_cast<uint8_t>(val >> 8);
					*bout++ = static_cast<uint8_t>(val >> 16);
					*keyp |= static_cast<uint8_t>(2 << 4);
				} else {
					// the compiler will do the right thing
					*reinterpret_cast<uint32_t *>(bout) = val;
					bout += 4;
					*keyp |= static_cast<uint8_t>(3 << 4);
				}
			}
			{
				const uint32_t val = delta ? in[k + 3] - prev : in[k + 3];
				if (delta)
					prev = in[k + 3];
				if (val < (1U << 8)) {
					*bout++ = static_cast<uint8_t>(val);
				} else if (val < (1U << 16)) {
					*bout++ = static_cast<uint8_t>(val);
					*bout++ = static_cast<uint8_t>(val >> 8);
					*keyp |= static_cast<uint8_t>(1 << 6);
				} else if (val < (1U << 24)) {
					*bout++ = static_cast<uint8_t>(val);
					*bout++ = static_cast<uint8_t>(val >> 8);
					*bout++ = static_cast<uint8_t>(val >> 16);
					*keyp |= static_cast<uint8_t>(2 << 6);
				} else {
					// the compiler will do the right thing
					*reinterpret_cast<uint32_t *>(bout) = val;
					bout += 4;
					*keyp |= static_cast<uint8_t>(3 << 6);
				}
			}
		}
		if (k < length) {
			uint8_t * keyp = bout++;
			*keyp = 0;
			for (int j = 0; k < length && j < 8; j += 2, ++k) {
				const uint32_t val = delta ? in[k] - prev : in[k];
				if (delta)
					prev = in[k];
				if (val < (1U << 8)) {
					*bout++ = static_cast<uint8_t>(val);
				} else if (val < (1U << 16)) {
					*bout++ = static_cast<uint8_t>(val);
					*bout++ = static_cast<uint8_t>(val >> 8);
					*keyp |= static_cast<uint8_t>(1 << j);
				} else if (val < (1U << 24)) {
					*bout++ = static_cast<uint8_t>(val);
					*bout++ = static_cast<uint8_t>(val >> 8);
					*bout++ = static_cast<uint8_t>(val >> 16);
					*keyp |= static_cast<uint8_t>(2 << j);
				} else {
					// the compiler will do the right thing
					*reinterpret_cast<uint32_t *>(bout) = val;
					bout += 4;
					*keyp |= static_cast<uint8_t>(3 << j);
				}
			}
		}
		return bout;
	}

	// returns how many values were decoded to out, will try to decode desirednumber
	// if input allows.
    size_t headlessDecode(const uint8_t * inbyte, const size_t length, uint32_t prev,
                                 uint32_t *out, const size_t desirednumber) {

        uint32_t * initout = out;
        const uint32_t * const endout = out + desirednumber;
        const uint8_t * const endbyte = inbyte + length;
        uint32_t val;
        while ((endbyte > inbyte + 4 * 4 ) ) {//&& (endout > out + 3)
            inbyte = delta ? decodeGroupVarIntDelta(inbyte, &prev, out) :
                     decodeGroupVarInt(inbyte, out);
            out+=4;
        }
        while (endbyte > inbyte + 1) {
            uint8_t key = *inbyte++;
            for (int k = 0; (k < 4) && (endout > out); k++) {
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
        return out - initout;
    }


private:


    const uint32_t mask[4] = { 0xFF, 0xFFFF, 0xFFFFFF, 0xFFFFFFFF };


    void sortinfirstvalue(uint32_t * tmpbuffer, size_t length) {
    	int top = length < 4 ? length : 4;
    	for (int j = 0; j < top; ++j) {
    		if (tmpbuffer[j] > tmpbuffer[j + 1]) {
    			uint32_t t = tmpbuffer[j + 1];
    			tmpbuffer[j + 1] = tmpbuffer[j];
    			tmpbuffer[j] = t;
    		}
    	}
    }

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

    const uint8_t *decodeCarefully(const uint8_t *inbyte,
                                   uint32_t *initial, uint32_t *out, uint32_t count) {
        uint32_t val;
        uint32_t k, key = *inbyte++;
        for (k = 0; k < count && k < 4; k++) {
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
            if(delta) {
                *initial += val;
                *out = *initial;
            } else {
                *out = val;
            }
            out++;
        }
        return (inbyte);
    }


    const uint8_t* scanGroupVarIntDelta(const uint8_t* in, uint32_t * val) {
		const uint32_t sel = *in++;
		if (sel == 0) {
			*val += static_cast<uint32_t>(in[0]);
			*val += static_cast<uint32_t>(in[1]);
			*val += static_cast<uint32_t>(in[2]);
			*val += static_cast<uint32_t>(in[3]);
			return in + 4;
		}
		const uint32_t sel1 = (sel & 3);
		*val += *(reinterpret_cast<const uint32_t*>(in)) & mask[sel1];
		in += sel1 + 1;
		const uint32_t sel2 = ((sel >> 2) & 3);
		*val += *(reinterpret_cast<const uint32_t*>(in)) & mask[sel2];
		in += sel2 + 1;
		const uint32_t sel3 = ((sel >> 4) & 3);
		*val += *(reinterpret_cast<const uint32_t*>(in)) & mask[sel3];
		in += sel3 + 1;
		const uint32_t sel4 = (sel >> 6);
		*val += *(reinterpret_cast<const uint32_t*>(in)) & mask[sel4];
		in += sel4 + 1;
		return in;
	}


    const uint8_t* scanGroupVarInt(const uint8_t* in) {
		const uint32_t sel = *in++;
		if (sel == 0) {
			return in + 4;
		}
		const uint32_t sel1 = (sel & 3);
		in += sel1 + 1;
		const uint32_t sel2 = ((sel >> 2) & 3);
		in += sel2 + 1;
		const uint32_t sel3 = ((sel >> 4) & 3);
		in += sel3 + 1;
		const uint32_t sel4 = (sel >> 6);
		in += sel4 + 1;
		return in;
	}


};









} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_VARINTGB_H_ */
