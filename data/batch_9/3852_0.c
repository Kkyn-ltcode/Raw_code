static int dissect_h245_Cmd_aal5 ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 offset = dissect_per_sequence ( tvb , offset , actx , tree , hf_index , ett_h245_Cmd_aal5 , Cmd_aal5_sequence ) ;
 return offset ;
 }