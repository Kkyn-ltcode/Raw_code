static void test_bad_union ( ) {
 MYSQL_STMT * stmt ;
 const char * query = "SELECT 1, 2 union SELECT 1" ;
 myheader ( "test_bad_union" ) ;
 stmt = mysql_simple_prepare ( mysql , query ) ;
 DIE_UNLESS ( stmt == 0 ) ;
 myerror ( NULL ) ;
 }