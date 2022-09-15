static __inline__ void __swahb32s ( __u32 * p ) {
 # ifdef __arch_swahb32s __arch_swahb32s ( p ) ;
 # else * p = __swahb32p ( p ) ;
 # endif }