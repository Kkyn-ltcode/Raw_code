int main ( int argc , char * * argv ) {
 VpxVideoWriter * outfile [ VPX_TS_MAX_LAYERS ] = {
 NULL }
 ;
 vpx_codec_ctx_t codec ;
 vpx_codec_enc_cfg_t cfg ;
 int frame_cnt = 0 ;
 vpx_image_t raw ;
 vpx_codec_err_t res ;
 unsigned int width ;
 unsigned int height ;
 int speed ;
 int frame_avail ;
 int got_data ;
 int flags = 0 ;
 unsigned int i ;
 int pts = 0 ;
 int frame_duration = 1 ;
 int layering_mode = 0 ;
 int layer_flags [ VPX_TS_MAX_PERIODICITY ] = {
 0 }
 ;
 int flag_periodicity = 1 ;
 vpx_svc_layer_id_t layer_id = {
 0 , 0 }
 ;
 const VpxInterface * encoder = NULL ;
 FILE * infile = NULL ;
 struct RateControlMetrics rc ;
 int64_t cx_time = 0 ;
 exec_name = argv [ 0 ] ;
 if ( argc < 11 ) {
 die ( "Usage: %s <infile> <outfile> <codec_type(vp8/vp9)> <width> <height> " "<rate_num> <rate_den> <speed> <frame_drop_threshold> <mode> " "<Rate_0> ... <Rate_nlayers-1> \n" , argv [ 0 ] ) ;
 }
 encoder = get_vpx_encoder_by_name ( argv [ 3 ] ) ;
 if ( ! encoder ) die ( "Unsupported codec." ) ;
 printf ( "Using %s\n" , vpx_codec_iface_name ( encoder -> codec_interface ( ) ) ) ;
 width = strtol ( argv [ 4 ] , NULL , 0 ) ;
 height = strtol ( argv [ 5 ] , NULL , 0 ) ;
 if ( width < 16 || width % 2 || height < 16 || height % 2 ) {
 die ( "Invalid resolution: %d x %d" , width , height ) ;
 }
 layering_mode = strtol ( argv [ 10 ] , NULL , 0 ) ;
 if ( layering_mode < 0 || layering_mode > 12 ) {
 die ( "Invalid layering mode (0..12) %s" , argv [ 10 ] ) ;
 }
 if ( argc != 11 + mode_to_num_layers [ layering_mode ] ) {
 die ( "Invalid number of arguments" ) ;
 }
 if ( ! vpx_img_alloc ( & raw , VPX_IMG_FMT_I420 , width , height , 32 ) ) {
 die ( "Failed to allocate image" , width , height ) ;
 }
 res = vpx_codec_enc_config_default ( encoder -> codec_interface ( ) , & cfg , 0 ) ;
 if ( res ) {
 printf ( "Failed to get config: %s\n" , vpx_codec_err_to_string ( res ) ) ;
 return EXIT_FAILURE ;
 }
 cfg . g_w = width ;
 cfg . g_h = height ;
 cfg . g_timebase . num = strtol ( argv [ 6 ] , NULL , 0 ) ;
 cfg . g_timebase . den = strtol ( argv [ 7 ] , NULL , 0 ) ;
 speed = strtol ( argv [ 8 ] , NULL , 0 ) ;
 if ( speed < 0 ) {
 die ( "Invalid speed setting: must be positive" ) ;
 }
 for ( i = 11 ;
 ( int ) i < 11 + mode_to_num_layers [ layering_mode ] ;
 ++ i ) {
 cfg . ts_target_bitrate [ i - 11 ] = strtol ( argv [ i ] , NULL , 0 ) ;
 }
 cfg . rc_dropframe_thresh = strtol ( argv [ 9 ] , NULL , 0 ) ;
 cfg . rc_end_usage = VPX_CBR ;
 cfg . rc_resize_allowed = 0 ;
 cfg . rc_min_quantizer = 2 ;
 cfg . rc_max_quantizer = 56 ;
 cfg . rc_undershoot_pct = 50 ;
 cfg . rc_overshoot_pct = 50 ;
 cfg . rc_buf_initial_sz = 500 ;
 cfg . rc_buf_optimal_sz = 600 ;
 cfg . rc_buf_sz = 1000 ;
 cfg . g_error_resilient = 1 ;
 cfg . g_lag_in_frames = 0 ;
 cfg . kf_mode = VPX_KF_AUTO ;
 cfg . kf_min_dist = cfg . kf_max_dist = 3000 ;
 set_temporal_layer_pattern ( layering_mode , & cfg , layer_flags , & flag_periodicity ) ;
 set_rate_control_metrics ( & rc , & cfg ) ;
 cfg . rc_target_bitrate = cfg . ts_target_bitrate [ cfg . ts_number_layers - 1 ] ;
 if ( ! ( infile = fopen ( argv [ 1 ] , "rb" ) ) ) {
 die ( "Failed to open %s for reading" , argv [ 1 ] ) ;
 }
 for ( i = 0 ;
 i < cfg . ts_number_layers ;
 ++ i ) {
 char file_name [ PATH_MAX ] ;
 VpxVideoInfo info ;
 info . codec_fourcc = encoder -> fourcc ;
 info . frame_width = cfg . g_w ;
 info . frame_height = cfg . g_h ;
 info . time_base . numerator = cfg . g_timebase . num ;
 info . time_base . denominator = cfg . g_timebase . den ;
 snprintf ( file_name , sizeof ( file_name ) , "%s_%d.ivf" , argv [ 2 ] , i ) ;
 outfile [ i ] = vpx_video_writer_open ( file_name , kContainerIVF , & info ) ;
 if ( ! outfile [ i ] ) die ( "Failed to open %s for writing" , file_name ) ;
 assert ( outfile [ i ] != NULL ) ;
 }
 cfg . ss_number_layers = 1 ;
 if ( vpx_codec_enc_init ( & codec , encoder -> codec_interface ( ) , & cfg , 0 ) ) die_codec ( & codec , "Failed to initialize encoder" ) ;
 if ( strncmp ( encoder -> name , "vp8" , 3 ) == 0 ) {
 vpx_codec_control ( & codec , VP8E_SET_CPUUSED , - speed ) ;
 vpx_codec_control ( & codec , VP8E_SET_NOISE_SENSITIVITY , kDenoiserOnYOnly ) ;
 }
 else if ( strncmp ( encoder -> name , "vp9" , 3 ) == 0 ) {
 vpx_codec_control ( & codec , VP8E_SET_CPUUSED , speed ) ;
 vpx_codec_control ( & codec , VP9E_SET_AQ_MODE , 3 ) ;
 vpx_codec_control ( & codec , VP9E_SET_FRAME_PERIODIC_BOOST , 0 ) ;
 vpx_codec_control ( & codec , VP8E_SET_NOISE_SENSITIVITY , 0 ) ;
 if ( vpx_codec_control ( & codec , VP9E_SET_SVC , 1 ) ) {
 die_codec ( & codec , "Failed to set SVC" ) ;
 }
 }
 vpx_codec_control ( & codec , VP8E_SET_STATIC_THRESHOLD , 1 ) ;
 vpx_codec_control ( & codec , VP8E_SET_TOKEN_PARTITIONS , 1 ) ;
 {
 const int max_intra_size_pct = 200 ;
 vpx_codec_control ( & codec , VP8E_SET_MAX_INTRA_BITRATE_PCT , max_intra_size_pct ) ;
 }
 frame_avail = 1 ;
 while ( frame_avail || got_data ) {
 struct vpx_usec_timer timer ;
 vpx_codec_iter_t iter = NULL ;
 const vpx_codec_cx_pkt_t * pkt ;
 layer_id . spatial_layer_id = 0 ;
 layer_id . temporal_layer_id = cfg . ts_layer_id [ frame_cnt % cfg . ts_periodicity ] ;
 if ( strncmp ( encoder -> name , "vp9" , 3 ) == 0 ) {
 vpx_codec_control ( & codec , VP9E_SET_SVC_LAYER_ID , & layer_id ) ;
 }
 flags = layer_flags [ frame_cnt % flag_periodicity ] ;
 frame_avail = vpx_img_read ( & raw , infile ) ;
 if ( frame_avail ) ++ rc . layer_input_frames [ layer_id . temporal_layer_id ] ;
 vpx_usec_timer_start ( & timer ) ;
 if ( vpx_codec_encode ( & codec , frame_avail ? & raw : NULL , pts , 1 , flags , VPX_DL_REALTIME ) ) {
 die_codec ( & codec , "Failed to encode frame" ) ;
 }
 vpx_usec_timer_mark ( & timer ) ;
 cx_time += vpx_usec_timer_elapsed ( & timer ) ;
 if ( layering_mode != 7 ) {
 layer_flags [ 0 ] &= ~ VPX_EFLAG_FORCE_KF ;
 }
 got_data = 0 ;
 while ( ( pkt = vpx_codec_get_cx_data ( & codec , & iter ) ) ) {
 got_data = 1 ;
 switch ( pkt -> kind ) {
 case VPX_CODEC_CX_FRAME_PKT : for ( i = cfg . ts_layer_id [ frame_cnt % cfg . ts_periodicity ] ;
 i < cfg . ts_number_layers ;
 ++ i ) {
 vpx_video_writer_write_frame ( outfile [ i ] , pkt -> data . frame . buf , pkt -> data . frame . sz , pts ) ;
 ++ rc . layer_tot_enc_frames [ i ] ;
 rc . layer_encoding_bitrate [ i ] += 8.0 * pkt -> data . frame . sz ;
 if ( i == cfg . ts_layer_id [ frame_cnt % cfg . ts_periodicity ] && ! ( pkt -> data . frame . flags & VPX_FRAME_IS_KEY ) ) {
 rc . layer_avg_frame_size [ i ] += 8.0 * pkt -> data . frame . sz ;
 rc . layer_avg_rate_mismatch [ i ] += fabs ( 8.0 * pkt -> data . frame . sz - rc . layer_pfb [ i ] ) / rc . layer_pfb [ i ] ;
 ++ rc . layer_enc_frames [ i ] ;
 }
 }
 break ;
 default : break ;
 }
 }
 ++ frame_cnt ;
 pts += frame_duration ;
 }
 fclose ( infile ) ;
 printout_rate_control_summary ( & rc , & cfg , frame_cnt ) ;
 printf ( "\n" ) ;
 printf ( "Frame cnt and encoding time/FPS stats for encoding: %d %f %f \n" , frame_cnt , * ( float ) cx_time / ( double ) ( frame_cnt * 1000000 ) , * ( double ) frame_cnt / ( double ) cx_time ) ;
 if ( vpx_codec_destroy ( & codec ) ) die_codec ( & codec , "Failed to destroy codec" ) ;
 for ( i = 0 ;
 i < cfg . ts_number_layers ;
 ++ i ) vpx_video_writer_close ( outfile [ i ] ) ;
 vpx_img_free ( & raw ) ;
 return EXIT_SUCCESS ;
 }