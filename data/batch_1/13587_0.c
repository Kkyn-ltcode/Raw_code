void nautilus_file_operations_link ( GList * files , GArray * relative_item_points , GFile * target_dir , GtkWindow * parent_window , NautilusCopyCallback done_callback , gpointer done_callback_data ) {
 GTask * task ;
 CopyMoveJob * job ;
 job = op_job_new ( CopyMoveJob , parent_window ) ;
 job -> done_callback = done_callback ;
 job -> done_callback_data = done_callback_data ;
 job -> files = g_list_copy_deep ( files , ( GCopyFunc ) g_object_ref , NULL ) ;
 job -> destination = g_object_ref ( target_dir ) ;
 nautilus_progress_info_set_destination ( ( ( CommonJob * ) job ) -> progress , target_dir ) ;
 if ( relative_item_points != NULL && relative_item_points -> len > 0 ) {
 job -> icon_positions = g_memdup ( relative_item_points -> data , sizeof ( GdkPoint ) * relative_item_points -> len ) ;
 job -> n_icon_positions = relative_item_points -> len ;
 }
 job -> debuting_files = g_hash_table_new_full ( g_file_hash , ( GEqualFunc ) g_file_equal , g_object_unref , NULL ) ;
 if ( ! nautilus_file_undo_manager_is_operating ( ) ) {
 GFile * src_dir ;
 src_dir = g_file_get_parent ( files -> data ) ;
 job -> common . undo_info = nautilus_file_undo_info_ext_new ( NAUTILUS_FILE_UNDO_OP_CREATE_LINK , g_list_length ( files ) , src_dir , target_dir ) ;
 g_object_unref ( src_dir ) ;
 }
 task = g_task_new ( NULL , job -> common . cancellable , link_task_done , job ) ;
 g_task_set_task_data ( task , job , NULL ) ;
 g_task_run_in_thread ( task , link_task_thread_func ) ;
 g_object_unref ( task ) ;
 }