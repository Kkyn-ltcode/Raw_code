void ff_vdpau_h264_picture_start ( H264Context * h ) {
 struct vdpau_render_state * render ;
 int i ;
 render = ( struct vdpau_render_state * ) h -> cur_pic_ptr -> f . data [ 0 ] ;
 assert ( render ) ;
 for ( i = 0 ;
 i < 2 ;
 ++ i ) {
 int foc = h -> cur_pic_ptr -> field_poc [ i ] ;
 if ( foc == INT_MAX ) foc = 0 ;
 render -> info . h264 . field_order_cnt [ i ] = foc ;
 }
 render -> info . h264 . frame_num = h -> frame_num ;
 }