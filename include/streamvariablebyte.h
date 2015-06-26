#ifndef SIMDCompressionAndIntersection_STREAMVARIABLEBYTE_
#define SIMDCompressionAndIntersection_STREAMVARIABLEBYTE_

#include "common.h"
#include "codecs.h"

namespace SIMDCompressionLib {


/**
 * StreamVByte is an integer CODEC invented by Nathan Kurz.
 */



extern "C" {
uint64_t svb_encode(uint8_t *out, const uint32_t *in, uint32_t count,
                    int delta, int type);
uint8_t *svb_decode_avx_simple(uint32_t *out, uint8_t * keyPtr, uint8_t * dataPtr, uint64_t count);
uint8_t *svb_decode_avx_d1_simple(uint32_t *out, uint8_t * keyPtr, uint8_t * dataPtr, uint64_t count);
uint8_t *svb_decode_scalar_d1_init(uint32_t *outPtr, const uint8_t *keyPtr,
                              uint8_t *dataPtr, uint32_t count, uint32_t prev);
uint32_t svb_select_avx_d1_init(uint8_t *keyPtr, uint8_t *dataPtr,
                         uint64_t count, uint32_t prev, int slot);
int svb_find_avx_d1_init(uint8_t *keyPtr, uint8_t *dataPtr, uint64_t count,
                         uint32_t prev, uint32_t key, uint32_t *presult);
uint8_t *svb_insert_scalar_d1_init(uint8_t *keyPtr, uint8_t *dataPtr,
                              size_t dataSize, uint32_t count,
                              uint32_t prev, uint32_t new_key,
                              uint32_t *position);
}


/**
 * Regular StreamVByte (no differential coding)
 */
class StreamVByte : public IntegerCODEC {
public:
    void encodeArray(uint32_t *in, const size_t count, uint32_t *out,
                     size_t &nvalue) {
        uint64_t bytesWritten = svb_encode((uint8_t *)out, in, count, 0, 1);
        nvalue = (bytesWritten + 3)/4;
    }

    const uint32_t * decodeArray(const uint32_t *in, const size_t /* count */,
                                 uint32_t *out, size_t & nvalue) {
        uint32_t count = *(uint32_t *)in;  // first 4 bytes is number of ints
        nvalue = count;
        if (count == 0) return 0;

        uint8_t *keyPtr = (uint8_t *)in + 4; // full list of keys is next
        uint32_t keyLen = ((count + 3) / 4);   // 2-bits per key (rounded up)
        uint8_t *dataPtr = keyPtr + keyLen;    // data starts at end of keys
        nvalue = count;
        return reinterpret_cast<const uint32_t *>((reinterpret_cast<uintptr_t>(
        		svb_decode_avx_simple(out, keyPtr, dataPtr, count))
                + 3) & ~3);

    }

    std::string name() const {
        return "streamvbyte";
    }

};

/**
 * StreamVByte with integrated differential coding
 */
class StreamVByteD1 : public IntegerCODEC {
public:

    void encodeArray(uint32_t *in, const size_t count, uint32_t *out,
                     size_t &nvalue) {
        uint32_t bytesWritten = svb_encode((uint8_t *)(out + 1), in,
                                    count, 1, 1);
        *out = 4 + bytesWritten;
        nvalue = 1 + (bytesWritten + 3) / 4;
    }

    const uint32_t * decodeArray(const uint32_t *in, const size_t /* count */,
                                 uint32_t *out, size_t & nvalue) {
        ++in;   // number of encoded bytes
        uint32_t count = *(uint32_t *)in;  // next 4 bytes is number of ints
        nvalue = count;
        if (count == 0) return 0;

        uint8_t *keyPtr = (uint8_t *)in + 4; // full list of keys is next
        uint32_t keyLen = ((count + 3) / 4);   // 2-bits per key (rounded up)
        uint8_t *dataPtr = keyPtr + keyLen;    // data starts at end of keys
        return reinterpret_cast<const uint32_t *>((reinterpret_cast<uintptr_t>(
        		svb_decode_avx_d1_simple(out, keyPtr, dataPtr, count))
                + 3) & ~3);
    }

    uint32_t select(const uint32_t *in, int slot) {
        ++in;   // number of encoded bytes
        uint32_t count = *in;  // next 4 bytes is number of ints
        assert(slot < (int)count);
        uint8_t *keyPtr = (uint8_t *)in + 4; // full list of keys is next
        uint32_t keyLen = ((count + 3) / 4);   // 2-bits per key (rounded up)
        uint8_t *dataPtr = keyPtr + keyLen;    // data starts at end of keys
        return svb_select_avx_d1_init(keyPtr, dataPtr, count, 0, slot);
    }

    uint32_t findLowerBound(const uint32_t *in, uint32_t /* count */,
                           uint32_t key, uint32_t *presult) {
        ++in;   // skip number of encoded bytes
        uint32_t count = *(uint32_t *)in;  // next 4 bytes is number of ints
        uint8_t *keyPtr = (uint8_t *)in + 4; // full list of keys is next
        uint32_t keyLen = ((count + 3) / 4);   // 2-bits per key (rounded up)
        uint8_t *dataPtr = keyPtr + keyLen;    // data starts at end of keys
        return (uint32_t)svb_find_avx_d1_init(keyPtr, dataPtr, count,
                         0, key, presult);
    }

    // Inserts |key| into an encoded sequence. |encodedSize| is the total
    // allocated size for |in| (in bytes).
    // Returns the number of values written.
    uint32_t insert(uint32_t *in, uint32_t, uint32_t key) {
        uint32_t bytesEncoded = *in;
        uint32_t count = *(in + 1);  // first 4 bytes is number of ints
        uint8_t *keyPtr = (uint8_t *)(in + 2); // full list of keys is next
        // keyLen: 2-bits per key (rounded up), but at least 1 byte
        uint32_t keyLen = count == 0 ? 1 : ((count + 3) / 4);
        uint8_t *dataPtr = keyPtr + keyLen;    // data starts at end of keys
        uint32_t dataSize = (bytesEncoded - 8) - keyLen;

        // make space for the new key?
        if (count > 0
                && count % 4 == 0
                && keyPtr + keyLen + 1 > dataPtr) {
            memmove(dataPtr + 1, dataPtr, dataSize);
            dataPtr++;
        }

        *(in + 1) = count + 1;

        uint32_t position;
        uint32_t bytesWritten = svb_insert_scalar_d1_init(keyPtr, dataPtr,
                                    dataSize, count, 0, key, &position)
                                - (uint8_t *)in;
        *in = bytesWritten; 
        return (bytesWritten + 3) / 4;
    }

    std::string name() const {
        return "streamvbyte_d1";
    }

};

} // namespace SIMDCompressionLib


#endif // STREAMVARIABLEBYTE_
