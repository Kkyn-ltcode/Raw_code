static void steamdiscover_dissect_body_authrequest ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , gint offset , gint bytes_left ) {
 guint len ;
 gint64 value ;
 protobuf_desc_t pb = {
 tvb , offset , bytes_left }
 ;
 protobuf_tag_t tag = {
 0 , 0 , 0 }
 ;
 wmem_allocator_t * strpool ;
 strpool = wmem_allocator_new ( WMEM_ALLOCATOR_SIMPLE ) ;
 guint8 * devicename ;
 while ( protobuf_iter_next ( & pb , & tag ) ) {
 switch ( tag . field_number ) {
 case STEAMDISCOVER_FN_AUTHREQUEST_DEVICETOKEN : STEAMDISCOVER_ENSURE_WIRETYPE ( PROTOBUF_WIRETYPE_LENGTHDELIMITED ) ;
 value = get_varint64 ( pb . tvb , pb . offset , pb . bytes_left , & len ) ;
 proto_tree_add_item ( tree , hf_steam_ihs_discovery_body_authrequest_devicetoken , pb . tvb , pb . offset + len , ( gint ) value , ENC_NA ) ;
 len += ( gint ) value ;
 break ;
 case STEAMDISCOVER_FN_AUTHREQUEST_DEVICENAME : STEAMDISCOVER_ENSURE_WIRETYPE ( PROTOBUF_WIRETYPE_LENGTHDELIMITED ) ;
 value = get_varint64 ( pb . tvb , pb . offset , pb . bytes_left , & len ) ;
 proto_tree_add_item ( tree , hf_steam_ihs_discovery_body_authrequest_devicename , pb . tvb , pb . offset + len , ( gint ) value , ENC_UTF_8 | ENC_NA ) ;
 devicename = tvb_get_string_enc ( strpool , pb . tvb , pb . offset + len , ( gint ) value , ENC_UTF_8 ) ;
 if ( devicename && strlen ( devicename ) ) {
 col_append_fstr ( pinfo -> cinfo , COL_INFO , " from %s" , devicename ) ;
 }
 len += ( gint ) value ;
 break ;
 case STEAMDISCOVER_FN_AUTHREQUEST_ENCRYPTEDREQUEST : STEAMDISCOVER_ENSURE_WIRETYPE ( PROTOBUF_WIRETYPE_LENGTHDELIMITED ) ;
 value = get_varint64 ( pb . tvb , pb . offset , pb . bytes_left , & len ) ;
 proto_tree_add_item ( tree , hf_steam_ihs_discovery_body_authrequest_encryptedrequest , pb . tvb , pb . offset + len , ( gint ) value , ENC_NA ) ;
 len += ( gint ) value ;
 break ;
 default : len = protobuf_dissect_unknown_field ( & pb , & tag , pinfo , tree , NULL ) ;
 break ;
 }
 protobuf_seek_forward ( & pb , len ) ;
 }
 wmem_destroy_allocator ( strpool ) ;
 }