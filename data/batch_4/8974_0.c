void getauthkeys ( const char * keyfile ) {
 int len ;
 len = strlen ( keyfile ) ;
 if ( ! len ) return ;
 # ifndef SYS_WINNT key_file_name = erealloc ( key_file_name , len + 1 ) ;
 memcpy ( key_file_name , keyfile , len + 1 ) ;
 # else key_file_name = erealloc ( key_file_name , _MAX_PATH ) ;
 if ( len + 1 > _MAX_PATH ) return ;
 if ( ! ExpandEnvironmentStrings ( keyfile , key_file_name , _MAX_PATH ) ) {
 msyslog ( LOG_ERR , "ExpandEnvironmentStrings(KEY_FILE) failed: %m" ) ;
 strncpy ( key_file_name , keyfile , _MAX_PATH ) ;
 }
 # endif authreadkeys ( key_file_name ) ;
 }