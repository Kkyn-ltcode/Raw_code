static const char * cmd_debug_log_level ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 dcfg -> debuglog_level = atoi ( p1 ) ;
 if ( ( dcfg -> debuglog_level >= 0 ) && ( dcfg -> debuglog_level <= 9 ) ) return NULL ;
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid value for SecDebugLogLevel: %s" , p1 ) ;
 }