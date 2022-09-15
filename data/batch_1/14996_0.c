static void test_select_direct ( ) {
 int rc ;
 MYSQL_RES * result ;
 myheader ( "test_select_direct" ) ;
 rc = mysql_autocommit ( mysql , TRUE ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS test_select" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE test_select(id int, id1 tinyint, " " id2 float, " " id3 double, " " name varchar(50))" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "INSERT INTO test_select VALUES(10, 5, 2.3, 4.5, 'venu')" ) ;
 myquery ( rc ) ;
 rc = mysql_commit ( mysql ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "SELECT * FROM test_select" ) ;
 myquery ( rc ) ;
 result = mysql_store_result ( mysql ) ;
 mytest ( result ) ;
 ( void ) my_process_result_set ( result ) ;
 mysql_free_result ( result ) ;
 }