static int dissect_t38_T_error_recovery ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 258 "../../asn1/t38/t38.cnf" primary_part = FALSE ;
 offset = dissect_per_choice ( tvb , offset , actx , tree , hf_index , ett_t38_T_error_recovery , T_error_recovery_choice , NULL ) ;
 # line 260 "../../asn1/t38/t38.cnf" primary_part = TRUE ;
 return offset ;
 }