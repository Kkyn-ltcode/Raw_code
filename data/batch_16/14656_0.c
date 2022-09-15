static int show_stream ( WriterContext * w , AVFormatContext * fmt_ctx , int stream_idx , InputStream * ist , int in_program ) {
 AVStream * stream = ist -> st ;
 AVCodecParameters * par ;
 AVCodecContext * dec_ctx ;
 char val_str [ 128 ] ;
 const char * s ;
 AVRational sar , dar ;
 AVBPrint pbuf ;
 const AVCodecDescriptor * cd ;
 int ret = 0 ;
 const char * profile = NULL ;
 av_bprint_init ( & pbuf , 1 , AV_BPRINT_SIZE_UNLIMITED ) ;
 writer_print_section_header ( w , in_program ? SECTION_ID_PROGRAM_STREAM : SECTION_ID_STREAM ) ;
 print_int ( "index" , stream -> index ) ;
 par = stream -> codecpar ;
 dec_ctx = ist -> dec_ctx ;
 if ( cd = avcodec_descriptor_get ( par -> codec_id ) ) {
 print_str ( "codec_name" , cd -> name ) ;
 if ( ! do_bitexact ) {
 print_str ( "codec_long_name" , cd -> long_name ? cd -> long_name : "unknown" ) ;
 }
 }
 else {
 print_str_opt ( "codec_name" , "unknown" ) ;
 if ( ! do_bitexact ) {
 print_str_opt ( "codec_long_name" , "unknown" ) ;
 }
 }
 if ( ! do_bitexact && ( profile = avcodec_profile_name ( par -> codec_id , par -> profile ) ) ) print_str ( "profile" , profile ) ;
 else {
 if ( par -> profile != FF_PROFILE_UNKNOWN ) {
 char profile_num [ 12 ] ;
 snprintf ( profile_num , sizeof ( profile_num ) , "%d" , par -> profile ) ;
 print_str ( "profile" , profile_num ) ;
 }
 else print_str_opt ( "profile" , "unknown" ) ;
 }
 s = av_get_media_type_string ( par -> codec_type ) ;
 if ( s ) print_str ( "codec_type" , s ) ;
 else print_str_opt ( "codec_type" , "unknown" ) ;
 # if FF_API_LAVF_AVCTX if ( dec_ctx ) print_q ( "codec_time_base" , dec_ctx -> time_base , '/' ) ;
 # endif print_str ( "codec_tag_string" , av_fourcc2str ( par -> codec_tag ) ) ;
 print_fmt ( "codec_tag" , "0x%04" PRIx32 , par -> codec_tag ) ;
 switch ( par -> codec_type ) {
 case AVMEDIA_TYPE_VIDEO : print_int ( "width" , par -> width ) ;
 print_int ( "height" , par -> height ) ;
 if ( dec_ctx ) {
 print_int ( "coded_width" , dec_ctx -> coded_width ) ;
 print_int ( "coded_height" , dec_ctx -> coded_height ) ;
 }
 print_int ( "has_b_frames" , par -> video_delay ) ;
 sar = av_guess_sample_aspect_ratio ( fmt_ctx , stream , NULL ) ;
 if ( sar . den ) {
 print_q ( "sample_aspect_ratio" , sar , ':' ) ;
 av_reduce ( & dar . num , & dar . den , par -> width * sar . num , par -> height * sar . den , 1024 * 1024 ) ;
 print_q ( "display_aspect_ratio" , dar , ':' ) ;
 }
 else {
 print_str_opt ( "sample_aspect_ratio" , "N/A" ) ;
 print_str_opt ( "display_aspect_ratio" , "N/A" ) ;
 }
 s = av_get_pix_fmt_name ( par -> format ) ;
 if ( s ) print_str ( "pix_fmt" , s ) ;
 else print_str_opt ( "pix_fmt" , "unknown" ) ;
 print_int ( "level" , par -> level ) ;
 if ( par -> color_range != AVCOL_RANGE_UNSPECIFIED ) print_str ( "color_range" , av_color_range_name ( par -> color_range ) ) ;
 else print_str_opt ( "color_range" , "N/A" ) ;
 if ( par -> color_space != AVCOL_SPC_UNSPECIFIED ) print_str ( "color_space" , av_color_space_name ( par -> color_space ) ) ;
 else print_str_opt ( "color_space" , av_color_space_name ( par -> color_space ) ) ;
 if ( par -> color_trc != AVCOL_TRC_UNSPECIFIED ) print_str ( "color_transfer" , av_color_transfer_name ( par -> color_trc ) ) ;
 else print_str_opt ( "color_transfer" , av_color_transfer_name ( par -> color_trc ) ) ;
 print_primaries ( w , par -> color_primaries ) ;
 if ( par -> chroma_location != AVCHROMA_LOC_UNSPECIFIED ) print_str ( "chroma_location" , av_chroma_location_name ( par -> chroma_location ) ) ;
 else print_str_opt ( "chroma_location" , av_chroma_location_name ( par -> chroma_location ) ) ;
 if ( par -> field_order == AV_FIELD_PROGRESSIVE ) print_str ( "field_order" , "progressive" ) ;
 else if ( par -> field_order == AV_FIELD_TT ) print_str ( "field_order" , "tt" ) ;
 else if ( par -> field_order == AV_FIELD_BB ) print_str ( "field_order" , "bb" ) ;
 else if ( par -> field_order == AV_FIELD_TB ) print_str ( "field_order" , "tb" ) ;
 else if ( par -> field_order == AV_FIELD_BT ) print_str ( "field_order" , "bt" ) ;
 else print_str_opt ( "field_order" , "unknown" ) ;
 # if FF_API_PRIVATE_OPT if ( dec_ctx && dec_ctx -> timecode_frame_start >= 0 ) {
 char tcbuf [ AV_TIMECODE_STR_SIZE ] ;
 av_timecode_make_mpeg_tc_string ( tcbuf , dec_ctx -> timecode_frame_start ) ;
 print_str ( "timecode" , tcbuf ) ;
 }
 else {
 print_str_opt ( "timecode" , "N/A" ) ;
 }
 # endif if ( dec_ctx ) print_int ( "refs" , dec_ctx -> refs ) ;
 break ;
 case AVMEDIA_TYPE_AUDIO : s = av_get_sample_fmt_name ( par -> format ) ;
 if ( s ) print_str ( "sample_fmt" , s ) ;
 else print_str_opt ( "sample_fmt" , "unknown" ) ;
 print_val ( "sample_rate" , par -> sample_rate , unit_hertz_str ) ;
 print_int ( "channels" , par -> channels ) ;
 if ( par -> channel_layout ) {
 av_bprint_clear ( & pbuf ) ;
 av_bprint_channel_layout ( & pbuf , par -> channels , par -> channel_layout ) ;
 print_str ( "channel_layout" , pbuf . str ) ;
 }
 else {
 print_str_opt ( "channel_layout" , "unknown" ) ;
 }
 print_int ( "bits_per_sample" , av_get_bits_per_sample ( par -> codec_id ) ) ;
 break ;
 case AVMEDIA_TYPE_SUBTITLE : if ( par -> width ) print_int ( "width" , par -> width ) ;
 else print_str_opt ( "width" , "N/A" ) ;
 if ( par -> height ) print_int ( "height" , par -> height ) ;
 else print_str_opt ( "height" , "N/A" ) ;
 break ;
 }
 if ( dec_ctx && dec_ctx -> codec && dec_ctx -> codec -> priv_class && show_private_data ) {
 const AVOption * opt = NULL ;
 while ( opt = av_opt_next ( dec_ctx -> priv_data , opt ) ) {
 uint8_t * str ;
 if ( opt -> flags ) continue ;
 if ( av_opt_get ( dec_ctx -> priv_data , opt -> name , 0 , & str ) >= 0 ) {
 print_str ( opt -> name , str ) ;
 av_free ( str ) ;
 }
 }
 }
 if ( fmt_ctx -> iformat -> flags & AVFMT_SHOW_IDS ) print_fmt ( "id" , "0x%x" , stream -> id ) ;
 else print_str_opt ( "id" , "N/A" ) ;
 print_q ( "r_frame_rate" , stream -> r_frame_rate , '/' ) ;
 print_q ( "avg_frame_rate" , stream -> avg_frame_rate , '/' ) ;
 print_q ( "time_base" , stream -> time_base , '/' ) ;
 print_ts ( "start_pts" , stream -> start_time ) ;
 print_time ( "start_time" , stream -> start_time , & stream -> time_base ) ;
 print_ts ( "duration_ts" , stream -> duration ) ;
 print_time ( "duration" , stream -> duration , & stream -> time_base ) ;
 if ( par -> bit_rate > 0 ) print_val ( "bit_rate" , par -> bit_rate , unit_bit_per_second_str ) ;
 else print_str_opt ( "bit_rate" , "N/A" ) ;
 # if FF_API_LAVF_AVCTX if ( stream -> codec -> rc_max_rate > 0 ) print_val ( "max_bit_rate" , stream -> codec -> rc_max_rate , unit_bit_per_second_str ) ;
 else print_str_opt ( "max_bit_rate" , "N/A" ) ;
 # endif if ( dec_ctx && dec_ctx -> bits_per_raw_sample > 0 ) print_fmt ( "bits_per_raw_sample" , "%d" , dec_ctx -> bits_per_raw_sample ) ;
 else print_str_opt ( "bits_per_raw_sample" , "N/A" ) ;
 if ( stream -> nb_frames ) print_fmt ( "nb_frames" , "%" PRId64 , stream -> nb_frames ) ;
 else print_str_opt ( "nb_frames" , "N/A" ) ;
 if ( nb_streams_frames [ stream_idx ] ) print_fmt ( "nb_read_frames" , "%" PRIu64 , nb_streams_frames [ stream_idx ] ) ;
 else print_str_opt ( "nb_read_frames" , "N/A" ) ;
 if ( nb_streams_packets [ stream_idx ] ) print_fmt ( "nb_read_packets" , "%" PRIu64 , nb_streams_packets [ stream_idx ] ) ;
 else print_str_opt ( "nb_read_packets" , "N/A" ) ;
 if ( do_show_data ) writer_print_data ( w , "extradata" , par -> extradata , par -> extradata_size ) ;
 writer_print_data_hash ( w , "extradata_hash" , par -> extradata , par -> extradata_size ) ;
 # define PRINT_DISPOSITION ( flagname , name ) do {
 print_int ( name , ! ! ( stream -> disposition & AV_DISPOSITION_ ## flagname ) ) ;
 }
 while ( 0 ) if ( do_show_stream_disposition ) {
 writer_print_section_header ( w , in_program ? SECTION_ID_PROGRAM_STREAM_DISPOSITION : SECTION_ID_STREAM_DISPOSITION ) ;
 PRINT_DISPOSITION ( DEFAULT , "default" ) ;
 PRINT_DISPOSITION ( DUB , "dub" ) ;
 PRINT_DISPOSITION ( ORIGINAL , "original" ) ;
 PRINT_DISPOSITION ( COMMENT , "comment" ) ;
 PRINT_DISPOSITION ( LYRICS , "lyrics" ) ;
 PRINT_DISPOSITION ( KARAOKE , "karaoke" ) ;
 PRINT_DISPOSITION ( FORCED , "forced" ) ;
 PRINT_DISPOSITION ( HEARING_IMPAIRED , "hearing_impaired" ) ;
 PRINT_DISPOSITION ( VISUAL_IMPAIRED , "visual_impaired" ) ;
 PRINT_DISPOSITION ( CLEAN_EFFECTS , "clean_effects" ) ;
 PRINT_DISPOSITION ( ATTACHED_PIC , "attached_pic" ) ;
 PRINT_DISPOSITION ( TIMED_THUMBNAILS , "timed_thumbnails" ) ;
 writer_print_section_footer ( w ) ;
 }
 if ( do_show_stream_tags ) ret = show_tags ( w , stream -> metadata , in_program ? SECTION_ID_PROGRAM_STREAM_TAGS : SECTION_ID_STREAM_TAGS ) ;
 if ( stream -> nb_side_data ) {
 print_pkt_side_data ( w , stream -> codecpar , stream -> side_data , stream -> nb_side_data , SECTION_ID_STREAM_SIDE_DATA_LIST , SECTION_ID_STREAM_SIDE_DATA ) ;
 }
 writer_print_section_footer ( w ) ;
 av_bprint_finalize ( & pbuf , NULL ) ;
 fflush ( stdout ) ;
 return ret ;
 }