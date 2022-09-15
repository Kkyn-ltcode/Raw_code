static int sdp_parse_fmtp_config_h264 ( AVFormatContext * s , AVStream * stream , PayloadContext * h264_data , const char * attr , const char * value ) {
 AVCodecParameters * par = stream -> codecpar ;
 if ( ! strcmp ( attr , "packetization-mode" ) ) {
 av_log ( s , AV_LOG_DEBUG , "RTP Packetization Mode: %d\n" , atoi ( value ) ) ;
 h264_data -> packetization_mode = atoi ( value ) ;
 if ( h264_data -> packetization_mode > 1 ) av_log ( s , AV_LOG_ERROR , "Interleaved RTP mode is not supported yet.\n" ) ;
 }
 else if ( ! strcmp ( attr , "profile-level-id" ) ) {
 if ( strlen ( value ) == 6 ) parse_profile_level_id ( s , h264_data , value ) ;
 }
 else if ( ! strcmp ( attr , "sprop-parameter-sets" ) ) {
 int ret ;
 if ( * value == 0 || value [ strlen ( value ) - 1 ] == ',' ) {
 av_log ( s , AV_LOG_WARNING , "Missing PPS in sprop-parameter-sets, ignoring\n" ) ;
 return 0 ;
 }
 par -> extradata_size = 0 ;
 av_freep ( & par -> extradata ) ;
 ret = ff_h264_parse_sprop_parameter_sets ( s , & par -> extradata , & par -> extradata_size , value ) ;
 av_log ( s , AV_LOG_DEBUG , "Extradata set to %p (size: %d)\n" , par -> extradata , par -> extradata_size ) ;
 return ret ;
 }
 return 0 ;
 }