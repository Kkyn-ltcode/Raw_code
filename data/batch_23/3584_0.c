static int dissect_h245_GenericMessage ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 605 "../../asn1/h245/h245.cnf" void * priv_data = actx -> private_data ;
 gef_ctx_t * gefx ;
 gefx = gef_ctx_get ( actx -> private_data ) ;
 if ( ! gefx ) {
 gefx = gef_ctx_alloc ( NULL , "GenericMessage" ) ;
 actx -> private_data = gefx ;
 }
 offset = dissect_per_sequence ( tvb , offset , actx , tree , hf_index , ett_h245_GenericMessage , GenericMessage_sequence ) ;
 # line 615 "../../asn1/h245/h245.cnf" actx -> private_data = priv_data ;
 return offset ;
 }