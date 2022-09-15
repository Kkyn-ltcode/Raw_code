static void test_union2 ( ) {
 MYSQL_STMT * stmt ;
 int rc , i ;
 myheader ( "test_union2" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS t1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE t1(col1 INT, \ col2 VARCHAR(40), \ col3 SMALLINT, \ col4 TIMESTAMP)" ) ;
 myquery ( rc ) ;
 stmt = mysql_simple_prepare ( mysql , "select col1 FROM t1 where col1=1 union distinct " "select col1 FROM t1 where col1=2" ) ;
 check_stmt ( stmt ) ;
 for ( i = 0 ;
 i < 3 ;
 i ++ ) {
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = my_process_stmt_result ( stmt ) ;
 DIE_UNLESS ( rc == 0 ) ;
 }
 mysql_stmt_close ( stmt ) ;
 rc = mysql_query ( mysql , "DROP TABLE t1" ) ;
 myquery ( rc ) ;
 }