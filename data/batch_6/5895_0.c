static inline bool ipv6_masked_addr_cmp ( const struct in6_addr * a1 , const struct in6_addr * m , const struct in6_addr * a2 ) {
 # if defined ( CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS ) && BITS_PER_LONG == 64 const unsigned long * ul1 = ( const unsigned long * ) a1 ;
 const unsigned long * ulm = ( const unsigned long * ) m ;
 const unsigned long * ul2 = ( const unsigned long * ) a2 ;
 return ! ! ( ( ( ul1 [ 0 ] ^ ul2 [ 0 ] ) & ulm [ 0 ] ) | ( ( ul1 [ 1 ] ^ ul2 [ 1 ] ) & ulm [ 1 ] ) ) ;
 # else return ! ! ( ( ( a1 -> s6_addr32 [ 0 ] ^ a2 -> s6_addr32 [ 0 ] ) & m -> s6_addr32 [ 0 ] ) | ( ( a1 -> s6_addr32 [ 1 ] ^ a2 -> s6_addr32 [ 1 ] ) & m -> s6_addr32 [ 1 ] ) | ( ( a1 -> s6_addr32 [ 2 ] ^ a2 -> s6_addr32 [ 2 ] ) & m -> s6_addr32 [ 2 ] ) | ( ( a1 -> s6_addr32 [ 3 ] ^ a2 -> s6_addr32 [ 3 ] ) & m -> s6_addr32 [ 3 ] ) ) ;
 # endif }