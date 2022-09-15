static int dissect_h245_OLC_reverseLogicalChannelParameters ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 194 "../../asn1/h245/h245.cnf" upcoming_channel = ( upcoming_olc ) ? & upcoming_olc -> rev_lc : NULL ;
 offset = dissect_per_sequence ( tvb , offset , actx , tree , hf_index , ett_h245_OLC_reverseLogicalChannelParameters , OLC_reverseLogicalChannelParameters_sequence ) ;
 if ( upcoming_channel && codec_type ) {
 g_strlcpy ( upcoming_channel -> data_type_str , codec_type , sizeof ( upcoming_channel -> data_type_str ) ) ;
 }
 upcoming_channel = NULL ;
 return offset ;
 }