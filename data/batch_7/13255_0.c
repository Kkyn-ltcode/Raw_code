static int dissect_t38_INTEGER ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 offset = dissect_per_integer ( tvb , offset , actx , tree , hf_index , NULL ) ;
 return offset ;
 }