static void matroska_execute_seekhead ( MatroskaDemuxContext * matroska ) {
 EbmlList * seekhead_list = & matroska -> seekhead ;
 int64_t before_pos = avio_tell ( matroska -> ctx -> pb ) ;
 int i ;
 if ( ! matroska -> ctx -> pb -> seekable || ( matroska -> ctx -> flags & AVFMT_FLAG_IGNIDX ) ) return ;
 for ( i = 0 ;
 i < seekhead_list -> nb_elem ;
 i ++ ) {
 MatroskaSeekhead * seekhead = seekhead_list -> elem ;
 if ( seekhead [ i ] . pos <= before_pos ) continue ;
 if ( seekhead [ i ] . id == MATROSKA_ID_CUES ) {
 matroska -> cues_parsing_deferred = 1 ;
 continue ;
 }
 if ( matroska_parse_seekhead_entry ( matroska , i ) < 0 ) break ;
 }
 }