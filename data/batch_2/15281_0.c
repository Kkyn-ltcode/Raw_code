static int prefix_array ( const char * dirname , char * * array , size_t n ) {
 register size_t i ;
 size_t dirlen = strlen ( dirname ) ;
 # if defined __MSDOS__ || defined WINDOWS32 int sep_char = '/' ;
 # define DIRSEP_CHAR sep_char # else # define DIRSEP_CHAR '/' # endif if ( dirlen == 1 && dirname [ 0 ] == '/' ) dirlen = 0 ;
 # if defined __MSDOS__ || defined WINDOWS32 else if ( dirlen > 1 ) {
 if ( dirname [ dirlen - 1 ] == '/' && dirname [ dirlen - 2 ] == ':' ) -- dirlen ;
 else if ( dirname [ dirlen - 1 ] == ':' ) {
 -- dirlen ;
 sep_char = ':' ;
 }
 }
 # endif for ( i = 0 ;
 i < n ;
 ++ i ) {
 size_t eltlen = strlen ( array [ i ] ) + 1 ;
 char * new = ( char * ) malloc ( dirlen + 1 + eltlen ) ;
 if ( new == NULL ) {
 while ( i > 0 ) free ( array [ -- i ] ) ;
 return 1 ;
 }
 {
 char * endp = mempcpy ( new , dirname , dirlen ) ;
 * endp ++ = DIRSEP_CHAR ;
 mempcpy ( endp , array [ i ] , eltlen ) ;
 }
 free ( array [ i ] ) ;
 array [ i ] = new ;
 }
 return 0 ;
 }