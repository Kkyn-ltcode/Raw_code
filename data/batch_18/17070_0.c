static void update_layer_contexts ( VP8_COMP * cpi ) {
 VP8_CONFIG * oxcf = & cpi -> oxcf ;
 if ( oxcf -> number_of_layers > 1 ) {
 unsigned int i ;
 double prev_layer_framerate = 0 ;
 assert ( oxcf -> number_of_layers <= VPX_TS_MAX_LAYERS ) ;
 for ( i = 0 ;
 i < oxcf -> number_of_layers && i < VPX_TS_MAX_LAYERS ;
 ++ i ) {
 LAYER_CONTEXT * lc = & cpi -> layer_context [ i ] ;
 lc -> framerate = cpi -> ref_framerate / oxcf -> rate_decimator [ i ] ;
 lc -> target_bandwidth = oxcf -> target_bitrate [ i ] * 1000 ;
 lc -> starting_buffer_level = rescale ( ( int ) oxcf -> starting_buffer_level_in_ms , lc -> target_bandwidth , 1000 ) ;
 if ( oxcf -> optimal_buffer_level == 0 ) lc -> optimal_buffer_level = lc -> target_bandwidth / 8 ;
 else lc -> optimal_buffer_level = rescale ( ( int ) oxcf -> optimal_buffer_level_in_ms , lc -> target_bandwidth , 1000 ) ;
 if ( oxcf -> maximum_buffer_size == 0 ) lc -> maximum_buffer_size = lc -> target_bandwidth / 8 ;
 else lc -> maximum_buffer_size = rescale ( ( int ) oxcf -> maximum_buffer_size_in_ms , lc -> target_bandwidth , 1000 ) ;
 if ( i > 0 ) lc -> avg_frame_size_for_layer = ( int ) ( ( oxcf -> target_bitrate [ i ] - oxcf -> target_bitrate [ i - 1 ] ) * 1000 / ( lc -> framerate - prev_layer_framerate ) ) ;
 prev_layer_framerate = lc -> framerate ;
 }
 }
 }