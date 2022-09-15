static void fixDirToTreePath ( char * s ) {
 # if ( U_FILE_SEP_CHAR != U_TREE_ENTRY_SEP_CHAR ) || ( ( U_FILE_ALT_SEP_CHAR != U_FILE_SEP_CHAR ) && ( U_FILE_ALT_SEP_CHAR != U_TREE_ENTRY_SEP_CHAR ) ) char * t ;
 # endif # if ( U_FILE_SEP_CHAR != U_TREE_ENTRY_SEP_CHAR ) for ( t = s ;
 t = uprv_strchr ( t , U_FILE_SEP_CHAR ) ;
 ) {
 * t = U_TREE_ENTRY_SEP_CHAR ;
 }
 # endif # if ( U_FILE_ALT_SEP_CHAR != U_FILE_SEP_CHAR ) && ( U_FILE_ALT_SEP_CHAR != U_TREE_ENTRY_SEP_CHAR ) for ( t = s ;
 t = uprv_strchr ( t , U_FILE_ALT_SEP_CHAR ) ;
 ) {
 * t = U_TREE_ENTRY_SEP_CHAR ;
 }
 # endif }