static gboolean confirm_delete_directly ( CommonJob * job , GList * files ) {
 char * prompt ;
 int file_count ;
 int response ;
 if ( ! should_confirm_trash ( ) ) {
 return TRUE ;
 }
 file_count = g_list_length ( files ) ;
 g_assert ( file_count > 0 ) ;
 if ( can_delete_files_without_confirm ( files ) ) {
 return TRUE ;
 }
 if ( file_count == 1 ) {
 prompt = f ( _ ( "Are you sure you want to permanently delete “%B”?" ) , files -> data ) ;
 }
 else {
 prompt = f ( ngettext ( "Are you sure you want to permanently delete " "the %'d selected item?" , "Are you sure you want to permanently delete " "the %'d selected items?" , file_count ) , file_count ) ;
 }
 response = run_warning ( job , prompt , f ( _ ( "If you delete an item, it will be permanently lost." ) ) , NULL , FALSE , CANCEL , DELETE , NULL ) ;
 return response == 1 ;
 }