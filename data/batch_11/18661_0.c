void xsltFreeStyleDocuments ( xsltStylesheetPtr style ) {
 xsltDocumentPtr doc , cur ;
 # ifdef XSLT_REFACTORED_XSLT_NSCOMP xsltNsMapPtr nsMap ;
 # endif if ( style == NULL ) return ;
 # ifdef XSLT_REFACTORED_XSLT_NSCOMP if ( XSLT_HAS_INTERNAL_NSMAP ( style ) ) nsMap = XSLT_GET_INTERNAL_NSMAP ( style ) ;
 else nsMap = NULL ;
 # endif cur = style -> docList ;
 while ( cur != NULL ) {
 doc = cur ;
 cur = cur -> next ;
 # ifdef XSLT_REFACTORED_XSLT_NSCOMP if ( nsMap ) xsltRestoreDocumentNamespaces ( nsMap , doc -> doc ) ;
 # endif xsltFreeDocumentKeys ( doc ) ;
 if ( ! doc -> main ) xmlFreeDoc ( doc -> doc ) ;
 xmlFree ( doc ) ;
 }
 }