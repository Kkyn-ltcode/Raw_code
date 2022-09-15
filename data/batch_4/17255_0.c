void vp9_fdct8x8_1_c ( const int16_t * input , tran_low_t * output , int stride ) {
 int r , c ;
 tran_low_t sum = 0 ;
 for ( r = 0 ;
 r < 8 ;
 ++ r ) for ( c = 0 ;
 c < 8 ;
 ++ c ) sum += input [ r * stride + c ] ;
 output [ 0 ] = sum ;
 output [ 1 ] = 0 ;
 }