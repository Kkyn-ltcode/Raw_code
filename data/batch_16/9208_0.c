static const char * cmd_response_body_mime_types_clear ( cmd_parms * cmd , void * _dcfg ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 if ( dcfg == NULL ) return NULL ;
 dcfg -> of_mime_types_cleared = 1 ;
 if ( ( dcfg -> of_mime_types != NULL ) && ( dcfg -> of_mime_types != NOT_SET_P ) ) {
 apr_table_clear ( dcfg -> of_mime_types ) ;
 }
 return NULL ;
 }