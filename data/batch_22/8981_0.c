void record_clock_stats ( sockaddr_u * addr , const char * text ) {
 l_fp now ;
 u_long day ;
 if ( ! stats_control ) return ;
 get_systime ( & now ) ;
 filegen_setup ( & clockstats , now . l_ui ) ;
 day = now . l_ui / 86400 + MJD_1900 ;
 now . l_ui %= 86400 ;
 if ( clockstats . fp != NULL ) {
 fprintf ( clockstats . fp , "%lu %s %s %s\n" , day , ulfptoa ( & now , 3 ) , stoa ( addr ) , text ) ;
 fflush ( clockstats . fp ) ;
 }
 }