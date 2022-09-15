void record_raw_stats ( sockaddr_u * srcadr , sockaddr_u * dstadr , l_fp * t1 , l_fp * t2 , l_fp * t3 , l_fp * t4 ) {
 l_fp now ;
 u_long day ;
 if ( ! stats_control ) return ;
 get_systime ( & now ) ;
 filegen_setup ( & rawstats , now . l_ui ) ;
 day = now . l_ui / 86400 + MJD_1900 ;
 now . l_ui %= 86400 ;
 if ( rawstats . fp != NULL ) {
 fprintf ( rawstats . fp , "%lu %s %s %s %s %s %s %s\n" , day , ulfptoa ( & now , 3 ) , stoa ( srcadr ) , dstadr ? stoa ( dstadr ) : "-" , ulfptoa ( t1 , 9 ) , ulfptoa ( t2 , 9 ) , ulfptoa ( t3 , 9 ) , ulfptoa ( t4 , 9 ) ) ;
 fflush ( rawstats . fp ) ;
 }
 }