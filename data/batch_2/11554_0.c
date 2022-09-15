TSReturnCode TSAIOThreadNumSet ( int thread_num ) {
 # if AIO_MODE == AIO_MODE_NATIVE ( void ) thread_num ;
 return TS_SUCCESS ;
 # else if ( ink_aio_thread_num_set ( thread_num ) ) {
 return TS_SUCCESS ;
 }
 return TS_ERROR ;
 # endif }