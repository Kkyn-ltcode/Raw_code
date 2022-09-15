static const char * cmd_unicode_map ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 const char * filename = resolve_relative_path ( cmd -> pool , cmd -> directive -> filename , p1 ) ;
 char * error_msg ;
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 if ( dcfg == NULL ) return NULL ;
 if ( unicode_map_init ( dcfg , filename , & error_msg ) <= 0 ) {
 return error_msg ;
 }
 return NULL ;
 }