static int mspack_fmap_seek ( struct mspack_file * file , off_t offset , int mode ) {
 struct mspack_handle * mspack_handle = ( struct mspack_handle * ) file ;
 if ( ! mspack_handle ) {
 cli_dbgmsg ( "%s() err %d\n" , __func__ , __LINE__ ) ;
 return - 1 ;
 }
 if ( mspack_handle -> type == FILETYPE_FMAP ) {
 off_t new_pos ;
 switch ( mode ) {
 case MSPACK_SYS_SEEK_START : new_pos = offset ;
 break ;
 case MSPACK_SYS_SEEK_CUR : new_pos = mspack_handle -> offset + offset ;
 break ;
 case MSPACK_SYS_SEEK_END : new_pos = mspack_handle -> fmap -> len + offset ;
 break ;
 default : cli_dbgmsg ( "%s() err %d\n" , __func__ , __LINE__ ) ;
 return - 1 ;
 }
 if ( new_pos < 0 || new_pos > mspack_handle -> fmap -> len ) {
 cli_dbgmsg ( "%s() err %d\n" , __func__ , __LINE__ ) ;
 return - 1 ;
 }
 mspack_handle -> offset = new_pos ;
 return 0 ;
 }
 switch ( mode ) {
 case MSPACK_SYS_SEEK_START : mode = SEEK_SET ;
 break ;
 case MSPACK_SYS_SEEK_CUR : mode = SEEK_CUR ;
 break ;
 case MSPACK_SYS_SEEK_END : mode = SEEK_END ;
 break ;
 default : cli_dbgmsg ( "%s() err %d\n" , __func__ , __LINE__ ) ;
 return - 1 ;
 }
 return fseek ( mspack_handle -> f , offset , mode ) ;
 }