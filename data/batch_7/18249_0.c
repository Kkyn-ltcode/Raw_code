static void decSetSubnormal ( decNumber * dn , decContext * set , Int * residue , uInt * status ) {
 decContext workset ;
 Int etiny , adjust ;
 # if DECSUBSET if ( ! set -> extended ) {
 uprv_decNumberZero ( dn ) ;
 * status |= DEC_Underflow | DEC_Subnormal | DEC_Inexact | DEC_Rounded ;
 return ;
 }
 # endif etiny = set -> emin - ( set -> digits - 1 ) ;
 if ISZERO ( dn ) {
 # if DECCHECK if ( * residue != 0 ) {
 printf ( "++ Subnormal 0 residue %ld\n" , ( LI ) * residue ) ;
 * status |= DEC_Invalid_operation ;
 }
 # endif if ( dn -> exponent < etiny ) {
 dn -> exponent = etiny ;
 * status |= DEC_Clamped ;
 }
 return ;
 }
 * status |= DEC_Subnormal ;
 adjust = etiny - dn -> exponent ;
 if ( adjust <= 0 ) {
 if ( * status & DEC_Inexact ) * status |= DEC_Underflow ;
 return ;
 }
 workset = * set ;
 workset . digits = dn -> digits - adjust ;
 workset . emin -= adjust ;
 decSetCoeff ( dn , & workset , dn -> lsu , dn -> digits , residue , status ) ;
 decApplyRound ( dn , & workset , * residue , status ) ;
 if ( * status & DEC_Inexact ) * status |= DEC_Underflow ;
 if ( dn -> exponent > etiny ) {
 dn -> digits = decShiftToMost ( dn -> lsu , dn -> digits , 1 ) ;
 dn -> exponent -- ;
 }
 if ( ISZERO ( dn ) ) * status |= DEC_Clamped ;
 }