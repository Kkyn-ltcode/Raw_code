static const char * cmd_stream_outbody_inspection ( cmd_parms * cmd , void * _dcfg , int flag ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 if ( dcfg == NULL ) return NULL ;
 dcfg -> stream_outbody_inspection = flag ;
 return NULL ;
 }