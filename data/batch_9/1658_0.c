int dissect_ber_real ( gboolean implicit_tag , asn1_ctx_t * actx , proto_tree * tree , tvbuff_t * tvb , int offset , gint hf_id _U_ , double * value ) {
 gint8 ber_class ;
 gboolean pc ;
 gint32 tag ;
 guint32 val_length = 0 , len_remain , end_offset ;
 double val = 0 ;
 proto_item * cause ;
 if ( ! implicit_tag ) {
 offset = dissect_ber_identifier ( actx -> pinfo , tree , tvb , offset , & ber_class , & pc , & tag ) ;
 offset = dissect_ber_length ( actx -> pinfo , tree , tvb , offset , & val_length , NULL ) ;
 end_offset = offset + val_length ;
 }
 else {
 get_last_ber_identifier ( & ber_class , & pc , & tag ) ;
 get_last_ber_length ( & val_length , NULL ) ;
 end_offset = offset + val_length ;
 len_remain = ( guint32 ) tvb_reported_length_remaining ( tvb , offset ) ;
 if ( len_remain < val_length ) {
 cause = proto_tree_add_string_format_value ( tree , hf_ber_error , tvb , offset , val_length , "illegal_length" , "length:%u longer than tvb_reported_length_remaining:%d" , val_length , len_remain ) ;
 expert_add_info ( actx -> pinfo , cause , & ei_ber_error_length ) ;
 return end_offset ;
 }
 }
 if ( pc ) {
 cause = proto_tree_add_string_format_value ( tree , hf_ber_error , tvb , offset - 2 , 1 , "wrong_tag" , "REAL class must be encoded as primitive" ) ;
 expert_add_info ( actx -> pinfo , cause , & ei_ber_error_length ) ;
 }
 val = asn1_get_real ( tvb_get_ptr ( tvb , offset , val_length ) , val_length ) ;
 actx -> created_item = proto_tree_add_double ( tree , hf_id , tvb , end_offset - val_length , val_length , val ) ;
 if ( value ) * value = val ;
 return end_offset ;
 }