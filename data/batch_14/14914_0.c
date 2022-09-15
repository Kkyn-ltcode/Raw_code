static void test_debug_example ( ) {
 int rc ;
 MYSQL_RES * result ;
 myheader ( "test_debug_example" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS test_debug_example" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE test_debug_example(" "id INT PRIMARY KEY AUTO_INCREMENT, " "name VARCHAR(20), xxx INT)" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "INSERT INTO test_debug_example (name) " "VALUES ('mysql')" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "UPDATE test_debug_example SET name='updated' " "WHERE name='deleted'" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "SELECT * FROM test_debug_example where name='mysql'" ) ;
 myquery ( rc ) ;
 result = mysql_use_result ( mysql ) ;
 mytest ( result ) ;
 ( void ) my_process_result_set ( result ) ;
 mysql_free_result ( result ) ;
 rc = mysql_query ( mysql , "DROP TABLE test_debug_example" ) ;
 myquery ( rc ) ;
 }