int ff_MPV_frame_start ( MpegEncContext * s , AVCodecContext * avctx ) {
 int i , ret ;
 Picture * pic ;
 s -> mb_skipped = 0 ;
 if ( s -> out_format != FMT_H264 || s -> codec_id == AV_CODEC_ID_SVQ3 ) {
 if ( s -> pict_type != AV_PICTURE_TYPE_B && s -> last_picture_ptr && s -> last_picture_ptr != s -> next_picture_ptr && s -> last_picture_ptr -> f . data [ 0 ] ) {
 ff_mpeg_unref_picture ( s , s -> last_picture_ptr ) ;
 }
 if ( ! s -> encoding ) {
 for ( i = 0 ;
 i < MAX_PICTURE_COUNT ;
 i ++ ) {
 if ( & s -> picture [ i ] != s -> last_picture_ptr && & s -> picture [ i ] != s -> next_picture_ptr && s -> picture [ i ] . reference && ! s -> picture [ i ] . needs_realloc ) {
 if ( ! ( avctx -> active_thread_type & FF_THREAD_FRAME ) ) av_log ( avctx , AV_LOG_ERROR , "releasing zombie picture\n" ) ;
 ff_mpeg_unref_picture ( s , & s -> picture [ i ] ) ;
 }
 }
 }
 }
 if ( ! s -> encoding ) {
 ff_release_unused_pictures ( s , 1 ) ;
 if ( s -> current_picture_ptr && s -> current_picture_ptr -> f . data [ 0 ] == NULL ) {
 pic = s -> current_picture_ptr ;
 }
 else {
 i = ff_find_unused_picture ( s , 0 ) ;
 if ( i < 0 ) {
 av_log ( s -> avctx , AV_LOG_ERROR , "no frame buffer available\n" ) ;
 return i ;
 }
 pic = & s -> picture [ i ] ;
 }
 pic -> reference = 0 ;
 if ( ! s -> droppable ) {
 if ( s -> codec_id == AV_CODEC_ID_H264 ) pic -> reference = s -> picture_structure ;
 else if ( s -> pict_type != AV_PICTURE_TYPE_B ) pic -> reference = 3 ;
 }
 pic -> f . coded_picture_number = s -> coded_picture_number ++ ;
 if ( ff_alloc_picture ( s , pic , 0 ) < 0 ) return - 1 ;
 s -> current_picture_ptr = pic ;
 s -> current_picture_ptr -> f . top_field_first = s -> top_field_first ;
 if ( s -> codec_id == AV_CODEC_ID_MPEG1VIDEO || s -> codec_id == AV_CODEC_ID_MPEG2VIDEO ) {
 if ( s -> picture_structure != PICT_FRAME ) s -> current_picture_ptr -> f . top_field_first = ( s -> picture_structure == PICT_TOP_FIELD ) == s -> first_field ;
 }
 s -> current_picture_ptr -> f . interlaced_frame = ! s -> progressive_frame && ! s -> progressive_sequence ;
 s -> current_picture_ptr -> field_picture = s -> picture_structure != PICT_FRAME ;
 }
 s -> current_picture_ptr -> f . pict_type = s -> pict_type ;
 s -> current_picture_ptr -> f . key_frame = s -> pict_type == AV_PICTURE_TYPE_I ;
 ff_mpeg_unref_picture ( s , & s -> current_picture ) ;
 if ( ( ret = ff_mpeg_ref_picture ( s , & s -> current_picture , s -> current_picture_ptr ) ) < 0 ) return ret ;
 if ( s -> codec_id != AV_CODEC_ID_H264 && s -> pict_type != AV_PICTURE_TYPE_B ) {
 s -> last_picture_ptr = s -> next_picture_ptr ;
 if ( ! s -> droppable ) s -> next_picture_ptr = s -> current_picture_ptr ;
 }
 av_dlog ( s -> avctx , "L%p N%p C%p L%p N%p C%p type:%d drop:%d\n" , s -> last_picture_ptr , s -> next_picture_ptr , s -> current_picture_ptr , s -> last_picture_ptr ? s -> last_picture_ptr -> f . data [ 0 ] : NULL , s -> next_picture_ptr ? s -> next_picture_ptr -> f . data [ 0 ] : NULL , s -> current_picture_ptr ? s -> current_picture_ptr -> f . data [ 0 ] : NULL , s -> pict_type , s -> droppable ) ;
 if ( s -> codec_id != AV_CODEC_ID_H264 ) {
 if ( ( s -> last_picture_ptr == NULL || s -> last_picture_ptr -> f . data [ 0 ] == NULL ) && ( s -> pict_type != AV_PICTURE_TYPE_I || s -> picture_structure != PICT_FRAME ) ) {
 int h_chroma_shift , v_chroma_shift ;
 av_pix_fmt_get_chroma_sub_sample ( s -> avctx -> pix_fmt , & h_chroma_shift , & v_chroma_shift ) ;
 if ( s -> pict_type != AV_PICTURE_TYPE_I ) av_log ( avctx , AV_LOG_ERROR , "warning: first frame is no keyframe\n" ) ;
 else if ( s -> picture_structure != PICT_FRAME ) av_log ( avctx , AV_LOG_INFO , "allocate dummy last picture for field based first keyframe\n" ) ;
 i = ff_find_unused_picture ( s , 0 ) ;
 if ( i < 0 ) {
 av_log ( s -> avctx , AV_LOG_ERROR , "no frame buffer available\n" ) ;
 return i ;
 }
 s -> last_picture_ptr = & s -> picture [ i ] ;
 if ( ff_alloc_picture ( s , s -> last_picture_ptr , 0 ) < 0 ) {
 s -> last_picture_ptr = NULL ;
 return - 1 ;
 }
 memset ( s -> last_picture_ptr -> f . data [ 0 ] , 0 , avctx -> height * s -> last_picture_ptr -> f . linesize [ 0 ] ) ;
 memset ( s -> last_picture_ptr -> f . data [ 1 ] , 0x80 , ( avctx -> height >> v_chroma_shift ) * s -> last_picture_ptr -> f . linesize [ 1 ] ) ;
 memset ( s -> last_picture_ptr -> f . data [ 2 ] , 0x80 , ( avctx -> height >> v_chroma_shift ) * s -> last_picture_ptr -> f . linesize [ 2 ] ) ;
 ff_thread_report_progress ( & s -> last_picture_ptr -> tf , INT_MAX , 0 ) ;
 ff_thread_report_progress ( & s -> last_picture_ptr -> tf , INT_MAX , 1 ) ;
 }
 if ( ( s -> next_picture_ptr == NULL || s -> next_picture_ptr -> f . data [ 0 ] == NULL ) && s -> pict_type == AV_PICTURE_TYPE_B ) {
 i = ff_find_unused_picture ( s , 0 ) ;
 if ( i < 0 ) {
 av_log ( s -> avctx , AV_LOG_ERROR , "no frame buffer available\n" ) ;
 return i ;
 }
 s -> next_picture_ptr = & s -> picture [ i ] ;
 if ( ff_alloc_picture ( s , s -> next_picture_ptr , 0 ) < 0 ) {
 s -> next_picture_ptr = NULL ;
 return - 1 ;
 }
 ff_thread_report_progress ( & s -> next_picture_ptr -> tf , INT_MAX , 0 ) ;
 ff_thread_report_progress ( & s -> next_picture_ptr -> tf , INT_MAX , 1 ) ;
 }
 }
 if ( s -> codec_id != AV_CODEC_ID_H264 ) {
 if ( s -> last_picture_ptr ) {
 ff_mpeg_unref_picture ( s , & s -> last_picture ) ;
 if ( s -> last_picture_ptr -> f . data [ 0 ] && ( ret = ff_mpeg_ref_picture ( s , & s -> last_picture , s -> last_picture_ptr ) ) < 0 ) return ret ;
 }
 if ( s -> next_picture_ptr ) {
 ff_mpeg_unref_picture ( s , & s -> next_picture ) ;
 if ( s -> next_picture_ptr -> f . data [ 0 ] && ( ret = ff_mpeg_ref_picture ( s , & s -> next_picture , s -> next_picture_ptr ) ) < 0 ) return ret ;
 }
 assert ( s -> pict_type == AV_PICTURE_TYPE_I || ( s -> last_picture_ptr && s -> last_picture_ptr -> f . data [ 0 ] ) ) ;
 }
 if ( s -> picture_structure != PICT_FRAME && s -> out_format != FMT_H264 ) {
 int i ;
 for ( i = 0 ;
 i < 4 ;
 i ++ ) {
 if ( s -> picture_structure == PICT_BOTTOM_FIELD ) {
 s -> current_picture . f . data [ i ] += s -> current_picture . f . linesize [ i ] ;
 }
 s -> current_picture . f . linesize [ i ] *= 2 ;
 s -> last_picture . f . linesize [ i ] *= 2 ;
 s -> next_picture . f . linesize [ i ] *= 2 ;
 }
 }
 s -> err_recognition = avctx -> err_recognition ;
 if ( s -> mpeg_quant || s -> codec_id == AV_CODEC_ID_MPEG2VIDEO ) {
 s -> dct_unquantize_intra = s -> dct_unquantize_mpeg2_intra ;
 s -> dct_unquantize_inter = s -> dct_unquantize_mpeg2_inter ;
 }
 else if ( s -> out_format == FMT_H263 || s -> out_format == FMT_H261 ) {
 s -> dct_unquantize_intra = s -> dct_unquantize_h263_intra ;
 s -> dct_unquantize_inter = s -> dct_unquantize_h263_inter ;
 }
 else {
 s -> dct_unquantize_intra = s -> dct_unquantize_mpeg1_intra ;
 s -> dct_unquantize_inter = s -> dct_unquantize_mpeg1_inter ;
 }
 if ( s -> dct_error_sum ) {
 assert ( s -> avctx -> noise_reduction && s -> encoding ) ;
 update_noise_reduction ( s ) ;
 }
 if ( CONFIG_MPEG_XVMC_DECODER && s -> avctx -> xvmc_acceleration ) return ff_xvmc_field_start ( s , avctx ) ;
 return 0 ;
 }