static const char * cmd_httpBl_key ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 if ( dcfg == NULL ) return NULL ;
 if ( p1 == NULL ) return NULL ;
 dcfg -> httpBlkey = p1 ;
 return NULL ;
 }