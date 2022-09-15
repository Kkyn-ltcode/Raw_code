static const char * cmd_request_body_inmemory_limit ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 long int limit ;
 if ( dcfg == NULL ) return NULL ;
 limit = strtol ( p1 , NULL , 10 ) ;
 if ( ( limit == LONG_MAX ) || ( limit == LONG_MIN ) || ( limit <= 0 ) ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid value for SecRequestBodyInMemoryLimit: %s" , p1 ) ;
 }
 dcfg -> reqbody_inmemory_limit = limit ;
 return NULL ;
 }