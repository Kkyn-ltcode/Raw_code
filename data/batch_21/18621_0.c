int xsltLocaleStrcmp ( xsltLocale locale , const xsltLocaleChar * str1 , const xsltLocaleChar * str2 ) {
 ( void ) locale ;
 # ifdef XSLT_LOCALE_WINAPI {
 int ret ;
 if ( str1 == str2 ) return ( 0 ) ;
 if ( str1 == NULL ) return ( - 1 ) ;
 if ( str2 == NULL ) return ( 1 ) ;
 ret = CompareStringW ( locale , 0 , str1 , - 1 , str2 , - 1 ) ;
 if ( ret == 0 ) {
 xsltTransformError ( NULL , NULL , NULL , "xsltLocaleStrcmp : CompareStringW fail\n" ) ;
 return ( 0 ) ;
 }
 return ( ret - 2 ) ;
 }
 # else return ( xmlStrcmp ( str1 , str2 ) ) ;
 # endif }