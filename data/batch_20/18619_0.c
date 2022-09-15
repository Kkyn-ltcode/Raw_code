void xsltFreeLocales ( void ) {
 # ifdef XSLT_LOCALE_WINAPI xmlRMutexLock ( xsltLocaleMutex ) ;
 xmlFree ( xsltLocaleList ) ;
 xsltLocaleList = NULL ;
 xmlRMutexUnlock ( xsltLocaleMutex ) ;
 # endif }