static const char * cmd_upload_keep_files ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 if ( dcfg == NULL ) return NULL ;
 if ( strcasecmp ( p1 , "on" ) == 0 ) {
 dcfg -> upload_keep_files = KEEP_FILES_ON ;
 }
 else if ( strcasecmp ( p1 , "off" ) == 0 ) {
 dcfg -> upload_keep_files = KEEP_FILES_OFF ;
 }
 else if ( strcasecmp ( p1 , "relevantonly" ) == 0 ) {
 dcfg -> upload_keep_files = KEEP_FILES_RELEVANT_ONLY ;
 }
 else {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid setting for SecUploadKeepFiles: %s" , p1 ) ;
 }
 return NULL ;
 }