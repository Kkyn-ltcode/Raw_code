static __always_inline void __swab64s ( __u64 * p ) {
 # ifdef __arch_swab64s __arch_swab64s ( p ) ;
 # else * p = __swab64p ( p ) ;
 # endif }