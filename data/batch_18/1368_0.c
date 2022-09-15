static __always_inline void __swab32s ( __u32 * p ) {
 # ifdef __arch_swab32s __arch_swab32s ( p ) ;
 # else * p = __swab32p ( p ) ;
 # endif }