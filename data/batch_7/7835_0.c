static int dump_all_tables_in_db ( char * database ) {
 char * table ;
 uint numrows ;
 char table_buff [ NAME_LEN * 2 + 3 ] ;
 char hash_key [ 2 * NAME_LEN + 2 ] ;
 char * afterdot ;
 my_bool general_log_table_exists = 0 , slow_log_table_exists = 0 ;
 int using_mysql_db = ! my_strcasecmp ( charset_info , database , "mysql" ) ;
 DBUG_ENTER ( "dump_all_tables_in_db" ) ;
 afterdot = strmov ( hash_key , database ) ;
 * afterdot ++ = '.' ;
 if ( init_dumping ( database , init_dumping_tables ) ) DBUG_RETURN ( 1 ) ;
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
 else verbose_msg ( "-- dump_all_tables_in_db : logs flushed successfully!\n" ) ;
 }
 while ( ( table = getTableName ( 0 ) ) ) {
 char * end = strmov ( afterdot , table ) ;
 if ( include_table ( ( uchar * ) hash_key , end - hash_key ) ) {
 dump_table ( table , database ) ;
 my_free ( order_by ) ;
 order_by = 0 ;
 if ( opt_dump_triggers && mysql_get_server_version ( mysql ) >= 50009 ) {
 if ( dump_triggers_for_table ( table , database ) ) {
 if ( path ) my_fclose ( md_result_file , MYF ( MY_WME ) ) ;
 maybe_exit ( EX_MYSQLERR ) ;
 }
 }
 }
 else {
 if ( using_mysql_db ) {
 if ( ! my_strcasecmp ( charset_info , table , "general_log" ) ) general_log_table_exists = 1 ;
 else if ( ! my_strcasecmp ( charset_info , table , "slow_log" ) ) slow_log_table_exists = 1 ;
 }
 }
 }
 if ( opt_events && mysql_get_server_version ( mysql ) >= 50106 ) {
 DBUG_PRINT ( "info" , ( "Dumping events for database %s" , database ) ) ;
 dump_events_for_db ( database ) ;
 }
 if ( opt_routines && mysql_get_server_version ( mysql ) >= 50009 ) {
 DBUG_PRINT ( "info" , ( "Dumping routines for database %s" , database ) ) ;
 dump_routines_for_db ( database ) ;
 }
 if ( opt_xml ) {
 fputs ( "</database>\n" , md_result_file ) ;
 check_io ( md_result_file ) ;
 }
 if ( lock_tables ) ( void ) mysql_query_with_error_report ( mysql , 0 , "UNLOCK TABLES" ) ;
 if ( using_mysql_db ) {
 char table_type [ NAME_LEN ] ;
 char ignore_flag ;
 if ( general_log_table_exists ) {
 if ( ! get_table_structure ( ( char * ) "general_log" , database , table_type , & ignore_flag ) ) verbose_msg ( "-- Warning: get_table_structure() failed with some internal " "error for 'general_log' table\n" ) ;
 }
 if ( slow_log_table_exists ) {
 if ( ! get_table_structure ( ( char * ) "slow_log" , database , table_type , & ignore_flag ) ) verbose_msg ( "-- Warning: get_table_structure() failed with some internal " "error for 'slow_log' table\n" ) ;
 }
 }
 if ( flush_privileges && using_mysql_db ) {
 fprintf ( md_result_file , "\n--\n-- Flush Grant Tables \n--\n" ) ;
 fprintf ( md_result_file , "\n/*! FLUSH PRIVILEGES */;
\n" ) ;
 }
 DBUG_RETURN ( 0 ) ;
 }