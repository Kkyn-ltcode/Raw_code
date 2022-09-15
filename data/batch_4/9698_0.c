static VALUE cState_to_h ( VALUE self ) {
 VALUE result = rb_hash_new ( ) ;
 GET_STATE ( self ) ;
 set_state_ivars ( result , self ) ;
 rb_hash_aset ( result , ID2SYM ( i_indent ) , rb_str_new ( state -> indent , state -> indent_len ) ) ;
 rb_hash_aset ( result , ID2SYM ( i_space ) , rb_str_new ( state -> space , state -> space_len ) ) ;
 rb_hash_aset ( result , ID2SYM ( i_space_before ) , rb_str_new ( state -> space_before , state -> space_before_len ) ) ;
 rb_hash_aset ( result , ID2SYM ( i_object_nl ) , rb_str_new ( state -> object_nl , state -> object_nl_len ) ) ;
 rb_hash_aset ( result , ID2SYM ( i_array_nl ) , rb_str_new ( state -> array_nl , state -> array_nl_len ) ) ;
 rb_hash_aset ( result , ID2SYM ( i_allow_nan ) , state -> allow_nan ? Qtrue : Qfalse ) ;
 rb_hash_aset ( result , ID2SYM ( i_ascii_only ) , state -> ascii_only ? Qtrue : Qfalse ) ;
 rb_hash_aset ( result , ID2SYM ( i_max_nesting ) , LONG2FIX ( state -> max_nesting ) ) ;
 rb_hash_aset ( result , ID2SYM ( i_depth ) , LONG2FIX ( state -> depth ) ) ;
 rb_hash_aset ( result , ID2SYM ( i_buffer_initial_length ) , LONG2FIX ( state -> buffer_initial_length ) ) ;
 return result ;
 }