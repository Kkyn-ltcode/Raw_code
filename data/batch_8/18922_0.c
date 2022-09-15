TEST_F ( FullscreenControllerStateUnitTest , CapturedFullscreenedTabTransferredBetweenBrowserWindows ) {
 content : : WebContentsDelegate * const wc_delegate = static_cast < content : : WebContentsDelegate * > ( browser ( ) ) ;
 ASSERT_TRUE ( wc_delegate -> EmbedsFullscreenWidget ( ) ) ;
 AddTab ( browser ( ) , GURL ( url : : kAboutBlankURL ) ) ;
 AddTab ( browser ( ) , GURL ( url : : kAboutBlankURL ) ) ;
 content : : WebContents * const tab = browser ( ) -> tab_strip_model ( ) -> GetWebContentsAt ( 0 ) ;
 browser ( ) -> tab_strip_model ( ) -> ActivateTabAt ( 0 , true ) ;
 const gfx : : Size kCaptureSize ( 1280 , 720 ) ;
 tab -> IncrementCapturerCount ( kCaptureSize ) ;
 ASSERT_FALSE ( browser ( ) -> window ( ) -> IsFullscreen ( ) ) ;
 ASSERT_FALSE ( wc_delegate -> IsFullscreenForTabOrPending ( tab ) ) ;
 ASSERT_FALSE ( GetFullscreenController ( ) -> IsWindowFullscreenForTabOrPending ( ) ) ;
 ASSERT_TRUE ( InvokeEvent ( TAB_FULLSCREEN_TRUE ) ) ;
 EXPECT_FALSE ( browser ( ) -> window ( ) -> IsFullscreen ( ) ) ;
 EXPECT_TRUE ( wc_delegate -> IsFullscreenForTabOrPending ( tab ) ) ;
 EXPECT_FALSE ( GetFullscreenController ( ) -> IsWindowFullscreenForTabOrPending ( ) ) ;
 const scoped_ptr < BrowserWindow > second_browser_window ( CreateBrowserWindow ( ) ) ;
 const scoped_ptr < Browser > second_browser ( CreateBrowser ( browser ( ) -> profile ( ) , browser ( ) -> type ( ) , false , browser ( ) -> host_desktop_type ( ) , second_browser_window . get ( ) ) ) ;
 AddTab ( second_browser . get ( ) , GURL ( url : : kAboutBlankURL ) ) ;
 content : : WebContentsDelegate * const second_wc_delegate = static_cast < content : : WebContentsDelegate * > ( second_browser . get ( ) ) ;
 browser ( ) -> tab_strip_model ( ) -> DetachWebContentsAt ( 0 ) ;
 second_browser -> tab_strip_model ( ) -> InsertWebContentsAt ( 0 , tab , TabStripModel : : ADD_ACTIVE ) ;
 EXPECT_FALSE ( browser ( ) -> window ( ) -> IsFullscreen ( ) ) ;
 EXPECT_FALSE ( second_browser -> window ( ) -> IsFullscreen ( ) ) ;
 EXPECT_TRUE ( wc_delegate -> IsFullscreenForTabOrPending ( tab ) ) ;
 EXPECT_TRUE ( second_wc_delegate -> IsFullscreenForTabOrPending ( tab ) ) ;
 EXPECT_FALSE ( GetFullscreenController ( ) -> IsWindowFullscreenForTabOrPending ( ) ) ;
 EXPECT_FALSE ( second_browser -> fullscreen_controller ( ) -> IsWindowFullscreenForTabOrPending ( ) ) ;
 second_browser -> tab_strip_model ( ) -> DetachWebContentsAt ( 0 ) ;
 browser ( ) -> tab_strip_model ( ) -> InsertWebContentsAt ( 0 , tab , TabStripModel : : ADD_ACTIVE ) ;
 EXPECT_FALSE ( browser ( ) -> window ( ) -> IsFullscreen ( ) ) ;
 EXPECT_FALSE ( second_browser -> window ( ) -> IsFullscreen ( ) ) ;
 EXPECT_TRUE ( wc_delegate -> IsFullscreenForTabOrPending ( tab ) ) ;
 EXPECT_TRUE ( second_wc_delegate -> IsFullscreenForTabOrPending ( tab ) ) ;
 EXPECT_FALSE ( GetFullscreenController ( ) -> IsWindowFullscreenForTabOrPending ( ) ) ;
 EXPECT_FALSE ( second_browser -> fullscreen_controller ( ) -> IsWindowFullscreenForTabOrPending ( ) ) ;
 ASSERT_TRUE ( InvokeEvent ( TAB_FULLSCREEN_FALSE ) ) ;
 EXPECT_FALSE ( browser ( ) -> window ( ) -> IsFullscreen ( ) ) ;
 EXPECT_FALSE ( wc_delegate -> IsFullscreenForTabOrPending ( tab ) ) ;
 EXPECT_FALSE ( second_wc_delegate -> IsFullscreenForTabOrPending ( tab ) ) ;
 EXPECT_FALSE ( GetFullscreenController ( ) -> IsWindowFullscreenForTabOrPending ( ) ) ;
 EXPECT_FALSE ( second_browser -> fullscreen_controller ( ) -> IsWindowFullscreenForTabOrPending ( ) ) ;
 second_browser -> tab_strip_model ( ) -> CloseAllTabs ( ) ;
 }