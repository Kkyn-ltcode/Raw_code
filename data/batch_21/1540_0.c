static inline unsigned int ip_hdrlen ( const struct sk_buff * skb ) {
 return ip_hdr ( skb ) -> ihl * 4 ;
 }