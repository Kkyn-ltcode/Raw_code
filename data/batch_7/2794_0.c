static void append_extra_bits ( int32_t * buffer [ 2 ] , int32_t * extra_bits_buffer [ 2 ] , int extra_bits , int channels , int nb_samples ) {
 int i , ch ;
 for ( ch = 0 ;
 ch < channels ;
 ch ++ ) for ( i = 0 ;
 i < nb_samples ;
 i ++ ) buffer [ ch ] [ i ] = ( buffer [ ch ] [ i ] << extra_bits ) | extra_bits_buffer [ ch ] [ i ] ;
 }