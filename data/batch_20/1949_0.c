static int vdpau_h264_start_frame ( AVCodecContext * avctx , const uint8_t * buffer , uint32_t size ) {
 H264Context * const h = avctx -> priv_data ;
 AVVDPAUContext * hwctx = avctx -> hwaccel_context ;
 VdpPictureInfoH264 * info = & hwctx -> info . h264 ;
 Picture * pic = h -> cur_pic_ptr ;
 info -> slice_count = 0 ;
 info -> field_order_cnt [ 0 ] = h264_foc ( pic -> field_poc [ 0 ] ) ;
 info -> field_order_cnt [ 1 ] = h264_foc ( pic -> field_poc [ 1 ] ) ;
 info -> is_reference = h -> nal_ref_idc != 0 ;
 info -> frame_num = h -> frame_num ;
 info -> field_pic_flag = h -> picture_structure != PICT_FRAME ;
 info -> bottom_field_flag = h -> picture_structure == PICT_BOTTOM_FIELD ;
 info -> num_ref_frames = h -> sps . ref_frame_count ;
 info -> mb_adaptive_frame_field_flag = h -> sps . mb_aff && ! info -> field_pic_flag ;
 info -> constrained_intra_pred_flag = h -> pps . constrained_intra_pred ;
 info -> weighted_pred_flag = h -> pps . weighted_pred ;
 info -> weighted_bipred_idc = h -> pps . weighted_bipred_idc ;
 info -> frame_mbs_only_flag = h -> sps . frame_mbs_only_flag ;
 info -> transform_8x8_mode_flag = h -> pps . transform_8x8_mode ;
 info -> chroma_qp_index_offset = h -> pps . chroma_qp_index_offset [ 0 ] ;
 info -> second_chroma_qp_index_offset = h -> pps . chroma_qp_index_offset [ 1 ] ;
 info -> pic_init_qp_minus26 = h -> pps . init_qp - 26 ;
 info -> num_ref_idx_l0_active_minus1 = h -> pps . ref_count [ 0 ] - 1 ;
 info -> num_ref_idx_l1_active_minus1 = h -> pps . ref_count [ 1 ] - 1 ;
 info -> log2_max_frame_num_minus4 = h -> sps . log2_max_frame_num - 4 ;
 info -> pic_order_cnt_type = h -> sps . poc_type ;
 info -> log2_max_pic_order_cnt_lsb_minus4 = h -> sps . poc_type ? 0 : h -> sps . log2_max_poc_lsb - 4 ;
 info -> delta_pic_order_always_zero_flag = h -> sps . delta_pic_order_always_zero_flag ;
 info -> direct_8x8_inference_flag = h -> sps . direct_8x8_inference_flag ;
 info -> entropy_coding_mode_flag = h -> pps . cabac ;
 info -> pic_order_present_flag = h -> pps . pic_order_present ;
 info -> deblocking_filter_control_present_flag = h -> pps . deblocking_filter_parameters_present ;
 info -> redundant_pic_cnt_present_flag = h -> pps . redundant_pic_cnt_present ;
 memcpy ( info -> scaling_lists_4x4 , h -> pps . scaling_matrix4 , sizeof ( info -> scaling_lists_4x4 ) ) ;
 memcpy ( info -> scaling_lists_8x8 [ 0 ] , h -> pps . scaling_matrix8 [ 0 ] , sizeof ( info -> scaling_lists_8x8 [ 0 ] ) ) ;
 memcpy ( info -> scaling_lists_8x8 [ 1 ] , h -> pps . scaling_matrix8 [ 3 ] , sizeof ( info -> scaling_lists_8x8 [ 1 ] ) ) ;
 vdpau_h264_set_reference_frames ( avctx ) ;
 return ff_vdpau_common_start_frame ( avctx , buffer , size ) ;
 }