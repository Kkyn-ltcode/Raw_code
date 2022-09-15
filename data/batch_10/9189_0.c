static const char * cmd_conn_read_state_limit ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 long int limit ;
 if ( dcfg == NULL ) return NULL ;
 limit = strtol ( p1 , NULL , 10 ) ;
 if ( ( limit == LONG_MAX ) || ( limit == LONG_MIN ) || ( limit <= 0 ) ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid value for SecReadStateLimit: %s" , p1 ) ;
 }
 conn_read_state_limit = limit ;
 return NULL ;
 }