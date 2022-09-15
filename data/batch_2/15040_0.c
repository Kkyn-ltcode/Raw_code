static void test_bug14845 ( ) {
 MYSQL_STMT * stmt ;
 int rc ;
 const ulong type = CURSOR_TYPE_READ_ONLY ;
 const char * query = "select count(*) from t1 where 1 = 0" ;
 myheader ( "test_bug14845" ) ;
 rc = mysql_query ( mysql , "drop table if exists t1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create table t1 (id int(11) default null, " "name varchar(20) default null)" "engine=MyISAM DEFAULT CHARSET=utf8" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "insert into t1 values (1,'abc'),(2,'def')" ) ;
 myquery ( rc ) ;
 stmt = mysql_stmt_init ( mysql ) ;
 rc = mysql_stmt_attr_set ( stmt , STMT_ATTR_CURSOR_TYPE , ( const void * ) & type ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_stmt_prepare ( stmt , query , strlen ( query ) ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_stmt_fetch ( stmt ) ;
 DIE_UNLESS ( rc == 0 ) ;
 rc = mysql_stmt_fetch ( stmt ) ;
 DIE_UNLESS ( rc == MYSQL_NO_DATA ) ;
 mysql_stmt_close ( stmt ) ;
 rc = mysql_query ( mysql , "drop table t1" ) ;
 myquery ( rc ) ;
 }