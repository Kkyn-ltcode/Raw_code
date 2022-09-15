static const char * cmd_audit_log_relevant_status ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = _dcfg ;
 dcfg -> auditlog_relevant_regex = msc_pregcomp ( cmd -> pool , p1 , PCRE_DOTALL , NULL , NULL ) ;
 if ( dcfg -> auditlog_relevant_regex == NULL ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid regular expression: %s" , p1 ) ;
 }
 return NULL ;
 }