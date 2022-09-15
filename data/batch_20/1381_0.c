static __inline__ __u32 __swahb32p ( const __u32 * p ) {
 # ifdef __arch_swahb32p return __arch_swahb32p ( p ) ;
 # else return __swahb32 ( * p ) ;
 # endif }