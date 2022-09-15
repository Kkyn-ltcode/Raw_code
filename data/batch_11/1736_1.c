void vp9_loop_filter_alloc ( VP9_COMMON * cm , VP9LfSync * lf_sync , int rows , int width ) {
 lf_sync -> rows = rows ;
 # if CONFIG_MULTITHREAD {
 int i ;
 CHECK_MEM_ERROR ( cm , lf_sync -> mutex_ , vpx_malloc ( sizeof ( * lf_sync -> mutex_ ) * rows ) ) ;
 for ( i = 0 ;
 i < rows ;
 ++ i ) {
 pthread_mutex_init ( & lf_sync -> mutex_ [ i ] , NULL ) ;
 }
 CHECK_MEM_ERROR ( cm , lf_sync -> cond_ , vpx_malloc ( sizeof ( * lf_sync -> cond_ ) * rows ) ) ;
 for ( i = 0 ;
 i < rows ;
 ++ i ) {
 pthread_cond_init ( & lf_sync -> cond_ [ i ] , NULL ) ;
 }
 }
 # endif CHECK_MEM_ERROR ( cm , lf_sync -> cur_sb_col , vpx_malloc ( sizeof ( * lf_sync -> cur_sb_col ) * rows ) ) ;
 lf_sync -> sync_range = get_sync_range ( width ) ;
 }