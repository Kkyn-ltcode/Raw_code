static inline u16 socket_type_to_security_class ( int family , int type , int protocol ) {
 switch ( family ) {
 case PF_UNIX : switch ( type ) {
 case SOCK_STREAM : case SOCK_SEQPACKET : return SECCLASS_UNIX_STREAM_SOCKET ;
 case SOCK_DGRAM : return SECCLASS_UNIX_DGRAM_SOCKET ;
 }
 break ;
 case PF_INET : case PF_INET6 : switch ( type ) {
 case SOCK_STREAM : if ( default_protocol_stream ( protocol ) ) return SECCLASS_TCP_SOCKET ;
 else return SECCLASS_RAWIP_SOCKET ;
 case SOCK_DGRAM : if ( default_protocol_dgram ( protocol ) ) return SECCLASS_UDP_SOCKET ;
 else return SECCLASS_RAWIP_SOCKET ;
 case SOCK_DCCP : return SECCLASS_DCCP_SOCKET ;
 default : return SECCLASS_RAWIP_SOCKET ;
 }
 break ;
 case PF_NETLINK : switch ( protocol ) {
 case NETLINK_ROUTE : return SECCLASS_NETLINK_ROUTE_SOCKET ;
 case NETLINK_SOCK_DIAG : return SECCLASS_NETLINK_TCPDIAG_SOCKET ;
 case NETLINK_NFLOG : return SECCLASS_NETLINK_NFLOG_SOCKET ;
 case NETLINK_XFRM : return SECCLASS_NETLINK_XFRM_SOCKET ;
 case NETLINK_SELINUX : return SECCLASS_NETLINK_SELINUX_SOCKET ;
 case NETLINK_ISCSI : return SECCLASS_NETLINK_ISCSI_SOCKET ;
 case NETLINK_AUDIT : return SECCLASS_NETLINK_AUDIT_SOCKET ;
 case NETLINK_FIB_LOOKUP : return SECCLASS_NETLINK_FIB_LOOKUP_SOCKET ;
 case NETLINK_CONNECTOR : return SECCLASS_NETLINK_CONNECTOR_SOCKET ;
 case NETLINK_NETFILTER : return SECCLASS_NETLINK_NETFILTER_SOCKET ;
 case NETLINK_DNRTMSG : return SECCLASS_NETLINK_DNRT_SOCKET ;
 case NETLINK_KOBJECT_UEVENT : return SECCLASS_NETLINK_KOBJECT_UEVENT_SOCKET ;
 case NETLINK_GENERIC : return SECCLASS_NETLINK_GENERIC_SOCKET ;
 case NETLINK_SCSITRANSPORT : return SECCLASS_NETLINK_SCSITRANSPORT_SOCKET ;
 case NETLINK_RDMA : return SECCLASS_NETLINK_RDMA_SOCKET ;
 case NETLINK_CRYPTO : return SECCLASS_NETLINK_CRYPTO_SOCKET ;
 default : return SECCLASS_NETLINK_SOCKET ;
 }
 case PF_PACKET : return SECCLASS_PACKET_SOCKET ;
 case PF_KEY : return SECCLASS_KEY_SOCKET ;
 case PF_APPLETALK : return SECCLASS_APPLETALK_SOCKET ;
 }
 return SECCLASS_SOCKET ;
 }