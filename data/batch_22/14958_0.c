static void test_distinct ( ) {
 MYSQL_STMT * stmt ;
 int rc , i ;
 const char * query = "SELECT 2+count(distinct b), group_concat(a) FROM t1 group by a" ;
 myheader ( "test_distinct" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS t1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE t1 (a int , b int);
" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "insert into t1 values (1, 1), (2, 2), (3, 3), (4, 4), (5, 5), \ (1, 10), (2, 20), (3, 30), (4, 40), (5, 50);
" ) ;
 myquery ( rc ) ;
 for ( i = 0 ;
 i < 3 ;
 i ++ ) {
 stmt = mysql_simple_prepare ( mysql , query ) ;
 check_stmt ( stmt ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = my_process_stmt_result ( stmt ) ;
 DIE_UNLESS ( rc == 5 ) ;
 mysql_stmt_close ( stmt ) ;
 }
 rc = mysql_query ( mysql , "DROP TABLE t1" ) ;
 myquery ( rc ) ;
 }