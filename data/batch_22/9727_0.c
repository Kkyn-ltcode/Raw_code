static VALUE mString_to_json_raw ( int argc , VALUE * argv , VALUE self ) {
 VALUE obj = mString_to_json_raw_object ( self ) ;
 Check_Type ( obj , T_HASH ) ;
 return mHash_to_json ( argc , argv , obj ) ;
 }