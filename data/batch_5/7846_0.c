static int purge_bin_logs_to ( MYSQL * mysql_con , char * log_name ) {
 DYNAMIC_STRING str ;
 int err ;
 init_dynamic_string_checked ( & str , "PURGE BINARY LOGS TO '" , 1024 , 1024 ) ;
 dynstr_append_checked ( & str , log_name ) ;
 dynstr_append_checked ( & str , "'" ) ;
 err = mysql_query_with_error_report ( mysql_con , 0 , str . str ) ;
 dynstr_free ( & str ) ;
 return err ;
 }