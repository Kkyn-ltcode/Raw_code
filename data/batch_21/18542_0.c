static debugCBContext * debugCB_clone ( debugCBContext * ctx ) {
 debugCBContext * newCtx ;
 newCtx = malloc ( sizeof ( debugCBContext ) ) ;
 newCtx -> serial = debugCB_nextSerial ( ) ;
 newCtx -> magic = 0xC0FFEE ;
 newCtx -> subCallback = ctx -> subCallback ;
 newCtx -> subContext = ctx -> subContext ;
 # if DEBUG_TMI printf ( "debugCB_clone: %p:%d -> new context %p:%d\n" , ctx , ctx -> serial , newCtx , newCtx -> serial ) ;
 # endif return newCtx ;
 }