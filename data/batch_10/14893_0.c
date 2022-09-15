static void test_left_join_view ( ) {
 MYSQL_STMT * stmt ;
 int rc , i ;
 const char * query = "select t1.a, v1.x from t1 left join v1 on (t1.a= v1.x);
" ;
 myheader ( "test_left_join_view" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS t1,v1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "DROP VIEW IF EXISTS v1,t1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE t1 (a int)" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "insert into t1 values (1), (2), (3)" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create view v1 (x) as select a from t1 where a > 1" ) ;
 myquery ( rc ) ;
 stmt = mysql_stmt_init ( mysql ) ;
 rc = mysql_stmt_prepare ( stmt , query , strlen ( query ) ) ;
 check_execute ( stmt , rc ) ;
 for ( i = 0 ;
 i < 3 ;
 i ++ ) {
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = my_process_stmt_result ( stmt ) ;
 DIE_UNLESS ( 3 == rc ) ;
 }
 mysql_stmt_close ( stmt ) ;
 rc = mysql_query ( mysql , "DROP VIEW v1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "DROP TABLE t1" ) ;
 myquery ( rc ) ;
 }