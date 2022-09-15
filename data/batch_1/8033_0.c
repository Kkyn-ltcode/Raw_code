static byte * i_alloc_bytes ( gs_memory_t * mem , uint size , client_name_t cname ) {
 gs_ref_memory_t * const imem = ( gs_ref_memory_t * ) mem ;
 obj_header_t * obj ;
 obj_header_t * * pfl ;
 # ifdef MEMENTO if ( Memento_failThisEvent ( ) ) return NULL ;
 # endif IF_FREELIST_ALLOC ( obj , imem , size , & st_bytes , pfl ) alloc_trace ( ":+bf" , imem , cname , NULL , size , obj ) ;
 ELSEIF_BIG_FREELIST_ALLOC ( obj , imem , size , & st_bytes ) alloc_trace ( ":+bF" , imem , cname , NULL , size , obj ) ;
 ELSEIF_LIFO_ALLOC ( obj , imem , size , & st_bytes ) alloc_trace ( ":+b " , imem , cname , NULL , size , obj ) ;
 ELSE_ALLOC {
 obj = alloc_obj ( imem , size , & st_bytes , 0 , cname ) ;
 if ( obj == 0 ) return 0 ;
 alloc_trace ( ":+b." , imem , cname , NULL , size , obj ) ;
 }
 # if IGC_PTR_STABILITY_CHECK obj [ - 1 ] . d . o . space_id = imem -> space_id ;
 # endif return ( byte * ) obj ;
 }