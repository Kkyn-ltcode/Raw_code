static void cirrus_cursor_draw_line ( VGACommonState * s1 , uint8_t * d1 , int scr_y ) {
 CirrusVGAState * s = container_of ( s1 , CirrusVGAState , vga ) ;
 int w , h , x1 , x2 , poffset ;
 unsigned int color0 , color1 ;
 const uint8_t * palette , * src ;
 uint32_t content ;
 if ( ! ( s -> vga . sr [ 0x12 ] & CIRRUS_CURSOR_SHOW ) ) return ;
 if ( s -> vga . sr [ 0x12 ] & CIRRUS_CURSOR_LARGE ) {
 h = 64 ;
 }
 else {
 h = 32 ;
 }
 if ( scr_y < s -> vga . hw_cursor_y || scr_y >= ( s -> vga . hw_cursor_y + h ) ) {
 return ;
 }
 src = s -> vga . vram_ptr + s -> real_vram_size - 16 * 1024 ;
 if ( s -> vga . sr [ 0x12 ] & CIRRUS_CURSOR_LARGE ) {
 src += ( s -> vga . sr [ 0x13 ] & 0x3c ) * 256 ;
 src += ( scr_y - s -> vga . hw_cursor_y ) * 16 ;
 poffset = 8 ;
 content = ( ( uint32_t * ) src ) [ 0 ] | ( ( uint32_t * ) src ) [ 1 ] | ( ( uint32_t * ) src ) [ 2 ] | ( ( uint32_t * ) src ) [ 3 ] ;
 }
 else {
 src += ( s -> vga . sr [ 0x13 ] & 0x3f ) * 256 ;
 src += ( scr_y - s -> vga . hw_cursor_y ) * 4 ;
 poffset = 128 ;
 content = ( ( uint32_t * ) src ) [ 0 ] | ( ( uint32_t * ) ( src + 128 ) ) [ 0 ] ;
 }
 if ( ! content ) return ;
 w = h ;
 x1 = s -> vga . hw_cursor_x ;
 if ( x1 >= s -> vga . last_scr_width ) return ;
 x2 = s -> vga . hw_cursor_x + w ;
 if ( x2 > s -> vga . last_scr_width ) x2 = s -> vga . last_scr_width ;
 w = x2 - x1 ;
 palette = s -> cirrus_hidden_palette ;
 color0 = rgb_to_pixel32 ( c6_to_8 ( palette [ 0x0 * 3 ] ) , c6_to_8 ( palette [ 0x0 * 3 + 1 ] ) , c6_to_8 ( palette [ 0x0 * 3 + 2 ] ) ) ;
 color1 = rgb_to_pixel32 ( c6_to_8 ( palette [ 0xf * 3 ] ) , c6_to_8 ( palette [ 0xf * 3 + 1 ] ) , c6_to_8 ( palette [ 0xf * 3 + 2 ] ) ) ;
 d1 += x1 * 4 ;
 vga_draw_cursor_line ( d1 , src , poffset , w , color0 , color1 , 0xffffff ) ;
 }