static const char * cmd_component_signature ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 * ( char * * ) apr_array_push ( dcfg -> component_signatures ) = ( char * ) p1 ;
 return NULL ;
 }