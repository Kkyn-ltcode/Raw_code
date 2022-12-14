static void dissect_coap_opt_object_security ( tvbuff_t * tvb , proto_item * head_item , proto_tree * subtree , gint offset , gint opt_length , packet_info * pinfo , coap_info * coinfo , coap_common_dissect_t * dissect_hf ) {
 guint8 flag_byte = 0 ;
 gboolean non_compressed = FALSE ;
 gboolean expand = FALSE ;
 gboolean signature_present = FALSE ;
 gboolean kid_context_present = FALSE ;
 gboolean kid_present = FALSE ;
 guint8 piv_len = 0 ;
 guint8 kid_context_len = 0 ;
 guint8 kid_len = 0 ;
 coinfo -> object_security = TRUE ;
 coinfo -> oscore_info -> piv = NULL ;
 coinfo -> oscore_info -> piv_len = 0 ;
 coinfo -> oscore_info -> kid_context = NULL ;
 coinfo -> oscore_info -> kid_context_len = 0 ;
 coinfo -> oscore_info -> kid = NULL ;
 coinfo -> oscore_info -> kid_len = 0 ;
 if ( opt_length == 0 ) {
 proto_item_append_text ( head_item , ": 00 (no Flag Byte)" ) ;
 }
 else {
 flag_byte = tvb_get_guint8 ( tvb , offset ) ;
 proto_tree_add_item ( subtree , dissect_hf -> hf . opt_object_security_non_compressed , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 non_compressed = flag_byte & COAP_OBJECT_SECURITY_NON_COMPRESSED_MASK ;
 proto_tree_add_item ( subtree , dissect_hf -> hf . opt_object_security_expand , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 expand = flag_byte & COAP_OBJECT_SECURITY_EXPAND_MASK ;
 proto_tree_add_item ( subtree , dissect_hf -> hf . opt_object_security_signature , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 signature_present = flag_byte & COAP_OBJECT_SECURITY_SIGNATURE_MASK ;
 proto_tree_add_item ( subtree , dissect_hf -> hf . opt_object_security_kid_context_present , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 kid_context_present = flag_byte & COAP_OBJECT_SECURITY_KID_CONTEXT_MASK ;
 proto_tree_add_item ( subtree , dissect_hf -> hf . opt_object_security_kid_present , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 kid_present = flag_byte & COAP_OBJECT_SECURITY_KID_MASK ;
 proto_tree_add_item ( subtree , dissect_hf -> hf . opt_object_security_piv_len , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 piv_len = ( flag_byte & COAP_OBJECT_SECURITY_PIVLEN_MASK ) >> 0 ;
 kid_len = opt_length ;
 offset += 1 ;
 kid_len -= 1 ;
 if ( non_compressed || expand || signature_present ) {
 expert_add_info_format ( pinfo , subtree , & dissect_hf -> ei . opt_object_security_bad , "Unsupported format" ) ;
 }
 if ( piv_len > 0 ) {
 proto_tree_add_item ( subtree , dissect_hf -> hf . opt_object_security_piv , tvb , offset , piv_len , ENC_NA ) ;
 coinfo -> oscore_info -> piv = ( guint8 * ) tvb_memdup ( wmem_packet_scope ( ) , tvb , offset , piv_len ) ;
 coinfo -> oscore_info -> piv_len = piv_len ;
 offset += piv_len ;
 kid_len -= piv_len ;
 }
 if ( kid_context_present ) {
 proto_tree_add_item ( subtree , dissect_hf -> hf . opt_object_security_kid_context_len , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 kid_context_len = tvb_get_guint8 ( tvb , offset ) ;
 offset += 1 ;
 kid_len -= 1 ;
 proto_tree_add_item ( subtree , dissect_hf -> hf . opt_object_security_kid_context , tvb , offset , kid_context_len , ENC_NA ) ;
 coinfo -> oscore_info -> kid_context = ( guint8 * ) tvb_memdup ( wmem_packet_scope ( ) , tvb , offset , kid_context_len ) ;
 coinfo -> oscore_info -> kid_context_len = kid_context_len ;
 offset += kid_context_len ;
 kid_len -= kid_context_len ;
 }
 if ( kid_present ) {
 if ( kid_len > 0 ) {
 proto_tree_add_item ( subtree , dissect_hf -> hf . opt_object_security_kid , tvb , offset , kid_len , ENC_NA ) ;
 coinfo -> oscore_info -> kid = ( guint8 * ) tvb_memdup ( wmem_packet_scope ( ) , tvb , offset , kid_len ) ;
 coinfo -> oscore_info -> kid_len = kid_len ;
 }
 else {
 expert_add_info_format ( pinfo , subtree , & dissect_hf -> ei . opt_object_security_bad , "Key ID flag is set but there are no remaining bytes to be processed" ) ;
 }
 }
 proto_item_append_text ( head_item , ": Key ID:%s, Key ID Context:%s, Partial IV:%s" , coinfo -> oscore_info -> kid == NULL ? nullstr : bytes_to_str ( wmem_packet_scope ( ) , coinfo -> oscore_info -> kid , coinfo -> oscore_info -> kid_len ) , coinfo -> oscore_info -> kid_context == NULL ? nullstr : bytes_to_str ( wmem_packet_scope ( ) , coinfo -> oscore_info -> kid_context , coinfo -> oscore_info -> kid_context_len ) , coinfo -> oscore_info -> piv == NULL ? nullstr : bytes_to_str ( wmem_packet_scope ( ) , coinfo -> oscore_info -> piv , coinfo -> oscore_info -> piv_len ) ) ;
 }
 }