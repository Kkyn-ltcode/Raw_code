static inline int vp3_dequant ( Vp3DecodeContext * s , Vp3Fragment * frag , int plane , int inter , int16_t block [ 64 ] ) {
 int16_t * dequantizer = s -> qmat [ frag -> qpi ] [ inter ] [ plane ] ;
 uint8_t * perm = s -> scantable . permutated ;
 int i = 0 ;
 do {
 int token = * s -> dct_tokens [ plane ] [ i ] ;
 switch ( token & 3 ) {
 case 0 : if ( -- token < 4 ) s -> dct_tokens [ plane ] [ i ] ++ ;
 else * s -> dct_tokens [ plane ] [ i ] = token & ~ 3 ;
 goto end ;
 case 1 : s -> dct_tokens [ plane ] [ i ] ++ ;
 i += ( token >> 2 ) & 0x7f ;
 if ( i > 63 ) {
 av_log ( s -> avctx , AV_LOG_ERROR , "Coefficient index overflow\n" ) ;
 return i ;
 }
 block [ perm [ i ] ] = ( token >> 9 ) * dequantizer [ perm [ i ] ] ;
 i ++ ;
 break ;
 case 2 : block [ perm [ i ] ] = ( token >> 2 ) * dequantizer [ perm [ i ] ] ;
 s -> dct_tokens [ plane ] [ i ++ ] ++ ;
 break ;
 default : return i ;
 }
 }
 while ( i < 64 ) ;
 i -- ;
 end : block [ 0 ] = frag -> dc * s -> qmat [ 0 ] [ inter ] [ plane ] [ 0 ] ;
 return i ;
 }