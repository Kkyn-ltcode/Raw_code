static void Type_ColorantOrderType_Free ( struct _cms_typehandler_struct * self , void * Ptr ) {
 _cmsFree ( self -> ContextID , Ptr ) ;
 }