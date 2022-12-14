static int dissect_mac_fdd_rach ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , void * data ) {
 guint8 tctf ;
 guint8 chan ;
 guint16 bitoffs = 0 ;
 tvbuff_t * next_tvb ;
 proto_tree * rach_tree = NULL ;
 proto_item * channel_type ;
 umts_mac_info * macinf ;
 fp_info * fpinf ;
 rlc_info * rlcinf ;
 proto_item * ti = NULL ;
 guint8 c_t ;
 tctf = tvb_get_bits8 ( tvb , 0 , 2 ) ;
 bitoffs += 2 ;
 col_set_str ( pinfo -> cinfo , COL_PROTOCOL , "MAC" ) ;
 col_set_str ( pinfo -> cinfo , COL_INFO , val_to_str_const ( tctf , rach_fdd_tctf_vals , "Unknown TCTF" ) ) ;
 ti = proto_tree_add_item ( tree , proto_umts_mac , tvb , 0 , - 1 , ENC_NA ) ;
 rach_tree = proto_item_add_subtree ( ti , ett_mac_rach ) ;
 macinf = ( umts_mac_info * ) p_get_proto_data ( wmem_file_scope ( ) , pinfo , proto_umts_mac , 0 ) ;
 fpinf = ( fp_info * ) p_get_proto_data ( wmem_file_scope ( ) , pinfo , proto_fp , 0 ) ;
 rlcinf = ( rlc_info * ) p_get_proto_data ( wmem_file_scope ( ) , pinfo , proto_rlc , 0 ) ;
 if ( ! macinf || ! fpinf ) {
 proto_tree_add_expert ( rach_tree , pinfo , & ei_mac_per_frame_info_missing , tvb , 0 , - 1 ) ;
 return 1 ;
 }
 proto_tree_add_bits_item ( rach_tree , hf_mac_rach_fdd_tctf , tvb , 0 , 2 , ENC_BIG_ENDIAN ) ;
 if ( tctf == TCTF_DCCH_DTCH_RACH_FDD ) {
 macinf -> ctmux [ fpinf -> cur_tb ] = 1 ;
 bitoffs = tree_add_common_dcch_dtch_fields ( tvb , pinfo , rach_tree , bitoffs , fpinf , macinf , rlcinf ) ;
 }
 chan = fpinf -> cur_chan ;
 switch ( tctf ) {
 case TCTF_CCCH_RACH_FDD : proto_item_append_text ( ti , " (CCCH)" ) ;
 channel_type = proto_tree_add_uint ( rach_tree , hf_mac_channel , tvb , 0 , 0 , MAC_CCCH ) ;
 PROTO_ITEM_SET_GENERATED ( channel_type ) ;
 next_tvb = tvb_new_octet_aligned ( tvb , bitoffs , fpinf -> chan_tf_size [ chan ] - bitoffs ) ;
 add_new_data_source ( pinfo , next_tvb , "Octet-Aligned CCCH Data" ) ;
 call_dissector_with_data ( rlc_ccch_handle , next_tvb , pinfo , tree , data ) ;
 break ;
 case TCTF_DCCH_DTCH_RACH_FDD : c_t = tvb_get_bits8 ( tvb , bitoffs - 4 , 4 ) ;
 rlcinf -> mode [ chan ] = lchId_rlc_map [ c_t + 1 ] ;
 macinf -> content [ chan ] = lchId_type_table [ c_t + 1 ] ;
 rlcinf -> rbid [ chan ] = c_t + 1 ;
 switch ( macinf -> content [ chan ] ) {
 case MAC_CONTENT_DCCH : proto_item_append_text ( ti , " (DCCH)" ) ;
 channel_type = proto_tree_add_uint ( rach_tree , hf_mac_channel , tvb , 0 , 0 , MAC_DCCH ) ;
 PROTO_ITEM_SET_GENERATED ( channel_type ) ;
 next_tvb = tvb_new_octet_aligned ( tvb , bitoffs , fpinf -> chan_tf_size [ chan ] - bitoffs ) ;
 add_new_data_source ( pinfo , next_tvb , "Octet-Aligned DCCH Data" ) ;
 call_dissector_with_data ( rlc_dcch_handle , next_tvb , pinfo , tree , data ) ;
 break ;
 case MAC_CONTENT_PS_DTCH : proto_item_append_text ( ti , " (PS DTCH)" ) ;
 channel_type = proto_tree_add_uint ( rach_tree , hf_mac_channel , tvb , 0 , 0 , MAC_DTCH ) ;
 PROTO_ITEM_SET_GENERATED ( channel_type ) ;
 next_tvb = tvb_new_octet_aligned ( tvb , bitoffs , fpinf -> chan_tf_size [ chan ] - bitoffs ) ;
 add_new_data_source ( pinfo , next_tvb , "Octet-Aligned DTCH Data" ) ;
 call_dissector_with_data ( rlc_ps_dtch_handle , next_tvb , pinfo , tree , data ) ;
 break ;
 case MAC_CONTENT_CS_DTCH : proto_item_append_text ( ti , " (CS DTCH)" ) ;
 break ;
 default : proto_item_append_text ( ti , " (Unknown RACH DCCH/DTCH Content)" ) ;
 expert_add_info_format ( pinfo , NULL , & ei_mac_unknown_content , "Unknown RACH DCCH/DTCH Content" ) ;
 }
 break ;
 default : proto_item_append_text ( ti , " (Unknown RACH TCTF)" ) ;
 expert_add_info_format ( pinfo , NULL , & ei_mac_rach_tctf_unknown , "Unknown RACH TCTF" ) ;
 }
 return tvb_captured_length ( tvb ) ;
 }