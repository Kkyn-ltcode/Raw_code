VALUE rb_dlhandle_to_i ( VALUE self ) {
 struct dl_handle * dlhandle ;
 Data_Get_Struct ( self , struct dl_handle , dlhandle ) ;
 return PTR2NUM ( dlhandle ) ;
 }