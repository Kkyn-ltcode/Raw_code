static const char * cmd_audit_log_parts ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = _dcfg ;
 if ( is_valid_parts_specification ( ( char * ) p1 ) != 1 ) {
 return apr_psprintf ( cmd -> pool , "Invalid parts specification for SecAuditLogParts: %s" , p1 ) ;
 }
 dcfg -> auditlog_parts = ( char * ) p1 ;
 return NULL ;
 }