void proto_register_dcerpc_spoolss ( void ) {
 static hf_register_info hf [ ] = {
 {
 & hf_clientmajorversion , {
 "Client major version" , "spoolss.clientmajorversion" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Client printer driver major version" , HFILL }
 }
 , {
 & hf_clientminorversion , {
 "Client minor version" , "spoolss.clientminorversion" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Client printer driver minor version" , HFILL }
 }
 , {
 & hf_servermajorversion , {
 "Server major version" , "spoolss.servermajorversion" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Server printer driver major version" , HFILL }
 }
 , {
 & hf_serverminorversion , {
 "Server minor version" , "spoolss.serverminorversion" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Server printer driver minor version" , HFILL }
 }
 , {
 & hf_driverpath , {
 "Driver path" , "spoolss.driverpath" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_datafile , {
 "Data file" , "spoolss.datafile" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_configfile , {
 "Config file" , "spoolss.configfile" , FT_STRING , BASE_NONE , NULL , 0 , "Printer name" , HFILL }
 }
 , {
 & hf_helpfile , {
 "Help file" , "spoolss.helpfile" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_monitorname , {
 "Monitor name" , "spoolss.monitorname" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_defaultdatatype , {
 "Default data type" , "spoolss.defaultdatatype" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_driverinfo_cversion , {
 "Driver version" , "spoolss.driverversion" , FT_UINT32 , BASE_DEC , VALS ( driverinfo_cversion_vals ) , 0 , "Printer name" , HFILL }
 }
 , {
 & hf_dependentfiles , {
 "Dependent files" , "spoolss.dependentfiles" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_status , {
 "Status" , "spoolss.printer_status" , FT_UINT32 , BASE_DEC | BASE_EXT_STRING , & printer_status_vals_ext , 0 , NULL , HFILL }
 }
 , {
 & hf_previousdrivernames , {
 "Previous Driver Names" , "spoolss.previousdrivernames" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_driverdate , {
 "Driver Date" , "spoolss.driverdate" , FT_ABSOLUTE_TIME , ABSOLUTE_TIME_LOCAL , NULL , 0 , "Date of driver creation" , HFILL }
 }
 , {
 & hf_padding , {
 "Padding" , "spoolss.padding" , FT_UINT32 , BASE_HEX , NULL , 0 , "Some padding - conveys no semantic information" , HFILL }
 }
 , {
 & hf_driver_version_low , {
 "Minor Driver Version" , "spoolss.minordriverversion" , FT_UINT32 , BASE_DEC , NULL , 0 , "Driver Version Low" , HFILL }
 }
 , {
 & hf_driver_version_high , {
 "Major Driver Version" , "spoolss.majordriverversion" , FT_UINT32 , BASE_DEC , NULL , 0 , "Driver Version High" , HFILL }
 }
 , {
 & hf_mfgname , {
 "Mfgname" , "spoolss.mfgname" , FT_STRING , BASE_NONE , NULL , 0 , "Manufacturer Name" , HFILL }
 }
 , {
 & hf_oemurl , {
 "OEM URL" , "spoolss.oemrul" , FT_STRING , BASE_NONE , NULL , 0 , "OEM URL - Website of Vendor" , HFILL }
 }
 , {
 & hf_hardwareid , {
 "Hardware ID" , "spoolss.hardwareid" , FT_STRING , BASE_NONE , NULL , 0 , "Hardware Identification Information" , HFILL }
 }
 , {
 & hf_provider , {
 "Provider" , "spoolss.provider" , FT_STRING , BASE_NONE , NULL , 0 , "Provider of Driver" , HFILL }
 }
 , {
 & hf_setprinter_cmd , {
 "Command" , "spoolss.setprinter_cmd" , FT_UINT32 , BASE_DEC , VALS ( setprinter_cmd_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_enumprinters_flags , {
 "Flags" , "spoolss.enumprinters.flags" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_enumprinters_flags_local , {
 "Enum local" , "spoolss.enumprinters.flags.enum_local" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , PRINTER_ENUM_LOCAL , NULL , HFILL }
 }
 , {
 & hf_enumprinters_flags_name , {
 "Enum name" , "spoolss.enumprinters.flags.enum_name" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , PRINTER_ENUM_NAME , NULL , HFILL }
 }
 , {
 & hf_enumprinters_flags_shared , {
 "Enum shared" , "spoolss.enumprinters.flags.enum_shared" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , PRINTER_ENUM_SHARED , NULL , HFILL }
 }
 , {
 & hf_enumprinters_flags_default , {
 "Enum default" , "spoolss.enumprinters.flags.enum_default" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , PRINTER_ENUM_DEFAULT , NULL , HFILL }
 }
 , {
 & hf_enumprinters_flags_connections , {
 "Enum connections" , "spoolss.enumprinters.flags.enum_connections" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , PRINTER_ENUM_CONNECTIONS , NULL , HFILL }
 }
 , {
 & hf_enumprinters_flags_network , {
 "Enum network" , "spoolss.enumprinters.flags.enum_network" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , PRINTER_ENUM_NETWORK , NULL , HFILL }
 }
 , {
 & hf_enumprinters_flags_remote , {
 "Enum remote" , "spoolss.enumprinters.flags.enum_remote" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , PRINTER_ENUM_REMOTE , NULL , HFILL }
 }
 , {
 & hf_start_time , {
 "Start time" , "spoolss.start_time" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_end_time , {
 "End time" , "spoolss.end_time" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_elapsed_time , {
 "Elapsed time" , "spoolss.elapsed_time" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_opnum , {
 "Operation" , "spoolss.opnum" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_hnd , {
 "Context handle" , "spoolss.hnd" , FT_BYTES , BASE_NONE , NULL , 0x0 , "SPOOLSS policy handle" , HFILL }
 }
 , {
 & hf_rc , {
 "Return code" , "spoolss.rc" , FT_UINT32 , BASE_HEX | BASE_EXT_STRING , & DOS_errors_ext , 0x0 , "SPOOLSS return code" , HFILL }
 }
 , {
 & hf_offered , {
 "Offered" , "spoolss.offered" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Size of buffer offered in this request" , HFILL }
 }
 , {
 & hf_needed , {
 "Needed" , "spoolss.needed" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Size of buffer required for request" , HFILL }
 }
 , {
 & hf_returned , {
 "Returned" , "spoolss.returned" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Number of items returned" , HFILL }
 }
 , {
 & hf_buffer_size , {
 "Buffer size" , "spoolss.buffer.size" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Size of buffer" , HFILL }
 }
 , {
 & hf_buffer_data , {
 "Buffer data" , "spoolss.buffer.data" , FT_BYTES , BASE_NONE , NULL , 0x0 , "Contents of buffer" , HFILL }
 }
 , {
 & hf_string_parm_size , {
 "String buffer size" , "spoolss.string.buffersize" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Size of string buffer" , HFILL }
 }
 , {
 & hf_string_parm_data , {
 "String data" , "spoolss.string.data" , FT_STRINGZ , BASE_NONE , NULL , 0x0 , "Contents of string" , HFILL }
 }
 , {
 & hf_offset , {
 "Offset" , "spoolss.offset" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Offset of data" , HFILL }
 }
 , {
 & hf_level , {
 "Info level" , "spoolss.enumjobs.level" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_printername , {
 "Printer name" , "spoolss.printername" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_machinename , {
 "Machine name" , "spoolss.machinename" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notifyname , {
 "Notify name" , "spoolss.notifyname" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printerdesc , {
 "Printer description" , "spoolss.printerdesc" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printercomment , {
 "Printer comment" , "spoolss.printercomment" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_servername , {
 "Server name" , "spoolss.servername" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_sharename , {
 "Share name" , "spoolss.sharename" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_portname , {
 "Port name" , "spoolss.portname" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printerlocation , {
 "Printer location" , "spoolss.printerlocation" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_environment , {
 "Environment name" , "spoolss.environment" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_drivername , {
 "Driver name" , "spoolss.drivername" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_username , {
 "User name" , "spoolss.username" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_documentname , {
 "Document name" , "spoolss.document" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_outputfile , {
 "Output file" , "spoolss.outputfile" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_datatype , {
 "Datatype" , "spoolss.datatype" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_textstatus , {
 "Text status" , "spoolss.textstatus" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_sepfile , {
 "Separator file" , "spoolss.setpfile" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_parameters , {
 "Parameters" , "spoolss.parameters" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printprocessor , {
 "Print processor" , "spoolss.printprocessor" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printerdata , {
 "Data" , "spoolss.printerdata" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printerdata_key , {
 "Key" , "spoolss.printerdata.key" , FT_STRING , BASE_NONE , NULL , 0 , "Printer data key" , HFILL }
 }
 , {
 & hf_printerdata_value , {
 "Value" , "spoolss.printerdata.value" , FT_STRING , BASE_NONE , NULL , 0 , "Printer data value" , HFILL }
 }
 , {
 & hf_printerdata_type , {
 "Type" , "spoolss.printerdata.type" , FT_UINT32 , BASE_DEC | BASE_EXT_STRING , & reg_datatypes_ext , 0 , "Printer data type" , HFILL }
 }
 , {
 & hf_printerdata_size , {
 "Size" , "spoolss.printerdata.size" , FT_UINT32 , BASE_DEC , NULL , 0 , "Printer data size" , HFILL }
 }
 , {
 & hf_printerdata_data , {
 "Data" , "spoolss.printerdata.data" , FT_BYTES , BASE_NONE , NULL , 0x0 , "Printer data" , HFILL }
 }
 , {
 & hf_printerdata_data_dword , {
 "DWORD data" , "spoolss.printerdata.data.dword" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printerdata_data_sz , {
 "String data" , "spoolss.printerdata.data.sz" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmodectr_size , {
 "Devicemode ctr size" , "spoolss.devicemodectr.size" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode , {
 "Devicemode" , "spoolss.devmode" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_size , {
 "Size" , "spoolss.devmode.size" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_spec_version , {
 "Spec version" , "spoolss.devmode.spec_version" , FT_UINT16 , BASE_DEC , VALS ( devmode_specversion_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_driver_version , {
 "Driver version" , "spoolss.devmode.driver_version" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_size2 , {
 "Size2" , "spoolss.devmode.size2" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_fields , {
 "Fields" , "spoolss.devmode.fields" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_orientation , {
 "Orientation" , "spoolss.devmode.orientation" , FT_UINT16 , BASE_DEC , VALS ( devmode_orientation_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_paper_size , {
 "Paper size" , "spoolss.devmode.paper_size" , FT_UINT16 , BASE_DEC | BASE_EXT_STRING , & devmode_papersize_vals_ext , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_paper_width , {
 "Paper width" , "spoolss.devmode.paper_width" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_paper_length , {
 "Paper length" , "spoolss.devmode.paper_length" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_scale , {
 "Scale" , "spoolss.devmode.scale" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_copies , {
 "Copies" , "spoolss.devmode.copies" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_default_source , {
 "Default source" , "spoolss.devmode.default_source" , FT_UINT16 , BASE_DEC | BASE_EXT_STRING , & devmode_papersource_vals_ext , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_print_quality , {
 "Print quality" , "spoolss.devmode.print_quality" , FT_UINT16 , BASE_DEC , VALS ( devmode_printquality_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_color , {
 "Color" , "spoolss.devmode.color" , FT_UINT16 , BASE_DEC , VALS ( devmode_colour_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_duplex , {
 "Duplex" , "spoolss.devmode.duplex" , FT_UINT16 , BASE_DEC , VALS ( devmode_duplex_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_y_resolution , {
 "Y resolution" , "spoolss.devmode.y_resolution" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_tt_option , {
 "TT option" , "spoolss.devmode.tt_option" , FT_UINT16 , BASE_DEC , VALS ( devmode_ttoption_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_collate , {
 "Collate" , "spoolss.devmode.collate" , FT_UINT16 , BASE_DEC , VALS ( devmode_collate_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_log_pixels , {
 "Log pixels" , "spoolss.devmode.log_pixels" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_bits_per_pel , {
 "Bits per pel" , "spoolss.devmode.bits_per_pel" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_pels_width , {
 "Pels width" , "spoolss.devmode.pels_width" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_pels_height , {
 "Pels height" , "spoolss.devmode.pels_height" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_display_flags , {
 "Display flags" , "spoolss.devmode.display_flags" , FT_UINT32 , BASE_DEC , VALS ( devmode_displayflags_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_display_freq , {
 "Display frequency" , "spoolss.devmode.display_freq" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_icm_method , {
 "ICM method" , "spoolss.devmode.icm_method" , FT_UINT32 , BASE_DEC , VALS ( devmode_icmmethod_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_icm_intent , {
 "ICM intent" , "spoolss.devmode.icm_intent" , FT_UINT32 , BASE_DEC , VALS ( devmode_icmintent_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_media_type , {
 "Media type" , "spoolss.devmode.media_type" , FT_UINT32 , BASE_DEC , VALS ( devmode_mediatype_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_dither_type , {
 "Dither type" , "spoolss.devmode.dither_type" , FT_UINT32 , BASE_DEC , VALS ( devmode_dithertype_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_reserved1 , {
 "Reserved1" , "spoolss.devmode.reserved1" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_reserved2 , {
 "Reserved2" , "spoolss.devmode.reserved2" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_panning_width , {
 "Panning width" , "spoolss.devmode.panning_width" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_panning_height , {
 "Panning height" , "spoolss.devmode.panning_height" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_driver_extra_len , {
 "Driver extra length" , "spoolss.devmode.driver_extra_len" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_driver_extra , {
 "Driver extra" , "spoolss.devmode.driver_extra" , FT_BYTES , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_orientation , {
 "Orientation" , "spoolss.devmode.fields.orientation" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_ORIENTATION , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_papersize , {
 "Paper size" , "spoolss.devmode.fields.paper_size" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_PAPERSIZE , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_paperlength , {
 "Paper length" , "spoolss.devmode.fields.paper_length" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_PAPERLENGTH , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_paperwidth , {
 "Paper width" , "spoolss.devmode.fields.paper_width" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_PAPERWIDTH , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_scale , {
 "Scale" , "spoolss.devmode.fields.scale" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_SCALE , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_position , {
 "Position" , "spoolss.devmode.fields.position" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_POSITION , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_nup , {
 "N-up" , "spoolss.devmode.fields.nup" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_NUP , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_copies , {
 "Copies" , "spoolss.devmode.fields.copies" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_COPIES , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_defaultsource , {
 "Default source" , "spoolss.devmode.fields.default_source" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_DEFAULTSOURCE , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_printquality , {
 "Print quality" , "spoolss.devmode.fields.print_quality" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_PRINTQUALITY , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_color , {
 "Color" , "spoolss.devmode.fields.color" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_COLOR , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_duplex , {
 "Duplex" , "spoolss.devmode.fields.duplex" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_DUPLEX , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_yresolution , {
 "Y resolution" , "spoolss.devmode.fields.y_resolution" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_YRESOLUTION , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_ttoption , {
 "TT option" , "spoolss.devmode.fields.tt_option" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_TTOPTION , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_collate , {
 "Collate" , "spoolss.devmode.fields.collate" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_COLLATE , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_formname , {
 "Form name" , "spoolss.devmode.fields.form_name" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_FORMNAME , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_logpixels , {
 "Log pixels" , "spoolss.devmode.fields.log_pixels" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_LOGPIXELS , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_bitsperpel , {
 "Bits per pel" , "spoolss.devmode.fields.bits_per_pel" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_BITSPERPEL , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_pelswidth , {
 "Pels width" , "spoolss.devmode.fields.pels_width" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_PELSWIDTH , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_pelsheight , {
 "Pels height" , "spoolss.devmode.fields.pels_height" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_PELSHEIGHT , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_displayflags , {
 "Display flags" , "spoolss.devmode.fields.display_flags" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_DISPLAYFLAGS , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_displayfrequency , {
 "Display frequency" , "spoolss.devmode.fields.display_frequency" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_DISPLAYFREQUENCY , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_icmmethod , {
 "ICM method" , "spoolss.devmode.fields.icm_method" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_ICMMETHOD , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_icmintent , {
 "ICM intent" , "spoolss.devmode.fields.icm_intent" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_ICMINTENT , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_mediatype , {
 "Media type" , "spoolss.devmode.fields.media_type" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_MEDIATYPE , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_dithertype , {
 "Dither type" , "spoolss.devmode.fields.dither_type" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_DITHERTYPE , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_panningwidth , {
 "Panning width" , "spoolss.devmode.fields.panning_width" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_PANNINGWIDTH , NULL , HFILL }
 }
 , {
 & hf_devmode_fields_panningheight , {
 "Panning height" , "spoolss.devmode.fields.panning_height" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , DEVMODE_PANNINGHEIGHT , NULL , HFILL }
 }
 , {
 & hf_enumprinterdata_enumindex , {
 "Enum index" , "spoolss.enumprinterdata.enumindex" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Index for start of enumeration" , HFILL }
 }
 , {
 & hf_enumprinterdata_value_offered , {
 "Value size offered" , "spoolss.enumprinterdata.value_offered" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Buffer size offered for printerdata value" , HFILL }
 }
 , {
 & hf_enumprinterdata_data_offered , {
 "Data size offered" , "spoolss.enumprinterdata.data_offered" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Buffer size offered for printerdata data" , HFILL }
 }
 , {
 & hf_enumprinterdata_value_len , {
 "Value length" , "spoolss.enumprinterdata.value_len" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Size of printerdata value" , HFILL }
 }
 , {
 & hf_enumprinterdata_value_needed , {
 "Value size needed" , "spoolss.enumprinterdata.value_needed" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Buffer size needed for printerdata value" , HFILL }
 }
 , {
 & hf_enumprinterdata_data_needed , {
 "Data size needed" , "spoolss.enumprinterdata.data_needed" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Buffer size needed for printerdata data" , HFILL }
 }
 , {
 & hf_job_id , {
 "Job ID" , "spoolss.job.id" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Job identification number" , HFILL }
 }
 , {
 & hf_job_status , {
 "Job status" , "spoolss.job.status" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_job_status_paused , {
 "Paused" , "spoolss.job.status.paused" , FT_BOOLEAN , 32 , TFS ( & tfs_job_status_paused ) , JOB_STATUS_PAUSED , NULL , HFILL }
 }
 , {
 & hf_job_status_error , {
 "Error" , "spoolss.job.status.error" , FT_BOOLEAN , 32 , TFS ( & tfs_job_status_error ) , JOB_STATUS_ERROR , NULL , HFILL }
 }
 , {
 & hf_job_status_deleting , {
 "Deleting" , "spoolss.job.status.deleting" , FT_BOOLEAN , 32 , TFS ( & tfs_job_status_deleting ) , JOB_STATUS_DELETING , NULL , HFILL }
 }
 , {
 & hf_job_status_spooling , {
 "Spooling" , "spoolss.job.status.spooling" , FT_BOOLEAN , 32 , TFS ( & tfs_job_status_spooling ) , JOB_STATUS_SPOOLING , NULL , HFILL }
 }
 , {
 & hf_job_status_printing , {
 "Printing" , "spoolss.job.status.printing" , FT_BOOLEAN , 32 , TFS ( & tfs_job_status_printing ) , JOB_STATUS_PRINTING , NULL , HFILL }
 }
 , {
 & hf_job_status_offline , {
 "Offline" , "spoolss.job.status.offline" , FT_BOOLEAN , 32 , TFS ( & tfs_job_status_offline ) , JOB_STATUS_OFFLINE , NULL , HFILL }
 }
 , {
 & hf_job_status_paperout , {
 "Paperout" , "spoolss.job.status.paperout" , FT_BOOLEAN , 32 , TFS ( & tfs_job_status_paperout ) , JOB_STATUS_PAPEROUT , NULL , HFILL }
 }
 , {
 & hf_job_status_printed , {
 "Printed" , "spoolss.job.status.printed" , FT_BOOLEAN , 32 , TFS ( & tfs_job_status_printed ) , JOB_STATUS_PRINTED , NULL , HFILL }
 }
 , {
 & hf_job_status_deleted , {
 "Deleted" , "spoolss.job.status.deleted" , FT_BOOLEAN , 32 , TFS ( & tfs_job_status_deleted ) , JOB_STATUS_DELETED , NULL , HFILL }
 }
 , {
 & hf_job_status_blocked , {
 "Blocked" , "spoolss.job.status.blocked" , FT_BOOLEAN , 32 , TFS ( & tfs_job_status_blocked ) , JOB_STATUS_BLOCKED , NULL , HFILL }
 }
 , {
 & hf_job_status_user_intervention , {
 "User intervention" , "spoolss.job.status.user_intervention" , FT_BOOLEAN , 32 , TFS ( & tfs_job_status_user_intervention ) , JOB_STATUS_USER_INTERVENTION , NULL , HFILL }
 }
 , {
 & hf_job_priority , {
 "Job priority" , "spoolss.job.priority" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_job_position , {
 "Job position" , "spoolss.job.position" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_job_totalpages , {
 "Job total pages" , "spoolss.job.totalpages" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_job_totalbytes , {
 "Job total bytes" , "spoolss.job.totalbytes" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_job_bytesprinted , {
 "Job bytes printed" , "spoolss.job.bytesprinted" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_job_pagesprinted , {
 "Job pages printed" , "spoolss.job.pagesprinted" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_job_size , {
 "Job size" , "spoolss.job.size" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_form , {
 "Data" , "spoolss.form" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_form_level , {
 "Level" , "spoolss.form.level" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_form_name , {
 "Name" , "spoolss.form.name" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_form_flags , {
 "Flags" , "spoolss.form.flags" , FT_UINT32 , BASE_DEC , VALS ( form_type_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_form_unknown , {
 "Unknown" , "spoolss.form.unknown" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_form_width , {
 "Width" , "spoolss.form.width" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_form_height , {
 "Height" , "spoolss.form.height" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_form_left_margin , {
 "Left margin" , "spoolss.form.left" , FT_UINT32 , BASE_DEC , NULL , 0 , "Left" , HFILL }
 }
 , {
 & hf_form_top_margin , {
 "Top" , "spoolss.form.top" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_form_horiz_len , {
 "Horizontal" , "spoolss.form.horiz" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_form_vert_len , {
 "Vertical" , "spoolss.form.vert" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_enumforms_num , {
 "Num" , "spoolss.enumforms.num" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_options_version , {
 "Version" , "spoolss.notify_options.version" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_options_flags , {
 "Flags" , "spoolss.notify_options.flags" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_options_count , {
 "Count" , "spoolss.notify_options.count" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_option_type , {
 "Type" , "spoolss.notify_option.type" , FT_UINT16 , BASE_DEC , VALS ( printer_notify_types ) , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_option_reserved1 , {
 "Reserved1" , "spoolss.notify_option.reserved1" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_option_reserved2 , {
 "Reserved2" , "spoolss.notify_option.reserved2" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_option_reserved3 , {
 "Reserved3" , "spoolss.notify_option.reserved3" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_option_count , {
 "Count" , "spoolss.notify_option.count" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_option_data_count , {
 "Count" , "spoolss.notify_option_data.count" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_options_flags_refresh , {
 "Refresh" , "spoolss.notify_options.flags.refresh" , FT_BOOLEAN , 32 , TFS ( & tfs_notify_options_flags_refresh ) , PRINTER_NOTIFY_OPTIONS_REFRESH , NULL , HFILL }
 }
 , {
 & hf_notify_info_count , {
 "Count" , "spoolss.notify_info.count" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_info_version , {
 "Version" , "spoolss.notify_info.version" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_info_flags , {
 "Flags" , "spoolss.notify_info.flags" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_info_data_type , {
 "Type" , "spoolss.notify_info_data.type" , FT_UINT16 , BASE_DEC , VALS ( printer_notify_types ) , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_field , {
 "Field" , "spoolss.notify_field" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_info_data_count , {
 "Count" , "spoolss.notify_info_data.count" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_info_data_id , {
 "Job Id" , "spoolss.notify_info_data.jobid" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_info_data_value1 , {
 "Value1" , "spoolss.notify_info_data.value1" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_info_data_value2 , {
 "Value2" , "spoolss.notify_info_data.value2" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_info_data_bufsize , {
 "Buffer size" , "spoolss.notify_info_data.bufsize" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_info_data_buffer , {
 "Buffer" , "spoolss.notify_info_data.buffer" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_info_data_buffer_len , {
 "Buffer length" , "spoolss.notify_info_data.buffer.len" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_notify_info_data_buffer_data , {
 "Buffer data" , "spoolss.notify_info_data.buffer.data" , FT_BYTES , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_options , {
 "Options" , "spoolss.rffpcnex.options" , FT_UINT32 , BASE_DEC , NULL , 0 , "RFFPCNEX options" , HFILL }
 }
 , {
 & hf_printerlocal , {
 "Printer local" , "spoolss.printer_local" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags , {
 "RFFPCNEX flags" , "spoolss.rffpcnex.flags" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_add_printer , {
 "Add printer" , "spoolss.rffpcnex.flags.add_printer" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_add_printer ) , SPOOLSS_PRINTER_CHANGE_ADD_PRINTER , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_set_printer , {
 "Set printer" , "spoolss.rffpcnex.flags.set_printer" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_set_printer ) , SPOOLSS_PRINTER_CHANGE_SET_PRINTER , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_delete_printer , {
 "Delete printer" , "spoolss.rffpcnex.flags.delete_printer" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_delete_printer ) , SPOOLSS_PRINTER_CHANGE_DELETE_PRINTER , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_add_job , {
 "Add job" , "spoolss.rffpcnex.flags.add_job" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_add_job ) , SPOOLSS_PRINTER_CHANGE_ADD_JOB , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_set_job , {
 "Set job" , "spoolss.rffpcnex.flags.set_job" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_set_job ) , SPOOLSS_PRINTER_CHANGE_SET_JOB , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_delete_job , {
 "Delete job" , "spoolss.rffpcnex.flags.delete_job" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_delete_job ) , SPOOLSS_PRINTER_CHANGE_DELETE_JOB , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_write_job , {
 "Write job" , "spoolss.rffpcnex.flags.write_job" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_write_job ) , SPOOLSS_PRINTER_CHANGE_WRITE_JOB , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_add_form , {
 "Add form" , "spoolss.rffpcnex.flags.add_form" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_add_form ) , SPOOLSS_PRINTER_CHANGE_ADD_FORM , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_set_form , {
 "Set form" , "spoolss.rffpcnex.flags.set_form" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_set_form ) , SPOOLSS_PRINTER_CHANGE_SET_FORM , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_delete_form , {
 "Delete form" , "spoolss.rffpcnex.flags.delete_form" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_delete_form ) , SPOOLSS_PRINTER_CHANGE_DELETE_FORM , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_add_port , {
 "Add port" , "spoolss.rffpcnex.flags.add_port" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_add_port ) , SPOOLSS_PRINTER_CHANGE_ADD_PORT , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_configure_port , {
 "Configure port" , "spoolss.rffpcnex.flags.configure_port" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_configure_port ) , SPOOLSS_PRINTER_CHANGE_CONFIGURE_PORT , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_delete_port , {
 "Delete port" , "spoolss.rffpcnex.flags.delete_port" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_delete_port ) , SPOOLSS_PRINTER_CHANGE_DELETE_PORT , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_add_print_processor , {
 "Add processor" , "spoolss.rffpcnex.flags.add_processor" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_add_print_processor ) , SPOOLSS_PRINTER_CHANGE_ADD_PRINT_PROCESSOR , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_delete_print_processor , {
 "Delete processor" , "spoolss.rffpcnex.flags.delete_processor" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_delete_print_processor ) , SPOOLSS_PRINTER_CHANGE_DELETE_PRINT_PROCESSOR , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_add_driver , {
 "Add driver" , "spoolss.rffpcnex.flags.add_driver" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_add_driver ) , SPOOLSS_PRINTER_CHANGE_ADD_PRINTER_DRIVER , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_set_driver , {
 "Set driver" , "spoolss.rffpcnex.flags.set_driver" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_set_driver ) , SPOOLSS_PRINTER_CHANGE_SET_PRINTER_DRIVER , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_delete_driver , {
 "Delete driver" , "spoolss.rffpcnex.flags.delete_driver" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_delete_driver ) , SPOOLSS_PRINTER_CHANGE_DELETE_PRINTER_DRIVER , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_timeout , {
 "Timeout" , "spoolss.rffpcnex.flags.timeout" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_timeout ) , SPOOLSS_PRINTER_CHANGE_TIMEOUT , NULL , HFILL }
 }
 , {
 & hf_rffpcnex_flags_failed_printer_connection , {
 "Failed printer connection" , "spoolss.rffpcnex.flags.failed_connection_printer" , FT_BOOLEAN , 32 , TFS ( & tfs_rffpcnex_flags_failed_connection_printer ) , SPOOLSS_PRINTER_CHANGE_FAILED_CONNECTION_PRINTER , NULL , HFILL }
 }
 , {
 & hf_rrpcn_changelow , {
 "Change low" , "spoolss.rrpcn.changelow" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_rrpcn_changehigh , {
 "Change high" , "spoolss.rrpcn.changehigh" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_rrpcn_unk0 , {
 "Unknown 0" , "spoolss.rrpcn.unk0" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_rrpcn_unk1 , {
 "Unknown 1" , "spoolss.rrpcn.unk1" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_replyopenprinter_unk0 , {
 "Unknown 0" , "spoolss.replyopenprinter.unk0" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_replyopenprinter_unk1 , {
 "Unknown 1" , "spoolss.replyopenprinter.unk1" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_devicename , {
 "DeviceName" , "spoolss.devmode.devicename" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_devmode_form_name , {
 "FormName" , "spoolss.devmode.form_name" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_relative_string , {
 "String" , "spoolss.relative_string" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_value_name , {
 "Value Name" , "spoolss.value_name" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_keybuffer , {
 "Key" , "spoolss.hf_keybuffer" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_value_string , {
 "Value" , "spoolss.value_string" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_attributes , {
 "Attributes" , "spoolss.printer_attributes" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_attributes_queued , {
 "Queued" , "spoolss.printer_attributes.queued" , FT_BOOLEAN , 32 , TFS ( & tfs_printer_attributes_queued ) , PRINTER_ATTRIBUTE_QUEUED , NULL , HFILL }
 }
 , {
 & hf_printer_attributes_direct , {
 "Direct" , "spoolss.printer_attributes.direct" , FT_BOOLEAN , 32 , TFS ( & tfs_printer_attributes_direct ) , PRINTER_ATTRIBUTE_DIRECT , NULL , HFILL }
 }
 , {
 & hf_printer_attributes_default , {
 "Default (9x/ME only)" , "spoolss.printer_attributes.default" , FT_BOOLEAN , 32 , TFS ( & tfs_printer_attributes_default ) , PRINTER_ATTRIBUTE_DEFAULT , "Default" , HFILL }
 }
 , {
 & hf_printer_attributes_shared , {
 "Shared" , "spoolss.printer_attributes.shared" , FT_BOOLEAN , 32 , TFS ( & tfs_printer_attributes_shared ) , PRINTER_ATTRIBUTE_SHARED , NULL , HFILL }
 }
 , {
 & hf_printer_attributes_network , {
 "Network" , "spoolss.printer_attributes.network" , FT_BOOLEAN , 32 , TFS ( & tfs_printer_attributes_network ) , PRINTER_ATTRIBUTE_NETWORK , NULL , HFILL }
 }
 , {
 & hf_printer_attributes_hidden , {
 "Hidden" , "spoolss.printer_attributes.hidden" , FT_BOOLEAN , 32 , TFS ( & tfs_printer_attributes_hidden ) , PRINTER_ATTRIBUTE_HIDDEN , NULL , HFILL }
 }
 , {
 & hf_printer_attributes_local , {
 "Local" , "spoolss.printer_attributes.local" , FT_BOOLEAN , 32 , TFS ( & tfs_printer_attributes_local ) , PRINTER_ATTRIBUTE_LOCAL , NULL , HFILL }
 }
 , {
 & hf_printer_attributes_enable_devq , {
 "Enable devq" , "spoolss.printer_attributes.enable_devq" , FT_BOOLEAN , 32 , TFS ( & tfs_printer_attributes_enable_devq ) , PRINTER_ATTRIBUTE_ENABLE_DEVQ , "Enable evq" , HFILL }
 }
 , {
 & hf_printer_attributes_keep_printed_jobs , {
 "Keep printed jobs" , "spoolss.printer_attributes.keep_printed_jobs" , FT_BOOLEAN , 32 , TFS ( & tfs_printer_attributes_keep_printed_jobs ) , PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS , NULL , HFILL }
 }
 , {
 & hf_printer_attributes_do_complete_first , {
 "Do complete first" , "spoolss.printer_attributes.do_complete_first" , FT_BOOLEAN , 32 , TFS ( & tfs_printer_attributes_do_complete_first ) , PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST , NULL , HFILL }
 }
 , {
 & hf_printer_attributes_work_offline , {
 "Work offline (9x/ME only)" , "spoolss.printer_attributes.work_offline" , FT_BOOLEAN , 32 , TFS ( & tfs_printer_attributes_work_offline ) , PRINTER_ATTRIBUTE_WORK_OFFLINE , "Work offline" , HFILL }
 }
 , {
 & hf_printer_attributes_enable_bidi , {
 "Enable bidi (9x/ME only)" , "spoolss.printer_attributes.enable_bidi" , FT_BOOLEAN , 32 , TFS ( & tfs_printer_attributes_enable_bidi ) , PRINTER_ATTRIBUTE_ENABLE_BIDI , "Enable bidi" , HFILL }
 }
 , {
 & hf_printer_attributes_raw_only , {
 "Raw only" , "spoolss.printer_attributes.raw_only" , FT_BOOLEAN , 32 , TFS ( & tfs_printer_attributes_raw_only ) , PRINTER_ATTRIBUTE_RAW_ONLY , NULL , HFILL }
 }
 , {
 & hf_printer_attributes_published , {
 "Published" , "spoolss.printer_attributes.published" , FT_BOOLEAN , 32 , TFS ( & tfs_printer_attributes_published ) , PRINTER_ATTRIBUTE_PUBLISHED , NULL , HFILL }
 }
 , {
 & hf_time_year , {
 "Year" , "spoolss.time.year" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_time_month , {
 "Month" , "spoolss.time.month" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_time_dow , {
 "Day of week" , "spoolss.time.dow" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_time_day , {
 "Day" , "spoolss.time.day" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_time_hour , {
 "Hour" , "spoolss.time.hour" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_time_minute , {
 "Minute" , "spoolss.time.minute" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_time_second , {
 "Second" , "spoolss.time.second" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_time_msec , {
 "Millisecond" , "spoolss.time.msec" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_userlevel_size , {
 "Size" , "spoolss.userlevel.size" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_userlevel_client , {
 "Client" , "spoolss.userlevel.client" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_userlevel_user , {
 "User" , "spoolss.userlevel.user" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_userlevel_build , {
 "Build" , "spoolss.userlevel.build" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_userlevel_major , {
 "Major" , "spoolss.userlevel.major" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_userlevel_minor , {
 "Minor" , "spoolss.userlevel.minor" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_userlevel_processor , {
 "Processor" , "spoolss.userlevel.processor" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_enumprinterdataex_name_offset , {
 "Name offset" , "spoolss.enumprinterdataex.name_offset" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_enumprinterdataex_name_len , {
 "Name len" , "spoolss.enumprinterdataex.name_len" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_enumprinterdataex_name , {
 "Name" , "spoolss.enumprinterdataex.name" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_enumprinterdataex_val_offset , {
 "Value offset" , "spoolss.enumprinterdataex.value_offset" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_enumprinterdataex_val_len , {
 "Value len" , "spoolss.enumprinterdataex.value_len" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_enumprinterdataex_val_dword_high , {
 "DWORD value (high)" , "spoolss.enumprinterdataex.val_dword.high" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_enumprinterdataex_value_null , {
 "Value" , "spoolss.enumprinterdataex.val_null" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_enumprinterdataex_value_uint , {
 "Value" , "spoolss.enumprinterdataex.val_uint" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_enumprinterdataex_value_binary , {
 "Value" , "spoolss.enumprinterdataex.val_binary" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_enumprinterdataex_value_multi_sz , {
 "Value" , "spoolss.enumprinterdataex.val_multi_sz" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_enumprinterdataex_val_dword_low , {
 "DWORD value (low)" , "spoolss.enumprinterdataex.val_dword.low" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_routerreplyprinter_condition , {
 "Condition" , "spoolss.routerreplyprinter.condition" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_routerreplyprinter_unknown1 , {
 "Unknown1" , "spoolss.routerreplyprinter.unknown1" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_routerreplyprinter_changeid , {
 "Change id" , "spoolss.routerreplyprinter.changeid" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_keybuffer_size , {
 "Key Buffer size" , "spoolss.keybuffer.size" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Size of buffer" , HFILL }
 }
 , {
 & hf_setjob_cmd , {
 "Set job command" , "spoolss.setjob.cmd" , FT_UINT32 , BASE_DEC , VALS ( setjob_commands ) , 0x0 , "Printer data name" , HFILL }
 }
 , {
 & hf_enumjobs_firstjob , {
 "First job" , "spoolss.enumjobs.firstjob" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Index of first job to return" , HFILL }
 }
 , {
 & hf_enumjobs_numjobs , {
 "Num jobs" , "spoolss.enumjobs.numjobs" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Number of jobs to return" , HFILL }
 }
 , {
 & hf_secdescbuf_maxlen , {
 "Max len" , "spoolss.secdescbuf.max_len" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_secdescbuf_undoc , {
 "Undocumented" , "spoolss.secdescbuf.undoc" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_secdescbuf_len , {
 "Length" , "spoolss.secdescbuf.len" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_spool_printer_info_devmode_ptr , {
 "Devmode pointer" , "spoolss.spoolprinterinfo.devmode_ptr" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_spool_printer_info_secdesc_ptr , {
 "Secdesc pointer" , "spoolss.spoolprinterinfo.secdesc_ptr" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_writeprinter_numwritten , {
 "Num written" , "spoolss.writeprinter.numwritten" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "Number of bytes written" , HFILL }
 }
 , {
 & hf_setprinterdataex_max_len , {
 "Max len" , "spoolss.setprinterdataex.max_len" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_setprinterdataex_real_len , {
 "Real len" , "spoolss.setprinterdataex.real_len" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_setprinterdataex_data , {
 "Data" , "spoolss.setprinterdataex.data" , FT_BYTES , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_access_required , {
 "Access required" , "spoolss.access_required" , FT_UINT32 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_server_access_admin , {
 "Server admin" , "spoolss.access_mask.server_admin" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , SERVER_ACCESS_ADMINISTER , NULL , HFILL }
 }
 , {
 & hf_server_access_enum , {
 "Server enum" , "spoolss.access_mask.server_enum" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , SERVER_ACCESS_ENUMERATE , NULL , HFILL }
 }
 , {
 & hf_printer_access_admin , {
 "Printer admin" , "spoolss.access_mask.printer_admin" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , PRINTER_ACCESS_ADMINISTER , NULL , HFILL }
 }
 , {
 & hf_printer_access_use , {
 "Printer use" , "spoolss.access_mask.printer_use" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , PRINTER_ACCESS_USE , NULL , HFILL }
 }
 , {
 & hf_job_access_admin , {
 "Job admin" , "spoolss.access_mask.job_admin" , FT_BOOLEAN , 32 , TFS ( & tfs_set_notset ) , JOB_ACCESS_ADMINISTER , NULL , HFILL }
 }
 , {
 & hf_printer_cjobs , {
 "CJobs" , "spoolss.printer.cjobs" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_total_jobs , {
 "Total jobs" , "spoolss.printer.total_jobs" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_total_bytes , {
 "Total bytes" , "spoolss.printer.total_bytes" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_global_counter , {
 "Global counter" , "spoolss.printer.global_counter" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_total_pages , {
 "Total pages" , "spoolss.printer.total_pages" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_major_version , {
 "Major version" , "spoolss.printer.major_version" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_build_version , {
 "Build version" , "spoolss.printer.build_version" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk7 , {
 "Unknown 7" , "spoolss.printer.unknown7" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk8 , {
 "Unknown 8" , "spoolss.printer.unknown8" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk9 , {
 "Unknown 9" , "spoolss.printer.unknown9" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_session_ctr , {
 "Session counter" , "spoolss.printer.session_ctr" , FT_UINT32 , BASE_DEC , NULL , 0 , "Sessopm counter" , HFILL }
 }
 , {
 & hf_printer_unk11 , {
 "Unknown 11" , "spoolss.printer.unknown11" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_printer_errors , {
 "Printer errors" , "spoolss.printer.printer_errors" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk13 , {
 "Unknown 13" , "spoolss.printer.unknown13" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk14 , {
 "Unknown 14" , "spoolss.printer.unknown14" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk15 , {
 "Unknown 15" , "spoolss.printer.unknown15" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk16 , {
 "Unknown 16" , "spoolss.printer.unknown16" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_changeid , {
 "Change id" , "spoolss.printer.changeid" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk18 , {
 "Unknown 18" , "spoolss.printer.unknown18" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk20 , {
 "Unknown 20" , "spoolss.printer.unknown20" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_c_setprinter , {
 "Csetprinter" , "spoolss.printer.c_setprinter" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk22 , {
 "Unknown 22" , "spoolss.printer.unknown22" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk23 , {
 "Unknown 23" , "spoolss.printer.unknown23" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk24 , {
 "Unknown 24" , "spoolss.printer.unknown24" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk25 , {
 "Unknown 25" , "spoolss.printer.unknown25" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk26 , {
 "Unknown 26" , "spoolss.printer.unknown26" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk27 , {
 "Unknown 27" , "spoolss.printer.unknown27" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk28 , {
 "Unknown 28" , "spoolss.printer.unknown28" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_unk29 , {
 "Unknown 29" , "spoolss.printer.unknown29" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_flags , {
 "Flags" , "spoolss.printer.flags" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_priority , {
 "Priority" , "spoolss.printer.priority" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_default_priority , {
 "Default Priority" , "spoolss.printer.default_priority" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_averageppm , {
 "Average PPM" , "spoolss.printer.averageppm" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_jobs , {
 "Jobs" , "spoolss.printer.jobs" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_guid , {
 "GUID" , "spoolss.printer.guid" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_printer_action , {
 "Action" , "spoolss.printer.action" , FT_UINT32 , BASE_DEC , VALS ( getprinter_action_vals ) , 0 , NULL , HFILL }
 }
 , }
 ;
 static gint * ett [ ] = {
 & ett_dcerpc_spoolss , & ett_PRINTER_DATATYPE , & ett_DEVMODE_CTR , & ett_DEVMODE , & ett_DEVMODE_fields , & ett_USER_LEVEL_CTR , & ett_USER_LEVEL_1 , & ett_BUFFER , & ett_PRINTER_INFO , & ett_SPOOL_PRINTER_INFO_LEVEL , & ett_PRINTER_INFO_0 , & ett_PRINTER_INFO_1 , & ett_PRINTER_INFO_2 , & ett_PRINTER_INFO_3 , & ett_PRINTER_INFO_7 , & ett_RELSTR , & ett_RELSTR_ARRAY , & ett_FORM_REL , & ett_FORM_CTR , & ett_FORM_1 , & ett_JOB_INFO_1 , & ett_JOB_INFO_2 , & ett_SEC_DESC_BUF , & ett_SYSTEM_TIME , & ett_DOC_INFO_1 , & ett_DOC_INFO , & ett_DOC_INFO_CTR , & ett_printerdata_value , & ett_printerdata_data , & ett_writeprinter_buffer , & ett_DRIVER_INFO_1 , & ett_DRIVER_INFO_2 , & ett_DRIVER_INFO_3 , & ett_DRIVER_INFO_6 , & ett_DRIVER_INFO_101 , & ett_rffpcnex_flags , & ett_notify_options_flags , & ett_NOTIFY_INFO_DATA , & ett_NOTIFY_OPTION , & ett_printer_attributes , & ett_job_status , & ett_enumprinters_flags , & ett_PRINTER_DATA_CTR , & ett_printer_enumdataex_value , }
 ;
 static ei_register_info ei [ ] = {
 {
 & ei_unimplemented_dissector , {
 "spoolss.unimplemented_dissector" , PI_UNDECODED , PI_WARN , "Unimplemented dissector: SPOOLSS" , EXPFILL }
 }
 , {
 & ei_unknown_data , {
 "spoolss.unknown_data" , PI_UNDECODED , PI_WARN , "Unknown data follows" , EXPFILL }
 }
 , {
 & ei_printer_info_level , {
 "spoolss.printer.unknown" , PI_PROTOCOL , PI_WARN , "Unknown printer info level" , EXPFILL }
 }
 , {
 & ei_spool_printer_info_level , {
 "spoolss.spool_printer.unknown" , PI_PROTOCOL , PI_WARN , "Unknown spool printer info level" , EXPFILL }
 }
 , {
 & ei_form_level , {
 "spoolss.form.level.unknown" , PI_PROTOCOL , PI_WARN , "Unknown form info level" , EXPFILL }
 }
 , {
 & ei_job_info_level , {
 "spoolss.job_info.level.unknown" , PI_PROTOCOL , PI_WARN , "Unknown job info level" , EXPFILL }
 }
 , {
 & ei_driver_info_level , {
 "spoolss.driver_info.level.unknown" , PI_PROTOCOL , PI_WARN , "Unknown driver info level" , EXPFILL }
 }
 , {
 & ei_level , {
 "spoolss.level.unknown" , PI_PROTOCOL , PI_WARN , "Info level unknown" , EXPFILL }
 }
 , {
 & ei_notify_info_data_type , {
 "spoolss.notify_info_data.type.unknown" , PI_PROTOCOL , PI_WARN , "Unknown notify type" , EXPFILL }
 }
 , {
 & ei_enumprinterdataex_value , {
 "spoolss.enumprinterdataex.val_unknown" , PI_PROTOCOL , PI_WARN , "Unknown value type" , EXPFILL }
 }
 , }
 ;
 expert_module_t * expert_dcerpc_spoolss ;
 proto_dcerpc_spoolss = proto_register_protocol ( "Microsoft Spool Subsystem" , "SPOOLSS" , "spoolss" ) ;
 proto_register_field_array ( proto_dcerpc_spoolss , hf , array_length ( hf ) ) ;
 proto_register_subtree_array ( ett , array_length ( ett ) ) ;
 expert_dcerpc_spoolss = expert_register_protocol ( proto_dcerpc_spoolss ) ;
 expert_register_field_array ( expert_dcerpc_spoolss , ei , array_length ( ei ) ) ;
 }