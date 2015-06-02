#include "frameofreference.h"




    static uint32_t * pack1_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack2_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack3_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack4_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack5_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 5  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack6_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 6  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack7_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 7  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack8_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack9_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 9  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 9  -  8 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack10_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 10  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 10  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack11_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack12_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 12  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 12  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack13_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  8 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack14_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack15_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  13 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack16_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack17_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  8 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack18_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  16 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack19_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack20_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack21_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  19 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  8 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack22_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  16 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack23_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  19 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack24_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack25_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  15 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  8 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack26_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  16 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack27_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  17 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  24 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack28_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack29_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  26 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  23 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  17 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  8 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack30_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  28 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  26 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  16 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack31_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  30 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  29 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  28 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  27 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  26 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  25 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  24 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack32_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;

        return out;
      }




 static const uint32_t * unpack1_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   & 1  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack2_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 2 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack3_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  )   % (1U << 3 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack4_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack5_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 5 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 5 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack6_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 6 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 6 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack7_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 7 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  17  )   % (1U << 7 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack8_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack9_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 9 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 9 - 8 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack10_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 10 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 10 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 10 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack11_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 11 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 11 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 11 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack12_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 12 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 12 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack13_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 13 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 13 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 13 - 8 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack14_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 14 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 14 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 14 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 14 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack15_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 13 ))<<( 15 - 13 );
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 15 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 15 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 15 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack16_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack17_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 17 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 17 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 17 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 17 - 8 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack18_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 18 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 18 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 18 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 18 - 16 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack19_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 19 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 19 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 19 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 19 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 19 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack20_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 20 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 20 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 20 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 20 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack21_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 21 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 21 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 21 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 19 ))<<( 21 - 19 );
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 21 - 8 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack22_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 22 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 22 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 22 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 22 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 22 - 16 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack23_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 23 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 23 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 23 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 23 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 19 ))<<( 23 - 19 );
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 23 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 23 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 23 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack24_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 24 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 24 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 24 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 24 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 24 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 24 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack25_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 25 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 25 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 25 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 25 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 25 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 25 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 15 ))<<( 25 - 15 );
    *out += base;
    out++;
    *out = ( (*in) >>  15  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 25 - 8 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack26_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 26 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 26 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 26 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 26 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 26 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 26 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 26 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 26 - 16 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack27_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 27 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 27 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 17 ))<<( 27 - 17 );
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 27 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 27 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 27 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 27 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 27 - 24 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack28_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 28 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 28 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 28 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 28 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 28 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 28 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 28 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack29_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 29 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 26 ))<<( 29 - 26 );
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 23 ))<<( 29 - 23 );
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 29 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 17 ))<<( 29 - 17 );
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 29 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 29 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 29 - 8 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack30_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 30 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 28 ))<<( 30 - 28 );
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 26 ))<<( 30 - 26 );
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 30 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 30 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 30 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 30 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 30 - 16 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack31_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 31 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 30 ))<<( 31 - 30 );
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 29 ))<<( 31 - 29 );
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 28 ))<<( 31 - 28 );
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 27 ))<<( 31 - 27 );
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 26 ))<<( 31 - 26 );
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 25 ))<<( 31 - 25 );
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 31 - 24 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack32_8( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }



    static uint32_t * pack1_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack2_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack3_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 3  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack4_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack5_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 5  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 5  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack6_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 6  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 6  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack7_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 7  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 7  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 7  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack8_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack9_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 9  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 9  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 9  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 9  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack10_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 10  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 10  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 10  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 10  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack11_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack12_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 12  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 12  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 12  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 12  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack13_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack14_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack15_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  13 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;

        return out + 1;
      }



    static uint32_t * pack16_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack17_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  16 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack18_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack19_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  17 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  16 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack20_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack21_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  19 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  17 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  16 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack22_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack23_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  19 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  15 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  16 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack24_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack25_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  15 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  19 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  23 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  16 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack26_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack27_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  17 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  19 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  26 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  21 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  16 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack28_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack29_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  26 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  23 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  17 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  28 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  25 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  19 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  16 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack30_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  28 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  26 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack31_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  30 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  29 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  28 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  27 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  26 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  25 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  23 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  21 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  19 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  17 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  16 );
    ++in;

        return out + 1;
      }



    static uint32_t * pack32_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;

        return out;
      }




 static const uint32_t * unpack1_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   & 1  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack2_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack3_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 3 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 3 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack4_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack5_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 5 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 5 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   % (1U << 5 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack6_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 6 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 6 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack7_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 7 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  17  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 7 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 7 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 7 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack8_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack9_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 9 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 9 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  17  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 9 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 9 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 9 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack10_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 10 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 10 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 10 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 10 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack11_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 11 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 11 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 11 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 11 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 11 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 11 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack12_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 12 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 12 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 12 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 12 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack13_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 13 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 13 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 13 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 13 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 13 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 13 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 13 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack14_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 14 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 14 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 14 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 14 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 14 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 14 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack15_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 13 ))<<( 15 - 13 );
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 15 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 15 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 15 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 15 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 15 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 15 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 15 )  ;
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack16_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack17_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 17 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 17 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 17 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 17 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 17 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 17 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 17 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 17 - 16 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack18_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 18 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 18 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 18 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 18 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 18 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 18 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 18 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 18 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack19_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 19 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 19 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 19 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 19 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 19 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 17 ))<<( 19 - 17 );
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 19 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 19 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 19 - 16 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack20_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 20 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 20 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 20 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 20 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 20 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 20 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 20 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 20 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack21_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 21 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 21 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 21 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 19 ))<<( 21 - 19 );
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 21 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 21 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 21 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 17 ))<<( 21 - 17 );
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 21 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 21 - 16 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack22_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 22 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 22 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 22 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 22 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 22 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 22 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 22 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 22 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 22 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 22 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack23_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 23 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 23 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 23 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 23 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 19 ))<<( 23 - 19 );
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 23 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 23 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 23 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 15 ))<<( 23 - 15 );
    *out += base;
    out++;
    *out = ( (*in) >>  15  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 23 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 23 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 23 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 23 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 23 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 23 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 23 - 16 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack24_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 24 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 24 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 24 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 24 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 24 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 24 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 24 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 24 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 24 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 24 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 24 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 24 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack25_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 25 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 25 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 25 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 25 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 25 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 25 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 15 ))<<( 25 - 15 );
    *out += base;
    out++;
    *out = ( (*in) >>  15  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 25 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 25 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 25 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 19 ))<<( 25 - 19 );
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 25 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 25 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 25 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 23 ))<<( 25 - 23 );
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 25 - 16 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack26_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 26 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 26 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 26 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 26 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 26 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 26 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 26 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 26 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 26 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 26 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 26 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 26 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 26 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 26 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 26 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack27_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 27 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 27 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 17 ))<<( 27 - 17 );
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 27 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 27 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 27 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 27 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 27 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 19 ))<<( 27 - 19 );
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 27 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 27 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 27 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 27 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 26 ))<<( 27 - 26 );
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 21 ))<<( 27 - 21 );
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 27 - 16 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack28_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 28 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 28 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 28 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 28 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 28 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 28 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 28 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 28 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 28 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 28 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 28 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 28 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 28 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 28 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack29_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 29 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 26 ))<<( 29 - 26 );
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 23 ))<<( 29 - 23 );
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 29 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 17 ))<<( 29 - 17 );
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 29 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 29 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 29 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 29 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 29 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 29 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 28 ))<<( 29 - 28 );
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 25 ))<<( 29 - 25 );
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 29 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 19 ))<<( 29 - 19 );
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 29 - 16 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack30_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 30 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 28 ))<<( 30 - 28 );
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 26 ))<<( 30 - 26 );
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 30 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 30 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 30 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 30 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 30 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 30 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 30 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 30 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 30 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 30 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 30 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 30 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack31_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 31 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 30 ))<<( 31 - 30 );
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 29 ))<<( 31 - 29 );
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 28 ))<<( 31 - 28 );
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 27 ))<<( 31 - 27 );
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 26 ))<<( 31 - 26 );
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 25 ))<<( 31 - 25 );
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 31 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 23 ))<<( 31 - 23 );
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 31 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 21 ))<<( 31 - 21 );
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 31 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 19 ))<<( 31 - 19 );
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 31 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 17 ))<<( 31 - 17 );
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 31 - 16 );
    *out += base;
    out++;

        return in + 1;
      }




 static const uint32_t * unpack32_16( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }



    static uint32_t * pack1_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack2_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack3_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 3  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 3  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack4_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack5_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 5  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 5  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 5  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 5  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack6_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 6  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 6  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 6  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 6  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack7_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 7  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 7  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 7  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 7  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 7  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 7  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack8_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack9_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 9  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 9  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 9  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 9  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 9  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 9  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 9  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 9  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack10_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 10  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 10  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 10  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 10  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 10  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 10  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 10  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 10  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack11_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 11  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack12_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 12  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 12  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 12  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 12  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 12  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 12  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 12  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 12  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack13_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 13  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack14_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 14  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack15_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  13 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 15  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack16_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack17_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  13 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 17  -  15 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack18_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 18  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack19_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  17 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  15 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 19  -  13 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack20_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 20  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack21_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  19 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  17 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  15 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  13 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 21  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack22_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 22  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack23_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  19 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  15 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  21 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  17 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  13 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 23  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack24_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 24  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack25_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  15 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  19 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  23 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  13 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  17 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  21 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 25  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack26_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 26  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack27_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  17 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  19 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  26 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  21 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  23 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  13 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  25 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  15 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 27  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack28_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 28  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack29_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  26 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  23 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  17 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  28 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  25 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  19 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  13 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  27 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  21 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  15 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 29  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack30_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  28 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  26 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  28 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  26 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 30  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack31_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  31 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  30 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  30 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  29 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  29 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  28 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  28 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  27 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  27 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  26 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  26 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  25 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  25 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  24 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  24 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  23 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  23 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  22 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  22 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  21 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  21 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  20 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  20 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  19 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  19 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  18 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  18 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  17 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  17 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  16 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  16 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  15 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  15 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  14 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  14 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  13 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  13 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  12 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  12 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  11 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  11 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  10 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  10 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  9 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  9 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  8 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  8 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  7 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  7 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  6 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  6 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  5 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  5 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  4 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  4 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  3 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  3 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  2 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  2 ;
    ++out;
    *out =  static_cast<uint32_t>( (*in) - base ) >> ( 31  -  1 );
    ++in;
    *out |= static_cast<uint32_t>( (*in) - base  ) <<  1 ;
    ++out;
    ++in;

        return out;
      }



    static uint32_t * pack32_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;
    *out =  static_cast<uint32_t>((*in) -base)  ;
    ++out;
    ++in;

        return out;
      }




 static const uint32_t * unpack1_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  17  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  19  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  )   & 1  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack2_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  )   % (1U << 2 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack3_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 3 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  19  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 3 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  17  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  )   % (1U << 3 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack4_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 4 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack5_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 5 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 5 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 5 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  19  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 5 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  17  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  )   % (1U << 5 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack6_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 6 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 6 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 6 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 6 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 6 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack7_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 7 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  17  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 7 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 7 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 7 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  19  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 7 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 7 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 7 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack8_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 8 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack9_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 9 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 9 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  17  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 9 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 9 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 9 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 9 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 9 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  19  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 9 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 9 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack10_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 10 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 10 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 10 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 10 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 10 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 10 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 10 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 10 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 10 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack11_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 11 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 11 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 11 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 11 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 11 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 11 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  17  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 11 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 11 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  19  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 11 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 11 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 11 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack12_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 12 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 12 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 12 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 12 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 12 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 12 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 12 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 12 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 12 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack13_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 13 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 13 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 13 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 13 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 13 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 13 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 13 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 13 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  17  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 13 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 13 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 13 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 13 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 13 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack14_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 14 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 14 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 14 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 14 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 14 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 14 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 14 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 14 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 14 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 14 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 14 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 14 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 14 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack15_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  15  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 13 ))<<( 15 - 13 );
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 15 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 15 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 15 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 15 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 15 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 15 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 15 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 15 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 15 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 15 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 15 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 15 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 15 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 15 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack16_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 16 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack17_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 17 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 17 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 17 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 17 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 17 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 17 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 17 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 17 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 17 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 17 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 17 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 17 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 17 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 17 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 13 ))<<( 17 - 13 );
    *out += base;
    out++;
    *out = ( (*in) >>  13  )   % (1U << 17 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 15 ))<<( 17 - 15 );
    *out += base;
    out++;
    *out = ( (*in) >>  15  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack18_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 18 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 18 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 18 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 18 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 18 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 18 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 18 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 18 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 18 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 18 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 18 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 18 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 18 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 18 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 18 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 18 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 18 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack19_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 19 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 19 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 19 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 19 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 19 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 17 ))<<( 19 - 17 );
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 19 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 19 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 19 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 19 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 19 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 15 ))<<( 19 - 15 );
    *out += base;
    out++;
    *out = ( (*in) >>  15  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 19 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 19 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 19 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 19 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 19 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 19 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 13 ))<<( 19 - 13 );
    *out += base;
    out++;
    *out = ( (*in) >>  13  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack20_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 20 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 20 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 20 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 20 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 20 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 20 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 20 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 20 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 20 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 20 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 20 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 20 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 20 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 20 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 20 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 20 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 20 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack21_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 21 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 21 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 21 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 19 ))<<( 21 - 19 );
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 21 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 21 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 21 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 17 ))<<( 21 - 17 );
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 21 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 21 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 21 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 15 ))<<( 21 - 15 );
    *out += base;
    out++;
    *out = ( (*in) >>  15  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 21 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 21 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 21 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 13 ))<<( 21 - 13 );
    *out += base;
    out++;
    *out = ( (*in) >>  13  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 21 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 21 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 21 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 21 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 21 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack22_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 22 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 22 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 22 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 22 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 22 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 22 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 22 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 22 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 22 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 22 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 22 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 22 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 22 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 22 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 22 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 22 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 22 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 22 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 22 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 22 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 22 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack23_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 23 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 23 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 23 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 23 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 19 ))<<( 23 - 19 );
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 23 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 23 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 23 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 15 ))<<( 23 - 15 );
    *out += base;
    out++;
    *out = ( (*in) >>  15  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 23 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 23 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 23 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 23 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 23 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 23 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 23 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 23 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  )   % (1U << 23 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 21 ))<<( 23 - 21 );
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 23 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 23 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 23 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 17 ))<<( 23 - 17 );
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 23 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  )   % (1U << 23 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 23 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 13 ))<<( 23 - 13 );
    *out += base;
    out++;
    *out = ( (*in) >>  13  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 23 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 23 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 23 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 23 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack24_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 24 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 24 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 24 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 24 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 24 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 24 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 24 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 24 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 24 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 24 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 24 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 24 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 24 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 24 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 24 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 24 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 24 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 24 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 24 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 24 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 24 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 24 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 24 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 24 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack25_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 25 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 25 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 25 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 25 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 25 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 25 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 15 ))<<( 25 - 15 );
    *out += base;
    out++;
    *out = ( (*in) >>  15  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 25 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 25 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 25 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 19 ))<<( 25 - 19 );
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 25 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 25 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  )   % (1U << 25 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 23 ))<<( 25 - 23 );
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 25 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 25 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 25 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 25 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 25 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 13 ))<<( 25 - 13 );
    *out += base;
    out++;
    *out = ( (*in) >>  13  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 25 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  )   % (1U << 25 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 25 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 17 ))<<( 25 - 17 );
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 25 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 25 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 25 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 21 ))<<( 25 - 21 );
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 25 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 25 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack26_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 26 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 26 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 26 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 26 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 26 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 26 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 26 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 26 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 26 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 26 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 26 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 26 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 26 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 26 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 26 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 26 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 26 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 26 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 26 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 26 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 26 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 26 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 26 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 26 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 26 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 26 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 26 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 26 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 26 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 26 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack27_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 27 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 27 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 17 ))<<( 27 - 17 );
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 27 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 27 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 27 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 27 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 27 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 19 ))<<( 27 - 19 );
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 27 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 27 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 27 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  )   % (1U << 27 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 26 ))<<( 27 - 26 );
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 21 ))<<( 27 - 21 );
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 27 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 27 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 27 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 27 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 27 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 23 ))<<( 27 - 23 );
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 27 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 13 ))<<( 27 - 13 );
    *out += base;
    out++;
    *out = ( (*in) >>  13  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 27 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 27 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  )   % (1U << 27 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 25 ))<<( 27 - 25 );
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 27 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 15 ))<<( 27 - 15 );
    *out += base;
    out++;
    *out = ( (*in) >>  15  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 27 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 27 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack28_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 28 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 28 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 28 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 28 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 28 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 28 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 28 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 28 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 28 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 28 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 28 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 28 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 28 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 28 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 28 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 28 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 28 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 28 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 28 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 28 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 28 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 28 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 28 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 28 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 28 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 28 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 28 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 28 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack29_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 29 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 26 ))<<( 29 - 26 );
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 23 ))<<( 29 - 23 );
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 29 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 17 ))<<( 29 - 17 );
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 29 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 29 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 29 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 29 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 29 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  )   % (1U << 29 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 28 ))<<( 29 - 28 );
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 25 ))<<( 29 - 25 );
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 29 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 19 ))<<( 29 - 19 );
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 29 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 13 ))<<( 29 - 13 );
    *out += base;
    out++;
    *out = ( (*in) >>  13  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 29 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 29 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 29 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 29 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  )   % (1U << 29 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 27 ))<<( 29 - 27 );
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 29 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 21 ))<<( 29 - 21 );
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 29 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 15 ))<<( 29 - 15 );
    *out += base;
    out++;
    *out = ( (*in) >>  15  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 29 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 29 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 29 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 29 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack30_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 30 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 28 ))<<( 30 - 28 );
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 26 ))<<( 30 - 26 );
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 30 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 30 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 30 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 30 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 30 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 30 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 30 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 30 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 30 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 30 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 30 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 30 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  )   % (1U << 30 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 28 ))<<( 30 - 28 );
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 26 ))<<( 30 - 26 );
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 30 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 30 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 30 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 30 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 30 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 30 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 30 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 30 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 30 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 30 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 30 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 30 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack31_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  )   % (1U << 31 )  ;
    *out += base;
    out++;
    *out = ( (*in) >>  31  ) ;
    ++in;
    *out |= ((*in) % (1U<< 30 ))<<( 31 - 30 );
    *out += base;
    out++;
    *out = ( (*in) >>  30  ) ;
    ++in;
    *out |= ((*in) % (1U<< 29 ))<<( 31 - 29 );
    *out += base;
    out++;
    *out = ( (*in) >>  29  ) ;
    ++in;
    *out |= ((*in) % (1U<< 28 ))<<( 31 - 28 );
    *out += base;
    out++;
    *out = ( (*in) >>  28  ) ;
    ++in;
    *out |= ((*in) % (1U<< 27 ))<<( 31 - 27 );
    *out += base;
    out++;
    *out = ( (*in) >>  27  ) ;
    ++in;
    *out |= ((*in) % (1U<< 26 ))<<( 31 - 26 );
    *out += base;
    out++;
    *out = ( (*in) >>  26  ) ;
    ++in;
    *out |= ((*in) % (1U<< 25 ))<<( 31 - 25 );
    *out += base;
    out++;
    *out = ( (*in) >>  25  ) ;
    ++in;
    *out |= ((*in) % (1U<< 24 ))<<( 31 - 24 );
    *out += base;
    out++;
    *out = ( (*in) >>  24  ) ;
    ++in;
    *out |= ((*in) % (1U<< 23 ))<<( 31 - 23 );
    *out += base;
    out++;
    *out = ( (*in) >>  23  ) ;
    ++in;
    *out |= ((*in) % (1U<< 22 ))<<( 31 - 22 );
    *out += base;
    out++;
    *out = ( (*in) >>  22  ) ;
    ++in;
    *out |= ((*in) % (1U<< 21 ))<<( 31 - 21 );
    *out += base;
    out++;
    *out = ( (*in) >>  21  ) ;
    ++in;
    *out |= ((*in) % (1U<< 20 ))<<( 31 - 20 );
    *out += base;
    out++;
    *out = ( (*in) >>  20  ) ;
    ++in;
    *out |= ((*in) % (1U<< 19 ))<<( 31 - 19 );
    *out += base;
    out++;
    *out = ( (*in) >>  19  ) ;
    ++in;
    *out |= ((*in) % (1U<< 18 ))<<( 31 - 18 );
    *out += base;
    out++;
    *out = ( (*in) >>  18  ) ;
    ++in;
    *out |= ((*in) % (1U<< 17 ))<<( 31 - 17 );
    *out += base;
    out++;
    *out = ( (*in) >>  17  ) ;
    ++in;
    *out |= ((*in) % (1U<< 16 ))<<( 31 - 16 );
    *out += base;
    out++;
    *out = ( (*in) >>  16  ) ;
    ++in;
    *out |= ((*in) % (1U<< 15 ))<<( 31 - 15 );
    *out += base;
    out++;
    *out = ( (*in) >>  15  ) ;
    ++in;
    *out |= ((*in) % (1U<< 14 ))<<( 31 - 14 );
    *out += base;
    out++;
    *out = ( (*in) >>  14  ) ;
    ++in;
    *out |= ((*in) % (1U<< 13 ))<<( 31 - 13 );
    *out += base;
    out++;
    *out = ( (*in) >>  13  ) ;
    ++in;
    *out |= ((*in) % (1U<< 12 ))<<( 31 - 12 );
    *out += base;
    out++;
    *out = ( (*in) >>  12  ) ;
    ++in;
    *out |= ((*in) % (1U<< 11 ))<<( 31 - 11 );
    *out += base;
    out++;
    *out = ( (*in) >>  11  ) ;
    ++in;
    *out |= ((*in) % (1U<< 10 ))<<( 31 - 10 );
    *out += base;
    out++;
    *out = ( (*in) >>  10  ) ;
    ++in;
    *out |= ((*in) % (1U<< 9 ))<<( 31 - 9 );
    *out += base;
    out++;
    *out = ( (*in) >>  9  ) ;
    ++in;
    *out |= ((*in) % (1U<< 8 ))<<( 31 - 8 );
    *out += base;
    out++;
    *out = ( (*in) >>  8  ) ;
    ++in;
    *out |= ((*in) % (1U<< 7 ))<<( 31 - 7 );
    *out += base;
    out++;
    *out = ( (*in) >>  7  ) ;
    ++in;
    *out |= ((*in) % (1U<< 6 ))<<( 31 - 6 );
    *out += base;
    out++;
    *out = ( (*in) >>  6  ) ;
    ++in;
    *out |= ((*in) % (1U<< 5 ))<<( 31 - 5 );
    *out += base;
    out++;
    *out = ( (*in) >>  5  ) ;
    ++in;
    *out |= ((*in) % (1U<< 4 ))<<( 31 - 4 );
    *out += base;
    out++;
    *out = ( (*in) >>  4  ) ;
    ++in;
    *out |= ((*in) % (1U<< 3 ))<<( 31 - 3 );
    *out += base;
    out++;
    *out = ( (*in) >>  3  ) ;
    ++in;
    *out |= ((*in) % (1U<< 2 ))<<( 31 - 2 );
    *out += base;
    out++;
    *out = ( (*in) >>  2  ) ;
    ++in;
    *out |= ((*in) % (1U<< 1 ))<<( 31 - 1 );
    *out += base;
    out++;
    *out = ( (*in) >>  1  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }




 static const uint32_t * unpack32_32( uint32_t base,  const uint32_t *   in, uint32_t *    out) {

    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;
    *out = ( (*in) >>  0  ) ;
    ++in;
    *out += base;
    out++;

        return in;
      }

 typedef const uint32_t * (*unpackfnc)( uint32_t,  const uint32_t * , uint32_t * );

 typedef uint32_t * (*packfnc)( uint32_t,  const uint32_t * , uint32_t * );

