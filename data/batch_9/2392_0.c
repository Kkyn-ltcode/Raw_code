static int cavs_decode_frame ( AVCodecContext * avctx , void * data , int * got_frame , AVPacket * avpkt ) {
 AVSContext * h = avctx -> priv_data ;
 const uint8_t * buf = avpkt -> data ;
 int buf_size = avpkt -> size ;
 uint32_t stc = - 1 ;
 int input_size , ret ;
 const uint8_t * buf_end ;
 const uint8_t * buf_ptr ;
 if ( buf_size == 0 ) {
 if ( ! h -> low_delay && h -> DPB [ 0 ] . f -> data [ 0 ] ) {
 * got_frame = 1 ;
 av_frame_move_ref ( data , h -> DPB [ 0 ] . f ) ;
 }
 return 0 ;
 }
 buf_ptr = buf ;
 buf_end = buf + buf_size ;
 for ( ;
 ;
 ) {
 buf_ptr = avpriv_mpv_find_start_code ( buf_ptr , buf_end , & stc ) ;
 if ( ( stc & 0xFFFFFE00 ) || buf_ptr == buf_end ) return FFMAX ( 0 , buf_ptr - buf ) ;
 input_size = ( buf_end - buf_ptr ) * 8 ;
 switch ( stc ) {
 case CAVS_START_CODE : init_get_bits ( & h -> gb , buf_ptr , input_size ) ;
 decode_seq_header ( h ) ;
 break ;
 case PIC_I_START_CODE : if ( ! h -> got_keyframe ) {
 av_frame_unref ( h -> DPB [ 0 ] . f ) ;
 av_frame_unref ( h -> DPB [ 1 ] . f ) ;
 h -> got_keyframe = 1 ;
 }
 case PIC_PB_START_CODE : * got_frame = 0 ;
 if ( ! h -> got_keyframe ) break ;
 init_get_bits ( & h -> gb , buf_ptr , input_size ) ;
 h -> stc = stc ;
 if ( decode_pic ( h ) ) break ;
 * got_frame = 1 ;
 if ( h -> cur . f -> pict_type != AV_PICTURE_TYPE_B ) {
 if ( h -> DPB [ 1 ] . f -> data [ 0 ] ) {
 if ( ( ret = av_frame_ref ( data , h -> DPB [ 1 ] . f ) ) < 0 ) return ret ;
 }
 else {
 * got_frame = 0 ;
 }
 }
 else {
 av_frame_move_ref ( data , h -> cur . f ) ;
 }
 break ;
 case EXT_START_CODE : break ;
 case USER_START_CODE : break ;
 default : if ( stc <= SLICE_MAX_START_CODE ) {
 init_get_bits ( & h -> gb , buf_ptr , input_size ) ;
 decode_slice_header ( h , & h -> gb ) ;
 }
 break ;
 }
 }
 }