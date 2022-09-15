static int evutil_issetugid ( void ) {
 # ifdef _EVENT_HAVE_ISSETUGID return issetugid ( ) ;
 # else # ifdef _EVENT_HAVE_GETEUID if ( getuid ( ) != geteuid ( ) ) return 1 ;
 # endif # ifdef _EVENT_HAVE_GETEGID if ( getgid ( ) != getegid ( ) ) return 1 ;
 # endif return 0 ;
 # endif }