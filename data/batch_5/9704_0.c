static VALUE cState_object_nl ( VALUE self ) {
 GET_STATE ( self ) ;
 return state -> object_nl ? rb_str_new ( state -> object_nl , state -> object_nl_len ) : rb_str_new2 ( "" ) ;
 }