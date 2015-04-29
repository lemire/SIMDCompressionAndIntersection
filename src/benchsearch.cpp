#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "codecfactory.h"

#ifdef _MSC_VER
# include <windows.h>

__int64 freq;

typedef __int64 time_snap_t;

static time_snap_t time_snap(void)
{
	__int64 now;

	QueryPerformanceCounter((LARGE_INTEGER *)&now);

	return (__int64)((now*1000000)/freq);
}
# define TIME_SNAP_FMT "%I64d"
#else
# define time_snap clock
# define TIME_SNAP_FMT "%lu"
typedef clock_t time_snap_t;
#endif

template<typename T>
int benchmarkSelect() {
	T codec;
	static const size_t N = 128;
    uint32_t buffer[N];
    uint32_t backbuffer[N];
    uint32_t b;
    time_snap_t S1, S2, S3;
    size_t i;
    printf("# benchmarking select %s \n",codec.name().c_str());

    /* this test creates delta encoded buffers with different bits, then
     * performs lower bound searches for each key */
    for (b = 0; b <= 32; b++) {
        uint32_t out[N * 2];
        uint32_t prev = 0;
        /* initialize the buffer */
        for (i = 0; i < N; i++) {
            buffer[i] =  ((uint32_t)(1655765 * i )) ;
            if(b < 32) buffer[i] %= (1<<b);
        }
        for (i = 0; i < N; i++) {
            buffer[i] = buffer[i] + prev;
            prev = buffer[i];
        }

        for (i = 1; i < N; i++) {
            if(buffer[i] < buffer[i-1] )
                buffer[i] = buffer[i-1];
        }

        for (i = 0; i < N; i++) {
            out[i] = 0; /* memset would do too */
        }

        /* delta-encode to 'i' bits */
        size_t nvalue = 2 * N;
        codec.encodeArray(buffer, N,out,nvalue);

        S1 = time_snap();
        for (i = 0; i < N * 10; i++) {
        	uint32_t valretrieved =  codec.select(out, i % N);
            if(valretrieved != buffer[i%N]) {
            	return -1;
            }
        }
        S2 = time_snap();
        for (i = 0; i < N * 10; i++) {
        	size_t recovlength = N;
        	codec.decodeArray(out,nvalue,backbuffer,recovlength);
            if(backbuffer[i % N] != buffer[i % N]) {
            	return -1;
            }
        }
        S3 = time_snap();
        printf("# bit width = %d, fast select function time = " TIME_SNAP_FMT ", naive time = " TIME_SNAP_FMT "  \n", b, (S2-S1), (S3-S2));
        printf("%d " TIME_SNAP_FMT " " TIME_SNAP_FMT " \n",b, (S2-S1), (S3-S2));
    }
    printf("\n\n");
    return 0;
}

int uint32_cmp(const void *a, const void *b)
{
    const uint32_t *ia = (const uint32_t *)a;
    const uint32_t *ib = (const uint32_t *)b;
    if(*ia < *ib)
        return -1;
    else if (*ia > *ib)
        return 1;
    return 0;
}

/* adapted from wikipedia */
int binary_search(uint32_t * A, uint32_t key, int imin, int imax)
{
    int imid;
    imax --;
    while(imin + 1 < imax) {
        imid = imin + ((imax - imin) / 2);

        if (A[imid] > key) {
            imax = imid;
        } else if (A[imid] < key) {
            imin = imid;
        } else {
            return imid;
        }
    }
    return imax;
}


/* adapted from wikipedia */
int lower_bound(uint32_t * A, uint32_t key, int imin, int imax)
{
    int imid;
    imax --;
    while(imin + 1 < imax) {
        imid = imin + ((imax - imin) / 2);

        if (A[imid] >= key) {
            imax = imid;
        } else if (A[imid] < key) {
            imin = imid;
        }
    }
    if(A[imin] >= key) return imin;
    return imax;
}


