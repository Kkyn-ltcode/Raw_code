static void generate_json_bignum ( FBuffer * buffer , VALUE Vstate , JSON_Generator_State * state , VALUE obj ) {
 VALUE tmp = rb_funcall ( obj , i_to_s , 0 ) ;
 fbuffer_append_str ( buffer , tmp ) ;
 }