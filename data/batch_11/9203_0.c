static const char * cmd_rule_update_target_by_id ( cmd_parms * cmd , void * _dcfg , const char * p1 , const char * p2 , const char * p3 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 rule_exception * re = apr_pcalloc ( cmd -> pool , sizeof ( rule_exception ) ) ;
 if ( dcfg == NULL ) return NULL ;
 if ( p1 == NULL ) {
 return apr_psprintf ( cmd -> pool , "Updating target by ID with no ID" ) ;
 }
 re -> type = RULE_EXCEPTION_REMOVE_ID ;
 re -> param = p1 ;
 return msre_ruleset_rule_update_target_matching_exception ( NULL , dcfg -> ruleset , re , p2 , p3 ) ;
 }