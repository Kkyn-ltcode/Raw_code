int append_warnings ( DYNAMIC_STRING * ds , MYSQL * mysql ) {
 uint count ;
 MYSQL_RES * warn_res ;
 DBUG_ENTER ( "append_warnings" ) ;
 if ( ! ( count = mysql_warning_count ( mysql ) ) ) DBUG_RETURN ( 0 ) ;
 DBUG_ASSERT ( ! mysql_more_results ( mysql ) ) ;
 if ( mysql_real_query ( mysql , "SHOW WARNINGS" , 13 ) ) die ( "Error running query \"SHOW WARNINGS\": %s" , mysql_error ( mysql ) ) ;
 if ( ! ( warn_res = mysql_store_result ( mysql ) ) ) die ( "Warning count is %u but didn't get any warnings" , count ) ;
 append_result ( ds , warn_res ) ;
 mysql_free_result ( warn_res ) ;
 DBUG_PRINT ( "warnings" , ( "%s" , ds -> str ) ) ;
 DBUG_RETURN ( count ) ;
 }