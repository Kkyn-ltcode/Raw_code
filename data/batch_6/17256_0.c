static void fadst16 ( const tran_low_t * input , tran_low_t * output ) {
 tran_high_t s0 , s1 , s2 , s3 , s4 , s5 , s6 , s7 , s8 ;
 tran_high_t s9 , s10 , s11 , s12 , s13 , s14 , s15 ;
 tran_high_t x0 = input [ 15 ] ;
 tran_high_t x1 = input [ 0 ] ;
 tran_high_t x2 = input [ 13 ] ;
 tran_high_t x3 = input [ 2 ] ;
 tran_high_t x4 = input [ 11 ] ;
 tran_high_t x5 = input [ 4 ] ;
 tran_high_t x6 = input [ 9 ] ;
 tran_high_t x7 = input [ 6 ] ;
 tran_high_t x8 = input [ 7 ] ;
 tran_high_t x9 = input [ 8 ] ;
 tran_high_t x10 = input [ 5 ] ;
 tran_high_t x11 = input [ 10 ] ;
 tran_high_t x12 = input [ 3 ] ;
 tran_high_t x13 = input [ 12 ] ;
 tran_high_t x14 = input [ 1 ] ;
 tran_high_t x15 = input [ 14 ] ;
 s0 = x0 * cospi_1_64 + x1 * cospi_31_64 ;
 s1 = x0 * cospi_31_64 - x1 * cospi_1_64 ;
 s2 = x2 * cospi_5_64 + x3 * cospi_27_64 ;
 s3 = x2 * cospi_27_64 - x3 * cospi_5_64 ;
 s4 = x4 * cospi_9_64 + x5 * cospi_23_64 ;
 s5 = x4 * cospi_23_64 - x5 * cospi_9_64 ;
 s6 = x6 * cospi_13_64 + x7 * cospi_19_64 ;
 s7 = x6 * cospi_19_64 - x7 * cospi_13_64 ;
 s8 = x8 * cospi_17_64 + x9 * cospi_15_64 ;
 s9 = x8 * cospi_15_64 - x9 * cospi_17_64 ;
 s10 = x10 * cospi_21_64 + x11 * cospi_11_64 ;
 s11 = x10 * cospi_11_64 - x11 * cospi_21_64 ;
 s12 = x12 * cospi_25_64 + x13 * cospi_7_64 ;
 s13 = x12 * cospi_7_64 - x13 * cospi_25_64 ;
 s14 = x14 * cospi_29_64 + x15 * cospi_3_64 ;
 s15 = x14 * cospi_3_64 - x15 * cospi_29_64 ;
 x0 = fdct_round_shift ( s0 + s8 ) ;
 x1 = fdct_round_shift ( s1 + s9 ) ;
 x2 = fdct_round_shift ( s2 + s10 ) ;
 x3 = fdct_round_shift ( s3 + s11 ) ;
 x4 = fdct_round_shift ( s4 + s12 ) ;
 x5 = fdct_round_shift ( s5 + s13 ) ;
 x6 = fdct_round_shift ( s6 + s14 ) ;
 x7 = fdct_round_shift ( s7 + s15 ) ;
 x8 = fdct_round_shift ( s0 - s8 ) ;
 x9 = fdct_round_shift ( s1 - s9 ) ;
 x10 = fdct_round_shift ( s2 - s10 ) ;
 x11 = fdct_round_shift ( s3 - s11 ) ;
 x12 = fdct_round_shift ( s4 - s12 ) ;
 x13 = fdct_round_shift ( s5 - s13 ) ;
 x14 = fdct_round_shift ( s6 - s14 ) ;
 x15 = fdct_round_shift ( s7 - s15 ) ;
 s0 = x0 ;
 s1 = x1 ;
 s2 = x2 ;
 s3 = x3 ;
 s4 = x4 ;
 s5 = x5 ;
 s6 = x6 ;
 s7 = x7 ;
 s8 = x8 * cospi_4_64 + x9 * cospi_28_64 ;
 s9 = x8 * cospi_28_64 - x9 * cospi_4_64 ;
 s10 = x10 * cospi_20_64 + x11 * cospi_12_64 ;
 s11 = x10 * cospi_12_64 - x11 * cospi_20_64 ;
 s12 = - x12 * cospi_28_64 + x13 * cospi_4_64 ;
 s13 = x12 * cospi_4_64 + x13 * cospi_28_64 ;
 s14 = - x14 * cospi_12_64 + x15 * cospi_20_64 ;
 s15 = x14 * cospi_20_64 + x15 * cospi_12_64 ;
 x0 = s0 + s4 ;
 x1 = s1 + s5 ;
 x2 = s2 + s6 ;
 x3 = s3 + s7 ;
 x4 = s0 - s4 ;
 x5 = s1 - s5 ;
 x6 = s2 - s6 ;
 x7 = s3 - s7 ;
 x8 = fdct_round_shift ( s8 + s12 ) ;
 x9 = fdct_round_shift ( s9 + s13 ) ;
 x10 = fdct_round_shift ( s10 + s14 ) ;
 x11 = fdct_round_shift ( s11 + s15 ) ;
 x12 = fdct_round_shift ( s8 - s12 ) ;
 x13 = fdct_round_shift ( s9 - s13 ) ;
 x14 = fdct_round_shift ( s10 - s14 ) ;
 x15 = fdct_round_shift ( s11 - s15 ) ;
 s0 = x0 ;
 s1 = x1 ;
 s2 = x2 ;
 s3 = x3 ;
 s4 = x4 * cospi_8_64 + x5 * cospi_24_64 ;
 s5 = x4 * cospi_24_64 - x5 * cospi_8_64 ;
 s6 = - x6 * cospi_24_64 + x7 * cospi_8_64 ;
 s7 = x6 * cospi_8_64 + x7 * cospi_24_64 ;
 s8 = x8 ;
 s9 = x9 ;
 s10 = x10 ;
 s11 = x11 ;
 s12 = x12 * cospi_8_64 + x13 * cospi_24_64 ;
 s13 = x12 * cospi_24_64 - x13 * cospi_8_64 ;
 s14 = - x14 * cospi_24_64 + x15 * cospi_8_64 ;
 s15 = x14 * cospi_8_64 + x15 * cospi_24_64 ;
 x0 = s0 + s2 ;
 x1 = s1 + s3 ;
 x2 = s0 - s2 ;
 x3 = s1 - s3 ;
 x4 = fdct_round_shift ( s4 + s6 ) ;
 x5 = fdct_round_shift ( s5 + s7 ) ;
 x6 = fdct_round_shift ( s4 - s6 ) ;
 x7 = fdct_round_shift ( s5 - s7 ) ;
 x8 = s8 + s10 ;
 x9 = s9 + s11 ;
 x10 = s8 - s10 ;
 x11 = s9 - s11 ;
 x12 = fdct_round_shift ( s12 + s14 ) ;
 x13 = fdct_round_shift ( s13 + s15 ) ;
 x14 = fdct_round_shift ( s12 - s14 ) ;
 x15 = fdct_round_shift ( s13 - s15 ) ;
 s2 = ( - cospi_16_64 ) * ( x2 + x3 ) ;
 s3 = cospi_16_64 * ( x2 - x3 ) ;
 s6 = cospi_16_64 * ( x6 + x7 ) ;
 s7 = cospi_16_64 * ( - x6 + x7 ) ;
 s10 = cospi_16_64 * ( x10 + x11 ) ;
 s11 = cospi_16_64 * ( - x10 + x11 ) ;
 s14 = ( - cospi_16_64 ) * ( x14 + x15 ) ;
 s15 = cospi_16_64 * ( x14 - x15 ) ;
 x2 = fdct_round_shift ( s2 ) ;
 x3 = fdct_round_shift ( s3 ) ;
 x6 = fdct_round_shift ( s6 ) ;
 x7 = fdct_round_shift ( s7 ) ;
 x10 = fdct_round_shift ( s10 ) ;
 x11 = fdct_round_shift ( s11 ) ;
 x14 = fdct_round_shift ( s14 ) ;
 x15 = fdct_round_shift ( s15 ) ;
 output [ 0 ] = x0 ;
 output [ 1 ] = - x8 ;
 output [ 2 ] = x12 ;
 output [ 3 ] = - x4 ;
 output [ 4 ] = x6 ;
 output [ 5 ] = x14 ;
 output [ 6 ] = x10 ;
 output [ 7 ] = x2 ;
 output [ 8 ] = x3 ;
 output [ 9 ] = x11 ;
 output [ 10 ] = x15 ;
 output [ 11 ] = x7 ;
 output [ 12 ] = x5 ;
 output [ 13 ] = - x13 ;
 output [ 14 ] = x9 ;
 output [ 15 ] = - x1 ;
 }