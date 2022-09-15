static char * fix_path_separator ( char * path ) {
 # ifdef WIN32 char * result ;
 char * c ;
 result = pg_strdup ( path ) ;
 for ( c = result ;
 * c != '\0' ;
 c ++ ) if ( * c == '/' ) * c = '\\' ;
 return result ;
 # else return path ;
 # endif }