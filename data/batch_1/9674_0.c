static VALUE cState_initialize ( int argc , VALUE * argv , VALUE self ) {
 VALUE opts ;
 GET_STATE ( self ) ;
 state -> max_nesting = 100 ;
 state -> buffer_initial_length = FBUFFER_INITIAL_LENGTH_DEFAULT ;
 rb_scan_args ( argc , argv , "01" , & opts ) ;
 if ( ! NIL_P ( opts ) ) cState_configure ( self , opts ) ;
 return self ;
 }