static int ref_frames ( Vp3DecodeContext * dst , Vp3DecodeContext * src ) {
 int ret ;
 if ( ( ret = ref_frame ( dst , & dst -> current_frame , & src -> current_frame ) ) < 0 || ( ret = ref_frame ( dst , & dst -> golden_frame , & src -> golden_frame ) ) < 0 || ( ret = ref_frame ( dst , & dst -> last_frame , & src -> last_frame ) ) < 0 ) return ret ;
 return 0 ;
 }