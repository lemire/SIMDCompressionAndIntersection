

#ifndef INCLUDE_FRAMEOFREFERENCE_H_
#define INCLUDE_FRAMEOFREFERENCE_H_




#include "common.h"
#include "codecs.h"
#include "util.h"

namespace SIMDCompressionLib {


/**
 * Simple implementation of FOR compression using blocks of
 * 32 integers. If you specify a length that is not a multiple
 * of 32, the leftover integers are not compressed.
 *
 *
 * It might be worthwhile to pad your input up to 32 integers
 * before compression or to otherwise adapt this class to your needs.
 *
 * FOR does not compress particularly well but it supports
 * fast random access.
 */
class FrameOfReference: public IntegerCODEC {
public:

    void encodeArray(uint32_t *in, const size_t length, uint32_t *out,
                     size_t &nvalue) {
    	*out = length;
        uint32_t * finalout =  compress_length(in,length, out  + 1);
        nvalue = finalout - out;

    }

    const uint32_t * uncompress_length(const uint32_t * in, uint32_t * out, uint32_t  nvalue);
    uint32_t * compress_length(const uint32_t * in, uint32_t length, uint32_t * out);

    const uint32_t *decodeArray(const uint32_t *in, const size_t ,
                                uint32_t *out, size_t &nvalue) {
    	nvalue = *in;
    	in++;
    	return uncompress_length(in,out,nvalue);
    }



    // Performs a lower bound find in the encoded array.
    // Returns the index
    size_t findLowerBound(const uint32_t *in, const size_t length, uint32_t key,
                          uint32_t *presult);




    // Returns a decompressed value in an encoded array
    uint32_t select(uint32_t *in, size_t index);


    string name() const {
            return "FrameOfReference";
    }
private:

};


/**
 * Accelerated implementation of FOR compression using blocks of
 * 128 integers. If you specify a length that is not a multiple
 * of 128, the leftover integers are not compressed.
 *
 * It might be worthwhile to pad your input up to 128 integers
 * before compression or to otherwise adapt this class to your needs.
 *
 * FOR does not compress particularly well but it supports
 * fast random access.
 */
class SIMDFrameOfReference: public IntegerCODEC {
public:

    void encodeArray(uint32_t *in, const size_t length, uint32_t *out,
                     size_t &nvalue) {
    	*out = length;
        uint32_t * finalout =  simd_compress_length(in,length, out  + 1);
        nvalue = finalout - out;

    }

    const uint32_t * simd_uncompress_length(const uint32_t * in, uint32_t * out, uint32_t  nvalue);
    uint32_t * simd_compress_length(const uint32_t * in, uint32_t length, uint32_t * out);

    const uint32_t *decodeArray(const uint32_t *in, const size_t ,
                                uint32_t *out, size_t &nvalue) {
    	nvalue = *in;
    	in++;
    	return simd_uncompress_length(in,out,nvalue);
    }



    // Performs a lower bound find in the encoded array.
    // Returns the index
    size_t findLowerBound(const uint32_t *in, const size_t length, uint32_t key,
                          uint32_t *presult);




    // Returns a decompressed value in an encoded array
    uint32_t select(uint32_t *in, size_t index);


    string name() const {
            return "SIMDFrameOfReference";
    }
private:

};

}


#endif /* INCLUDE_FRAMEOFREFERENCE_H_ */
