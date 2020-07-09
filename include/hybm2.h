/*
 * This is an implementation of the hyb+m2 method proposed in:
 *
 * J. S. Culpepper and A. Moffat. Efficient set intersection for
 * inverted indexing. ACM Trans. Inf. Syst., 29(1):1:1�1:25, Dec. 2010.
 *
 *      Implemented by Daniel Lemire
 */

#ifndef SIMDCompressionAndIntersection_HYBM2_H_
#define SIMDCompressionAndIntersection_HYBM2_H_

#include "common.h"
#include "codecs.h"
#include "codecfactory.h"
#include "boolarray.h"
#include "intersection.h"
#include "skipping.h"

namespace SIMDCompressionLib {

class HybM2 {
public:
  // th = 0 means that we select bitmaps as needed
  HybM2(IntegerCODEC &c, intersectionfunction inter, uint32_t MaxId,
        vector<uint32_t> &recovbuffer, uint32_t th = 32)
      : bitmapmap(), shortlistmap(), mapuncompsizes(), mMaxId(MaxId),
        threshold(th), recovbuffer(recovbuffer), codec(c), Inter(inter) {}

  /**
   * Returns the *uncompressed* size of a given posting list (specified
   * by ID).
   */
  size_t getSizeInInts(uint32_t postId) { return mapuncompsizes[postId]; }

  /**
   * Load an array (data) of length "length" as the posting list corresponding
   * to id postid
   * into the data structure. The data will be either converted to a bitmap or
   * compressed.
   */
  size_t load(const uint32_t postid, const uint32_t *data,
              const uint32_t length) {
    if (threshold == 0)
      return loadOptimized(postid, data, length);
    else if (length * threshold >= mMaxId)
      return loadAsBitmap(postid, data, length);
    else
      return loadAsShortArray(postid, data, length);
  }

  /**
   * Check whether we have a posting list corresponding to postid
   */
  bool hasBeenLoaded(const uint32_t postid) {
    return ((shortlistmap.find(postid) != shortlistmap.end()) ||
            (bitmapmap.find(postid) != bitmapmap.end()));
  }

  /**
   * Compute the total of the volume of of posting lists
   * corresponding to a query.
   */
  size_t computeUnpackVolume(const vector<uint32_t> &ids) {
    size_t answer = 0;
    for (uint32_t id : ids) {
      answer += mapuncompsizes[id];
    }
    return answer;
  }

