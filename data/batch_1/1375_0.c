static __inline__ __u32 __swahw32p ( const __u32 * p ) {
 # ifdef __arch_swahw32p return __arch_swahw32p ( p ) ;
 # else return __swahw32 ( * p ) ;
 # endif }