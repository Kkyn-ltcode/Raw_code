static void test_warnings ( ) {
 int rc ;
 MYSQL_RES * result ;
 myheader ( "test_warnings" ) ;
 mysql_query ( mysql , "DROP TABLE if exists test_non_exists" ) ;
 rc = mysql_query ( mysql , "DROP TABLE if exists test_non_exists" ) ;
 myquery ( rc ) ;
 if ( ! opt_silent ) fprintf ( stdout , "\n total warnings: %d" , mysql_warning_count ( mysql ) ) ;
 rc = mysql_query ( mysql , "SHOW WARNINGS" ) ;
 myquery ( rc ) ;
 result = mysql_store_result ( mysql ) ;
 mytest ( result ) ;
 rc = my_process_result_set ( result ) ;
 DIE_UNLESS ( rc == 1 ) ;
 mysql_free_result ( result ) ;
 }