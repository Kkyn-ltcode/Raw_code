static void libschroedinger_flush ( AVCodecContext * avctx ) {
 SchroDecoderParams * p_schro_params = avctx -> priv_data ;
 ff_schro_queue_free ( & p_schro_params -> dec_frame_queue , libschroedinger_decode_frame_free ) ;
 ff_schro_queue_init ( & p_schro_params -> dec_frame_queue ) ;
 schro_decoder_reset ( p_schro_params -> decoder ) ;
 p_schro_params -> eos_pulled = 0 ;
 p_schro_params -> eos_signalled = 0 ;
 }