  /**
   * Compute the total of the intersection of of posting lists
   * corresponding to a query, and output how many integers are
   * in
   *
   * ids: the query as a set of posting ids
   * out: write to result
   * sizeout: will indicate how many integers were written to out.
   *
   * return unpack volume defined as the total volume of the posting
   * lists that were needed to compute the intersection (which can
   * be less than the total volume possible due to early abandoning).
   */
  size_t intersect(const vector<uint32_t> &ids, uint32_t *out,
                   size_t &sizeout) {
    if (ids.empty()) {
      sizeout = 0;
      return 0;
    }
    vector<pair<uint32_t, shared_ptr<vector<uint32_t>>>> shortlists;
    vector<pair<uint32_t, shared_ptr<BoolArray>>> bitmaps;
    // vector<uint32_t> bitmapscard;

    for (uint32_t id : ids) {
      if (shortlistmap.find(id) != shortlistmap.end())
        shortlists.push_back(make_pair(mapuncompsizes[id], shortlistmap[id]));
      else {
        assert(bitmapmap.find(id) != bitmapmap.end());
        bitmaps.push_back(make_pair(mapuncompsizes[id], bitmapmap[id]));
      }
    }
    size_t unpackVolume = 0;
    if (shortlists.empty()) {
      if (bitmaps.size() == 1) {
        sizeout = bitmaps.front().second->toInts(out);
        unpackVolume += sizeout;
        return unpackVolume;
      }

      BoolArray answer(mMaxId);
      bitmaps[0].second->intersect(*bitmaps[1].second, answer);
      unpackVolume += bitmaps[0].first + bitmaps[1].first;
      for (uint32_t i = 2; i < bitmaps.size(); ++i) {
        answer.inplaceIntersect(*bitmaps[i].second);
        unpackVolume += bitmaps[i].first;
      }
      sizeout = answer.toInts(out);
      return unpackVolume;
    } else {
      sort(shortlists.begin(), shortlists.end());
      sort(bitmaps.begin(), bitmaps.end());
      codec.decodeArray(shortlists[0].second->data(),
                        shortlists[0].second->size(), out, sizeout);
      assert(shortlists[0].first == sizeout);
      unpackVolume += sizeout;
      assert(sizeout == shortlists[0].first);
      for (uint32_t i = 1; (sizeout > 0) && (i < shortlists.size()); ++i) {
        size_t thissize = recovbuffer.size();
        codec.decodeArray(shortlists[i].second->data(),
                          shortlists[i].second->size(), recovbuffer.data(),
                          thissize);
        unpackVolume += thissize;
        assert(shortlists[i].first == thissize);
        sizeout = Inter(out, sizeout, recovbuffer.data(), thissize, out);
      }
      size_t pos = 0;
      for (uint32_t i = 0; (sizeout > 0) && (i < bitmaps.size()); ++i) {
        unpackVolume += bitmaps[i].first;
        shared_ptr<BoolArray> &ba = bitmaps[i].second;
        pos = 0;
        for (uint32_t ii = 0; ii < sizeout; ++ii) {
          if (!ba->get(out[ii]))
            continue;
          else
            out[pos++] = out[ii];
        }
        sizeout = pos;
      }
      return unpackVolume;
    }
  }

  ~HybM2() {}

  /**
   * Estimate of the volume of data used by this object.
   */
  size_t storageInBytes() const {
    size_t answer = 0;
    for (auto i : bitmapmap)
      answer += i.second->sizeInBytes();
    for (auto i : shortlistmap)
      answer += i.second->size() * sizeof(uint32_t);
    return answer;
  }

  size_t sizeOfRecoveryBufferInWords() const { return recovbuffer.size(); }

private:
  // load as either a bitmap or a compressed short list
  size_t loadOptimized(const uint32_t postid, const uint32_t *data,
                       const uint32_t length) {
    if (mapuncompsizes.find(postid) != mapuncompsizes.end())
      return 0;
    vector<uint32_t> *compressedbuffer = new vector<uint32_t>(length + 1024);
    size_t outlength = compressedbuffer->size();
    vector<uint32_t> tmp(
        data,
        data + length); // use the buffer because some codecs modify the input
    codec.encodeArray(tmp.data(), length, compressedbuffer->data(), outlength);
    if (outlength * sizeof(uint32_t) <
        BoolArray::sizeInBytes(mMaxId)) { // we are good
      if (recovbuffer.size() < length)
        recovbuffer.resize(length);
      compressedbuffer->resize(outlength);
      compressedbuffer->shrink_to_fit();
      shortlistmap[postid] = shared_ptr<vector<uint32_t>>(compressedbuffer);
      mapuncompsizes[postid] = length;
      return compressedbuffer->size();
    } else {
      delete compressedbuffer;
      return loadAsBitmap(postid, data, length);
    }
  }
  /**
   * Load an array (data) of length "length" as the posting list corresponding
   * to id postid
   * as a bitmap.
   *
   * Do not call this directly, call load() instead.
   */
  size_t loadAsBitmap(const uint32_t postid, const uint32_t *data,
                      const uint32_t length) {
    if (bitmapmap.find(postid) != bitmapmap.end())
      return 0;
    BoolArray *ba = new BoolArray(mMaxId);
    for (uint32_t k = 0; k < length; ++k)
      ba->set(data[k]);
    bitmapmap[postid] = shared_ptr<BoolArray>(ba);
    mapuncompsizes[postid] = length;
    return ba->sizeInBytes() / sizeof(uint32_t);
  }

