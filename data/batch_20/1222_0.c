static void dissect_zcl_scenes_add_remove_store_scene_response ( tvbuff_t * tvb , proto_tree * tree , guint * offset ) {
 proto_tree_add_item ( tree , hf_zbee_zcl_scenes_status , tvb , * offset , 1 , ENC_LITTLE_ENDIAN ) ;
 * offset += 1 ;
 proto_tree_add_item ( tree , hf_zbee_zcl_scenes_group_id , tvb , * offset , 2 , ENC_LITTLE_ENDIAN ) ;
 * offset += 2 ;
 proto_tree_add_item ( tree , hf_zbee_zcl_scenes_scene_id , tvb , * offset , 1 , ENC_LITTLE_ENDIAN ) ;
 * offset += 1 ;
 }