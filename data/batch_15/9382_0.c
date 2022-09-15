static int dissect_USER_LEVEL_1 ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 guint32 level ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_level , & level ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_userlevel_size , NULL ) ;
 offset = dissect_ndr_str_pointer_item ( tvb , offset , pinfo , tree , di , drep , NDR_POINTER_UNIQUE , "Client" , hf_userlevel_client , 0 ) ;
 offset = dissect_ndr_str_pointer_item ( tvb , offset , pinfo , tree , di , drep , NDR_POINTER_UNIQUE , "User" , hf_userlevel_user , 0 ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_userlevel_build , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_userlevel_major , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_userlevel_minor , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_userlevel_processor , NULL ) ;
 return offset ;
 }