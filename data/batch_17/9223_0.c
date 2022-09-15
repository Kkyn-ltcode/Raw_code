static const char * cmd_marker ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 const char * action = apr_pstrcat ( dcfg -> mp , SECMARKER_BASE_ACTIONS , p1 , NULL ) ;
 return add_marker ( cmd , ( directory_config * ) _dcfg , SECMARKER_TARGETS , SECMARKER_ARGS , action ) ;
 }