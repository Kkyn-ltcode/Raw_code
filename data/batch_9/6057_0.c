VALUE rb_dlhandle_s_allocate ( VALUE klass ) {
 VALUE obj ;
 struct dl_handle * dlhandle ;
 obj = Data_Make_Struct ( rb_cDLHandle , struct dl_handle , 0 , dlhandle_free , dlhandle ) ;
 dlhandle -> ptr = 0 ;
 dlhandle -> open = 0 ;
 dlhandle -> enable_close = 0 ;
 return obj ;
 }