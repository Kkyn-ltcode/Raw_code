int vp8_use_as_reference ( VP8_COMP * cpi , int ref_frame_flags ) {
 if ( ref_frame_flags > 7 ) return - 1 ;
 cpi -> ref_frame_flags = ref_frame_flags ;
 return 0 ;
 }