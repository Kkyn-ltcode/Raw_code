void vp9_fdct16x16_1_c ( const int16_t * input , tran_low_t * output , int stride ) {
 int r , c ;
 tran_low_t sum = 0 ;
 for ( r = 0 ;
 r < 16 ;
 ++ r ) for ( c = 0 ;
 c < 16 ;
 ++ c ) sum += input [ r * stride + c ] ;
 output [ 0 ] = sum >> 1 ;
 output [ 1 ] = 0 ;
 }