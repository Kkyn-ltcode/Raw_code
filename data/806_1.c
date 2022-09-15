void proto_register_adb ( void ) {
 module_t * module ;
 expert_module_t * expert_module ;
 static hf_register_info hf [ ] = {
 {
 & hf_command , {
 "Command" , "adb.command" , FT_UINT32 , BASE_HEX , VALS ( command_vals ) , 0x00 , NULL , HFILL }
 }
 , {
 & hf_argument_0 , {
 "Argument 0" , "adb.argument.0" , FT_UINT32 , BASE_HEX , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_argument_1 , {
 "Argument 0" , "adb.argument.1" , FT_UINT32 , BASE_HEX , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_data_length , {
 "Data Length" , "adb.data_length" , FT_UINT32 , BASE_DEC , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_data_crc32 , {
 "Data CRC32" , "adb.data_crc32" , FT_UINT32 , BASE_HEX , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_magic , {
 "Magic" , "adb.magic" , FT_UINT32 , BASE_HEX , VALS ( magic_vals ) , 0x00 , NULL , HFILL }
 }
 , {
 & hf_version , {
 "Version" , "adb.version" , FT_UINT32 , BASE_HEX , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_max_data , {
 "Max Data" , "adb.max_data" , FT_UINT32 , BASE_DEC , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_auth_type , {
 "Type" , "adb.auth_type" , FT_UINT32 , BASE_HEX , VALS ( auth_type_vals ) , 0x00 , NULL , HFILL }
 }
 , {
 & hf_online , {
 "Online" , "adb.online" , FT_BOOLEAN , 32 , TFS ( & tfs_no_yes ) , 0x00 , NULL , HFILL }
 }
 , {
 & hf_sequence , {
 "Sequence" , "adb.sequence" , FT_UINT32 , BASE_DEC , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_zero , {
 "Zero" , "adb.zero" , FT_UINT32 , BASE_HEX , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_local_id , {
 "Local ID" , "adb.local_id" , FT_UINT32 , BASE_DEC , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_remote_id , {
 "Remote ID" , "adb.remote_id" , FT_UINT32 , BASE_DEC , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_data , {
 "Data" , "adb.data" , FT_NONE , BASE_NONE , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_service , {
 "Service" , "adb.service" , FT_STRING , BASE_NONE , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_data_fragment , {
 "Data Fragment" , "adb.data_fragment" , FT_NONE , BASE_NONE , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_service_start_in_frame , {
 "Service Start in Frame" , "adb.service_start_in_frame" , FT_FRAMENUM , BASE_NONE , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_close_local_in_frame , {
 "Local Service Close in Frame" , "adb.close_local_in_frame" , FT_FRAMENUM , BASE_NONE , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_close_remote_in_frame , {
 "Remote Service Close in Frame" , "adb.close_remote_in_frame" , FT_FRAMENUM , BASE_NONE , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_command_in_frame , {
 "Command in Frame" , "adb.command_in_frame" , FT_FRAMENUM , BASE_NONE , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_completed_in_frame , {
 "Completed in Frame" , "adb.completed_in_frame" , FT_FRAMENUM , BASE_NONE , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_connection_info , {
 "Info" , "adb.connection_info" , FT_STRINGZ , STR_ASCII , NULL , 0x00 , NULL , HFILL }
 }
 }
 ;
 static gint * ett [ ] = {
 & ett_adb , & ett_adb_arg0 , & ett_adb_arg1 , & ett_adb_crc , & ett_adb_magic }
 ;
 static ei_register_info ei [ ] = {
 {
 & ei_invalid_magic , {
 "adb.expert.invalid_magic" , PI_PROTOCOL , PI_WARN , "Invalid Magic" , EXPFILL }
 }
 , {
 & ei_invalid_crc , {
 "adb.expert.crc_error" , PI_PROTOCOL , PI_ERROR , "CRC32 Error" , EXPFILL }
 }
 , }
 ;
 command_info = wmem_tree_new_autoreset ( wmem_epan_scope ( ) , wmem_file_scope ( ) ) ;
 service_info = wmem_tree_new_autoreset ( wmem_epan_scope ( ) , wmem_file_scope ( ) ) ;
 proto_adb = proto_register_protocol ( "Android Debug Bridge" , "ADB" , "adb" ) ;
 adb_handle = register_dissector ( "adb" , dissect_adb , proto_adb ) ;
 proto_register_field_array ( proto_adb , hf , array_length ( hf ) ) ;
 proto_register_subtree_array ( ett , array_length ( ett ) ) ;
 expert_module = expert_register_protocol ( proto_adb ) ;
 expert_register_field_array ( expert_module , ei , array_length ( ei ) ) ;
 module = prefs_register_protocol ( proto_adb , NULL ) ;
 prefs_register_static_text_preference ( module , "version" , "ADB protocol version is compatible prior to: adb 1.0.31" , "Version of protocol supported by this dissector." ) ;
 }