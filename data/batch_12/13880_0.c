int virLogDefineOutputs ( virLogOutputPtr * outputs , size_t noutputs ) {
 # if HAVE_SYSLOG_H int id ;
 char * tmp = NULL ;
 # endif if ( virLogInitialize ( ) < 0 ) return - 1 ;
 virLogLock ( ) ;
 virLogResetOutputs ( ) ;
 # if HAVE_SYSLOG_H if ( ( id = virLogFindOutput ( outputs , noutputs , VIR_LOG_TO_SYSLOG , current_ident ) ) != - 1 ) {
 if ( VIR_STRDUP_QUIET ( tmp , outputs [ id ] -> name ) < 0 ) {
 virLogUnlock ( ) ;
 return - 1 ;
 }
 VIR_FREE ( current_ident ) ;
 current_ident = tmp ;
 openlog ( current_ident , 0 , 0 ) ;
 }
 # endif virLogOutputs = outputs ;
 virLogNbOutputs = noutputs ;
 virLogUnlock ( ) ;
 return 0 ;
 }