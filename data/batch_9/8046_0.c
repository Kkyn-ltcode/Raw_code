static byte * i_alloc_bytes_immovable ( gs_memory_t * mem , uint size , client_name_t cname ) {
 gs_ref_memory_t * const imem = ( gs_ref_memory_t * ) mem ;
 obj_header_t * obj ;
 # ifdef MEMENTO if ( Memento_failThisEvent ( ) ) return NULL ;
 # endif obj = alloc_obj ( imem , size , & st_bytes , ALLOC_IMMOVABLE | ALLOC_DIRECT , cname ) ;
 if ( obj == 0 ) return 0 ;
 alloc_trace ( "|+b." , imem , cname , NULL , size , obj ) ;
 return ( byte * ) obj ;
 }