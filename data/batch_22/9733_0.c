static VALUE cState_indent ( VALUE self ) {
 GET_STATE ( self ) ;
 return state -> indent ? rb_str_new ( state -> indent , state -> indent_len ) : rb_str_new2 ( "" ) ;
 }