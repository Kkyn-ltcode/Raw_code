proto_item * parseInt64 ( proto_tree * tree , tvbuff_t * tvb , packet_info * pinfo _U_ , gint * pOffset , int hfIndex ) {
 proto_item * item = proto_tree_add_item ( tree , hfIndex , tvb , * pOffset , 8 , ENC_LITTLE_ENDIAN ) ;
 * pOffset += 8 ;
 return item ;
 }