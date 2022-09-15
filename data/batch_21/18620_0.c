xsltLocaleChar * xsltStrxfrm ( xsltLocale locale , const xmlChar * string ) {
 # ifdef XSLT_LOCALE_NONE return ( NULL ) ;
 # else size_t xstrlen , r ;
 xsltLocaleChar * xstr ;
 # ifdef XSLT_LOCALE_XLOCALE xstrlen = strxfrm_l ( NULL , ( const char * ) string , 0 , locale ) + 1 ;
 xstr = ( xsltLocaleChar * ) xmlMalloc ( xstrlen ) ;
 if ( xstr == NULL ) {
 xsltTransformError ( NULL , NULL , NULL , "xsltStrxfrm : out of memory error\n" ) ;
 return ( NULL ) ;
 }
 r = strxfrm_l ( ( char * ) xstr , ( const char * ) string , xstrlen , locale ) ;
 # endif # ifdef XSLT_LOCALE_WINAPI xstrlen = MultiByteToWideChar ( CP_UTF8 , 0 , string , - 1 , NULL , 0 ) ;
 if ( xstrlen == 0 ) {
 xsltTransformError ( NULL , NULL , NULL , "xsltStrxfrm : MultiByteToWideChar check failed\n" ) ;
 return ( NULL ) ;
 }
 xstr = ( xsltLocaleChar * ) xmlMalloc ( xstrlen * sizeof ( xsltLocaleChar ) ) ;
 if ( xstr == NULL ) {
 xsltTransformError ( NULL , NULL , NULL , "xsltStrxfrm : out of memory\n" ) ;
 return ( NULL ) ;
 }
 r = MultiByteToWideChar ( CP_UTF8 , 0 , string , - 1 , xstr , xstrlen ) ;
 if ( r == 0 ) {
 xsltTransformError ( NULL , NULL , NULL , "xsltStrxfrm : MultiByteToWideChar failed\n" ) ;
 xmlFree ( xstr ) ;
 return ( NULL ) ;
 }
 return ( xstr ) ;
 # endif if ( r >= xstrlen ) {
 xsltTransformError ( NULL , NULL , NULL , "xsltStrxfrm : strxfrm failed\n" ) ;
 xmlFree ( xstr ) ;
 return ( NULL ) ;
 }
 return ( xstr ) ;
 # endif }