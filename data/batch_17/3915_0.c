static int dissect_h245_RTPPayloadType ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 924 "../../asn1/h245/h245.cnf" rfc_number = 0 ;
 offset = dissect_per_sequence ( tvb , offset , actx , tree , hf_index , ett_h245_RTPPayloadType , RTPPayloadType_sequence ) ;
 return offset ;
 }