int xml_init ( modsec_rec * msr , char * * error_msg ) {
 xmlParserInputBufferCreateFilenameFunc entity ;
 if ( error_msg == NULL ) return - 1 ;
 * error_msg = NULL ;
 msr -> xml = apr_pcalloc ( msr -> mp , sizeof ( xml_data ) ) ;
 if ( msr -> xml == NULL ) return - 1 ;
 if ( msr -> txcfg -> xml_external_entity == 0 ) {
 entity = xmlParserInputBufferCreateFilenameDefault ( xml_unload_external_entity ) ;
 }
 return 1 ;
 }