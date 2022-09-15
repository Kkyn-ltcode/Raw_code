static gboolean confirm_delete_from_trash ( CommonJob * job , GList * files ) {
 char * prompt ;
 int file_count ;
 int response ;
 if ( ! should_confirm_trash ( ) ) {
 return TRUE ;
 }
 file_count = g_list_length ( files ) ;
 g_assert ( file_count > 0 ) ;
 if ( file_count == 1 ) {
 prompt = f ( _ ( "Are you sure you want to permanently delete “%B” " "from the trash?" ) , files -> data ) ;
 }
 else {
 prompt = f ( ngettext ( "Are you sure you want to permanently delete " "the %'d selected item from the trash?" , "Are you sure you want to permanently delete " "the %'d selected items from the trash?" , file_count ) , file_count ) ;
 }
 response = run_warning ( job , prompt , f ( _ ( "If you delete an item, it will be permanently lost." ) ) , NULL , FALSE , CANCEL , DELETE , NULL ) ;
 return ( response == 1 ) ;
 }