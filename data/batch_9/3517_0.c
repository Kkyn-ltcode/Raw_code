static int dissect_h245_T_h223_al_type_al2M ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 344 "../../asn1/h245/h245.cnf" if ( h223_lc_params_temp ) h223_lc_params_temp -> al_type = al2M ;
 offset = dissect_h245_H223AL2MParameters ( tvb , offset , actx , tree , hf_index ) ;
 return offset ;
 }