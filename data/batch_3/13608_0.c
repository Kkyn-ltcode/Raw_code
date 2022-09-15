void nautilus_file_operations_copy_file ( GFile * source_file , GFile * target_dir , const gchar * source_display_name , const gchar * new_name , GtkWindow * parent_window , NautilusCopyCallback done_callback , gpointer done_callback_data ) {
 GTask * task ;
 CopyMoveJob * job ;
 job = op_job_new ( CopyMoveJob , parent_window ) ;
 job -> done_callback = done_callback ;
 job -> done_callback_data = done_callback_data ;
 job -> files = g_list_append ( NULL , g_object_ref ( source_file ) ) ;
 job -> destination = g_object_ref ( target_dir ) ;
 nautilus_progress_info_set_destination ( ( ( CommonJob * ) job ) -> progress , target_dir ) ;
 job -> target_name = g_strdup ( new_name ) ;
 job -> debuting_files = g_hash_table_new_full ( g_file_hash , ( GEqualFunc ) g_file_equal , g_object_unref , NULL ) ;
 if ( source_display_name != NULL ) {
 gchar * path ;
 path = g_build_filename ( "/" , source_display_name , NULL ) ;
 job -> fake_display_source = g_file_new_for_path ( path ) ;
 g_free ( path ) ;
 }
 inhibit_power_manager ( ( CommonJob * ) job , _ ( "Copying Files" ) ) ;
 task = g_task_new ( NULL , job -> common . cancellable , copy_task_done , job ) ;
 g_task_set_task_data ( task , job , NULL ) ;
 g_task_run_in_thread ( task , copy_task_thread_func ) ;
 g_object_unref ( task ) ;
 }