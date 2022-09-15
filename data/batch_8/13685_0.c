static void report_copy_progress ( CopyMoveJob * copy_job , SourceInfo * source_info , TransferInfo * transfer_info ) {
 int files_left ;
 goffset total_size ;
 double elapsed , transfer_rate ;
 int remaining_time ;
 guint64 now ;
 CommonJob * job ;
 gboolean is_move ;
 gchar * status ;
 char * details ;
 job = ( CommonJob * ) copy_job ;
 is_move = copy_job -> is_move ;
 now = g_get_monotonic_time ( ) ;
 files_left = source_info -> num_files - transfer_info -> num_files ;
 if ( files_left < 0 ) {
 files_left = 0 ;
 }
 if ( transfer_info -> last_report_time != 0 && ABS ( ( gint64 ) ( transfer_info -> last_report_time - now ) ) < 100 * NSEC_PER_MICROSEC && files_left > 0 ) {
 return ;
 }
 transfer_info -> last_report_time = now ;
 if ( files_left != transfer_info -> last_reported_files_left || transfer_info -> last_reported_files_left == 0 ) {
 transfer_info -> last_reported_files_left = files_left ;
 if ( source_info -> num_files == 1 ) {
 if ( copy_job -> destination != NULL ) {
 if ( is_move ) {
 if ( files_left > 0 ) {
 status = _ ( "Moving “%B” to “%B”" ) ;
 }
 else {
 status = _ ( "Moved “%B” to “%B”" ) ;
 }
 }
 else {
 if ( files_left > 0 ) {
 status = _ ( "Copying “%B” to “%B”" ) ;
 }
 else {
 status = _ ( "Copied “%B” to “%B”" ) ;
 }
 }
 nautilus_progress_info_take_status ( job -> progress , f ( status , copy_job -> fake_display_source != NULL ? copy_job -> fake_display_source : ( GFile * ) copy_job -> files -> data , copy_job -> destination ) ) ;
 }
 else {
 if ( files_left > 0 ) {
 status = _ ( "Duplicating “%B”" ) ;
 }
 else {
 status = _ ( "Duplicated “%B”" ) ;
 }
 nautilus_progress_info_take_status ( job -> progress , f ( status , ( GFile * ) copy_job -> files -> data ) ) ;
 }
 }
 else if ( copy_job -> files != NULL ) {
 if ( copy_job -> destination != NULL ) {
 if ( files_left > 0 ) {
 if ( is_move ) {
 status = ngettext ( "Moving %'d file to “%B”" , "Moving %'d files to “%B”" , source_info -> num_files ) ;
 }
 else {
 status = ngettext ( "Copying %'d file to “%B”" , "Copying %'d files to “%B”" , source_info -> num_files ) ;
 }
 nautilus_progress_info_take_status ( job -> progress , f ( status , source_info -> num_files , ( GFile * ) copy_job -> destination ) ) ;
 }
 else {
 if ( is_move ) {
 status = ngettext ( "Moved %'d file to “%B”" , "Moved %'d files to “%B”" , source_info -> num_files ) ;
 }
 else {
 status = ngettext ( "Copied %'d file to “%B”" , "Copied %'d files to “%B”" , source_info -> num_files ) ;
 }
 nautilus_progress_info_take_status ( job -> progress , f ( status , source_info -> num_files , ( GFile * ) copy_job -> destination ) ) ;
 }
 }
 else {
 GFile * parent ;
 parent = g_file_get_parent ( copy_job -> files -> data ) ;
 if ( files_left > 0 ) {
 status = ngettext ( "Duplicating %'d file in “%B”" , "Duplicating %'d files in “%B”" , source_info -> num_files ) ;
 nautilus_progress_info_take_status ( job -> progress , f ( status , source_info -> num_files , parent ) ) ;
 }
 else {
 status = ngettext ( "Duplicated %'d file in “%B”" , "Duplicated %'d files in “%B”" , source_info -> num_files ) ;
 nautilus_progress_info_take_status ( job -> progress , f ( status , source_info -> num_files , parent ) ) ;
 }
 g_object_unref ( parent ) ;
 }
 }
 }
 total_size = MAX ( source_info -> num_bytes , transfer_info -> num_bytes ) ;
 elapsed = g_timer_elapsed ( job -> time , NULL ) ;
 transfer_rate = 0 ;
 remaining_time = INT_MAX ;
 if ( elapsed > 0 ) {
 transfer_rate = transfer_info -> num_bytes / elapsed ;
 if ( transfer_rate > 0 ) {
 remaining_time = ( total_size - transfer_info -> num_bytes ) / transfer_rate ;
 }
 }
 if ( elapsed < SECONDS_NEEDED_FOR_RELIABLE_TRANSFER_RATE && transfer_rate > 0 ) {
 if ( source_info -> num_files == 1 ) {
 details = f ( _ ( "%S / %S" ) , transfer_info -> num_bytes , total_size ) ;
 }
 else {
 if ( files_left > 0 ) {
 details = f ( _ ( "%'d / %'d" ) , transfer_info -> num_files + 1 , source_info -> num_files ) ;
 }
 else {
 details = f ( _ ( "%'d / %'d" ) , transfer_info -> num_files , source_info -> num_files ) ;
 }
 }
 }
 else {
 if ( source_info -> num_files == 1 ) {
 if ( files_left > 0 ) {
 details = f ( ngettext ( "%S / %S \xE2\x80\x94 %T left (%S/sec)" , "%S / %S \xE2\x80\x94 %T left (%S/sec)" , seconds_count_format_time_units ( remaining_time ) ) , transfer_info -> num_bytes , total_size , remaining_time , ( goffset ) transfer_rate ) ;
 }
 else {
 details = f ( _ ( "%S / %S" ) , transfer_info -> num_bytes , total_size ) ;
 }
 }
 else {
 if ( files_left > 0 ) {
 details = f ( ngettext ( "%'d / %'d \xE2\x80\x94 %T left (%S/sec)" , "%'d / %'d \xE2\x80\x94 %T left (%S/sec)" , seconds_count_format_time_units ( remaining_time ) ) , transfer_info -> num_files + 1 , source_info -> num_files , remaining_time , ( goffset ) transfer_rate ) ;
 }
 else {
 details = f ( _ ( "%'d / %'d" ) , transfer_info -> num_files , source_info -> num_files ) ;
 }
 }
 }
 nautilus_progress_info_take_details ( job -> progress , details ) ;
 if ( elapsed > SECONDS_NEEDED_FOR_APROXIMATE_TRANSFER_RATE ) {
 nautilus_progress_info_set_remaining_time ( job -> progress , remaining_time ) ;
 nautilus_progress_info_set_elapsed_time ( job -> progress , elapsed ) ;
 }
 nautilus_progress_info_set_progress ( job -> progress , transfer_info -> num_bytes , total_size ) ;
 }