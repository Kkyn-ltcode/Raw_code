static void test_bug12243 ( ) {
 MYSQL_STMT * stmt1 , * stmt2 ;
 int rc ;
 const char * stmt_text ;
 ulong type ;
 myheader ( "test_bug12243" ) ;
 if ( ! have_innodb ) {
 if ( ! opt_silent ) printf ( "This test requires InnoDB.\n" ) ;
 return ;
 }
 mysql_query ( mysql , "drop table if exists t1" ) ;
 mysql_query ( mysql , "create table t1 (a int) engine=InnoDB" ) ;
 rc = mysql_query ( mysql , "insert into t1 (a) values (1), (2)" ) ;
 myquery ( rc ) ;
 mysql_autocommit ( mysql , FALSE ) ;
 stmt1 = mysql_stmt_init ( mysql ) ;
 stmt2 = mysql_stmt_init ( mysql ) ;
 type = ( ulong ) CURSOR_TYPE_READ_ONLY ;
 mysql_stmt_attr_set ( stmt1 , STMT_ATTR_CURSOR_TYPE , ( const void * ) & type ) ;
 mysql_stmt_attr_set ( stmt2 , STMT_ATTR_CURSOR_TYPE , ( const void * ) & type ) ;
 stmt_text = "select a from t1" ;
 rc = mysql_stmt_prepare ( stmt1 , stmt_text , strlen ( stmt_text ) ) ;
 check_execute ( stmt1 , rc ) ;
 rc = mysql_stmt_execute ( stmt1 ) ;
 check_execute ( stmt1 , rc ) ;
 rc = mysql_stmt_fetch ( stmt1 ) ;
 check_execute ( stmt1 , rc ) ;
 rc = mysql_stmt_prepare ( stmt2 , stmt_text , strlen ( stmt_text ) ) ;
 check_execute ( stmt2 , rc ) ;
 rc = mysql_stmt_execute ( stmt2 ) ;
 check_execute ( stmt2 , rc ) ;
 rc = mysql_stmt_fetch ( stmt2 ) ;
 check_execute ( stmt2 , rc ) ;
 rc = mysql_stmt_close ( stmt1 ) ;
 check_execute ( stmt1 , rc ) ;
 rc = mysql_commit ( mysql ) ;
 myquery ( rc ) ;
 rc = mysql_stmt_fetch ( stmt2 ) ;
 check_execute ( stmt2 , rc ) ;
 mysql_stmt_close ( stmt2 ) ;
 rc = mysql_query ( mysql , "drop table t1" ) ;
 myquery ( rc ) ;
 mysql_autocommit ( mysql , TRUE ) ;
 }