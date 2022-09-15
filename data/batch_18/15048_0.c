static void test_bug13488 ( ) {
 MYSQL_BIND my_bind [ 3 ] ;
 MYSQL_STMT * stmt1 ;
 int rc , f1 , f2 , f3 , i ;
 const ulong type = CURSOR_TYPE_READ_ONLY ;
 const char * query = "select * from t1 left join t2 on f1=f2 where f1=1" ;
 myheader ( "test_bug13488" ) ;
 rc = mysql_query ( mysql , "drop table if exists t1, t2" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create table t1 (f1 int not null primary key)" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create table t2 (f2 int not null primary key, " "f3 int not null)" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "insert into t1 values (1), (2)" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "insert into t2 values (1,2), (2,4)" ) ;
 myquery ( rc ) ;
 memset ( my_bind , 0 , sizeof ( my_bind ) ) ;
 for ( i = 0 ;
 i < 3 ;
 i ++ ) {
 my_bind [ i ] . buffer_type = MYSQL_TYPE_LONG ;
 my_bind [ i ] . buffer_length = 4 ;
 my_bind [ i ] . length = 0 ;
 }
 my_bind [ 0 ] . buffer = & f1 ;
 my_bind [ 1 ] . buffer = & f2 ;
 my_bind [ 2 ] . buffer = & f3 ;
 stmt1 = mysql_stmt_init ( mysql ) ;
 rc = mysql_stmt_attr_set ( stmt1 , STMT_ATTR_CURSOR_TYPE , ( const void * ) & type ) ;
 check_execute ( stmt1 , rc ) ;
 rc = mysql_stmt_prepare ( stmt1 , query , strlen ( query ) ) ;
 check_execute ( stmt1 , rc ) ;
 rc = mysql_stmt_execute ( stmt1 ) ;
 check_execute ( stmt1 , rc ) ;
 rc = mysql_stmt_bind_result ( stmt1 , my_bind ) ;
 check_execute ( stmt1 , rc ) ;
 rc = mysql_stmt_fetch ( stmt1 ) ;
 check_execute ( stmt1 , rc ) ;
 rc = mysql_stmt_free_result ( stmt1 ) ;
 check_execute ( stmt1 , rc ) ;
 rc = mysql_stmt_reset ( stmt1 ) ;
 check_execute ( stmt1 , rc ) ;
 rc = mysql_stmt_close ( stmt1 ) ;
 check_execute ( stmt1 , rc ) ;
 if ( ! opt_silent ) {
 printf ( "data: f1: %d;
 f2: %d;
 f3: %d\n" , f1 , f2 , f3 ) ;
 printf ( "data is: %s\n" , ( f1 == 1 && f2 == 1 && f3 == 2 ) ? "OK" : "wrong" ) ;
 }
 DIE_UNLESS ( f1 == 1 && f2 == 1 && f3 == 2 ) ;
 rc = mysql_query ( mysql , "drop table t1, t2" ) ;
 myquery ( rc ) ;
 }