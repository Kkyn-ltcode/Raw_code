static void test_fetch_str ( ) {
 int rc ;
 myheader ( "test_fetch_str" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS test_bind_fetch" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE test_bind_fetch(c1 char(10), \ c2 char(10), \ c3 char(20), \ c4 char(20), \ c5 char(30), \ c6 char(40), \ c7 char(20))" ) ;
 myquery ( rc ) ;
 bind_fetch ( 3 ) ;
 }