static uint32_t * nullpacker( uint32_t,  const uint32_t *   , uint32_t *    out) {
   return out;
 }

static const uint32_t * nullunpacker( uint32_t,  const uint32_t *  in , uint32_t * ) {
   return in;
 }

static unpackfnc unpack8[33]={nullunpacker,unpack1_8,
         unpack2_8,
         unpack3_8,
         unpack4_8,
         unpack5_8,
         unpack6_8,
         unpack7_8,
         unpack8_8,
         unpack9_8,
         unpack10_8,
         unpack11_8,
         unpack12_8,
         unpack13_8,
         unpack14_8,
         unpack15_8,
         unpack16_8,
         unpack17_8,
         unpack18_8,
         unpack19_8,
         unpack20_8,
         unpack21_8,
         unpack22_8,
         unpack23_8,
         unpack24_8,
         unpack25_8,
         unpack26_8,
         unpack27_8,
         unpack28_8,
         unpack29_8,
         unpack30_8,
         unpack31_8,
         unpack32_8};

static packfnc pack8[33]={nullpacker,pack1_8,
         pack2_8,
         pack3_8,
         pack4_8,
         pack5_8,
         pack6_8,
         pack7_8,
         pack8_8,
         pack9_8,
         pack10_8,
         pack11_8,
         pack12_8,
         pack13_8,
         pack14_8,
         pack15_8,
         pack16_8,
         pack17_8,
         pack18_8,
         pack19_8,
         pack20_8,
         pack21_8,
         pack22_8,
         pack23_8,
         pack24_8,
         pack25_8,
         pack26_8,
         pack27_8,
         pack28_8,
         pack29_8,
         pack30_8,
         pack31_8,
         pack32_8};

