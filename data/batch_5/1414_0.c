void jpc_ns_fwdlift_row ( jpc_fix_t * a , int numcols , int parity ) {
 register jpc_fix_t * lptr ;
 register jpc_fix_t * hptr ;
 register int n ;
 int llen ;
 llen = ( numcols + 1 - parity ) >> 1 ;
 if ( numcols > 1 ) {
 lptr = & a [ 0 ] ;
 hptr = & a [ llen ] ;
 if ( parity ) {
 jpc_fix_pluseq ( hptr [ 0 ] , jpc_fix_mul ( jpc_dbltofix ( 2.0 * ALPHA ) , lptr [ 0 ] ) ) ;
 ++ hptr ;
 }
 n = numcols - llen - parity - ( parity == ( numcols & 1 ) ) ;
 while ( n -- > 0 ) {
 jpc_fix_pluseq ( hptr [ 0 ] , jpc_fix_mul ( jpc_dbltofix ( ALPHA ) , jpc_fix_add ( lptr [ 0 ] , lptr [ 1 ] ) ) ) ;
 ++ hptr ;
 ++ lptr ;
 }
 if ( parity == ( numcols & 1 ) ) {
 jpc_fix_pluseq ( hptr [ 0 ] , jpc_fix_mul ( jpc_dbltofix ( 2.0 * ALPHA ) , lptr [ 0 ] ) ) ;
 }
 lptr = & a [ 0 ] ;
 hptr = & a [ llen ] ;
 if ( ! parity ) {
 jpc_fix_pluseq ( lptr [ 0 ] , jpc_fix_mul ( jpc_dbltofix ( 2.0 * BETA ) , hptr [ 0 ] ) ) ;
 ++ lptr ;
 }
 n = llen - ( ! parity ) - ( parity != ( numcols & 1 ) ) ;
 while ( n -- > 0 ) {
 jpc_fix_pluseq ( lptr [ 0 ] , jpc_fix_mul ( jpc_dbltofix ( BETA ) , jpc_fix_add ( hptr [ 0 ] , hptr [ 1 ] ) ) ) ;
 ++ lptr ;
 ++ hptr ;
 }
 if ( parity != ( numcols & 1 ) ) {
 jpc_fix_pluseq ( lptr [ 0 ] , jpc_fix_mul ( jpc_dbltofix ( 2.0 * BETA ) , hptr [ 0 ] ) ) ;
 }
 lptr = & a [ 0 ] ;
 hptr = & a [ llen ] ;
 if ( parity ) {
 jpc_fix_pluseq ( hptr [ 0 ] , jpc_fix_mul ( jpc_dbltofix ( 2.0 * GAMMA ) , lptr [ 0 ] ) ) ;
 ++ hptr ;
 }
 n = numcols - llen - parity - ( parity == ( numcols & 1 ) ) ;
 while ( n -- > 0 ) {
 jpc_fix_pluseq ( hptr [ 0 ] , jpc_fix_mul ( jpc_dbltofix ( GAMMA ) , jpc_fix_add ( lptr [ 0 ] , lptr [ 1 ] ) ) ) ;
 ++ hptr ;
 ++ lptr ;
 }
 if ( parity == ( numcols & 1 ) ) {
 jpc_fix_pluseq ( hptr [ 0 ] , jpc_fix_mul ( jpc_dbltofix ( 2.0 * GAMMA ) , lptr [ 0 ] ) ) ;
 }
 lptr = & a [ 0 ] ;
 hptr = & a [ llen ] ;
 if ( ! parity ) {
 jpc_fix_pluseq ( lptr [ 0 ] , jpc_fix_mul ( jpc_dbltofix ( 2.0 * DELTA ) , hptr [ 0 ] ) ) ;
 ++ lptr ;
 }
 n = llen - ( ! parity ) - ( parity != ( numcols & 1 ) ) ;
 while ( n -- > 0 ) {
 jpc_fix_pluseq ( lptr [ 0 ] , jpc_fix_mul ( jpc_dbltofix ( DELTA ) , jpc_fix_add ( hptr [ 0 ] , hptr [ 1 ] ) ) ) ;
 ++ lptr ;
 ++ hptr ;
 }
 if ( parity != ( numcols & 1 ) ) {
 jpc_fix_pluseq ( lptr [ 0 ] , jpc_fix_mul ( jpc_dbltofix ( 2.0 * DELTA ) , hptr [ 0 ] ) ) ;
 }
 # if defined ( WT_DOSCALE ) lptr = & a [ 0 ] ;
 n = llen ;
 while ( n -- > 0 ) {
 lptr [ 0 ] = jpc_fix_mul ( lptr [ 0 ] , jpc_dbltofix ( LGAIN ) ) ;
 ++ lptr ;
 }
 hptr = & a [ llen ] ;
 n = numcols - llen ;
 while ( n -- > 0 ) {
 hptr [ 0 ] = jpc_fix_mul ( hptr [ 0 ] , jpc_dbltofix ( HGAIN ) ) ;
 ++ hptr ;
 }
 # endif }
 else {
 # if defined ( WT_LENONE ) if ( parity ) {
 lptr = & a [ 0 ] ;
 lptr [ 0 ] = jpc_fix_asl ( lptr [ 0 ] , 1 ) ;
 }
 # endif }
 }