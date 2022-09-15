static void encode_aspect_ratio ( VC2EncContext * s ) {
 put_bits ( & s -> pb , 1 , ! s -> strict_compliance ) ;
 if ( ! s -> strict_compliance ) {
 AVCodecContext * avctx = s -> avctx ;
 put_vc2_ue_uint ( & s -> pb , 0 ) ;
 put_vc2_ue_uint ( & s -> pb , avctx -> sample_aspect_ratio . num ) ;
 put_vc2_ue_uint ( & s -> pb , avctx -> sample_aspect_ratio . den ) ;
 }
 }