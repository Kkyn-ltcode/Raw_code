static VALUE cState_max_nesting ( VALUE self ) {
 GET_STATE ( self ) ;
 return LONG2FIX ( state -> max_nesting ) ;
 }