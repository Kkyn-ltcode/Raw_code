static int rawv6_bind ( struct sock * sk , struct sockaddr * uaddr , int addr_len ) {
 struct inet_sock * inet = inet_sk ( sk ) ;
 struct ipv6_pinfo * np = inet6_sk ( sk ) ;
 struct sockaddr_in6 * addr = ( struct sockaddr_in6 * ) uaddr ;
 __be32 v4addr = 0 ;
 int addr_type ;
 int err ;
 if ( addr_len < SIN6_LEN_RFC2133 ) return - EINVAL ;
 addr_type = ipv6_addr_type ( & addr -> sin6_addr ) ;
 if ( addr_type == IPV6_ADDR_MAPPED ) return - EADDRNOTAVAIL ;
 lock_sock ( sk ) ;
 err = - EINVAL ;
 if ( sk -> sk_state != TCP_CLOSE ) goto out ;
 rcu_read_lock ( ) ;
 if ( addr_type != IPV6_ADDR_ANY ) {
 struct net_device * dev = NULL ;
 if ( addr_type & IPV6_ADDR_LINKLOCAL ) {
 if ( addr_len >= sizeof ( struct sockaddr_in6 ) && addr -> sin6_scope_id ) {
 sk -> sk_bound_dev_if = addr -> sin6_scope_id ;
 }
 if ( ! sk -> sk_bound_dev_if ) goto out_unlock ;
 err = - ENODEV ;
 dev = dev_get_by_index_rcu ( sock_net ( sk ) , sk -> sk_bound_dev_if ) ;
 if ( ! dev ) goto out_unlock ;
 }
 v4addr = LOOPBACK4_IPV6 ;
 if ( ! ( addr_type & IPV6_ADDR_MULTICAST ) ) {
 err = - EADDRNOTAVAIL ;
 if ( ! ipv6_chk_addr ( sock_net ( sk ) , & addr -> sin6_addr , dev , 0 ) ) {
 goto out_unlock ;
 }
 }
 }
 inet -> inet_rcv_saddr = inet -> inet_saddr = v4addr ;
 ipv6_addr_copy ( & np -> rcv_saddr , & addr -> sin6_addr ) ;
 if ( ! ( addr_type & IPV6_ADDR_MULTICAST ) ) ipv6_addr_copy ( & np -> saddr , & addr -> sin6_addr ) ;
 err = 0 ;
 out_unlock : rcu_read_unlock ( ) ;
 out : release_sock ( sk ) ;
 return err ;
 }