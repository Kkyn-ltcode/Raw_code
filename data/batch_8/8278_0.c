static off_t mspack_fmap_tell ( struct mspack_file * file ) {
 struct mspack_handle * mspack_handle = ( struct mspack_handle * ) file ;
 if ( ! mspack_handle ) return - 1 ;
 if ( mspack_handle -> type == FILETYPE_FMAP ) return mspack_handle -> offset ;
 return ( off_t ) ftell ( mspack_handle -> f ) ;
 }