static const char * cmd_rule_update_action_by_id ( cmd_parms * cmd , void * _dcfg , const char * p1 , const char * p2 ) {
 int offset = 0 , rule_id = atoi ( p1 ) ;
 char * opt = strchr ( p1 , ':' ) ;
 char * savedptr = NULL ;
 char * param = apr_pstrdup ( cmd -> pool , p1 ) ;
 if ( ( rule_id == LONG_MAX ) || ( rule_id == LONG_MIN ) || ( rule_id <= 0 ) ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid value for ID for update action: %s" , p1 ) ;
 }
 if ( opt != NULL ) {
 opt ++ ;
 offset = atoi ( opt ) ;
 opt = apr_strtok ( param , ":" , & savedptr ) ;
 return update_rule_action ( cmd , ( directory_config * ) _dcfg , ( const char * ) opt , p2 , offset ) ;
 }
 return update_rule_action ( cmd , ( directory_config * ) _dcfg , p1 , p2 , offset ) ;
 }