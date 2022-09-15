static inline picture_t * ffmpeg_NewPictBuf ( decoder_t * p_dec , AVCodecContext * p_context ) {
 decoder_sys_t * p_sys = p_dec -> p_sys ;
 int width = p_context -> coded_width ;
 int height = p_context -> coded_height ;
 if ( p_sys -> p_va == NULL ) {
 int aligns [ AV_NUM_DATA_POINTERS ] ;
 avcodec_align_dimensions2 ( p_context , & width , & height , aligns ) ;
 }
 if ( width == 0 || height == 0 || width > 8192 || height > 8192 || width < p_context -> width || height < p_context -> height ) {
 msg_Err ( p_dec , "Invalid frame size %dx%d. vsz %dx%d" , width , height , p_context -> width , p_context -> height ) ;
 return NULL ;
 }
 p_dec -> fmt_out . video . i_width = width ;
 p_dec -> fmt_out . video . i_height = height ;
 if ( width != p_context -> width || height != p_context -> height ) {
 p_dec -> fmt_out . video . i_visible_width = p_context -> width ;
 p_dec -> fmt_out . video . i_visible_height = p_context -> height ;
 }
 else {
 p_dec -> fmt_out . video . i_visible_width = width ;
 p_dec -> fmt_out . video . i_visible_height = height ;
 }
 if ( ! p_sys -> p_va && GetVlcChroma ( & p_dec -> fmt_out . video , p_context -> pix_fmt ) ) {
 p_dec -> fmt_out . video . i_chroma = VLC_CODEC_I420 ;
 }
 p_dec -> fmt_out . i_codec = p_dec -> fmt_out . video . i_chroma ;
 if ( p_dec -> fmt_in . video . i_sar_num > 0 && p_dec -> fmt_in . video . i_sar_den > 0 ) {
 p_dec -> fmt_out . video . i_sar_num = p_dec -> fmt_in . video . i_sar_num ;
 p_dec -> fmt_out . video . i_sar_den = p_dec -> fmt_in . video . i_sar_den ;
 }
 else {
 p_dec -> fmt_out . video . i_sar_num = p_context -> sample_aspect_ratio . num ;
 p_dec -> fmt_out . video . i_sar_den = p_context -> sample_aspect_ratio . den ;
 if ( ! p_dec -> fmt_out . video . i_sar_num || ! p_dec -> fmt_out . video . i_sar_den ) {
 p_dec -> fmt_out . video . i_sar_num = 1 ;
 p_dec -> fmt_out . video . i_sar_den = 1 ;
 }
 }
 if ( p_dec -> fmt_in . video . i_frame_rate > 0 && p_dec -> fmt_in . video . i_frame_rate_base > 0 ) {
 p_dec -> fmt_out . video . i_frame_rate = p_dec -> fmt_in . video . i_frame_rate ;
 p_dec -> fmt_out . video . i_frame_rate_base = p_dec -> fmt_in . video . i_frame_rate_base ;
 }
 # if LIBAVCODEC_VERSION_CHECK ( 56 , 5 , 0 , 7 , 100 ) else if ( p_context -> framerate . num > 0 && p_context -> framerate . den > 0 ) {
 p_dec -> fmt_out . video . i_frame_rate = p_context -> framerate . num ;
 p_dec -> fmt_out . video . i_frame_rate_base = p_context -> framerate . den ;
 # if LIBAVCODEC_VERSION_MICRO < 100 p_dec -> fmt_out . video . i_frame_rate_base *= __MAX ( p_context -> ticks_per_frame , 1 ) ;
 # endif }
 # endif else if ( p_context -> time_base . num > 0 && p_context -> time_base . den > 0 ) {
 p_dec -> fmt_out . video . i_frame_rate = p_context -> time_base . den ;
 p_dec -> fmt_out . video . i_frame_rate_base = p_context -> time_base . num * __MAX ( p_context -> ticks_per_frame , 1 ) ;
 }
 return decoder_NewPicture ( p_dec ) ;
 }