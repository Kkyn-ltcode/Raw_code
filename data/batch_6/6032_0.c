static void encode_frame_size ( VC2EncContext * s ) {
 put_bits ( & s -> pb , 1 , ! s -> strict_compliance ) ;
 if ( ! s -> strict_compliance ) {
 AVCodecContext * avctx = s -> avctx ;
 put_vc2_ue_uint ( & s -> pb , avctx -> width ) ;
 put_vc2_ue_uint ( & s -> pb , avctx -> height ) ;
 }
 }