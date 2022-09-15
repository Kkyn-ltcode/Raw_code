static void dissect_rtmpt_common ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , rtmpt_conv_t * rconv , int cdir , guint32 seq , guint32 lastackseq ) {
 int offset = 0 ;
 int remain ;
 int want ;
 guint8 header_type ;
 int basic_hlen ;
 int message_hlen ;
 guint32 id ;
 guint32 ts = 0 ;
 guint32 tsd = 0 ;
 int body_len ;
 guint8 cmd ;
 guint32 src ;
 int chunk_size ;
 guint32 save_seq = 0 ;
 rtmpt_frag_t * tf ;
 rtmpt_id_t * ti ;
 rtmpt_packet_t * tp ;
 tvbuff_t * pktbuf ;
 remain = tvb_reported_length ( tvb ) ;
 if ( ! remain ) return ;
 RTMPT_DEBUG ( "Segment: cdir=%d seq=%d-%d\n" , cdir , seq , seq + remain - 1 ) ;
 if ( pinfo -> fd -> flags . visited ) {
 wmem_stack_t * packets ;
 packets = wmem_stack_new ( wmem_packet_scope ( ) ) ;
 wmem_stack_push ( packets , 0 ) ;
 tp = ( rtmpt_packet_t * ) wmem_tree_lookup32_le ( rconv -> packets [ cdir ] , seq + remain - 1 ) ;
 while ( tp && tp -> lastseq >= seq && tp -> lastseq >= save_seq ) {
 wmem_stack_push ( packets , tp ) ;
 save_seq = tp -> lastseq + 1 ;
 tp = ( rtmpt_packet_t * ) wmem_tree_lookup32_le ( rconv -> packets [ cdir ] , tp -> lastseq - 1 ) ;
 }
 while ( ( tp = ( rtmpt_packet_t * ) wmem_stack_pop ( packets ) ) != NULL ) {
 if ( tp -> resident ) {
 pktbuf = tvb_new_child_real_data ( tvb , tp -> data . p , tp -> have , tp -> have ) ;
 add_new_data_source ( pinfo , pktbuf , "Unchunked RTMP" ) ;
 }
 else {
 pktbuf = tvb_new_subset_length ( tvb , tp -> data . offset , tp -> have ) ;
 }
 dissect_rtmpt ( pktbuf , pinfo , tree , rconv , cdir , tp ) ;
 }
 return ;
 }
 while ( remain > 0 ) {
 tf = NULL ;
 ti = NULL ;
 tp = NULL ;
 if ( offset == 0 ) {
 tf = ( rtmpt_frag_t * ) wmem_tree_lookup32_le ( rconv -> frags [ cdir ] , seq + offset - 1 ) ;
 if ( tf ) {
 RTMPT_DEBUG ( " tf seq=%d lseq=%d h=%d l=%d\n" , tf -> seq , tf -> lastseq , tf -> have , tf -> len ) ;
 if ( tf -> have >= tf -> len || seq + offset < tf -> seq || seq + offset > tf -> lastseq + tf -> len - tf -> have ) {
 tf = NULL ;
 }
 else if ( ! tf -> ishdr ) {
 ti = ( rtmpt_id_t * ) wmem_tree_lookup32 ( rconv -> ids [ cdir ] , tf -> saved . id ) ;
 if ( ti ) {
 tp = ( rtmpt_packet_t * ) wmem_tree_lookup32_le ( ti -> packets , seq + offset - 1 ) ;
 }
 if ( tp && tp -> chunkwant ) {
 goto unchunk ;
 }
 tf = NULL ;
 ti = NULL ;
 tp = NULL ;
 }
 if ( tf ) {
 want = tf -> len - tf -> have ;
 if ( remain < want ) want = remain ;
 tvb_memcpy ( tvb , tf -> saved . d + tf -> have , offset , want ) ;
 id = tf -> saved . d [ 0 ] ;
 header_type = ( id >> 6 ) & 3 ;
 basic_hlen = rtmpt_basic_header_length ( id ) ;
 if ( ( header_type < 3 ) && ( tf -> have < ( basic_hlen + 3 ) ) && ( tf -> have + want >= ( basic_hlen + 3 ) ) ) {
 if ( pntoh24 ( tf -> saved . d + basic_hlen ) == 0xffffff ) {
 tf -> len += 4 ;
 }
 }
 tf -> have += want ;
 tf -> lastseq = seq + want - 1 ;
 remain -= want ;
 offset += want ;
 if ( tf -> have < tf -> len ) {
 return ;
 }
 }
 }
 }
 if ( ! tf ) {
 id = tvb_get_guint8 ( tvb , offset ) ;
 if ( id == RTMPT_MAGIC && seq + offset == RTMPT_HANDSHAKE_OFFSET_1 ) {
 header_type = 4 ;
 basic_hlen = 1 ;
 message_hlen = 0 ;
 id = lastackseq == 1 ? RTMPT_TYPE_HANDSHAKE_1 : RTMPT_TYPE_HANDSHAKE_2 ;
 }
 else if ( seq + offset == RTMPT_HANDSHAKE_OFFSET_2 ) {
 header_type = 4 ;
 basic_hlen = 0 ;
 message_hlen = 0 ;
 id = RTMPT_TYPE_HANDSHAKE_3 ;
 }
 else {
 header_type = ( id >> 6 ) & 3 ;
 basic_hlen = rtmpt_basic_header_length ( id ) ;
 message_hlen = rtmpt_message_header_length ( id ) ;
 if ( ( header_type < 3 ) && ( remain >= ( basic_hlen + 3 ) ) ) {
 if ( tvb_get_ntoh24 ( tvb , offset + basic_hlen ) == 0xffffff ) {
 message_hlen += 4 ;
 }
 }
 if ( remain < ( basic_hlen + message_hlen ) ) {
 tf = wmem_new ( wmem_file_scope ( ) , rtmpt_frag_t ) ;
 tf -> ishdr = 1 ;
 tf -> seq = seq + offset ;
 tf -> lastseq = tf -> seq + remain - 1 ;
 tf -> len = basic_hlen + message_hlen ;
 tvb_memcpy ( tvb , tf -> saved . d , offset , remain ) ;
 tf -> have = remain ;
 wmem_tree_insert32 ( rconv -> frags [ cdir ] , seq + offset , tf ) ;
 return ;
 }
 id = id & 0x3f ;
 if ( id == 0 ) id = tvb_get_guint8 ( tvb , offset + 1 ) + 64 ;
 else if ( id == 1 ) id = tvb_get_letohs ( tvb , offset + 1 ) + 64 ;
 }
 }
 else {
 id = tf -> saved . d [ 0 ] ;
 header_type = ( id >> 6 ) & 3 ;
 basic_hlen = rtmpt_basic_header_length ( id ) ;
 message_hlen = tf -> len - basic_hlen ;
 id = id & 0x3f ;
 if ( id == 0 ) id = tf -> saved . d [ 1 ] + 64 ;
 else if ( id == 1 ) id = pletoh16 ( tf -> saved . d + 1 ) + 64 ;
 }
 if ( id <= RTMPT_ID_MAX ) ti = ( rtmpt_id_t * ) wmem_tree_lookup32 ( rconv -> ids [ cdir ] , id ) ;
 if ( ti ) tp = ( rtmpt_packet_t * ) wmem_tree_lookup32_le ( ti -> packets , seq + offset - 1 ) ;
 if ( header_type == 0 ) src = tf ? pntoh32 ( tf -> saved . d + basic_hlen + 7 ) : tvb_get_ntohl ( tvb , offset + basic_hlen + 7 ) ;
 else if ( ti ) src = ti -> src ;
 else src = 0 ;
 if ( header_type < 2 ) cmd = tf ? tf -> saved . d [ basic_hlen + 6 ] : tvb_get_guint8 ( tvb , offset + basic_hlen + 6 ) ;
 else if ( ti ) cmd = ti -> cmd ;
 else cmd = 0 ;
 if ( id > RTMPT_ID_MAX ) {
 if ( id == RTMPT_TYPE_HANDSHAKE_1 ) chunk_size = body_len = 1536 ;
 else if ( id == RTMPT_TYPE_HANDSHAKE_2 ) chunk_size = body_len = 3072 ;
 else chunk_size = body_len = 1536 ;
 }
 else {
 chunk_size = GPOINTER_TO_INT ( wmem_tree_lookup32_le ( rconv -> chunksize [ cdir ] , seq + offset - 1 ) ) ;
 if ( ! chunk_size ) chunk_size = RTMPT_DEFAULT_CHUNK_SIZE ;
 if ( header_type < 2 ) body_len = tf ? pntoh24 ( tf -> saved . d + basic_hlen + 3 ) : tvb_get_ntoh24 ( tvb , offset + basic_hlen + 3 ) ;
 else if ( ti ) body_len = ti -> len ;
 else body_len = chunk_size ;
 if ( body_len > ( gint ) rtmpt_max_packet_size ) {
 return ;
 }
 }
 if ( ! ti || ! tp || header_type < 3 || tp -> have == tp -> want || tp -> chunkhave != tp -> chunkwant ) {
 RTMPT_DEBUG ( "New packet cdir=%d seq=%d ti=%p tp=%p header_type=%d header_len=%d id=%d tph=%d tpw=%d len=%d cs=%d\n" , cdir , seq + offset , ti , tp , header_type , basic_hlen + message_hlen , id , tp ? tp -> have : 0 , tp ? tp -> want : 0 , body_len , chunk_size ) ;
 if ( ! ti ) {
 ti = wmem_new ( wmem_file_scope ( ) , rtmpt_id_t ) ;
 ti -> packets = wmem_tree_new ( wmem_file_scope ( ) ) ;
 ti -> ts = 0 ;
 ti -> tsd = 0 ;
 wmem_tree_insert32 ( rconv -> ids [ cdir ] , id , ti ) ;
 }
 if ( header_type == 0 ) {
 ts = tf ? pntoh24 ( tf -> saved . d + basic_hlen ) : tvb_get_ntoh24 ( tvb , offset + basic_hlen ) ;
 if ( ts == 0xffffff ) {
 ts = tf ? pntoh32 ( tf -> saved . d + basic_hlen + 11 ) : tvb_get_ntohl ( tvb , offset + basic_hlen + 11 ) ;
 }
 tsd = ts - ti -> ts ;
 }
 else if ( header_type < 3 ) {
 tsd = tf ? pntoh24 ( tf -> saved . d + basic_hlen ) : tvb_get_ntoh24 ( tvb , offset + basic_hlen ) ;
 if ( tsd == 0xffffff ) {
 ts = tf ? pntoh32 ( tf -> saved . d + basic_hlen + message_hlen - 4 ) : tvb_get_ntohl ( tvb , offset + basic_hlen + message_hlen - 4 ) ;
 tsd = ti -> tsd ;
 }
 else {
 ts = ti -> ts + tsd ;
 }
 }
 else {
 ts = ti -> ts + ti -> tsd ;
 tsd = ti -> tsd ;
 }
 tp = wmem_new ( wmem_file_scope ( ) , rtmpt_packet_t ) ;
 tp -> seq = tp -> lastseq = tf ? tf -> seq : seq + offset ;
 tp -> have = 0 ;
 tp -> want = basic_hlen + message_hlen + body_len ;
 tp -> chunkwant = 0 ;
 tp -> chunkhave = 0 ;
 tp -> bhlen = basic_hlen ;
 tp -> mhlen = message_hlen ;
 tp -> fmt = header_type ;
 tp -> id = id ;
 tp -> ts = ts ;
 tp -> len = body_len ;
 if ( id > RTMPT_ID_MAX ) tp -> cmd = id ;
 else tp -> cmd = cmd & 0x7f ;
 tp -> src = src ;
 tp -> txid = 0 ;
 tp -> isresponse = FALSE ;
 tp -> otherframe = 0 ;
 ti -> ts = ts ;
 ti -> tsd = tsd ;
 ti -> len = body_len ;
 ti -> cmd = cmd ;
 ti -> src = src ;
 wmem_tree_insert32 ( ti -> packets , tp -> seq , tp ) ;
 if ( ! tf && body_len <= chunk_size && tp -> want <= remain ) {
 tp -> resident = FALSE ;
 tp -> data . offset = offset ;
 tp -> lastseq = seq + offset + tp -> want - 1 ;
 tp -> have = tp -> want ;
 wmem_tree_insert32 ( rconv -> packets [ cdir ] , tp -> lastseq , tp ) ;
 pktbuf = tvb_new_subset_length ( tvb , tp -> data . offset , tp -> have ) ;
 dissect_rtmpt ( pktbuf , pinfo , tree , rconv , cdir , tp ) ;
 offset += tp -> want ;
 remain -= tp -> want ;
 continue ;
 }
 else {
 tp -> resident = TRUE ;
 tp -> data . p = ( guint8 * ) wmem_alloc ( wmem_file_scope ( ) , tp -> bhlen + tp -> mhlen + tp -> len ) ;
 if ( tf && tf -> ishdr ) {
 memcpy ( tp -> data . p , tf -> saved . d , tf -> len ) ;
 }
 else {
 tvb_memcpy ( tvb , tp -> data . p , offset , basic_hlen + message_hlen ) ;
 offset += basic_hlen + message_hlen ;
 remain -= basic_hlen + message_hlen ;
 }
 tp -> lastseq = seq + offset - 1 ;
 tp -> have = basic_hlen + message_hlen ;
 if ( tp -> have == tp -> want ) {
 wmem_tree_insert32 ( rconv -> packets [ cdir ] , tp -> lastseq , tp ) ;
 pktbuf = tvb_new_child_real_data ( tvb , tp -> data . p , tp -> have , tp -> have ) ;
 add_new_data_source ( pinfo , pktbuf , "Unchunked RTMP" ) ;
 dissect_rtmpt ( pktbuf , pinfo , tree , rconv , cdir , tp ) ;
 continue ;
 }
 tp -> chunkwant = chunk_size ;
 if ( tp -> chunkwant > tp -> want - tp -> have ) tp -> chunkwant = tp -> want - tp -> have ;
 }
 }
 else {
 RTMPT_DEBUG ( "Old packet cdir=%d seq=%d ti=%p tp=%p header_len=%d id=%d tph=%d tpw=%d len=%d cs=%d\n" , cdir , seq + offset , ti , tp , basic_hlen + message_hlen , id , tp ? tp -> have : 0 , tp ? tp -> want : 0 , body_len , chunk_size ) ;
 tp -> chunkwant = chunk_size ;
 if ( tp -> chunkwant > tp -> want - tp -> have ) tp -> chunkwant = tp -> want - tp -> have ;
 offset += basic_hlen + message_hlen ;
 remain -= basic_hlen + message_hlen ;
 }
 tf = NULL ;
 unchunk : want = tp -> chunkwant - tp -> chunkhave ;
 if ( want > remain ) want = remain ;
 RTMPT_DEBUG ( " cw=%d ch=%d r=%d w=%d\n" , tp -> chunkwant , tp -> chunkhave , remain , want ) ;
 tvb_memcpy ( tvb , tp -> data . p + tp -> have , offset , want ) ;
 if ( tf ) {
 tf -> have += want ;
 tf -> lastseq = seq + offset + want - 1 ;
 }
 tp -> lastseq = seq + offset + want - 1 ;
 tp -> have += want ;
 tp -> chunkhave += want ;
 offset += want ;
 remain -= want ;
 if ( tp -> chunkhave == tp -> chunkwant ) {
 tp -> chunkhave = 0 ;
 tp -> chunkwant = 0 ;
 }
 if ( tp -> have == tp -> want ) {
 wmem_tree_insert32 ( rconv -> packets [ cdir ] , tp -> lastseq , tp ) ;
 pktbuf = tvb_new_child_real_data ( tvb , tp -> data . p , tp -> have , tp -> have ) ;
 add_new_data_source ( pinfo , pktbuf , "Unchunked RTMP" ) ;
 dissect_rtmpt ( pktbuf , pinfo , tree , rconv , cdir , tp ) ;
 }
 else if ( tp -> chunkhave < tp -> chunkwant ) {
 rtmpt_frag_t * tf2 = wmem_new ( wmem_file_scope ( ) , rtmpt_frag_t ) ;
 tf2 -> ishdr = 0 ;
 tf2 -> seq = seq + offset - want ;
 tf2 -> lastseq = tf2 -> seq + remain - 1 + want ;
 tf2 -> have = tp -> chunkhave ;
 tf2 -> len = tp -> chunkwant ;
 tf2 -> saved . id = tp -> id ;
 RTMPT_DEBUG ( " inserting tf @ %d\n" , seq + offset - want - 1 ) ;
 wmem_tree_insert32 ( rconv -> frags [ cdir ] , seq + offset - want - 1 , tf2 ) ;
 }
 }
 }