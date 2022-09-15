static void test_select_version ( ) {
 MYSQL_STMT * stmt ;
 int rc ;
 myheader ( "test_select_version" ) ;
 stmt = mysql_simple_prepare ( mysql , "SELECT @@version" ) ;
 check_stmt ( stmt ) ;
 verify_param_count ( stmt , 0 ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 my_process_stmt_result ( stmt ) ;
 mysql_stmt_close ( stmt ) ;
 }