static void test_bug11183 ( ) {
 int rc ;
 MYSQL_STMT * stmt ;
 char bug_statement [ ] = "insert into t1 values (1)" ;
 myheader ( "test_bug11183" ) ;
 mysql_query ( mysql , "drop table t1 if exists" ) ;
 mysql_query ( mysql , "create table t1 (a int)" ) ;
 stmt = mysql_stmt_init ( mysql ) ;
 DIE_UNLESS ( stmt != 0 ) ;
 rc = mysql_stmt_prepare ( stmt , bug_statement , strlen ( bug_statement ) ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_query ( mysql , "drop table t1" ) ;
 myquery ( rc ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 DIE_UNLESS ( rc ) ;
 mysql_stmt_reset ( stmt ) ;
 DIE_UNLESS ( mysql_stmt_errno ( stmt ) == 0 ) ;
 mysql_query ( mysql , "create table t1 (a int)" ) ;
 if ( mysql_stmt_execute ( stmt ) ) {
 mysql_stmt_reset ( stmt ) ;
 DIE_UNLESS ( mysql_stmt_errno ( stmt ) == 0 ) ;
 }
 mysql_stmt_close ( stmt ) ;
 rc = mysql_query ( mysql , "drop table t1" ) ;
 myquery ( rc ) ;
 }