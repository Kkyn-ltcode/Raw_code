static FBuffer * cState_prepare_buffer ( VALUE self ) {
 FBuffer * buffer ;
 GET_STATE ( self ) ;
 buffer = fbuffer_alloc ( state -> buffer_initial_length ) ;
 if ( state -> object_delim ) {
 fbuffer_clear ( state -> object_delim ) ;
 }
 else {
 state -> object_delim = fbuffer_alloc ( 16 ) ;
 }
 fbuffer_append_char ( state -> object_delim , ',' ) ;
 if ( state -> object_delim2 ) {
 fbuffer_clear ( state -> object_delim2 ) ;
 }
 else {
 state -> object_delim2 = fbuffer_alloc ( 16 ) ;
 }
 if ( state -> space_before ) fbuffer_append ( state -> object_delim2 , state -> space_before , state -> space_before_len ) ;
 fbuffer_append_char ( state -> object_delim2 , ':' ) ;
 if ( state -> space ) fbuffer_append ( state -> object_delim2 , state -> space , state -> space_len ) ;
 if ( state -> array_delim ) {
 fbuffer_clear ( state -> array_delim ) ;
 }
 else {
 state -> array_delim = fbuffer_alloc ( 16 ) ;
 }
 fbuffer_append_char ( state -> array_delim , ',' ) ;
 if ( state -> array_nl ) fbuffer_append ( state -> array_delim , state -> array_nl , state -> array_nl_len ) ;
 return buffer ;
 }