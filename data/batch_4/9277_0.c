static int SpoolssEnumForms_r ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep _U_ ) {
 dcerpc_call_value * dcv = ( dcerpc_call_value * ) di -> call_data ;
 BUFFER buffer ;
 guint32 level = GPOINTER_TO_UINT ( dcv -> se_data ) , i , count ;
 int buffer_offset ;
 proto_item * hidden_item ;
 hidden_item = proto_tree_add_uint ( tree , hf_form , tvb , offset , 0 , 1 ) ;
 PROTO_ITEM_SET_HIDDEN ( hidden_item ) ;
 offset = dissect_spoolss_buffer ( tvb , offset , pinfo , tree , di , drep , & buffer ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_needed , NULL ) ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , ", level %d" , level ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_enumforms_num , & count ) ;
 buffer_offset = 0 ;
 for ( i = 0 ;
 i < count ;
 i ++ ) {
 int struct_start = buffer_offset ;
 buffer_offset = dissect_FORM_REL ( buffer . tvb , buffer_offset , pinfo , buffer . tree , di , drep , struct_start ) ;
 }
 offset = dissect_doserror ( tvb , offset , pinfo , tree , di , drep , hf_rc , NULL ) ;
 return offset ;
 }