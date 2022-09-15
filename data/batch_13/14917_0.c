static void test_bug2248 ( ) {
 MYSQL_STMT * stmt ;
 int rc ;
 const char * query1 = "SELECT DATABASE()" ;
 const char * query2 = "INSERT INTO test_bug2248 VALUES (10)" ;
 myheader ( "test_bug2248" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS test_bug2248" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE test_bug2248 (id int)" ) ;
 myquery ( rc ) ;
 stmt = mysql_simple_prepare ( mysql , query1 ) ;
 check_stmt ( stmt ) ;
 rc = mysql_stmt_fetch ( stmt ) ;
 check_execute_r ( stmt , rc ) ;
 rc = mysql_stmt_store_result ( stmt ) ;
 check_execute_r ( stmt , rc ) ;
 mysql_stmt_close ( stmt ) ;
 stmt = mysql_simple_prepare ( mysql , query2 ) ;
 check_stmt ( stmt ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_stmt_fetch ( stmt ) ;
 DIE_UNLESS ( rc == 1 ) ;
 rc = mysql_stmt_store_result ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_stmt_fetch ( stmt ) ;
 check_execute_r ( stmt , rc ) ;
 DIE_UNLESS ( rc == 1 ) ;
 mysql_stmt_close ( stmt ) ;
 rc = mysql_query ( mysql , "DROP TABLE test_bug2248" ) ;
 myquery ( rc ) ;
 }