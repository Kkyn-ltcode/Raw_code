static inline int ipv6_addr_diff ( const struct in6_addr * a1 , const struct in6_addr * a2 ) {
 return __ipv6_addr_diff ( a1 , a2 , sizeof ( struct in6_addr ) ) ;
 }