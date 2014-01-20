SIMDCompressionAndIntersection
======================

As the name suggests, this is a C/C++ library for fast
compression and intersection of lists of sorted integers using
SIMD instructions. The library focuses on innovative techniques
and very fast schemes, with particular attention to differential
coding. It introduces new SIMD intersections schemes such as
SIMD Galloping.

Authors: Leonid Boystov, Nathan Kurz and Daniel Lemire
With some contributions from Owen Kaser and others.

Simple demo
------------------------

Check out example.cpp

You can run it like so:

make example
./example

Usage
------------------------

make
./unit

To run tests, you can do 

./testcodecs

(follow the instructions)



Comparison with the FastPFOR C++ library
-----------------------------------------

The FastPFOR C++ Library available at https://github.com/lemire/FastPFor
implements some of the same compression schemes except that
it is not optimized for the compression of sorted lists of integers.


Licensing
------------------------

Apache License, Version 2.0

As far as the authors know, this work is patent-free.

Requirements
------------------------

A desktop CPU (AMD or Intel) with support for SSE 4.1* (Penryn  [2007] processors or better). 


A recent GCC (4.7 or better), Clang or Intel compiler.

A processor support AVX (Intel or AMD).

Tested on Linux and MacOS. It should be portable to Windows and other platforms.

*- The default makefile might assume AVX support, but AVX is not required. For GCC
compilers you might need the -msse4.1 flag, and you will not need the -mavx flag.

For advanced benchmarking, please see

advancedbenchmarking/README.md

where there is additional information.


Acknowledgement
------------------------

Thanks to Kelly Sommers for useful feedback.

