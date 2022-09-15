int16_t vp9_ac_quant ( int qindex , int delta , vpx_bit_depth_t bit_depth ) {
 # if CONFIG_VP9_HIGHBITDEPTH switch ( bit_depth ) {
 case VPX_BITS_8 : return ac_qlookup [ clamp ( qindex + delta , 0 , MAXQ ) ] ;
 case VPX_BITS_10 : return ac_qlookup_10 [ clamp ( qindex + delta , 0 , MAXQ ) ] ;
 case VPX_BITS_12 : return ac_qlookup_12 [ clamp ( qindex + delta , 0 , MAXQ ) ] ;
 default : assert ( 0 && "bit_depth should be VPX_BITS_8, VPX_BITS_10 or VPX_BITS_12" ) ;
 return - 1 ;
 }
 # else ( void ) bit_depth ;
 return ac_qlookup [ clamp ( qindex + delta , 0 , MAXQ ) ] ;
 # endif }