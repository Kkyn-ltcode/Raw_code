static void mark_desktop_file_executable_task_thread_func ( GTask * task , gpointer source_object , gpointer task_data , GCancellable * cancellable ) {
 MarkTrustedJob * job = task_data ;
 CommonJob * common ;
 common = ( CommonJob * ) job ;
 nautilus_progress_info_start ( job -> common . progress ) ;
 mark_desktop_file_executable ( common , cancellable , job -> file , job -> interactive ) ;
 }