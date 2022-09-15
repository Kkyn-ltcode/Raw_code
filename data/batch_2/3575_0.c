static int dissect_h245_H263VideoCapability ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 offset = dissect_per_sequence ( tvb , offset , actx , tree , hf_index , ett_h245_H263VideoCapability , H263VideoCapability_sequence ) ;
 # line 363 "../../asn1/h245/h245.cnf" h245_lc_dissector = h263_handle ;
 return offset ;
 }