static unpackfnc unpack16[33]={nullunpacker,unpack1_16,
         unpack2_16,
         unpack3_16,
         unpack4_16,
         unpack5_16,
         unpack6_16,
         unpack7_16,
         unpack8_16,
         unpack9_16,
         unpack10_16,
         unpack11_16,
         unpack12_16,
         unpack13_16,
         unpack14_16,
         unpack15_16,
         unpack16_16,
         unpack17_16,
         unpack18_16,
         unpack19_16,
         unpack20_16,
         unpack21_16,
         unpack22_16,
         unpack23_16,
         unpack24_16,
         unpack25_16,
         unpack26_16,
         unpack27_16,
         unpack28_16,
         unpack29_16,
         unpack30_16,
         unpack31_16,
         unpack32_16};

static packfnc pack16[33]={nullpacker,pack1_16,
         pack2_16,
         pack3_16,
         pack4_16,
         pack5_16,
         pack6_16,
         pack7_16,
         pack8_16,
         pack9_16,
         pack10_16,
         pack11_16,
         pack12_16,
         pack13_16,
         pack14_16,
         pack15_16,
         pack16_16,
         pack17_16,
         pack18_16,
         pack19_16,
         pack20_16,
         pack21_16,
         pack22_16,
         pack23_16,
         pack24_16,
         pack25_16,
         pack26_16,
         pack27_16,
         pack28_16,
         pack29_16,
         pack30_16,
         pack31_16,
         pack32_16};

