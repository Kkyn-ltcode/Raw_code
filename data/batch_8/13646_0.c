void nautilus_file_operations_new_folder ( GtkWidget * parent_view , GdkPoint * target_point , const char * parent_dir , const char * folder_name , NautilusCreateCallback done_callback , gpointer done_callback_data ) {
 GTask * task ;
 CreateJob * job ;
 GtkWindow * parent_window ;
 parent_window = NULL ;
 if ( parent_view ) {
 parent_window = ( GtkWindow * ) gtk_widget_get_ancestor ( parent_view , GTK_TYPE_WINDOW ) ;
 }
 job = op_job_new ( CreateJob , parent_window ) ;
 job -> done_callback = done_callback ;
 job -> done_callback_data = done_callback_data ;
 job -> dest_dir = g_file_new_for_uri ( parent_dir ) ;
 job -> filename = g_strdup ( folder_name ) ;
 job -> make_dir = TRUE ;
 if ( target_point != NULL ) {
 job -> position = * target_point ;
 job -> has_position = TRUE ;
 }
 if ( ! nautilus_file_undo_manager_is_operating ( ) ) {
 job -> common . undo_info = nautilus_file_undo_info_create_new ( NAUTILUS_FILE_UNDO_OP_CREATE_FOLDER ) ;
 }
 task = g_task_new ( NULL , job -> common . cancellable , create_task_done , job ) ;
 g_task_set_task_data ( task , job , NULL ) ;
 g_task_run_in_thread ( task , create_task_thread_func ) ;
 g_object_unref ( task ) ;
 }