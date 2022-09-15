static int dump_triggers_for_table ( char * table_name , char * db_name ) {
 char name_buff [ NAME_LEN * 4 + 3 ] ;
 char query_buff [ QUERY_LENGTH ] ;
 uint old_opt_compatible_mode = opt_compatible_mode ;
 MYSQL_RES * show_triggers_rs ;
 MYSQL_ROW row ;
 FILE * sql_file = md_result_file ;
 char db_cl_name [ MY_CS_NAME_SIZE ] ;
 int ret = TRUE ;
 DBUG_ENTER ( "dump_triggers_for_table" ) ;
 DBUG_PRINT ( "enter" , ( "db: %s, table_name: %s" , db_name , table_name ) ) ;
 if ( path && ! ( sql_file = open_sql_file_for_table ( table_name , O_WRONLY | O_APPEND ) ) ) DBUG_RETURN ( 1 ) ;
 opt_compatible_mode &= ~ MASK_ANSI_QUOTES ;
 if ( switch_character_set_results ( mysql , "binary" ) ) goto done ;
 if ( fetch_db_collation ( db_name , db_cl_name , sizeof ( db_cl_name ) ) ) goto done ;
 my_snprintf ( query_buff , sizeof ( query_buff ) , "SHOW TRIGGERS LIKE %s" , quote_for_like ( table_name , name_buff ) ) ;
 if ( mysql_query_with_error_report ( mysql , & show_triggers_rs , query_buff ) ) goto done ;
 if ( ! mysql_num_rows ( show_triggers_rs ) ) goto skip ;
 if ( opt_xml ) print_xml_tag ( sql_file , "\t" , "\n" , "triggers" , "name=" , table_name , NullS ) ;
 while ( ( row = mysql_fetch_row ( show_triggers_rs ) ) ) {
 my_snprintf ( query_buff , sizeof ( query_buff ) , "SHOW CREATE TRIGGER %s" , quote_name ( row [ 0 ] , name_buff , TRUE ) ) ;
 if ( mysql_query ( mysql , query_buff ) ) {
 dump_trigger_old ( sql_file , show_triggers_rs , & row , table_name ) ;
 }
 else {
 MYSQL_RES * show_create_trigger_rs = mysql_store_result ( mysql ) ;
 if ( ! show_create_trigger_rs || dump_trigger ( sql_file , show_create_trigger_rs , db_name , db_cl_name ) ) goto done ;
 mysql_free_result ( show_create_trigger_rs ) ;
 }
 }
 if ( opt_xml ) {
 fputs ( "\t</triggers>\n" , sql_file ) ;
 check_io ( sql_file ) ;
 }
 skip : mysql_free_result ( show_triggers_rs ) ;
 if ( switch_character_set_results ( mysql , default_charset ) ) goto done ;
 opt_compatible_mode = old_opt_compatible_mode ;
 ret = FALSE ;
 done : if ( path ) my_fclose ( sql_file , MYF ( 0 ) ) ;
 DBUG_RETURN ( ret ) ;
 }