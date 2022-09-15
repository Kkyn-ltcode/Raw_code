static void DB_error ( MYSQL * mysql_arg , const char * when ) {
 DBUG_ENTER ( "DB_error" ) ;
 maybe_die ( EX_MYSQLERR , "Got error: %d: \"%s\" %s" , mysql_errno ( mysql_arg ) , mysql_error ( mysql_arg ) , when ) ;
 DBUG_VOID_RETURN ;
 }