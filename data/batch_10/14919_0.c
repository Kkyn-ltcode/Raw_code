static void test_bug11904 ( ) {
 MYSQL_STMT * stmt1 ;
 int rc ;
 const char * stmt_text ;
 const ulong type = ( ulong ) CURSOR_TYPE_READ_ONLY ;
 MYSQL_BIND my_bind [ 2 ] ;
 int country_id = 0 ;
 char row_data [ 11 ] = {
 0 }
 ;
 myheader ( "test_bug11904" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS bug11904b" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE bug11904b (id int, name char(10), primary key(id, name))" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "INSERT INTO bug11904b VALUES (1, 'sofia'), (1,'plovdiv')," " (1,'varna'), (2,'LA'), (2,'new york'), (3,'heidelberg')," " (3,'berlin'), (3, 'frankfurt')" ) ;
 myquery ( rc ) ;
 mysql_commit ( mysql ) ;
 stmt1 = mysql_stmt_init ( mysql ) ;
 mysql_stmt_attr_set ( stmt1 , STMT_ATTR_CURSOR_TYPE , ( const void * ) & type ) ;
 stmt_text = "SELECT id, MIN(name) FROM bug11904b GROUP BY id" ;
 rc = mysql_stmt_prepare ( stmt1 , stmt_text , strlen ( stmt_text ) ) ;
 check_execute ( stmt1 , rc ) ;
 memset ( my_bind , 0 , sizeof ( my_bind ) ) ;
 my_bind [ 0 ] . buffer_type = MYSQL_TYPE_LONG ;
 my_bind [ 0 ] . buffer = & country_id ;
 my_bind [ 0 ] . buffer_length = 0 ;
 my_bind [ 0 ] . length = 0 ;
 my_bind [ 1 ] . buffer_type = MYSQL_TYPE_STRING ;
 my_bind [ 1 ] . buffer = & row_data ;
 my_bind [ 1 ] . buffer_length = sizeof ( row_data ) - 1 ;
 my_bind [ 1 ] . length = 0 ;
 rc = mysql_stmt_bind_result ( stmt1 , my_bind ) ;
 check_execute ( stmt1 , rc ) ;
 rc = mysql_stmt_execute ( stmt1 ) ;
 check_execute ( stmt1 , rc ) ;
 rc = mysql_stmt_fetch ( stmt1 ) ;
 check_execute ( stmt1 , rc ) ;
 DIE_UNLESS ( country_id == 1 ) ;
 DIE_UNLESS ( memcmp ( row_data , "plovdiv" , 7 ) == 0 ) ;
 rc = mysql_stmt_fetch ( stmt1 ) ;
 check_execute ( stmt1 , rc ) ;
 DIE_UNLESS ( country_id == 2 ) ;
 DIE_UNLESS ( memcmp ( row_data , "LA" , 2 ) == 0 ) ;
 rc = mysql_stmt_fetch ( stmt1 ) ;
 check_execute ( stmt1 , rc ) ;
 DIE_UNLESS ( country_id == 3 ) ;
 DIE_UNLESS ( memcmp ( row_data , "berlin" , 6 ) == 0 ) ;
 rc = mysql_stmt_close ( stmt1 ) ;
 check_execute ( stmt1 , rc ) ;
 rc = mysql_query ( mysql , "drop table bug11904b" ) ;
 myquery ( rc ) ;
 }