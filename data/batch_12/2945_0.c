static void decode_10bit_pulse ( int code , int pulse_position [ 8 ] , int i1 , int i2 , int i3 ) {
 const uint8_t * positions = base_five_table [ code >> 3 ] ;
 pulse_position [ i1 ] = ( positions [ 2 ] << 1 ) + ( code & 1 ) ;
 pulse_position [ i2 ] = ( positions [ 1 ] << 1 ) + ( ( code >> 1 ) & 1 ) ;
 pulse_position [ i3 ] = ( positions [ 0 ] << 1 ) + ( ( code >> 2 ) & 1 ) ;
 }