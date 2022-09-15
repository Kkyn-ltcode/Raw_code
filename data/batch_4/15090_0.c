static void test_bug12001 ( ) {
 MYSQL * mysql_local ;
 MYSQL_RES * result ;
 const char * query = "DROP TABLE IF EXISTS test_table;
" "CREATE TABLE test_table(id INT);
" "INSERT INTO test_table VALUES(10);
" "UPDATE test_table SET id=20 WHERE id=10;
" "SELECT * FROM test_table;
" "INSERT INTO non_existent_table VALUES(11);
" ;
 int rc , res ;
 myheader ( "test_bug12001" ) ;
 if ( ! ( mysql_local = mysql_client_init ( NULL ) ) ) {
 fprintf ( stdout , "\n mysql_client_init() failed" ) ;
 exit ( 1 ) ;
 }
 if ( ! mysql_real_connect ( mysql_local , opt_host , opt_user , opt_password , current_db , opt_port , opt_unix_socket , CLIENT_MULTI_STATEMENTS ) ) {
 fprintf ( stdout , "\n mysql_real_connect() failed" ) ;
 exit ( 1 ) ;
 }
 rc = mysql_query ( mysql_local , query ) ;
 myquery ( rc ) ;
 do {
 if ( mysql_field_count ( mysql_local ) && ( result = mysql_use_result ( mysql_local ) ) ) {
 mysql_free_result ( result ) ;
 }
 }
 while ( ! ( res = mysql_next_result ( mysql_local ) ) ) ;
 rc = mysql_query ( mysql_local , "DROP TABLE IF EXISTS test_table" ) ;
 myquery ( rc ) ;
 mysql_close ( mysql_local ) ;
 DIE_UNLESS ( res == 1 ) ;
 }