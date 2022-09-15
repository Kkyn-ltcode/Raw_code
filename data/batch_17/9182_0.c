static const char * cmd_hash_method_pm ( cmd_parms * cmd , void * _dcfg , const char * p1 , const char * p2 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 rule_exception * re = apr_pcalloc ( cmd -> pool , sizeof ( hash_method ) ) ;
 const char * _p2 = apr_pstrdup ( cmd -> pool , p2 ) ;
 ACMP * p = NULL ;
 const char * phrase = NULL ;
 const char * next = NULL ;
 if ( dcfg == NULL ) return NULL ;
 p = acmp_create ( 0 , cmd -> pool ) ;
 if ( p == NULL ) return NULL ;
 if ( phrase == NULL ) phrase = apr_pstrdup ( cmd -> pool , _p2 ) ;
 for ( ;
 ;
 ) {
 while ( ( apr_isspace ( * phrase ) != 0 ) && ( * phrase != '\0' ) ) phrase ++ ;
 if ( * phrase == '\0' ) break ;
 next = phrase ;
 while ( ( apr_isspace ( * next ) == 0 ) && ( * next != 0 ) ) next ++ ;
 acmp_add_pattern ( p , phrase , NULL , NULL , next - phrase ) ;
 phrase = next ;
 }
 acmp_prepare ( p ) ;
 if ( strcasecmp ( p1 , "HashHref" ) == 0 ) {
 re -> type = HASH_URL_HREF_HASH_PM ;
 re -> param = _p2 ;
 re -> param_data = ( void * ) p ;
 if ( re -> param_data == NULL ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid pattern: %s" , p2 ) ;
 }
 dcfg -> crypto_hash_href_pm = 1 ;
 }
 else if ( strcasecmp ( p1 , "HashFormAction" ) == 0 ) {
 re -> type = HASH_URL_FACTION_HASH_PM ;
 re -> param = _p2 ;
 re -> param_data = ( void * ) p ;
 if ( re -> param_data == NULL ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid pattern: %s" , p2 ) ;
 }
 dcfg -> crypto_hash_faction_pm = 1 ;
 }
 else if ( strcasecmp ( p1 , "HashLocation" ) == 0 ) {
 re -> type = HASH_URL_LOCATION_HASH_PM ;
 re -> param = _p2 ;
 re -> param_data = ( void * ) p ;
 if ( re -> param_data == NULL ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid pattern: %s" , p2 ) ;
 }
 dcfg -> crypto_hash_location_pm = 1 ;
 }
 else if ( strcasecmp ( p1 , "HashIframeSrc" ) == 0 ) {
 re -> type = HASH_URL_IFRAMESRC_HASH_PM ;
 re -> param = _p2 ;
 re -> param_data = ( void * ) p ;
 if ( re -> param_data == NULL ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid pattern: %s" , p2 ) ;
 }
 dcfg -> crypto_hash_iframesrc_pm = 1 ;
 }
 else if ( strcasecmp ( p1 , "HashFrameSrc" ) == 0 ) {
 re -> type = HASH_URL_FRAMESRC_HASH_PM ;
 re -> param = _p2 ;
 re -> param_data = ( void * ) p ;
 if ( re -> param_data == NULL ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid pattern: %s" , p2 ) ;
 }
 dcfg -> crypto_hash_framesrc_pm = 1 ;
 }
 * ( hash_method * * ) apr_array_push ( dcfg -> hash_method ) = re ;
 return NULL ;
 }