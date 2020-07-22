SIMDCompressionAndIntersection
======================
[![Build Status](https://travis-ci.org/lemire/SIMDCompressionAndIntersection.png)](https://travis-ci.org/lemire/SIMDCompressionAndIntersection)
[![Code Quality: Cpp](https://img.shields.io/lgtm/grade/cpp/g/lemire/SIMDCompressionAndIntersection.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/lemire/SIMDCompressionAndIntersection/context:cpp)


As the name suggests, this is a C/C++ library for fast
compression and intersection of lists of sorted integers using
SIMD instructions. The library focuses on innovative techniques
and very fast schemes, with particular attention to differential
coding. It introduces new SIMD intersections schemes such as
SIMD Galloping.

This library can decode at least 4 billions of compressed integers per second on most
desktop or laptop processors. That is, it can decompress data at a rate of 15 GB/s.
This is significantly faster than generic codecs like gzip, LZO, Snappy or LZ4.

Authors: Leonid Boystov, Nathan Kurz,  Daniel Lemire,
Owen Kaser, Andrew Consroe, Shlomi Vaknin, Christoph Rupp, Bradley Grainger, and others.

Documentation
-----------------------

* Daniel Lemire, Nathan Kurz, Christoph Rupp, Stream VByte: Faster Byte-Oriented Integer Compression, Information Processing Letters 130, 2018 https://arxiv.org/abs/1709.08990
* Daniel Lemire, Leonid Boytsov, Nathan Kurz, SIMD Compression and the Intersection of Sorted Integers, Software Practice & Experience 46 (6), 2016 http://arxiv.org/abs/1401.6399
* Daniel Lemire and Leonid Boytsov, Decoding billions of integers per second through vectorization, Software Practice & Experience 45 (1), 2015.  http://arxiv.org/abs/1209.2137 http://onlinelibrary.wiley.com/doi/10.1002/spe.2203/abstract
* Jeff Plaisance, Nathan Kurz, Daniel Lemire, Vectorized VByte Decoding, International Symposium on Web Algorithms 2015, 2015. http://arxiv.org/abs/1503.07387
* Wayne Xin Zhao, Xudong Zhang, Daniel Lemire, Dongdong Shan, Jian-Yun Nie, Hongfei Yan, Ji-Rong Wen, A General SIMD-based Approach to Accelerating Compression Algorithms, ACM Transactions on Information Systems 33 (3), 2015. http://arxiv.org/abs/1502.01916

This work has also inspired other work such as...

* P. Damme, D. Habich, J. Hildebrandt, W. Lehner, Lightweight Data Compression Algorithms: An Experimental Survey (Experiments and Analyses), EDBT 2017 http://openproceedings.org/2017/conf/edbt/paper-146.pdf
* P. Damme, D. Habich, J. Hildebrandt, W. Lehner, Insights into the Comparative Evaluation of Lightweight Data Compression Algorithms, EDBT 2017 http://openproceedings.org/2017/conf/edbt/paper-414.pdf
* T. D. Wu, Bitpacking techniques for indexing genomes: I. Hash tables, Algorithms for Molecular Biology 11 (5), 2016. http://almob.biomedcentral.com/articles/10.1186/s13015-016-0069-5
* Jianguo Wang, Chunbin Lin, Yannis Papakonstantinou, Steven Swanson, An Experimental Study of Bitmap Compression vs. Inverted List Compression, SIGMOD 2017 http://db.ucsd.edu/wp-content/uploads/2017/03/sidm338-wangA.pdf

Simple demo
------------------------

Check out example.cpp

You can run it like so:

```
make example
./example
```


Usage
------------------------

```
make
./unit
```

To run tests, you can do 
```
./testcodecs
```

(follow the instructions)


For a simple C library
----------------------

This library is a C++ research library. For something simpler,
written in C, see:

https://github.com/lemire/simdcomp


Comparison with the FastPFOR C++ library
-----------------------------------------

The FastPFOR C++ Library available at https://github.com/lemire/FastPFor
implements some of the same compression schemes except that
it is not optimized for the compression of sorted lists of integers.

Other recommended libraries
---------------------------------

* libvbyte: A fast implementation for varbyte 32bit/64bit integer compression https://github.com/cruppstahl/libvbyte
* TurboPFor is a C library that offers lots of interesting optimizations. Well worth checking! (GPL license) https://github.com/powturbo/TurboPFor
* Oroch is a C++ library that offers a usable API (MIT license) https://github.com/ademakov/Oroch
* CSharpFastPFOR: A C#  integer compression library  https://github.com/Genbox/CSharpFastPFOR
* JavaFastPFOR: A java integer compression library https://github.com/lemire/JavaFastPFOR
* Encoding: Integer Compression Libraries for Go https://github.com/zhenjl/encoding
* FrameOfReference is a C++ library dedicated to frame-of-reference (FOR) compression: https://github.com/lemire/FrameOfReference

Licensing
------------------------

Apache License, Version 2.0

As far as the authors know, this work is patent-free.

Requirements
------------------------

A CPU (AMD or Intel) with support for SSE2 (Pentium 4 or better) is required
while a CPU with SSE 4.1* (Penryn  [2007] processors or better) is recommended. 


A recent GCC (4.7 or better), Clang, Intel or Visual C++ compiler.

A processor support AVX (Intel or AMD).

Tested on Linux, MacOS and Windows. It should be portable to other platforms.

*- The default makefile might assume AVX support, but AVX is not required. For GCC
compilers, you might need the -msse2 flag, but you will not need the -mavx flag.

For advanced benchmarking, please see

advancedbenchmarking/README.md

where there is additional information as well as links to real data sets.


Acknowledgement
------------------------

Thanks to Kelly Sommers for useful feedback.

This work was supported by NSERC grant number 26143.
