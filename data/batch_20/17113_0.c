static int decide_key_frame ( VP8_COMP * cpi ) {
 VP8_COMMON * cm = & cpi -> common ;
 int code_key_frame = 0 ;
 cpi -> kf_boost = 0 ;
 if ( cpi -> Speed > 11 ) return 0 ;
 vp8_clear_system_state ( ) ;
 if ( ( cpi -> compressor_speed == 2 ) && ( cpi -> Speed >= 5 ) && ( cpi -> sf . RD == 0 ) ) {
 double change = 1.0 * abs ( ( int ) ( cpi -> mb . intra_error - cpi -> last_intra_error ) ) / ( 1 + cpi -> last_intra_error ) ;
 double change2 = 1.0 * abs ( ( int ) ( cpi -> mb . prediction_error - cpi -> last_prediction_error ) ) / ( 1 + cpi -> last_prediction_error ) ;
 double minerror = cm -> MBs * 256 ;
 cpi -> last_intra_error = cpi -> mb . intra_error ;
 cpi -> last_prediction_error = cpi -> mb . prediction_error ;
 if ( 10 * cpi -> mb . intra_error / ( 1 + cpi -> mb . prediction_error ) < 15 && cpi -> mb . prediction_error > minerror && ( change > .25 || change2 > .25 ) ) {
 return 1 ;
 }
 return 0 ;
 }
 if ( ( ( cpi -> this_frame_percent_intra == 100 ) && ( cpi -> this_frame_percent_intra > ( cpi -> last_frame_percent_intra + 2 ) ) ) || ( ( cpi -> this_frame_percent_intra > 95 ) && ( cpi -> this_frame_percent_intra >= ( cpi -> last_frame_percent_intra + 5 ) ) ) ) {
 code_key_frame = 1 ;
 }
 else if ( ( ( cpi -> this_frame_percent_intra > 60 ) && ( cpi -> this_frame_percent_intra > ( cpi -> last_frame_percent_intra * 2 ) ) ) || ( ( cpi -> this_frame_percent_intra > 75 ) && ( cpi -> this_frame_percent_intra > ( cpi -> last_frame_percent_intra * 3 / 2 ) ) ) || ( ( cpi -> this_frame_percent_intra > 90 ) && ( cpi -> this_frame_percent_intra > ( cpi -> last_frame_percent_intra + 10 ) ) ) ) {
 if ( ! cm -> refresh_golden_frame ) code_key_frame = 1 ;
 }
 return code_key_frame ;
 }