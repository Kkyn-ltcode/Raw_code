static void test_bug14210 ( ) {
 MYSQL_STMT * stmt ;
 int rc , i ;
 const char * stmt_text ;
 ulong type ;
 myheader ( "test_bug14210" ) ;
 mysql_query ( mysql , "drop table if exists t1" ) ;
 mysql_query ( mysql , "create table t1 (a varchar(255)) engine=InnoDB" ) ;
 rc = mysql_query ( mysql , "insert into t1 (a) values (repeat('a', 256))" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "set @@session.max_heap_table_size=16384" ) ;
 for ( i = 0 ;
 i < 8 ;
 i ++ ) {
 rc = mysql_query ( mysql , "insert into t1 (a) select a from t1" ) ;
 myquery ( rc ) ;
 }
 stmt = mysql_stmt_init ( mysql ) ;
 type = ( ulong ) CURSOR_TYPE_READ_ONLY ;
 mysql_stmt_attr_set ( stmt , STMT_ATTR_CURSOR_TYPE , ( const void * ) & type ) ;
 stmt_text = "select a from t1" ;
 rc = mysql_stmt_prepare ( stmt , stmt_text , strlen ( stmt_text ) ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 while ( ( rc = mysql_stmt_fetch ( stmt ) ) == 0 ) ;
 DIE_UNLESS ( rc == MYSQL_NO_DATA ) ;
 rc = mysql_stmt_close ( stmt ) ;
 rc = mysql_query ( mysql , "drop table t1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "set @@session.max_heap_table_size=default" ) ;
 myquery ( rc ) ;
 }