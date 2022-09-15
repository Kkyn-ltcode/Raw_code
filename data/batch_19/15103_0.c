static void test_prepare_resultset ( ) {
 MYSQL_STMT * stmt ;
 int rc ;
 MYSQL_RES * result ;
 myheader ( "test_prepare_resultset" ) ;
 rc = mysql_autocommit ( mysql , TRUE ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS test_prepare_resultset" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE test_prepare_resultset(id int, \ name varchar(50), extra double)" ) ;
 myquery ( rc ) ;
 stmt = mysql_simple_prepare ( mysql , "SELECT * FROM test_prepare_resultset" ) ;
 check_stmt ( stmt ) ;
 verify_param_count ( stmt , 0 ) ;
 result = mysql_stmt_result_metadata ( stmt ) ;
 mytest ( result ) ;
 my_print_result_metadata ( result ) ;
 mysql_free_result ( result ) ;
 mysql_stmt_close ( stmt ) ;
 }