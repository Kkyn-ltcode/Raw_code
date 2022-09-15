static int dissect_h225_T_h245Ip6 ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 348 "./asn1/h225/h225.cnf" tvbuff_t * value_tvb ;
 ipv6_address = ipv6_address_zeros ;
 offset = dissect_per_octet_string ( tvb , offset , actx , tree , hf_index , 16 , 16 , FALSE , & value_tvb ) ;
 if ( value_tvb ) tvb_get_ipv6 ( value_tvb , 0 , & ipv6_address ) ;
 return offset ;
 }