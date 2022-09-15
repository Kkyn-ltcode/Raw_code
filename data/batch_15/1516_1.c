void vp9_fdct32x32_1_c ( const int16_t * input , int16_t * output , int stride ) {
 int r , c ;
 int16_t sum = 0 ;
 for ( r = 0 ;
 r < 32 ;
 ++ r ) for ( c = 0 ;
 c < 32 ;
 ++ c ) sum += input [ r * stride + c ] ;
 output [ 0 ] = sum >> 3 ;
 output [ 1 ] = 0 ;
 }