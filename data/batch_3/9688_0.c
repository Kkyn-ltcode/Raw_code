static VALUE cState_s_allocate ( VALUE klass ) {
 JSON_Generator_State * state ;
 return TypedData_Make_Struct ( klass , JSON_Generator_State , & JSON_Generator_State_type , state ) ;
 }