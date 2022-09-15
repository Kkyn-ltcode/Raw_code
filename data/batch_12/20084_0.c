static void fifo_read ( int fd , short event , void * arg ) {
 char buf [ 255 ] ;
 int len ;
 struct event * ev = arg ;
 # ifdef WIN32 DWORD dwBytesRead ;
 # endif event_add ( ev , NULL ) ;
 fprintf ( stderr , "fifo_read called with fd: %d, event: %d, arg: %p\n" , fd , event , arg ) ;
 # ifdef WIN32 len = ReadFile ( ( HANDLE ) fd , buf , sizeof ( buf ) - 1 , & dwBytesRead , NULL ) ;
 if ( len && dwBytesRead == 0 ) {
 fprintf ( stderr , "End Of File" ) ;
 event_del ( ev ) ;
 return ;
 }
 buf [ dwBytesRead ] = '\0' ;
 # else len = read ( fd , buf , sizeof ( buf ) - 1 ) ;
 if ( len == - 1 ) {
 perror ( "read" ) ;
 return ;
 }
 else if ( len == 0 ) {
 fprintf ( stderr , "Connection closed\n" ) ;
 return ;
 }
 buf [ len ] = '\0' ;
 # endif fprintf ( stdout , "Read: %s\n" , buf ) ;
 }