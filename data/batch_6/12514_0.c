static inline Quantum GetPixelGreen ( const Image * restrict image , const Quantum * restrict pixel ) {
 return ( pixel [ image -> channel_map [ GreenPixelChannel ] . offset ] ) ;
 }