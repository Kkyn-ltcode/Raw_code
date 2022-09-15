static VALUE cState_aref ( VALUE self , VALUE name ) {
 name = rb_funcall ( name , i_to_s , 0 ) ;
 if ( RTEST ( rb_funcall ( self , i_respond_to_p , 1 , name ) ) ) {
 return rb_funcall ( self , i_send , 1 , name ) ;
 }
 else {
 return rb_ivar_get ( self , rb_intern_str ( rb_str_concat ( rb_str_new2 ( "@" ) , name ) ) ) ;
 }
 }