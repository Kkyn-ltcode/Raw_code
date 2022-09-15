static uint query_cache_hits ( MYSQL * conn ) {
 MYSQL_RES * res ;
 MYSQL_ROW row ;
 int rc ;
 uint result ;
 rc = mysql_query ( conn , "show status like 'qcache_hits'" ) ;
 myquery ( rc ) ;
 res = mysql_use_result ( conn ) ;
 DIE_UNLESS ( res ) ;
 row = mysql_fetch_row ( res ) ;
 DIE_UNLESS ( row ) ;
 result = atoi ( row [ 1 ] ) ;
 mysql_free_result ( res ) ;
 return result ;
 }