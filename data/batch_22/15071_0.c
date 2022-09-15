static void test_bug15510 ( ) {
 MYSQL_STMT * stmt ;
 int rc ;
 const char * query = "select 1 from dual where 1/0" ;
 myheader ( "test_bug15510" ) ;
 rc = mysql_query ( mysql , "set @@sql_mode='ERROR_FOR_DIVISION_BY_ZERO'" ) ;
 myquery ( rc ) ;
 stmt = mysql_stmt_init ( mysql ) ;
 rc = mysql_stmt_prepare ( stmt , query , strlen ( query ) ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_stmt_fetch ( stmt ) ;
 DIE_UNLESS ( mysql_warning_count ( mysql ) ) ;
 mysql_stmt_close ( stmt ) ;
 rc = mysql_query ( mysql , "set @@sql_mode=''" ) ;
 myquery ( rc ) ;
 }