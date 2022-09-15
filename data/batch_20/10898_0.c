static int dissect_h225_CallProceeding_UUIE ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 489 "./asn1/h225/h225.cnf" h225_packet_info * h225_pi ;
 offset = dissect_per_sequence ( tvb , offset , actx , tree , hf_index , ett_h225_CallProceeding_UUIE , CallProceeding_UUIE_sequence ) ;
 # line 493 "./asn1/h225/h225.cnf" h225_pi = ( h225_packet_info * ) p_get_proto_data ( wmem_packet_scope ( ) , actx -> pinfo , proto_h225 , 0 ) ;
 if ( h225_pi != NULL ) {
 h225_pi -> cs_type = H225_CALL_PROCEDING ;
 if ( contains_faststart ) {
 char temp [ 50 ] ;
 g_snprintf ( temp , 50 , "%s OLC (%s)" , val_to_str ( h225_pi -> cs_type , T_h323_message_body_vals , "<unknown>" ) , h225_pi -> frame_label ) ;
 g_strlcpy ( h225_pi -> frame_label , temp , 50 ) ;
 }
 else g_snprintf ( h225_pi -> frame_label , 50 , "%s" , val_to_str ( h225_pi -> cs_type , T_h323_message_body_vals , "<unknown>" ) ) ;
 }
 return offset ;
 }