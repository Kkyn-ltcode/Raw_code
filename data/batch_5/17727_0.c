static void SvcEncode ( VP9_COMP * cpi , size_t * size , uint8_t * dest , unsigned int * frame_flags ) {
 vp9_rc_get_svc_params ( cpi ) ;
 encode_frame_to_data_rate ( cpi , size , dest , frame_flags ) ;
 }