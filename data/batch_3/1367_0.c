static __always_inline __u32 __swab32p ( const __u32 * p ) {
 # ifdef __arch_swab32p return __arch_swab32p ( p ) ;
 # else return __swab32 ( * p ) ;
 # endif }