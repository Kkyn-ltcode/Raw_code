TEST_F ( ProtocolHandlerRegistryTest , TestIsSameOrigin ) {
 ProtocolHandler ph1 = CreateProtocolHandler ( "mailto" , GURL ( "http://test.com/%s" ) , "test1" ) ;
 ProtocolHandler ph2 = CreateProtocolHandler ( "mailto" , GURL ( "http://test.com/updated-url/%s" ) , "test2" ) ;
 ProtocolHandler ph3 = CreateProtocolHandler ( "mailto" , GURL ( "http://other.com/%s" ) , "test" ) ;
 ASSERT_EQ ( ph1 . url ( ) . GetOrigin ( ) == ph2 . url ( ) . GetOrigin ( ) , ph1 . IsSameOrigin ( ph2 ) ) ;
 ASSERT_EQ ( ph1 . url ( ) . GetOrigin ( ) == ph2 . url ( ) . GetOrigin ( ) , ph2 . IsSameOrigin ( ph1 ) ) ;
 ASSERT_EQ ( ph2 . url ( ) . GetOrigin ( ) == ph3 . url ( ) . GetOrigin ( ) , ph2 . IsSameOrigin ( ph3 ) ) ;
 ASSERT_EQ ( ph3 . url ( ) . GetOrigin ( ) == ph2 . url ( ) . GetOrigin ( ) , ph3 . IsSameOrigin ( ph2 ) ) ;
 }