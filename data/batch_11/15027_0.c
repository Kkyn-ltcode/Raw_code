static void test_fetch_bigint ( ) {
 int rc ;
 myheader ( "test_fetch_bigint" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS test_bind_fetch" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE test_bind_fetch(c1 bigint, \ c2 bigint, \ c3 bigint unsigned, \ c4 bigint unsigned, \ c5 bigint unsigned, \ c6 bigint unsigned, \ c7 bigint unsigned)" ) ;
 myquery ( rc ) ;
 bind_fetch ( 2 ) ;
 }