static unpackfnc unpack32[33]={nullunpacker,unpack1_32,
         unpack2_32,
         unpack3_32,
         unpack4_32,
         unpack5_32,
         unpack6_32,
         unpack7_32,
         unpack8_32,
         unpack9_32,
         unpack10_32,
         unpack11_32,
         unpack12_32,
         unpack13_32,
         unpack14_32,
         unpack15_32,
         unpack16_32,
         unpack17_32,
         unpack18_32,
         unpack19_32,
         unpack20_32,
         unpack21_32,
         unpack22_32,
         unpack23_32,
         unpack24_32,
         unpack25_32,
         unpack26_32,
         unpack27_32,
         unpack28_32,
         unpack29_32,
         unpack30_32,
         unpack31_32,
         unpack32_32};

static packfnc pack32[33]={nullpacker,pack1_32,
         pack2_32,
         pack3_32,
         pack4_32,
         pack5_32,
         pack6_32,
         pack7_32,
         pack8_32,
         pack9_32,
         pack10_32,
         pack11_32,
         pack12_32,
         pack13_32,
         pack14_32,
         pack15_32,
         pack16_32,
         pack17_32,
         pack18_32,
         pack19_32,
         pack20_32,
         pack21_32,
         pack22_32,
         pack23_32,
         pack24_32,
         pack25_32,
         pack26_32,
         pack27_32,
         pack28_32,
         pack29_32,
         pack30_32,
         pack31_32,
         pack32_32};

