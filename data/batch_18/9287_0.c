static int SpoolssSetForm_q ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep _U_ ) {
 char * name = NULL ;
 guint32 level ;
 proto_item * hidden_item ;
 hidden_item = proto_tree_add_uint ( tree , hf_form , tvb , offset , 0 , 1 ) ;
 PROTO_ITEM_SET_HIDDEN ( hidden_item ) ;
 offset = dissect_nt_policy_hnd ( tvb , offset , pinfo , tree , di , drep , hf_hnd , NULL , NULL , FALSE , FALSE ) ;
 offset = dissect_ndr_cvstring ( tvb , offset , pinfo , tree , di , drep , sizeof ( guint16 ) , hf_form_name , TRUE , & name ) ;
 if ( name ) col_append_fstr ( pinfo -> cinfo , COL_INFO , ", %s" , name ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_form_level , & level ) ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , ", level %d" , level ) ;
 offset = dissect_FORM_CTR ( tvb , offset , pinfo , tree , di , drep ) ;
 return offset ;
 }