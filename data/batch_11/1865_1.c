static UFILE * finit_owner ( FILE * f , const char * locale , const char * codepage , UBool takeOwnership ) {
 UErrorCode status = U_ZERO_ERROR ;
 UFILE * result ;
 if ( f == NULL ) {
 return 0 ;
 }
 result = ( UFILE * ) uprv_malloc ( sizeof ( UFILE ) ) ;
 if ( result == NULL ) {
 return 0 ;
 }
 uprv_memset ( result , 0 , sizeof ( UFILE ) ) ;
 result -> fFileno = fileno ( f ) ;
 # if U_PLATFORM_USES_ONLY_WIN32_API && _MSC_VER < 1900 if ( 0 <= result -> fFileno && result -> fFileno <= 2 ) {
 # if _MSC_VER >= 1400 result -> fFile = & __iob_func ( ) [ _fileno ( f ) ] ;
 # else result -> fFile = & _iob [ _fileno ( f ) ] ;
 # endif }
 else # endif {
 result -> fFile = f ;
 }
 result -> str . fBuffer = result -> fUCBuffer ;
 result -> str . fPos = result -> fUCBuffer ;
 result -> str . fLimit = result -> fUCBuffer ;
 # if ! UCONFIG_NO_FORMATTING if ( u_locbund_init ( & result -> str . fBundle , locale ) == 0 ) {
 uprv_free ( result ) ;
 return 0 ;
 }
 # endif if ( codepage == NULL || * codepage != '\0' ) {
 result -> fConverter = ucnv_open ( codepage , & status ) ;
 }
 if ( U_SUCCESS ( status ) ) {
 result -> fOwnFile = takeOwnership ;
 }
 else {
 # if ! UCONFIG_NO_FORMATTING u_locbund_close ( & result -> str . fBundle ) ;
 # endif uprv_free ( result ) ;
 result = NULL ;
 }
 return result ;
 }