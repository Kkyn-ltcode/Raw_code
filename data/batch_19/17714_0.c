void adjust_frame_rate ( VP9_COMP * cpi , const struct lookahead_entry * source ) {
 int64_t this_duration ;
 int step = 0 ;
 if ( source -> ts_start == cpi -> first_time_stamp_ever ) {
 this_duration = source -> ts_end - source -> ts_start ;
 step = 1 ;
 }
 else {
 int64_t last_duration = cpi -> last_end_time_stamp_seen - cpi -> last_time_stamp_seen ;
 this_duration = source -> ts_end - cpi -> last_end_time_stamp_seen ;
 if ( last_duration ) step = ( int ) ( ( this_duration - last_duration ) * 10 / last_duration ) ;
 }
 if ( this_duration ) {
 if ( step ) {
 vp9_new_framerate ( cpi , 10000000.0 / this_duration ) ;
 }
 else {
 const double interval = MIN ( ( double ) ( source -> ts_end - cpi -> first_time_stamp_ever ) , 10000000.0 ) ;
 double avg_duration = 10000000.0 / cpi -> framerate ;
 avg_duration *= ( interval - avg_duration + this_duration ) ;
 avg_duration /= interval ;
 vp9_new_framerate ( cpi , 10000000.0 / avg_duration ) ;
 }
 }
 cpi -> last_time_stamp_seen = source -> ts_start ;
 cpi -> last_end_time_stamp_seen = source -> ts_end ;
 }