static Picture * remove_short ( H264Context * h , int frame_num , int ref_mask ) {
 Picture * pic ;
 int i ;
 if ( h -> avctx -> debug & FF_DEBUG_MMCO ) av_log ( h -> avctx , AV_LOG_DEBUG , "remove short %d count %d\n" , frame_num , h -> short_ref_count ) ;
 pic = find_short ( h , frame_num , & i ) ;
 if ( pic ) {
 if ( unreference_pic ( h , pic , ref_mask ) ) remove_short_at_index ( h , i ) ;
 }
 return pic ;
 }