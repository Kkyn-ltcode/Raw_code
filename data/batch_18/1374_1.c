static int remoteStreamHandleRead ( struct qemud_client * client , struct qemud_client_stream * stream ) {
 char * buffer ;
 size_t bufferLen = REMOTE_MESSAGE_PAYLOAD_MAX ;
 int ret ;
 VIR_DEBUG ( "stream=%p" , stream ) ;
 if ( ! stream -> tx ) return 0 ;
 if ( VIR_ALLOC_N ( buffer , bufferLen ) < 0 ) return - 1 ;
 ret = virStreamRecv ( stream -> st , buffer , bufferLen ) ;
 if ( ret == - 2 ) {
 ret = 0 ;
 }
 else if ( ret < 0 ) {
 remote_error rerr ;
 memset ( & rerr , 0 , sizeof rerr ) ;
 remoteDispatchConnError ( & rerr , NULL ) ;
 ret = remoteSerializeStreamError ( client , & rerr , stream -> procedure , stream -> serial ) ;
 }
 else {
 stream -> tx = 0 ;
 if ( ret == 0 ) stream -> recvEOF = 1 ;
 ret = remoteSendStreamData ( client , stream , buffer , ret ) ;
 }
 VIR_FREE ( buffer ) ;
 return ret ;
 }