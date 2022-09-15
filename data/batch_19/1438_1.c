static void idct16 ( const int16_t * input , int16_t * output ) {
 int16_t step1 [ 16 ] , step2 [ 16 ] ;
 int temp1 , temp2 ;
 step1 [ 0 ] = input [ 0 / 2 ] ;
 step1 [ 1 ] = input [ 16 / 2 ] ;
 step1 [ 2 ] = input [ 8 / 2 ] ;
 step1 [ 3 ] = input [ 24 / 2 ] ;
 step1 [ 4 ] = input [ 4 / 2 ] ;
 step1 [ 5 ] = input [ 20 / 2 ] ;
 step1 [ 6 ] = input [ 12 / 2 ] ;
 step1 [ 7 ] = input [ 28 / 2 ] ;
 step1 [ 8 ] = input [ 2 / 2 ] ;
 step1 [ 9 ] = input [ 18 / 2 ] ;
 step1 [ 10 ] = input [ 10 / 2 ] ;
 step1 [ 11 ] = input [ 26 / 2 ] ;
 step1 [ 12 ] = input [ 6 / 2 ] ;
 step1 [ 13 ] = input [ 22 / 2 ] ;
 step1 [ 14 ] = input [ 14 / 2 ] ;
 step1 [ 15 ] = input [ 30 / 2 ] ;
 step2 [ 0 ] = step1 [ 0 ] ;
 step2 [ 1 ] = step1 [ 1 ] ;
 step2 [ 2 ] = step1 [ 2 ] ;
 step2 [ 3 ] = step1 [ 3 ] ;
 step2 [ 4 ] = step1 [ 4 ] ;
 step2 [ 5 ] = step1 [ 5 ] ;
 step2 [ 6 ] = step1 [ 6 ] ;
 step2 [ 7 ] = step1 [ 7 ] ;
 temp1 = step1 [ 8 ] * cospi_30_64 - step1 [ 15 ] * cospi_2_64 ;
 temp2 = step1 [ 8 ] * cospi_2_64 + step1 [ 15 ] * cospi_30_64 ;
 step2 [ 8 ] = dct_const_round_shift ( temp1 ) ;
 step2 [ 15 ] = dct_const_round_shift ( temp2 ) ;
 temp1 = step1 [ 9 ] * cospi_14_64 - step1 [ 14 ] * cospi_18_64 ;
 temp2 = step1 [ 9 ] * cospi_18_64 + step1 [ 14 ] * cospi_14_64 ;
 step2 [ 9 ] = dct_const_round_shift ( temp1 ) ;
 step2 [ 14 ] = dct_const_round_shift ( temp2 ) ;
 temp1 = step1 [ 10 ] * cospi_22_64 - step1 [ 13 ] * cospi_10_64 ;
 temp2 = step1 [ 10 ] * cospi_10_64 + step1 [ 13 ] * cospi_22_64 ;
 step2 [ 10 ] = dct_const_round_shift ( temp1 ) ;
 step2 [ 13 ] = dct_const_round_shift ( temp2 ) ;
 temp1 = step1 [ 11 ] * cospi_6_64 - step1 [ 12 ] * cospi_26_64 ;
 temp2 = step1 [ 11 ] * cospi_26_64 + step1 [ 12 ] * cospi_6_64 ;
 step2 [ 11 ] = dct_const_round_shift ( temp1 ) ;
 step2 [ 12 ] = dct_const_round_shift ( temp2 ) ;
 step1 [ 0 ] = step2 [ 0 ] ;
 step1 [ 1 ] = step2 [ 1 ] ;
 step1 [ 2 ] = step2 [ 2 ] ;
 step1 [ 3 ] = step2 [ 3 ] ;
 temp1 = step2 [ 4 ] * cospi_28_64 - step2 [ 7 ] * cospi_4_64 ;
 temp2 = step2 [ 4 ] * cospi_4_64 + step2 [ 7 ] * cospi_28_64 ;
 step1 [ 4 ] = dct_const_round_shift ( temp1 ) ;
 step1 [ 7 ] = dct_const_round_shift ( temp2 ) ;
 temp1 = step2 [ 5 ] * cospi_12_64 - step2 [ 6 ] * cospi_20_64 ;
 temp2 = step2 [ 5 ] * cospi_20_64 + step2 [ 6 ] * cospi_12_64 ;
 step1 [ 5 ] = dct_const_round_shift ( temp1 ) ;
 step1 [ 6 ] = dct_const_round_shift ( temp2 ) ;
 step1 [ 8 ] = step2 [ 8 ] + step2 [ 9 ] ;
 step1 [ 9 ] = step2 [ 8 ] - step2 [ 9 ] ;
 step1 [ 10 ] = - step2 [ 10 ] + step2 [ 11 ] ;
 step1 [ 11 ] = step2 [ 10 ] + step2 [ 11 ] ;
 step1 [ 12 ] = step2 [ 12 ] + step2 [ 13 ] ;
 step1 [ 13 ] = step2 [ 12 ] - step2 [ 13 ] ;
 step1 [ 14 ] = - step2 [ 14 ] + step2 [ 15 ] ;
 step1 [ 15 ] = step2 [ 14 ] + step2 [ 15 ] ;
 temp1 = ( step1 [ 0 ] + step1 [ 1 ] ) * cospi_16_64 ;
 temp2 = ( step1 [ 0 ] - step1 [ 1 ] ) * cospi_16_64 ;
 step2 [ 0 ] = dct_const_round_shift ( temp1 ) ;
 step2 [ 1 ] = dct_const_round_shift ( temp2 ) ;
 temp1 = step1 [ 2 ] * cospi_24_64 - step1 [ 3 ] * cospi_8_64 ;
 temp2 = step1 [ 2 ] * cospi_8_64 + step1 [ 3 ] * cospi_24_64 ;
 step2 [ 2 ] = dct_const_round_shift ( temp1 ) ;
 step2 [ 3 ] = dct_const_round_shift ( temp2 ) ;
 step2 [ 4 ] = step1 [ 4 ] + step1 [ 5 ] ;
 step2 [ 5 ] = step1 [ 4 ] - step1 [ 5 ] ;
 step2 [ 6 ] = - step1 [ 6 ] + step1 [ 7 ] ;
 step2 [ 7 ] = step1 [ 6 ] + step1 [ 7 ] ;
 step2 [ 8 ] = step1 [ 8 ] ;
 step2 [ 15 ] = step1 [ 15 ] ;
 temp1 = - step1 [ 9 ] * cospi_8_64 + step1 [ 14 ] * cospi_24_64 ;
 temp2 = step1 [ 9 ] * cospi_24_64 + step1 [ 14 ] * cospi_8_64 ;
 step2 [ 9 ] = dct_const_round_shift ( temp1 ) ;
 step2 [ 14 ] = dct_const_round_shift ( temp2 ) ;
 temp1 = - step1 [ 10 ] * cospi_24_64 - step1 [ 13 ] * cospi_8_64 ;
 temp2 = - step1 [ 10 ] * cospi_8_64 + step1 [ 13 ] * cospi_24_64 ;
 step2 [ 10 ] = dct_const_round_shift ( temp1 ) ;
 step2 [ 13 ] = dct_const_round_shift ( temp2 ) ;
 step2 [ 11 ] = step1 [ 11 ] ;
 step2 [ 12 ] = step1 [ 12 ] ;
 step1 [ 0 ] = step2 [ 0 ] + step2 [ 3 ] ;
 step1 [ 1 ] = step2 [ 1 ] + step2 [ 2 ] ;
 step1 [ 2 ] = step2 [ 1 ] - step2 [ 2 ] ;
 step1 [ 3 ] = step2 [ 0 ] - step2 [ 3 ] ;
 step1 [ 4 ] = step2 [ 4 ] ;
 temp1 = ( step2 [ 6 ] - step2 [ 5 ] ) * cospi_16_64 ;
 temp2 = ( step2 [ 5 ] + step2 [ 6 ] ) * cospi_16_64 ;
 step1 [ 5 ] = dct_const_round_shift ( temp1 ) ;
 step1 [ 6 ] = dct_const_round_shift ( temp2 ) ;
 step1 [ 7 ] = step2 [ 7 ] ;
 step1 [ 8 ] = step2 [ 8 ] + step2 [ 11 ] ;
 step1 [ 9 ] = step2 [ 9 ] + step2 [ 10 ] ;
 step1 [ 10 ] = step2 [ 9 ] - step2 [ 10 ] ;
 step1 [ 11 ] = step2 [ 8 ] - step2 [ 11 ] ;
 step1 [ 12 ] = - step2 [ 12 ] + step2 [ 15 ] ;
 step1 [ 13 ] = - step2 [ 13 ] + step2 [ 14 ] ;
 step1 [ 14 ] = step2 [ 13 ] + step2 [ 14 ] ;
 step1 [ 15 ] = step2 [ 12 ] + step2 [ 15 ] ;
 step2 [ 0 ] = step1 [ 0 ] + step1 [ 7 ] ;
 step2 [ 1 ] = step1 [ 1 ] + step1 [ 6 ] ;
 step2 [ 2 ] = step1 [ 2 ] + step1 [ 5 ] ;
 step2 [ 3 ] = step1 [ 3 ] + step1 [ 4 ] ;
 step2 [ 4 ] = step1 [ 3 ] - step1 [ 4 ] ;
 step2 [ 5 ] = step1 [ 2 ] - step1 [ 5 ] ;
 step2 [ 6 ] = step1 [ 1 ] - step1 [ 6 ] ;
 step2 [ 7 ] = step1 [ 0 ] - step1 [ 7 ] ;
 step2 [ 8 ] = step1 [ 8 ] ;
 step2 [ 9 ] = step1 [ 9 ] ;
 temp1 = ( - step1 [ 10 ] + step1 [ 13 ] ) * cospi_16_64 ;
 temp2 = ( step1 [ 10 ] + step1 [ 13 ] ) * cospi_16_64 ;
 step2 [ 10 ] = dct_const_round_shift ( temp1 ) ;
 step2 [ 13 ] = dct_const_round_shift ( temp2 ) ;
 temp1 = ( - step1 [ 11 ] + step1 [ 12 ] ) * cospi_16_64 ;
 temp2 = ( step1 [ 11 ] + step1 [ 12 ] ) * cospi_16_64 ;
 step2 [ 11 ] = dct_const_round_shift ( temp1 ) ;
 step2 [ 12 ] = dct_const_round_shift ( temp2 ) ;
 step2 [ 14 ] = step1 [ 14 ] ;
 step2 [ 15 ] = step1 [ 15 ] ;
 output [ 0 ] = step2 [ 0 ] + step2 [ 15 ] ;
 output [ 1 ] = step2 [ 1 ] + step2 [ 14 ] ;
 output [ 2 ] = step2 [ 2 ] + step2 [ 13 ] ;
 output [ 3 ] = step2 [ 3 ] + step2 [ 12 ] ;
 output [ 4 ] = step2 [ 4 ] + step2 [ 11 ] ;
 output [ 5 ] = step2 [ 5 ] + step2 [ 10 ] ;
 output [ 6 ] = step2 [ 6 ] + step2 [ 9 ] ;
 output [ 7 ] = step2 [ 7 ] + step2 [ 8 ] ;
 output [ 8 ] = step2 [ 7 ] - step2 [ 8 ] ;
 output [ 9 ] = step2 [ 6 ] - step2 [ 9 ] ;
 output [ 10 ] = step2 [ 5 ] - step2 [ 10 ] ;
 output [ 11 ] = step2 [ 4 ] - step2 [ 11 ] ;
 output [ 12 ] = step2 [ 3 ] - step2 [ 12 ] ;
 output [ 13 ] = step2 [ 2 ] - step2 [ 13 ] ;
 output [ 14 ] = step2 [ 1 ] - step2 [ 14 ] ;
 output [ 15 ] = step2 [ 0 ] - step2 [ 15 ] ;
 }