  /**
   * Load an array (data) of length "length" as the posting list corresponding
   * to id postid
   * as a short array.
   *
   * Do not call this directly, call load() instead.
   */
  size_t loadAsShortArray(const uint32_t postid, const uint32_t *data,
                          const uint32_t length) {
    if (shortlistmap.find(postid) != shortlistmap.end())
      return 0;
    if (recovbuffer.size() < length)
      recovbuffer.resize(length);
    vector<uint32_t> *compressedbuffer = new vector<uint32_t>(length + 1024);
    size_t outlength = compressedbuffer->size();
    for (size_t i = 0; i < length;
         ++i) // use the buffer because some codecs modify the input
      recovbuffer[i] = data[i];
    codec.encodeArray(recovbuffer.data(), length, compressedbuffer->data(),
                      outlength);
    compressedbuffer->resize(outlength);
    compressedbuffer->shrink_to_fit();
    shortlistmap[postid] = shared_ptr<vector<uint32_t>>(compressedbuffer);
    mapuncompsizes[postid] = length;
    return compressedbuffer->size();
  }

  map<uint32_t, shared_ptr<BoolArray>> bitmapmap;
  map<uint32_t, shared_ptr<vector<uint32_t>>> shortlistmap;
  map<uint32_t, uint32_t> mapuncompsizes;

  const size_t mMaxId; // max value that can be stored in a list
  const size_t threshold; //// 32 seems to be the recommended setting, no need
                          ///to change it?

  vector<uint32_t> &recovbuffer;

  IntegerCODEC &codec; // how we compress the short lists
  intersectionfunction Inter;
};

/**
 * This is a version of HybM2 without compression (other than the bitmaps).
 */
class UncompressedHybM2 {
public:
  UncompressedHybM2(intersectionfunction inter, uint32_t MaxId,
                    uint32_t th = 32)
      : bitmapmap(), shortlistmap(), mapuncompsizes(), mMaxId(MaxId),
        threshold(th), Inter(inter) {}

  /**
   * Returns the *uncompressed* size of a given posting list (specified
   * by ID).
   */
  size_t getSizeInInts(uint32_t postId) { return mapuncompsizes[postId]; }

  /**
   * Load an array (data) of length "length" as the posting list corresponding
   * to id postid
   * into the data structure. The data will be either converted to a bitmap or
   * compressed.
   */
  size_t load(const uint32_t postid, const uint32_t *data,
              const uint32_t length) {
    if (length * threshold >= mMaxId)
      return loadAsBitmap(postid, data, length);
    else
      return loadAsShortArray(postid, data, length);
  }

  /**
   * Check whether we have a posting list corresponding to postid
   */
  bool hasBeenLoaded(const uint32_t postid) {
    return ((shortlistmap.find(postid) != shortlistmap.end()) ||
            (bitmapmap.find(postid) != bitmapmap.end()));
  }

  /**
   * Compute the total of the volume of of posting lists
   * corresponding to a query.
   */
  size_t computeUnpackVolume(const vector<uint32_t> &ids) {
    size_t answer = 0;
    for (uint32_t id : ids) {
      answer += mapuncompsizes[id];
    }
    return answer;
  }

