void vp8_new_framerate ( VP8_COMP * cpi , double framerate ) {
 if ( framerate < .1 ) framerate = 30 ;
 cpi -> framerate = framerate ;
 cpi -> output_framerate = framerate ;
 cpi -> per_frame_bandwidth = ( int ) ( cpi -> oxcf . target_bandwidth / cpi -> output_framerate ) ;
 cpi -> av_per_frame_bandwidth = cpi -> per_frame_bandwidth ;
 cpi -> min_frame_bandwidth = ( int ) ( cpi -> av_per_frame_bandwidth * cpi -> oxcf . two_pass_vbrmin_section / 100 ) ;
 cpi -> max_gf_interval = ( ( int ) ( cpi -> output_framerate / 2.0 ) + 2 ) ;
 if ( cpi -> max_gf_interval < 12 ) cpi -> max_gf_interval = 12 ;
 cpi -> twopass . static_scene_max_gf_interval = cpi -> key_frame_frequency >> 1 ;
 if ( cpi -> oxcf . play_alternate && cpi -> oxcf . lag_in_frames ) {
 if ( cpi -> max_gf_interval > cpi -> oxcf . lag_in_frames - 1 ) cpi -> max_gf_interval = cpi -> oxcf . lag_in_frames - 1 ;
 if ( cpi -> twopass . static_scene_max_gf_interval > cpi -> oxcf . lag_in_frames - 1 ) cpi -> twopass . static_scene_max_gf_interval = cpi -> oxcf . lag_in_frames - 1 ;
 }
 if ( cpi -> max_gf_interval > cpi -> twopass . static_scene_max_gf_interval ) cpi -> max_gf_interval = cpi -> twopass . static_scene_max_gf_interval ;
 }