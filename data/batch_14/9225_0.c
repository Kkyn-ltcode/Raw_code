static const char * cmd_audit_log_storage_dir ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = _dcfg ;
 dcfg -> auditlog_storage_dir = ap_server_root_relative ( cmd -> pool , p1 ) ;
 return NULL ;
 }