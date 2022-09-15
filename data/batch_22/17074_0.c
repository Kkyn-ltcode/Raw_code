static int frame_is_reference ( const VP8_COMP * cpi ) {
 const VP8_COMMON * cm = & cpi -> common ;
 const MACROBLOCKD * xd = & cpi -> mb . e_mbd ;
 return cm -> frame_type == KEY_FRAME || cm -> refresh_last_frame || cm -> refresh_golden_frame || cm -> refresh_alt_ref_frame || cm -> copy_buffer_to_gf || cm -> copy_buffer_to_arf || cm -> refresh_entropy_probs || xd -> mode_ref_lf_delta_update || xd -> update_mb_segmentation_map || xd -> update_mb_segmentation_data ;
 }