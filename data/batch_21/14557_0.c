int mvfprintf ( FILE * fp , const char * fmt , va_list ap ) {
 # ifndef VSNPRINTF_PERCENT_M char nfmt [ 256 ] ;
 # else const char * nfmt = fmt ;
 # endif int errval ;
 # ifdef SYS_WINNT errval = GetLastError ( ) ;
 if ( NO_ERROR == errval ) # endif errval = errno ;
 # ifndef VSNPRINTF_PERCENT_M format_errmsg ( nfmt , sizeof ( nfmt ) , fmt , errval ) ;
 # else errno = errval ;
 # endif return vfprintf ( fp , nfmt , ap ) ;
 }