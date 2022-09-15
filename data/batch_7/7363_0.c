static void show_query ( MYSQL * mysql , const char * query ) {
 MYSQL_RES * res ;
 DBUG_ENTER ( "show_query" ) ;
 if ( ! mysql ) DBUG_VOID_RETURN ;
 if ( mysql_query ( mysql , query ) ) {
 log_msg ( "Error running query '%s': %d %s" , query , mysql_errno ( mysql ) , mysql_error ( mysql ) ) ;
 DBUG_VOID_RETURN ;
 }
 if ( ( res = mysql_store_result ( mysql ) ) == NULL ) {
 DBUG_VOID_RETURN ;
 }
 {
 MYSQL_ROW row ;
 unsigned int i ;
 unsigned int row_num = 0 ;
 unsigned int num_fields = mysql_num_fields ( res ) ;
 MYSQL_FIELD * fields = mysql_fetch_fields ( res ) ;
 fprintf ( stderr , "=== %s ===\n" , query ) ;
 while ( ( row = mysql_fetch_row ( res ) ) ) {
 unsigned long * lengths = mysql_fetch_lengths ( res ) ;
 row_num ++ ;
 fprintf ( stderr , "---- %d. ----\n" , row_num ) ;
 for ( i = 0 ;
 i < num_fields ;
 i ++ ) {
 fprintf ( stderr , "%s\t%.*s\n" , fields [ i ] . name , ( int ) lengths [ i ] , row [ i ] ? row [ i ] : "NULL" ) ;
 }
 }
 for ( i = 0 ;
 i < strlen ( query ) + 8 ;
 i ++ ) fprintf ( stderr , "=" ) ;
 fprintf ( stderr , "\n\n" ) ;
 }
 mysql_free_result ( res ) ;
 DBUG_VOID_RETURN ;
 }