static void xps_select_best_font_encoding ( xps_document * doc , fz_font * font ) {
 static struct {
 int pid , eid ;
 }
 xps_cmap_list [ ] = {
 {
 3 , 10 }
 , {
 3 , 1 }
 , {
 3 , 5 }
 , {
 3 , 4 }
 , {
 3 , 3 }
 , {
 3 , 2 }
 , {
 3 , 0 }
 , {
 1 , 0 }
 , {
 - 1 , - 1 }
 , }
 ;
 int i , k , n , pid , eid ;
 n = xps_count_font_encodings ( font ) ;
 for ( k = 0 ;
 xps_cmap_list [ k ] . pid != - 1 ;
 k ++ ) {
 for ( i = 0 ;
 i < n ;
 i ++ ) {
 xps_identify_font_encoding ( font , i , & pid , & eid ) ;
 if ( pid == xps_cmap_list [ k ] . pid && eid == xps_cmap_list [ k ] . eid ) {
 xps_select_font_encoding ( font , i ) ;
 return ;
 }
 }
 }
 fz_warn ( doc -> ctx , "cannot find a suitable cmap" ) ;
 }