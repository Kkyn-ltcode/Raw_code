static VALUE cState_configure ( VALUE self , VALUE opts ) {
 VALUE tmp ;
 GET_STATE ( self ) ;
 tmp = rb_check_convert_type ( opts , T_HASH , "Hash" , "to_hash" ) ;
 if ( NIL_P ( tmp ) ) tmp = rb_convert_type ( opts , T_HASH , "Hash" , "to_h" ) ;
 opts = tmp ;
 tmp = rb_hash_aref ( opts , ID2SYM ( i_indent ) ) ;
 if ( RTEST ( tmp ) ) {
 unsigned long len ;
 Check_Type ( tmp , T_STRING ) ;
 len = RSTRING_LEN ( tmp ) ;
 state -> indent = fstrndup ( RSTRING_PTR ( tmp ) , len + 1 ) ;
 state -> indent_len = len ;
 }
 tmp = rb_hash_aref ( opts , ID2SYM ( i_space ) ) ;
 if ( RTEST ( tmp ) ) {
 unsigned long len ;
 Check_Type ( tmp , T_STRING ) ;
 len = RSTRING_LEN ( tmp ) ;
 state -> space = fstrndup ( RSTRING_PTR ( tmp ) , len + 1 ) ;
 state -> space_len = len ;
 }
 tmp = rb_hash_aref ( opts , ID2SYM ( i_space_before ) ) ;
 if ( RTEST ( tmp ) ) {
 unsigned long len ;
 Check_Type ( tmp , T_STRING ) ;
 len = RSTRING_LEN ( tmp ) ;
 state -> space_before = fstrndup ( RSTRING_PTR ( tmp ) , len + 1 ) ;
 state -> space_before_len = len ;
 }
 tmp = rb_hash_aref ( opts , ID2SYM ( i_array_nl ) ) ;
 if ( RTEST ( tmp ) ) {
 unsigned long len ;
 Check_Type ( tmp , T_STRING ) ;
 len = RSTRING_LEN ( tmp ) ;
 state -> array_nl = fstrndup ( RSTRING_PTR ( tmp ) , len + 1 ) ;
 state -> array_nl_len = len ;
 }
 tmp = rb_hash_aref ( opts , ID2SYM ( i_object_nl ) ) ;
 if ( RTEST ( tmp ) ) {
 unsigned long len ;
 Check_Type ( tmp , T_STRING ) ;
 len = RSTRING_LEN ( tmp ) ;
 state -> object_nl = fstrndup ( RSTRING_PTR ( tmp ) , len + 1 ) ;
 state -> object_nl_len = len ;
 }
 tmp = ID2SYM ( i_max_nesting ) ;
 state -> max_nesting = 100 ;
 if ( option_given_p ( opts , tmp ) ) {
 VALUE max_nesting = rb_hash_aref ( opts , tmp ) ;
 if ( RTEST ( max_nesting ) ) {
 Check_Type ( max_nesting , T_FIXNUM ) ;
 state -> max_nesting = FIX2LONG ( max_nesting ) ;
 }
 else {
 state -> max_nesting = 0 ;
 }
 }
 tmp = ID2SYM ( i_depth ) ;
 state -> depth = 0 ;
 if ( option_given_p ( opts , tmp ) ) {
 VALUE depth = rb_hash_aref ( opts , tmp ) ;
 if ( RTEST ( depth ) ) {
 Check_Type ( depth , T_FIXNUM ) ;
 state -> depth = FIX2LONG ( depth ) ;
 }
 else {
 state -> depth = 0 ;
 }
 }
 tmp = ID2SYM ( i_buffer_initial_length ) ;
 if ( option_given_p ( opts , tmp ) ) {
 VALUE buffer_initial_length = rb_hash_aref ( opts , tmp ) ;
 if ( RTEST ( buffer_initial_length ) ) {
 long initial_length ;
 Check_Type ( buffer_initial_length , T_FIXNUM ) ;
 initial_length = FIX2LONG ( buffer_initial_length ) ;
 if ( initial_length > 0 ) state -> buffer_initial_length = initial_length ;
 }
 }
 tmp = rb_hash_aref ( opts , ID2SYM ( i_allow_nan ) ) ;
 state -> allow_nan = RTEST ( tmp ) ;
 tmp = rb_hash_aref ( opts , ID2SYM ( i_ascii_only ) ) ;
 state -> ascii_only = RTEST ( tmp ) ;
 return self ;
 }