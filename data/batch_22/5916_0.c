static inline bool ipv6_addr_any ( const struct in6_addr * a ) {
 # if defined ( CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS ) && BITS_PER_LONG == 64 const unsigned long * ul = ( const unsigned long * ) a ;
 return ( ul [ 0 ] | ul [ 1 ] ) == 0UL ;
 # else return ( a -> s6_addr32 [ 0 ] | a -> s6_addr32 [ 1 ] | a -> s6_addr32 [ 2 ] | a -> s6_addr32 [ 3 ] ) == 0 ;
 # endif }