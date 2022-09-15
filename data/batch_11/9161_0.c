static const char * cmd_argument_separator ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 if ( strlen ( p1 ) != 1 ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid argument separator: %s" , p1 ) ;
 }
 dcfg -> argument_separator = p1 [ 0 ] ;
 return NULL ;
 }