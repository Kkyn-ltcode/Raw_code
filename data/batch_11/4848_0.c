static int dissect_CPMConnect ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * parent_tree , gboolean in , void * private_data ) {
 proto_item * ti ;
 proto_tree * tree ;
 gint offset = 16 ;
 guint len ;
 guint32 version ;
 struct message_data * data = NULL ;
 struct mswsp_ct * ct = NULL ;
 ti = proto_tree_add_item ( parent_tree , hf_mswsp_msg , tvb , offset , - 1 , ENC_NA ) ;
 tree = proto_item_add_subtree ( ti , ett_mswsp_msg ) ;
 proto_item_set_text ( ti , "CPMConnect%s" , in ? "In" : "Out" ) ;
 col_append_str ( pinfo -> cinfo , COL_INFO , "Connect" ) ;
 ti = proto_tree_add_item_ret_uint ( tree , hf_mswsp_msg_Connect_Version , tvb , offset , 4 , ENC_LITTLE_ENDIAN , & version ) ;
 ct = get_create_converstation_data ( pinfo ) ;
 if ( ct ) {
 data = find_or_create_message_data ( ct , pinfo , 0xC8 , in , private_data ) ;
 if ( data ) {
 data -> content . version = version ;
 }
 }
 offset += 4 ;
 if ( in ) {
 guint32 blob_size1_off , blob_size2_off ;
 proto_tree * pad_tree ;
 pad_tree = proto_tree_add_subtree ( tree , tvb , offset , 0 , ett_mswsp_pad , & ti , "Padding" ) ;
 proto_tree_add_item ( tree , hf_mswsp_msg_ConnectIn_ClientIsRemote , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 blob_size1_off = offset ;
 offset += 4 ;
 offset = parse_padding ( tvb , offset , 8 , pad_tree , "_paddingcbBlob2" ) ;
 blob_size2_off = offset ;
 offset += 4 ;
 offset = parse_padding ( tvb , offset , 16 , pad_tree , "_padding" ) ;
 len = tvb_unicode_strsize ( tvb , offset ) ;
 proto_tree_add_item ( tree , hf_mswsp_msg_ConnectIn_MachineName , tvb , offset , len , ENC_LITTLE_ENDIAN | ENC_UCS_2 ) ;
 offset += len ;
 len = tvb_unicode_strsize ( tvb , offset ) ;
 ti = proto_tree_add_item ( tree , hf_mswsp_msg_ConnectIn_UserName , tvb , offset , len , ENC_LITTLE_ENDIAN | ENC_UCS_2 ) ;
 offset += len ;
 offset = parse_padding ( tvb , offset , 8 , pad_tree , "_paddingcPropSets" ) ;
 offset = parse_PropertySetArray ( tvb , pinfo , offset , blob_size1_off , tree , pad_tree , "PropSets" ) ;
 offset = parse_padding ( tvb , offset , 8 , pad_tree , "paddingExtPropset" ) ;
 offset = parse_PropertySetArray ( tvb , pinfo , offset , blob_size2_off , tree , pad_tree , "ExtPropset" ) ;
 offset = parse_padding ( tvb , offset , 8 , pad_tree , "???" ) ;
 DISSECTOR_ASSERT ( offset == ( int ) tvb_reported_length ( tvb ) ) ;
 proto_tree_move_item ( tree , ti , proto_tree_get_parent ( pad_tree ) ) ;
 }
 else {
 }
 return tvb_reported_length ( tvb ) ;
 }