static void idct8 ( const int16_t * input , int16_t * output ) {
 int16_t step1 [ 8 ] , step2 [ 8 ] ;
 int temp1 , temp2 ;
 step1 [ 0 ] = input [ 0 ] ;
 step1 [ 2 ] = input [ 4 ] ;
 step1 [ 1 ] = input [ 2 ] ;
 step1 [ 3 ] = input [ 6 ] ;
 temp1 = input [ 1 ] * cospi_28_64 - input [ 7 ] * cospi_4_64 ;
 temp2 = input [ 1 ] * cospi_4_64 + input [ 7 ] * cospi_28_64 ;
 step1 [ 4 ] = dct_const_round_shift ( temp1 ) ;
 step1 [ 7 ] = dct_const_round_shift ( temp2 ) ;
 temp1 = input [ 5 ] * cospi_12_64 - input [ 3 ] * cospi_20_64 ;
 temp2 = input [ 5 ] * cospi_20_64 + input [ 3 ] * cospi_12_64 ;
 step1 [ 5 ] = dct_const_round_shift ( temp1 ) ;
 step1 [ 6 ] = dct_const_round_shift ( temp2 ) ;
 idct4 ( step1 , step1 ) ;
 step2 [ 4 ] = step1 [ 4 ] + step1 [ 5 ] ;
 step2 [ 5 ] = step1 [ 4 ] - step1 [ 5 ] ;
 step2 [ 6 ] = - step1 [ 6 ] + step1 [ 7 ] ;
 step2 [ 7 ] = step1 [ 6 ] + step1 [ 7 ] ;
 step1 [ 4 ] = step2 [ 4 ] ;
 temp1 = ( step2 [ 6 ] - step2 [ 5 ] ) * cospi_16_64 ;
 temp2 = ( step2 [ 5 ] + step2 [ 6 ] ) * cospi_16_64 ;
 step1 [ 5 ] = dct_const_round_shift ( temp1 ) ;
 step1 [ 6 ] = dct_const_round_shift ( temp2 ) ;
 step1 [ 7 ] = step2 [ 7 ] ;
 output [ 0 ] = step1 [ 0 ] + step1 [ 7 ] ;
 output [ 1 ] = step1 [ 1 ] + step1 [ 6 ] ;
 output [ 2 ] = step1 [ 2 ] + step1 [ 5 ] ;
 output [ 3 ] = step1 [ 3 ] + step1 [ 4 ] ;
 output [ 4 ] = step1 [ 3 ] - step1 [ 4 ] ;
 output [ 5 ] = step1 [ 2 ] - step1 [ 5 ] ;
 output [ 6 ] = step1 [ 1 ] - step1 [ 6 ] ;
 output [ 7 ] = step1 [ 0 ] - step1 [ 7 ] ;
 }