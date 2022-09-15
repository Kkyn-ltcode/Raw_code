static void rawv6_err ( struct sock * sk , struct sk_buff * skb , struct inet6_skb_parm * opt , u8 type , u8 code , int offset , __be32 info ) {
 struct inet_sock * inet = inet_sk ( sk ) ;
 struct ipv6_pinfo * np = inet6_sk ( sk ) ;
 int err ;
 int harderr ;
 if ( ! np -> recverr && sk -> sk_state != TCP_ESTABLISHED ) return ;
 harderr = icmpv6_err_convert ( type , code , & err ) ;
 if ( type == ICMPV6_PKT_TOOBIG ) harderr = ( np -> pmtudisc == IPV6_PMTUDISC_DO ) ;
 if ( np -> recverr ) {
 u8 * payload = skb -> data ;
 if ( ! inet -> hdrincl ) payload += offset ;
 ipv6_icmp_error ( sk , skb , err , 0 , ntohl ( info ) , payload ) ;
 }
 if ( np -> recverr || harderr ) {
 sk -> sk_err = err ;
 sk -> sk_error_report ( sk ) ;
 }
 }