static VALUE mString_to_json_raw_object ( VALUE self ) {
 VALUE ary ;
 VALUE result = rb_hash_new ( ) ;
 rb_hash_aset ( result , rb_funcall ( mJSON , i_create_id , 0 ) , rb_class_name ( rb_obj_class ( self ) ) ) ;
 ary = rb_funcall ( self , i_unpack , 1 , rb_str_new2 ( "C*" ) ) ;
 rb_hash_aset ( result , rb_str_new2 ( "raw" ) , ary ) ;
 return result ;
 }