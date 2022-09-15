static void dissect_rsvp_dclass ( proto_tree * ti , proto_tree * rsvp_object_tree , tvbuff_t * tvb , int offset , int obj_length , int rsvp_class _U_ , int type ) {
 int offset2 = offset + 4 ;
 int mylen ;
 proto_item_set_text ( ti , "DCLASS: " ) ;
 switch ( type ) {
 case 1 : proto_tree_add_uint ( rsvp_object_tree , hf_rsvp_ctype , tvb , offset + 3 , 1 , type ) ;
 for ( mylen = 4 ;
 mylen < obj_length ;
 mylen += 4 ) {
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_dclass_dscp , tvb , offset + mylen + 3 , 1 , ENC_BIG_ENDIAN ) ;
 proto_item_append_text ( ti , "%d%s" , tvb_get_guint8 ( tvb , offset + mylen + 3 ) >> 2 , mylen == obj_length - 4 ? "" : mylen < 16 ? ", " : mylen == 16 ? ", ..." : "" ) ;
 }
 break ;
 default : mylen = obj_length - 4 ;
 proto_tree_add_uint_format_value ( rsvp_object_tree , hf_rsvp_ctype , tvb , offset + 3 , 1 , type , "Unknown (%u)" , type ) ;
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_dclass_data , tvb , offset2 , mylen , ENC_NA ) ;
 break ;
 }
 }