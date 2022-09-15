static void test_bug24179 ( ) {
 int rc ;
 MYSQL_STMT * stmt ;
 DBUG_ENTER ( "test_bug24179" ) ;
 myheader ( "test_bug24179" ) ;
 stmt = open_cursor ( "select 1 into @a" ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 DIE_UNLESS ( rc ) ;
 if ( ! opt_silent ) {
 printf ( "Got error (as expected): %d %s\n" , mysql_stmt_errno ( stmt ) , mysql_stmt_error ( stmt ) ) ;
 }
 DIE_UNLESS ( mysql_stmt_errno ( stmt ) == 1323 ) ;
 mysql_stmt_close ( stmt ) ;
 DBUG_VOID_RETURN ;
 }