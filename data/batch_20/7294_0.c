static void * show_parts ( void * arg ) {
 char * device = arg ;
 int nbd ;
 nbd = open ( device , O_RDWR ) ;
 if ( nbd >= 0 ) {
 close ( nbd ) ;
 }
 return NULL ;
 }