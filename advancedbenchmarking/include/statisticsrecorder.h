/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 */
#

#ifndef SIMDCompressionAndIntersection_STATISTICSRECORDER_H_
#define SIMDCompressionAndIntersection_STATISTICSRECORDER_H_

#include "common.h"
#include "timer.h"

class StatisticsRecorder {
public:
  StatisticsRecorder() : ss(), timer(), timesinmicros() {
    ss << "# timeinms intersectionsize size1 size2 ..." << endl;
    timesinmicros.reserve(5000); // 40KB buffer
  }

  /**
   * Call this before each new query
   */
  inline void prepareQuery() { timer.reset(); }

  /**
   * Call this before after each query
   */
  template <class SizeProvider>
  inline void endQuery(size_t intersectionsize, SizeProvider &sizeprovider,
                       const vector<uint32_t> &PostIds) {
    uint64_t timeinmicroseconds = timer.split();
    timesinmicros.push_back(timeinmicroseconds);
    ss << timeinmicroseconds << "\t";
    ss << intersectionsize << "\t";
    for (uint32_t id : PostIds) {
      ss << sizeprovider.getSizeInInts(id) << "\t";
    }
    ss << endl;
  }

  // average time in ms per query
  double averageTimeInMS() const {
    if (timesinmicros.size() == 0)
      return 0;
    return static_cast<double>(
               std::accumulate(timesinmicros.begin(), timesinmicros.end(), 0)) *
           0.001 / static_cast<double>(timesinmicros.size());
  }

  // average time in ms per query
  double medianTimeInMS() const {
    if (timesinmicros.size() == 0)
      return 0;
    vector<uint64_t> buffer(timesinmicros);
    sort(buffer.begin(), buffer.end());
    return static_cast<double>(buffer[buffer.size() / 2]) *
           0.001; // not *exactly* the median but close enough
  }

  // average time in ms per query
  double ninetypercentileTimeInMS() const {
    if (timesinmicros.size() == 0)
      return 0;
    vector<uint64_t> buffer(timesinmicros);
    sort(buffer.begin(), buffer.end());
    return static_cast<double>(
               buffer[static_cast<size_t>(round(buffer.size() * 0.9))]) *
           0.001; // not *exactly* the 90 perc. but close enough
  }

  /**
   * Dump the CSV data
   */
  void output(ostream &out) { out << ss.str(); }

  void reset() {
    ss.str("");
    ss.seekp(0);
    ss.seekg(0);
    timesinmicros.clear();
  }

private:
  stringstream ss;
  WallClockTimer timer;
  vector<uint64_t> timesinmicros;
};

#endif /* SIMDCompressionAndIntersection_STATISTICSRECORDER_H_ */
