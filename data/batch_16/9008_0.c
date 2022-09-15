static unsigned long get_logmask ( char * s ) {
 char * t ;
 unsigned long offset ;
 unsigned long mask ;
 t = s ;
 offset = get_pfxmatch ( & t , logcfg_class ) ;
 mask = get_match ( t , logcfg_item ) ;
 if ( mask ) return mask << offset ;
 else msyslog ( LOG_ERR , "logconfig: illegal argument %s - ignored" , s ) ;
 return 0 ;
 }