static VALUE cState_init_copy ( VALUE obj , VALUE orig ) {
 JSON_Generator_State * objState , * origState ;
 if ( obj == orig ) return obj ;
 GET_STATE_TO ( obj , objState ) ;
 GET_STATE_TO ( orig , origState ) ;
 if ( ! objState ) rb_raise ( rb_eArgError , "unallocated JSON::State" ) ;
 MEMCPY ( objState , origState , JSON_Generator_State , 1 ) ;
 objState -> indent = fstrndup ( origState -> indent , origState -> indent_len ) ;
 objState -> space = fstrndup ( origState -> space , origState -> space_len ) ;
 objState -> space_before = fstrndup ( origState -> space_before , origState -> space_before_len ) ;
 objState -> object_nl = fstrndup ( origState -> object_nl , origState -> object_nl_len ) ;
 objState -> array_nl = fstrndup ( origState -> array_nl , origState -> array_nl_len ) ;
 if ( origState -> array_delim ) objState -> array_delim = fbuffer_dup ( origState -> array_delim ) ;
 if ( origState -> object_delim ) objState -> object_delim = fbuffer_dup ( origState -> object_delim ) ;
 if ( origState -> object_delim2 ) objState -> object_delim2 = fbuffer_dup ( origState -> object_delim2 ) ;
 return obj ;
 }