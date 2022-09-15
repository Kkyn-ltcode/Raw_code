static void setup_pass ( struct stream_state * stream , struct VpxEncoderConfig * global , int pass ) {
 if ( stream -> config . stats_fn ) {
 if ( ! stats_open_file ( & stream -> stats , stream -> config . stats_fn , pass ) ) fatal ( "Failed to open statistics store" ) ;
 }
 else {
 if ( ! stats_open_mem ( & stream -> stats , pass ) ) fatal ( "Failed to open statistics store" ) ;
 }
 # if CONFIG_FP_MB_STATS if ( stream -> config . fpmb_stats_fn ) {
 if ( ! stats_open_file ( & stream -> fpmb_stats , stream -> config . fpmb_stats_fn , pass ) ) fatal ( "Failed to open mb statistics store" ) ;
 }
 else {
 if ( ! stats_open_mem ( & stream -> fpmb_stats , pass ) ) fatal ( "Failed to open mb statistics store" ) ;
 }
 # endif stream -> config . cfg . g_pass = global -> passes == 2 ? pass ? VPX_RC_LAST_PASS : VPX_RC_FIRST_PASS : VPX_RC_ONE_PASS ;
 if ( pass ) {
 stream -> config . cfg . rc_twopass_stats_in = stats_get ( & stream -> stats ) ;
 # if CONFIG_FP_MB_STATS stream -> config . cfg . rc_firstpass_mb_stats_in = stats_get ( & stream -> fpmb_stats ) ;
 # endif }
 stream -> cx_time = 0 ;
 stream -> nbytes = 0 ;
 stream -> frames_out = 0 ;
 }