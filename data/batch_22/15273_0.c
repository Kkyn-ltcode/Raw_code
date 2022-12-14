static int dissect_mac_fdd_fach ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , void * data ) {
 guint8 hdr , tctf ;
 guint16 bitoffs = 0 ;
 guint16 tctf_len , chan ;
 proto_tree * fach_tree = NULL ;
 proto_item * channel_type ;
 tvbuff_t * next_tvb ;
 umts_mac_info * macinf ;
 fp_info * fpinf ;
 rlc_info * rlcinf ;
 struct rrc_info * rrcinf ;
 proto_item * ti = NULL ;
 gint c_t ;
 hdr = tvb_get_guint8 ( tvb , 0 ) ;
 tctf = fach_fdd_tctf ( hdr , & bitoffs ) ;
 tctf_len = bitoffs ;
 col_set_str ( pinfo -> cinfo , COL_PROTOCOL , "MAC" ) ;
 col_set_str ( pinfo -> cinfo , COL_INFO , val_to_str_const ( tctf , fach_fdd_tctf_vals , "Unknown TCTF" ) ) ;
 ti = proto_tree_add_item ( tree , proto_umts_mac , tvb , 0 , - 1 , ENC_NA ) ;
 fach_tree = proto_item_add_subtree ( ti , ett_mac_fach ) ;
 macinf = ( umts_mac_info * ) p_get_proto_data ( wmem_file_scope ( ) , pinfo , proto_umts_mac , 0 ) ;
 fpinf = ( fp_info * ) p_get_proto_data ( wmem_file_scope ( ) , pinfo , proto_fp , 0 ) ;
 rlcinf = ( rlc_info * ) p_get_proto_data ( wmem_file_scope ( ) , pinfo , proto_rlc , 0 ) ;
 if ( ! macinf || ! fpinf ) {
 proto_tree_add_expert ( fach_tree , pinfo , & ei_mac_per_frame_info_missing , tvb , 0 , - 1 ) ;
 return 1 ;
 }
 proto_tree_add_bits_item ( fach_tree , hf_mac_fach_fdd_tctf , tvb , 0 , tctf_len , ENC_BIG_ENDIAN ) ;
 if ( tctf == TCTF_DCCH_DTCH_FACH_FDD ) {
 macinf -> ctmux [ fpinf -> cur_tb ] = 1 ;
 bitoffs = tree_add_common_dcch_dtch_fields ( tvb , pinfo , fach_tree , bitoffs , fpinf , macinf , rlcinf ) ;
 }
 chan = fpinf -> cur_chan ;
 switch ( tctf ) {
 case TCTF_CCCH_FACH_FDD : proto_item_append_text ( ti , " (CCCH)" ) ;
 channel_type = proto_tree_add_uint ( fach_tree , hf_mac_channel , tvb , 0 , 0 , MAC_CCCH ) ;
 PROTO_ITEM_SET_GENERATED ( channel_type ) ;
 next_tvb = tvb_new_subset_remaining ( tvb , 1 ) ;
 call_dissector_with_data ( rlc_ccch_handle , next_tvb , pinfo , tree , data ) ;
 break ;
 case TCTF_DCCH_DTCH_FACH_FDD : c_t = tvb_get_bits8 ( tvb , bitoffs - 4 , 4 ) ;
 if ( c_t == 15 ) {
 expert_add_info ( pinfo , NULL , & ei_mac_reserved_c_t ) ;
 break ;
 }
 rlcinf -> mode [ fpinf -> cur_tb ] = lchId_rlc_map [ c_t + 1 ] ;
 macinf -> content [ fpinf -> cur_tb ] = lchId_type_table [ c_t + 1 ] ;
 switch ( macinf -> content [ fpinf -> cur_tb ] ) {
 case MAC_CONTENT_DCCH : proto_item_append_text ( ti , " (DCCH)" ) ;
 channel_type = proto_tree_add_uint ( fach_tree , hf_mac_channel , tvb , 0 , 0 , MAC_DCCH ) ;
 PROTO_ITEM_SET_GENERATED ( channel_type ) ;
 next_tvb = tvb_new_octet_aligned ( tvb , bitoffs , fpinf -> chan_tf_size [ chan ] - bitoffs ) ;
 add_new_data_source ( pinfo , next_tvb , "Octet-Aligned DCCH Data" ) ;
 call_dissector_with_data ( rlc_dcch_handle , next_tvb , pinfo , tree , data ) ;
 break ;
 case MAC_CONTENT_PS_DTCH : proto_item_append_text ( ti , " (PS DTCH)" ) ;
 channel_type = proto_tree_add_uint ( fach_tree , hf_mac_channel , tvb , 0 , 0 , MAC_DTCH ) ;
 PROTO_ITEM_SET_GENERATED ( channel_type ) ;
 next_tvb = tvb_new_octet_aligned ( tvb , bitoffs , fpinf -> chan_tf_size [ chan ] - bitoffs ) ;
 add_new_data_source ( pinfo , next_tvb , "Octet-Aligned DCCH Data" ) ;
 call_dissector_with_data ( rlc_ps_dtch_handle , next_tvb , pinfo , tree , data ) ;
 break ;
 case MAC_CONTENT_CS_DTCH : proto_item_append_text ( ti , " (CS DTCH)" ) ;
 expert_add_info ( pinfo , NULL , & ei_mac_cs_dtch_not_implemented ) ;
 break ;
 default : proto_item_append_text ( ti , " (Unknown FACH Content" ) ;
 expert_add_info_format ( pinfo , NULL , & ei_mac_unknown_content , "Unknown FACH Content for this transportblock" ) ;
 }
 break ;
 case TCTF_CTCH_FACH_FDD : proto_item_append_text ( ti , " (CTCH)" ) ;
 channel_type = proto_tree_add_uint ( fach_tree , hf_mac_channel , tvb , 0 , 0 , MAC_CTCH ) ;
 PROTO_ITEM_SET_GENERATED ( channel_type ) ;
 next_tvb = tvb_new_subset_remaining ( tvb , 1 ) ;
 call_dissector_with_data ( rlc_ctch_handle , next_tvb , pinfo , tree , data ) ;
 break ;
 case TCTF_BCCH_FACH_FDD : proto_item_append_text ( ti , " (BCCH)" ) ;
 channel_type = proto_tree_add_uint ( fach_tree , hf_mac_channel , tvb , 0 , 0 , MAC_BCCH ) ;
 PROTO_ITEM_SET_GENERATED ( channel_type ) ;
 next_tvb = tvb_new_octet_aligned ( tvb , 2 , ( tvb_reported_length ( tvb ) * 8 ) - 2 ) ;
 add_new_data_source ( pinfo , next_tvb , "Octet-Aligned BCCH Data" ) ;
 rrcinf = ( rrc_info * ) p_get_proto_data ( wmem_file_scope ( ) , pinfo , proto_rrc , 0 ) ;
 if ( ! rrcinf ) {
 rrcinf = wmem_new0 ( wmem_file_scope ( ) , struct rrc_info ) ;
 p_add_proto_data ( wmem_file_scope ( ) , pinfo , proto_rrc , 0 , rrcinf ) ;
 }
 rrcinf -> msgtype [ fpinf -> cur_tb ] = RRC_MESSAGE_TYPE_BCCH_FACH ;
 call_dissector_with_data ( rrc_handle , next_tvb , pinfo , tree , data ) ;
 break ;
 case TCTF_MSCH_FACH_FDD : case TCTF_MCCH_FACH_FDD : case TCTF_MTCH_FACH_FDD : expert_add_info ( pinfo , NULL , & ei_mac_fach_content_type_unknown ) ;
 break ;
 default : proto_item_append_text ( ti , " (Unknown FACH Content)" ) ;
 expert_add_info_format ( pinfo , NULL , & ei_mac_unknown_content , " Unknown FACH Content" ) ;
 break ;
 }
 return tvb_captured_length ( tvb ) ;
 }