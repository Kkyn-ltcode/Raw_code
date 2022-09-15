static void scan_sources ( GList * files , SourceInfo * source_info , CommonJob * job , OpKind kind ) {
 GList * l ;
 GFile * file ;
 g_autoptr ( GHashTable ) scanned = NULL ;
 memset ( source_info , 0 , sizeof ( SourceInfo ) ) ;
 source_info -> op = kind ;
 scanned = g_hash_table_new_full ( g_str_hash , g_str_equal , ( GDestroyNotify ) g_free , NULL ) ;
 report_preparing_count_progress ( job , source_info ) ;
 for ( l = files ;
 l != NULL && ! job_aborted ( job ) ;
 l = l -> next ) {
 file = l -> data ;
 scan_file ( file , source_info , job , scanned ) ;
 }
 report_preparing_count_progress ( job , source_info ) ;
 }