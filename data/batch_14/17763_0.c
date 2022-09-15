static void Pass0Encode ( VP9_COMP * cpi , size_t * size , uint8_t * dest , unsigned int * frame_flags ) {
 if ( cpi -> oxcf . rc_mode == VPX_CBR ) {
 vp9_rc_get_one_pass_cbr_params ( cpi ) ;
 }
 else {
 vp9_rc_get_one_pass_vbr_params ( cpi ) ;
 }
 encode_frame_to_data_rate ( cpi , size , dest , frame_flags ) ;
 }