static void vga_draw_line32_be ( VGACommonState * s1 , uint8_t * d , const uint8_t * s , int width ) {
 # ifdef HOST_WORDS_BIGENDIAN memcpy ( d , s , width * 4 ) ;
 # else int w ;
 uint32_t r , g , b ;
 w = width ;
 do {
 r = s [ 1 ] ;
 g = s [ 2 ] ;
 b = s [ 3 ] ;
 ( ( uint32_t * ) d ) [ 0 ] = rgb_to_pixel32 ( r , g , b ) ;
 s += 4 ;
 d += 4 ;
 }
 while ( -- w != 0 ) ;
 # endif }