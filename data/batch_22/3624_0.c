static int dissect_h245_T_nonCollapsing_item ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 680 "../../asn1/h245/h245.cnf" gef_ctx_t * parent_gefx ;
 parent_gefx = gef_ctx_get ( actx -> private_data ) ;
 actx -> private_data = gef_ctx_alloc ( parent_gefx , "nonCollapsing" ) ;
 offset = dissect_h245_GenericParameter ( tvb , offset , actx , tree , hf_index ) ;
 # line 685 "../../asn1/h245/h245.cnf" actx -> private_data = parent_gefx ;
 return offset ;
 }