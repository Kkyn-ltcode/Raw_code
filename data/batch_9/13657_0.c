static void compress_task_thread_func ( GTask * task , gpointer source_object , gpointer task_data , GCancellable * cancellable ) {
 CompressJob * compress_job = task_data ;
 SourceInfo source_info ;
 g_autoptr ( AutoarCompressor ) compressor = NULL ;
 g_timer_start ( compress_job -> common . time ) ;
 nautilus_progress_info_start ( compress_job -> common . progress ) ;
 scan_sources ( compress_job -> source_files , & source_info , ( CommonJob * ) compress_job , OP_KIND_COMPRESS ) ;
 compress_job -> total_files = source_info . num_files ;
 compress_job -> total_size = source_info . num_bytes ;
 compressor = autoar_compressor_new ( compress_job -> source_files , compress_job -> output_file , compress_job -> format , compress_job -> filter , FALSE ) ;
 autoar_compressor_set_output_is_dest ( compressor , TRUE ) ;
 autoar_compressor_set_notify_interval ( compressor , PROGRESS_NOTIFY_INTERVAL ) ;
 g_signal_connect ( compressor , "progress" , G_CALLBACK ( compress_job_on_progress ) , compress_job ) ;
 g_signal_connect ( compressor , "error" , G_CALLBACK ( compress_job_on_error ) , compress_job ) ;
 g_signal_connect ( compressor , "completed" , G_CALLBACK ( compress_job_on_completed ) , compress_job ) ;
 autoar_compressor_start ( compressor , compress_job -> common . cancellable ) ;
 compress_job -> success = g_file_query_exists ( compress_job -> output_file , NULL ) ;
 if ( compress_job -> common . undo_info != NULL && ! compress_job -> success ) {
 g_clear_object ( & compress_job -> common . undo_info ) ;
 }
 }