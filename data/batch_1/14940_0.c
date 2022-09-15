static void test_wl4435_2 ( ) {
 MYSQL_STMT * stmt ;
 int i ;
 int rc ;
 char query [ MAX_TEST_QUERY_LENGTH ] ;
 myheader ( "test_wl4435_2" ) ;
 mct_start_logging ( "test_wl4435_2" ) ;
 for ( i = 0 ;
 i < 10 ;
 ++ i ) {
 rc = mysql_query ( mysql , "DROP PROCEDURE IF EXISTS p1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE PROCEDURE p1()" "BEGIN " " SELECT 1;
 " " SELECT 2, 3 UNION SELECT 4, 5;
 " " SELECT 6, 7, 8;
 " "END" ) ;
 myquery ( rc ) ;
 strmov ( query , "CALL p1()" ) ;
 stmt = mysql_simple_prepare ( mysql , query ) ;
 check_stmt ( stmt ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 mysql_stmt_close ( stmt ) ;
 rc = mysql_commit ( mysql ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "DROP PROCEDURE p1" ) ;
 myquery ( rc ) ;
 }
 mct_close_log ( ) ;
 }