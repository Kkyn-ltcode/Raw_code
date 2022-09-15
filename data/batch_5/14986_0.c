static void test_bug8880 ( ) {
 MYSQL_STMT * stmt_list [ 2 ] , * * stmt ;
 MYSQL_STMT * * stmt_list_end = ( MYSQL_STMT * * ) stmt_list + 2 ;
 int rc ;
 myheader ( "test_bug8880" ) ;
 mysql_query ( mysql , "drop table if exists t1" ) ;
 mysql_query ( mysql , "create table t1 (a int not null primary key, b int)" ) ;
 rc = mysql_query ( mysql , "insert into t1 values (1,1)" ) ;
 myquery ( rc ) ;
 for ( stmt = stmt_list ;
 stmt < stmt_list_end ;
 stmt ++ ) * stmt = open_cursor ( "select a from t1" ) ;
 for ( stmt = stmt_list ;
 stmt < stmt_list_end ;
 stmt ++ ) {
 rc = mysql_stmt_execute ( * stmt ) ;
 check_execute ( * stmt , rc ) ;
 }
 for ( stmt = stmt_list ;
 stmt < stmt_list_end ;
 stmt ++ ) mysql_stmt_close ( * stmt ) ;
 }