static const char * cmd_rule_remove_by_tag ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 rule_exception * re = apr_pcalloc ( cmd -> pool , sizeof ( rule_exception ) ) ;
 if ( dcfg == NULL ) return NULL ;
 re -> type = RULE_EXCEPTION_REMOVE_TAG ;
 re -> param = p1 ;
 re -> param_data = msc_pregcomp ( cmd -> pool , p1 , 0 , NULL , NULL ) ;
 if ( re -> param_data == NULL ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid regular expression: %s" , p1 ) ;
 }
 * ( rule_exception * * ) apr_array_push ( dcfg -> rule_exceptions ) = re ;
 msre_ruleset_rule_remove_with_exception ( dcfg -> ruleset , re ) ;
 # ifdef DEBUG_CONF ap_log_perror ( APLOG_MARK , APLOG_STARTUP | APLOG_NOERRNO , 0 , cmd -> pool , "Added exception %pp (%d %s) to dcfg %pp." , re , re -> type , re -> param , dcfg ) ;
 # endif return NULL ;
 }