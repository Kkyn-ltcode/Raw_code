static VALUE cState_depth_set ( VALUE self , VALUE depth ) {
 GET_STATE ( self ) ;
 Check_Type ( depth , T_FIXNUM ) ;
 state -> depth = FIX2LONG ( depth ) ;
 return Qnil ;
 }