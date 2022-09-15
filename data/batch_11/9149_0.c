static const char * cmd_rule_update_target_by_tag ( cmd_parms * cmd , void * _dcfg , const char * p1 , const char * p2 , const char * p3 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 rule_exception * re = apr_pcalloc ( cmd -> pool , sizeof ( rule_exception ) ) ;
 if ( dcfg == NULL ) return NULL ;
 if ( p1 == NULL ) {
 return apr_psprintf ( cmd -> pool , "Updating target by tag with no tag" ) ;
 }
 re -> type = RULE_EXCEPTION_REMOVE_TAG ;
 re -> param = p1 ;
 re -> param_data = msc_pregcomp ( cmd -> pool , p1 , 0 , NULL , NULL ) ;
 if ( re -> param_data == NULL ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid regular expression: %s" , p1 ) ;
 }
 return msre_ruleset_rule_update_target_matching_exception ( NULL , dcfg -> ruleset , re , p2 , p3 ) ;
 }