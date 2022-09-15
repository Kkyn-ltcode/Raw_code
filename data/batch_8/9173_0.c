static const char * cmd_audit_engine ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = _dcfg ;
 if ( strcasecmp ( p1 , "On" ) == 0 ) dcfg -> auditlog_flag = AUDITLOG_ON ;
 else if ( strcasecmp ( p1 , "Off" ) == 0 ) dcfg -> auditlog_flag = AUDITLOG_OFF ;
 else if ( strcasecmp ( p1 , "RelevantOnly" ) == 0 ) dcfg -> auditlog_flag = AUDITLOG_RELEVANT ;
 else return ( const char * ) apr_psprintf ( cmd -> pool , "ModSecurity: Unrecognised parameter value for SecAuditEngine: %s" , p1 ) ;
 return NULL ;
 }