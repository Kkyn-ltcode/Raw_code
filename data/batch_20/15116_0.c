static void test_selecttmp ( ) {
 MYSQL_STMT * stmt ;
 int rc , i ;
 const char * query = "select a, (select count(distinct t1.b) as sum from t1, t2 where t1.a=t2.a and t2.b > 0 and t1.a <= t3.b group by t1.a order by sum limit 1) from t3" ;
 myheader ( "test_select_tmp" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS t1, t2, t3" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE t1 (a int , b int);
" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create table t2 (a int, b int);
" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create table t3 (a int, b int);
" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "insert into t1 values (0, 100), (1, 2), (1, 3), (2, 2), (2, 7), \ (2, -1), (3, 10);
" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "insert into t2 values (0, 0), (1, 1), (2, 1), (3, 1), (4, 1);
" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "insert into t3 values (3, 3), (2, 2), (1, 1);
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
 DIE_UNLESS ( rc == 3 ) ;
 }
 mysql_stmt_close ( stmt ) ;
 rc = mysql_query ( mysql , "DROP TABLE t1, t2, t3" ) ;
 myquery ( rc ) ;
 }