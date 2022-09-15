static YV12_BUFFER_CONFIG * get_vp9_ref_frame_buffer ( VP9_COMP * cpi , VP9_REFFRAME ref_frame_flag ) {
 MV_REFERENCE_FRAME ref_frame = NONE ;
 if ( ref_frame_flag == VP9_LAST_FLAG ) ref_frame = LAST_FRAME ;
 else if ( ref_frame_flag == VP9_GOLD_FLAG ) ref_frame = GOLDEN_FRAME ;
 else if ( ref_frame_flag == VP9_ALT_FLAG ) ref_frame = ALTREF_FRAME ;
 return ref_frame == NONE ? NULL : get_ref_frame_buffer ( cpi , ref_frame ) ;
 }