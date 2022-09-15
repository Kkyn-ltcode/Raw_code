static int32_t _appendPrivateuseToLanguageTag ( const char * localeID , char * appendAt , int32_t capacity , UBool strict , UBool hadPosix , UErrorCode * status ) {
 char buf [ ULOC_FULLNAME_CAPACITY ] ;
 char tmpAppend [ ULOC_FULLNAME_CAPACITY ] ;
 UErrorCode tmpStatus = U_ZERO_ERROR ;
 int32_t len , i ;
 int32_t reslen = 0 ;
 if ( U_FAILURE ( * status ) ) {
 return 0 ;
 }
 len = uloc_getVariant ( localeID , buf , sizeof ( buf ) , & tmpStatus ) ;
 if ( U_FAILURE ( tmpStatus ) || tmpStatus == U_STRING_NOT_TERMINATED_WARNING ) {
 if ( strict ) {
 * status = U_ILLEGAL_ARGUMENT_ERROR ;
 }
 return 0 ;
 }
 if ( len > 0 ) {
 char * p , * pPriv ;
 UBool bNext = TRUE ;
 UBool firstValue = TRUE ;
 UBool writeValue ;
 pPriv = NULL ;
 p = buf ;
 while ( bNext ) {
 writeValue = FALSE ;
 if ( * p == SEP || * p == LOCALE_SEP || * p == 0 ) {
 if ( * p == 0 ) {
 bNext = FALSE ;
 }
 else {
 * p = 0 ;
 }
 if ( pPriv != NULL ) {
 for ( i = 0 ;
 * ( pPriv + i ) != 0 ;
 i ++ ) {
 * ( pPriv + i ) = uprv_tolower ( * ( pPriv + i ) ) ;
 }
 if ( _isPrivateuseValueSubtag ( pPriv , - 1 ) ) {
 if ( firstValue ) {
 if ( ! _isVariantSubtag ( pPriv , - 1 ) ) {
 writeValue = TRUE ;
 }
 }
 else {
 writeValue = TRUE ;
 }
 }
 else if ( strict ) {
 * status = U_ILLEGAL_ARGUMENT_ERROR ;
 break ;
 }
 else {
 break ;
 }
 if ( writeValue ) {
 if ( reslen < capacity ) {
 tmpAppend [ reslen ++ ] = SEP ;
 }
 if ( firstValue ) {
 if ( reslen < capacity ) {
 tmpAppend [ reslen ++ ] = * PRIVATEUSE_KEY ;
 }
 if ( reslen < capacity ) {
 tmpAppend [ reslen ++ ] = SEP ;
 }
 len = ( int32_t ) uprv_strlen ( PRIVUSE_VARIANT_PREFIX ) ;
 if ( reslen < capacity ) {
 uprv_memcpy ( tmpAppend + reslen , PRIVUSE_VARIANT_PREFIX , uprv_min ( len , capacity - reslen ) ) ;
 }
 reslen += len ;
 if ( reslen < capacity ) {
 tmpAppend [ reslen ++ ] = SEP ;
 }
 firstValue = FALSE ;
 }
 len = ( int32_t ) uprv_strlen ( pPriv ) ;
 if ( reslen < capacity ) {
 uprv_memcpy ( tmpAppend + reslen , pPriv , uprv_min ( len , capacity - reslen ) ) ;
 }
 reslen += len ;
 }
 }
 pPriv = NULL ;
 }
 else if ( pPriv == NULL ) {
 pPriv = p ;
 }
 p ++ ;
 }
 if ( U_FAILURE ( * status ) ) {
 return 0 ;
 }
 }
 if ( U_SUCCESS ( * status ) ) {
 len = reslen ;
 if ( reslen < capacity ) {
 uprv_memcpy ( appendAt , tmpAppend , uprv_min ( len , capacity - reslen ) ) ;
 }
 }
 u_terminateChars ( appendAt , capacity , reslen , status ) ;
 return reslen ;
 }