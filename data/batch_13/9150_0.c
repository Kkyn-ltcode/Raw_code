static const char * cmd_response_body_mime_type ( cmd_parms * cmd , void * _dcfg , const char * _p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 char * p1 = apr_pstrdup ( cmd -> pool , _p1 ) ;
 if ( ( dcfg -> of_mime_types == NULL ) || ( dcfg -> of_mime_types == NOT_SET_P ) ) {
 dcfg -> of_mime_types = apr_table_make ( cmd -> pool , 10 ) ;
 }
 strtolower_inplace ( ( unsigned char * ) p1 ) ;
 apr_table_setn ( dcfg -> of_mime_types , p1 , "1" ) ;
 return NULL ;
 }