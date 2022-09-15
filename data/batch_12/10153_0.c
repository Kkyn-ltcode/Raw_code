int qemuMonitorJSONRemoveNetdev ( qemuMonitorPtr mon , const char * alias ) {
 int ret ;
 virJSONValuePtr cmd = qemuMonitorJSONMakeCommand ( "netdev_del" , "s:id" , alias , NULL ) ;
 virJSONValuePtr reply = NULL ;
 if ( ! cmd ) return - 1 ;
 ret = qemuMonitorJSONCommand ( mon , cmd , & reply ) ;
 if ( ret == 0 ) ret = qemuMonitorJSONCheckError ( cmd , reply ) ;
 virJSONValueFree ( cmd ) ;
 virJSONValueFree ( reply ) ;
 return ret ;
 }