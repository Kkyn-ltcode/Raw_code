static const char * cmd_hash_method_rx ( cmd_parms * cmd , void * _dcfg , const char * p1 , const char * p2 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 rule_exception * re = apr_pcalloc ( cmd -> pool , sizeof ( hash_method ) ) ;
 const char * _p2 = apr_pstrdup ( cmd -> pool , p2 ) ;
 if ( dcfg == NULL ) return NULL ;
 if ( strcasecmp ( p1 , "HashHref" ) == 0 ) {
 re -> type = HASH_URL_HREF_HASH_RX ;
 re -> param = _p2 ;
 re -> param_data = msc_pregcomp ( cmd -> pool , p2 , 0 , NULL , NULL ) ;
 if ( re -> param_data == NULL ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid regular expression: %s" , p2 ) ;
 }
 dcfg -> crypto_hash_href_rx = 1 ;
 }
 else if ( strcasecmp ( p1 , "HashFormAction" ) == 0 ) {
 re -> type = HASH_URL_FACTION_HASH_RX ;
 re -> param = _p2 ;
 re -> param_data = msc_pregcomp ( cmd -> pool , p2 , 0 , NULL , NULL ) ;
 if ( re -> param_data == NULL ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid regular expression: %s" , p2 ) ;
 }
 dcfg -> crypto_hash_faction_rx = 1 ;
 }
 else if ( strcasecmp ( p1 , "HashLocation" ) == 0 ) {
 re -> type = HASH_URL_LOCATION_HASH_RX ;
 re -> param = _p2 ;
 re -> param_data = msc_pregcomp ( cmd -> pool , p2 , 0 , NULL , NULL ) ;
 if ( re -> param_data == NULL ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid regular expression: %s" , p2 ) ;
 }
 dcfg -> crypto_hash_location_rx = 1 ;
 }
 else if ( strcasecmp ( p1 , "HashIframeSrc" ) == 0 ) {
 re -> type = HASH_URL_IFRAMESRC_HASH_RX ;
 re -> param = _p2 ;
 re -> param_data = msc_pregcomp ( cmd -> pool , p2 , 0 , NULL , NULL ) ;
 if ( re -> param_data == NULL ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid regular expression: %s" , p2 ) ;
 }
 dcfg -> crypto_hash_iframesrc_rx = 1 ;
 }
 else if ( strcasecmp ( p1 , "HashFrameSrc" ) == 0 ) {
 re -> type = HASH_URL_FRAMESRC_HASH_RX ;
 re -> param = _p2 ;
 re -> param_data = msc_pregcomp ( cmd -> pool , p2 , 0 , NULL , NULL ) ;
 if ( re -> param_data == NULL ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid regular expression: %s" , p2 ) ;
 }
 dcfg -> crypto_hash_framesrc_rx = 1 ;
 }
 * ( hash_method * * ) apr_array_push ( dcfg -> hash_method ) = re ;
 return NULL ;
 }