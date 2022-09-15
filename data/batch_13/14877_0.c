static void test_bug57058 ( ) {
 MYSQL_RES * res ;
 int rc ;
 DBUG_ENTER ( "test_bug57058" ) ;
 myheader ( "test_bug57058" ) ;
 rc = mysql_query ( mysql , "set @@session.long_query_time=0.1" ) ;
 myquery ( rc ) ;
 DIE_UNLESS ( ! ( mysql -> server_status & SERVER_QUERY_WAS_SLOW ) ) ;
 rc = mysql_query ( mysql , "select sleep(1)" ) ;
 myquery ( rc ) ;
 res = mysql_store_result ( mysql ) ;
 DIE_UNLESS ( mysql -> server_status & SERVER_QUERY_WAS_SLOW ) ;
 mysql_free_result ( res ) ;
 rc = mysql_query ( mysql , "set @@session.long_query_time=default" ) ;
 myquery ( rc ) ;
 DBUG_VOID_RETURN ;
 }