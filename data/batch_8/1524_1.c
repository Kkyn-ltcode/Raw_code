static void fadst8 ( const int16_t * input , int16_t * output ) {
 int s0 , s1 , s2 , s3 , s4 , s5 , s6 , s7 ;
 int x0 = input [ 7 ] ;
 int x1 = input [ 0 ] ;
 int x2 = input [ 5 ] ;
 int x3 = input [ 2 ] ;
 int x4 = input [ 3 ] ;
 int x5 = input [ 4 ] ;
 int x6 = input [ 1 ] ;
 int x7 = input [ 6 ] ;
 s0 = cospi_2_64 * x0 + cospi_30_64 * x1 ;
 s1 = cospi_30_64 * x0 - cospi_2_64 * x1 ;
 s2 = cospi_10_64 * x2 + cospi_22_64 * x3 ;
 s3 = cospi_22_64 * x2 - cospi_10_64 * x3 ;
 s4 = cospi_18_64 * x4 + cospi_14_64 * x5 ;
 s5 = cospi_14_64 * x4 - cospi_18_64 * x5 ;
 s6 = cospi_26_64 * x6 + cospi_6_64 * x7 ;
 s7 = cospi_6_64 * x6 - cospi_26_64 * x7 ;
 x0 = fdct_round_shift ( s0 + s4 ) ;
 x1 = fdct_round_shift ( s1 + s5 ) ;
 x2 = fdct_round_shift ( s2 + s6 ) ;
 x3 = fdct_round_shift ( s3 + s7 ) ;
 x4 = fdct_round_shift ( s0 - s4 ) ;
 x5 = fdct_round_shift ( s1 - s5 ) ;
 x6 = fdct_round_shift ( s2 - s6 ) ;
 x7 = fdct_round_shift ( s3 - s7 ) ;
 s0 = x0 ;
 s1 = x1 ;
 s2 = x2 ;
 s3 = x3 ;
 s4 = cospi_8_64 * x4 + cospi_24_64 * x5 ;
 s5 = cospi_24_64 * x4 - cospi_8_64 * x5 ;
 s6 = - cospi_24_64 * x6 + cospi_8_64 * x7 ;
 s7 = cospi_8_64 * x6 + cospi_24_64 * x7 ;
 x0 = s0 + s2 ;
 x1 = s1 + s3 ;
 x2 = s0 - s2 ;
 x3 = s1 - s3 ;
 x4 = fdct_round_shift ( s4 + s6 ) ;
 x5 = fdct_round_shift ( s5 + s7 ) ;
 x6 = fdct_round_shift ( s4 - s6 ) ;
 x7 = fdct_round_shift ( s5 - s7 ) ;
 s2 = cospi_16_64 * ( x2 + x3 ) ;
 s3 = cospi_16_64 * ( x2 - x3 ) ;
 s6 = cospi_16_64 * ( x6 + x7 ) ;
 s7 = cospi_16_64 * ( x6 - x7 ) ;
 x2 = fdct_round_shift ( s2 ) ;
 x3 = fdct_round_shift ( s3 ) ;
 x6 = fdct_round_shift ( s6 ) ;
 x7 = fdct_round_shift ( s7 ) ;
 output [ 0 ] = x0 ;
 output [ 1 ] = - x4 ;
 output [ 2 ] = x6 ;
 output [ 3 ] = - x2 ;
 output [ 4 ] = x3 ;
 output [ 5 ] = - x7 ;
 output [ 6 ] = x5 ;
 output [ 7 ] = - x1 ;
 }