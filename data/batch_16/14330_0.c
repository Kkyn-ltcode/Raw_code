static int dissect_pvfs_flowproto_type ( tvbuff_t * tvb , proto_tree * tree , int offset ) {
 proto_tree_add_item ( tree , hf_pvfs_flowproto_type , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 return offset ;
 }