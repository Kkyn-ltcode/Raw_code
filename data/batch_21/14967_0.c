static void test_bug15752 ( ) {
 MYSQL mysql_local ;
 int rc , i ;
 const int ITERATION_COUNT = 100 ;
 const char * query = "CALL p1()" ;
 myheader ( "test_bug15752" ) ;
 rc = mysql_query ( mysql , "drop procedure if exists p1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create procedure p1() select 1" ) ;
 myquery ( rc ) ;
 mysql_client_init ( & mysql_local ) ;
 if ( ! mysql_real_connect ( & mysql_local , opt_host , opt_user , opt_password , current_db , opt_port , opt_unix_socket , CLIENT_MULTI_STATEMENTS ) ) {
 printf ( "Unable connect to MySQL server: %s\n" , mysql_error ( & mysql_local ) ) ;
 DIE_UNLESS ( 0 ) ;
 }
 rc = mysql_real_query ( & mysql_local , query , strlen ( query ) ) ;
 myquery ( rc ) ;
 mysql_free_result ( mysql_store_result ( & mysql_local ) ) ;
 rc = mysql_real_query ( & mysql_local , query , strlen ( query ) ) ;
 DIE_UNLESS ( rc && mysql_errno ( & mysql_local ) == CR_COMMANDS_OUT_OF_SYNC ) ;
 if ( ! opt_silent ) printf ( "Got error (as expected): %s\n" , mysql_error ( & mysql_local ) ) ;
 DIE_UNLESS ( mysql_next_result ( & mysql_local ) == 0 ) ;
 mysql_free_result ( mysql_store_result ( & mysql_local ) ) ;
 DIE_UNLESS ( mysql_next_result ( & mysql_local ) == - 1 ) ;
 for ( i = 0 ;
 i < ITERATION_COUNT ;
 i ++ ) {
 if ( mysql_real_query ( & mysql_local , query , strlen ( query ) ) ) {
 printf ( "\ni=%d %s failed: %s\n" , i , query , mysql_error ( & mysql_local ) ) ;
 break ;
 }
 mysql_free_result ( mysql_store_result ( & mysql_local ) ) ;
 DIE_UNLESS ( mysql_next_result ( & mysql_local ) == 0 ) ;
 mysql_free_result ( mysql_store_result ( & mysql_local ) ) ;
 DIE_UNLESS ( mysql_next_result ( & mysql_local ) == - 1 ) ;
 }
 mysql_close ( & mysql_local ) ;
 rc = mysql_query ( mysql , "drop procedure p1" ) ;
 myquery ( rc ) ;
 }