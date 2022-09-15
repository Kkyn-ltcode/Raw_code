static int dissect_rsl_ie_smscb_mess ( tvbuff_t * tvb , packet_info * pinfo _U_ , proto_tree * tree , int offset , gboolean is_mandatory ) {
 proto_item * ti ;
 proto_tree * ie_tree ;
 tvbuff_t * next_tvb ;
 guint length ;
 guint8 ie_id ;
 int ie_offset ;
 if ( is_mandatory == FALSE ) {
 ie_id = tvb_get_guint8 ( tvb , offset ) ;
 if ( ie_id != RSL_IE_SMSCB_MESS ) return offset ;
 }
 ie_tree = proto_tree_add_subtree ( tree , tvb , offset , 0 , ett_ie_smscb_mess , & ti , "SMSCB Message IE" ) ;
 proto_tree_add_item ( ie_tree , hf_rsl_ie_id , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 offset ++ ;
 length = tvb_get_guint8 ( tvb , offset ) ;
 proto_item_set_len ( ti , length + 2 ) ;
 proto_tree_add_item ( ie_tree , hf_rsl_ie_length , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 offset ++ ;
 ie_offset = offset ;
 next_tvb = tvb_new_subset_length ( tvb , offset , length ) ;
 call_dissector ( gsm_cbs_handle , next_tvb , pinfo , top_tree ) ;
 offset = ie_offset + length ;
 return offset ;
 }