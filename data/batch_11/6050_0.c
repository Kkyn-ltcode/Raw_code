void Init_dlhandle ( ) {
 rb_cDLHandle = rb_define_class_under ( rb_mDL , "Handle" , rb_cObject ) ;
 rb_define_alloc_func ( rb_cDLHandle , rb_dlhandle_s_allocate ) ;
 rb_define_method ( rb_cDLHandle , "initialize" , rb_dlhandle_initialize , - 1 ) ;
 rb_define_method ( rb_cDLHandle , "to_i" , rb_dlhandle_to_i , 0 ) ;
 rb_define_method ( rb_cDLHandle , "close" , rb_dlhandle_close , 0 ) ;
 rb_define_method ( rb_cDLHandle , "sym" , rb_dlhandle_sym , 1 ) ;
 rb_define_method ( rb_cDLHandle , "[]" , rb_dlhandle_sym , 1 ) ;
 rb_define_method ( rb_cDLHandle , "disable_close" , rb_dlhandle_disable_close , 0 ) ;
 rb_define_method ( rb_cDLHandle , "enable_close" , rb_dlhandle_enable_close , 0 ) ;
 }