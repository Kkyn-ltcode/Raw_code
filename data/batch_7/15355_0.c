static int dissect_rsl_ie_starting_time ( tvbuff_t * tvb , packet_info * pinfo _U_ , proto_tree * tree , int offset , gboolean is_mandatory ) {
 proto_tree * ie_tree ;
 guint8 ie_id ;
 if ( is_mandatory == FALSE ) {
 ie_id = tvb_get_guint8 ( tvb , offset ) ;
 if ( ie_id != RSL_IE_STARTING_TIME ) return offset ;
 }
 ie_tree = proto_tree_add_subtree ( tree , tvb , offset , 3 , ett_ie_staring_time , NULL , "Starting Time IE" ) ;
 proto_tree_add_item ( ie_tree , hf_rsl_ie_id , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 offset ++ ;
 proto_tree_add_item ( ie_tree , hf_rsl_req_ref_T1prim , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( ie_tree , hf_rsl_req_ref_T3 , tvb , offset , 2 , ENC_BIG_ENDIAN ) ;
 offset ++ ;
 proto_tree_add_item ( ie_tree , hf_rsl_req_ref_T2 , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 offset ++ ;
 return offset ;
 }