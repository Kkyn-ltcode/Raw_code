static void test_errors ( ) {
 int rc ;
 MYSQL_RES * result ;
 myheader ( "test_errors" ) ;
 mysql_query ( mysql , "DROP TABLE if exists test_non_exists" ) ;
 rc = mysql_query ( mysql , "DROP TABLE test_non_exists" ) ;
 myquery_r ( rc ) ;
 rc = mysql_query ( mysql , "SHOW ERRORS" ) ;
 myquery ( rc ) ;
 result = mysql_store_result ( mysql ) ;
 mytest ( result ) ;
 ( void ) my_process_result_set ( result ) ;
 mysql_free_result ( result ) ;
 }