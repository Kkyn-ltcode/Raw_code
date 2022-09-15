static void test_bug27592 ( ) {
 const int NUM_ITERATIONS = 40 ;
 int i ;
 int rc ;
 MYSQL_STMT * stmt = NULL ;
 MYSQL_BIND bind [ 1 ] ;
 MYSQL_TIME time_val ;
 DBUG_ENTER ( "test_bug27592" ) ;
 myheader ( "test_bug27592" ) ;
 mysql_query ( mysql , "DROP TABLE IF EXISTS t1" ) ;
 mysql_query ( mysql , "CREATE TABLE t1(c2 DATETIME)" ) ;
 stmt = mysql_simple_prepare ( mysql , "INSERT INTO t1 VALUES (?)" ) ;
 DIE_UNLESS ( stmt ) ;
 memset ( bind , 0 , sizeof ( bind ) ) ;
 bind [ 0 ] . buffer_type = MYSQL_TYPE_DATETIME ;
 bind [ 0 ] . buffer = ( char * ) & time_val ;
 bind [ 0 ] . length = NULL ;
 for ( i = 0 ;
 i < NUM_ITERATIONS ;
 i ++ ) {
 time_val . year = 2007 ;
 time_val . month = 6 ;
 time_val . day = 7 ;
 time_val . hour = 18 ;
 time_val . minute = 41 ;
 time_val . second = 3 ;
 time_val . second_part = 0 ;
 time_val . neg = 0 ;
 rc = mysql_stmt_bind_param ( stmt , bind ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 }
 mysql_stmt_close ( stmt ) ;
 DBUG_VOID_RETURN ;
 }