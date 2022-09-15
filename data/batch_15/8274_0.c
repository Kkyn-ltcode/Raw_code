static int mspack_fmap_write ( struct mspack_file * file , void * buffer , int bytes ) {
 struct mspack_handle * mspack_handle = ( struct mspack_handle * ) file ;
 size_t count ;
 off_t max_size ;
 if ( bytes < 0 || ! mspack_handle ) {
 cli_dbgmsg ( "%s() err %d\n" , __func__ , __LINE__ ) ;
 return - 1 ;
 }
 if ( mspack_handle -> type == FILETYPE_FMAP ) {
 cli_dbgmsg ( "%s() err %d\n" , __func__ , __LINE__ ) ;
 return - 1 ;
 }
 if ( ! bytes ) return 0 ;
 max_size = mspack_handle -> max_size ;
 if ( ! max_size ) return bytes ;
 max_size = max_size < ( off_t ) bytes ? max_size : ( off_t ) bytes ;
 mspack_handle -> max_size -= max_size ;
 count = fwrite ( buffer , max_size , 1 , mspack_handle -> f ) ;
 if ( count < 1 ) {
 cli_dbgmsg ( "%s() err %m <%zd %d>\n" , __func__ , count , bytes ) ;
 return - 1 ;
 }
 return bytes ;
 }