/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef VARIABLEBYTE_H_
#define VARIABLEBYTE_H_
#include "common.h"
#include "codecs.h"
#include "util.h"

template<bool delta>
class VariableByte: public IntegerCODEC {
public:

	void encodeArray(uint32_t *in, const size_t length, uint32_t *out,
			size_t &nvalue) {
		uint8_t *bout = reinterpret_cast<uint8_t *>(out);
		const uint8_t * const initbout = reinterpret_cast<uint8_t *>(out);
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
		while (needPaddingTo32Bits(bout)) {
			*bout++ = 0;
		}
		const size_t storageinbytes = bout - initbout;
		assert((storageinbytes % 4) == 0);
		nvalue = storageinbytes / 4;
	}
	// this assumes that there is a value to be read
	int read_int(const uint8_t* in, uint32_t* out) {
		*out = in[0] & 0x7F;
		if (in[0] >= 128) {
			return 1;
		}
		*out = ((in[1] & 0x7FU) << 7) | *out;
		if (in[1] >= 128) {
			return 2;
		}
		*out = ((in[2] & 0x7FU) << 14) | *out;
		if (in[2] >= 128) {
			return 3;
		}
		*out = ((in[3] & 0x7FU) << 21) | *out;
		if (in[3] >= 128) {
			return 4;
		}
		*out = ((in[4] & 0x7FU) << 28) | *out;
		return 5;
	}

	const uint32_t *decodeArray(const uint32_t *in, const size_t length,
			uint32_t *out, size_t &nvalue) {
		uint32_t prev = 0;
		if (length == 0) {
			nvalue = 0;
			return in; //abort
		}
		const uint8_t *inbyte = reinterpret_cast<const uint8_t *>(in);
		const uint8_t * const endbyte = reinterpret_cast<const uint8_t *>(in
				+ length);
		const uint32_t * const initout(out);
		// this assumes that there is a value to be read

		for (uint32_t v = 0;endbyte > inbyte + 5;) {
			if(delta) {
				inbyte += read_int(inbyte, &v);
				*out = (prev = v + prev);
			} else {
				inbyte += read_int(inbyte, out);
			}
			++out;
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
		return in + length;
	}

	string name() const {
		if (delta)
			return "VariableByteDelta";
		else
			return "VariableByte";
	}
private:
	template<uint32_t i>
	uint8_t extract7bits(const uint32_t val) {
		return static_cast<uint8_t>((val >> (7 * i)) & ((1U << 7) - 1));
	}

	template<uint32_t i>
	uint8_t extract7bitsmaskless(const uint32_t val) {
		return static_cast<uint8_t>((val >> (7 * i)));
	}
};

#endif /* VARIABLEBYTE_H_ */
