/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 */
#ifndef SIMDCompressionAndIntersection_BUDGETEDPOSTINGCOLLECTOR_H_
#define SIMDCompressionAndIntersection_BUDGETEDPOSTINGCOLLECTOR_H_

#include "common.h"
#include "util.h"
#include "maropuparser.h"
#include "intersection.h"

using namespace SIMDCompressionLib;

/*
 * This class reads postings until their total size is below a threshold (memory
 * budget).
 * It encapsulates an out-of-order posting retrieval. It is not straightforward,
 * because
 * the posting file format lacks a dictionary.
 */
class BudgetedPostingCollector {
public:
  BudgetedPostingCollector(const string &postFileName, size_t memBudget)
      : seenOffsets(0), readPostings(), gapReader(postFileName),
        memBudget(memBudget), memUsed(0) {
    if (!gapReader.open()) {
      throw runtime_error(" could not open " + postFileName +
                          " for reading...");
    }
    readOffsets();
  }

  ~BudgetedPostingCollector() { gapReader.close(); }

  /*
  * checks whether the posting list index is between 0 and getMaxPostQty()
  */
  bool valid(uint32_t postId) { return postId < seenOffsets.size(); }

  /*
   * Returns false, when the memory budget is exhausted.
   * Throws an exception in case of an error. It is assumed
   * that postId is a valid identifier (call valid() to check).
   */
  bool loadOnePost(uint32_t postId) {
    if (readPostings.find(postId) != readPostings.end())
      return true; // already loaded, nothing to do
    assert(valid(postId));
    gapReader.setPos(seenOffsets[postId]);
    if (!gapReader.loadIntegers(readPostings[postId])) {
      stringstream err;
      err << "Cannot read posting list, id = " << postId;
      throw runtime_error(err.str());
    }
    if (!is_strictlysorted(readPostings[postId].begin(),
                           readPostings[postId].end())) {
      stringstream err;
      err << "Posting list is not in sorted order, id = " << postId;
      throw runtime_error("not in sorted order");
    }
    size_t qty = readPostings[postId].size();
    readPostings[postId].shrink_to_fit(); // may or may not be useful
    if (qty == 0)
      cout << "[WARNING] Empty posting  list found." << endl;
    size_t addMem = qty * sizeof(uint32_t);
    if (memUsed + addMem > memBudget) {
      readPostings.erase(postId);
      return false;
    }
    memUsed += addMem;
    return true;
  }
  /*
   * Returns false, when the memory budget is exhausted.
   * Throws an exception in case of an error.
   * It is assume that all ideas are valid (call valid()).
   *
   * this is basically a convenience wrapper around loadOnePost.
   */
  bool loadPostings(const vector<uint32_t> &postIds) {
    for (const auto id : postIds) {
      if (!loadOnePost(id))
        return false;
    }
    return true;
  }

  /*
  * how many posting lists are there to be loaded?
  * this is not necessarily the total number of buffered
  * posting lists.
  */
  size_t getMaxPostQty() const { return seenOffsets.size(); }

  /**
   * This finds the largest and smallest document ID from a set of queries.
   */
  pair<uint32_t, uint32_t>
  findDocumentIDRange(const vector<vector<uint32_t>> &allPostIds) {
    uint32_t largestpossible = numeric_limits<uint32_t>::max();
    uint32_t smallestpossible = 0;
    pair<uint32_t, uint32_t> answer =
        make_pair(largestpossible, smallestpossible);
    for (const vector<uint32_t> &qids : allPostIds) {
      for (uint32_t id : qids) {
        vector<uint32_t> &onePost = getOnePost(id);
        if (onePost.empty())
          continue;
        if (onePost.front() < answer.first)
          answer.first = onePost.front();
        if (onePost.back() > answer.second)
          answer.second = onePost.back();
      }
    }
    if (answer.first > answer.second) {
      cout << "[WARNING] invalid range because no data." << endl;
      answer.second = answer.first;
    }
    return answer;
  }

