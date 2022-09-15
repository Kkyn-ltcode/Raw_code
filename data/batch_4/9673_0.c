static void generate_json_string ( FBuffer * buffer , VALUE Vstate , JSON_Generator_State * state , VALUE obj ) {
 fbuffer_append_char ( buffer , '"' ) ;
 # ifdef HAVE_RUBY_ENCODING_H obj = rb_funcall ( obj , i_encode , 1 , CEncoding_UTF_8 ) ;
 # endif if ( state -> ascii_only ) {
 convert_UTF8_to_JSON_ASCII ( buffer , obj ) ;
 }
 else {
 convert_UTF8_to_JSON ( buffer , obj ) ;
 }
 fbuffer_append_char ( buffer , '"' ) ;
 }