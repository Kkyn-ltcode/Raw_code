static void test_bug11037 ( ) {
 MYSQL_STMT * stmt ;
 int rc ;
 const char * stmt_text ;
 myheader ( "test_bug11037" ) ;
 mysql_query ( mysql , "drop table if exists t1" ) ;
 rc = mysql_query ( mysql , "create table t1 (id int not null)" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "insert into t1 values (1)" ) ;
 myquery ( rc ) ;
 stmt_text = "select id FROM t1" ;
 stmt = mysql_stmt_init ( mysql ) ;
 rc = mysql_stmt_prepare ( stmt , stmt_text , strlen ( stmt_text ) ) ;
 rc = mysql_stmt_fetch ( stmt ) ;
 DIE_UNLESS ( rc == 1 ) ;
 if ( ! opt_silent ) fprintf ( stdout , "Got error, as expected:\n [%d] %s\n" , mysql_stmt_errno ( stmt ) , mysql_stmt_error ( stmt ) ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_stmt_fetch ( stmt ) ;
 DIE_UNLESS ( rc == 0 ) ;
 rc = mysql_stmt_fetch ( stmt ) ;
 DIE_UNLESS ( rc == MYSQL_NO_DATA ) ;
 rc = mysql_stmt_fetch ( stmt ) ;
 DIE_UNLESS ( rc == MYSQL_NO_DATA ) ;
 mysql_stmt_close ( stmt ) ;
 rc = mysql_query ( mysql , "drop table t1" ) ;
 myquery ( rc ) ;
 }