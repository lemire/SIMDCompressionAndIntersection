

#ifndef INCLUDE_FRAMEOFREFERENCE_H_
#define INCLUDE_FRAMEOFREFERENCE_H_




#include "common.h"
#include "codecs.h"
#include "util.h"

namespace SIMDCompressionLib {


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

    const uint32_t *decodeArray(const uint32_t *in, const size_t length,
                                uint32_t *out, size_t &nvalue) {
    	nvalue = *in;
    	in++;
    	return uncompress_length(in,out,nvalue);
    }



    // Performs a lower bound find in the encoded array.
    // Returns the index
    size_t findLowerBound(const uint32_t *in, const size_t length, uint32_t key,
                          uint32_t *presult) {
    	return 0;// TODO : implement
    }




    // Returns a decompressed value in an encoded array
    uint32_t select(uint32_t *in, size_t index);


    string name() const {
            return "FrameOfReference";
    }
private:

};


}


#endif /* INCLUDE_FRAMEOFREFERENCE_H_ */
