/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 */


#include <unistd.h>
#include "synthetic.h"
#include "timer.h"
#include "intersection.h"

// https://code.google.com/p/likwid/wiki/LikwidPerfCtr#Using_the_marker_API
#ifdef LIKWID_MARKERS  // see 'make likwidintersection' for compiler flags
#include <likwid.h>
#endif

/**
 * Goal: have the largest array count about 4M terms (this
 * matches our experiments), and vary the size of the
 * smallest array vary from 1*4M to 1/1000*4M (or so).
 *
 * Set the size of the intersection to 30% of the lesser
 * array. (Again, this matches our real data...)
 *
 * To match our clueweb, we use a range of values in [0,2**26).
 */
template <class generator>
pair<vector<uint32_t>, vector<uint32_t>> getNaivePair(generator gen, uint32_t minlength, uint32_t Max, float sizeratio,
float intersectionratio) {
    if (sizeratio < 1) throw runtime_error("sizeratio should be larger or equal to 1");
    if (intersectionratio < 0) throw runtime_error("intersectionratio should be positive");
    if (intersectionratio > 1) throw runtime_error("intersectionratio cannot be larger than 1");
    const uint32_t maxlenth = static_cast<uint32_t>(round(static_cast<float>(minlength) * sizeratio));
    if (maxlenth > Max)  throw runtime_error("I can't generate an array so large in such a small range.");
    if (maxlenth < minlength) throw runtime_error("something went wrong, possibly an overflow.");
    // we basically assume that, if we do nothing, intersections are very small
    const uint32_t intersize = static_cast<uint32_t>(round(static_cast<float>(minlength) * intersectionratio));

    vector<uint32_t> inter = gen.generate(intersize, Max);
    vector<uint32_t> smallest =  unite(gen.generate(static_cast<uint32_t>(minlength - inter.size()), Max), inter);
    vector<uint32_t> largest = unite(gen.generate(static_cast<uint32_t>(maxlenth - inter.size()), Max), inter);
    vector<uint32_t> intersection = intersect(smallest, largest);
    if (largest.size() > smallest.size())
        return pair<vector<uint32_t>, vector<uint32_t>>(smallest, largest);
    return pair<vector<uint32_t>, vector<uint32_t>>(largest, smallest);

}



void printusage() {
#ifdef LIKWID_MARKERS
    cout << "example: likwid -m -C 1 -g BRANCH ./likwidintersection -u > uniform.out" << endl;
#else
    cout << " -u switches to uniform distribution" << endl;
#endif
}

int main(int argc, char **argv) {
    size_t howmany = 0;
    size_t loop = 3;
    bool uniform = false;
    uint32_t Big = 22;
    float intersectionratio = 0.3f;
    uint32_t MaxBit = 26;
    int c;
    while ((c = getopt(argc, argv, "uns:m:R:M:S:l:h")) != -1)
        switch (c) {
        case 'h':
            printusage();
            return 0;
        case 'S':
            Big = atoi(optarg);
            break;
        case 'R':
            intersectionratio = atof(optarg);
            break;
        case 'M':
            intersectionratio = atoi(optarg);
            if (MaxBit < 1) {
                printusage();
                return -1;
            }
            break;
        case 'm':
            howmany = atoi(optarg);
            if (howmany < 1) {
                printusage();
                return -1;
            }
            break;
        case 'l':
            loop = atoi(optarg);
            if (loop < 1) {
                printusage();
                return -1;
            }
            break;
        case 'u':
            uniform = true;
            break;
        default:
            abort();
        }
    if (howmany == 0) {
        howmany = 5;
    }
    cout << "# howmany : " << howmany << endl;
    cout << "# loop : " << loop << endl;
    cout << "# distribution : " << (uniform ? "uniform" : "clustered") << endl;
    cout << "# Big : " << Big << endl;
    cout << "# intersectionratio : " << intersectionratio << endl;
    cout << "# MaxBit : " << MaxBit << endl;
    UniformDataGenerator udg;
    ClusteredDataGenerator cdg;
    WallClockTimer z;
    size_t bogus = 0;
    vector <uint32_t> buffer(2 * (1U << Big));
#ifdef LIKWID_MARKERS
    char currentMarker[64];
    likwid_markerInit();
#endif

    cout << "# size-ratio\t";
    for (string intername : IntersectionFactory::allNames()) {
        cout << intername << "\t";
    }
    cout << "relative-intersection-size " << endl;

    for (float ir = 1.001; ir <= 10000; ir = ir * sqrt(1.9)) {
        vector <pair<vector<uint32_t> , vector<uint32_t>>> data(howmany);
        uint32_t smallsize = static_cast<uint32_t>(round(static_cast<float>(1 << Big) / ir));
        cout << "#generating data...";
        cout.flush();
        for (size_t k = 0; k < howmany; ++k) {
            data[k] = uniform ? getNaivePair(udg , smallsize, 1U << MaxBit, ir, intersectionratio)
                      : getNaivePair(cdg , smallsize, 1U << MaxBit, ir, intersectionratio);
        }
        cout << "ok." << endl;
        cout << ir << "\t";
        float aratio = 0.0f;
        for (string intername : IntersectionFactory::allNames()) {
            intersectionfunction interfnc = IntersectionFactory::getFromName(intername);
            size_t volume = 0;
#ifdef LIKWID_MARKERS
            snprintf(currentMarker, sizeof(currentMarker), "%s %.2f", intername.c_str(), ir);
            likwid_markerStartRegion(currentMarker);
#endif
            z.reset();
            for (size_t k = 0; k < data.size(); ++k) {
                volume += (data[k].first.size() + data[k].second.size()) * loop;
                for (size_t L = 0; L < loop; ++L) {
                    aratio = interfnc(data[k].first.data(),
                                      (data[k].first).size(), data[k].second.data(),
                                      (data[k].second).size(), buffer.data());
                    bogus += aratio;
                }
            }
            cout << setw(10) << setprecision(5) << (volume / (static_cast<double>(z.split()))) << "\t";
#ifdef LIKWID_MARKERS
            likwid_markerStopRegion(currentMarker);
#endif
        }
        cout << "\t\t" << aratio / smallsize;
        cout << endl;

    }
#ifdef LIKWID_MARKERS
    likwid_markerClose();
#endif

    cout << "# bogus = " << bogus << endl;
}
