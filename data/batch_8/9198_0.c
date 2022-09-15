static const char * add_marker ( cmd_parms * cmd , directory_config * dcfg , const char * p1 , const char * p2 , const char * p3 ) {
 char * my_error_msg = NULL ;
 msre_rule * rule = NULL ;
 extern msc_engine * modsecurity ;
 int p ;
 # ifdef DEBUG_CONF ap_log_perror ( APLOG_MARK , APLOG_STARTUP | APLOG_NOERRNO , 0 , cmd -> pool , "Rule: type=%d p1='%s' p2='%s' p3='%s'" , RULE_TYPE_MARKER , p1 , p2 , p3 ) ;
 # endif if ( ( dcfg -> ruleset == NULL ) || ( dcfg -> ruleset == NOT_SET_P ) ) {
 dcfg -> ruleset = msre_ruleset_create ( modsecurity -> msre , cmd -> pool ) ;
 if ( dcfg -> ruleset == NULL ) return FATAL_ERROR ;
 }
 rule = msre_rule_create ( dcfg -> ruleset , RULE_TYPE_MARKER , cmd -> directive -> filename , cmd -> directive -> line_num , p1 , p2 , p3 , & my_error_msg ) ;
 if ( rule == NULL ) {
 return my_error_msg ;
 }
 rule -> placeholder = RULE_PH_MARKER ;
 for ( p = PHASE_FIRST ;
 p <= PHASE_LAST ;
 p ++ ) {
 # ifdef DEBUG_CONF ap_log_perror ( APLOG_MARK , APLOG_STARTUP | APLOG_NOERRNO , 0 , cmd -> pool , "Adding marker %pp phase=%d id=\"%s\"." , rule , p , ( rule -> actionset -> id == NOT_SET_P ? "(none)" : rule -> actionset -> id ) ) ;
 # endif if ( msre_ruleset_rule_add ( dcfg -> ruleset , rule , p ) < 0 ) {
 return "Internal Error: Failed to add marker to the ruleset." ;
 }
 }
 if ( dcfg -> tmp_rule_placeholders != NULL ) {
 apr_table_unset ( dcfg -> tmp_rule_placeholders , rule -> actionset -> id ) ;
 }
 return NULL ;
 }