static void test_fetch_double ( ) {
 int rc ;
 myheader ( "test_fetch_double" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS test_bind_fetch" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE test_bind_fetch(c1 double(5, 2), " "c2 double unsigned, c3 double unsigned, " "c4 double unsigned, c5 double unsigned, " "c6 double unsigned, c7 double unsigned)" ) ;
 myquery ( rc ) ;
 bind_fetch ( 3 ) ;
 }