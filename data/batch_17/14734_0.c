sf_count_t psf_fread ( void * ptr , sf_count_t bytes , sf_count_t items , SF_PRIVATE * psf ) {
 sf_count_t total = 0 ;
 ssize_t count ;
 if ( psf -> virtual_io ) return psf -> vio . read ( ptr , bytes * items , psf -> vio_user_data ) / bytes ;
 items *= bytes ;
 if ( items <= 0 ) return 0 ;
 while ( items > 0 ) {
 count = ( items > SENSIBLE_SIZE ) ? SENSIBLE_SIZE : ( ssize_t ) items ;
 count = read ( psf -> file . filedes , ( ( char * ) ptr ) + total , ( size_t ) count ) ;
 if ( count == - 1 ) {
 if ( errno == EINTR ) continue ;
 psf_log_syserr ( psf , errno ) ;
 break ;
 }
 ;
 if ( count == 0 ) break ;
 total += count ;
 items -= count ;
 }
 ;
 if ( psf -> is_pipe ) psf -> pipeoffset += total ;
 return total / bytes ;
 }