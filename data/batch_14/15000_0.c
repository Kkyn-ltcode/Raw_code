static void test_bug20152 ( ) {
 MYSQL_BIND my_bind [ 1 ] ;
 MYSQL_STMT * stmt ;
 MYSQL_TIME tm ;
 int rc ;
 const char * query = "INSERT INTO t1 (f1) VALUES (?)" ;
 myheader ( "test_bug20152" ) ;
 memset ( my_bind , 0 , sizeof ( my_bind ) ) ;
 my_bind [ 0 ] . buffer_type = MYSQL_TYPE_DATE ;
 my_bind [ 0 ] . buffer = ( void * ) & tm ;
 tm . year = 2006 ;
 tm . month = 6 ;
 tm . day = 18 ;
 tm . hour = 14 ;
 tm . minute = 9 ;
 tm . second = 42 ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS t1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE t1 (f1 DATE)" ) ;
 myquery ( rc ) ;
 stmt = mysql_stmt_init ( mysql ) ;
 rc = mysql_stmt_prepare ( stmt , query , strlen ( query ) ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_stmt_bind_param ( stmt , my_bind ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_stmt_close ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_query ( mysql , "DROP TABLE t1" ) ;
 myquery ( rc ) ;
 if ( tm . hour == 14 && tm . minute == 9 && tm . second == 42 ) {
 if ( ! opt_silent ) printf ( "OK!" ) ;
 }
 else {
 printf ( "[14:09:42] != [%02d:%02d:%02d]\n" , tm . hour , tm . minute , tm . second ) ;
 DIE_UNLESS ( 0 == 1 ) ;
 }
 }