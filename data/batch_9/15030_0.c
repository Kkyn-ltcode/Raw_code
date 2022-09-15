static void test_bug21635 ( ) {
 const char * expr [ ] = {
 "MIN(i)" , "MIN(i)" , "MIN(i) AS A1" , "A1" , "MAX(i)" , "MAX(i)" , "MAX(i) AS A2" , "A2" , "COUNT(i)" , "COUNT(i)" , "COUNT(i) AS A3" , "A3" , }
 ;
 char query [ MAX_TEST_QUERY_LENGTH ] ;
 char * query_end ;
 MYSQL_RES * result ;
 MYSQL_FIELD * field ;
 unsigned int field_count , i , j ;
 int rc ;
 DBUG_ENTER ( "test_bug21635" ) ;
 myheader ( "test_bug21635" ) ;
 query_end = strxmov ( query , "SELECT " , NullS ) ;
 for ( i = 0 ;
 i < sizeof ( expr ) / sizeof ( * expr ) / 2 ;
 ++ i ) query_end = strxmov ( query_end , expr [ i * 2 ] , ", " , NullS ) ;
 query_end = strxmov ( query_end - 2 , " FROM t1 GROUP BY i" , NullS ) ;
 DIE_UNLESS ( query_end - query < MAX_TEST_QUERY_LENGTH ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS t1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE t1 (i INT)" ) ;
 myquery ( rc ) ;
 for ( j = 0 ;
 j < 2 ;
 j ++ ) {
 rc = mysql_query ( mysql , "INSERT INTO t1 VALUES (1)" ) ;
 myquery ( rc ) ;
 rc = mysql_real_query ( mysql , query , query_end - query ) ;
 myquery ( rc ) ;
 result = mysql_use_result ( mysql ) ;
 DIE_UNLESS ( result ) ;
 field_count = mysql_field_count ( mysql ) ;
 for ( i = 0 ;
 i < field_count ;
 ++ i ) {
 field = mysql_fetch_field_direct ( result , i ) ;
 if ( ! opt_silent ) if ( ! opt_silent ) printf ( "%s -> %s ... " , expr [ i * 2 ] , field -> name ) ;
 fflush ( stdout ) ;
 DIE_UNLESS ( field -> db [ 0 ] == 0 && field -> org_table [ 0 ] == 0 && field -> table [ 0 ] == 0 && field -> org_name [ 0 ] == 0 ) ;
 DIE_UNLESS ( strcmp ( field -> name , expr [ i * 2 + 1 ] ) == 0 ) ;
 if ( ! opt_silent ) if ( ! opt_silent ) puts ( "OK" ) ;
 }
 mysql_free_result ( result ) ;
 }
 rc = mysql_query ( mysql , "DROP TABLE t1" ) ;
 myquery ( rc ) ;
 DBUG_VOID_RETURN ;
 }