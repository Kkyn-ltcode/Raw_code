static void vga_draw_line15_be ( VGACommonState * vga , uint8_t * d , uint32_t addr , int width ) {
 int w ;
 uint32_t v , r , g , b ;
 w = width ;
 do {
 v = vga_read_word_be ( vga , addr ) ;
 r = ( v >> 7 ) & 0xf8 ;
 g = ( v >> 2 ) & 0xf8 ;
 b = ( v << 3 ) & 0xf8 ;
 ( ( uint32_t * ) d ) [ 0 ] = rgb_to_pixel32 ( r , g , b ) ;
 addr += 2 ;
 d += 4 ;
 }
 while ( -- w != 0 ) ;
 }