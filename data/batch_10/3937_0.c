static int dissect_h245_TsapIdentifier ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 877 "../../asn1/h245/h245.cnf" guint32 tsapIdentifier ;
 offset = dissect_per_constrained_integer ( tvb , offset , actx , tree , hf_index , 0U , 65535U , & tsapIdentifier , FALSE ) ;
 if ( upcoming_channel && upcoming_channel -> upcoming_addr ) {
 upcoming_channel -> upcoming_addr -> port = tsapIdentifier ;
 }
 return offset ;
 }