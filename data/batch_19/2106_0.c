static int dca_decode_block ( DCAContext * s , int base_channel , int block_index ) {
 int ret ;
 if ( s -> current_subframe >= s -> subframes ) {
 av_log ( s -> avctx , AV_LOG_DEBUG , "check failed: %i>%i" , s -> current_subframe , s -> subframes ) ;
 return AVERROR_INVALIDDATA ;
 }
 if ( ! s -> current_subsubframe ) {
 # ifdef TRACE av_log ( s -> avctx , AV_LOG_DEBUG , "DSYNC dca_subframe_header\n" ) ;
 # endif if ( ( ret = dca_subframe_header ( s , base_channel , block_index ) ) ) return ret ;
 }
 # ifdef TRACE av_log ( s -> avctx , AV_LOG_DEBUG , "DSYNC dca_subsubframe\n" ) ;
 # endif if ( ( ret = dca_subsubframe ( s , base_channel , block_index ) ) ) return ret ;
 s -> current_subsubframe ++ ;
 if ( s -> current_subsubframe >= s -> subsubframes [ s -> current_subframe ] ) {
 s -> current_subsubframe = 0 ;
 s -> current_subframe ++ ;
 }
 if ( s -> current_subframe >= s -> subframes ) {
 # ifdef TRACE av_log ( s -> avctx , AV_LOG_DEBUG , "DSYNC dca_subframe_footer\n" ) ;
 # endif if ( ( ret = dca_subframe_footer ( s , base_channel ) ) ) return ret ;
 }
 return 0 ;
 }