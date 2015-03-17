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

		while(endbyte > inbyte + 5) {
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

template<bool delta>
class VByte: public IntegerCODEC {
public:
	void encodeArray(uint32_t *in, const size_t length, uint32_t *out,
			size_t &nvalue) {
		const uint8_t * const initbout = reinterpret_cast<uint8_t *>(out);
		uint8_t * bout = reinterpret_cast<uint8_t *>(out);
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

		while(endbyte > inbyte + 5) {
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
		return in + length;
	}

	std::string name() const {
		if (delta)
			return "VByteDelta";
		else
			return "VByte";
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


} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_VARIABLEBYTE_H_ */
