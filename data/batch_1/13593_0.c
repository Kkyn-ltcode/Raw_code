void nautilus_file_operations_empty_trash ( GtkWidget * parent_view ) {
 GTask * task ;
 EmptyTrashJob * job ;
 GtkWindow * parent_window ;
 parent_window = NULL ;
 if ( parent_view ) {
 parent_window = ( GtkWindow * ) gtk_widget_get_ancestor ( parent_view , GTK_TYPE_WINDOW ) ;
 }
 job = op_job_new ( EmptyTrashJob , parent_window ) ;
 job -> trash_dirs = g_list_prepend ( job -> trash_dirs , g_file_new_for_uri ( "trash:" ) ) ;
 job -> should_confirm = TRUE ;
 inhibit_power_manager ( ( CommonJob * ) job , _ ( "Emptying Trash" ) ) ;
 task = g_task_new ( NULL , NULL , empty_trash_task_done , job ) ;
 g_task_set_task_data ( task , job , NULL ) ;
 g_task_run_in_thread ( task , empty_trash_thread_func ) ;
 g_object_unref ( task ) ;
 }