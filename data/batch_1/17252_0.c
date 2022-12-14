void vp9_fht8x8_c ( const int16_t * input , tran_low_t * output , int stride , int tx_type ) {
 if ( tx_type == DCT_DCT ) {
 vp9_fdct8x8_c ( input , output , stride ) ;
 }
 else {
 tran_low_t out [ 64 ] ;
 tran_low_t * outptr = & out [ 0 ] ;
 int i , j ;
 tran_low_t temp_in [ 8 ] , temp_out [ 8 ] ;
 const transform_2d ht = FHT_8 [ tx_type ] ;
 for ( i = 0 ;
 i < 8 ;
 ++ i ) {
 for ( j = 0 ;
 j < 8 ;
 ++ j ) temp_in [ j ] = input [ j * stride + i ] * 4 ;
 ht . cols ( temp_in , temp_out ) ;
 for ( j = 0 ;
 j < 8 ;
 ++ j ) outptr [ j * 8 + i ] = temp_out [ j ] ;
 }
 for ( i = 0 ;
 i < 8 ;
 ++ i ) {
 for ( j = 0 ;
 j < 8 ;
 ++ j ) temp_in [ j ] = out [ j + i * 8 ] ;
 ht . rows ( temp_in , temp_out ) ;
 for ( j = 0 ;
 j < 8 ;
 ++ j ) output [ j + i * 8 ] = ( temp_out [ j ] + ( temp_out [ j ] < 0 ) ) >> 1 ;
 }
 }
 }