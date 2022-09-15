static inline u32 ipv6_addr_hash ( const struct in6_addr * a ) {
 # if defined ( CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS ) && BITS_PER_LONG == 64 const unsigned long * ul = ( const unsigned long * ) a ;
 unsigned long x = ul [ 0 ] ^ ul [ 1 ] ;
 return ( u32 ) ( x ^ ( x >> 32 ) ) ;
 # else return ( __force u32 ) ( a -> s6_addr32 [ 0 ] ^ a -> s6_addr32 [ 1 ] ^ a -> s6_addr32 [ 2 ] ^ a -> s6_addr32 [ 3 ] ) ;
 # endif }