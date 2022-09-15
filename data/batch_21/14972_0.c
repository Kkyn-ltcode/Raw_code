static void test_bug5315 ( ) {
 MYSQL_STMT * stmt ;
 const char * stmt_text ;
 int rc ;
 myheader ( "test_bug5315" ) ;
 stmt_text = "SELECT 1" ;
 stmt = mysql_stmt_init ( mysql ) ;
 rc = mysql_stmt_prepare ( stmt , stmt_text , strlen ( stmt_text ) ) ;
 DIE_UNLESS ( rc == 0 ) ;
 if ( ! opt_silent ) printf ( "Excuting mysql_change_user\n" ) ;
 mysql_change_user ( mysql , opt_user , opt_password , current_db ) ;
 if ( ! opt_silent ) printf ( "Excuting mysql_stmt_execute\n" ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 DIE_UNLESS ( rc != 0 ) ;
 if ( rc ) {
 if ( ! opt_silent ) printf ( "Got error (as expected): '%s'\n" , mysql_stmt_error ( stmt ) ) ;
 }
 if ( ! opt_silent ) printf ( "Excuting mysql_stmt_close\n" ) ;
 mysql_stmt_close ( stmt ) ;
 if ( ! opt_silent ) printf ( "Excuting mysql_stmt_init\n" ) ;
 stmt = mysql_stmt_init ( mysql ) ;
 rc = mysql_stmt_prepare ( stmt , stmt_text , strlen ( stmt_text ) ) ;
 DIE_UNLESS ( rc == 0 ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 DIE_UNLESS ( rc == 0 ) ;
 mysql_stmt_close ( stmt ) ;
 }