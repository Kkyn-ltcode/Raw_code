static void update_reference_frames ( VP8_COMP * cpi ) {
 VP8_COMMON * cm = & cpi -> common ;
 YV12_BUFFER_CONFIG * yv12_fb = cm -> yv12_fb ;
 if ( cm -> frame_type == KEY_FRAME ) {
 yv12_fb [ cm -> new_fb_idx ] . flags |= VP8_GOLD_FRAME | VP8_ALTR_FRAME ;
 yv12_fb [ cm -> gld_fb_idx ] . flags &= ~ VP8_GOLD_FRAME ;
 yv12_fb [ cm -> alt_fb_idx ] . flags &= ~ VP8_ALTR_FRAME ;
 cm -> alt_fb_idx = cm -> gld_fb_idx = cm -> new_fb_idx ;
 cpi -> current_ref_frames [ GOLDEN_FRAME ] = cm -> current_video_frame ;
 cpi -> current_ref_frames [ ALTREF_FRAME ] = cm -> current_video_frame ;
 }
 else {
 if ( cm -> refresh_alt_ref_frame ) {
 assert ( ! cm -> copy_buffer_to_arf ) ;
 cm -> yv12_fb [ cm -> new_fb_idx ] . flags |= VP8_ALTR_FRAME ;
 cm -> yv12_fb [ cm -> alt_fb_idx ] . flags &= ~ VP8_ALTR_FRAME ;
 cm -> alt_fb_idx = cm -> new_fb_idx ;
 cpi -> current_ref_frames [ ALTREF_FRAME ] = cm -> current_video_frame ;
 }
 else if ( cm -> copy_buffer_to_arf ) {
 assert ( ! ( cm -> copy_buffer_to_arf & ~ 0x3 ) ) ;
 if ( cm -> copy_buffer_to_arf == 1 ) {
 if ( cm -> alt_fb_idx != cm -> lst_fb_idx ) {
 yv12_fb [ cm -> lst_fb_idx ] . flags |= VP8_ALTR_FRAME ;
 yv12_fb [ cm -> alt_fb_idx ] . flags &= ~ VP8_ALTR_FRAME ;
 cm -> alt_fb_idx = cm -> lst_fb_idx ;
 cpi -> current_ref_frames [ ALTREF_FRAME ] = cpi -> current_ref_frames [ LAST_FRAME ] ;
 }
 }
 else {
 if ( cm -> alt_fb_idx != cm -> gld_fb_idx ) {
 yv12_fb [ cm -> gld_fb_idx ] . flags |= VP8_ALTR_FRAME ;
 yv12_fb [ cm -> alt_fb_idx ] . flags &= ~ VP8_ALTR_FRAME ;
 cm -> alt_fb_idx = cm -> gld_fb_idx ;
 cpi -> current_ref_frames [ ALTREF_FRAME ] = cpi -> current_ref_frames [ GOLDEN_FRAME ] ;
 }
 }
 }
 if ( cm -> refresh_golden_frame ) {
 assert ( ! cm -> copy_buffer_to_gf ) ;
 cm -> yv12_fb [ cm -> new_fb_idx ] . flags |= VP8_GOLD_FRAME ;
 cm -> yv12_fb [ cm -> gld_fb_idx ] . flags &= ~ VP8_GOLD_FRAME ;
 cm -> gld_fb_idx = cm -> new_fb_idx ;
 cpi -> current_ref_frames [ GOLDEN_FRAME ] = cm -> current_video_frame ;
 }
 else if ( cm -> copy_buffer_to_gf ) {
 assert ( ! ( cm -> copy_buffer_to_arf & ~ 0x3 ) ) ;
 if ( cm -> copy_buffer_to_gf == 1 ) {
 if ( cm -> gld_fb_idx != cm -> lst_fb_idx ) {
 yv12_fb [ cm -> lst_fb_idx ] . flags |= VP8_GOLD_FRAME ;
 yv12_fb [ cm -> gld_fb_idx ] . flags &= ~ VP8_GOLD_FRAME ;
 cm -> gld_fb_idx = cm -> lst_fb_idx ;
 cpi -> current_ref_frames [ GOLDEN_FRAME ] = cpi -> current_ref_frames [ LAST_FRAME ] ;
 }
 }
 else {
 if ( cm -> alt_fb_idx != cm -> gld_fb_idx ) {
 yv12_fb [ cm -> alt_fb_idx ] . flags |= VP8_GOLD_FRAME ;
 yv12_fb [ cm -> gld_fb_idx ] . flags &= ~ VP8_GOLD_FRAME ;
 cm -> gld_fb_idx = cm -> alt_fb_idx ;
 cpi -> current_ref_frames [ GOLDEN_FRAME ] = cpi -> current_ref_frames [ ALTREF_FRAME ] ;
 }
 }
 }
 }
 if ( cm -> refresh_last_frame ) {
 cm -> yv12_fb [ cm -> new_fb_idx ] . flags |= VP8_LAST_FRAME ;
 cm -> yv12_fb [ cm -> lst_fb_idx ] . flags &= ~ VP8_LAST_FRAME ;
 cm -> lst_fb_idx = cm -> new_fb_idx ;
 cpi -> current_ref_frames [ LAST_FRAME ] = cm -> current_video_frame ;
 }
 # if CONFIG_TEMPORAL_DENOISING if ( cpi -> oxcf . noise_sensitivity ) {
 if ( cm -> frame_type == KEY_FRAME ) {
 int i ;
 for ( i = LAST_FRAME ;
 i < MAX_REF_FRAMES ;
 ++ i ) vp8_yv12_copy_frame ( cpi -> Source , & cpi -> denoiser . yv12_running_avg [ i ] ) ;
 }
 else {
 vp8_yv12_extend_frame_borders ( & cpi -> denoiser . yv12_running_avg [ INTRA_FRAME ] ) ;
 if ( cm -> refresh_alt_ref_frame || cm -> copy_buffer_to_arf ) {
 vp8_yv12_copy_frame ( & cpi -> denoiser . yv12_running_avg [ INTRA_FRAME ] , & cpi -> denoiser . yv12_running_avg [ ALTREF_FRAME ] ) ;
 }
 if ( cm -> refresh_golden_frame || cm -> copy_buffer_to_gf ) {
 vp8_yv12_copy_frame ( & cpi -> denoiser . yv12_running_avg [ INTRA_FRAME ] , & cpi -> denoiser . yv12_running_avg [ GOLDEN_FRAME ] ) ;
 }
 if ( cm -> refresh_last_frame ) {
 vp8_yv12_copy_frame ( & cpi -> denoiser . yv12_running_avg [ INTRA_FRAME ] , & cpi -> denoiser . yv12_running_avg [ LAST_FRAME ] ) ;
 }
 }
 if ( cpi -> oxcf . noise_sensitivity == 4 ) vp8_yv12_copy_frame ( cpi -> Source , & cpi -> denoiser . yv12_last_source ) ;
 }
 # endif }