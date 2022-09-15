void proto_register_usb_vid ( void ) {
 static hf_register_info hf [ ] = {
 {
 & hf_usb_vid_request , {
 "bRequest" , "usbvideo.setup.bRequest" , FT_UINT8 , BASE_HEX , VALS ( setup_request_names_vals ) , 0x0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_length , {
 "wLength" , "usbvideo.setup.wLength" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_request_error , {
 "bRequestErrorCode" , "usbvideo.reqerror.code" , FT_UINT8 , BASE_DEC | BASE_EXT_STRING , & request_error_codes_ext , 0 , "Request Error Code" , HFILL }
 }
 , {
 & hf_usb_vid_control_selector , {
 "Control Selector" , "usbvideo.control.selector" , FT_UINT8 , BASE_HEX , NULL , 0x0 , "ID of the control within its entity" , HFILL }
 }
 , {
 & hf_usb_vid_control_entity , {
 "Entity" , "usbvideo.control.entity" , FT_UINT8 , BASE_HEX , NULL , 0x0 , "Unit or terminal to which the control belongs" , HFILL }
 }
 , {
 & hf_usb_vid_control_interface , {
 "Interface" , "usbvideo.control.interface" , FT_UINT8 , BASE_HEX , NULL , 0x0 , "Interface to which the control belongs" , HFILL }
 }
 , {
 & hf_usb_vid_control_info , {
 "Info (Capabilities/State)" , "usbvideo.control.info" , FT_UINT8 , BASE_HEX , NULL , 0 , "Control capabilities and current state" , HFILL }
 }
 , {
 & hf_usb_vid_control_info_D [ 0 ] , {
 "Supports GET" , "usbvideo.control.info.D0" , FT_BOOLEAN , 8 , TFS ( & tfs_yes_no ) , ( 1 << 0 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_info_D [ 1 ] , {
 "Supports SET" , "usbvideo.control.info.D1" , FT_BOOLEAN , 8 , TFS ( & tfs_yes_no ) , ( 1 << 1 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_info_D [ 2 ] , {
 "Disabled due to automatic mode" , "usbvideo.control.info.D2" , FT_BOOLEAN , 8 , TFS ( & tfs_yes_no ) , ( 1 << 2 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_info_D [ 3 ] , {
 "Autoupdate" , "usbvideo.control.info.D3" , FT_BOOLEAN , 8 , TFS ( & tfs_yes_no ) , ( 1 << 3 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_info_D [ 4 ] , {
 "Asynchronous" , "usbvideo.control.info.D4" , FT_BOOLEAN , 8 , TFS ( & tfs_yes_no ) , ( 1 << 4 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_info_D [ 5 ] , {
 "Disabled due to incompatibility with Commit state" , "usbvideo.control.info.D5" , FT_BOOLEAN , 8 , TFS ( & tfs_yes_no ) , ( 1 << 5 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_info_D [ 6 ] , {
 "Reserved" , "usbvideo.control.info.D6" , FT_UINT8 , BASE_HEX , NULL , ( 3 << 6 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_length , {
 "Control Length" , "usbvideo.control.len" , FT_UINT16 , BASE_DEC , NULL , 0 , "Control size in bytes" , HFILL }
 }
 , {
 & hf_usb_vid_control_default , {
 "Default value" , "usbvideo.control.value.default" , FT_UINT32 , BASE_DEC_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_min , {
 "Minimum value" , "usbvideo.control.value.min" , FT_UINT32 , BASE_DEC_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_max , {
 "Maximum value" , "usbvideo.control.value.max" , FT_UINT32 , BASE_DEC_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_res , {
 "Resolution" , "usbvideo.control.value.res" , FT_UINT32 , BASE_DEC_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_cur , {
 "Current value" , "usbvideo.control.value.cur" , FT_UINT32 , BASE_DEC_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_ifdesc_iTerminal , {
 "iTerminal" , "usbvideo.terminal.name" , FT_UINT8 , BASE_DEC , NULL , 0x0 , "String Descriptor describing this terminal" , HFILL }
 }
 , {
 & hf_usb_vid_control_ifdesc_terminal_id , {
 "bTerminalID" , "usbvideo.terminal.id" , FT_UINT8 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_ifdesc_terminal_type , {
 "wTerminalType" , "usbvideo.terminal.type" , FT_UINT16 , BASE_HEX | BASE_EXT_STRING , & vc_terminal_types_ext , 0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_ifdesc_assoc_terminal , {
 "bAssocTerminal" , "usbvideo.terminal.assocTerminal" , FT_UINT8 , BASE_DEC , NULL , 0x0 , "Associated Terminal" , HFILL }
 }
 , {
 & hf_usb_vid_cam_objective_focal_len_min , {
 "wObjectiveFocalLengthMin" , "usbvideo.camera.objectiveFocalLengthMin" , FT_UINT16 , BASE_DEC , NULL , 0 , "Minimum Focal Length for Optical Zoom" , HFILL }
 }
 , {
 & hf_usb_vid_cam_objective_focal_len_max , {
 "wObjectiveFocalLengthMax" , "usbvideo.camera.objectiveFocalLengthMax" , FT_UINT16 , BASE_DEC , NULL , 0 , "Minimum Focal Length for Optical Zoom" , HFILL }
 }
 , {
 & hf_usb_vid_cam_ocular_focal_len , {
 "wOcularFocalLength" , "usbvideo.camera.ocularFocalLength" , FT_UINT16 , BASE_DEC , NULL , 0 , "Ocular Focal Length for Optical Zoom" , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 0 ] , {
 "Scanning Mode" , "usbvideo.camera.control.D0" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 0 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 1 ] , {
 "Auto Exposure Mode" , "usbvideo.camera.control.D1" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 1 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 2 ] , {
 "Auto Exposure Priority" , "usbvideo.camera.control.D2" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 2 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 3 ] , {
 "Exposure Time (Absolute)" , "usbvideo.camera.control.D3" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 3 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 4 ] , {
 "Exposure Time (Relative)" , "usbvideo.camera.control.D4" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 4 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 5 ] , {
 "Focus (Absolute)" , "usbvideo.camera.control.D5" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 5 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 6 ] , {
 "Focus (Relative)" , "usbvideo.camera.control.D6" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 6 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 7 ] , {
 "Iris (Absolute)" , "usbvideo.camera.control.D7" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 7 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 8 ] , {
 "Iris (Relative)" , "usbvideo.camera.control.D8" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 8 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 9 ] , {
 "Zoom (Absolute)" , "usbvideo.camera.control.D9" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 9 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 10 ] , {
 "Zoom (Relative)" , "usbvideo.camera.control.D10" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 10 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 11 ] , {
 "PanTilt (Absolute)" , "usbvideo.camera.control.D11" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 11 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 12 ] , {
 "PanTilt (Relative)" , "usbvideo.camera.control.D12" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 12 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 13 ] , {
 "Roll (Absolute)" , "usbvideo.camera.control.D13" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 13 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 14 ] , {
 "Roll (Relative)" , "usbvideo.camera.control.D14" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 14 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 15 ] , {
 "D15" , "usbvideo.camera.control.D15" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 15 ) , "Reserved" , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 16 ] , {
 "D16" , "usbvideo.camera.control.D16" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 16 ) , "Reserved" , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 17 ] , {
 "Auto Focus" , "usbvideo.camera.control.D17" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 17 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 18 ] , {
 "Privacy" , "usbvideo.camera.control.D18" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 18 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 19 ] , {
 "Focus (Simple)" , "usbvideo.camera.control.D19" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 19 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 20 ] , {
 "Window" , "usbvideo.camera.control.D20" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 20 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_cam_control_D [ 21 ] , {
 "Region of Interest" , "usbvideo.camera.control.D21" , FT_BOOLEAN , array_length ( hf_usb_vid_cam_control_D ) , TFS ( & tfs_yes_no ) , ( 1 << 21 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_ifdesc_unit_id , {
 "bUnitID" , "usbvideo.unit.id" , FT_UINT8 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_num_inputs , {
 "bNrInPins" , "usbvideo.unit.numInputs" , FT_UINT8 , BASE_DEC , NULL , 0 , "Number of input pins" , HFILL }
 }
 , {
 & hf_usb_vid_sources , {
 "baSourceID" , "usbvideo.unit.sources" , FT_BYTES , BASE_NONE , NULL , 0 , "Input entity IDs" , HFILL }
 }
 , {
 & hf_usb_vid_iProcessing , {
 "iProcessing" , "usbvideo.processor.name" , FT_UINT8 , BASE_DEC , NULL , 0x0 , "String Descriptor describing this terminal" , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 0 ] , {
 "Brightness" , "usbvideo.processor.control.D0" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 0 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 1 ] , {
 "Contrast" , "usbvideo.processor.control.D1" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 1 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 2 ] , {
 "Hue" , "usbvideo.processor.control.D2" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 2 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 3 ] , {
 "Saturation" , "usbvideo.processor.control.D3" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 3 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 4 ] , {
 "Sharpness" , "usbvideo.processor.control.D4" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 4 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 5 ] , {
 "Gamma" , "usbvideo.processor.control.D5" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 5 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 6 ] , {
 "White Balance Temperature" , "usbvideo.processor.control.D6" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 6 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 7 ] , {
 "White Balance Component" , "usbvideo.processor.control.D7" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 7 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 8 ] , {
 "Backlight Compensation" , "usbvideo.processor.control.D8" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 8 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 9 ] , {
 "Gain" , "usbvideo.processor.control.D9" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 9 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 10 ] , {
 "Power Line Frequency" , "usbvideo.processor.control.D10" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 10 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 11 ] , {
 "Hue, Auto" , "usbvideo.processor.control.D11" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 11 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 12 ] , {
 "White Balance Temperature, Auto" , "usbvideo.processor.control.D12" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 12 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 13 ] , {
 "White Balance Component, Auto" , "usbvideo.processor.control.D13" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 13 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 14 ] , {
 "Digital Multiplier" , "usbvideo.processor.control.D14" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 14 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 15 ] , {
 "Digital Multiplier Limit" , "usbvideo.processor.control.D15" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 15 ) , "Reserved" , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 16 ] , {
 "Analog Video Standard" , "usbvideo.processor.control.D16" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 16 ) , "Reserved" , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 17 ] , {
 "Analog Video Lock Status" , "usbvideo.processor.control.D17" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 17 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_control_D [ 18 ] , {
 "Contrast, Auto" , "usbvideo.processor.control.D18" , FT_BOOLEAN , 24 , TFS ( & tfs_yes_no ) , ( 1 << 18 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_standards , {
 "bmVideoStandards" , "usbvideo.processor.standards" , FT_UINT8 , BASE_HEX , NULL , 0 , "Supported analog video standards" , HFILL }
 }
 , {
 & hf_usb_vid_proc_standards_D [ 0 ] , {
 "None" , "usbvideo.processor.standards.D0" , FT_BOOLEAN , 8 , TFS ( & tfs_yes_no ) , ( 1 << 0 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_standards_D [ 1 ] , {
 "NTSC - 525/60" , "usbvideo.processor.standards.D1" , FT_BOOLEAN , 8 , TFS ( & tfs_yes_no ) , ( 1 << 1 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_standards_D [ 2 ] , {
 "PAL - 625/50" , "usbvideo.processor.standards.D2" , FT_BOOLEAN , 8 , TFS ( & tfs_yes_no ) , ( 1 << 2 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_standards_D [ 3 ] , {
 "SECAM - 625/50" , "usbvideo.processor.standards.D3" , FT_BOOLEAN , 8 , TFS ( & tfs_yes_no ) , ( 1 << 3 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_standards_D [ 4 ] , {
 "NTSC - 625/50" , "usbvideo.processor.standards.D4" , FT_BOOLEAN , 8 , TFS ( & tfs_yes_no ) , ( 1 << 4 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_proc_standards_D [ 5 ] , {
 "PAL - 525/60" , "usbvideo.processor.standards.D5" , FT_BOOLEAN , 8 , TFS ( & tfs_yes_no ) , ( 1 << 5 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_max_multiplier , {
 "wMaxMultiplier" , "usbvideo.processor.maxMultiplier" , FT_UINT16 , BASE_DEC , NULL , 0 , "100 x max digital multiplication" , HFILL }
 }
 , {
 & hf_usb_vid_iSelector , {
 "iSelector" , "usbvideo.selector.name" , FT_UINT8 , BASE_DEC , NULL , 0x0 , "String Descriptor describing this terminal" , HFILL }
 }
 , {
 & hf_usb_vid_iExtension , {
 "iExtension" , "usbvideo.extension.name" , FT_UINT8 , BASE_DEC , NULL , 0x0 , "String Descriptor describing this terminal" , HFILL }
 }
 , {
 & hf_usb_vid_exten_guid , {
 "guid" , "usbvideo.extension.guid" , FT_GUID , BASE_NONE , NULL , 0 , "Identifier" , HFILL }
 }
 , {
 & hf_usb_vid_exten_num_controls , {
 "bNumControls" , "usbvideo.extension.numControls" , FT_UINT8 , BASE_DEC , NULL , 0 , "Number of controls" , HFILL }
 }
 , {
 & hf_usb_vid_probe_hint , {
 "bmHint" , "usbvideo.probe.hint" , FT_UINT16 , BASE_HEX , NULL , 0 , "Fields to hold constant during negotiation" , HFILL }
 }
 , {
 & hf_usb_vid_probe_hint_D [ 0 ] , {
 "dwFrameInterval" , "usbvideo.probe.hint.D0" , FT_BOOLEAN , 5 , TFS ( & probe_hint_meaning ) , ( 1 << 0 ) , "Frame Rate" , HFILL }
 }
 , {
 & hf_usb_vid_probe_hint_D [ 1 ] , {
 "wKeyFrameRate" , "usbvideo.probe.hint.D1" , FT_BOOLEAN , 5 , TFS ( & probe_hint_meaning ) , ( 1 << 1 ) , "Key Frame Rate" , HFILL }
 }
 , {
 & hf_usb_vid_probe_hint_D [ 2 ] , {
 "wPFrameRate" , "usbvideo.probe.hint.D2" , FT_BOOLEAN , 5 , TFS ( & probe_hint_meaning ) , ( 1 << 2 ) , "P-Frame Rate" , HFILL }
 }
 , {
 & hf_usb_vid_probe_hint_D [ 3 ] , {
 "wCompQuality" , "usbvideo.probe.hint.D3" , FT_BOOLEAN , 5 , TFS ( & probe_hint_meaning ) , ( 1 << 3 ) , "Compression Quality" , HFILL }
 }
 , {
 & hf_usb_vid_probe_hint_D [ 4 ] , {
 "wCompWindowSize" , "usbvideo.probe.hint.D4" , FT_BOOLEAN , 5 , TFS ( & probe_hint_meaning ) , ( 1 << 4 ) , "Compression Window Size" , HFILL }
 }
 , {
 & hf_usb_vid_probe_key_frame_rate , {
 "wKeyFrameRate" , "usbvideo.probe.keyFrameRate" , FT_UINT16 , BASE_DEC , NULL , 0 , "Key frame rate" , HFILL }
 }
 , {
 & hf_usb_vid_probe_p_frame_rate , {
 "wPFrameRate" , "usbvideo.probe.pFrameRate" , FT_UINT16 , BASE_DEC , NULL , 0 , "P frame rate" , HFILL }
 }
 , {
 & hf_usb_vid_probe_comp_quality , {
 "wCompQuality" , "usbvideo.probe.compQuality" , FT_UINT16 , BASE_DEC , NULL , 0 , "Compression quality [0-10000]" , HFILL }
 }
 , {
 & hf_usb_vid_probe_comp_window , {
 "wCompWindow" , "usbvideo.probe.compWindow" , FT_UINT16 , BASE_DEC , NULL , 0 , "Window size for average bit rate control" , HFILL }
 }
 , {
 & hf_usb_vid_probe_delay , {
 "wDelay" , "usbvideo.probe.delay" , FT_UINT16 , BASE_DEC , NULL , 0 , "Latency in ms from capture to USB" , HFILL }
 }
 , {
 & hf_usb_vid_probe_max_frame_sz , {
 "dwMaxVideoFrameSize" , "usbvideo.probe.maxVideoFrameSize" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_probe_max_payload_sz , {
 "dwMaxPayloadTransferSize" , "usbvideo.probe.maxPayloadTransferSize" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_probe_clock_freq , {
 "dwClockFrequency" , "usbvideo.probe.clockFrequency" , FT_UINT32 , BASE_DEC , NULL , 0 , "Device clock frequency in Hz" , HFILL }
 }
 , {
 & hf_usb_vid_probe_framing , {
 "bmFramingInfo" , "usbvideo.probe.framing" , FT_UINT16 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_probe_framing_D [ 0 ] , {
 "Frame ID required" , "usbvideo.probe.framing.D0" , FT_BOOLEAN , 2 , TFS ( & tfs_yes_no ) , ( 1 << 0 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_probe_framing_D [ 1 ] , {
 "EOF utilized" , "usbvideo.probe.framing.D1" , FT_BOOLEAN , 2 , TFS ( & tfs_yes_no ) , ( 1 << 1 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_probe_preferred_ver , {
 "bPreferredVersion" , "usbvideo.probe.preferredVersion" , FT_UINT8 , BASE_DEC , NULL , 0 , "Preferred payload format version" , HFILL }
 }
 , {
 & hf_usb_vid_probe_min_ver , {
 "bMinVersion" , "usbvideo.probe.minVersion" , FT_UINT8 , BASE_DEC , NULL , 0 , "Min supported payload format version" , HFILL }
 }
 , {
 & hf_usb_vid_probe_max_ver , {
 "bPreferredVersion" , "usbvideo.probe.maxVer" , FT_UINT8 , BASE_DEC , NULL , 0 , "Max supported payload format version" , HFILL }
 }
 , {
 & hf_usb_vid_control_ifdesc_dwClockFrequency , {
 "dwClockFrequency" , "usbvideo.probe.clockFrequency" , FT_UINT32 , BASE_DEC , NULL , 0 , "Device clock frequency (Hz) for selected format" , HFILL }
 }
 , {
 & hf_usb_vid_format_index , {
 "bFormatIndex" , "usbvideo.format.index" , FT_UINT8 , BASE_DEC , NULL , 0 , "Index of this format descriptor" , HFILL }
 }
 , {
 & hf_usb_vid_format_num_frame_descriptors , {
 "bNumFrameDescriptors" , "usbvideo.format.numFrameDescriptors" , FT_UINT8 , BASE_DEC , NULL , 0 , "Number of frame descriptors for this format" , HFILL }
 }
 , {
 & hf_usb_vid_format_guid , {
 "guidFormat" , "usbvideo.format.guid" , FT_GUID , BASE_NONE , NULL , 0 , "Stream encoding format" , HFILL }
 }
 , {
 & hf_usb_vid_format_bits_per_pixel , {
 "bBitsPerPixel" , "usbvideo.format.bitsPerPixel" , FT_UINT8 , BASE_DEC , NULL , 0 , "Bits per pixel" , HFILL }
 }
 , {
 & hf_usb_vid_default_frame_index , {
 "bDefaultFrameIndex" , "usbvideo.format.defaultFrameIndex" , FT_UINT8 , BASE_DEC , NULL , 0 , "Optimum frame index for this stream" , HFILL }
 }
 , {
 & hf_usb_vid_aspect_ratio_x , {
 "bAspectRatioX" , "usbvideo.format.aspectRatioX" , FT_UINT8 , BASE_DEC , NULL , 0 , "X dimension of picture aspect ratio" , HFILL }
 }
 , {
 & hf_usb_vid_aspect_ratio_y , {
 "bAspectRatioY" , "usbvideo.format.aspectRatioY" , FT_UINT8 , BASE_DEC , NULL , 0 , "Y dimension of picture aspect ratio" , HFILL }
 }
 , {
 & hf_usb_vid_interlace_flags , {
 "bmInterlaceFlags" , "usbvideo.format.interlace" , FT_UINT8 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_is_interlaced , {
 "Interlaced stream" , "usbvideo.format.interlace.D0" , FT_BOOLEAN , 8 , TFS ( & is_interlaced_meaning ) , ( 1 << 0 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_interlaced_fields , {
 "Fields per frame" , "usbvideo.format.interlace.D1" , FT_BOOLEAN , 8 , TFS ( & interlaced_fields_meaning ) , ( 1 << 1 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_field_1_first , {
 "Field 1 first" , "usbvideo.format.interlace.D2" , FT_BOOLEAN , 8 , TFS ( & tfs_yes_no ) , ( 1 << 2 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_field_pattern , {
 "Field pattern" , "usbvideo.format.interlace.pattern" , FT_UINT8 , BASE_DEC | BASE_EXT_STRING , & field_pattern_meaning_ext , ( 3 << 4 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_copy_protect , {
 "bCopyProtect" , "usbvideo.format.copyProtect" , FT_UINT8 , BASE_DEC , VALS ( copy_protect_meaning ) , 0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_variable_size , {
 "Variable size" , "usbvideo.format.variableSize" , FT_BOOLEAN , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_mjpeg_flags , {
 "bmFlags" , "usbvideo.mjpeg.flags" , FT_UINT8 , BASE_HEX , NULL , 0 , "Characteristics" , HFILL }
 }
 , {
 & hf_usb_vid_mjpeg_fixed_samples , {
 "Fixed size samples" , "usbvideo.mjpeg.fixed_size" , FT_BOOLEAN , 8 , TFS ( & tfs_yes_no ) , ( 1 << 0 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_frame_index , {
 "bFrameIndex" , "usbvideo.frame.index" , FT_UINT8 , BASE_DEC , NULL , 0 , "Index of this frame descriptor" , HFILL }
 }
 , {
 & hf_usb_vid_frame_capabilities , {
 "bmCapabilities" , "usbvideo.frame.capabilities" , FT_UINT8 , BASE_HEX , NULL , 0 , "Capabilities" , HFILL }
 }
 , {
 & hf_usb_vid_frame_stills_supported , {
 "Still image" , "usbvideo.frame.stills" , FT_BOOLEAN , 8 , TFS ( & tfs_supported_not_supported ) , ( 1 << 0 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_frame_interval , {
 "dwFrameInterval" , "usbvideo.frame.interval" , FT_UINT32 , BASE_DEC , NULL , 0 , "Frame interval multiple of 100 ns" , HFILL }
 }
 , {
 & hf_usb_vid_frame_fixed_frame_rate , {
 "Fixed frame rate" , "usbvideo.frame.fixedRate" , FT_BOOLEAN , 8 , TFS ( & tfs_yes_no ) , ( 1 << 1 ) , NULL , HFILL }
 }
 , {
 & hf_usb_vid_frame_width , {
 "wWidth" , "usbvideo.frame.width" , FT_UINT16 , BASE_DEC , NULL , 0 , "Width of frame in pixels" , HFILL }
 }
 , {
 & hf_usb_vid_frame_height , {
 "wHeight" , "usbvideo.frame.height" , FT_UINT16 , BASE_DEC , NULL , 0 , "Height of frame in pixels" , HFILL }
 }
 , {
 & hf_usb_vid_frame_min_bit_rate , {
 "dwMinBitRate" , "usbvideo.frame.minBitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "Minimum bit rate in bps" , HFILL }
 }
 , {
 & hf_usb_vid_frame_max_bit_rate , {
 "dwMaxBitRate" , "usbvideo.frame.maxBitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "Maximum bit rate in bps" , HFILL }
 }
 , {
 & hf_usb_vid_frame_max_frame_sz , {
 "dwMaxVideoFrameBufferSize" , "usbvideo.frame.maxBuffer" , FT_UINT32 , BASE_DEC , NULL , 0 , "Maximum bytes per frame" , HFILL }
 }
 , {
 & hf_usb_vid_frame_default_interval , {
 "dwDefaultFrameInterval" , "usbvideo.frame.interval.default" , FT_UINT32 , BASE_DEC , NULL , 0 , "Suggested default" , HFILL }
 }
 , {
 & hf_usb_vid_frame_interval_type , {
 "bFrameIntervalType" , "usbvideo.frame.interval.type" , FT_UINT8 , BASE_DEC , NULL , 0 , "Frame rate control (continuous/discrete)" , HFILL }
 }
 , {
 & hf_usb_vid_frame_min_interval , {
 "dwMinFrameInterval" , "usbvideo.frame.interval.min" , FT_UINT32 , BASE_DEC , NULL , 0 , "Shortest frame interval (* 100 ns)" , HFILL }
 }
 , {
 & hf_usb_vid_frame_max_interval , {
 "dwMaxFrameInterval" , "usbvideo.frame.interval.max" , FT_UINT32 , BASE_DEC , NULL , 0 , "Longest frame interval (* 100 ns)" , HFILL }
 }
 , {
 & hf_usb_vid_frame_step_interval , {
 "dwMinFrameInterval" , "usbvideo.frame.interval.step" , FT_UINT32 , BASE_DEC , NULL , 0 , "Granularity of frame interval (* 100 ns)" , HFILL }
 }
 , {
 & hf_usb_vid_frame_bytes_per_line , {
 "dwBytesPerLine" , "usbvideo.frame.bytesPerLine" , FT_UINT32 , BASE_DEC , NULL , 0 , "Fixed number of bytes per video line" , HFILL }
 }
 , {
 & hf_usb_vid_color_primaries , {
 "bColorPrimaries" , "usbvideo.color.primaries" , FT_UINT8 , BASE_DEC | BASE_EXT_STRING , & color_primaries_meaning_ext , 0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_transfer_characteristics , {
 "bTransferCharacteristics" , "usbvideo.color.transferCharacteristics" , FT_UINT8 , BASE_DEC | BASE_EXT_STRING , & color_transfer_characteristics_ext , 0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_matrix_coefficients , {
 "bMatrixCoefficients" , "usbvideo.color.matrixCoefficients" , FT_UINT8 , BASE_DEC | BASE_EXT_STRING , & matrix_coefficients_meaning_ext , 0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_ifdesc_bcdUVC , {
 "bcdUVC" , "usbvideo.bcdUVC" , FT_UINT16 , BASE_HEX , NULL , 0 , "Video Device Class Specification release number" , HFILL }
 }
 , {
 & hf_usb_vid_control_ifdesc_bInCollection , {
 "bInCollection" , "usbvideo.numStreamingInterfaces" , FT_UINT8 , BASE_DEC , NULL , 0 , "Number of VideoStreaming interfaces" , HFILL }
 }
 , {
 & hf_usb_vid_control_ifdesc_baInterfaceNr , {
 "baInterfaceNr" , "usbvideo.streamingInterfaceNumbers" , FT_BYTES , BASE_NONE , NULL , 0 , "Interface numbers of VideoStreaming interfaces" , HFILL }
 }
 , {
 & hf_usb_vid_streaming_ifdesc_bNumFormats , {
 "bNumFormats" , "usbvideo.streaming.numFormats" , FT_UINT8 , BASE_DEC , NULL , 0 , "Number of video payload format descriptors" , HFILL }
 }
 , {
 & hf_usb_vid_streaming_bmInfo , {
 "bmInfo" , "usbvideo.streaming.info" , FT_UINT8 , BASE_HEX , NULL , 0 , "Capabilities" , HFILL }
 }
 , {
 & hf_usb_vid_streaming_info_D [ 0 ] , {
 "Dynamic Format Change" , "usbvideo.streaming.info.D0" , FT_BOOLEAN , 8 , TFS ( & tfs_yes_no ) , ( 1 << 0 ) , "Dynamic Format Change" , HFILL }
 }
 , {
 & hf_usb_vid_streaming_control_D [ 0 ] , {
 "wKeyFrameRate" , "usbvideo.streaming.control.D0" , FT_BOOLEAN , 6 , TFS ( & tfs_yes_no ) , ( 1 << 0 ) , "Probe and Commit support" , HFILL }
 }
 , {
 & hf_usb_vid_streaming_control_D [ 1 ] , {
 "wPFrameRate" , "usbvideo.streaming.control.D1" , FT_BOOLEAN , 6 , TFS ( & tfs_yes_no ) , ( 1 << 1 ) , "Probe and Commit support" , HFILL }
 }
 , {
 & hf_usb_vid_streaming_control_D [ 2 ] , {
 "wCompQuality" , "usbvideo.streaming.control.D2" , FT_BOOLEAN , 6 , TFS ( & tfs_yes_no ) , ( 1 << 2 ) , "Probe and Commit support" , HFILL }
 }
 , {
 & hf_usb_vid_streaming_control_D [ 3 ] , {
 "wCompWindowSize" , "usbvideo.streaming.control.D3" , FT_BOOLEAN , 6 , TFS ( & tfs_yes_no ) , ( 1 << 3 ) , "Probe and Commit support" , HFILL }
 }
 , {
 & hf_usb_vid_streaming_control_D [ 4 ] , {
 "Generate Key Frame" , "usbvideo.streaming.control.D4" , FT_BOOLEAN , 6 , TFS ( & tfs_yes_no ) , ( 1 << 4 ) , "Probe and Commit support" , HFILL }
 }
 , {
 & hf_usb_vid_streaming_control_D [ 5 ] , {
 "Update Frame Segment" , "usbvideo.streaming.control.D5" , FT_BOOLEAN , 6 , TFS ( & tfs_yes_no ) , ( 1 << 5 ) , "Probe and Commit support" , HFILL }
 }
 , {
 & hf_usb_vid_streaming_terminal_link , {
 "bTerminalLink" , "usbvideo.streaming.terminalLink" , FT_UINT8 , BASE_DEC , NULL , 0x0 , "Output terminal ID" , HFILL }
 }
 , {
 & hf_usb_vid_streaming_still_capture_method , {
 "bStillCaptureMethod" , "usbvideo.streaming.stillCaptureMethod" , FT_UINT8 , BASE_DEC | BASE_EXT_STRING , & vs_still_capture_methods_ext , 0 , "Method of Still Image Capture" , HFILL }
 }
 , {
 & hf_usb_vid_streaming_trigger_support , {
 "HW Triggering" , "usbvideo.streaming.triggerSupport" , FT_BOOLEAN , BASE_DEC , TFS ( & tfs_supported_not_supported ) , 0 , "Is HW triggering supported" , HFILL }
 }
 , {
 & hf_usb_vid_streaming_trigger_usage , {
 "bTriggerUsage" , "usbvideo.streaming.triggerUsage" , FT_UINT8 , BASE_DEC , VALS ( vs_trigger_usage ) , 0 , "How host SW should respond to trigger" , HFILL }
 }
 , {
 & hf_usb_vid_interrupt_bStatusType , {
 "Status Type" , "usbvideo.interrupt.statusType" , FT_UINT8 , BASE_HEX , VALS ( interrupt_status_types ) , 0xF , NULL , HFILL }
 }
 , {
 & hf_usb_vid_interrupt_bAttribute , {
 "Change Type" , "usbvideo.interrupt.attribute" , FT_UINT8 , BASE_HEX | BASE_EXT_STRING , & control_change_types_ext , 0 , "Type of control change" , HFILL }
 }
 , {
 & hf_usb_vid_interrupt_bOriginator , {
 "Originator" , "usbvideo.interrupt.originator" , FT_UINT8 , BASE_DEC , NULL , 0 , "ID of the entity that reports this interrupt" , HFILL }
 }
 , {
 & hf_usb_vid_control_interrupt_bEvent , {
 "Event" , "usbvideo.interrupt.controlEvent" , FT_UINT8 , BASE_HEX , VALS ( control_interrupt_events ) , 0 , "Type of event" , HFILL }
 }
 , {
 & hf_usb_vid_epdesc_subtype , {
 "Subtype" , "usbvideo.ep.descriptorSubType" , FT_UINT8 , BASE_DEC , VALS ( vc_ep_descriptor_subtypes ) , 0 , "Descriptor Subtype" , HFILL }
 }
 , {
 & hf_usb_vid_epdesc_max_transfer_sz , {
 "wMaxTransferSize" , "usbvideo.ep.maxInterruptSize" , FT_UINT16 , BASE_DEC , NULL , 0x0 , "Max interrupt structure size" , HFILL }
 }
 , {
 & hf_usb_vid_ifdesc_wTotalLength , {
 "wTotalLength" , "usbvideo.totalLength" , FT_UINT16 , BASE_DEC , NULL , 0 , "Video interface descriptor size" , HFILL }
 }
 , {
 & hf_usb_vid_bControlSize , {
 "bControlSize" , "usbvideo.bmcontrolSize" , FT_UINT8 , BASE_DEC , NULL , 0 , "Size of bmControls field" , HFILL }
 }
 , {
 & hf_usb_vid_bmControl , {
 "bmControl" , "usbvideo.availableControls" , FT_UINT32 , BASE_HEX , NULL , 0 , "Available controls" , HFILL }
 }
 , {
 & hf_usb_vid_bmControl_bytes , {
 "bmControl" , "usbvideo.availableControls.bytes" , FT_BYTES , BASE_NONE , NULL , 0 , "Available controls" , HFILL }
 }
 , {
 & hf_usb_vid_control_ifdesc_src_id , {
 "bSourceID" , "usbvideo.sourceID" , FT_UINT8 , BASE_DEC , NULL , 0x0 , "Entity to which this terminal/unit is connected" , HFILL }
 }
 , {
 & hf_usb_vid_control_ifdesc_subtype , {
 "Subtype" , "usbvideo.control.descriptorSubType" , FT_UINT8 , BASE_DEC | BASE_EXT_STRING , & vc_if_descriptor_subtypes_ext , 0 , "Descriptor Subtype" , HFILL }
 }
 , {
 & hf_usb_vid_streaming_ifdesc_subtype , {
 "Subtype" , "usbvideo.streaming.descriptorSubType" , FT_UINT8 , BASE_DEC | BASE_EXT_STRING , & vs_if_descriptor_subtypes_ext , 0 , "Descriptor Subtype" , HFILL }
 }
 , {
 & hf_usb_vid_descriptor_data , {
 "Descriptor data" , "usbvideo.descriptor_data" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_data , {
 "Control data" , "usbvideo.control_data" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_control_value , {
 "Control value" , "usbvideo.control_value" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_usb_vid_value_data , {
 "Value data" , "usbvideo.value_data" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , }
 ;
 static gint * usb_vid_subtrees [ ] = {
 & ett_usb_vid , & ett_descriptor_video_endpoint , & ett_descriptor_video_control , & ett_descriptor_video_streaming , & ett_camera_controls , & ett_processing_controls , & ett_streaming_controls , & ett_streaming_info , & ett_interlace_flags , & ett_frame_capability_flags , & ett_mjpeg_flags , & ett_video_probe , & ett_probe_hint , & ett_probe_framing , & ett_video_standards , & ett_control_capabilities }
 ;
 static ei_register_info ei [ ] = {
 {
 & ei_usb_vid_subtype_unknown , {
 "usbvideo.subtype.unknown" , PI_UNDECODED , PI_WARN , "Unknown VC subtype" , EXPFILL }
 }
 , {
 & ei_usb_vid_bitmask_len , {
 "usbvideo.bitmask_len_error" , PI_UNDECODED , PI_WARN , "Only least-significant bytes decoded" , EXPFILL }
 }
 , }
 ;
 expert_module_t * expert_usb_vid ;
 proto_usb_vid = proto_register_protocol ( "USB Video" , "USBVIDEO" , "usbvideo" ) ;
 proto_register_field_array ( proto_usb_vid , hf , array_length ( hf ) ) ;
 proto_register_subtree_array ( usb_vid_subtrees , array_length ( usb_vid_subtrees ) ) ;
 expert_usb_vid = expert_register_protocol ( proto_usb_vid ) ;
 expert_register_field_array ( expert_usb_vid , ei , array_length ( ei ) ) ;
 }