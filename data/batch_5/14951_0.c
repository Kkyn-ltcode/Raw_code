static void test_bug1946 ( ) {
 MYSQL_STMT * stmt ;
 int rc ;
 const char * query = "INSERT INTO prepare_command VALUES (?)" ;
 myheader ( "test_bug1946" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS prepare_command" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE prepare_command(ID INT)" ) ;
 myquery ( rc ) ;
 stmt = mysql_simple_prepare ( mysql , query ) ;
 check_stmt ( stmt ) ;
 rc = mysql_real_query ( mysql , query , strlen ( query ) ) ;
 DIE_UNLESS ( rc != 0 ) ;
 if ( ! opt_silent ) fprintf ( stdout , "Got error (as expected):\n" ) ;
 myerror ( NULL ) ;
 mysql_stmt_close ( stmt ) ;
 rc = mysql_query ( mysql , "DROP TABLE prepare_command" ) ;
 }