void dissect_q931_cause_ie ( tvbuff_t * tvb , int offset , int len , proto_tree * tree , int hf_cause_value , guint8 * cause_value , const value_string * ie_vals ) {
 dissect_q931_cause_ie_with_info ( tvb , offset , len , tree , hf_cause_value , cause_value , ie_vals , NULL ) ;
 }