int vp8_reverse_trans ( int x ) {
 int i ;
 for ( i = 0 ;
 i < 64 ;
 i ++ ) if ( q_trans [ i ] >= x ) return i ;
 return 63 ;
 }