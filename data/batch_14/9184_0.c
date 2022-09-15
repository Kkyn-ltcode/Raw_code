static const char * cmd_cache_transformations ( cmd_parms * cmd , void * _dcfg , const char * p1 , const char * p2 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 if ( dcfg == NULL ) return NULL ;
 if ( strcasecmp ( p1 , "on" ) == 0 ) dcfg -> cache_trans = MODSEC_CACHE_ENABLED ;
 else if ( strcasecmp ( p1 , "off" ) == 0 ) dcfg -> cache_trans = MODSEC_CACHE_DISABLED ;
 else return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid value for SecCacheTransformations: %s" , p1 ) ;
 if ( p2 != NULL ) {
 apr_table_t * vartable = apr_table_make ( cmd -> pool , 4 ) ;
 apr_status_t rc ;
 char * error_msg = NULL ;
 const char * charval = NULL ;
 apr_int64_t intval = 0 ;
 if ( vartable == NULL ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Unable to process options for SecCacheTransformations" ) ;
 }
 rc = msre_parse_generic ( cmd -> pool , p2 , vartable , & error_msg ) ;
 if ( rc < 0 ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Unable to parse options for SecCacheTransformations: %s" , error_msg ) ;
 }
 charval = apr_table_get ( vartable , "incremental" ) ;
 if ( charval != NULL ) {
 if ( strcasecmp ( charval , "on" ) == 0 ) dcfg -> cache_trans_incremental = 1 ;
 else if ( strcasecmp ( charval , "off" ) == 0 ) dcfg -> cache_trans_incremental = 0 ;
 else return apr_psprintf ( cmd -> pool , "ModSecurity: SecCacheTransformations invalid incremental value: %s" , charval ) ;
 }
 charval = apr_table_get ( vartable , "minlen" ) ;
 if ( charval != NULL ) {
 intval = apr_atoi64 ( charval ) ;
 if ( errno == ERANGE ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: SecCacheTransformations minlen out of range: %s" , charval ) ;
 }
 if ( intval < 0 ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: SecCacheTransformations minlen must be positive: %s" , charval ) ;
 }
 if ( ( unsigned long ) intval >= ( unsigned long ) NOT_SET ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: SecCacheTransformations minlen must be less than: %lu" , ( unsigned long ) NOT_SET ) ;
 }
 dcfg -> cache_trans_min = ( apr_size_t ) intval ;
 }
 charval = apr_table_get ( vartable , "maxlen" ) ;
 if ( charval != NULL ) {
 intval = apr_atoi64 ( charval ) ;
 if ( errno == ERANGE ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: SecCacheTransformations maxlen out of range: %s" , charval ) ;
 }
 if ( intval < 0 ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: SecCacheTransformations maxlen must be positive: %s" , charval ) ;
 }
 if ( ( unsigned long ) intval >= ( unsigned long ) NOT_SET ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: SecCacheTransformations maxlen must be less than: %lu" , ( unsigned long ) NOT_SET ) ;
 }
 if ( ( intval != 0 ) && ( ( apr_size_t ) intval < dcfg -> cache_trans_min ) ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: SecCacheTransformations maxlen must not be less than minlen: %lu < %" APR_SIZE_T_FMT , ( unsigned long ) intval , dcfg -> cache_trans_min ) ;
 }
 dcfg -> cache_trans_max = ( apr_size_t ) intval ;
 }
 charval = apr_table_get ( vartable , "maxitems" ) ;
 if ( charval != NULL ) {
 intval = apr_atoi64 ( charval ) ;
 if ( errno == ERANGE ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: SecCacheTransformations maxitems out of range: %s" , charval ) ;
 }
 if ( intval < 0 ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: SecCacheTransformations maxitems must be positive: %s" , charval ) ;
 }
 dcfg -> cache_trans_maxitems = ( apr_size_t ) intval ;
 }
 }
 return NULL ;
 }