  /**
   * Compute the total of the intersection of of posting lists
   * corresponding to a query, and output how many integers are
   * in
   *
   * ids: the query as a set of posting ids
   * out: write to result
   * sizeout: will indicate how many integers were written to out.
   *
   * return unpack volume defined as the total volume of the posting
   * lists that were needed to compute the intersection (which can
   * be less than the total volume possible due to early abandoning).
   */
  size_t intersect(const vector<uint32_t> &ids, uint32_t *out,
                   size_t &sizeout) {
    if (ids.empty()) {
      sizeout = 0;
      return 0;
    }
    vector<pair<uint32_t, shared_ptr<vector<uint32_t>>>> shortlists;
    vector<pair<uint32_t, shared_ptr<BoolArray>>> bitmaps;
    // vector<uint32_t> bitmapscard;

    for (uint32_t id : ids) {
      if (shortlistmap.find(id) != shortlistmap.end())
        shortlists.push_back(make_pair(mapuncompsizes[id], shortlistmap[id]));
      else {
        assert(bitmapmap.find(id) != bitmapmap.end());
        bitmaps.push_back(make_pair(mapuncompsizes[id], bitmapmap[id]));
      }
    }
    size_t unpackVolume = 0;
    if (shortlists.empty()) {
      if (bitmaps.size() == 1) {
        sizeout = bitmaps.front().second->toInts(out);
        unpackVolume += sizeout;
        return unpackVolume;
      }

      BoolArray answer(mMaxId);
      bitmaps[0].second->intersect(*bitmaps[1].second, answer);
      unpackVolume += bitmaps[0].first + bitmaps[1].first;
      for (uint32_t i = 2; i < bitmaps.size(); ++i) {
        answer.inplaceIntersect(*bitmaps[i].second);
        unpackVolume += bitmaps[i].first;
      }
      sizeout = answer.toInts(out);
      return unpackVolume;
    } else {
      sort(shortlists.begin(), shortlists.end());
      sort(bitmaps.begin(), bitmaps.end());
      assert(sizeout >= shortlists[0].second->size());
      sizeout = shortlists[0].second->size();
      unpackVolume += shortlists[0].second->size();
      assert(sizeout == shortlists[0].first);
      // we have to make a copy because by convention the output is not directly
      // from the index
      const vector<uint32_t> &firstvector = *shortlists[0].second;
      for (uint32_t i = 0; i < firstvector.size(); ++i)
        out[i] = firstvector[i];
      for (uint32_t i = 1; (sizeout > 0) && (i < shortlists.size()); ++i) {
        unpackVolume += shortlists[i].first;
        sizeout = Inter(out, sizeout, shortlists[i].second->data(),
                        shortlists[i].second->size(), out);
      }
      size_t pos = 0;
      for (uint32_t i = 0; (sizeout > 0) && (i < bitmaps.size()); ++i) {
        unpackVolume += bitmaps[i].first;
        shared_ptr<BoolArray> &ba = bitmaps[i].second;
        pos = 0;
        for (uint32_t ii = 0; ii < sizeout; ++ii) {
          if (!ba->get(out[ii]))
            continue;
          else
            out[pos++] = out[ii];
        }
        sizeout = pos;
      }
      return unpackVolume;
    }
  }

  ~UncompressedHybM2() {}

  /**
   * Estimate of the volume of data used by this object.
   */
  size_t storageInBytes() const {
    size_t answer = 0;
    for (auto i : bitmapmap)
      answer += i.second->sizeInBytes();
    for (auto i : shortlistmap)
      answer += i.second->size() * sizeof(uint32_t);
    return answer;
  }

private:
  /**
   * Load an array (data) of length "length" as the posting list corresponding
   * to id postid
   * as a bitmap.
   *
   * Do not call this directly, call load() instead.
   */
  size_t loadAsBitmap(const uint32_t postid, const uint32_t *data,
                      const uint32_t length) {
    if (bitmapmap.find(postid) != bitmapmap.end())
      return 0;
    BoolArray *ba = new BoolArray(mMaxId);
    for (uint32_t k = 0; k < length; ++k)
      ba->set(data[k]);
    bitmapmap[postid] = shared_ptr<BoolArray>(ba);
    mapuncompsizes[postid] = length;
    return ba->sizeInBytes() / sizeof(uint32_t);
  }

