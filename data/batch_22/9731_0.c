static VALUE cState_aset ( VALUE self , VALUE name , VALUE value ) {
 VALUE name_writer ;
 name = rb_funcall ( name , i_to_s , 0 ) ;
 name_writer = rb_str_cat2 ( rb_str_dup ( name ) , "=" ) ;
 if ( RTEST ( rb_funcall ( self , i_respond_to_p , 1 , name_writer ) ) ) {
 return rb_funcall ( self , i_send , 2 , name_writer , value ) ;
 }
 else {
 rb_ivar_set ( self , rb_intern_str ( rb_str_concat ( rb_str_new2 ( "@" ) , name ) ) , value ) ;
 }
 return Qnil ;
 }