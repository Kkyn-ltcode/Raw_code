static int dissect_h245_OLC_ack_fw_lcn ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 offset = dissect_h245_LogicalChannelNumber ( tvb , offset , actx , tree , hf_index ) ;
 # line 274 "../../asn1/h245/h245.cnf" if ( upcoming_olc ) upcoming_olc -> fwd_lc_num = h245_lc_temp ;
 h223_fw_lc_num = h245_lc_temp ;
 return offset ;
 }