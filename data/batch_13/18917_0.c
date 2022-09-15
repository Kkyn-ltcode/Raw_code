TEST_F ( ImmersiveModeControllerAshTest , Layout ) {
 AddTab ( browser ( ) , GURL ( "about:blank" ) ) ;
 TabStrip * tabstrip = browser_view ( ) -> tabstrip ( ) ;
 ToolbarView * toolbar = browser_view ( ) -> toolbar ( ) ;
 views : : WebView * contents_web_view = browser_view ( ) -> GetContentsWebViewForTest ( ) ;
 ASSERT_FALSE ( browser_view ( ) -> GetWidget ( ) -> IsFullscreen ( ) ) ;
 ASSERT_FALSE ( controller ( ) -> IsEnabled ( ) ) ;
 EXPECT_TRUE ( tabstrip -> visible ( ) ) ;
 EXPECT_TRUE ( toolbar -> visible ( ) ) ;
 ToggleFullscreen ( ) ;
 EXPECT_TRUE ( browser_view ( ) -> GetWidget ( ) -> IsFullscreen ( ) ) ;
 EXPECT_TRUE ( controller ( ) -> IsEnabled ( ) ) ;
 EXPECT_FALSE ( controller ( ) -> IsRevealed ( ) ) ;
 EXPECT_TRUE ( tabstrip -> visible ( ) ) ;
 EXPECT_TRUE ( tabstrip -> IsImmersiveStyle ( ) ) ;
 EXPECT_FALSE ( toolbar -> visible ( ) ) ;
 EXPECT_EQ ( 0 , GetBoundsInWidget ( tabstrip ) . y ( ) ) ;
 EXPECT_EQ ( Tab : : GetImmersiveHeight ( ) , GetBoundsInWidget ( contents_web_view ) . y ( ) ) ;
 AttemptReveal ( ) ;
 EXPECT_TRUE ( controller ( ) -> IsRevealed ( ) ) ;
 EXPECT_TRUE ( tabstrip -> visible ( ) ) ;
 EXPECT_FALSE ( tabstrip -> IsImmersiveStyle ( ) ) ;
 EXPECT_TRUE ( toolbar -> visible ( ) ) ;
 EXPECT_EQ ( 0 , GetBoundsInWidget ( browser_view ( ) -> top_container ( ) ) . y ( ) ) ;
 EXPECT_EQ ( Tab : : GetImmersiveHeight ( ) , GetBoundsInWidget ( contents_web_view ) . y ( ) ) ;
 SetTabFullscreen ( true ) ;
 AttemptUnreveal ( ) ;
 AttemptReveal ( ) ;
 EXPECT_TRUE ( controller ( ) -> IsRevealed ( ) ) ;
 EXPECT_TRUE ( tabstrip -> visible ( ) ) ;
 EXPECT_FALSE ( tabstrip -> IsImmersiveStyle ( ) ) ;
 EXPECT_TRUE ( toolbar -> visible ( ) ) ;
 EXPECT_EQ ( 0 , GetBoundsInWidget ( browser_view ( ) -> top_container ( ) ) . y ( ) ) ;
 EXPECT_EQ ( 0 , GetBoundsInWidget ( contents_web_view ) . y ( ) ) ;
 AttemptUnreveal ( ) ;
 EXPECT_FALSE ( controller ( ) -> IsRevealed ( ) ) ;
 EXPECT_FALSE ( tabstrip -> visible ( ) ) ;
 EXPECT_FALSE ( toolbar -> visible ( ) ) ;
 EXPECT_EQ ( 0 , GetBoundsInWidget ( contents_web_view ) . y ( ) ) ;
 ToggleFullscreen ( ) ;
 EXPECT_FALSE ( browser_view ( ) -> GetWidget ( ) -> IsFullscreen ( ) ) ;
 EXPECT_FALSE ( controller ( ) -> IsEnabled ( ) ) ;
 EXPECT_FALSE ( controller ( ) -> IsRevealed ( ) ) ;
 EXPECT_TRUE ( tabstrip -> visible ( ) ) ;
 EXPECT_FALSE ( tabstrip -> IsImmersiveStyle ( ) ) ;
 EXPECT_TRUE ( toolbar -> visible ( ) ) ;
 }