static int dissect_h245_LogicalChannelNumber ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 122 "../../asn1/h245/h245.cnf" guint32 value ;
 offset = dissect_per_constrained_integer ( tvb , offset , actx , tree , hf_index , 1U , 65535U , & value , FALSE ) ;
 h245_lc_temp = value & 0xfff ;
 return offset ;
 }