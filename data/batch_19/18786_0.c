TEST_F ( WebFrameTest , GetCanonicalUrlForSharingNotInHead ) {
 FrameTestHelpers : : WebViewHelper web_view_helper ;
 web_view_helper . Initialize ( ) ;
 WebLocalFrameImpl * frame = web_view_helper . LocalMainFrame ( ) ;
 FrameTestHelpers : : LoadHTMLString ( frame , R "( < body > < link rel = "canonical" href = "https://example.com/canonical.html" > < / body > ) ", ToKURL(" https : EXPECT_TRUE ( frame -> GetDocument ( ) . CanonicalUrlForSharing ( ) . IsNull ( ) ) ;
 }