static VALUE cState_buffer_initial_length ( VALUE self ) {
 GET_STATE ( self ) ;
 return LONG2FIX ( state -> buffer_initial_length ) ;
 }