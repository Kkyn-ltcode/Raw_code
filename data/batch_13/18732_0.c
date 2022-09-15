static int xsltCheckFilename ( const char * path ) {
 # ifdef HAVE_STAT struct stat stat_buffer ;
 # if defined ( WIN32 ) && ! defined ( __CYGWIN__ ) DWORD dwAttrs ;
 dwAttrs = GetFileAttributesA ( path ) ;
 if ( dwAttrs != INVALID_FILE_ATTRIBUTES ) {
 if ( dwAttrs & FILE_ATTRIBUTE_DIRECTORY ) {
 return 2 ;
 }
 }
 # endif if ( stat ( path , & stat_buffer ) == - 1 ) return 0 ;
 # ifdef S_ISDIR if ( S_ISDIR ( stat_buffer . st_mode ) ) {
 return 2 ;
 }
 # endif # endif return 1 ;
 }