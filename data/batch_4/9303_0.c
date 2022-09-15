static int dissect_spoolss_printer_enum_values ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 guint32 start_offset = offset ;
 guint32 name_offset , name_len , val_offset , val_len , val_type ;
 char * name ;
 proto_item * item ;
 proto_tree * subtree ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , NULL , di , drep , hf_enumprinterdataex_name_offset , & name_offset ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , NULL , di , drep , hf_enumprinterdataex_name_len , & name_len ) ;
 dissect_spoolss_uint16uni ( tvb , start_offset + name_offset , pinfo , NULL , drep , & name , hf_enumprinterdataex_name ) ;
 subtree = proto_tree_add_subtree_format ( tree , tvb , offset , 0 , ett_printer_enumdataex_value , & item , "Name: %s" , name ) ;
 proto_tree_add_uint ( subtree , hf_enumprinterdataex_name_offset , tvb , offset - 8 , 4 , name_offset ) ;
 proto_tree_add_uint ( subtree , hf_enumprinterdataex_name_len , tvb , offset - 4 , 4 , name_len ) ;
 proto_tree_add_string ( subtree , hf_enumprinterdataex_name , tvb , start_offset + name_offset , ( ( int ) strlen ( name ) + 1 ) * 2 , name ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_printerdata_type , & val_type ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_enumprinterdataex_val_offset , & val_offset ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_enumprinterdataex_val_len , & val_len ) ;
 if ( val_len == 0 ) {
 proto_tree_add_uint_format_value ( subtree , hf_enumprinterdataex_value_null , tvb , start_offset + val_offset , 4 , 0 , "(null)" ) ;
 goto done ;
 }
 switch ( val_type ) {
 case DCERPC_REG_DWORD : {
 guint32 value ;
 guint16 low , high ;
 int offset2 = start_offset + val_offset ;
 offset2 = dissect_ndr_uint16 ( tvb , offset2 , pinfo , subtree , di , drep , hf_enumprinterdataex_val_dword_low , & low ) ;
 dissect_ndr_uint16 ( tvb , offset2 , pinfo , subtree , di , drep , hf_enumprinterdataex_val_dword_high , & high ) ;
 value = ( high << 16 ) | low ;
 proto_tree_add_uint ( subtree , hf_enumprinterdataex_value_uint , tvb , start_offset + val_offset , 4 , value ) ;
 proto_item_append_text ( item , ", Value: %d" , value ) ;
 break ;
 }
 case DCERPC_REG_SZ : {
 char * value ;
 dissect_spoolss_uint16uni ( tvb , start_offset + val_offset , pinfo , subtree , drep , & value , hf_value_string ) ;
 proto_item_append_text ( item , ", Value: %s" , value ) ;
 g_free ( value ) ;
 break ;
 }
 case DCERPC_REG_BINARY : proto_tree_add_bytes_format_value ( subtree , hf_enumprinterdataex_value_binary , tvb , start_offset + val_offset , val_len , NULL , "<binary data>" ) ;
 break ;
 case DCERPC_REG_MULTI_SZ : proto_tree_add_bytes_format_value ( subtree , hf_enumprinterdataex_value_multi_sz , tvb , start_offset + val_offset , val_len , NULL , "<REG_MULTI_SZ not implemented>" ) ;
 break ;
 default : proto_tree_add_expert_format ( subtree , pinfo , & ei_enumprinterdataex_value , tvb , start_offset + val_offset , val_len , "%s: unknown type %d" , name , val_type ) ;
 }
 done : g_free ( name ) ;
 return offset ;
 }