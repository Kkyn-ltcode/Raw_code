rfbBool rfbSendFileTransferChunk ( rfbClientPtr cl ) {
 unsigned char readBuf [ sz_rfbBlockSize ] ;
 int bytesRead = 0 ;
 int retval = 0 ;
 fd_set wfds ;
 struct timeval tv ;
 int n ;
 # ifdef LIBVNCSERVER_HAVE_LIBZ unsigned char compBuf [ sz_rfbBlockSize + 1024 ] ;
 unsigned long nMaxCompSize = sizeof ( compBuf ) ;
 int nRetC = 0 ;
 # endif if ( cl -> screen -> permitFileTransfer != TRUE || ( cl -> screen -> getFileTransferPermission != NULL && cl -> screen -> getFileTransferPermission ( cl ) != TRUE ) ) {
 return TRUE ;
 }
 if ( ( cl -> fileTransfer . fd != - 1 ) && ( cl -> fileTransfer . sending == 1 ) ) {
 FD_ZERO ( & wfds ) ;
 FD_SET ( cl -> sock , & wfds ) ;
 tv . tv_sec = 0 ;
 tv . tv_usec = 0 ;
 n = select ( cl -> sock + 1 , NULL , & wfds , NULL , & tv ) ;
 if ( n < 0 ) {
 # ifdef WIN32 errno = WSAGetLastError ( ) ;
 # endif rfbLog ( "rfbSendFileTransferChunk() select failed: %s\n" , strerror ( errno ) ) ;
 }
 if ( n > 0 ) {
 bytesRead = read ( cl -> fileTransfer . fd , readBuf , sz_rfbBlockSize ) ;
 switch ( bytesRead ) {
 case 0 : retval = rfbSendFileTransferMessage ( cl , rfbEndOfFile , 0 , 0 , 0 , NULL ) ;
 close ( cl -> fileTransfer . fd ) ;
 cl -> fileTransfer . fd = - 1 ;
 cl -> fileTransfer . sending = 0 ;
 cl -> fileTransfer . receiving = 0 ;
 return retval ;
 case - 1 : # ifdef WIN32 errno = WSAGetLastError ( ) ;
 # endif rfbLog ( "rfbSendFileTransferChunk(): %s\n" , strerror ( errno ) ) ;
 retval = rfbSendFileTransferMessage ( cl , rfbAbortFileTransfer , 0 , 0 , 0 , NULL ) ;
 close ( cl -> fileTransfer . fd ) ;
 cl -> fileTransfer . fd = - 1 ;
 cl -> fileTransfer . sending = 0 ;
 cl -> fileTransfer . receiving = 0 ;
 return retval ;
 default : if ( ! cl -> fileTransfer . compressionEnabled ) return rfbSendFileTransferMessage ( cl , rfbFilePacket , 0 , 0 , bytesRead , ( char * ) readBuf ) ;
 else {
 # ifdef LIBVNCSERVER_HAVE_LIBZ nRetC = compress ( compBuf , & nMaxCompSize , readBuf , bytesRead ) ;
 if ( ( nRetC == 0 ) && ( nMaxCompSize < bytesRead ) ) return rfbSendFileTransferMessage ( cl , rfbFilePacket , 0 , 1 , nMaxCompSize , ( char * ) compBuf ) ;
 else return rfbSendFileTransferMessage ( cl , rfbFilePacket , 0 , 0 , bytesRead , ( char * ) readBuf ) ;
 # else return rfbSendFileTransferMessage ( cl , rfbFilePacket , 0 , 0 , bytesRead , ( char * ) readBuf ) ;
 # endif }
 }
 }
 }
 return TRUE ;
 }