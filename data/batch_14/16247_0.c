static VALUE ossl_s_ciphers ( VALUE self ) {
 VALUE ary ;
 ary = rb_ary_new ( ) ;
 OBJ_NAME_do_all_sorted ( OBJ_NAME_TYPE_CIPHER_METH , ( void ( * ) ( const OBJ_NAME * , void * ) ) add_cipher_name_to_ary , ( void * ) ary ) ;
 return ary ;
 }