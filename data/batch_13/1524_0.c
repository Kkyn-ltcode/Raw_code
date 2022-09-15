static int udp_v6_push_pending_frames ( struct sock * sk ) {
 struct sk_buff * skb ;
 struct udphdr * uh ;
 struct udp_sock * up = udp_sk ( sk ) ;
 struct inet_sock * inet = inet_sk ( sk ) ;
 struct flowi * fl = & inet -> cork . fl ;
 int err = 0 ;
 int is_udplite = IS_UDPLITE ( sk ) ;
 __wsum csum = 0 ;
 if ( ( skb = skb_peek ( & sk -> sk_write_queue ) ) == NULL ) goto out ;
 uh = udp_hdr ( skb ) ;
 uh -> source = fl -> fl_ip_sport ;
 uh -> dest = fl -> fl_ip_dport ;
 uh -> len = htons ( up -> len ) ;
 uh -> check = 0 ;
 if ( is_udplite ) csum = udplite_csum_outgoing ( sk , skb ) ;
 else if ( skb -> ip_summed == CHECKSUM_PARTIAL ) {
 udp6_hwcsum_outgoing ( sk , skb , & fl -> fl6_src , & fl -> fl6_dst , up -> len ) ;
 goto send ;
 }
 else csum = udp_csum_outgoing ( sk , skb ) ;
 uh -> check = csum_ipv6_magic ( & fl -> fl6_src , & fl -> fl6_dst , up -> len , fl -> proto , csum ) ;
 if ( uh -> check == 0 ) uh -> check = CSUM_MANGLED_0 ;
 send : err = ip6_push_pending_frames ( sk ) ;
 if ( err ) {
 if ( err == - ENOBUFS && ! inet6_sk ( sk ) -> recverr ) {
 UDP6_INC_STATS_USER ( sock_net ( sk ) , UDP_MIB_SNDBUFERRORS , is_udplite ) ;
 err = 0 ;
 }
 }
 else UDP6_INC_STATS_USER ( sock_net ( sk ) , UDP_MIB_OUTDATAGRAMS , is_udplite ) ;
 out : up -> len = 0 ;
 up -> pending = 0 ;
 return err ;
 }