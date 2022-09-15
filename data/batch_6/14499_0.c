static int com_tee ( String * buffer __attribute__ ( ( unused ) ) , char * line __attribute__ ( ( unused ) ) ) {
 char file_name [ FN_REFLEN ] , * end , * param ;
 if ( status . batch ) return 0 ;
 while ( my_isspace ( charset_info , * line ) ) line ++ ;
 if ( ! ( param = strchr ( line , ' ' ) ) ) {
 if ( ! strlen ( outfile ) ) {
 printf ( "No previous outfile available, you must give a filename!\n" ) ;
 return 0 ;
 }
 else if ( opt_outfile ) {
 tee_fprintf ( stdout , "Currently logging to file '%s'\n" , outfile ) ;
 return 0 ;
 }
 else param = outfile ;
 }
 while ( my_isspace ( charset_info , * param ) ) param ++ ;
 end = strmake_buf ( file_name , param ) ;
 while ( end > file_name && ( my_isspace ( charset_info , end [ - 1 ] ) || my_iscntrl ( charset_info , end [ - 1 ] ) ) ) end -- ;
 end [ 0 ] = 0 ;
 if ( end == file_name ) {
 printf ( "No outfile specified!\n" ) ;
 return 0 ;
 }
 init_tee ( file_name ) ;
 return 0 ;
 }