static uint32_t bits(const uint32_t v) {
     return v == 0 ? 0 : 32 - __builtin_clz(v);
 }

 uint32_t * SIMDCompressionLib::FrameOfReference::compress_length(const uint32_t * in, uint32_t length, uint32_t * out) {
     if(length == 0) return out;
     uint32_t m = in[0];
     uint32_t M = in[0];
     for(uint32_t i = 1; i < length; ++i) {
         if(in[i]>M) M=in[i];
         if(in[i]<m) m=in[i];
     }
     int b = bits(static_cast<uint32_t>(M-m));
     out[0] = m;
     ++out;
     out[0] = M;
     ++out;
     uint32_t k = 0;
     for(; k+32<=length; k+=32,in+=32) {
         out = pack32[b](m,in,out);
     }
     // we could pack the rest, but we don't  bother
     for(;k<length;++k,in++,out++) {
         out[0] = in [0];
     }
     return out;
 }

const uint32_t * SIMDCompressionLib::FrameOfReference::uncompress_length(const uint32_t * in, uint32_t * out, uint32_t  nvalue) {
     if(nvalue == 0) return out;
     uint32_t m = in[0];
     ++in;
     uint32_t M = in[0];
     ++in;
     int b = bits(static_cast<uint32_t>(M-m));
     for(uint32_t k = 0; k<nvalue/32; ++k) {
         unpack32[b](m,in+b*k,out+32*k);
     }
     out = out + nvalue/32*32;
     in = in + nvalue/32*b;
     // we could pack the rest, but we don't  bother
     for(uint32_t k=nvalue/8*8;k<nvalue;++k,in++,out++) {
         out[0] = in [0];
     }
     return in;
 }




