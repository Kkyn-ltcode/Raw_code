static void init_temporal_layer_context ( VP8_COMP * cpi , VP8_CONFIG * oxcf , const int layer , double prev_layer_framerate ) {
 LAYER_CONTEXT * lc = & cpi -> layer_context [ layer ] ;
 lc -> framerate = cpi -> output_framerate / cpi -> oxcf . rate_decimator [ layer ] ;
 lc -> target_bandwidth = cpi -> oxcf . target_bitrate [ layer ] * 1000 ;
 lc -> starting_buffer_level_in_ms = oxcf -> starting_buffer_level ;
 lc -> optimal_buffer_level_in_ms = oxcf -> optimal_buffer_level ;
 lc -> maximum_buffer_size_in_ms = oxcf -> maximum_buffer_size ;
 lc -> starting_buffer_level = rescale ( ( int ) ( oxcf -> starting_buffer_level ) , lc -> target_bandwidth , 1000 ) ;
 if ( oxcf -> optimal_buffer_level == 0 ) lc -> optimal_buffer_level = lc -> target_bandwidth / 8 ;
 else lc -> optimal_buffer_level = rescale ( ( int ) ( oxcf -> optimal_buffer_level ) , lc -> target_bandwidth , 1000 ) ;
 if ( oxcf -> maximum_buffer_size == 0 ) lc -> maximum_buffer_size = lc -> target_bandwidth / 8 ;
 else lc -> maximum_buffer_size = rescale ( ( int ) ( oxcf -> maximum_buffer_size ) , lc -> target_bandwidth , 1000 ) ;
 if ( layer > 0 ) lc -> avg_frame_size_for_layer = ( int ) ( ( cpi -> oxcf . target_bitrate [ layer ] - cpi -> oxcf . target_bitrate [ layer - 1 ] ) * 1000 / ( lc -> framerate - prev_layer_framerate ) ) ;
 lc -> active_worst_quality = cpi -> oxcf . worst_allowed_q ;
 lc -> active_best_quality = cpi -> oxcf . best_allowed_q ;
 lc -> avg_frame_qindex = cpi -> oxcf . worst_allowed_q ;
 lc -> buffer_level = lc -> starting_buffer_level ;
 lc -> bits_off_target = lc -> starting_buffer_level ;
 lc -> total_actual_bits = 0 ;
 lc -> ni_av_qi = 0 ;
 lc -> ni_tot_qi = 0 ;
 lc -> ni_frames = 0 ;
 lc -> rate_correction_factor = 1.0 ;
 lc -> key_frame_rate_correction_factor = 1.0 ;
 lc -> gf_rate_correction_factor = 1.0 ;
 lc -> inter_frame_target = 0 ;
 }