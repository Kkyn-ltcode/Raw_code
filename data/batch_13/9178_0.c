static const char * cmd_rule_remove_by_id ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 rule_exception * re = apr_pcalloc ( cmd -> pool , sizeof ( rule_exception ) ) ;
 if ( dcfg == NULL ) return NULL ;
 re -> type = RULE_EXCEPTION_REMOVE_ID ;
 re -> param = p1 ;
 * ( rule_exception * * ) apr_array_push ( dcfg -> rule_exceptions ) = re ;
 msre_ruleset_rule_remove_with_exception ( dcfg -> ruleset , re ) ;
 return NULL ;
 }