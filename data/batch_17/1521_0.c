static void udp_v6_flush_pending_frames ( struct sock * sk ) {
 struct udp_sock * up = udp_sk ( sk ) ;
 if ( up -> pending == AF_INET ) udp_flush_pending_frames ( sk ) ;
 else if ( up -> pending ) {
 up -> len = 0 ;
 up -> pending = 0 ;
 ip6_flush_pending_frames ( sk ) ;
 }
 }