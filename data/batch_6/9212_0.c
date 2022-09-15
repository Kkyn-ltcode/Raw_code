static const char * cmd_pcre_match_limit ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 long val ;
 if ( cmd -> server -> is_virtual ) {
 return "ModSecurity: SecPcreMatchLimit not allowed in VirtualHost" ;
 }
 val = atol ( p1 ) ;
 if ( val <= 0 ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid setting for " "SecPcreMatchLimit: %s" , p1 ) ;
 }
 msc_pcre_match_limit = ( unsigned long int ) val ;
 return NULL ;
 }