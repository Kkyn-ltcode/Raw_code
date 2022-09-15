static my_bool dump_all_views_in_db ( char * database ) {
 char * table ;
 uint numrows ;
 char table_buff [ NAME_LEN * 2 + 3 ] ;
 char hash_key [ 2 * NAME_LEN + 2 ] ;
 char * afterdot ;
 afterdot = strmov ( hash_key , database ) ;
 * afterdot ++ = '.' ;
 if ( init_dumping ( database , init_dumping_views ) ) return 1 ;
 if ( opt_xml ) print_xml_tag ( md_result_file , "" , "\n" , "database" , "name=" , database , NullS ) ;
 if ( lock_tables ) {
 DYNAMIC_STRING query ;
 init_dynamic_string_checked ( & query , "LOCK TABLES " , 256 , 1024 ) ;
 for ( numrows = 0 ;
 ( table = getTableName ( 1 ) ) ;
 ) {
 char * end = strmov ( afterdot , table ) ;
 if ( include_table ( ( uchar * ) hash_key , end - hash_key ) ) {
 numrows ++ ;
 dynstr_append_checked ( & query , quote_name ( table , table_buff , 1 ) ) ;
 dynstr_append_checked ( & query , " READ /*!32311 LOCAL */," ) ;
 }
 }
 if ( numrows && mysql_real_query ( mysql , query . str , query . length - 1 ) ) DB_error ( mysql , "when using LOCK TABLES" ) ;
 dynstr_free ( & query ) ;
 }
 if ( flush_logs ) {
 if ( mysql_refresh ( mysql , REFRESH_LOG ) ) DB_error ( mysql , "when doing refresh" ) ;
 else verbose_msg ( "-- dump_all_views_in_db : logs flushed successfully!\n" ) ;
 }
 while ( ( table = getTableName ( 0 ) ) ) {
 char * end = strmov ( afterdot , table ) ;
 if ( include_table ( ( uchar * ) hash_key , end - hash_key ) ) get_view_structure ( table , database ) ;
 }
 if ( opt_xml ) {
 fputs ( "</database>\n" , md_result_file ) ;
 check_io ( md_result_file ) ;
 }
 if ( lock_tables ) ( void ) mysql_query_with_error_report ( mysql , 0 , "UNLOCK TABLES" ) ;
 return 0 ;
 }