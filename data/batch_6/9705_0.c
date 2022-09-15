static VALUE cState_from_state_s ( VALUE self , VALUE opts ) {
 if ( rb_obj_is_kind_of ( opts , self ) ) {
 return opts ;
 }
 else if ( rb_obj_is_kind_of ( opts , rb_cHash ) ) {
 return rb_funcall ( self , i_new , 1 , opts ) ;
 }
 else {
 if ( NIL_P ( CJSON_SAFE_STATE_PROTOTYPE ) ) {
 CJSON_SAFE_STATE_PROTOTYPE = rb_const_get ( mJSON , i_SAFE_STATE_PROTOTYPE ) ;
 }
 return rb_funcall ( CJSON_SAFE_STATE_PROTOTYPE , i_dup , 0 ) ;
 }
 }