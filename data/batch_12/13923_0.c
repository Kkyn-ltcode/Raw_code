void my_message_sql ( uint error , const char * str , myf MyFlags ) {
 THD * thd = current_thd ;
 MYSQL_ERROR : : enum_warning_level level ;
 sql_print_message_func func ;
 DBUG_ENTER ( "my_message_sql" ) ;
 DBUG_PRINT ( "error" , ( "error: %u message: '%s' Flag: %d" , error , str , MyFlags ) ) ;
 DBUG_ASSERT ( str != NULL ) ;
 DBUG_ASSERT ( error != 0 ) ;
 if ( MyFlags & ME_JUST_INFO ) {
 level = MYSQL_ERROR : : WARN_LEVEL_NOTE ;
 func = sql_print_information ;
 }
 else if ( MyFlags & ME_JUST_WARNING ) {
 level = MYSQL_ERROR : : WARN_LEVEL_WARN ;
 func = sql_print_warning ;
 }
 else {
 level = MYSQL_ERROR : : WARN_LEVEL_ERROR ;
 func = sql_print_error ;
 }
 if ( thd ) {
 if ( MyFlags & ME_FATALERROR ) thd -> is_fatal_error = 1 ;
 ( void ) thd -> raise_condition ( error , NULL , level , str ) ;
 }
 else mysql_audit_general ( 0 , MYSQL_AUDIT_GENERAL_ERROR , error , str ) ;
 DBUG_EXECUTE_IF ( "simulate_out_of_memory" , DBUG_VOID_RETURN ;
 ) ;
 if ( ! thd || thd -> log_all_errors || ( MyFlags & ME_NOREFRESH ) ) ( * func ) ( "%s: %s" , my_progname_short , str ) ;
 DBUG_VOID_RETURN ;
 }