  /**
   * Given a set of queries, this will find the size of the largest
   * posting list corresponding to one of the IDs being queried.
   * Before calling this function, the data should have be
   * pre-loaded using the function loadOnePost or loadPostings;
   * an exception is thrown otherwise.
   */
  size_t findMaxPostingSize(const vector<vector<uint32_t>> &allPostIds) {
    size_t MaxPostingSize(0);
    for (const vector<uint32_t> &qids : allPostIds) {
      for (uint32_t id : qids) {
        vector<uint32_t> &onePost = getOnePost(id);
        if (MaxPostingSize < onePost.size())
          MaxPostingSize = onePost.size();
      }
    }
    return MaxPostingSize;
  }
  /*
   * Before getOnePost are called, the data should be
   * pre-loaded using the function loadOnePost or loadPostings;
   * an exception is thrown otherwise.
   */
  vector<uint32_t> &getOnePost(uint32_t postId) {
    if (readPostings.find(postId) == readPostings.end()) {
      throw runtime_error(
          "Should call loadIntegers before can access postings!");
    }
    return readPostings[postId];
  }

  size_t getSizeInInts(uint32_t postId) { return getOnePost(postId).size(); }

  /**
   * Flushes all posting lists, recovering the memory.
   */
  void clear() {
    readPostings.clear();
    memUsed = 0;
  }

  /**
   * Given a set of posting IDs, compute the corresponding intersection.
   * This is *specifically* not meant to be fast. Do not use if you need
   * good speed. (It *may* be fast... but it is not the design goal.)
   *
   *  The data should be pre-loaded using the function loadOnePost or
   * loadPostings;
   * an exception is thrown otherwise.
   */
  vector<uint32_t> computeIntersection(const vector<uint32_t> &qids,
                                       intersectionfunction Inter) {
    vector<uint32_t> inter;
    if (qids.empty())
      return inter;
    vector<pair<uint32_t, uint32_t>> sizeids;
    for (uint32_t i : qids) {
      sizeids.emplace_back(make_pair(getOnePost(i).size(), i));
    }
    sort(sizeids.begin(), sizeids.end());
    inter = getOnePost(sizeids.front().second);
    size_t intersize = inter.size();
    for (size_t k = 1; k < qids.size(); ++k) {
      intersize =
          Inter(inter.data(), intersize, getOnePost(sizeids[k].second).data(),
                getOnePost(sizeids[k].second).size(), inter.data());
    }
    inter.resize(intersize);
    return inter;
  }

  size_t getMemUsed() const { return memUsed; }

  /**
  * this function is called by the constructor. It recovers all
  * of the location of the posting lists. So if you have 1000,000 posting lists,
  * this could amount to sizeof(off_t) * 1000000 bytes. So maybe 8MB.
  *
  * Note that we don't normally keep all of the posting lists themselves in RAM.
  */
  void readOffsets() {
    seenOffsets.clear();
    off_t pos;
    uint32_t qty;
    while (true) {
      if (!gapReader.readNextPosAndQty(pos, qty)) {
        return;
      }
      seenOffsets.emplace_back(pos);
    }
  }

private:
  // we make the copy constructor private to prevent the compiler from
  // autogenerating one
  BudgetedPostingCollector(const BudgetedPostingCollector &);
  // we don't want people to use the assignment operator.
  BudgetedPostingCollector &operator=(const BudgetedPostingCollector &);

  /*
   * The class "knows" all offsets for posting ids from 0 to seenOffsets.size()
   * - 1
   * Yet, some of the posting pointers can be null. For example, we start
   * with an empty posting list collector and get a request to read posting with
   * 10.
   */
  vector<off_t> seenOffsets; // location of the postings
  unordered_map<off_t, vector<uint32_t>> readPostings; // accumulated postings

  MaropuGapReader gapReader; // reader to recover the postings
  size_t memBudget;
  size_t memUsed;
};

#endif /* SIMDCompressionAndIntersection_BUDGETEDPOSTINGCOLLECTOR_H_ */
