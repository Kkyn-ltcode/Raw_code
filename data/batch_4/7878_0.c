static int mysql_query_with_error_report ( MYSQL * mysql_con , MYSQL_RES * * res , const char * query ) {
 if ( mysql_query ( mysql_con , query ) || ( res && ! ( ( * res ) = mysql_store_result ( mysql_con ) ) ) ) {
 maybe_die ( EX_MYSQLERR , "Couldn't execute '%s': %s (%d)" , query , mysql_error ( mysql_con ) , mysql_errno ( mysql_con ) ) ;
 return 1 ;
 }
 return 0 ;
 }