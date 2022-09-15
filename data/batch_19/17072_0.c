static void save_layer_context ( VP8_COMP * cpi ) {
 LAYER_CONTEXT * lc = & cpi -> layer_context [ cpi -> current_layer ] ;
 lc -> target_bandwidth = cpi -> target_bandwidth ;
 lc -> starting_buffer_level = cpi -> oxcf . starting_buffer_level ;
 lc -> optimal_buffer_level = cpi -> oxcf . optimal_buffer_level ;
 lc -> maximum_buffer_size = cpi -> oxcf . maximum_buffer_size ;
 lc -> starting_buffer_level_in_ms = cpi -> oxcf . starting_buffer_level_in_ms ;
 lc -> optimal_buffer_level_in_ms = cpi -> oxcf . optimal_buffer_level_in_ms ;
 lc -> maximum_buffer_size_in_ms = cpi -> oxcf . maximum_buffer_size_in_ms ;
 lc -> buffer_level = cpi -> buffer_level ;
 lc -> bits_off_target = cpi -> bits_off_target ;
 lc -> total_actual_bits = cpi -> total_actual_bits ;
 lc -> worst_quality = cpi -> worst_quality ;
 lc -> active_worst_quality = cpi -> active_worst_quality ;
 lc -> best_quality = cpi -> best_quality ;
 lc -> active_best_quality = cpi -> active_best_quality ;
 lc -> ni_av_qi = cpi -> ni_av_qi ;
 lc -> ni_tot_qi = cpi -> ni_tot_qi ;
 lc -> ni_frames = cpi -> ni_frames ;
 lc -> avg_frame_qindex = cpi -> avg_frame_qindex ;
 lc -> rate_correction_factor = cpi -> rate_correction_factor ;
 lc -> key_frame_rate_correction_factor = cpi -> key_frame_rate_correction_factor ;
 lc -> gf_rate_correction_factor = cpi -> gf_rate_correction_factor ;
 lc -> zbin_over_quant = cpi -> mb . zbin_over_quant ;
 lc -> inter_frame_target = cpi -> inter_frame_target ;
 lc -> total_byte_count = cpi -> total_byte_count ;
 lc -> filter_level = cpi -> common . filter_level ;
 lc -> last_frame_percent_intra = cpi -> last_frame_percent_intra ;
 memcpy ( lc -> count_mb_ref_frame_usage , cpi -> mb . count_mb_ref_frame_usage , sizeof ( cpi -> mb . count_mb_ref_frame_usage ) ) ;
 }