static void vga_draw_line24_be ( VGACommonState * s1 , uint8_t * d , const uint8_t * s , int width ) {
 int w ;
 uint32_t r , g , b ;
 w = width ;
 do {
 r = s [ 0 ] ;
 g = s [ 1 ] ;
 b = s [ 2 ] ;
 ( ( uint32_t * ) d ) [ 0 ] = rgb_to_pixel32 ( r , g , b ) ;
 s += 3 ;
 d += 4 ;
 }
 while ( -- w != 0 ) ;
 }