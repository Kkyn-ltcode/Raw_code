static void cal_nmvsadcosts_hp ( int * mvsadcost [ 2 ] ) {
 int i = 1 ;
 mvsadcost [ 0 ] [ 0 ] = 0 ;
 mvsadcost [ 1 ] [ 0 ] = 0 ;
 do {
 double z = 256 * ( 2 * ( log2f ( 8 * i ) + .6 ) ) ;
 mvsadcost [ 0 ] [ i ] = ( int ) z ;
 mvsadcost [ 1 ] [ i ] = ( int ) z ;
 mvsadcost [ 0 ] [ - i ] = ( int ) z ;
 mvsadcost [ 1 ] [ - i ] = ( int ) z ;
 }
 while ( ++ i <= MV_MAX ) ;
 }