static VALUE cState_max_nesting_set ( VALUE self , VALUE depth ) {
 GET_STATE ( self ) ;
 Check_Type ( depth , T_FIXNUM ) ;
 return state -> max_nesting = FIX2LONG ( depth ) ;
 }