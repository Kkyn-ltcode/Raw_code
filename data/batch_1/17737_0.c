static int frame_is_reference ( const VP9_COMP * cpi ) {
 const VP9_COMMON * cm = & cpi -> common ;
 return cm -> frame_type == KEY_FRAME || cpi -> refresh_last_frame || cpi -> refresh_golden_frame || cpi -> refresh_alt_ref_frame || cm -> refresh_frame_context || cm -> lf . mode_ref_delta_update || cm -> seg . update_map || cm -> seg . update_data ;
 }