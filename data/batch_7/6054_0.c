VALUE rb_dlhandle_close ( VALUE self ) {
 struct dl_handle * dlhandle ;
 Data_Get_Struct ( self , struct dl_handle , dlhandle ) ;
 dlhandle -> open = 0 ;
 return INT2NUM ( dlclose ( dlhandle -> ptr ) ) ;
 }