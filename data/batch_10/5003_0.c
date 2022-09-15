static inline krb5_error_code data_to_gss ( krb5_data * input_k5data , gss_buffer_t output_buffer ) {
 krb5_error_code code = 0 ;
 output_buffer -> length = input_k5data -> length ;
 # if defined ( _WIN32 ) || defined ( DEBUG_GSSALLOC ) if ( output_buffer -> length > 0 ) {
 output_buffer -> value = gssalloc_malloc ( output_buffer -> length ) ;
 if ( output_buffer -> value ) memcpy ( output_buffer -> value , input_k5data -> data , output_buffer -> length ) ;
 else code = ENOMEM ;
 }
 else {
 output_buffer -> value = NULL ;
 }
 free ( input_k5data -> data ) ;
 # else output_buffer -> value = input_k5data -> data ;
 # endif * input_k5data = empty_data ( ) ;
 return code ;
 }