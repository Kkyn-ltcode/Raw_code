char * xmlrpc_time2date ( char * buf , time_t t ) {
 char timebuf [ XMLRPC_BUFSIZE ] ;
 struct tm * tm ;
 * buf = '\0' ;
 tm = localtime ( & t ) ;
 strftime ( timebuf , XMLRPC_BUFSIZE - 1 , "%Y%m%dT%I:%M:%S" , tm ) ;
 snprintf ( buf , XMLRPC_BUFSIZE , "<dateTime.iso8601>%s</dateTime.iso8601>" , timebuf ) ;
 return buf ;
 }