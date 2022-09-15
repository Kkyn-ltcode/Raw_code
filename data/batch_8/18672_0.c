void xsltRegisterAllExtras ( void ) {
 xsltRegisterExtModuleFunction ( ( const xmlChar * ) "node-set" , XSLT_LIBXSLT_NAMESPACE , xsltFunctionNodeSet ) ;
 xsltRegisterExtModuleFunction ( ( const xmlChar * ) "node-set" , XSLT_SAXON_NAMESPACE , xsltFunctionNodeSet ) ;
 xsltRegisterExtModuleFunction ( ( const xmlChar * ) "node-set" , XSLT_XT_NAMESPACE , xsltFunctionNodeSet ) ;
 # ifdef WITH_LOCALTIME xsltRegisterExtModuleFunction ( ( const xmlChar * ) "localTime" , XSLT_NORM_SAXON_NAMESPACE , xsltFunctionLocalTime ) ;
 # endif xsltRegisterExtModuleElement ( ( const xmlChar * ) "debug" , XSLT_LIBXSLT_NAMESPACE , NULL , ( xsltTransformFunction ) xsltDebug ) ;
 xsltRegisterExtModuleElement ( ( const xmlChar * ) "output" , XSLT_SAXON_NAMESPACE , xsltDocumentComp , ( xsltTransformFunction ) xsltDocumentElem ) ;
 xsltRegisterExtModuleElement ( ( const xmlChar * ) "write" , XSLT_XALAN_NAMESPACE , xsltDocumentComp , ( xsltTransformFunction ) xsltDocumentElem ) ;
 xsltRegisterExtModuleElement ( ( const xmlChar * ) "document" , XSLT_XT_NAMESPACE , xsltDocumentComp , ( xsltTransformFunction ) xsltDocumentElem ) ;
 xsltRegisterExtModuleElement ( ( const xmlChar * ) "document" , XSLT_NAMESPACE , xsltDocumentComp , ( xsltTransformFunction ) xsltDocumentElem ) ;
 }