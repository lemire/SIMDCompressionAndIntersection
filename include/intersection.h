

#ifndef SIMDCompressionAndIntersection_INTERSECTION_H_
#define SIMDCompressionAndIntersection_INTERSECTION_H_

#include <common.h>

namespace SIMDCompressionLib {

using namespace std;
/*
 * Given two arrays, this writes the intersection to out. Returns the
 * cardinality of the intersection.
 */
typedef size_t (*intersectionfunction)(const uint32_t *set1,
                                       const size_t length1,
                                       const uint32_t *set2,
                                       const size_t length2, uint32_t *out);

/*
 * Given two arrays, this writes the intersection to out. Returns the
 * cardinality of the intersection.
 *
 * This is a mix of very fast vectorized intersection algorithms, several
 * designed by N. Kurz, with adaptations by D. Lemire.
 */
size_t SIMDintersection(const uint32_t *set1, const size_t length1,
                        const uint32_t *set2, const size_t length2,
                        uint32_t *out);

#ifdef __AVX2__
#include <immintrin.h>

/*
 * Straight port of SIMDintersection to AVX2.
 */
size_t SIMDintersection_avx2(const uint32_t *set1, const size_t length1,
                        const uint32_t *set2, const size_t length2,
                        uint32_t *out);

#endif
/*
 * Given two arrays, this writes the intersection to out. Returns the
 * cardinality of the intersection.
 *
 * This is a well-written, but otherwise unsophisticated function.
 * Written by N. Kurz.
 */
size_t scalar(const uint32_t *set1, const size_t length1,
                   const uint32_t *set2, const size_t length2, uint32_t *out);

/*
 * Given two arrays, this writes the intersection to out. Returns the
 * cardinality of the intersection.
 *
 * This applies a state-of-the-art algorithm. First coded by O. Kaser, adapted
 * by D. Lemire.
 */
size_t onesidedgallopingintersection(const uint32_t *smallset,
                                     const size_t smalllength,
                                     const uint32_t *largeset,
                                     const size_t largelength, uint32_t *out);

class IntersectionFactory {
public:
  static std::map<std::string, intersectionfunction> intersection_schemes;

  static vector<string> allNames() {
    vector<string> ans;
    for (auto i = intersection_schemes.begin(); i != intersection_schemes.end();
         ++i) {
      ans.push_back(i->first);
    }
    return ans;
  }

  static string getName(intersectionfunction v) {
    for (auto i = intersection_schemes.begin(); i != intersection_schemes.end();
         ++i) {
      if (i->second == v)
        return i->first;
    }
    return "UNKNOWN";
  }

  static bool valid(string name) {
    return (intersection_schemes.find(name) != intersection_schemes.end());
  }

  static intersectionfunction getFromName(string name) {
    if (intersection_schemes.find(name) == intersection_schemes.end()) {
      cerr << "name " << name << " does not refer to an intersection procedure."
           << endl;
      cerr << "possible choices:" << endl;
      for (auto i = intersection_schemes.begin();
           i != intersection_schemes.end(); ++i) {
        cerr << static_cast<string>(i->first)
             << endl; // useless cast, but just to be clear
      }
      return NULL;
    }
    return intersection_schemes[name];
  }
};

} // namespace SIMDCompressionLib

#endif /* SIMDCompressionAndIntersection_INTERSECTION_H_ */
