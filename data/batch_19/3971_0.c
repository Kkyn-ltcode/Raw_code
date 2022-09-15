static int dissect_h245_Ack_mediaChannel ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 887 "../../asn1/h245/h245.cnf" if ( upcoming_channel ) upcoming_channel -> upcoming_addr = & upcoming_channel -> media_addr ;
 offset = dissect_h245_TransportAddress ( tvb , offset , actx , tree , hf_index ) ;
 # line 891 "../../asn1/h245/h245.cnf" if ( upcoming_channel ) upcoming_channel -> upcoming_addr = NULL ;
 return offset ;
 }