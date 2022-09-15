int xsltEvalXPathPredicate ( xsltTransformContextPtr ctxt , xmlXPathCompExprPtr comp , xmlNsPtr * nsList , int nsNr ) {
 int ret ;
 xmlXPathObjectPtr res ;
 int oldNsNr ;
 xmlNsPtr * oldNamespaces ;
 xmlNodePtr oldInst ;
 int oldProximityPosition , oldContextSize ;
 oldContextSize = ctxt -> xpathCtxt -> contextSize ;
 oldProximityPosition = ctxt -> xpathCtxt -> proximityPosition ;
 oldNsNr = ctxt -> xpathCtxt -> nsNr ;
 oldNamespaces = ctxt -> xpathCtxt -> namespaces ;
 oldInst = ctxt -> inst ;
 ctxt -> xpathCtxt -> node = ctxt -> node ;
 ctxt -> xpathCtxt -> namespaces = nsList ;
 ctxt -> xpathCtxt -> nsNr = nsNr ;
 res = xmlXPathCompiledEval ( comp , ctxt -> xpathCtxt ) ;
 if ( res != NULL ) {
 ret = xmlXPathEvalPredicate ( ctxt -> xpathCtxt , res ) ;
 xmlXPathFreeObject ( res ) ;
 # ifdef WITH_XSLT_DEBUG_TEMPLATES XSLT_TRACE ( ctxt , XSLT_TRACE_TEMPLATES , xsltGenericDebug ( xsltGenericDebugContext , "xsltEvalXPathPredicate: returns %d\n" , ret ) ) ;
 # endif }
 else {
 # ifdef WITH_XSLT_DEBUG_TEMPLATES XSLT_TRACE ( ctxt , XSLT_TRACE_TEMPLATES , xsltGenericDebug ( xsltGenericDebugContext , "xsltEvalXPathPredicate: failed\n" ) ) ;
 # endif ctxt -> state = XSLT_STATE_STOPPED ;
 ret = 0 ;
 }
 ctxt -> xpathCtxt -> nsNr = oldNsNr ;
 ctxt -> xpathCtxt -> namespaces = oldNamespaces ;
 ctxt -> inst = oldInst ;
 ctxt -> xpathCtxt -> contextSize = oldContextSize ;
 ctxt -> xpathCtxt -> proximityPosition = oldProximityPosition ;
 return ( ret ) ;
 }