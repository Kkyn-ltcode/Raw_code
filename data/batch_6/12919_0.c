int libevt_record_values_initialize ( libevt_record_values_t * * record_values , libcerror_error_t * * error ) {
 static char * function = "libevt_record_values_initialize" ;
 if ( record_values == NULL ) {
 libcerror_error_set ( error , LIBCERROR_ERROR_DOMAIN_ARGUMENTS , LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE , "%s: invalid record values." , function ) ;
 return ( - 1 ) ;
 }
 if ( * record_values != NULL ) {
 libcerror_error_set ( error , LIBCERROR_ERROR_DOMAIN_RUNTIME , LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET , "%s: invalid record values value already set." , function ) ;
 return ( - 1 ) ;
 }
 * record_values = memory_allocate_structure ( libevt_record_values_t ) ;
 if ( * record_values == NULL ) {
 libcerror_error_set ( error , LIBCERROR_ERROR_DOMAIN_MEMORY , LIBCERROR_MEMORY_ERROR_INSUFFICIENT , "%s: unable to create record values." , function ) ;
 goto on_error ;
 }
 if ( memory_set ( * record_values , 0 , sizeof ( libevt_record_values_t ) ) == NULL ) {
 libcerror_error_set ( error , LIBCERROR_ERROR_DOMAIN_MEMORY , LIBCERROR_MEMORY_ERROR_SET_FAILED , "%s: unable to clear record values." , function ) ;
 goto on_error ;
 }
 return ( 1 ) ;
 on_error : if ( * record_values != NULL ) {
 memory_free ( * record_values ) ;
 * record_values = NULL ;
 }
 return ( - 1 ) ;
 }