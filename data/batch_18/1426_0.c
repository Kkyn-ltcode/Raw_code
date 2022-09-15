void jpc_ft_fwdlift_row ( jpc_fix_t * a , int numcols , int parity ) {
 register jpc_fix_t * lptr ;
 register jpc_fix_t * hptr ;
 register int n ;
 int llen ;
 llen = ( numcols + 1 - parity ) >> 1 ;
 if ( numcols > 1 ) {
 lptr = & a [ 0 ] ;
 hptr = & a [ llen ] ;
 if ( parity ) {
 hptr [ 0 ] -= lptr [ 0 ] ;
 ++ hptr ;
 }
 n = numcols - llen - parity - ( parity == ( numcols & 1 ) ) ;
 while ( n -- > 0 ) {
 hptr [ 0 ] -= jpc_fix_asr ( lptr [ 0 ] + lptr [ 1 ] , 1 ) ;
 ++ hptr ;
 ++ lptr ;
 }
 if ( parity == ( numcols & 1 ) ) {
 hptr [ 0 ] -= lptr [ 0 ] ;
 }
 lptr = & a [ 0 ] ;
 hptr = & a [ llen ] ;
 if ( ! parity ) {
 lptr [ 0 ] += jpc_fix_asr ( hptr [ 0 ] + 1 , 1 ) ;
 ++ lptr ;
 }
 n = llen - ( ! parity ) - ( parity != ( numcols & 1 ) ) ;
 while ( n -- > 0 ) {
 lptr [ 0 ] += jpc_fix_asr ( hptr [ 0 ] + hptr [ 1 ] + 2 , 2 ) ;
 ++ lptr ;
 ++ hptr ;
 }
 if ( parity != ( numcols & 1 ) ) {
 lptr [ 0 ] += jpc_fix_asr ( hptr [ 0 ] + 1 , 1 ) ;
 }
 }
 else {
 if ( parity ) {
 lptr = & a [ 0 ] ;
 lptr [ 0 ] = jpc_fix_asl ( lptr [ 0 ] , 1 ) ;
 }
 }
 }