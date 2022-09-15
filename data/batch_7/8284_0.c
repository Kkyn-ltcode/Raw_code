static int cli_scanfile ( const char * filename , cli_ctx * ctx ) {
 int fd , ret ;
 fd = safe_open ( filename , O_RDONLY | O_BINARY ) ;
 if ( fd < 0 ) return CL_EOPEN ;
 ret = cli_magic_scandesc ( fd , ctx ) ;
 close ( fd ) ;
 return ret ;
 }