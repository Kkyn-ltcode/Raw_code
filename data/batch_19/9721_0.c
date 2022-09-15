static void set_state_ivars ( VALUE hash , VALUE state ) {
 VALUE ivars = rb_obj_instance_variables ( state ) ;
 int i = 0 ;
 for ( i = 0 ;
 i < RARRAY_LEN ( ivars ) ;
 i ++ ) {
 VALUE key = rb_funcall ( rb_ary_entry ( ivars , i ) , i_to_s , 0 ) ;
 long key_len = RSTRING_LEN ( key ) ;
 VALUE value = rb_iv_get ( state , StringValueCStr ( key ) ) ;
 rb_hash_aset ( hash , rb_str_intern ( rb_str_substr ( key , 1 , key_len - 1 ) ) , value ) ;
 }
 }