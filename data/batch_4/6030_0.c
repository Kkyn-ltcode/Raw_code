static void encode_source_params ( VC2EncContext * s ) {
 encode_frame_size ( s ) ;
 encode_sample_fmt ( s ) ;
 encode_scan_format ( s ) ;
 encode_frame_rate ( s ) ;
 encode_aspect_ratio ( s ) ;
 encode_clean_area ( s ) ;
 encode_signal_range ( s ) ;
 encode_color_spec ( s ) ;
 }