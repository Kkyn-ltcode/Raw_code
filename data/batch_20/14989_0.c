static void test_bug29692 ( ) {
 MYSQL * conn ;
 if ( ! ( conn = mysql_client_init ( NULL ) ) ) {
 myerror ( "test_bug29692 init failed" ) ;
 exit ( 1 ) ;
 }
 if ( ! ( mysql_real_connect ( conn , opt_host , opt_user , opt_password , opt_db ? opt_db : "test" , opt_port , opt_unix_socket , CLIENT_FOUND_ROWS ) ) ) {
 myerror ( "test_bug29692 connection failed" ) ;
 mysql_close ( mysql ) ;
 exit ( 1 ) ;
 }
 myquery ( mysql_query ( conn , "drop table if exists t1" ) ) ;
 myquery ( mysql_query ( conn , "create table t1(f1 int)" ) ) ;
 myquery ( mysql_query ( conn , "insert into t1 values(1)" ) ) ;
 DIE_UNLESS ( 1 == mysql_affected_rows ( conn ) ) ;
 myquery ( mysql_query ( conn , "drop table t1" ) ) ;
 mysql_close ( conn ) ;
 }