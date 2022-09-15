static int dissect_h245_CapabilityIdentifier ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 714 "../../asn1/h245/h245.cnf" gef_ctx_t * gefx ;
 offset = dissect_per_choice ( tvb , offset , actx , tree , hf_index , ett_h245_CapabilityIdentifier , CapabilityIdentifier_choice , NULL ) ;
 # line 716 "../../asn1/h245/h245.cnf" gef_ctx_update_key ( gef_ctx_get ( actx -> private_data ) ) ;
 gefx = gef_ctx_get ( actx -> private_data ) ;
 if ( gefx ) {
 dissector_try_string ( gef_name_dissector_table , gefx -> key , tvb_new_subset ( tvb , offset >> 3 , 0 , 0 ) , actx -> pinfo , tree , actx ) ;
 }
 actx -> private_data = gefx ;
 return offset ;
 }