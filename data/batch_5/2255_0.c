static int ivi_dec_tile_data_size ( GetBitContext * gb ) {
 int len ;
 len = 0 ;
 if ( get_bits1 ( gb ) ) {
 len = get_bits ( gb , 8 ) ;
 if ( len == 255 ) len = get_bits_long ( gb , 24 ) ;
 }
 align_get_bits ( gb ) ;
 return len ;
 }