  /**
   * Load an array (data) of length "length" as the posting list corresponding
   * to id postid
   * as a short array.
   *
   * Do not call this directly, call load() instead.
   */
  size_t loadAsShortArray(const uint32_t postid, const uint32_t *data,
                          const uint32_t length) {
    if (shortlistmap.find(postid) != shortlistmap.end())
      return 0;
    mapuncompsizes[postid] = length;
    vector<uint32_t> *compressedbuffer =
        new vector<uint32_t>(data, data + length);
    shortlistmap[postid] = shared_ptr<vector<uint32_t>>(compressedbuffer);
    return compressedbuffer->size();
  }

  map<uint32_t, shared_ptr<BoolArray>> bitmapmap;
  map<uint32_t, shared_ptr<vector<uint32_t>>> shortlistmap;
  map<uint32_t, uint32_t> mapuncompsizes;

  const size_t mMaxId; // max value that can be stored in a list
  const size_t threshold; //// 32 seems to be the recommended setting, no need
                          ///to change it?

  intersectionfunction Inter;
};

/**
 * This is a version of HybM2 with a skipping data structure akin to what is
 * described
 * by Culpepper and Moffat. We seem to get no gain from this approach.
 */
class SkippingHybM2 {
public:
  SkippingHybM2(uint32_t MaxId, uint32_t th = 32, uint32_t BS = 8)
      : bitmapmap(), shortlistmap(), mapuncompsizes(), mMaxId(MaxId),
        threshold(th), BlockSizeLog(BS) {}

  /**
   * Returns the *uncompressed* size of a given posting list (specified
   * by ID).
   */
  size_t getSizeInInts(uint32_t postId) { return mapuncompsizes[postId]; }

  /**
   * Load an array (data) of length "length" as the posting list corresponding
   * to id postid
   * into the data structure. The data will be either converted to a bitmap or
   * compressed.
   */
  size_t load(const uint32_t postid, const uint32_t *data,
              const uint32_t length) {
    if (length * threshold >= mMaxId)
      return loadAsBitmap(postid, data, length);
    else
      return loadAsShortArray(postid, data, length);
  }

  /**
   * Check whether we have a posting list corresponding to postid
   */
  bool hasBeenLoaded(const uint32_t postid) {
    return ((shortlistmap.find(postid) != shortlistmap.end()) ||
            (bitmapmap.find(postid) != bitmapmap.end()));
  }

  /**
   * Compute the total of the volume of of posting lists
   * corresponding to a query.
   */
  size_t computeUnpackVolume(const vector<uint32_t> &ids) {
    size_t answer = 0;
    for (uint32_t id : ids) {
      answer += mapuncompsizes[id];
    }
    return answer;
  }

