static __always_inline __u64 __swab64p ( const __u64 * p ) {
 # ifdef __arch_swab64p return __arch_swab64p ( p ) ;
 # else return __swab64 ( * p ) ;
 # endif }