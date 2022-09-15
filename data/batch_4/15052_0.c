static void test_bug28934 ( ) {
 my_bool error = 0 ;
 MYSQL_BIND bind [ 5 ] ;
 MYSQL_STMT * stmt ;
 int cnt ;
 myquery ( mysql_query ( mysql , "drop table if exists t1" ) ) ;
 myquery ( mysql_query ( mysql , "create table t1(id int)" ) ) ;
 myquery ( mysql_query ( mysql , "insert into t1 values(1),(2),(3),(4),(5)" ) ) ;
 stmt = mysql_simple_prepare ( mysql , "select * from t1 where id in(?,?,?,?,?)" ) ;
 check_stmt ( stmt ) ;
 memset ( & bind , 0 , sizeof ( bind ) ) ;
 for ( cnt = 0 ;
 cnt < 5 ;
 cnt ++ ) {
 bind [ cnt ] . buffer_type = MYSQL_TYPE_LONG ;
 bind [ cnt ] . buffer = ( char * ) & cnt ;
 bind [ cnt ] . buffer_length = 0 ;
 }
 myquery ( mysql_stmt_bind_param ( stmt , bind ) ) ;
 stmt -> param_count = 2 ;
 error = mysql_stmt_execute ( stmt ) ;
 DIE_UNLESS ( error != 0 ) ;
 myerror ( NULL ) ;
 mysql_stmt_close ( stmt ) ;
 myquery ( mysql_query ( mysql , "drop table t1" ) ) ;
 }