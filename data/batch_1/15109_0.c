static void test_fetch_long ( ) {
 int rc ;
 myheader ( "test_fetch_long" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS test_bind_fetch" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE test_bind_fetch(c1 int unsigned, \ c2 int unsigned, \ c3 int, \ c4 int, \ c5 int, \ c6 int unsigned, \ c7 int)" ) ;
 myquery ( rc ) ;
 bind_fetch ( 4 ) ;
 }