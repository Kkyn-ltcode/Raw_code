static void * i_alloc_struct_array_immovable ( gs_memory_t * mem , uint num_elements , gs_memory_type_ptr_t pstype , client_name_t cname ) {
 gs_ref_memory_t * const imem = ( gs_ref_memory_t * ) mem ;
 obj_header_t * obj ;
 ulong lsize ;
 # ifdef MEMENTO if ( Memento_failThisEvent ( ) ) return NULL ;
 # endif ALLOC_CHECK_SIZE ( mem , pstype ) ;
 if ( alloc_array_check_size ( num_elements , pstype -> ssize , & lsize ) == false ) return NULL ;
 obj = alloc_obj ( imem , lsize , pstype , ALLOC_IMMOVABLE | ALLOC_DIRECT , cname ) ;
 if_debug7m ( 'A' , mem , "[a%d|+<.]%s %s*(%lu=%u*%u) = 0x%lx\n" , alloc_trace_space ( imem ) , client_name_string ( cname ) , struct_type_name_string ( pstype ) , ( ulong ) num_elements * pstype -> ssize , num_elements , pstype -> ssize , ( ulong ) obj ) ;
 return ( char * ) obj ;
 }