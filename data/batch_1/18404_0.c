static char * pathToFullPath ( const char * path , const char * source ) {
 int32_t length ;
 int32_t newLength ;
 char * fullPath ;
 int32_t n ;
 length = ( uint32_t ) ( uprv_strlen ( path ) + 1 ) ;
 newLength = ( length + 1 + ( int32_t ) uprv_strlen ( source ) ) ;
 fullPath = ( char * ) uprv_malloc ( newLength ) ;
 if ( source != NULL ) {
 uprv_strcpy ( fullPath , source ) ;
 uprv_strcat ( fullPath , U_FILE_SEP_STRING ) ;
 }
 else {
 fullPath [ 0 ] = 0 ;
 }
 n = ( int32_t ) uprv_strlen ( fullPath ) ;
 fullPath [ n ] = 0 ;
 uprv_strcat ( fullPath , path ) ;
 # if ( U_FILE_ALT_SEP_CHAR != U_TREE_ENTRY_SEP_CHAR ) # if ( U_FILE_ALT_SEP_CHAR != U_FILE_SEP_CHAR ) for ( ;
 fullPath [ n ] ;
 n ++ ) {
 if ( fullPath [ n ] == U_FILE_ALT_SEP_CHAR ) {
 fullPath [ n ] = U_FILE_SEP_CHAR ;
 }
 }
 # endif # endif # if ( U_FILE_SEP_CHAR != U_TREE_ENTRY_SEP_CHAR ) for ( ;
 fullPath [ n ] ;
 n ++ ) {
 if ( fullPath [ n ] == U_TREE_ENTRY_SEP_CHAR ) {
 fullPath [ n ] = U_FILE_SEP_CHAR ;
 }
 }
 # endif return fullPath ;
 }