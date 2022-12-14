static gboolean logcat_dump_text ( wtap_dumper * wdh , const struct wtap_pkthdr * phdr , const guint8 * pd , int * err ) {
 gchar * buf ;
 gint length ;
 gchar priority ;
 const struct logger_entry * log_entry = ( struct logger_entry * ) pd ;
 const struct logger_entry_v2 * log_entry_v2 = ( struct logger_entry_v2 * ) pd ;
 gint payload_length ;
 const gchar * tag ;
 gint32 pid ;
 gint32 tid ;
 gint32 seconds ;
 gint32 milliseconds ;
 const gchar * msg_begin ;
 gint msg_pre_skip ;
 gchar * log ;
 gchar * log_part ;
 gchar * log_next ;
 const union wtap_pseudo_header * pseudo_header = & phdr -> pseudo_header ;
 const struct dumper_t * dumper = ( const struct dumper_t * ) wdh -> priv ;
 if ( phdr -> rec_type != REC_TYPE_PACKET ) {
 * err = WTAP_ERR_REC_TYPE_UNSUPPORTED ;
 return FALSE ;
 }
 payload_length = GINT32_FROM_LE ( log_entry -> len ) ;
 pid = GINT32_FROM_LE ( log_entry -> pid ) ;
 tid = GINT32_FROM_LE ( log_entry -> tid ) ;
 seconds = GINT32_FROM_LE ( log_entry -> sec ) ;
 milliseconds = GINT32_FROM_LE ( log_entry -> nsec ) / 1000000 ;
 if ( pseudo_header -> logcat . version == 1 ) {
 priority = get_priority ( log_entry -> msg [ 0 ] ) ;
 tag = log_entry -> msg + 1 ;
 msg_pre_skip = 1 + strlen ( tag ) + 1 ;
 msg_begin = log_entry -> msg + msg_pre_skip ;
 }
 else if ( pseudo_header -> logcat . version == 2 ) {
 priority = get_priority ( log_entry_v2 -> msg [ 0 ] ) ;
 tag = log_entry_v2 -> msg + 1 ;
 msg_pre_skip = 1 + strlen ( tag ) + 1 ;
 msg_begin = log_entry_v2 -> msg + msg_pre_skip ;
 }
 else {
 * err = WTAP_ERR_UNSUPPORTED ;
 return FALSE ;
 }
 log = g_strndup ( msg_begin , payload_length - msg_pre_skip ) ;
 log_next = log ;
 do {
 log_part = log_next ;
 if ( dumper -> type == DUMP_LONG ) {
 log_next = NULL ;
 }
 else {
 log_next = strchr ( log_part , '\n' ) ;
 if ( log_next != NULL ) {
 * log_next = '\0' ;
 ++ log_next ;
 if ( * log_next == '\0' ) {
 log_next = NULL ;
 }
 }
 }
 buf = logcat_log ( dumper , seconds , milliseconds , pid , tid , priority , tag , log_part ) ;
 if ( ! buf ) {
 g_free ( log ) ;
 return FALSE ;
 }
 length = ( guint32 ) strlen ( buf ) ;
 if ( ! wtap_dump_file_write ( wdh , buf , length , err ) ) {
 g_free ( log ) ;
 return FALSE ;
 }
 wdh -> bytes_dumped += length ;
 }
 while ( log_next != NULL ) ;
 g_free ( log ) ;
 return TRUE ;
 }