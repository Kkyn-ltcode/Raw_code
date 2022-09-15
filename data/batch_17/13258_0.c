static int dissect_t38_UDPTLPacket ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 232 "../../asn1/t38/t38.cnf" Data_Field_field_type_value = 1 ;
 offset = dissect_per_sequence ( tvb , offset , actx , tree , hf_index , ett_t38_UDPTLPacket , UDPTLPacket_sequence ) ;
 return offset ;
 }