// Performs a lower bound find in the encoded array.
// Returns the index
size_t findLowerBound(const uint32_t *in, const size_t length, uint32_t key,
                      uint32_t *presult) {
	return 0;// TODO : implement
}




// Returns a decompressed value in an encoded array
uint32_t SIMDCompressionLib::FrameOfReference::select(uint32_t *in, size_t index) {
	uint32_t length = *in;
	in ++;
    uint32_t m = *in;
    ++in;
    uint32_t M = *in;
    ++in;
    uint32_t b = bits(M-m);
    uint32_t packedlength = length / 32 * 32;
    uint32_t packedsizeinwords = packedlength * b / 32;
    if(index > packedlength) {
    	return in[packedsizeinwords +  index - packedlength];
    }
	const int bitoffset = index * b; /* how many bits  */
	const int firstword = bitoffset / 32;
	const int secondword = (bitoffset + b - 1) / 32;
	const uint32_t firstpart = in[firstword]
			>> (bitoffset % 32);
	const uint32_t mask = (1 << b) - 1;
	if (firstword == secondword) {
		/* easy common case*/
		return m + (firstpart & mask);
	} else {
		/* harder case where we need to combine two words */
		const uint32_t secondpart = in[firstword + 1];
		const int usablebitsinfirstword = 32 - (bitoffset % 32);
		return m
				+ ((firstpart | (secondpart << usablebitsinfirstword))
						& mask);
	}
}


