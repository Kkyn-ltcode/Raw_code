void record_loop_stats ( double offset , double freq , double jitter , double wander , int spoll ) {
 l_fp now ;
 u_long day ;
 if ( ! stats_control ) return ;
 get_systime ( & now ) ;
 filegen_setup ( & loopstats , now . l_ui ) ;
 day = now . l_ui / 86400 + MJD_1900 ;
 now . l_ui %= 86400 ;
 if ( loopstats . fp != NULL ) {
 fprintf ( loopstats . fp , "%lu %s %.9f %.3f %.9f %.6f %d\n" , day , ulfptoa ( & now , 3 ) , offset , freq * 1e6 , jitter , wander * 1e6 , spoll ) ;
 fflush ( loopstats . fp ) ;
 }
 }