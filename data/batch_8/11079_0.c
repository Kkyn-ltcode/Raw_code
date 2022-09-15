static int dissect_h225_T_empty_flg ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 377 "./asn1/h225/h225.cnf" h225_packet_info * h225_pi ;
 offset = dissect_per_null ( tvb , offset , actx , tree , hf_index ) ;
 # line 381 "./asn1/h225/h225.cnf" h225_pi = ( h225_packet_info * ) p_get_proto_data ( wmem_packet_scope ( ) , actx -> pinfo , proto_h225 , 0 ) ;
 if ( h225_pi != NULL ) {
 h225_pi -> cs_type = H225_EMPTY ;
 }
 return offset ;
 }