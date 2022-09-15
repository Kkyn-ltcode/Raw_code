static gboolean all_streams_prerolled ( GstASFDemux * demux ) {
 GstClockTime preroll_time ;
 guint i , num_no_data = 0 ;
 preroll_time = MAX ( demux -> preroll , 500 * GST_MSECOND ) ;
 for ( i = 0 ;
 i < demux -> num_streams ;
 ++ i ) {
 AsfPayload * last_payload = NULL ;
 AsfStream * stream ;
 gint last_idx ;
 stream = & demux -> stream [ i ] ;
 if ( G_UNLIKELY ( stream -> payloads -> len == 0 ) ) {
 ++ num_no_data ;
 GST_LOG_OBJECT ( stream -> pad , "no data queued" ) ;
 continue ;
 }
 for ( last_idx = stream -> payloads -> len - 1 ;
 last_idx >= 0 && ( last_payload == NULL || ! GST_CLOCK_TIME_IS_VALID ( last_payload -> ts ) ) ;
 -- last_idx ) {
 last_payload = & g_array_index ( stream -> payloads , AsfPayload , last_idx ) ;
 }
 GST_LOG_OBJECT ( stream -> pad , "checking if %" GST_TIME_FORMAT " > %" GST_TIME_FORMAT , GST_TIME_ARGS ( last_payload -> ts ) , GST_TIME_ARGS ( preroll_time ) ) ;
 if ( G_UNLIKELY ( ! GST_CLOCK_TIME_IS_VALID ( last_payload -> ts ) || last_payload -> ts <= preroll_time ) ) {
 GST_LOG_OBJECT ( stream -> pad , "not beyond preroll point yet" ) ;
 return FALSE ;
 }
 }
 if ( G_UNLIKELY ( num_no_data > 0 ) ) return FALSE ;
 return TRUE ;
 }