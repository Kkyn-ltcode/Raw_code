int dissect_h225_GenericData ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 816 "./asn1/h225/h225.cnf" void * priv_data = actx -> private_data ;
 gef_ctx_t * gefx ;
 gefx = gef_ctx_get ( actx -> private_data ) ;
 if ( ! gefx ) {
 gefx = gef_ctx_alloc ( NULL , "GenericData" ) ;
 actx -> private_data = gefx ;
 }
 offset = dissect_per_sequence ( tvb , offset , actx , tree , hf_index , ett_h225_GenericData , GenericData_sequence ) ;
 # line 826 "./asn1/h225/h225.cnf" actx -> private_data = priv_data ;
 return offset ;
 }