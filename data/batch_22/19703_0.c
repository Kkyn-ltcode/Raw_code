static int gettime ( struct event_base * base , struct timeval * tp ) {
 if ( base -> tv_cache . tv_sec ) {
 * tp = base -> tv_cache ;
 return ( 0 ) ;
 }
 # if defined ( HAVE_CLOCK_GETTIME ) && defined ( CLOCK_MONOTONIC ) struct timespec ts ;
 if ( use_monotonic && clock_gettime ( CLOCK_MONOTONIC , & ts ) == 0 ) {
 tp -> tv_sec = ts . tv_sec ;
 tp -> tv_usec = ts . tv_nsec / 1000 ;
 return ( 0 ) ;
 }
 # endif use_monotonic = 0 ;
 return ( evutil_gettimeofday ( tp , NULL ) ) ;
 }