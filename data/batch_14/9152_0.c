static const char * cmd_hash_param ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 if ( dcfg == NULL ) return NULL ;
 if ( p1 == NULL ) return NULL ;
 dcfg -> crypto_param_name = p1 ;
 return NULL ;
 }