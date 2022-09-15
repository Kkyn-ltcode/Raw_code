IN_PROC_BROWSER_TEST_F ( SiteDetailsBrowserTest , IsolateExtensionsHostedApps ) {
 GURL app_with_web_iframe_url = embedded_test_server ( ) -> GetURL ( "app.org" , "/cross_site_iframe_factory.html?app.org(b.com)" ) ;
 GURL app_in_web_iframe_url = embedded_test_server ( ) -> GetURL ( "b.com" , "/cross_site_iframe_factory.html?b.com(app.org)" ) ;
 ui_test_utils : : NavigateToURL ( browser ( ) , app_with_web_iframe_url ) ;
 scoped_refptr < TestMemoryDetails > details = new TestMemoryDetails ( ) ;
 details -> StartFetchAndWait ( ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.CurrentRendererProcessCount" ) , HasOneSample ( GetRenderProcessCount ( ) ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateNothingProcessCountEstimate" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountEstimate" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountLowerBound" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountNoLimit" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( GetRenderProcessCount ( ) , DependingOnPolicy ( 1 , 1 , 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountEstimate" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountLowerBound" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountNoLimit" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( GetRenderProcessCount ( ) , DependingOnPolicy ( 1 , 1 , 2 ) ) ;
 EXPECT_THAT ( details -> GetOutOfProcessIframeCount ( ) , DependingOnPolicy ( 0 , 0 , 1 ) ) ;
 ui_test_utils : : NavigateToURL ( browser ( ) , app_in_web_iframe_url ) ;
 details = new TestMemoryDetails ( ) ;
 details -> StartFetchAndWait ( ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.CurrentRendererProcessCount" ) , HasOneSample ( GetRenderProcessCount ( ) ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateNothingProcessCountEstimate" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountEstimate" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountLowerBound" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountNoLimit" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( GetRenderProcessCount ( ) , DependingOnPolicy ( 1 , 1 , 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountEstimate" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountLowerBound" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountNoLimit" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( GetRenderProcessCount ( ) , DependingOnPolicy ( 1 , 1 , 2 ) ) ;
 EXPECT_THAT ( details -> GetOutOfProcessIframeCount ( ) , DependingOnPolicy ( 0 , 0 , 1 ) ) ;
 CreateHostedApp ( "App" , GURL ( "http://app.org" ) ) ;
 ui_test_utils : : NavigateToURL ( browser ( ) , app_with_web_iframe_url ) ;
 details = new TestMemoryDetails ( ) ;
 details -> StartFetchAndWait ( ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.CurrentRendererProcessCount" ) , HasOneSample ( GetRenderProcessCount ( ) ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateNothingProcessCountEstimate" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountEstimate" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountLowerBound" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountNoLimit" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( GetRenderProcessCount ( ) , DependingOnPolicy ( 1 , 1 , 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountEstimate" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountLowerBound" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountNoLimit" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( GetRenderProcessCount ( ) , DependingOnPolicy ( 1 , 1 , 2 ) ) ;
 EXPECT_THAT ( details -> GetOutOfProcessIframeCount ( ) , DependingOnPolicy ( 0 , 0 , 1 ) ) ;
 ui_test_utils : : NavigateToURL ( browser ( ) , app_in_web_iframe_url ) ;
 details = new TestMemoryDetails ( ) ;
 details -> StartFetchAndWait ( ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.CurrentRendererProcessCount" ) , HasOneSample ( GetRenderProcessCount ( ) ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateNothingProcessCountEstimate" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountEstimate" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountLowerBound" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountNoLimit" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( GetRenderProcessCount ( ) , DependingOnPolicy ( 1 , 1 , 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountEstimate" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountLowerBound" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountNoLimit" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( GetRenderProcessCount ( ) , DependingOnPolicy ( 1 , 1 , 2 ) ) ;
 EXPECT_THAT ( details -> GetOutOfProcessIframeCount ( ) , DependingOnPolicy ( 0 , 0 , 1 ) ) ;
 }