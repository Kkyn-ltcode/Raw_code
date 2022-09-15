static void gst_asf_demux_add_stream_headers_to_caps ( GstASFDemux * demux , GstBuffer * buffer , GstStructure * structure ) {
 GValue arr_val = G_VALUE_INIT ;
 GValue buf_val = G_VALUE_INIT ;
 g_value_init ( & arr_val , GST_TYPE_ARRAY ) ;
 g_value_init ( & buf_val , GST_TYPE_BUFFER ) ;
 gst_value_set_buffer ( & buf_val , buffer ) ;
 gst_value_array_append_and_take_value ( & arr_val , & buf_val ) ;
 gst_structure_take_value ( structure , "streamheader" , & arr_val ) ;
 }