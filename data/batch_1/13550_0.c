static void report_extract_final_progress ( ExtractJob * extract_job , gint total_files ) {
 char * status ;
 nautilus_progress_info_set_destination ( extract_job -> common . progress , extract_job -> destination_directory ) ;
 if ( total_files == 1 ) {
 GFile * source_file ;
 source_file = G_FILE ( extract_job -> source_files -> data ) ;
 status = f ( _ ( "Extracted “%B” to “%B”" ) , source_file , extract_job -> destination_directory ) ;
 }
 else {
 status = f ( ngettext ( "Extracted %'d file to “%B”" , "Extracted %'d files to “%B”" , total_files ) , total_files , extract_job -> destination_directory ) ;
 }
 nautilus_progress_info_take_status ( extract_job -> common . progress , status ) ;
 nautilus_progress_info_take_details ( extract_job -> common . progress , f ( _ ( "%S / %S" ) , extract_job -> total_compressed_size , extract_job -> total_compressed_size ) ) ;
 }