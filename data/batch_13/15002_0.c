static void test_fetch_short ( ) {
 int rc ;
 myheader ( "test_fetch_short" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS test_bind_fetch" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE test_bind_fetch(c1 smallint unsigned, \ c2 smallint, \ c3 smallint unsigned, \ c4 smallint, \ c5 smallint, \ c6 smallint, \ c7 smallint unsigned)" ) ;
 myquery ( rc ) ;
 bind_fetch ( 5 ) ;
 }