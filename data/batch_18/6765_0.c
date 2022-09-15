static void cirrus_cursor_invalidate ( VGACommonState * s1 ) {
 CirrusVGAState * s = container_of ( s1 , CirrusVGAState , vga ) ;
 int size ;
 if ( ! ( s -> vga . sr [ 0x12 ] & CIRRUS_CURSOR_SHOW ) ) {
 size = 0 ;
 }
 else {
 if ( s -> vga . sr [ 0x12 ] & CIRRUS_CURSOR_LARGE ) size = 64 ;
 else size = 32 ;
 }
 if ( s -> last_hw_cursor_size != size || s -> last_hw_cursor_x != s -> vga . hw_cursor_x || s -> last_hw_cursor_y != s -> vga . hw_cursor_y ) {
 invalidate_cursor1 ( s ) ;
 s -> last_hw_cursor_size = size ;
 s -> last_hw_cursor_x = s -> vga . hw_cursor_x ;
 s -> last_hw_cursor_y = s -> vga . hw_cursor_y ;
 cirrus_cursor_compute_yrange ( s ) ;
 invalidate_cursor1 ( s ) ;
 }
 }