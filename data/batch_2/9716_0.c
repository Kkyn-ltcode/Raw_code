static VALUE mString_Extend_json_create ( VALUE self , VALUE o ) {
 VALUE ary ;
 Check_Type ( o , T_HASH ) ;
 ary = rb_hash_aref ( o , rb_str_new2 ( "raw" ) ) ;
 return rb_funcall ( ary , i_pack , 1 , rb_str_new2 ( "C*" ) ) ;
 }