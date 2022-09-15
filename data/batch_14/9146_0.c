static const char * cmd_xml_external_entity ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 directory_config * dcfg = ( directory_config * ) _dcfg ;
 if ( dcfg == NULL ) return NULL ;
 if ( strcasecmp ( p1 , "on" ) == 0 ) {
 dcfg -> xml_external_entity = 1 ;
 }
 else if ( strcasecmp ( p1 , "off" ) == 0 ) {
 dcfg -> xml_external_entity = 0 ;
 }
 else return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid value for SecXmlExternalEntity: %s" , p1 ) ;
 return NULL ;
 }