static uint64_t calc_plane_error ( unsigned char * orig , int orig_stride , unsigned char * recon , int recon_stride , unsigned int cols , unsigned int rows ) {
 unsigned int row , col ;
 uint64_t total_sse = 0 ;
 int diff ;
 for ( row = 0 ;
 row + 16 <= rows ;
 row += 16 ) {
 for ( col = 0 ;
 col + 16 <= cols ;
 col += 16 ) {
 unsigned int sse ;
 vp8_mse16x16 ( orig + col , orig_stride , recon + col , recon_stride , & sse ) ;
 total_sse += sse ;
 }
 if ( col < cols ) {
 unsigned int border_row , border_col ;
 unsigned char * border_orig = orig ;
 unsigned char * border_recon = recon ;
 for ( border_row = 0 ;
 border_row < 16 ;
 border_row ++ ) {
 for ( border_col = col ;
 border_col < cols ;
 border_col ++ ) {
 diff = border_orig [ border_col ] - border_recon [ border_col ] ;
 total_sse += diff * diff ;
 }
 border_orig += orig_stride ;
 border_recon += recon_stride ;
 }
 }
 orig += orig_stride * 16 ;
 recon += recon_stride * 16 ;
 }
 for ( ;
 row < rows ;
 row ++ ) {
 for ( col = 0 ;
 col < cols ;
 col ++ ) {
 diff = orig [ col ] - recon [ col ] ;
 total_sse += diff * diff ;
 }
 orig += orig_stride ;
 recon += recon_stride ;
 }
 vp8_clear_system_state ( ) ;
 return total_sse ;
 }