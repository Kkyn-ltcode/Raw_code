static int dissect_h245_T_nsd_data ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 981 "../../asn1/h245/h245.cnf" tvbuff_t * next_tvb = NULL ;
 offset = dissect_per_octet_string ( tvb , offset , actx , tree , hf_index , NO_BOUND , NO_BOUND , FALSE , & next_tvb ) ;
 if ( next_tvb && tvb_length ( next_tvb ) ) {
 call_dissector ( ( nsp_handle ) ? nsp_handle : data_handle , next_tvb , actx -> pinfo , tree ) ;
 }
 return offset ;
 }