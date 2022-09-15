static void move_files ( CopyMoveJob * job , GList * fallbacks , const char * dest_fs_id , char * * dest_fs_type , SourceInfo * source_info , TransferInfo * transfer_info ) {
 CommonJob * common ;
 GList * l ;
 GFile * src ;
 gboolean same_fs ;
 int i ;
 GdkPoint * point ;
 gboolean skipped_file ;
 MoveFileCopyFallback * fallback ;
 common = & job -> common ;
 report_copy_progress ( job , source_info , transfer_info ) ;
 i = 0 ;
 for ( l = fallbacks ;
 l != NULL && ! job_aborted ( common ) ;
 l = l -> next ) {
 fallback = l -> data ;
 src = fallback -> file ;
 if ( fallback -> has_position ) {
 point = & fallback -> position ;
 }
 else {
 point = NULL ;
 }
 same_fs = FALSE ;
 if ( dest_fs_id ) {
 same_fs = has_fs_id ( src , dest_fs_id ) ;
 }
 skipped_file = FALSE ;
 copy_move_file ( job , src , job -> destination , same_fs , FALSE , dest_fs_type , source_info , transfer_info , job -> debuting_files , point , fallback -> overwrite , & skipped_file , FALSE ) ;
 i ++ ;
 if ( skipped_file ) {
 transfer_add_file_to_count ( src , common , transfer_info ) ;
 report_copy_progress ( job , source_info , transfer_info ) ;
 }
 }
 }