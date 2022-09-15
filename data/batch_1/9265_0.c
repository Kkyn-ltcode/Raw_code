static int SpoolssGetForm_r ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep _U_ ) {
 dcerpc_call_value * dcv = ( dcerpc_call_value * ) di -> call_data ;
 BUFFER buffer ;
 guint32 level = GPOINTER_TO_UINT ( dcv -> se_data ) ;
 proto_item * hidden_item ;
 hidden_item = proto_tree_add_uint ( tree , hf_form , tvb , offset , 0 , 1 ) ;
 PROTO_ITEM_SET_HIDDEN ( hidden_item ) ;
 offset = dissect_spoolss_buffer ( tvb , offset , pinfo , tree , di , drep , & buffer ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_needed , NULL ) ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , ", level %d" , level ) ;
 if ( buffer . tvb ) {
 int buffer_offset = 0 ;
 switch ( level ) {
 case 1 : {
 int struct_start = buffer_offset ;
 dissect_FORM_REL ( buffer . tvb , buffer_offset , pinfo , tree , di , drep , struct_start ) ;
 break ;
 }
 default : proto_tree_add_expert_format ( buffer . tree , pinfo , & ei_form_level , buffer . tvb , buffer_offset , - 1 , "Unknown form info level %d" , level ) ;
 break ;
 }
 }
 offset = dissect_doserror ( tvb , offset , pinfo , tree , di , drep , hf_rc , NULL ) ;
 return offset ;
 }