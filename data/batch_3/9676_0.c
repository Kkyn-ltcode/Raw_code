static VALUE cState_depth ( VALUE self ) {
 GET_STATE ( self ) ;
 return LONG2FIX ( state -> depth ) ;
 }