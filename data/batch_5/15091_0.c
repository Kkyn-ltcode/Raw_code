static void test_bug44495 ( ) {
 int rc ;
 MYSQL con ;
 MYSQL_STMT * stmt ;
 DBUG_ENTER ( "test_bug44495" ) ;
 myheader ( "test_44495" ) ;
 rc = mysql_query ( mysql , "DROP PROCEDURE IF EXISTS p1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE PROCEDURE p1(IN arg VARCHAR(25))" " BEGIN SET @stmt = CONCAT('SELECT \"', arg, '\"');
" " PREPARE ps1 FROM @stmt;
" " EXECUTE ps1;
" " DROP PREPARE ps1;
" "END;
" ) ;
 myquery ( rc ) ;
 DIE_UNLESS ( mysql_client_init ( & con ) ) ;
 DIE_UNLESS ( mysql_real_connect ( & con , opt_host , opt_user , opt_password , current_db , opt_port , opt_unix_socket , CLIENT_MULTI_RESULTS ) ) ;
 stmt = mysql_simple_prepare ( & con , "CALL p1('abc')" ) ;
 check_stmt ( stmt ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = my_process_stmt_result ( stmt ) ;
 DIE_UNLESS ( rc == 1 ) ;
 mysql_stmt_close ( stmt ) ;
 mysql_close ( & con ) ;
 rc = mysql_query ( mysql , "DROP PROCEDURE p1" ) ;
 myquery ( rc ) ;
 DBUG_VOID_RETURN ;
 }