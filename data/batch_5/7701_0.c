static int ssl3_record_app_data_waiting ( SSL * s ) {
 SSL3_BUFFER * rbuf ;
 int left , len ;
 unsigned char * p ;
 rbuf = RECORD_LAYER_get_rbuf ( & s -> rlayer ) ;
 p = SSL3_BUFFER_get_buf ( rbuf ) ;
 if ( p == NULL ) return 0 ;
 left = SSL3_BUFFER_get_left ( rbuf ) ;
 if ( left < SSL3_RT_HEADER_LENGTH ) return 0 ;
 p += SSL3_BUFFER_get_offset ( rbuf ) ;
 if ( * p != SSL3_RT_APPLICATION_DATA ) return 0 ;
 p += 3 ;
 n2s ( p , len ) ;
 if ( left < SSL3_RT_HEADER_LENGTH + len ) return 0 ;
 return 1 ;
 }