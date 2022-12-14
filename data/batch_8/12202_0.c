static gint dissect_sep ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , gint offset , guint32 interface_id , guint32 adapter_id , guint32 chandle ) {
 proto_tree * sep_tree ;
 proto_item * sep_item ;
 guint i_sep = 1 ;
 guint media_type ;
 guint type ;
 guint seid ;
 guint in_use ;
 guint items ;
 guint32 direction ;
 direction = ( pinfo -> p2p_dir == P2P_DIR_SENT ) ? P2P_DIR_RECV : P2P_DIR_SENT ;
 items = tvb_reported_length_remaining ( tvb , offset ) / 2 ;
 while ( tvb_reported_length_remaining ( tvb , offset ) > 0 ) {
 seid = tvb_get_guint8 ( tvb , offset ) ;
 in_use = seid & 0x02 ;
 seid = seid >> 2 ;
 media_type = tvb_get_guint8 ( tvb , offset + 1 ) >> 4 ;
 type = ( tvb_get_guint8 ( tvb , offset + 1 ) & 0x08 ) >> 3 ;
 sep_item = proto_tree_add_none_format ( tree , hf_btavdtp_acp_sep , tvb , offset , 2 , "ACP SEP [%u - %s %s] item %u/%u" , seid , val_to_str_const ( media_type , media_type_vals , "unknown" ) , val_to_str_const ( type , sep_type_vals , "unknown" ) , i_sep , items ) ;
 sep_tree = proto_item_add_subtree ( sep_item , ett_btavdtp_sep ) ;
 proto_tree_add_item ( sep_tree , hf_btavdtp_sep_seid , tvb , offset , 1 , ENC_NA ) ;
 proto_tree_add_item ( sep_tree , hf_btavdtp_sep_inuse , tvb , offset , 1 , ENC_NA ) ;
 proto_tree_add_item ( sep_tree , hf_btavdtp_sep_rfa0 , tvb , offset , 1 , ENC_NA ) ;
 offset += 1 ;
 proto_tree_add_item ( sep_tree , hf_btavdtp_sep_media_type , tvb , offset , 1 , ENC_NA ) ;
 proto_tree_add_item ( sep_tree , hf_btavdtp_sep_type , tvb , offset , 1 , ENC_NA ) ;
 proto_tree_add_item ( sep_tree , hf_btavdtp_sep_rfa1 , tvb , offset , 1 , ENC_NA ) ;
 if ( ! pinfo -> fd -> flags . visited ) {
 sep_entry_t * sep_data ;
 wmem_tree_key_t key [ 7 ] ;
 guint32 frame_number = pinfo -> num ;
 key [ 0 ] . length = 1 ;
 key [ 0 ] . key = & interface_id ;
 key [ 1 ] . length = 1 ;
 key [ 1 ] . key = & adapter_id ;
 key [ 2 ] . length = 1 ;
 key [ 2 ] . key = & chandle ;
 key [ 3 ] . length = 1 ;
 key [ 3 ] . key = & direction ;
 key [ 4 ] . length = 1 ;
 key [ 4 ] . key = & seid ;
 key [ 5 ] . length = 1 ;
 key [ 5 ] . key = & frame_number ;
 key [ 6 ] . length = 0 ;
 key [ 6 ] . key = NULL ;
 sep_data = wmem_new0 ( wmem_file_scope ( ) , sep_entry_t ) ;
 sep_data -> seid = seid ;
 sep_data -> type = type ;
 sep_data -> media_type = media_type ;
 sep_data -> codec = - 1 ;
 if ( in_use ) {
 sep_data -> state = SEP_STATE_IN_USE ;
 }
 else {
 sep_data -> state = SEP_STATE_FREE ;
 }
 wmem_tree_insert32_array ( sep_list , key , sep_data ) ;
 }
 offset += 1 ;
 i_sep += 1 ;
 }
 col_append_fstr ( pinfo -> cinfo , COL_INFO , " - items: %u" , items ) ;
 return offset ;
 }