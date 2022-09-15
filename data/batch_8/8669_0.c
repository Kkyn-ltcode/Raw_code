static int read_dns ( int fd , int tun_fd , struct query * q ) {
 struct sockaddr_in from ;
 socklen_t addrlen ;
 char packet [ 64 * 1024 ] ;
 int r ;
 # ifndef WINDOWS32 char address [ 96 ] ;
 struct msghdr msg ;
 struct iovec iov ;
 struct cmsghdr * cmsg ;
 addrlen = sizeof ( struct sockaddr ) ;
 iov . iov_base = packet ;
 iov . iov_len = sizeof ( packet ) ;
 msg . msg_name = ( caddr_t ) & from ;
 msg . msg_namelen = ( unsigned ) addrlen ;
 msg . msg_iov = & iov ;
 msg . msg_iovlen = 1 ;
 msg . msg_control = address ;
 msg . msg_controllen = sizeof ( address ) ;
 msg . msg_flags = 0 ;
 r = recvmsg ( fd , & msg , 0 ) ;
 # else addrlen = sizeof ( struct sockaddr ) ;
 r = recvfrom ( fd , packet , sizeof ( packet ) , 0 , ( struct sockaddr * ) & from , & addrlen ) ;
 # endif if ( r > 0 ) {
 memcpy ( ( struct sockaddr * ) & q -> from , ( struct sockaddr * ) & from , addrlen ) ;
 q -> fromlen = addrlen ;
 if ( raw_decode ( packet , r , q , fd , tun_fd ) ) {
 return 0 ;
 }
 if ( dns_decode ( NULL , 0 , q , QR_QUERY , packet , r ) < 0 ) {
 return 0 ;
 }
 # ifndef WINDOWS32 for ( cmsg = CMSG_FIRSTHDR ( & msg ) ;
 cmsg != NULL ;
 cmsg = CMSG_NXTHDR ( & msg , cmsg ) ) {
 if ( cmsg -> cmsg_level == IPPROTO_IP && cmsg -> cmsg_type == DSTADDR_SOCKOPT ) {
 q -> destination = * dstaddr ( cmsg ) ;
 break ;
 }
 }
 # endif return strlen ( q -> name ) ;
 }
 else if ( r < 0 ) {
 warn ( "read dns" ) ;
 }
 return 0 ;
 }