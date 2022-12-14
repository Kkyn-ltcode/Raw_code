static void test_store_result1 ( ) {
 MYSQL_STMT * stmt ;
 int rc ;
 myheader ( "test_store_result1" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS test_store_result" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE test_store_result(col1 int , col2 varchar(50))" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "INSERT INTO test_store_result VALUES(10, 'venu'), (20, 'mysql')" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "INSERT INTO test_store_result(col2) VALUES('monty')" ) ;
 myquery ( rc ) ;
 rc = mysql_commit ( mysql ) ;
 myquery ( rc ) ;
 stmt = mysql_simple_prepare ( mysql , "SELECT * FROM test_store_result" ) ;
 check_stmt ( stmt ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_stmt_store_result ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = 0 ;
 while ( mysql_stmt_fetch ( stmt ) != MYSQL_NO_DATA ) rc ++ ;
 if ( ! opt_silent ) fprintf ( stdout , "\n total rows: %d" , rc ) ;
 DIE_UNLESS ( rc == 3 ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_stmt_store_result ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = 0 ;
 while ( mysql_stmt_fetch ( stmt ) != MYSQL_NO_DATA ) rc ++ ;
 if ( ! opt_silent ) fprintf ( stdout , "\n total rows: %d" , rc ) ;
 DIE_UNLESS ( rc == 3 ) ;
 mysql_stmt_close ( stmt ) ;
 }