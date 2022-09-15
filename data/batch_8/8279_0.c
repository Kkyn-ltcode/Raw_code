static int mspack_fmap_read ( struct mspack_file * file , void * buffer , int bytes ) {
 struct mspack_handle * mspack_handle = ( struct mspack_handle * ) file ;
 off_t offset ;
 size_t count ;
 int ret ;
 if ( bytes < 0 ) {
 cli_dbgmsg ( "%s() %d\n" , __func__ , __LINE__ ) ;
 return - 1 ;
 }
 if ( ! mspack_handle ) {
 cli_dbgmsg ( "%s() %d\n" , __func__ , __LINE__ ) ;
 return - 1 ;
 }
 if ( mspack_handle -> type == FILETYPE_FMAP ) {
 offset = mspack_handle -> offset + mspack_handle -> org ;
 ret = fmap_readn ( mspack_handle -> fmap , buffer , offset , bytes ) ;
 if ( ret != bytes ) {
 cli_dbgmsg ( "%s() %d %d, %d\n" , __func__ , __LINE__ , bytes , ret ) ;
 return ret ;
 }
 mspack_handle -> offset += bytes ;
 return bytes ;
 }
 count = fread ( buffer , bytes , 1 , mspack_handle -> f ) ;
 if ( count < 1 ) {
 cli_dbgmsg ( "%s() %d %d, %zd\n" , __func__ , __LINE__ , bytes , count ) ;
 return - 1 ;
 }
 return bytes ;
 }