  /**
   * Compute the total of the intersection of of posting lists
   * corresponding to a query, and output how many integers are
   * in
   *
   * ids: the query as a set of posting ids
   * out: write to result
   * sizeout: will indicate how many integers were written to out.
   *
   * return unpack volume defined as the total volume of the posting
   * lists that were needed to compute the intersection (which can
   * be less than the total volume possible due to early abandoning).
   */
  size_t intersect(const vector<uint32_t> &ids, uint32_t *out,
                   size_t &sizeout) {
    if (ids.empty()) {
      sizeout = 0;
      return 0;
    }
    vector<pair<uint32_t, shared_ptr<Skipping>>> shortlists;
    vector<pair<uint32_t, shared_ptr<BoolArray>>> bitmaps;
    for (uint32_t id : ids) {
      if (shortlistmap.find(id) != shortlistmap.end())
        shortlists.push_back(make_pair(mapuncompsizes[id], shortlistmap[id]));
      else {
        assert(bitmapmap.find(id) != bitmapmap.end());
        bitmaps.push_back(make_pair(mapuncompsizes[id], bitmapmap[id]));
      }
    }
    size_t unpackVolume = 0;
    if (shortlists.empty()) {
      if (bitmaps.size() == 1) {
        sizeout = bitmaps.front().second->toInts(out);
        unpackVolume += sizeout;
        return unpackVolume;
      }

      BoolArray answer(mMaxId);
      bitmaps[0].second->intersect(*bitmaps[1].second, answer);
      unpackVolume += bitmaps[0].first + bitmaps[1].first;
      for (uint32_t i = 2; i < bitmaps.size(); ++i) {
        answer.inplaceIntersect(*bitmaps[i].second);
        unpackVolume += bitmaps[i].first;
      }
      sizeout = answer.toInts(out);
      return unpackVolume;
    } else {
      sort(shortlists.begin(), shortlists.end());
      sort(bitmaps.begin(), bitmaps.end());
      if (shortlists.size() == 1) {
        sizeout = shortlists[0].second->decompress(out);
        unpackVolume += shortlists[0].second->Length;
      } else {
        unpackVolume += shortlists[0].second->Length;
        unpackVolume += shortlists[1].second->Length;
        sizeout = shortlists[0].second->intersect(*shortlists[1].second, out);
        for (uint32_t i = 2; (sizeout > 0) && (i < shortlists.size()); ++i) {
          unpackVolume += shortlists[i].first;
          sizeout = shortlists[i].second->intersect(out, (uint32_t)sizeout, out);
        }
      }
      size_t pos = 0;
      for (uint32_t i = 0; (sizeout > 0) && (i < bitmaps.size()); ++i) {
        unpackVolume += bitmaps[i].first;
        shared_ptr<BoolArray> &ba = bitmaps[i].second;
        pos = 0;
        for (uint32_t ii = 0; ii < sizeout; ++ii) {
          if (!ba->get(out[ii]))
            continue;
          else
            out[pos++] = out[ii];
        }
        sizeout = pos;
      }
      return unpackVolume;
    }
  }

  ~SkippingHybM2() {}

  /**
   * Estimate of the volume of data used by this object.
   */
  size_t storageInBytes() const {
    size_t answer = 0;
    for (auto i : bitmapmap)
      answer += i.second->sizeInBytes();
    for (auto i : shortlistmap)
      answer += i.second->storageInBytes();
    return answer;
  }

private:
  /**
   * Load an array (data) of length "length" as the posting list corresponding
   * to id postid
   * as a bitmap.
   *
   * Do not call this directly, call load() instead.
   */
  size_t loadAsBitmap(const uint32_t postid, const uint32_t *data,
                      const uint32_t length) {
    if (bitmapmap.find(postid) != bitmapmap.end())
      return 0;
    BoolArray *ba = new BoolArray(mMaxId);
    for (uint32_t k = 0; k < length; ++k)
      ba->set(data[k]);
    bitmapmap[postid] = shared_ptr<BoolArray>(ba);
    mapuncompsizes[postid] = length;
    return ba->sizeInBytes() / sizeof(uint32_t);
  }

  /**
   * Load an array (data) of length "length" as the posting list corresponding
   * to id postid
   * as a short array.
   *
   * Do not call this directly, call load() instead.
   */
  size_t loadAsShortArray(const uint32_t postid, const uint32_t *data,
                          const uint32_t length) {
    if (shortlistmap.find(postid) != shortlistmap.end())
      return 0;

    Skipping *compressedbuffer = new Skipping(BlockSizeLog, data, length);
    shortlistmap[postid] = shared_ptr<Skipping>(compressedbuffer);
    return compressedbuffer->storageInBytes() / sizeof(uint32_t);
  }

  map<uint32_t, shared_ptr<BoolArray>> bitmapmap;
  map<uint32_t, shared_ptr<Skipping>> shortlistmap;
  map<uint32_t, uint32_t> mapuncompsizes;

  const size_t mMaxId; // max value that can be stored in a list
  const size_t threshold; //// 32 seems to be the recommended setting, no need
                          ///to change it?
  uint32_t BlockSizeLog;
};
} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_HYBM2_H_ */
