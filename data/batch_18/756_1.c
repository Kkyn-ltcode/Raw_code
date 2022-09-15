static int dissect_CPMGetRows ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * parent_tree , gboolean in , void * private_data ) {
 struct mswsp_ct * ct = NULL ;
 gint offset = 16 ;
 proto_item * item ;
 proto_tree * tree ;
 proto_tree * seek_tree ;
 guint32 eType = 0 ;
 item = proto_tree_add_item ( parent_tree , hf_mswsp_msg , tvb , offset , in ? 0 : - 1 , ENC_NA ) ;
 tree = proto_item_add_subtree ( item , ett_mswsp_msg ) ;
 proto_item_set_text ( item , "GetRows%s" , in ? "In" : "Out" ) ;
 col_append_str ( pinfo -> cinfo , COL_INFO , "GetRows" ) ;
 ct = get_create_converstation_data ( pinfo ) ;
 if ( in ) {
 struct message_data * data = NULL ;
 proto_tree_add_item ( tree , hf_mswsp_msg_cpmgetrows_hcursor , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_item ( tree , hf_mswsp_msg_cpmgetrows_rowstotransfer , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_item ( tree , hf_mswsp_msg_cpmgetrows_rowwidth , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_item ( tree , hf_mswsp_msg_cpmgetrows_cbseek , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 data = find_or_create_message_data ( ct , pinfo , 0xCC , in , private_data ) ;
 if ( data ) {
 data -> content . rowsin . cbreserved = tvb_get_letohl ( tvb , offset ) ;
 }
 proto_tree_add_item ( tree , hf_mswsp_msg_cpmgetrows_cbreserved , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_item ( tree , hf_mswsp_msg_cpmgetrows_cbreadbuffer , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 if ( data ) {
 data -> content . rowsin . ulclientbase = tvb_get_letohl ( tvb , offset ) ;
 }
 proto_tree_add_item ( tree , hf_mswsp_msg_cpmgetrows_ulclientbase , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_item ( tree , hf_mswsp_msg_cpmgetrows_fbwdfetch , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 eType = tvb_get_letohl ( tvb , offset ) ;
 proto_tree_add_item ( tree , hf_mswsp_msg_cpmgetrows_etype , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_item ( tree , hf_mswsp_msg_cpmgetrows_chapt , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 seek_tree = proto_tree_add_subtree ( tree , tvb , offset , 0 , ett_SeekDescription , NULL , "SeekDescription" ) ;
 switch ( eType ) {
 case 0 : break ;
 case 1 : parse_CRowSeekNext ( tvb , offset , seek_tree , "CRowSeekNext" ) ;
 break ;
 case 2 : parse_CRowSeekAt ( tvb , offset , seek_tree , "CRowSeekAt" ) ;
 break ;
 case 3 : parse_CRowSeekAtRatio ( tvb , offset , seek_tree , "CRowSeekAtRatio" ) ;
 break ;
 case 4 : parse_CRowSeekByBookmark ( tvb , offset , seek_tree , "CRowSeekByRatio" ) ;
 break ;
 default : break ;
 }
 }
 else {
 guint32 num_rows = 0 ;
 proto_item * ti ;
 proto_tree * pad_tree = proto_tree_add_subtree ( tree , tvb , offset , 0 , ett_mswsp_pad , & ti , "Padding" ) ;
 struct CPMSetBindingsIn * bindingsin = find_binding_msg_data ( ct , pinfo , private_data ) ;
 struct rows_data * rowsin = find_rowsin_msg_data ( ct , pinfo , private_data ) ;
 gboolean b_64bit_mode = FALSE ;
 gboolean b_has_arch = is_64bit_mode ( ct , pinfo , & b_64bit_mode , private_data ) ;
 num_rows = tvb_get_letohl ( tvb , offset ) ;
 proto_tree_add_item ( tree , hf_mswsp_msg_cpmgetrows_crowsreturned , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 eType = tvb_get_letohl ( tvb , offset ) ;
 proto_tree_add_item ( tree , hf_mswsp_msg_cpmgetrows_etype , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_item ( tree , hf_mswsp_msg_cpmgetrows_chapt , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 seek_tree = proto_tree_add_subtree ( tree , tvb , offset , 0 , ett_SeekDescription , NULL , "SeekDescription" ) ;
 switch ( eType ) {
 case 0 : break ;
 case 1 : parse_CRowSeekNext ( tvb , offset , seek_tree , "CRowSeekNext" ) ;
 break ;
 case 2 : parse_CRowSeekAt ( tvb , offset , seek_tree , "CRowSeekAt" ) ;
 break ;
 case 3 : parse_CRowSeekAtRatio ( tvb , offset , seek_tree , "CRowSeekAtRatio" ) ;
 break ;
 case 4 : parse_CRowSeekByBookmark ( tvb , offset , seek_tree , "CRowSeekByRatio" ) ;
 break ;
 default : break ;
 }
 if ( b_has_arch && bindingsin && rowsin ) {
 offset = parse_padding ( tvb , offset , rowsin -> cbreserved , pad_tree , "paddingRows" ) ;
 parse_RowsBuffer ( tvb , offset , num_rows , bindingsin , rowsin , b_64bit_mode , tree , "Rows" ) ;
 }
 else {
 gint nbytes = tvb_reported_length_remaining ( tvb , offset ) ;
 proto_tree_add_expert_format ( tree , pinfo , & ei_missing_msg_context , tvb , offset , nbytes , "Undissected %d bytes (due to missing preceding msg(s))" , nbytes ) ;
 }
 }
 return tvb_reported_length ( tvb ) ;
 }