static const char * cmd_rule_script ( cmd_parms * cmd , void * _dcfg , const char * p1 , const char * p2 ) {
 # if defined ( WITH_LUA ) const char * filename = resolve_relative_path ( cmd -> pool , cmd -> directive -> filename , p1 ) ;
 return add_rule ( cmd , ( directory_config * ) _dcfg , RULE_TYPE_LUA , filename , p2 , NULL ) ;
 # else ap_log_perror ( APLOG_MARK , APLOG_STARTUP | APLOG_NOERRNO , 0 , cmd -> pool , "Ignoring SecRuleScript \"%s\" directive (%s:%d): No Lua scripting support." , p1 , cmd -> directive -> filename , cmd -> directive -> line_num ) ;
 return NULL ;
 # endif }