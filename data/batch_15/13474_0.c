static void cancel_thumbnail_for_file ( NautilusDirectory * directory , NautilusFile * file ) {
 if ( directory -> details -> thumbnail_state != NULL && directory -> details -> thumbnail_state -> file == file ) {
 thumbnail_cancel ( directory ) ;
 }
 }