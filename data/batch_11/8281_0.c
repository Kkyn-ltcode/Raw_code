static void mspack_fmap_free ( void * mem ) {
 if ( mem ) {
 free ( mem ) ;
 mem = NULL ;
 }
 return ;
 }