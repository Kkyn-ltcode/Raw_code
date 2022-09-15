static int dissect_h245_T_untilClosingFlag ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 offset = dissect_per_null ( tvb , offset , actx , tree , hf_index ) ;
 # line 110 "../../asn1/h245/h245.cnf" h223_me -> repeat_count = 0 ;
 return offset ;
 }