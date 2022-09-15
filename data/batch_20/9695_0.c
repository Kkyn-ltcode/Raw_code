static void generate_json_object ( FBuffer * buffer , VALUE Vstate , JSON_Generator_State * state , VALUE obj ) {
 char * object_nl = state -> object_nl ;
 long object_nl_len = state -> object_nl_len ;
 char * indent = state -> indent ;
 long indent_len = state -> indent_len ;
 long max_nesting = state -> max_nesting ;
 char * delim = FBUFFER_PTR ( state -> object_delim ) ;
 long delim_len = FBUFFER_LEN ( state -> object_delim ) ;
 char * delim2 = FBUFFER_PTR ( state -> object_delim2 ) ;
 long delim2_len = FBUFFER_LEN ( state -> object_delim2 ) ;
 long depth = ++ state -> depth ;
 int i , j ;
 VALUE key , key_to_s , keys ;
 if ( max_nesting != 0 && depth > max_nesting ) {
 fbuffer_free ( buffer ) ;
 rb_raise ( eNestingError , "nesting of %ld is too deep" , -- state -> depth ) ;
 }
 fbuffer_append_char ( buffer , '{
' ) ;
 keys = rb_funcall ( obj , i_keys , 0 ) ;
 for ( i = 0 ;
 i < RARRAY_LEN ( keys ) ;
 i ++ ) {
 if ( i > 0 ) fbuffer_append ( buffer , delim , delim_len ) ;
 if ( object_nl ) {
 fbuffer_append ( buffer , object_nl , object_nl_len ) ;
 }
 if ( indent ) {
 for ( j = 0 ;
 j < depth ;
 j ++ ) {
 fbuffer_append ( buffer , indent , indent_len ) ;
 }
 }
 key = rb_ary_entry ( keys , i ) ;
 key_to_s = rb_funcall ( key , i_to_s , 0 ) ;
 Check_Type ( key_to_s , T_STRING ) ;
 generate_json ( buffer , Vstate , state , key_to_s ) ;
 fbuffer_append ( buffer , delim2 , delim2_len ) ;
 generate_json ( buffer , Vstate , state , rb_hash_aref ( obj , key ) ) ;
 }
 depth = -- state -> depth ;
 if ( object_nl ) {
 fbuffer_append ( buffer , object_nl , object_nl_len ) ;
 if ( indent ) {
 for ( j = 0 ;
 j < depth ;
 j ++ ) {
 fbuffer_append ( buffer , indent , indent_len ) ;
 }
 }
 }
 fbuffer_append_char ( buffer , '}
' ) ;
 }