static guint32 dissect_netb_status_resp ( tvbuff_t * tvb , packet_info * pinfo _U_ , int offset , proto_tree * tree ) {
 guint8 status_response = tvb_get_guint8 ( tvb , offset + NB_DATA1 ) ;
 proto_item * td2 ;
 proto_tree * data2_tree ;
 nb_call_name_type ( tvb , offset , tree ) ;
 if ( status_response == 0 ) {
 proto_tree_add_uint_format_value ( tree , hf_netb_status_response , tvb , offset + NB_DATA1 , 1 , status_response , "NetBIOS 1.x or 2.0" ) ;
 }
 else {
 proto_tree_add_uint_format_value ( tree , hf_netb_status_response , tvb , offset + NB_DATA1 , 1 , status_response , "NetBIOS 2.1, %u names sent so far" , status_response ) ;
 }
 td2 = proto_tree_add_item ( tree , hf_netb_data2 , tvb , offset + NB_DATA2 , 2 , ENC_LITTLE_ENDIAN ) ;
 data2_tree = proto_item_add_subtree ( td2 , ett_netb_status ) ;
 proto_tree_add_item ( data2_tree , hf_netb_data2_frame , tvb , offset + NB_DATA2 , 2 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( data2_tree , hf_netb_data2_user , tvb , offset + NB_DATA2 , 2 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( data2_tree , hf_netb_data2_status , tvb , offset + NB_DATA2 , 2 , ENC_LITTLE_ENDIAN ) ;
 nb_xmit_corrl ( tvb , offset , tree ) ;
 netbios_add_name ( "Receiver's Name" , tvb , offset + NB_RECVER_NAME , tree ) ;
 netbios_add_name ( "Sender's Name" , tvb , offset + NB_SENDER_NAME , tree ) ;
 return 0 ;
 }