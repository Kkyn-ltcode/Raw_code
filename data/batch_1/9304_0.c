static int SpoolssEnumPrinterDataEx_r ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 guint32 size , num_values ;
 proto_item * hidden_item ;
 hidden_item = proto_tree_add_uint ( tree , hf_printerdata , tvb , offset , 0 , 1 ) ;
 PROTO_ITEM_SET_HIDDEN ( hidden_item ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_buffer_size , & size ) ;
 dissect_ndr_uint32 ( tvb , offset + size + 4 , pinfo , NULL , di , drep , hf_returned , & num_values ) ;
 if ( size ) {
 proto_tree * subtree ;
 int offset2 = offset ;
 guint32 i ;
 subtree = proto_tree_add_subtree ( tree , tvb , offset , 0 , ett_PRINTER_DATA_CTR , NULL , "Printer data" ) ;
 for ( i = 0 ;
 i < num_values ;
 i ++ ) offset2 = dissect_spoolss_printer_enum_values ( tvb , offset2 , pinfo , subtree , di , drep ) ;
 }
 offset += size ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_needed , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_returned , NULL ) ;
 offset = dissect_doserror ( tvb , offset , pinfo , tree , di , drep , hf_rc , NULL ) ;
 return offset ;
 }