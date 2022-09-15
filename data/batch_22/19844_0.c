static u16 default_transaction_id_fn ( void ) {
 u16 trans_id ;
 # ifdef DNS_USE_CPU_CLOCK_FOR_ID struct timespec ts ;
 static int clkid = - 1 ;
 if ( clkid == - 1 ) {
 clkid = CLOCK_REALTIME ;
 # ifdef CLOCK_MONOTONIC if ( clock_gettime ( CLOCK_MONOTONIC , & ts ) != - 1 ) clkid = CLOCK_MONOTONIC ;
 # endif }
 if ( clock_gettime ( clkid , & ts ) == - 1 ) event_err ( 1 , "clock_gettime" ) ;
 trans_id = ts . tv_nsec & 0xffff ;
 # endif # ifdef DNS_USE_FTIME_FOR_ID struct _timeb tb ;
 _ftime ( & tb ) ;
 trans_id = tb . millitm & 0xffff ;
 # endif # ifdef DNS_USE_GETTIMEOFDAY_FOR_ID struct timeval tv ;
 evutil_gettimeofday ( & tv , NULL ) ;
 trans_id = tv . tv_usec & 0xffff ;
 # endif # ifdef DNS_USE_OPENSSL_FOR_ID if ( RAND_pseudo_bytes ( ( u8 * ) & trans_id , 2 ) == - 1 ) {
 abort ( ) ;
 }
 # endif return trans_id ;
 }