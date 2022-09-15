static void generate_json ( FBuffer * buffer , VALUE Vstate , JSON_Generator_State * state , VALUE obj ) {
 VALUE tmp ;
 VALUE klass = CLASS_OF ( obj ) ;
 if ( klass == rb_cHash ) {
 generate_json_object ( buffer , Vstate , state , obj ) ;
 }
 else if ( klass == rb_cArray ) {
 generate_json_array ( buffer , Vstate , state , obj ) ;
 }
 else if ( klass == rb_cString ) {
 generate_json_string ( buffer , Vstate , state , obj ) ;
 }
 else if ( obj == Qnil ) {
 generate_json_null ( buffer , Vstate , state , obj ) ;
 }
 else if ( obj == Qfalse ) {
 generate_json_false ( buffer , Vstate , state , obj ) ;
 }
 else if ( obj == Qtrue ) {
 generate_json_true ( buffer , Vstate , state , obj ) ;
 }
 else if ( FIXNUM_P ( obj ) ) {
 generate_json_fixnum ( buffer , Vstate , state , obj ) ;
 }
 else if ( RB_TYPE_P ( obj , T_BIGNUM ) ) {
 generate_json_bignum ( buffer , Vstate , state , obj ) ;
 }
 else if ( klass == rb_cFloat ) {
 generate_json_float ( buffer , Vstate , state , obj ) ;
 }
 else if ( rb_respond_to ( obj , i_to_json ) ) {
 tmp = rb_funcall ( obj , i_to_json , 1 , Vstate ) ;
 Check_Type ( tmp , T_STRING ) ;
 fbuffer_append_str ( buffer , tmp ) ;
 }
 else {
 tmp = rb_funcall ( obj , i_to_s , 0 ) ;
 Check_Type ( tmp , T_STRING ) ;
 generate_json_string ( buffer , Vstate , state , tmp ) ;
 }
 }