int dissect_ber_GeneralizedTime ( gboolean implicit_tag , asn1_ctx_t * actx , proto_tree * tree , tvbuff_t * tvb , int offset , gint hf_id ) {
 char str [ 35 ] ;
 int tmp_int ;
 const guint8 * tmpstr ;
 char * strptr ;
 char first_delim [ 2 ] ;
 int first_digits ;
 char second_delim [ 2 ] ;
 int second_digits ;
 int ret ;
 gint8 ber_class ;
 gboolean pc ;
 gint32 tag ;
 guint32 len ;
 int end_offset ;
 int hoffset ;
 proto_item * cause ;
 if ( ! implicit_tag ) {
 hoffset = offset ;
 offset = dissect_ber_identifier ( actx -> pinfo , tree , tvb , offset , & ber_class , & pc , & tag ) ;
 offset = dissect_ber_length ( actx -> pinfo , tree , tvb , offset , & len , NULL ) ;
 end_offset = offset + len ;
 if ( ( ber_class != BER_CLASS_UNI ) || ( tag != BER_UNI_TAG_GeneralizedTime ) ) {
 tvb_ensure_bytes_exist ( tvb , hoffset , 2 ) ;
 cause = proto_tree_add_string_format_value ( tree , hf_ber_error , tvb , offset , len , "generalized_time_expected" , "GeneralizedTime expected but class:%s(%d) %s tag:%d was unexpected" , val_to_str_const ( ber_class , ber_class_codes , "Unknown" ) , ber_class , pc ? ber_pc_codes_short . true_string : ber_pc_codes_short . false_string , tag ) ;
 expert_add_info ( actx -> pinfo , cause , & ei_ber_expected_generalized_time ) ;
 if ( decode_unexpected ) {
 proto_tree * unknown_tree = proto_item_add_subtree ( cause , ett_ber_unknown ) ;
 dissect_unknown_ber ( actx -> pinfo , tvb , hoffset , unknown_tree ) ;
 }
 return end_offset ;
 }
 }
 else {
 len = tvb_reported_length_remaining ( tvb , offset ) ;
 end_offset = offset + len ;
 }
 if ( ( len < 14 ) || ( len > 23 ) ) {
 cause = proto_tree_add_string_format_value ( tree , hf_ber_error , tvb , offset , len , "illegal_length" , "GeneralizedTime invalid length: %u" , len ) ;
 expert_add_info_format ( actx -> pinfo , cause , & ei_ber_error_length , "BER Error: GeneralizedTime invalid length" ) ;
 if ( decode_unexpected ) {
 proto_tree * unknown_tree = proto_item_add_subtree ( cause , ett_ber_unknown ) ;
 dissect_unknown_ber ( actx -> pinfo , tvb , offset , unknown_tree ) ;
 }
 return end_offset ;
 }
 tmpstr = tvb_get_string_enc ( wmem_packet_scope ( ) , tvb , offset , len , ENC_ASCII ) ;
 strptr = str ;
 strptr += g_snprintf ( str , 20 , "%.4s-%.2s-%.2s %.2s:%.2s:%.2s" , tmpstr , tmpstr + 4 , tmpstr + 6 , tmpstr + 8 , tmpstr + 10 , tmpstr + 12 ) ;
 first_delim [ 0 ] = 0 ;
 second_delim [ 0 ] = 0 ;
 ret = sscanf ( tmpstr , "%14d%1[.,+-Z]%4d%1[+-Z]%4d" , & tmp_int , first_delim , & first_digits , second_delim , & second_digits ) ;
 if ( ret < 1 ) {
 goto invalid ;
 }
 if ( ret >= 2 ) {
 switch ( first_delim [ 0 ] ) {
 case '.' : case ',' : if ( ret == 2 ) {
 goto invalid ;
 }
 strptr += g_snprintf ( strptr , 5 , "%c%.3d" , first_delim [ 0 ] , first_digits ) ;
 if ( ret >= 4 ) {
 switch ( second_delim [ 0 ] ) {
 case '+' : case '-' : if ( ret == 4 ) {
 goto invalid ;
 }
 g_snprintf ( strptr , 12 , " (UTC%c%.4d)" , second_delim [ 0 ] , second_digits ) ;
 break ;
 case 'Z' : g_snprintf ( strptr , 7 , " (UTC)" ) ;
 break ;
 default : break ;
 }
 }
 break ;
 case '+' : case '-' : if ( ret == 2 ) {
 goto invalid ;
 }
 g_snprintf ( strptr , 12 , " (UTC%c%.4d)" , first_delim [ 0 ] , first_digits ) ;
 break ;
 case 'Z' : g_snprintf ( strptr , 7 , " (UTC)" ) ;
 break ;
 default : break ;
 }
 }
 if ( hf_id >= 0 ) {
 proto_tree_add_string ( tree , hf_id , tvb , offset , len , str ) ;
 }
 offset += len ;
 return offset ;
 invalid : cause = proto_tree_add_string_format_value ( tree , hf_ber_error , tvb , offset , len , "invalid_generalized_time" , "GeneralizedTime invalid format: %s" , tmpstr ) ;
 expert_add_info ( actx -> pinfo , cause , & ei_ber_invalid_format_generalized_time ) ;
 if ( decode_unexpected ) {
 proto_tree * unknown_tree = proto_item_add_subtree ( cause , ett_ber_unknown ) ;
 dissect_unknown_ber ( actx -> pinfo , tvb , offset , unknown_tree ) ;
 }
 return end_offset ;
 }