template<typename T>
int benchmarkSearch() {
	static const size_t N = 128;
	T codec;
	uint32_t buffer[N];
    uint32_t backbuffer[N];
    uint32_t out[N * 2];
    uint32_t result, initial = 0;
    uint32_t b, i;
    time_snap_t S1, S2, S3;
    printf("# benchmarking search %s \n",codec.name().c_str());

    /* this test creates delta encoded buffers with different bits, then
     * performs lower bound searches for each key */
    for (b = 0; b <= 32; b++) {
        uint32_t prev = initial;
        /* initialize the buffer */
        for (i = 0; i < N; i++) {
            buffer[i] =  ((uint32_t)rand()) ;
            if(b < 32) buffer[i] %= (1<<b);
        }

        qsort(buffer,N, sizeof(uint32_t), uint32_cmp);

        for (i = 0; i < N; i++) {
            buffer[i] = buffer[i] + prev;
            prev = buffer[i];
        }
        for (i = 1; i < N; i++) {
            if(buffer[i] < buffer[i-1] )
                buffer[i] = buffer[i-1];
        }
        for (i = 0; i < N; i++) {
            out[i] = 0; /* memset would do too */
        }
        size_t nvalue = N * 2;

        codec.encodeArray(buffer, N,out,nvalue);
		{
			size_t recovlength = N;
			codec.decodeArray(out, nvalue, backbuffer, recovlength);
			assert(recovlength == N);
			for (size_t k = 0; k < N; k++) {
				assert(backbuffer[k] == buffer[k]);
			}
		}
        S1 = time_snap();
        for (i = 0; i < N * 10; i++) {
            uint32_t pseudorandomkey  =  buffer[i%N];
            uint32_t result = 0;
            size_t pos = codec.findLowerBound(out, nvalue, pseudorandomkey, &result);
            if((result < pseudorandomkey) || (buffer[pos] != result)) {
                printf("bug A: pseudorandomkey = %u result = %u  buffer[%zu] = %u .\n",pseudorandomkey, result,pos,buffer[pos]);
                return -1;
            } else if (pos > 0) {
                if(buffer[pos-1] >= pseudorandomkey) {
                    printf("bug B.\n");
                    return -1;
                }
            }
        }
        S2 = time_snap();
        for (i = 0; i < N * 10; i++) {
            int pos;
            uint32_t pseudorandomkey  =  buffer[i%N];
            size_t recovlength = N;
        	codec.decodeArray(out,nvalue,backbuffer,recovlength);
            pos =  lower_bound(backbuffer, pseudorandomkey, 0, N);
            result = backbuffer[pos];

            if((result < pseudorandomkey) || (buffer[pos] != result)) {
                printf("bug C.\n");
                return -1;
            } else if (pos > 0) {
                if(buffer[pos-1] >= pseudorandomkey) {
                    printf("bug D.\n");
                    return -1;
                }
            }
        }
        S3 = time_snap();
        printf("# bit width = %d, fast search function time = " TIME_SNAP_FMT ", naive time = " TIME_SNAP_FMT  " \n", b, (S2-S1), (S3-S2) );
        printf("%d " TIME_SNAP_FMT " " TIME_SNAP_FMT " \n",b, (S2-S1), (S3-S2));
    }
    printf("\n\n");
    return 0;
}


int main() {
	int r = 0;
#ifdef _MSC_VER
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
#endif

    r = benchmarkSearch<SIMDCompressionLib::VarIntGB<true>>();
    if(r < 0) return r;
    r = benchmarkSearch<SIMDCompressionLib::MaskedVByte<true>>();
    if(r < 0) return r;
    r = benchmarkSearch<SIMDCompressionLib::VariableByte<true>>();
    if(r < 0) return r;
    r = benchmarkSearch<SIMDCompressionLib::VByte<true>>();
    if(r < 0) return r;

    r = benchmarkSelect<SIMDCompressionLib::VarIntGB<true>>();
    if(r < 0) return r;
    r = benchmarkSelect<SIMDCompressionLib::MaskedVByte<true>>();
    if(r < 0) return r;
    r = benchmarkSelect<SIMDCompressionLib::VariableByte<true>>();
    if(r < 0) return r;
    r = benchmarkSelect<SIMDCompressionLib::VByte<true>>();
    if(r < 0) return r;
    return 0;
}




