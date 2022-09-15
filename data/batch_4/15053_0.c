static void test_field_misc ( ) {
 MYSQL_STMT * stmt ;
 MYSQL_RES * result ;
 int rc ;
 myheader ( "test_field_misc" ) ;
 rc = mysql_query ( mysql , "SELECT @@autocommit" ) ;
 myquery ( rc ) ;
 result = mysql_store_result ( mysql ) ;
 mytest ( result ) ;
 rc = my_process_result_set ( result ) ;
 DIE_UNLESS ( rc == 1 ) ;
 verify_prepare_field ( result , 0 , "@@autocommit" , "" , MYSQL_TYPE_LONGLONG , "" , "" , "" , 1 , 0 ) ;
 mysql_free_result ( result ) ;
 stmt = mysql_simple_prepare ( mysql , "SELECT @@autocommit" ) ;
 check_stmt ( stmt ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 result = mysql_stmt_result_metadata ( stmt ) ;
 mytest ( result ) ;
 rc = my_process_stmt_result ( stmt ) ;
 DIE_UNLESS ( rc == 1 ) ;
 verify_prepare_field ( result , 0 , "@@autocommit" , "" , MYSQL_TYPE_LONGLONG , "" , "" , "" , 1 , 0 ) ;
 mysql_free_result ( result ) ;
 mysql_stmt_close ( stmt ) ;
 stmt = mysql_simple_prepare ( mysql , "SELECT @@max_error_count" ) ;
 check_stmt ( stmt ) ;
 result = mysql_stmt_result_metadata ( stmt ) ;
 mytest ( result ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = my_process_stmt_result ( stmt ) ;
 DIE_UNLESS ( rc == 1 ) ;
 verify_prepare_field ( result , 0 , "@@max_error_count" , "" , MYSQL_TYPE_LONGLONG , "" , "" , "" , MY_INT64_NUM_DECIMAL_DIGITS , 0 ) ;
 mysql_free_result ( result ) ;
 mysql_stmt_close ( stmt ) ;
 stmt = mysql_simple_prepare ( mysql , "SELECT @@max_allowed_packet" ) ;
 check_stmt ( stmt ) ;
 result = mysql_stmt_result_metadata ( stmt ) ;
 mytest ( result ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 DIE_UNLESS ( 1 == my_process_stmt_result ( stmt ) ) ;
 verify_prepare_field ( result , 0 , "@@max_allowed_packet" , "" , MYSQL_TYPE_LONGLONG , "" , "" , "" , MY_INT64_NUM_DECIMAL_DIGITS , 0 ) ;
 mysql_free_result ( result ) ;
 mysql_stmt_close ( stmt ) ;
 stmt = mysql_simple_prepare ( mysql , "SELECT @@sql_warnings" ) ;
 check_stmt ( stmt ) ;
 result = mysql_stmt_result_metadata ( stmt ) ;
 mytest ( result ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = my_process_stmt_result ( stmt ) ;
 DIE_UNLESS ( rc == 1 ) ;
 verify_prepare_field ( result , 0 , "@@sql_warnings" , "" , MYSQL_TYPE_LONGLONG , "" , "" , "" , 1 , 0 ) ;
 mysql_free_result ( result ) ;
 mysql_stmt_close ( stmt ) ;
 }