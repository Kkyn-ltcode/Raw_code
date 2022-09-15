static void mspack_fmap_close ( struct mspack_file * file ) {
 struct mspack_handle * mspack_handle = ( struct mspack_handle * ) file ;
 if ( ! mspack_handle ) return ;
 if ( mspack_handle -> type == FILETYPE_FILENAME ) fclose ( mspack_handle -> f ) ;
 free ( mspack_handle ) ;
 }