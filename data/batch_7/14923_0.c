static void test_fetch_float ( ) {
 int rc ;
 myheader ( "test_fetch_float" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS test_bind_fetch" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE test_bind_fetch(c1 float(3), \ c2 float, \ c3 float unsigned, \ c4 float, \ c5 float, \ c6 float, \ c7 float(10) unsigned)" ) ;
 myquery ( rc ) ;
 bind_fetch ( 2 ) ;
 }