void vp9_loop_filter_dealloc ( VP9LfSync * lf_sync ) {
 if ( lf_sync != NULL ) {
 # if CONFIG_MULTITHREAD int i ;
 if ( lf_sync -> mutex_ != NULL ) {
 for ( i = 0 ;
 i < lf_sync -> rows ;
 ++ i ) {
 pthread_mutex_destroy ( & lf_sync -> mutex_ [ i ] ) ;
 }
 vpx_free ( lf_sync -> mutex_ ) ;
 }
 if ( lf_sync -> cond_ != NULL ) {
 for ( i = 0 ;
 i < lf_sync -> rows ;
 ++ i ) {
 pthread_cond_destroy ( & lf_sync -> cond_ [ i ] ) ;
 }
 vpx_free ( lf_sync -> cond_ ) ;
 }
 # endif vpx_free ( lf_sync -> cur_sb_col ) ;
 vp9_zero ( * lf_sync ) ;
 }
 }