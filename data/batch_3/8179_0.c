relpRetVal relpTcpAcceptConnReq ( relpTcp_t * * ppThis , int sock , relpSrv_t * pSrv ) {
 relpTcp_t * pThis = NULL ;
 int sockflags ;
 struct sockaddr_storage addr ;
 socklen_t addrlen = sizeof ( addr ) ;
 int iNewSock = - 1 ;
 relpEngine_t * pEngine = pSrv -> pEngine ;
 ENTER_RELPFUNC ;
 assert ( ppThis != NULL ) ;
 iNewSock = accept ( sock , ( struct sockaddr * ) & addr , & addrlen ) ;
 int errnosave = errno ;
 if ( iNewSock < 0 ) {
 pSrv -> pEngine -> dbgprint ( "error during accept, sleeping 20ms: %s\n" , strerror ( errnosave ) ) ;
 doSleep ( 0 , 20000 ) ;
 pSrv -> pEngine -> dbgprint ( "END SLEEP\n" ) ;
 ABORT_FINALIZE ( RELP_RET_ACCEPT_ERR ) ;
 }
 CHKRet ( relpTcpConstruct ( & pThis , pEngine , RELP_SRV_CONN , pSrv ) ) ;
 if ( pSrv -> bKeepAlive ) EnableKeepAlive ( pThis , pSrv , iNewSock ) ;
 CHKRet ( relpTcpSetRemHost ( pThis , ( struct sockaddr * ) & addr ) ) ;
 pThis -> pEngine -> dbgprint ( "remote host is '%s', ip '%s'\n" , pThis -> pRemHostName , pThis -> pRemHostIP ) ;
 if ( ( sockflags = fcntl ( iNewSock , F_GETFL ) ) != - 1 ) {
 sockflags |= O_NONBLOCK ;
 sockflags = fcntl ( iNewSock , F_SETFL , sockflags ) ;
 }
 if ( sockflags == - 1 ) {
 pThis -> pEngine -> dbgprint ( "error %d setting fcntl(O_NONBLOCK) on relp socket %d" , errno , iNewSock ) ;
 ABORT_FINALIZE ( RELP_RET_IO_ERR ) ;
 }
 pThis -> sock = iNewSock ;
 # ifdef ENABLE_TLS if ( pSrv -> pTcp -> bEnableTLS ) {
 pThis -> bEnableTLS = 1 ;
 pThis -> pSrv = pSrv ;
 CHKRet ( relpTcpSetPermittedPeers ( pThis , & ( pSrv -> permittedPeers ) ) ) ;
 CHKRet ( relpTcpAcceptConnReqInitTLS ( pThis , pSrv ) ) ;
 }
 # endif * ppThis = pThis ;
 finalize_it : if ( iRet != RELP_RET_OK ) {
 if ( pThis != NULL ) relpTcpDestruct ( & pThis ) ;
 if ( iNewSock >= 0 ) close ( iNewSock ) ;
 }
 LEAVE_RELPFUNC ;
 }