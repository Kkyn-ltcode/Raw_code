void check_io ( FILE * file ) {
 if ( ferror ( file ) ) die ( EX_EOF , "Got errno %d on write" , errno ) ;
 }