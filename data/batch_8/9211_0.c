static const char * cmd_tmp_dir ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 if ( dcfg == NULL ) return NULL ;
 if ( strcasecmp ( p1 , "none" ) == 0 ) dcfg -> tmp_dir = NULL ;
 else dcfg -> tmp_dir = ap_server_root_relative ( cmd -> pool , p1 ) ;
 return NULL ;
 }