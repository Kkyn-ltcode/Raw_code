static const char * cmd_response_body_limit ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 long int limit ;
 limit = strtol ( p1 , NULL , 10 ) ;
 if ( ( limit == LONG_MAX ) || ( limit == LONG_MIN ) || ( limit <= 0 ) ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid value for SecResponseBodyLimit: %s" , p1 ) ;
 }
 if ( limit > RESPONSE_BODY_HARD_LIMIT ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Response size limit can not exceed the hard limit: %li" , RESPONSE_BODY_HARD_LIMIT ) ;
 }
 dcfg -> of_limit = limit ;
 return NULL ;
 }