int dissect_h225_NonStandardParameter ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 803 "./asn1/h225/h225.cnf" nsp_handle = NULL ;
 offset = dissect_per_sequence ( tvb , offset , actx , tree , hf_index , ett_h225_NonStandardParameter , NonStandardParameter_sequence ) ;
 return offset ;
 }