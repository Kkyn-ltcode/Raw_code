static char * get_relative_path ( const char * path ) {
 if ( test_if_hard_path ( path ) && is_prefix ( path , DEFAULT_MYSQL_HOME ) && strcmp ( DEFAULT_MYSQL_HOME , FN_ROOTDIR ) ) {
 path += ( uint ) strlen ( DEFAULT_MYSQL_HOME ) ;
 while ( * path == FN_LIBCHAR || * path == FN_LIBCHAR2 ) path ++ ;
 }
 return ( char * ) path ;
 }