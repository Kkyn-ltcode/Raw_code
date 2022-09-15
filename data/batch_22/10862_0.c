int dissect_h225_TunnelledProtocol ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 760 "./asn1/h225/h225.cnf" tpOID = "" ;
 offset = dissect_per_sequence ( tvb , offset , actx , tree , hf_index , ett_h225_TunnelledProtocol , TunnelledProtocol_sequence ) ;
 # line 762 "./asn1/h225/h225.cnf" tp_handle = dissector_get_string_handle ( tp_dissector_table , tpOID ) ;
 return offset ;
 }