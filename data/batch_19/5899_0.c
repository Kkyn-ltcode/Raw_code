static inline bool ipv6_addr_equal ( const struct in6_addr * a1 , const struct in6_addr * a2 ) {
 # if defined ( CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS ) && BITS_PER_LONG == 64 const unsigned long * ul1 = ( const unsigned long * ) a1 ;
 const unsigned long * ul2 = ( const unsigned long * ) a2 ;
 return ( ( ul1 [ 0 ] ^ ul2 [ 0 ] ) | ( ul1 [ 1 ] ^ ul2 [ 1 ] ) ) == 0UL ;
 # else return ( ( a1 -> s6_addr32 [ 0 ] ^ a2 -> s6_addr32 [ 0 ] ) | ( a1 -> s6_addr32 [ 1 ] ^ a2 -> s6_addr32 [ 1 ] ) | ( a1 -> s6_addr32 [ 2 ] ^ a2 -> s6_addr32 [ 2 ] ) | ( a1 -> s6_addr32 [ 3 ] ^ a2 -> s6_addr32 [ 3 ] ) ) == 0 ;
 # endif }