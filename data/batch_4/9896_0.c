static void dissect_rsvp_link_cap ( proto_item * ti , packet_info * pinfo , proto_tree * rsvp_object_tree , tvbuff_t * tvb , int offset , int obj_length , int rsvp_class , int type ) {
 proto_item_set_text ( ti , "LINK CAPABILITY: " ) ;
 switch ( type ) {
 case 1 : proto_tree_add_uint ( rsvp_object_tree , hf_rsvp_ctype , tvb , offset + 3 , 1 , type ) ;
 dissect_rsvp_ero_rro_subobjects ( ti , pinfo , rsvp_object_tree , tvb , offset + 4 , obj_length , rsvp_class ) ;
 break ;
 default : proto_tree_add_uint_format_value ( rsvp_object_tree , hf_rsvp_ctype , tvb , offset + 3 , 1 , type , "Unknown (%u)" , type ) ;
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_record_route_data , tvb , offset + 4 , obj_length - 4 , ENC_NA ) ;
 break ;
 }
 }