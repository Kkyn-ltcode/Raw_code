static int decode_frame ( FLACContext * s ) {
 int i , ret ;
 GetBitContext * gb = & s -> gb ;
 FLACFrameInfo fi ;
 if ( ff_flac_decode_frame_header ( s -> avctx , gb , & fi , 0 ) ) {
 av_log ( s -> avctx , AV_LOG_ERROR , "invalid frame header\n" ) ;
 return - 1 ;
 }
 if ( s -> channels && fi . channels != s -> channels && s -> got_streaminfo ) {
 s -> channels = s -> avctx -> channels = fi . channels ;
 ff_flac_set_channel_layout ( s -> avctx ) ;
 ret = allocate_buffers ( s ) ;
 if ( ret < 0 ) return ret ;
 }
 s -> channels = s -> avctx -> channels = fi . channels ;
 if ( ! s -> avctx -> channel_layout ) ff_flac_set_channel_layout ( s -> avctx ) ;
 s -> ch_mode = fi . ch_mode ;
 if ( ! s -> bps && ! fi . bps ) {
 av_log ( s -> avctx , AV_LOG_ERROR , "bps not found in STREAMINFO or frame header\n" ) ;
 return - 1 ;
 }
 if ( ! fi . bps ) {
 fi . bps = s -> bps ;
 }
 else if ( s -> bps && fi . bps != s -> bps ) {
 av_log ( s -> avctx , AV_LOG_ERROR , "switching bps mid-stream is not " "supported\n" ) ;
 return - 1 ;
 }
 if ( ! s -> bps ) {
 s -> bps = s -> avctx -> bits_per_raw_sample = fi . bps ;
 flac_set_bps ( s ) ;
 }
 if ( ! s -> max_blocksize ) s -> max_blocksize = FLAC_MAX_BLOCKSIZE ;
 if ( fi . blocksize > s -> max_blocksize ) {
 av_log ( s -> avctx , AV_LOG_ERROR , "blocksize %d > %d\n" , fi . blocksize , s -> max_blocksize ) ;
 return - 1 ;
 }
 s -> blocksize = fi . blocksize ;
 if ( ! s -> samplerate && ! fi . samplerate ) {
 av_log ( s -> avctx , AV_LOG_ERROR , "sample rate not found in STREAMINFO" " or frame header\n" ) ;
 return - 1 ;
 }
 if ( fi . samplerate == 0 ) fi . samplerate = s -> samplerate ;
 s -> samplerate = s -> avctx -> sample_rate = fi . samplerate ;
 if ( ! s -> got_streaminfo ) {
 ret = allocate_buffers ( s ) ;
 if ( ret < 0 ) return ret ;
 ff_flacdsp_init ( & s -> dsp , s -> avctx -> sample_fmt , s -> bps ) ;
 s -> got_streaminfo = 1 ;
 dump_headers ( s -> avctx , ( FLACStreaminfo * ) s ) ;
 }
 for ( i = 0 ;
 i < s -> channels ;
 i ++ ) {
 if ( decode_subframe ( s , i ) < 0 ) return - 1 ;
 }
 align_get_bits ( gb ) ;
 skip_bits ( gb , 16 ) ;
 return 0 ;
 }