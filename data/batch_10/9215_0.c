static const char * cmd_disable_backend_compression ( cmd_parms * cmd , void * _dcfg , int flag ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 if ( dcfg == NULL ) return NULL ;
 dcfg -> disable_backend_compression = flag ;
 return NULL ;
 }