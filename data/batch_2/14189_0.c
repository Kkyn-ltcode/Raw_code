void proto_reg_handoff_usb_vid ( void ) {
 dissector_handle_t usb_vid_control_handle ;
 dissector_handle_t usb_vid_descriptor_handle ;
 dissector_handle_t usb_vid_interrupt_handle ;
 usb_vid_control_handle = create_dissector_handle ( dissect_usb_vid_control , proto_usb_vid ) ;
 dissector_add_uint ( "usb.control" , IF_CLASS_VIDEO , usb_vid_control_handle ) ;
 usb_vid_descriptor_handle = create_dissector_handle ( dissect_usb_vid_descriptor , proto_usb_vid ) ;
 dissector_add_uint ( "usb.descriptor" , IF_CLASS_VIDEO , usb_vid_descriptor_handle ) ;
 usb_vid_interrupt_handle = create_dissector_handle ( dissect_usb_vid_interrupt , proto_usb_vid ) ;
 dissector_add_uint ( "usb.interrupt" , IF_CLASS_VIDEO , usb_vid_interrupt_handle ) ;
 }