char * convertToNativePathSeparators ( char * path ) {
 # if defined ( U_MAKE_IS_NMAKE ) char * itr ;
 while ( ( itr = uprv_strchr ( path , U_FILE_ALT_SEP_CHAR ) ) ) {
 * itr = U_FILE_SEP_CHAR ;
 }
 # endif return path ;
 }