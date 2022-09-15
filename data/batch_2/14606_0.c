static void print_primaries ( WriterContext * w , enum AVColorPrimaries color_primaries ) {
 const char * val = av_color_primaries_name ( color_primaries ) ;
 if ( ! val || color_primaries == AVCOL_PRI_UNSPECIFIED ) {
 print_str_opt ( "color_primaries" , "unknown" ) ;
 }
 else {
 print_str ( "color_primaries" , val ) ;
 }
 }