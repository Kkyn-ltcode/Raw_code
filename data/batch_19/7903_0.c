static int dump_selected_tables ( char * db , char * * table_names , int tables ) {
 char table_buff [ NAME_LEN * 2 + 3 ] ;
 DYNAMIC_STRING lock_tables_query ;
 MEM_ROOT root ;
 char * * dump_tables , * * pos , * * end ;
 DBUG_ENTER ( "dump_selected_tables" ) ;
 if ( init_dumping ( db , init_dumping_tables ) ) DBUG_RETURN ( 1 ) ;
 init_alloc_root ( & root , 8192 , 0 ) ;
 if ( ! ( dump_tables = pos = ( char * * ) alloc_root ( & root , tables * sizeof ( char * ) ) ) ) die ( EX_EOM , "alloc_root failure." ) ;
 init_dynamic_string_checked ( & lock_tables_query , "LOCK TABLES " , 256 , 1024 ) ;
 for ( ;
 tables > 0 ;
 tables -- , table_names ++ ) {
 if ( ( * pos = get_actual_table_name ( * table_names , & root ) ) ) {
 if ( lock_tables ) {
 dynstr_append_checked ( & lock_tables_query , quote_name ( * pos , table_buff , 1 ) ) ;
 dynstr_append_checked ( & lock_tables_query , " READ /*!32311 LOCAL */," ) ;
 }
 pos ++ ;
 }
 else {
 if ( ! ignore_errors ) {
 dynstr_free ( & lock_tables_query ) ;
 free_root ( & root , MYF ( 0 ) ) ;
 }
 maybe_die ( EX_ILLEGAL_TABLE , "Couldn't find table: \"%s\"" , * table_names ) ;
 }
 }
 end = pos ;
 if ( lock_tables && ! ( mysql_get_server_version ( mysql ) >= FIRST_INFORMATION_SCHEMA_VERSION && ! my_strcasecmp ( & my_charset_latin1 , db , INFORMATION_SCHEMA_DB_NAME ) ) && ! ( mysql_get_server_version ( mysql ) >= FIRST_PERFORMANCE_SCHEMA_VERSION && ! my_strcasecmp ( & my_charset_latin1 , db , PERFORMANCE_SCHEMA_DB_NAME ) ) ) {
 if ( mysql_real_query ( mysql , lock_tables_query . str , lock_tables_query . length - 1 ) ) {
 if ( ! ignore_errors ) {
 dynstr_free ( & lock_tables_query ) ;
 free_root ( & root , MYF ( 0 ) ) ;
 }
 DB_error ( mysql , "when doing LOCK TABLES" ) ;
 }
 }
 dynstr_free ( & lock_tables_query ) ;
 if ( flush_logs ) {
 if ( mysql_refresh ( mysql , REFRESH_LOG ) ) {
 if ( ! ignore_errors ) free_root ( & root , MYF ( 0 ) ) ;
 DB_error ( mysql , "when doing refresh" ) ;
 }
 else verbose_msg ( "-- dump_selected_tables : logs flushed successfully!\n" ) ;
 }
 if ( opt_xml ) print_xml_tag ( md_result_file , "" , "\n" , "database" , "name=" , db , NullS ) ;
 for ( pos = dump_tables ;
 pos < end ;
 pos ++ ) {
 DBUG_PRINT ( "info" , ( "Dumping table %s" , * pos ) ) ;
 dump_table ( * pos , db ) ;
 if ( opt_dump_triggers && mysql_get_server_version ( mysql ) >= 50009 ) {
 if ( dump_triggers_for_table ( * pos , db ) ) {
 if ( path ) my_fclose ( md_result_file , MYF ( MY_WME ) ) ;
 maybe_exit ( EX_MYSQLERR ) ;
 }
 }
 }
 if ( seen_views ) {
 for ( pos = dump_tables ;
 pos < end ;
 pos ++ ) get_view_structure ( * pos , db ) ;
 }
 if ( opt_events && mysql_get_server_version ( mysql ) >= 50106 ) {
 DBUG_PRINT ( "info" , ( "Dumping events for database %s" , db ) ) ;
 dump_events_for_db ( db ) ;
 }
 if ( opt_routines && mysql_get_server_version ( mysql ) >= 50009 ) {
 DBUG_PRINT ( "info" , ( "Dumping routines for database %s" , db ) ) ;
 dump_routines_for_db ( db ) ;
 }
 free_root ( & root , MYF ( 0 ) ) ;
 my_free ( order_by ) ;
 order_by = 0 ;
 if ( opt_xml ) {
 fputs ( "</database>\n" , md_result_file ) ;
 check_io ( md_result_file ) ;
 }
 if ( lock_tables ) ( void ) mysql_query_with_error_report ( mysql , 0 , "UNLOCK TABLES" ) ;
 DBUG_RETURN ( 0 ) ;
 }