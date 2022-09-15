static void cal_mvsadcosts ( int * mvsadcost [ 2 ] ) {
 int i = 1 ;
 mvsadcost [ 0 ] [ 0 ] = 300 ;
 mvsadcost [ 1 ] [ 0 ] = 300 ;
 do {
 double z = 256 * ( 2 * ( log2f ( 8 * i ) + .6 ) ) ;
 mvsadcost [ 0 ] [ i ] = ( int ) z ;
 mvsadcost [ 1 ] [ i ] = ( int ) z ;
 mvsadcost [ 0 ] [ - i ] = ( int ) z ;
 mvsadcost [ 1 ] [ - i ] = ( int ) z ;
 }
 while ( ++ i <= mvfp_max ) ;
 }