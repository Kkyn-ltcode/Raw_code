static int ogg_packet ( AVFormatContext * s , int * sid , int * dstart , int * dsize , int64_t * fpos ) {
 struct ogg * ogg = s -> priv_data ;
 int idx , i , ret ;
 struct ogg_stream * os ;
 int complete = 0 ;
 int segp = 0 , psize = 0 ;
 av_log ( s , AV_LOG_TRACE , "ogg_packet: curidx=%i\n" , ogg -> curidx ) ;
 if ( sid ) * sid = - 1 ;
 do {
 idx = ogg -> curidx ;
 while ( idx < 0 ) {
 ret = ogg_read_page ( s , & idx ) ;
 if ( ret < 0 ) return ret ;
 }
 os = ogg -> streams + idx ;
 av_log ( s , AV_LOG_TRACE , "ogg_packet: idx=%d pstart=%d psize=%d segp=%d nsegs=%d\n" , idx , os -> pstart , os -> psize , os -> segp , os -> nsegs ) ;
 if ( ! os -> codec ) {
 if ( os -> header < 0 ) {
 os -> codec = ogg_find_codec ( os -> buf , os -> bufpos ) ;
 if ( ! os -> codec ) {
 av_log ( s , AV_LOG_WARNING , "Codec not found\n" ) ;
 os -> header = 0 ;
 return 0 ;
 }
 }
 else {
 return 0 ;
 }
 }
 segp = os -> segp ;
 psize = os -> psize ;
 while ( os -> segp < os -> nsegs ) {
 int ss = os -> segments [ os -> segp ++ ] ;
 os -> psize += ss ;
 if ( ss < 255 ) {
 complete = 1 ;
 break ;
 }
 }
 if ( ! complete && os -> segp == os -> nsegs ) {
 ogg -> curidx = - 1 ;
 os -> incomplete = ! ! os -> psize ;
 }
 }
 while ( ! complete ) ;
 if ( os -> granule == - 1 ) av_log ( s , AV_LOG_WARNING , "Page at %" PRId64 " is missing granule\n" , os -> page_pos ) ;
 ogg -> curidx = idx ;
 os -> incomplete = 0 ;
 if ( os -> header ) {
 os -> header = os -> codec -> header ( s , idx ) ;
 if ( ! os -> header ) {
 os -> segp = segp ;
 os -> psize = psize ;
 ogg -> headers = 1 ;
 if ( ! s -> internal -> data_offset ) s -> internal -> data_offset = os -> sync_pos ;
 for ( i = 0 ;
 i < ogg -> nstreams ;
 i ++ ) {
 struct ogg_stream * cur_os = ogg -> streams + i ;
 if ( cur_os -> incomplete ) s -> internal -> data_offset = FFMIN ( s -> internal -> data_offset , cur_os -> sync_pos ) ;
 }
 }
 else {
 os -> nb_header ++ ;
 os -> pstart += os -> psize ;
 os -> psize = 0 ;
 }
 }
 else {
 os -> pflags = 0 ;
 os -> pduration = 0 ;
 if ( os -> codec && os -> codec -> packet ) os -> codec -> packet ( s , idx ) ;
 if ( sid ) * sid = idx ;
 if ( dstart ) * dstart = os -> pstart ;
 if ( dsize ) * dsize = os -> psize ;
 if ( fpos ) * fpos = os -> sync_pos ;
 os -> pstart += os -> psize ;
 os -> psize = 0 ;
 if ( os -> pstart == os -> bufpos ) os -> bufpos = os -> pstart = 0 ;
 os -> sync_pos = os -> page_pos ;
 }
 os -> page_end = 1 ;
 for ( i = os -> segp ;
 i < os -> nsegs ;
 i ++ ) if ( os -> segments [ i ] < 255 ) {
 os -> page_end = 0 ;
 break ;
 }
 if ( os -> segp == os -> nsegs ) ogg -> curidx = - 1 ;
 return 0 ;
 }