int ff_rv34_decode_update_thread_context ( AVCodecContext * dst , const AVCodecContext * src ) {
 RV34DecContext * r = dst -> priv_data , * r1 = src -> priv_data ;
 MpegEncContext * const s = & r -> s , * const s1 = & r1 -> s ;
 int err ;
 if ( dst == src || ! s1 -> context_initialized ) return 0 ;
 if ( s -> height != s1 -> height || s -> width != s1 -> width ) {
 s -> height = s1 -> height ;
 s -> width = s1 -> width ;
 if ( ( err = ff_MPV_common_frame_size_change ( s ) ) < 0 ) return err ;
 if ( ( err = rv34_decoder_realloc ( r ) ) < 0 ) return err ;
 }
 if ( ( err = ff_mpeg_update_thread_context ( dst , src ) ) ) return err ;
 r -> cur_pts = r1 -> cur_pts ;
 r -> last_pts = r1 -> last_pts ;
 r -> next_pts = r1 -> next_pts ;
 memset ( & r -> si , 0 , sizeof ( r -> si ) ) ;
 return 0 ;
 }