static int decode_frame ( AVCodecContext * avctx , void * data , int * got_frame , AVPacket * avpkt ) {
 AVFrame * frame = data ;
 const uint8_t * buf = avpkt -> data ;
 int buf_size = avpkt -> size ;
 ZmbvContext * const c = avctx -> priv_data ;
 int zret = Z_OK ;
 int len = buf_size ;
 int hi_ver , lo_ver , ret ;
 uint8_t * tmp ;
 if ( ( ret = ff_get_buffer ( avctx , frame , 0 ) ) < 0 ) {
 av_log ( avctx , AV_LOG_ERROR , "get_buffer() failed\n" ) ;
 return ret ;
 }
 c -> flags = buf [ 0 ] ;
 buf ++ ;
 len -- ;
 if ( c -> flags & ZMBV_KEYFRAME ) {
 hi_ver = buf [ 0 ] ;
 lo_ver = buf [ 1 ] ;
 c -> comp = buf [ 2 ] ;
 c -> fmt = buf [ 3 ] ;
 c -> bw = buf [ 4 ] ;
 c -> bh = buf [ 5 ] ;
 c -> decode_intra = NULL ;
 c -> decode_xor = NULL ;
 buf += 6 ;
 len -= 6 ;
 av_log ( avctx , AV_LOG_DEBUG , "Flags=%X ver=%i.%i comp=%i fmt=%i blk=%ix%i\n" , c -> flags , hi_ver , lo_ver , c -> comp , c -> fmt , c -> bw , c -> bh ) ;
 if ( hi_ver != 0 || lo_ver != 1 ) {
 av_log_ask_for_sample ( avctx , "Unsupported version %i.%i\n" , hi_ver , lo_ver ) ;
 return AVERROR_PATCHWELCOME ;
 }
 if ( c -> bw == 0 || c -> bh == 0 ) {
 av_log_ask_for_sample ( avctx , "Unsupported block size %ix%i\n" , c -> bw , c -> bh ) ;
 return AVERROR_PATCHWELCOME ;
 }
 if ( c -> comp != 0 && c -> comp != 1 ) {
 av_log_ask_for_sample ( avctx , "Unsupported compression type %i\n" , c -> comp ) ;
 return AVERROR_PATCHWELCOME ;
 }
 switch ( c -> fmt ) {
 case ZMBV_FMT_8BPP : c -> bpp = 8 ;
 c -> decode_intra = zmbv_decode_intra ;
 c -> decode_xor = zmbv_decode_xor_8 ;
 break ;
 case ZMBV_FMT_15BPP : case ZMBV_FMT_16BPP : c -> bpp = 16 ;
 c -> decode_intra = zmbv_decode_intra ;
 c -> decode_xor = zmbv_decode_xor_16 ;
 break ;
 # ifdef ZMBV_ENABLE_24BPP case ZMBV_FMT_24BPP : c -> bpp = 24 ;
 c -> decode_intra = zmbv_decode_intra ;
 c -> decode_xor = zmbv_decode_xor_24 ;
 break ;
 # endif case ZMBV_FMT_32BPP : c -> bpp = 32 ;
 c -> decode_intra = zmbv_decode_intra ;
 c -> decode_xor = zmbv_decode_xor_32 ;
 break ;
 default : c -> decode_intra = NULL ;
 c -> decode_xor = NULL ;
 av_log_ask_for_sample ( avctx , "Unsupported (for now) format %i\n" , c -> fmt ) ;
 return AVERROR_PATCHWELCOME ;
 }
 zret = inflateReset ( & c -> zstream ) ;
 if ( zret != Z_OK ) {
 av_log ( avctx , AV_LOG_ERROR , "Inflate reset error: %d\n" , zret ) ;
 return AVERROR_UNKNOWN ;
 }
 tmp = av_realloc ( c -> cur , avctx -> width * avctx -> height * ( c -> bpp / 8 ) ) ;
 if ( ! tmp ) return AVERROR ( ENOMEM ) ;
 c -> cur = tmp ;
 tmp = av_realloc ( c -> prev , avctx -> width * avctx -> height * ( c -> bpp / 8 ) ) ;
 if ( ! tmp ) return AVERROR ( ENOMEM ) ;
 c -> prev = tmp ;
 c -> bx = ( c -> width + c -> bw - 1 ) / c -> bw ;
 c -> by = ( c -> height + c -> bh - 1 ) / c -> bh ;
 }
 if ( c -> decode_intra == NULL ) {
 av_log ( avctx , AV_LOG_ERROR , "Error! Got no format or no keyframe!\n" ) ;
 return AVERROR_INVALIDDATA ;
 }
 if ( c -> comp == 0 ) {
 memcpy ( c -> decomp_buf , buf , len ) ;
 c -> decomp_size = 1 ;
 }
 else {
 c -> zstream . total_in = c -> zstream . total_out = 0 ;
 c -> zstream . next_in = buf ;
 c -> zstream . avail_in = len ;
 c -> zstream . next_out = c -> decomp_buf ;
 c -> zstream . avail_out = c -> decomp_size ;
 zret = inflate ( & c -> zstream , Z_SYNC_FLUSH ) ;
 if ( zret != Z_OK && zret != Z_STREAM_END ) {
 av_log ( avctx , AV_LOG_ERROR , "inflate error %d\n" , zret ) ;
 return AVERROR_INVALIDDATA ;
 }
 c -> decomp_len = c -> zstream . total_out ;
 }
 if ( c -> flags & ZMBV_KEYFRAME ) {
 frame -> key_frame = 1 ;
 frame -> pict_type = AV_PICTURE_TYPE_I ;
 c -> decode_intra ( c ) ;
 }
 else {
 frame -> key_frame = 0 ;
 frame -> pict_type = AV_PICTURE_TYPE_P ;
 if ( c -> decomp_len ) c -> decode_xor ( c ) ;
 }
 {
 uint8_t * out , * src ;
 int i , j ;
 out = frame -> data [ 0 ] ;
 src = c -> cur ;
 switch ( c -> fmt ) {
 case ZMBV_FMT_8BPP : for ( j = 0 ;
 j < c -> height ;
 j ++ ) {
 for ( i = 0 ;
 i < c -> width ;
 i ++ ) {
 out [ i * 3 + 0 ] = c -> pal [ ( * src ) * 3 + 0 ] ;
 out [ i * 3 + 1 ] = c -> pal [ ( * src ) * 3 + 1 ] ;
 out [ i * 3 + 2 ] = c -> pal [ ( * src ) * 3 + 2 ] ;
 src ++ ;
 }
 out += frame -> linesize [ 0 ] ;
 }
 break ;
 case ZMBV_FMT_15BPP : for ( j = 0 ;
 j < c -> height ;
 j ++ ) {
 for ( i = 0 ;
 i < c -> width ;
 i ++ ) {
 uint16_t tmp = AV_RL16 ( src ) ;
 src += 2 ;
 out [ i * 3 + 0 ] = ( tmp & 0x7C00 ) >> 7 ;
 out [ i * 3 + 1 ] = ( tmp & 0x03E0 ) >> 2 ;
 out [ i * 3 + 2 ] = ( tmp & 0x001F ) << 3 ;
 }
 out += frame -> linesize [ 0 ] ;
 }
 break ;
 case ZMBV_FMT_16BPP : for ( j = 0 ;
 j < c -> height ;
 j ++ ) {
 for ( i = 0 ;
 i < c -> width ;
 i ++ ) {
 uint16_t tmp = AV_RL16 ( src ) ;
 src += 2 ;
 out [ i * 3 + 0 ] = ( tmp & 0xF800 ) >> 8 ;
 out [ i * 3 + 1 ] = ( tmp & 0x07E0 ) >> 3 ;
 out [ i * 3 + 2 ] = ( tmp & 0x001F ) << 3 ;
 }
 out += frame -> linesize [ 0 ] ;
 }
 break ;
 # ifdef ZMBV_ENABLE_24BPP case ZMBV_FMT_24BPP : for ( j = 0 ;
 j < c -> height ;
 j ++ ) {
 memcpy ( out , src , c -> width * 3 ) ;
 src += c -> width * 3 ;
 out += frame -> linesize [ 0 ] ;
 }
 break ;
 # endif case ZMBV_FMT_32BPP : for ( j = 0 ;
 j < c -> height ;
 j ++ ) {
 for ( i = 0 ;
 i < c -> width ;
 i ++ ) {
 uint32_t tmp = AV_RL32 ( src ) ;
 src += 4 ;
 AV_WB24 ( out + ( i * 3 ) , tmp ) ;
 }
 out += frame -> linesize [ 0 ] ;
 }
 break ;
 default : av_log ( avctx , AV_LOG_ERROR , "Cannot handle format %i\n" , c -> fmt ) ;
 }
 FFSWAP ( uint8_t * , c -> cur , c -> prev ) ;
 }
 * got_frame = 1 ;
 return buf_size ;
 }