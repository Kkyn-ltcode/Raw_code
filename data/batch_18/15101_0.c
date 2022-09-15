static void test_field_flags ( ) {
 int rc ;
 MYSQL_RES * result ;
 MYSQL_FIELD * field ;
 unsigned int i ;
 myheader ( "test_field_flags" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS test_field_flags" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE test_field_flags(id int NOT NULL AUTO_INCREMENT PRIMARY KEY, \ id1 int NOT NULL, \ id2 int UNIQUE, \ id3 int, \ id4 int NOT NULL, \ id5 int, \ KEY(id3, id4))" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "SELECT * FROM test_field_flags" ) ;
 myquery ( rc ) ;
 result = mysql_use_result ( mysql ) ;
 mytest ( result ) ;
 mysql_field_seek ( result , 0 ) ;
 if ( ! opt_silent ) fputc ( '\n' , stdout ) ;
 for ( i = 0 ;
 i < mysql_num_fields ( result ) ;
 i ++ ) {
 field = mysql_fetch_field ( result ) ;
 if ( ! opt_silent ) {
 fprintf ( stdout , "\n field:%d" , i ) ;
 if ( field -> flags & NOT_NULL_FLAG ) fprintf ( stdout , "\n NOT_NULL_FLAG" ) ;
 if ( field -> flags & PRI_KEY_FLAG ) fprintf ( stdout , "\n PRI_KEY_FLAG" ) ;
 if ( field -> flags & UNIQUE_KEY_FLAG ) fprintf ( stdout , "\n UNIQUE_KEY_FLAG" ) ;
 if ( field -> flags & MULTIPLE_KEY_FLAG ) fprintf ( stdout , "\n MULTIPLE_KEY_FLAG" ) ;
 if ( field -> flags & AUTO_INCREMENT_FLAG ) fprintf ( stdout , "\n AUTO_INCREMENT_FLAG" ) ;
 }
 }
 mysql_free_result ( result ) ;
 }