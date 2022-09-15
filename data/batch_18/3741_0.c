static int dissect_h245_T_reverseLogicalChannelNumber ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 offset = dissect_h245_LogicalChannelNumber ( tvb , offset , actx , tree , hf_index ) ;
 # line 288 "../../asn1/h245/h245.cnf" h223_rev_lc_num = h245_lc_temp ;
 return offset ;
 }