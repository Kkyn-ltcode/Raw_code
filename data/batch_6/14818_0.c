static GstStructure * gst_asf_demux_get_metadata_for_stream ( GstASFDemux * demux , guint stream_num ) {
 gchar sname [ 32 ] ;
 guint i ;
 g_snprintf ( sname , sizeof ( sname ) , "stream-%u" , stream_num ) ;
 for ( i = 0 ;
 i < gst_caps_get_size ( demux -> metadata ) ;
 ++ i ) {
 GstStructure * s ;
 s = gst_caps_get_structure ( demux -> metadata , i ) ;
 if ( gst_structure_has_name ( s , sname ) ) return s ;
 }
 gst_caps_append_structure ( demux -> metadata , gst_structure_new_empty ( sname ) ) ;
 return gst_asf_demux_get_metadata_for_stream ( demux , stream_num ) ;
 }