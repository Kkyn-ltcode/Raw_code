static VALUE cState_ascii_only_p ( VALUE self ) {
 GET_STATE ( self ) ;
 return state -> ascii_only ? Qtrue : Qfalse ;
 }