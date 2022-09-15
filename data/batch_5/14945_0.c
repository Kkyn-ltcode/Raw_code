static void test_bug29687 ( ) {
 const int NUM_ITERATIONS = 40 ;
 int i ;
 int rc ;
 MYSQL_STMT * stmt = NULL ;
 DBUG_ENTER ( "test_bug29687" ) ;
 myheader ( "test_bug29687" ) ;
 stmt = mysql_simple_prepare ( mysql , "SELECT 1 FROM dual WHERE 0=2" ) ;
 DIE_UNLESS ( stmt ) ;
 for ( i = 0 ;
 i < NUM_ITERATIONS ;
 i ++ ) {
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 mysql_stmt_store_result ( stmt ) ;
 while ( mysql_stmt_fetch ( stmt ) == 0 ) ;
 mysql_stmt_free_result ( stmt ) ;
 }
 mysql_stmt_close ( stmt ) ;
 DBUG_VOID_RETURN ;
 }