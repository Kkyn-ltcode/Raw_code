TEST_F ( FullscreenControllerStateUnitTest , OneCapturedFullscreenedTab ) {
 content : : WebContentsDelegate * const wc_delegate = static_cast < content : : WebContentsDelegate * > ( browser ( ) ) ;
 ASSERT_TRUE ( wc_delegate -> EmbedsFullscreenWidget ( ) ) ;
 AddTab ( browser ( ) , GURL ( url : : kAboutBlankURL ) ) ;
 AddTab ( browser ( ) , GURL ( url : : kAboutBlankURL ) ) ;
 content : : WebContents * const first_tab = browser ( ) -> tab_strip_model ( ) -> GetWebContentsAt ( 0 ) ;
 content : : WebContents * const second_tab = browser ( ) -> tab_strip_model ( ) -> GetWebContentsAt ( 1 ) ;
 browser ( ) -> tab_strip_model ( ) -> ActivateTabAt ( 0 , true ) ;
 const gfx : : Size kCaptureSize ( 1280 , 720 ) ;
 first_tab -> IncrementCapturerCount ( kCaptureSize ) ;
 ASSERT_FALSE ( browser ( ) -> window ( ) -> IsFullscreen ( ) ) ;
 ASSERT_FALSE ( wc_delegate -> IsFullscreenForTabOrPending ( first_tab ) ) ;
 ASSERT_FALSE ( wc_delegate -> IsFullscreenForTabOrPending ( second_tab ) ) ;
 ASSERT_FALSE ( GetFullscreenController ( ) -> IsWindowFullscreenForTabOrPending ( ) ) ;
 ASSERT_TRUE ( InvokeEvent ( TAB_FULLSCREEN_TRUE ) ) ;
 EXPECT_FALSE ( browser ( ) -> window ( ) -> IsFullscreen ( ) ) ;
 EXPECT_TRUE ( wc_delegate -> IsFullscreenForTabOrPending ( first_tab ) ) ;
 EXPECT_FALSE ( wc_delegate -> IsFullscreenForTabOrPending ( second_tab ) ) ;
 EXPECT_FALSE ( GetFullscreenController ( ) -> IsWindowFullscreenForTabOrPending ( ) ) ;
 browser ( ) -> tab_strip_model ( ) -> ActivateTabAt ( 1 , true ) ;
 EXPECT_FALSE ( browser ( ) -> window ( ) -> IsFullscreen ( ) ) ;
 EXPECT_TRUE ( wc_delegate -> IsFullscreenForTabOrPending ( first_tab ) ) ;
 EXPECT_FALSE ( wc_delegate -> IsFullscreenForTabOrPending ( second_tab ) ) ;
 EXPECT_FALSE ( GetFullscreenController ( ) -> IsWindowFullscreenForTabOrPending ( ) ) ;
 # if ! defined ( OS_MACOSX ) EXPECT_EQ ( kCaptureSize , first_tab -> GetViewBounds ( ) . size ( ) ) ;
 # endif browser ( ) -> tab_strip_model ( ) -> ActivateTabAt ( 0 , true ) ;
 EXPECT_FALSE ( browser ( ) -> window ( ) -> IsFullscreen ( ) ) ;
 EXPECT_TRUE ( wc_delegate -> IsFullscreenForTabOrPending ( first_tab ) ) ;
 EXPECT_FALSE ( wc_delegate -> IsFullscreenForTabOrPending ( second_tab ) ) ;
 EXPECT_FALSE ( GetFullscreenController ( ) -> IsWindowFullscreenForTabOrPending ( ) ) ;
 ASSERT_TRUE ( InvokeEvent ( TAB_FULLSCREEN_FALSE ) ) ;
 EXPECT_FALSE ( browser ( ) -> window ( ) -> IsFullscreen ( ) ) ;
 EXPECT_FALSE ( wc_delegate -> IsFullscreenForTabOrPending ( first_tab ) ) ;
 EXPECT_FALSE ( wc_delegate -> IsFullscreenForTabOrPending ( second_tab ) ) ;
 EXPECT_FALSE ( GetFullscreenController ( ) -> IsWindowFullscreenForTabOrPending ( ) ) ;
 }