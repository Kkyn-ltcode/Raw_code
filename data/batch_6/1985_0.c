static int vc1_decode_frame ( AVCodecContext * avctx , void * data , int * got_frame , AVPacket * avpkt ) {
 const uint8_t * buf = avpkt -> data ;
 int buf_size = avpkt -> size , n_slices = 0 , i , ret ;
 VC1Context * v = avctx -> priv_data ;
 MpegEncContext * s = & v -> s ;
 AVFrame * pict = data ;
 uint8_t * buf2 = NULL ;
 const uint8_t * buf_start = buf ;
 int mb_height , n_slices1 ;
 struct {
 uint8_t * buf ;
 GetBitContext gb ;
 int mby_start ;
 }
 * slices = NULL , * tmp ;
 if ( buf_size == 0 || ( buf_size == 4 && AV_RB32 ( buf ) == VC1_CODE_ENDOFSEQ ) ) {
 if ( s -> low_delay == 0 && s -> next_picture_ptr ) {
 if ( ( ret = av_frame_ref ( pict , & s -> next_picture_ptr -> f ) ) < 0 ) return ret ;
 s -> next_picture_ptr = NULL ;
 * got_frame = 1 ;
 }
 return 0 ;
 }
 if ( s -> avctx -> codec -> capabilities & CODEC_CAP_HWACCEL_VDPAU ) {
 if ( v -> profile < PROFILE_ADVANCED ) avctx -> pix_fmt = AV_PIX_FMT_VDPAU_WMV3 ;
 else avctx -> pix_fmt = AV_PIX_FMT_VDPAU_VC1 ;
 }
 if ( avctx -> codec_id == AV_CODEC_ID_VC1 || avctx -> codec_id == AV_CODEC_ID_VC1IMAGE ) {
 int buf_size2 = 0 ;
 buf2 = av_mallocz ( buf_size + FF_INPUT_BUFFER_PADDING_SIZE ) ;
 if ( IS_MARKER ( AV_RB32 ( buf ) ) ) {
 const uint8_t * start , * end , * next ;
 int size ;
 next = buf ;
 for ( start = buf , end = buf + buf_size ;
 next < end ;
 start = next ) {
 next = find_next_marker ( start + 4 , end ) ;
 size = next - start - 4 ;
 if ( size <= 0 ) continue ;
 switch ( AV_RB32 ( start ) ) {
 case VC1_CODE_FRAME : if ( avctx -> hwaccel || s -> avctx -> codec -> capabilities & CODEC_CAP_HWACCEL_VDPAU ) buf_start = start ;
 buf_size2 = vc1_unescape_buffer ( start + 4 , size , buf2 ) ;
 break ;
 case VC1_CODE_FIELD : {
 int buf_size3 ;
 tmp = av_realloc ( slices , sizeof ( * slices ) * ( n_slices + 1 ) ) ;
 if ( ! tmp ) goto err ;
 slices = tmp ;
 slices [ n_slices ] . buf = av_mallocz ( buf_size + FF_INPUT_BUFFER_PADDING_SIZE ) ;
 if ( ! slices [ n_slices ] . buf ) goto err ;
 buf_size3 = vc1_unescape_buffer ( start + 4 , size , slices [ n_slices ] . buf ) ;
 init_get_bits ( & slices [ n_slices ] . gb , slices [ n_slices ] . buf , buf_size3 << 3 ) ;
 slices [ n_slices ] . mby_start = s -> mb_height >> 1 ;
 n_slices1 = n_slices - 1 ;
 n_slices ++ ;
 break ;
 }
 case VC1_CODE_ENTRYPOINT : buf_size2 = vc1_unescape_buffer ( start + 4 , size , buf2 ) ;
 init_get_bits ( & s -> gb , buf2 , buf_size2 * 8 ) ;
 ff_vc1_decode_entry_point ( avctx , v , & s -> gb ) ;
 break ;
 case VC1_CODE_SLICE : {
 int buf_size3 ;
 tmp = av_realloc ( slices , sizeof ( * slices ) * ( n_slices + 1 ) ) ;
 if ( ! tmp ) goto err ;
 slices = tmp ;
 slices [ n_slices ] . buf = av_mallocz ( buf_size + FF_INPUT_BUFFER_PADDING_SIZE ) ;
 if ( ! slices [ n_slices ] . buf ) goto err ;
 buf_size3 = vc1_unescape_buffer ( start + 4 , size , slices [ n_slices ] . buf ) ;
 init_get_bits ( & slices [ n_slices ] . gb , slices [ n_slices ] . buf , buf_size3 << 3 ) ;
 slices [ n_slices ] . mby_start = get_bits ( & slices [ n_slices ] . gb , 9 ) ;
 n_slices ++ ;
 break ;
 }
 }
 }
 }
 else if ( v -> interlace && ( ( buf [ 0 ] & 0xC0 ) == 0xC0 ) ) {
 const uint8_t * divider ;
 int buf_size3 ;
 divider = find_next_marker ( buf , buf + buf_size ) ;
 if ( ( divider == ( buf + buf_size ) ) || AV_RB32 ( divider ) != VC1_CODE_FIELD ) {
 av_log ( avctx , AV_LOG_ERROR , "Error in WVC1 interlaced frame\n" ) ;
 goto err ;
 }
 else {
 tmp = av_realloc ( slices , sizeof ( * slices ) * ( n_slices + 1 ) ) ;
 if ( ! tmp ) goto err ;
 slices = tmp ;
 slices [ n_slices ] . buf = av_mallocz ( buf_size + FF_INPUT_BUFFER_PADDING_SIZE ) ;
 if ( ! slices [ n_slices ] . buf ) goto err ;
 buf_size3 = vc1_unescape_buffer ( divider + 4 , buf + buf_size - divider - 4 , slices [ n_slices ] . buf ) ;
 init_get_bits ( & slices [ n_slices ] . gb , slices [ n_slices ] . buf , buf_size3 << 3 ) ;
 slices [ n_slices ] . mby_start = s -> mb_height >> 1 ;
 n_slices1 = n_slices - 1 ;
 n_slices ++ ;
 }
 buf_size2 = vc1_unescape_buffer ( buf , divider - buf , buf2 ) ;
 }
 else {
 buf_size2 = vc1_unescape_buffer ( buf , buf_size , buf2 ) ;
 }
 init_get_bits ( & s -> gb , buf2 , buf_size2 * 8 ) ;
 }
 else init_get_bits ( & s -> gb , buf , buf_size * 8 ) ;
 if ( v -> res_sprite ) {
 v -> new_sprite = ! get_bits1 ( & s -> gb ) ;
 v -> two_sprites = get_bits1 ( & s -> gb ) ;
 if ( avctx -> codec_id == AV_CODEC_ID_WMV3IMAGE || avctx -> codec_id == AV_CODEC_ID_VC1IMAGE ) {
 if ( v -> new_sprite ) {
 avctx -> width = avctx -> coded_width = v -> sprite_width ;
 avctx -> height = avctx -> coded_height = v -> sprite_height ;
 }
 else {
 goto image ;
 }
 }
 }
 if ( s -> context_initialized && ( s -> width != avctx -> coded_width || s -> height != avctx -> coded_height ) ) {
 ff_vc1_decode_end ( avctx ) ;
 }
 if ( ! s -> context_initialized ) {
 if ( ff_msmpeg4_decode_init ( avctx ) < 0 || ff_vc1_decode_init_alloc_tables ( v ) < 0 ) goto err ;
 s -> low_delay = ! avctx -> has_b_frames || v -> res_sprite ;
 if ( v -> profile == PROFILE_ADVANCED ) {
 s -> h_edge_pos = avctx -> coded_width ;
 s -> v_edge_pos = avctx -> coded_height ;
 }
 }
 if ( s -> current_picture_ptr == NULL || s -> current_picture_ptr -> f . data [ 0 ] ) {
 int i = ff_find_unused_picture ( s , 0 ) ;
 if ( i < 0 ) goto err ;
 s -> current_picture_ptr = & s -> picture [ i ] ;
 }
 v -> pic_header_flag = 0 ;
 if ( v -> profile < PROFILE_ADVANCED ) {
 if ( ff_vc1_parse_frame_header ( v , & s -> gb ) == - 1 ) {
 goto err ;
 }
 }
 else {
 if ( ff_vc1_parse_frame_header_adv ( v , & s -> gb ) == - 1 ) {
 goto err ;
 }
 }
 if ( ( avctx -> codec_id == AV_CODEC_ID_WMV3IMAGE || avctx -> codec_id == AV_CODEC_ID_VC1IMAGE ) && s -> pict_type != AV_PICTURE_TYPE_I ) {
 av_log ( v -> s . avctx , AV_LOG_ERROR , "Sprite decoder: expected I-frame\n" ) ;
 goto err ;
 }
 s -> current_picture_ptr -> f . repeat_pict = 0 ;
 if ( v -> rff ) {
 s -> current_picture_ptr -> f . repeat_pict = 1 ;
 }
 else if ( v -> rptfrm ) {
 s -> current_picture_ptr -> f . repeat_pict = v -> rptfrm * 2 ;
 }
 s -> current_picture . f . pict_type = s -> pict_type ;
 s -> current_picture . f . key_frame = s -> pict_type == AV_PICTURE_TYPE_I ;
 if ( s -> last_picture_ptr == NULL && ( s -> pict_type == AV_PICTURE_TYPE_B || s -> droppable ) ) {
 goto err ;
 }
 if ( ( avctx -> skip_frame >= AVDISCARD_NONREF && s -> pict_type == AV_PICTURE_TYPE_B ) || ( avctx -> skip_frame >= AVDISCARD_NONKEY && s -> pict_type != AV_PICTURE_TYPE_I ) || avctx -> skip_frame >= AVDISCARD_ALL ) {
 goto end ;
 }
 if ( s -> next_p_frame_damaged ) {
 if ( s -> pict_type == AV_PICTURE_TYPE_B ) goto end ;
 else s -> next_p_frame_damaged = 0 ;
 }
 if ( ff_MPV_frame_start ( s , avctx ) < 0 ) {
 goto err ;
 }
 s -> me . qpel_put = s -> dsp . put_qpel_pixels_tab ;
 s -> me . qpel_avg = s -> dsp . avg_qpel_pixels_tab ;
 if ( ( CONFIG_VC1_VDPAU_DECODER ) && s -> avctx -> codec -> capabilities & CODEC_CAP_HWACCEL_VDPAU ) ff_vdpau_vc1_decode_picture ( s , buf_start , ( buf + buf_size ) - buf_start ) ;
 else if ( avctx -> hwaccel ) {
 if ( avctx -> hwaccel -> start_frame ( avctx , buf , buf_size ) < 0 ) goto err ;
 if ( avctx -> hwaccel -> decode_slice ( avctx , buf_start , ( buf + buf_size ) - buf_start ) < 0 ) goto err ;
 if ( avctx -> hwaccel -> end_frame ( avctx ) < 0 ) goto err ;
 }
 else {
 ff_mpeg_er_frame_start ( s ) ;
 v -> bits = buf_size * 8 ;
 v -> end_mb_x = s -> mb_width ;
 if ( v -> field_mode ) {
 uint8_t * tmp [ 2 ] ;
 s -> current_picture . f . linesize [ 0 ] <<= 1 ;
 s -> current_picture . f . linesize [ 1 ] <<= 1 ;
 s -> current_picture . f . linesize [ 2 ] <<= 1 ;
 s -> linesize <<= 1 ;
 s -> uvlinesize <<= 1 ;
 tmp [ 0 ] = v -> mv_f_last [ 0 ] ;
 tmp [ 1 ] = v -> mv_f_last [ 1 ] ;
 v -> mv_f_last [ 0 ] = v -> mv_f_next [ 0 ] ;
 v -> mv_f_last [ 1 ] = v -> mv_f_next [ 1 ] ;
 v -> mv_f_next [ 0 ] = v -> mv_f [ 0 ] ;
 v -> mv_f_next [ 1 ] = v -> mv_f [ 1 ] ;
 v -> mv_f [ 0 ] = tmp [ 0 ] ;
 v -> mv_f [ 1 ] = tmp [ 1 ] ;
 }
 mb_height = s -> mb_height >> v -> field_mode ;
 for ( i = 0 ;
 i <= n_slices ;
 i ++ ) {
 if ( i > 0 && slices [ i - 1 ] . mby_start >= mb_height ) {
 if ( v -> field_mode <= 0 ) {
 av_log ( v -> s . avctx , AV_LOG_ERROR , "Slice %d starts beyond " "picture boundary (%d >= %d)\n" , i , slices [ i - 1 ] . mby_start , mb_height ) ;
 continue ;
 }
 v -> second_field = 1 ;
 v -> blocks_off = s -> mb_width * s -> mb_height << 1 ;
 v -> mb_off = s -> mb_stride * s -> mb_height >> 1 ;
 }
 else {
 v -> second_field = 0 ;
 v -> blocks_off = 0 ;
 v -> mb_off = 0 ;
 }
 if ( i ) {
 v -> pic_header_flag = 0 ;
 if ( v -> field_mode && i == n_slices1 + 2 ) {
 if ( ff_vc1_parse_frame_header_adv ( v , & s -> gb ) < 0 ) {
 av_log ( v -> s . avctx , AV_LOG_ERROR , "Field header damaged\n" ) ;
 continue ;
 }
 }
 else if ( get_bits1 ( & s -> gb ) ) {
 v -> pic_header_flag = 1 ;
 if ( ff_vc1_parse_frame_header_adv ( v , & s -> gb ) < 0 ) {
 av_log ( v -> s . avctx , AV_LOG_ERROR , "Slice header damaged\n" ) ;
 continue ;
 }
 }
 }
 s -> start_mb_y = ( i == 0 ) ? 0 : FFMAX ( 0 , slices [ i - 1 ] . mby_start % mb_height ) ;
 if ( ! v -> field_mode || v -> second_field ) s -> end_mb_y = ( i == n_slices ) ? mb_height : FFMIN ( mb_height , slices [ i ] . mby_start % mb_height ) ;
 else s -> end_mb_y = ( i <= n_slices1 + 1 ) ? mb_height : FFMIN ( mb_height , slices [ i ] . mby_start % mb_height ) ;
 ff_vc1_decode_blocks ( v ) ;
 if ( i != n_slices ) s -> gb = slices [ i ] . gb ;
 }
 if ( v -> field_mode ) {
 v -> second_field = 0 ;
 if ( s -> pict_type == AV_PICTURE_TYPE_B ) {
 memcpy ( v -> mv_f_base , v -> mv_f_next_base , 2 * ( s -> b8_stride * ( s -> mb_height * 2 + 1 ) + s -> mb_stride * ( s -> mb_height + 1 ) * 2 ) ) ;
 }
 s -> current_picture . f . linesize [ 0 ] >>= 1 ;
 s -> current_picture . f . linesize [ 1 ] >>= 1 ;
 s -> current_picture . f . linesize [ 2 ] >>= 1 ;
 s -> linesize >>= 1 ;
 s -> uvlinesize >>= 1 ;
 }
 av_dlog ( s -> avctx , "Consumed %i/%i bits\n" , get_bits_count ( & s -> gb ) , s -> gb . size_in_bits ) ;
 ff_er_frame_end ( & s -> er ) ;
 }
 ff_MPV_frame_end ( s ) ;
 if ( avctx -> codec_id == AV_CODEC_ID_WMV3IMAGE || avctx -> codec_id == AV_CODEC_ID_VC1IMAGE ) {
 image : avctx -> width = avctx -> coded_width = v -> output_width ;
 avctx -> height = avctx -> coded_height = v -> output_height ;
 if ( avctx -> skip_frame >= AVDISCARD_NONREF ) goto end ;
 # if CONFIG_WMV3IMAGE_DECODER || CONFIG_VC1IMAGE_DECODER if ( vc1_decode_sprites ( v , & s -> gb ) ) goto err ;
 # endif if ( ( ret = av_frame_ref ( pict , & v -> sprite_output_frame ) ) < 0 ) goto err ;
 * got_frame = 1 ;
 }
 else {
 if ( s -> pict_type == AV_PICTURE_TYPE_B || s -> low_delay ) {
 if ( ( ret = av_frame_ref ( pict , & s -> current_picture_ptr -> f ) ) < 0 ) goto err ;
 ff_print_debug_info ( s , s -> current_picture_ptr ) ;
 }
 else if ( s -> last_picture_ptr != NULL ) {
 if ( ( ret = av_frame_ref ( pict , & s -> last_picture_ptr -> f ) ) < 0 ) goto err ;
 ff_print_debug_info ( s , s -> last_picture_ptr ) ;
 }
 if ( s -> last_picture_ptr || s -> low_delay ) {
 * got_frame = 1 ;
 }
 }
 end : av_free ( buf2 ) ;
 for ( i = 0 ;
 i < n_slices ;
 i ++ ) av_free ( slices [ i ] . buf ) ;
 av_free ( slices ) ;
 return buf_size ;
 err : av_free ( buf2 ) ;
 for ( i = 0 ;
 i < n_slices ;
 i ++ ) av_free ( slices [ i ] . buf ) ;
 av_free ( slices ) ;
 return - 1 ;
 }