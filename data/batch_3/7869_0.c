static char * get_actual_table_name ( const char * old_table_name , MEM_ROOT * root ) {
 char * name = 0 ;
 MYSQL_RES * table_res ;
 MYSQL_ROW row ;
 char query [ 50 + 2 * NAME_LEN ] ;
 char show_name_buff [ FN_REFLEN ] ;
 DBUG_ENTER ( "get_actual_table_name" ) ;
 DBUG_ASSERT ( 2 * sizeof ( old_table_name ) < sizeof ( show_name_buff ) ) ;
 my_snprintf ( query , sizeof ( query ) , "SHOW TABLES LIKE %s" , quote_for_like ( old_table_name , show_name_buff ) ) ;
 if ( mysql_query_with_error_report ( mysql , 0 , query ) ) return NullS ;
 if ( ( table_res = mysql_store_result ( mysql ) ) ) {
 my_ulonglong num_rows = mysql_num_rows ( table_res ) ;
 if ( num_rows > 0 ) {
 ulong * lengths ;
 row = mysql_fetch_row ( table_res ) ;
 lengths = mysql_fetch_lengths ( table_res ) ;
 name = strmake_root ( root , row [ 0 ] , lengths [ 0 ] ) ;
 }
 mysql_free_result ( table_res ) ;
 }
 DBUG_PRINT ( "exit" , ( "new_table_name: %s" , name ) ) ;
 DBUG_RETURN ( name ) ;
 }