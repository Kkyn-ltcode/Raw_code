static void steamdiscover_dissect_body_status ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , gint offset , gint bytes_left ) {
 gint64 value ;
 gint len ;
 gint len2 ;
 protobuf_desc_t pb = {
 tvb , offset , bytes_left }
 ;
 protobuf_desc_t pb2 = {
 tvb , 0 , 0 }
 ;
 protobuf_tag_t tag = {
 0 , 0 , 0 }
 ;
 guint8 * hostname ;
 nstime_t timestamp ;
 proto_tree * user_tree ;
 proto_item * user_it ;
 while ( protobuf_iter_next ( & pb , & tag ) ) {
 switch ( tag . field_number ) {
 case STEAMDISCOVER_FN_STATUS_VERSION : STEAMDISCOVER_ENSURE_WIRETYPE ( PROTOBUF_WIRETYPE_VARINT ) ;
 value = get_varint64 ( pb . tvb , pb . offset , pb . bytes_left , & len ) ;
 proto_tree_add_int ( tree , hf_steam_ihs_discovery_body_status_version , pb . tvb , pb . offset , len , ( gint32 ) value ) ;
 break ;
 case STEAMDISCOVER_FN_STATUS_MINVERSION : STEAMDISCOVER_ENSURE_WIRETYPE ( PROTOBUF_WIRETYPE_VARINT ) ;
 value = get_varint64 ( pb . tvb , pb . offset , pb . bytes_left , & len ) ;
 proto_tree_add_int ( tree , hf_steam_ihs_discovery_body_status_minversion , pb . tvb , pb . offset , len , ( gint32 ) value ) ;
 break ;
 case STEAMDISCOVER_FN_STATUS_CONNECTPORT : STEAMDISCOVER_ENSURE_WIRETYPE ( PROTOBUF_WIRETYPE_VARINT ) ;
 value = get_varint64 ( pb . tvb , pb . offset , pb . bytes_left , & len ) ;
 proto_tree_add_uint ( tree , hf_steam_ihs_discovery_body_status_connectport , pb . tvb , pb . offset , len , ( guint32 ) value ) ;
 break ;
 case STEAMDISCOVER_FN_STATUS_HOSTNAME : STEAMDISCOVER_ENSURE_WIRETYPE ( PROTOBUF_WIRETYPE_LENGTHDELIMITED ) ;
 value = get_varint64 ( pb . tvb , pb . offset , pb . bytes_left , & len ) ;
 proto_tree_add_item ( tree , hf_steam_ihs_discovery_body_status_hostname , pb . tvb , pb . offset + len , ( gint ) value , ENC_UTF_8 | ENC_NA ) ;
 hostname = tvb_get_string_enc ( wmem_packet_scope ( ) , pb . tvb , pb . offset + len , ( gint ) value , ENC_UTF_8 ) ;
 if ( hostname && strlen ( hostname ) ) {
 col_add_fstr ( pinfo -> cinfo , COL_INFO , "%s from %s" , hf_steam_ihs_discovery_header_msgtype_strings [ STEAMDISCOVER_MSGTYPE_CLIENTBROADCASTMSGSTATUS ] . strptr , hostname ) ;
 }
 len += ( gint ) value ;
 break ;
 case STEAMDISCOVER_FN_STATUS_ENABLEDSERVICES : STEAMDISCOVER_ENSURE_WIRETYPE ( PROTOBUF_WIRETYPE_VARINT ) ;
 value = get_varint64 ( pb . tvb , pb . offset , pb . bytes_left , & len ) ;
 proto_tree_add_uint ( tree , hf_steam_ihs_discovery_body_status_enabledservices , pb . tvb , pb . offset , len , ( guint32 ) value ) ;
 break ;
 case STEAMDISCOVER_FN_STATUS_OSTYPE : STEAMDISCOVER_ENSURE_WIRETYPE ( PROTOBUF_WIRETYPE_VARINT ) ;
 value = get_varint64 ( pb . tvb , pb . offset , pb . bytes_left , & len ) ;
 proto_tree_add_int ( tree , hf_steam_ihs_discovery_body_status_ostype , pb . tvb , pb . offset , len , ( gint32 ) value ) ;
 break ;
 case STEAMDISCOVER_FN_STATUS_IS64BIT : STEAMDISCOVER_ENSURE_WIRETYPE ( PROTOBUF_WIRETYPE_VARINT ) ;
 value = get_varint64 ( pb . tvb , pb . offset , pb . bytes_left , & len ) ;
 proto_tree_add_boolean ( tree , hf_steam_ihs_discovery_body_status_is64bit , pb . tvb , pb . offset , len , ( gint32 ) value ) ;
 break ;
 case STEAMDISCOVER_FN_STATUS_USERS : STEAMDISCOVER_ENSURE_WIRETYPE ( PROTOBUF_WIRETYPE_LENGTHDELIMITED ) ;
 value = get_varint64 ( pb . tvb , pb . offset , pb . bytes_left , & len ) ;
 pb2 . offset = pb . offset + len ;
 pb2 . bytes_left = ( gint ) value ;
 len += ( gint ) value ;
 user_tree = proto_tree_add_subtree ( tree , pb . tvb , pb . offset , len , ett_steam_ihs_discovery_body_status_user , & user_it , "User" ) ;
 while ( protobuf_iter_next ( & pb2 , & tag ) ) {
 switch ( tag . field_number ) {
 case STEAMDISCOVER_FN_STATUS_USER_STEAMID : if ( ( len2 = protobuf_verify_wiretype ( & pb2 , & tag , pinfo , user_tree , PROTOBUF_WIRETYPE_64BIT ) ) ) break ;
 len2 = 8 ;
 value = tvb_get_letoh64 ( pb2 . tvb , pb2 . offset ) ;
 proto_tree_add_uint64 ( user_tree , hf_steam_ihs_discovery_body_status_user_steamid , pb2 . tvb , pb2 . offset , len2 , ( guint64 ) value ) ;
 proto_item_append_text ( user_it , ", Steam ID: %" G_GUINT64_FORMAT , ( guint64 ) value ) ;
 break ;
 case STEAMDISCOVER_FN_STATUS_USER_AUTHKEYID : if ( ( len2 = protobuf_verify_wiretype ( & pb2 , & tag , pinfo , user_tree , PROTOBUF_WIRETYPE_VARINT ) ) ) break ;
 value = get_varint64 ( pb2 . tvb , pb2 . offset , pb2 . bytes_left , & len2 ) ;
 proto_tree_add_uint ( user_tree , hf_steam_ihs_discovery_body_status_user_authkeyid , pb2 . tvb , pb2 . offset , len2 , ( guint32 ) value ) ;
 proto_item_append_text ( user_it , ", Auth Key ID: %" G_GUINT32_FORMAT , ( guint32 ) value ) ;
 break ;
 default : len2 = protobuf_dissect_unknown_field ( & pb2 , & tag , pinfo , tree , NULL ) ;
 break ;
 }
 protobuf_seek_forward ( & pb2 , len2 ) ;
 }
 break ;
 case STEAMDISCOVER_FN_STATUS_EUNIVERSE : STEAMDISCOVER_ENSURE_WIRETYPE ( PROTOBUF_WIRETYPE_VARINT ) ;
 value = get_varint64 ( pb . tvb , pb . offset , pb . bytes_left , & len ) ;
 proto_tree_add_int ( tree , hf_steam_ihs_discovery_body_status_euniverse , pb . tvb , pb . offset , len , ( gint32 ) value ) ;
 break ;
 case STEAMDISCOVER_FN_STATUS_TIMESTAMP : STEAMDISCOVER_ENSURE_WIRETYPE ( PROTOBUF_WIRETYPE_VARINT ) ;
 timestamp . secs = get_varint64 ( pb . tvb , pb . offset , pb . bytes_left , & len ) ;
 timestamp . nsecs = 0 ;
 proto_tree_add_time ( tree , hf_steam_ihs_discovery_body_status_timestamp , pb . tvb , pb . offset , len , & timestamp ) ;
 break ;
 case STEAMDISCOVER_FN_STATUS_SCREENLOCKED : STEAMDISCOVER_ENSURE_WIRETYPE ( PROTOBUF_WIRETYPE_VARINT ) ;
 value = get_varint64 ( pb . tvb , pb . offset , pb . bytes_left , & len ) ;
 proto_tree_add_boolean ( tree , hf_steam_ihs_discovery_body_status_screenlocked , pb . tvb , pb . offset , len , ( gint32 ) value ) ;
 break ;
 case STEAMDISCOVER_FN_STATUS_GAMESRUNNING : STEAMDISCOVER_ENSURE_WIRETYPE ( PROTOBUF_WIRETYPE_VARINT ) ;
 value = get_varint64 ( pb . tvb , pb . offset , pb . bytes_left , & len ) ;
 proto_tree_add_boolean ( tree , hf_steam_ihs_discovery_body_status_gamesrunning , pb . tvb , pb . offset , len , ( gint32 ) value ) ;
 break ;
 case STEAMDISCOVER_FN_STATUS_MACADDRESSES : STEAMDISCOVER_ENSURE_WIRETYPE ( PROTOBUF_WIRETYPE_LENGTHDELIMITED ) ;
 value = get_varint64 ( pb . tvb , pb . offset , pb . bytes_left , & len ) ;
 proto_tree_add_item ( tree , hf_steam_ihs_discovery_body_status_macaddresses , pb . tvb , pb . offset + len , ( gint ) value , ENC_UTF_8 | ENC_NA ) ;
 len += ( gint ) value ;
 break ;
 default : len = protobuf_dissect_unknown_field ( & pb , & tag , pinfo , tree , NULL ) ;
 break ;
 }
 protobuf_seek_forward ( & pb , len ) ;
 }
 }