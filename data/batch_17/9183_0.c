static const char * cmd_audit_log2 ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = _dcfg ;
 if ( dcfg -> auditlog_name == NOT_SET_P ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Cannot configure a secondary audit log without a primary defined: %s" , p1 ) ;
 }
 dcfg -> auditlog2_name = ( char * ) p1 ;
 if ( dcfg -> auditlog2_name [ 0 ] == '|' ) {
 const char * pipe_name = ap_server_root_relative ( cmd -> pool , dcfg -> auditlog2_name + 1 ) ;
 piped_log * pipe_log ;
 pipe_log = ap_open_piped_log ( cmd -> pool , pipe_name ) ;
 if ( pipe_log == NULL ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Failed to open the secondary audit log pipe: %s" , pipe_name ) ;
 }
 dcfg -> auditlog2_fd = ap_piped_log_write_fd ( pipe_log ) ;
 }
 else {
 const char * file_name = ap_server_root_relative ( cmd -> pool , dcfg -> auditlog2_name ) ;
 apr_status_t rc ;
 rc = apr_file_open ( & dcfg -> auditlog2_fd , file_name , APR_WRITE | APR_APPEND | APR_CREATE | APR_BINARY , CREATEMODE , cmd -> pool ) ;
 if ( rc != APR_SUCCESS ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Failed to open the secondary audit log file: %s" , file_name ) ;
 }
 }
 return NULL ;
 }