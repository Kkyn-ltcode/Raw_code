static void test_subqueries_ref ( ) {
 MYSQL_STMT * stmt ;
 int rc , i ;
 const char * query = "SELECT a as ccc from t1 outr where a+1=(SELECT 1+outr.a from t1 where outr.a+1=a+1 and a=1)" ;
 myheader ( "test_subqueries_ref" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS t1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE t1 (a int);
" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "insert into t1 values (1), (2), (3), (4), (5);
" ) ;
 myquery ( rc ) ;
 stmt = mysql_simple_prepare ( mysql , query ) ;
 check_stmt ( stmt ) ;
 for ( i = 0 ;
 i < 3 ;
 i ++ ) {
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = my_process_stmt_result ( stmt ) ;
 DIE_UNLESS ( rc == 1 ) ;
 }
 mysql_stmt_close ( stmt ) ;
 rc = mysql_query ( mysql , "DROP TABLE t1" ) ;
 myquery ( rc ) ;
 }