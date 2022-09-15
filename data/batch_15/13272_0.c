static int dissect_t38_T30_data ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 offset = dissect_per_enumerated ( tvb , offset , actx , tree , hf_index , 9 , & Data_value , TRUE , 6 , NULL ) ;
 # line 41 "../../asn1/t38/t38.cnf" if ( primary_part ) {
 col_append_fstr ( actx -> pinfo -> cinfo , COL_INFO , " data:%s:" , val_to_str ( Data_value , t38_T30_data_vals , "<unknown>" ) ) ;
 }
 if ( primary_part ) t38_info -> data_value = Data_value ;
 return offset ;
 }