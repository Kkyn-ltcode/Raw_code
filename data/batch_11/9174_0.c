static const char * cmd_audit_log_type ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = _dcfg ;
 if ( strcasecmp ( p1 , "Serial" ) == 0 ) dcfg -> auditlog_type = AUDITLOG_SERIAL ;
 else if ( strcasecmp ( p1 , "Concurrent" ) == 0 ) dcfg -> auditlog_type = AUDITLOG_CONCURRENT ;
 else return ( const char * ) apr_psprintf ( cmd -> pool , "ModSecurity: Unrecognised parameter value for SecAuditLogType: %s" , p1 ) ;
 return NULL ;
 }