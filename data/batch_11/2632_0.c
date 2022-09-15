static void de_emphasis ( float * out , float * in , float m , float mem [ 1 ] ) {
 int i ;
 out [ 0 ] = in [ 0 ] + m * mem [ 0 ] ;
 for ( i = 1 ;
 i < AMRWB_SFR_SIZE ;
 i ++ ) out [ i ] = in [ i ] + out [ i - 1 ] * m ;
 mem [ 0 ] = out [ AMRWB_SFR_SIZE - 1 ] ;
 }