void check_regerr ( my_regex_t * r , int err ) {
 char err_buf [ 1024 ] ;
 if ( err ) {
 my_regerror ( err , r , err_buf , sizeof ( err_buf ) ) ;
 die ( "Regex error: %s\n" , err_buf ) ;
 }
 }