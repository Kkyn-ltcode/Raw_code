static const char * cmd_upload_filemode ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 if ( dcfg == NULL ) return NULL ;
 if ( strcasecmp ( p1 , "default" ) == 0 ) {
 dcfg -> upload_filemode = NOT_SET ;
 }
 else {
 long int mode = strtol ( p1 , NULL , 8 ) ;
 if ( ( mode == LONG_MAX ) || ( mode == LONG_MIN ) || ( mode <= 0 ) || ( mode > 07777 ) ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid value for SecUploadFileMode: %s" , p1 ) ;
 }
 dcfg -> upload_filemode = ( int ) mode ;
 }
 return NULL ;
 }