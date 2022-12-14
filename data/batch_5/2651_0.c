static int decode_mv_component ( GetBitContext * gb , int v ) {
 int mv_diff = get_vlc2 ( gb , h261_mv_vlc . table , H261_MV_VLC_BITS , 2 ) ;
 if ( mv_diff < 0 ) return v ;
 mv_diff = mvmap [ mv_diff ] ;
 if ( mv_diff && ! get_bits1 ( gb ) ) mv_diff = - mv_diff ;
 v += mv_diff ;
 if ( v <= - 16 ) v += 32 ;
 else if ( v >= 16 ) v -= 32 ;
 return v ;
 }