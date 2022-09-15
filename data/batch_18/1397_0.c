static __inline__ void __swahw32s ( __u32 * p ) {
 # ifdef __arch_swahw32s __arch_swahw32s ( p ) ;
 # else * p = __swahw32p ( p ) ;
 # endif }