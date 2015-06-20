/*
 * Copyright (C) 2005-2015 Christoph Rupp (chris@crupp.de).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * Frame of Reference encoding
 *
 * based on code from http://github.com/cruppstahl/for
 */

#ifndef INCLUDE_FOR_H
#define INCLUDE_FOR_H

#include <stdint.h>

#include "common.h"
#include "codecs.h"
#include "util.h"
#include "for.h"

namespace SIMDCompressionLib {

/*
 * Optimized scalar implementation of FOR (frame-of-reference) compression
 */
class ForCODEC : public IntegerCODEC {
  public:
    void encodeArray(uint32_t *in, const size_t length, uint32_t *out,
                        size_t &nvalue) {
      *(uint32_t *)out = length;
      out++;
      // for_compress_sorted() would be a bit faster, but requires
      // sorted input
      nvalue = (4 + for_compress_unsorted((const uint32_t *)in, (uint8_t *)out,
                        length) + 3) / 4;
    }

    const uint32_t *decodeArray(const uint32_t *in, const size_t,
                        uint32_t *out, size_t &nvalue) {
      nvalue = *in;
      in++;
      return in + for_uncompress((const uint8_t *)in, out, nvalue);
    }

    size_t findLowerBound(const uint32_t *in, const size_t,
                        uint32_t key, uint32_t *presult) {
      uint32_t length = *in;
      in++;
      return (size_t)for_lower_bound_search((const uint8_t *)in, length,
                        key, presult);
    }

    uint32_t select(const uint32_t *in, size_t index) {
      in++; // Skip length
      return for_select((const uint8_t *)in, index);
    }

    string name() const {
      return "For";
    }
};

} /* namespace */

#endif /* INCLUDE_FOR_H */
