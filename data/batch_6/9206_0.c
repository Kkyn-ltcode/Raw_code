static const char * cmd_cookie_format ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 if ( strcmp ( p1 , "0" ) == 0 ) dcfg -> cookie_format = COOKIES_V0 ;
 else if ( strcmp ( p1 , "1" ) == 0 ) dcfg -> cookie_format = COOKIES_V1 ;
 else {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid cookie format: %s" , p1 ) ;
 }
 return NULL ;
 }