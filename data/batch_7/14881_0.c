static void test_select_show_table ( ) {
 MYSQL_STMT * stmt ;
 int rc , i ;
 myheader ( "test_select_show_table" ) ;
 stmt = mysql_simple_prepare ( mysql , "SHOW TABLES FROM mysql" ) ;
 check_stmt ( stmt ) ;
 verify_param_count ( stmt , 0 ) ;
 for ( i = 1 ;
 i < 3 ;
 i ++ ) {
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 }
 my_process_stmt_result ( stmt ) ;
 mysql_stmt_close ( stmt ) ;
 }