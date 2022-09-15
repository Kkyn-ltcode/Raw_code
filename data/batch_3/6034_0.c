static void encode_frame_rate ( VC2EncContext * s ) {
 put_bits ( & s -> pb , 1 , ! s -> strict_compliance ) ;
 if ( ! s -> strict_compliance ) {
 AVCodecContext * avctx = s -> avctx ;
 put_vc2_ue_uint ( & s -> pb , 0 ) ;
 put_vc2_ue_uint ( & s -> pb , avctx -> time_base . den ) ;
 put_vc2_ue_uint ( & s -> pb , avctx -> time_base . num ) ;
 }
 }