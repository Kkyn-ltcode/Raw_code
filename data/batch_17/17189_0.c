void vp8_denoiser_denoise_mb ( VP8_DENOISER * denoiser , MACROBLOCK * x , unsigned int best_sse , unsigned int zero_mv_sse , int recon_yoffset , int recon_uvoffset , loop_filter_info_n * lfi_n , int mb_row , int mb_col , int block_index ) {
 int mv_row ;
 int mv_col ;
 unsigned int motion_threshold ;
 unsigned int motion_magnitude2 ;
 unsigned int sse_thresh ;
 int sse_diff_thresh = 0 ;
 int apply_spatial_loop_filter = 1 ;
 MV_REFERENCE_FRAME frame = x -> best_reference_frame ;
 MV_REFERENCE_FRAME zero_frame = x -> best_zeromv_reference_frame ;
 enum vp8_denoiser_decision decision = FILTER_BLOCK ;
 enum vp8_denoiser_decision decision_u = COPY_BLOCK ;
 enum vp8_denoiser_decision decision_v = COPY_BLOCK ;
 if ( zero_frame ) {
 YV12_BUFFER_CONFIG * src = & denoiser -> yv12_running_avg [ frame ] ;
 YV12_BUFFER_CONFIG * dst = & denoiser -> yv12_mc_running_avg ;
 YV12_BUFFER_CONFIG saved_pre , saved_dst ;
 MB_MODE_INFO saved_mbmi ;
 MACROBLOCKD * filter_xd = & x -> e_mbd ;
 MB_MODE_INFO * mbmi = & filter_xd -> mode_info_context -> mbmi ;
 int sse_diff = 0 ;
 const int zero_bias = denoiser -> denoise_pars . denoise_mv_bias ;
 zero_mv_sse = ( unsigned int ) ( ( int64_t ) zero_mv_sse * zero_bias / 100 ) ;
 sse_diff = zero_mv_sse - best_sse ;
 saved_mbmi = * mbmi ;
 mbmi -> ref_frame = x -> best_reference_frame ;
 mbmi -> mode = x -> best_sse_inter_mode ;
 mbmi -> mv = x -> best_sse_mv ;
 mbmi -> need_to_clamp_mvs = x -> need_to_clamp_best_mvs ;
 mv_col = x -> best_sse_mv . as_mv . col ;
 mv_row = x -> best_sse_mv . as_mv . row ;
 if ( ( unsigned int ) ( mv_row * mv_row + mv_col * mv_col ) <= NOISE_MOTION_THRESHOLD ) sse_diff_thresh = ( int ) SSE_DIFF_THRESHOLD ;
 if ( frame == INTRA_FRAME || sse_diff <= sse_diff_thresh ) {
 mbmi -> ref_frame = x -> best_zeromv_reference_frame ;
 src = & denoiser -> yv12_running_avg [ zero_frame ] ;
 mbmi -> mode = ZEROMV ;
 mbmi -> mv . as_int = 0 ;
 x -> best_sse_inter_mode = ZEROMV ;
 x -> best_sse_mv . as_int = 0 ;
 best_sse = zero_mv_sse ;
 }
 saved_pre = filter_xd -> pre ;
 saved_dst = filter_xd -> dst ;
 filter_xd -> pre . y_buffer = src -> y_buffer + recon_yoffset ;
 filter_xd -> pre . u_buffer = src -> u_buffer + recon_uvoffset ;
 filter_xd -> pre . v_buffer = src -> v_buffer + recon_uvoffset ;
 filter_xd -> dst . y_buffer = dst -> y_buffer + recon_yoffset ;
 filter_xd -> dst . u_buffer = dst -> u_buffer + recon_uvoffset ;
 filter_xd -> dst . v_buffer = dst -> v_buffer + recon_uvoffset ;
 if ( ! x -> skip ) {
 vp8_build_inter_predictors_mb ( filter_xd ) ;
 }
 else {
 vp8_build_inter16x16_predictors_mb ( filter_xd , filter_xd -> dst . y_buffer , filter_xd -> dst . u_buffer , filter_xd -> dst . v_buffer , filter_xd -> dst . y_stride , filter_xd -> dst . uv_stride ) ;
 }
 filter_xd -> pre = saved_pre ;
 filter_xd -> dst = saved_dst ;
 * mbmi = saved_mbmi ;
 }
 mv_row = x -> best_sse_mv . as_mv . row ;
 mv_col = x -> best_sse_mv . as_mv . col ;
 motion_magnitude2 = mv_row * mv_row + mv_col * mv_col ;
 motion_threshold = denoiser -> denoise_pars . scale_motion_thresh * NOISE_MOTION_THRESHOLD ;
 if ( motion_magnitude2 < denoiser -> denoise_pars . scale_increase_filter * NOISE_MOTION_THRESHOLD ) x -> increase_denoising = 1 ;
 sse_thresh = denoiser -> denoise_pars . scale_sse_thresh * SSE_THRESHOLD ;
 if ( x -> increase_denoising ) sse_thresh = denoiser -> denoise_pars . scale_sse_thresh * SSE_THRESHOLD_HIGH ;
 if ( best_sse > sse_thresh || motion_magnitude2 > motion_threshold ) decision = COPY_BLOCK ;
 if ( decision == FILTER_BLOCK ) {
 unsigned char * mc_running_avg_y = denoiser -> yv12_mc_running_avg . y_buffer + recon_yoffset ;
 int mc_avg_y_stride = denoiser -> yv12_mc_running_avg . y_stride ;
 unsigned char * running_avg_y = denoiser -> yv12_running_avg [ INTRA_FRAME ] . y_buffer + recon_yoffset ;
 int avg_y_stride = denoiser -> yv12_running_avg [ INTRA_FRAME ] . y_stride ;
 decision = vp8_denoiser_filter ( mc_running_avg_y , mc_avg_y_stride , running_avg_y , avg_y_stride , x -> thismb , 16 , motion_magnitude2 , x -> increase_denoising ) ;
 denoiser -> denoise_state [ block_index ] = motion_magnitude2 > 0 ? kFilterNonZeroMV : kFilterZeroMV ;
 if ( denoiser -> denoiser_mode != kDenoiserOnYOnly && motion_magnitude2 == 0 && decision == FILTER_BLOCK ) {
 unsigned char * mc_running_avg_u = denoiser -> yv12_mc_running_avg . u_buffer + recon_uvoffset ;
 unsigned char * running_avg_u = denoiser -> yv12_running_avg [ INTRA_FRAME ] . u_buffer + recon_uvoffset ;
 unsigned char * mc_running_avg_v = denoiser -> yv12_mc_running_avg . v_buffer + recon_uvoffset ;
 unsigned char * running_avg_v = denoiser -> yv12_running_avg [ INTRA_FRAME ] . v_buffer + recon_uvoffset ;
 int mc_avg_uv_stride = denoiser -> yv12_mc_running_avg . uv_stride ;
 int avg_uv_stride = denoiser -> yv12_running_avg [ INTRA_FRAME ] . uv_stride ;
 int signal_stride = x -> block [ 16 ] . src_stride ;
 decision_u = vp8_denoiser_filter_uv ( mc_running_avg_u , mc_avg_uv_stride , running_avg_u , avg_uv_stride , x -> block [ 16 ] . src + * x -> block [ 16 ] . base_src , signal_stride , motion_magnitude2 , 0 ) ;
 decision_v = vp8_denoiser_filter_uv ( mc_running_avg_v , mc_avg_uv_stride , running_avg_v , avg_uv_stride , x -> block [ 20 ] . src + * x -> block [ 20 ] . base_src , signal_stride , motion_magnitude2 , 0 ) ;
 }
 }
 if ( decision == COPY_BLOCK ) {
 vp8_copy_mem16x16 ( x -> thismb , 16 , denoiser -> yv12_running_avg [ INTRA_FRAME ] . y_buffer + recon_yoffset , denoiser -> yv12_running_avg [ INTRA_FRAME ] . y_stride ) ;
 denoiser -> denoise_state [ block_index ] = kNoFilter ;
 }
 if ( denoiser -> denoiser_mode != kDenoiserOnYOnly ) {
 if ( decision_u == COPY_BLOCK ) {
 vp8_copy_mem8x8 ( x -> block [ 16 ] . src + * x -> block [ 16 ] . base_src , x -> block [ 16 ] . src_stride , denoiser -> yv12_running_avg [ INTRA_FRAME ] . u_buffer + recon_uvoffset , denoiser -> yv12_running_avg [ INTRA_FRAME ] . uv_stride ) ;
 }
 if ( decision_v == COPY_BLOCK ) {
 vp8_copy_mem8x8 ( x -> block [ 20 ] . src + * x -> block [ 20 ] . base_src , x -> block [ 16 ] . src_stride , denoiser -> yv12_running_avg [ INTRA_FRAME ] . v_buffer + recon_uvoffset , denoiser -> yv12_running_avg [ INTRA_FRAME ] . uv_stride ) ;
 }
 }
 if ( apply_spatial_loop_filter ) {
 loop_filter_info lfi ;
 int apply_filter_col = 0 ;
 int apply_filter_row = 0 ;
 int apply_filter = 0 ;
 int y_stride = denoiser -> yv12_running_avg [ INTRA_FRAME ] . y_stride ;
 int uv_stride = denoiser -> yv12_running_avg [ INTRA_FRAME ] . uv_stride ;
 int filter_level = 32 ;
 int hev_index = lfi_n -> hev_thr_lut [ INTER_FRAME ] [ filter_level ] ;
 lfi . mblim = lfi_n -> mblim [ filter_level ] ;
 lfi . blim = lfi_n -> blim [ filter_level ] ;
 lfi . lim = lfi_n -> lim [ filter_level ] ;
 lfi . hev_thr = lfi_n -> hev_thr [ hev_index ] ;
 if ( mb_col > 0 ) {
 apply_filter_col = ! ( ( denoiser -> denoise_state [ block_index ] == denoiser -> denoise_state [ block_index - 1 ] ) && denoiser -> denoise_state [ block_index ] != kFilterNonZeroMV ) ;
 if ( apply_filter_col ) {
 apply_filter = 1 ;
 vp8_loop_filter_mbv ( denoiser -> yv12_running_avg [ INTRA_FRAME ] . y_buffer + recon_yoffset , NULL , NULL , y_stride , uv_stride , & lfi ) ;
 }
 }
 if ( mb_row > 0 ) {
 apply_filter_row = ! ( ( denoiser -> denoise_state [ block_index ] == denoiser -> denoise_state [ block_index - denoiser -> num_mb_cols ] ) && denoiser -> denoise_state [ block_index ] != kFilterNonZeroMV ) ;
 if ( apply_filter_row ) {
 apply_filter = 1 ;
 vp8_loop_filter_mbh ( denoiser -> yv12_running_avg [ INTRA_FRAME ] . y_buffer + recon_yoffset , NULL , NULL , y_stride , uv_stride , & lfi ) ;
 }
 }
 if ( apply_filter ) {
 vp8_copy_mem16x16 ( denoiser -> yv12_running_avg [ INTRA_FRAME ] . y_buffer + recon_yoffset , y_stride , x -> thismb , 16 ) ;
 }
 }
 }