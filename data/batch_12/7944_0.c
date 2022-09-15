static void * read_into_buffer ( FILE * fp , size_t * r_length ) {
 char * buffer ;
 size_t buflen ;
 size_t nread , bufsize = 0 ;
 * r_length = 0 ;
 # define NCHUNK 8192 # ifdef HAVE_W32_SYSTEM setmode ( fileno ( fp ) , O_BINARY ) ;
 # endif buffer = NULL ;
 buflen = 0 ;
 do {
 bufsize += NCHUNK ;
 buffer = realloc ( buffer , bufsize ) ;
 if ( ! buffer ) {
 perror ( "realloc failed" ) ;
 exit ( 1 ) ;
 }
 nread = fread ( buffer + buflen , 1 , NCHUNK , fp ) ;
 if ( nread < NCHUNK && ferror ( fp ) ) {
 perror ( "fread failed" ) ;
 exit ( 1 ) ;
 }
 buflen += nread ;
 }
 while ( nread == NCHUNK ) ;
 # undef NCHUNK * r_length = buflen ;
 return buffer ;
 }