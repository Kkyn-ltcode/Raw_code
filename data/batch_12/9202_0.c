static const char * cmd_debug_log ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 apr_status_t rc ;
 dcfg -> debuglog_name = ap_server_root_relative ( cmd -> pool , p1 ) ;
 rc = apr_file_open ( & dcfg -> debuglog_fd , dcfg -> debuglog_name , APR_WRITE | APR_APPEND | APR_CREATE | APR_BINARY , CREATEMODE , cmd -> pool ) ;
 if ( rc != APR_SUCCESS ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Failed to open debug log file: %s" , dcfg -> debuglog_name ) ;
 }
 return NULL ;
 }