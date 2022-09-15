static void test_do_set ( ) {
 MYSQL_STMT * stmt_do , * stmt_set ;
 char * query ;
 int rc , i ;
 myheader ( "test_do_set" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS t1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create table t1 (a int)" ) ;
 myquery ( rc ) ;
 query = ( char * ) "do @var:=(1 in (select * from t1))" ;
 stmt_do = mysql_simple_prepare ( mysql , query ) ;
 check_stmt ( stmt_do ) ;
 query = ( char * ) "set @var=(1 in (select * from t1))" ;
 stmt_set = mysql_simple_prepare ( mysql , query ) ;
 check_stmt ( stmt_set ) ;
 for ( i = 0 ;
 i < 3 ;
 i ++ ) {
 rc = mysql_stmt_execute ( stmt_do ) ;
 check_execute ( stmt_do , rc ) ;
 if ( ! opt_silent ) fprintf ( stdout , "do %i\n" , i ) ;
 rc = mysql_stmt_execute ( stmt_set ) ;
 check_execute ( stmt_set , rc ) ;
 if ( ! opt_silent ) fprintf ( stdout , "set %i\n" , i ) ;
 }
 mysql_stmt_close ( stmt_do ) ;
 mysql_stmt_close ( stmt_set ) ;
 }