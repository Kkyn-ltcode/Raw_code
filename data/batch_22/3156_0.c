static int pcm_bluray_parse_header ( AVCodecContext * avctx , const uint8_t * header ) {
 static const uint8_t bits_per_samples [ 4 ] = {
 0 , 16 , 20 , 24 }
 ;
 static const uint32_t channel_layouts [ 16 ] = {
 0 , AV_CH_LAYOUT_MONO , 0 , AV_CH_LAYOUT_STEREO , AV_CH_LAYOUT_SURROUND , AV_CH_LAYOUT_2_1 , AV_CH_LAYOUT_4POINT0 , AV_CH_LAYOUT_2_2 , AV_CH_LAYOUT_5POINT0 , AV_CH_LAYOUT_5POINT1 , AV_CH_LAYOUT_7POINT0 , AV_CH_LAYOUT_7POINT1 , 0 , 0 , 0 , 0 }
 ;
 static const uint8_t channels [ 16 ] = {
 0 , 1 , 0 , 2 , 3 , 3 , 4 , 4 , 5 , 6 , 7 , 8 , 0 , 0 , 0 , 0 }
 ;
 uint8_t channel_layout = header [ 2 ] >> 4 ;
 if ( avctx -> debug & FF_DEBUG_PICT_INFO ) av_dlog ( avctx , "pcm_bluray_parse_header: header = %02x%02x%02x%02x\n" , header [ 0 ] , header [ 1 ] , header [ 2 ] , header [ 3 ] ) ;
 avctx -> bits_per_coded_sample = bits_per_samples [ header [ 3 ] >> 6 ] ;
 if ( ! avctx -> bits_per_coded_sample ) {
 av_log ( avctx , AV_LOG_ERROR , "reserved sample depth (0)\n" ) ;
 return - 1 ;
 }
 avctx -> sample_fmt = avctx -> bits_per_coded_sample == 16 ? AV_SAMPLE_FMT_S16 : AV_SAMPLE_FMT_S32 ;
 avctx -> bits_per_raw_sample = avctx -> bits_per_coded_sample ;
 switch ( header [ 2 ] & 0x0f ) {
 case 1 : avctx -> sample_rate = 48000 ;
 break ;
 case 4 : avctx -> sample_rate = 96000 ;
 break ;
 case 5 : avctx -> sample_rate = 192000 ;
 break ;
 default : avctx -> sample_rate = 0 ;
 av_log ( avctx , AV_LOG_ERROR , "reserved sample rate (%d)\n" , header [ 2 ] & 0x0f ) ;
 return - 1 ;
 }
 avctx -> channel_layout = channel_layouts [ channel_layout ] ;
 avctx -> channels = channels [ channel_layout ] ;
 if ( ! avctx -> channels ) {
 av_log ( avctx , AV_LOG_ERROR , "reserved channel configuration (%d)\n" , channel_layout ) ;
 return - 1 ;
 }
 avctx -> bit_rate = FFALIGN ( avctx -> channels , 2 ) * avctx -> sample_rate * avctx -> bits_per_coded_sample ;
 if ( avctx -> debug & FF_DEBUG_PICT_INFO ) av_dlog ( avctx , "pcm_bluray_parse_header: %d channels, %d bits per sample, %d Hz, %d bit/s\n" , avctx -> channels , avctx -> bits_per_coded_sample , avctx -> sample_rate , avctx -> bit_rate ) ;
 return 0 ;
 }