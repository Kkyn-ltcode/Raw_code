void jpc_qmfb_split_col ( jpc_fix_t * a , int numrows , int stride , int parity ) {
 int bufsize = JPC_CEILDIVPOW2 ( numrows , 1 ) ;
 jpc_fix_t splitbuf [ QMFB_SPLITBUFSIZE ] ;
 jpc_fix_t * buf = splitbuf ;
 register jpc_fix_t * srcptr ;
 register jpc_fix_t * dstptr ;
 register int n ;
 register int m ;
 int hstartrow ;
 if ( bufsize > QMFB_SPLITBUFSIZE ) {
 if ( ! ( buf = jas_alloc2 ( bufsize , sizeof ( jpc_fix_t ) ) ) ) {
 abort ( ) ;
 }
 }
 if ( numrows >= 2 ) {
 hstartrow = ( numrows + 1 - parity ) >> 1 ;
 m = numrows - hstartrow ;
 n = m ;
 dstptr = buf ;
 srcptr = & a [ ( 1 - parity ) * stride ] ;
 while ( n -- > 0 ) {
 * dstptr = * srcptr ;
 ++ dstptr ;
 srcptr += stride << 1 ;
 }
 dstptr = & a [ ( 1 - parity ) * stride ] ;
 srcptr = & a [ ( 2 - parity ) * stride ] ;
 n = numrows - m - ( ! parity ) ;
 while ( n -- > 0 ) {
 * dstptr = * srcptr ;
 dstptr += stride ;
 srcptr += stride << 1 ;
 }
 dstptr = & a [ hstartrow * stride ] ;
 srcptr = buf ;
 n = m ;
 while ( n -- > 0 ) {
 * dstptr = * srcptr ;
 dstptr += stride ;
 ++ srcptr ;
 }
 }
 if ( buf != splitbuf ) {
 jas_free ( buf ) ;
 }
 }