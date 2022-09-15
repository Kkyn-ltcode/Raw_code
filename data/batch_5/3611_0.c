static int dissect_h245_T_forwardMultiplexAckParameters ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 279 "../../asn1/h245/h245.cnf" upcoming_channel = ( upcoming_olc ) ? & upcoming_olc -> fwd_lc : NULL ;
 offset = dissect_per_choice ( tvb , offset , actx , tree , hf_index , ett_h245_T_forwardMultiplexAckParameters , T_forwardMultiplexAckParameters_choice , NULL ) ;
 upcoming_channel = NULL ;
 return offset ;
 }