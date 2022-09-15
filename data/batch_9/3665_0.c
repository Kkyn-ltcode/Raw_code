static int dissect_h245_DataModeApplication ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 523 "../../asn1/h245/h245.cnf" gint32 value ;
 offset = dissect_per_choice ( tvb , offset , actx , tree , hf_index , ett_h245_DataModeApplication , DataModeApplication_choice , & value ) ;
 codec_type = val_to_str ( value , h245_DataModeApplication_vals , "<unknown>" ) ;
 return offset ;
 }