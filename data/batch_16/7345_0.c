static void vmsvga_value_write ( void * opaque , uint32_t address , uint32_t value ) {
 struct vmsvga_state_s * s = opaque ;
 if ( s -> index >= SVGA_SCRATCH_BASE ) {
 trace_vmware_scratch_write ( s -> index , value ) ;
 }
 else if ( s -> index >= SVGA_PALETTE_BASE ) {
 trace_vmware_palette_write ( s -> index , value ) ;
 }
 else {
 trace_vmware_value_write ( s -> index , value ) ;
 }
 switch ( s -> index ) {
 case SVGA_REG_ID : if ( value == SVGA_ID_2 || value == SVGA_ID_1 || value == SVGA_ID_0 ) {
 s -> svgaid = value ;
 }
 break ;
 case SVGA_REG_ENABLE : s -> enable = ! ! value ;
 s -> invalidated = 1 ;
 s -> vga . hw_ops -> invalidate ( & s -> vga ) ;
 if ( s -> enable && s -> config ) {
 vga_dirty_log_stop ( & s -> vga ) ;
 }
 else {
 vga_dirty_log_start ( & s -> vga ) ;
 }
 break ;
 case SVGA_REG_WIDTH : if ( value <= SVGA_MAX_WIDTH ) {
 s -> new_width = value ;
 s -> invalidated = 1 ;
 }
 else {
 printf ( "%s: Bad width: %i\n" , __func__ , value ) ;
 }
 break ;
 case SVGA_REG_HEIGHT : if ( value <= SVGA_MAX_HEIGHT ) {
 s -> new_height = value ;
 s -> invalidated = 1 ;
 }
 else {
 printf ( "%s: Bad height: %i\n" , __func__ , value ) ;
 }
 break ;
 case SVGA_REG_BITS_PER_PIXEL : if ( value != 32 ) {
 printf ( "%s: Bad bits per pixel: %i bits\n" , __func__ , value ) ;
 s -> config = 0 ;
 s -> invalidated = 1 ;
 }
 break ;
 case SVGA_REG_CONFIG_DONE : if ( value ) {
 s -> fifo = ( uint32_t * ) s -> fifo_ptr ;
 if ( ( CMD ( min ) | CMD ( max ) | CMD ( next_cmd ) | CMD ( stop ) ) & 3 ) {
 break ;
 }
 if ( CMD ( min ) < ( uint8_t * ) s -> cmd -> fifo - ( uint8_t * ) s -> fifo ) {
 break ;
 }
 if ( CMD ( max ) > SVGA_FIFO_SIZE ) {
 break ;
 }
 if ( CMD ( max ) < CMD ( min ) + 10 * 1024 ) {
 break ;
 }
 vga_dirty_log_stop ( & s -> vga ) ;
 }
 s -> config = ! ! value ;
 break ;
 case SVGA_REG_SYNC : s -> syncing = 1 ;
 vmsvga_fifo_run ( s ) ;
 break ;
 case SVGA_REG_GUEST_ID : s -> guest = value ;
 # ifdef VERBOSE if ( value >= GUEST_OS_BASE && value < GUEST_OS_BASE + ARRAY_SIZE ( vmsvga_guest_id ) ) {
 printf ( "%s: guest runs %s.\n" , __func__ , vmsvga_guest_id [ value - GUEST_OS_BASE ] ) ;
 }
 # endif break ;
 case SVGA_REG_CURSOR_ID : s -> cursor . id = value ;
 break ;
 case SVGA_REG_CURSOR_X : s -> cursor . x = value ;
 break ;
 case SVGA_REG_CURSOR_Y : s -> cursor . y = value ;
 break ;
 case SVGA_REG_CURSOR_ON : s -> cursor . on |= ( value == SVGA_CURSOR_ON_SHOW ) ;
 s -> cursor . on &= ( value != SVGA_CURSOR_ON_HIDE ) ;
 # ifdef HW_MOUSE_ACCEL if ( value <= SVGA_CURSOR_ON_SHOW ) {
 dpy_mouse_set ( s -> vga . con , s -> cursor . x , s -> cursor . y , s -> cursor . on ) ;
 }
 # endif break ;
 case SVGA_REG_DEPTH : case SVGA_REG_MEM_REGS : case SVGA_REG_NUM_DISPLAYS : case SVGA_REG_PITCHLOCK : case SVGA_PALETTE_BASE ... SVGA_PALETTE_END : break ;
 default : if ( s -> index >= SVGA_SCRATCH_BASE && s -> index < SVGA_SCRATCH_BASE + s -> scratch_size ) {
 s -> scratch [ s -> index - SVGA_SCRATCH_BASE ] = value ;
 break ;
 }
 printf ( "%s: Bad register %02x\n" , __func__ , s -> index ) ;
 }
 }