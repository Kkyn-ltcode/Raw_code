IN_PROC_BROWSER_TEST_F ( SiteDetailsBrowserTest , ManyIframes ) {
 GURL abcdefghi_url = embedded_test_server ( ) -> GetURL ( "a.com" , "/cross_site_iframe_factory.html?a(b(a(b,c,d,e,f,g,h)),c,d,e,i(f))" ) ;
 ui_test_utils : : NavigateToURL ( browser ( ) , abcdefghi_url ) ;
 scoped_refptr < TestMemoryDetails > details = new TestMemoryDetails ( ) ;
 details -> StartFetchAndWait ( ) ;
 EXPECT_EQ ( 1U , details -> CountPageTitles ( ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.BrowsingInstanceCount" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.CurrentRendererProcessCount" ) , HasOneSample ( GetRenderProcessCount ( ) ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateNothingProcessCountEstimate" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountEstimate" ) , HasOneSample ( 9 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountLowerBound" ) , HasOneSample ( 9 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountNoLimit" ) , HasOneSample ( 9 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateHttpsSitesProcessCountEstimate" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateHttpsSitesProcessCountLowerBound" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateHttpsSitesProcessCountNoLimit" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountEstimate" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountLowerBound" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountNoLimit" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( GetRenderProcessCount ( ) , DependingOnPolicy ( 1 , 1 , 9 ) ) ;
 EXPECT_THAT ( details -> GetOutOfProcessIframeCount ( ) , DependingOnPolicy ( 0 , 0 , 14 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.ProxyCount" ) , HasOneSample ( DependingOnPolicy ( 0 , 0 , 114 ) ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.ProxyCountPerBrowsingInstance" ) , HasOneSample ( DependingOnPolicy ( 0 , 0 , 114 ) ) ) ;
 GURL pqrstuv_url = embedded_test_server ( ) -> GetURL ( "p.com" , "/cross_site_iframe_factory.html?p(q(r),r(s),s(t),t(q),u(u),v(p))" ) ;
 ui_test_utils : : NavigateToURL ( browser ( ) , pqrstuv_url ) ;
 details = new TestMemoryDetails ( ) ;
 details -> StartFetchAndWait ( ) ;
 EXPECT_EQ ( 1U , details -> CountPageTitles ( ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.BrowsingInstanceCount" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.CurrentRendererProcessCount" ) , HasOneSample ( GetRenderProcessCount ( ) ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateNothingProcessCountEstimate" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountEstimate" ) , HasOneSample ( 7 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountLowerBound" ) , HasOneSample ( 7 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountNoLimit" ) , HasOneSample ( 7 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateHttpsSitesProcessCountEstimate" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateHttpsSitesProcessCountLowerBound" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateHttpsSitesProcessCountNoLimit" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountEstimate" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountLowerBound" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountNoLimit" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( GetRenderProcessCount ( ) , DependingOnPolicy ( 1 , 1 , 7 ) ) ;
 EXPECT_THAT ( details -> GetOutOfProcessIframeCount ( ) , DependingOnPolicy ( 0 , 0 , 11 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.ProxyCount" ) , HasOneSample ( DependingOnPolicy ( 0 , 0 , 68 ) ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.ProxyCountPerBrowsingInstance" ) , HasOneSample ( DependingOnPolicy ( 0 , 0 , 68 ) ) ) ;
 GURL abcd_url = embedded_test_server ( ) -> GetURL ( "a.com" , "/cross_site_iframe_factory.html?a(b(c(d())))" ) ;
 AddTabAtIndex ( 1 , abcd_url , ui : : PAGE_TRANSITION_TYPED ) ;
 details = new TestMemoryDetails ( ) ;
 details -> StartFetchAndWait ( ) ;
 EXPECT_EQ ( 2U , details -> CountPageTitles ( ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.BrowsingInstanceCount" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.CurrentRendererProcessCount" ) , HasOneSample ( GetRenderProcessCount ( ) ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateNothingProcessCountEstimate" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountEstimate" ) , HasOneSample ( 11 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountLowerBound" ) , HasOneSample ( 11 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountNoLimit" ) , HasOneSample ( 11 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateHttpsSitesProcessCountEstimate" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateHttpsSitesProcessCountLowerBound" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateHttpsSitesProcessCountNoLimit" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountEstimate" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountLowerBound" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountNoLimit" ) , HasOneSample ( 2 ) ) ;
 EXPECT_THAT ( GetRenderProcessCount ( ) , DependingOnPolicy ( 2 , 2 , 11 ) ) ;
 EXPECT_THAT ( details -> GetOutOfProcessIframeCount ( ) , DependingOnPolicy ( 0 , 0 , 14 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.ProxyCount" ) , HasOneSample ( DependingOnPolicy ( 0 , 0 , 81 ) ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.ProxyCountPerBrowsingInstance" ) , DependingOnPolicy ( ElementsAre ( Bucket ( 0 , 2 ) ) , ElementsAre ( Bucket ( 0 , 2 ) ) , ElementsAre ( Bucket ( 12 , 1 ) , Bucket ( 68 , 1 ) ) ) ) ;
 AddTabAtIndex ( 2 , abcd_url , ui : : PAGE_TRANSITION_TYPED ) ;
 details = new TestMemoryDetails ( ) ;
 details -> StartFetchAndWait ( ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.BrowsingInstanceCount" ) , HasOneSample ( 3 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.CurrentRendererProcessCount" ) , HasOneSample ( GetRenderProcessCount ( ) ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateNothingProcessCountEstimate" ) , HasOneSample ( 3 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountEstimate" ) , HasOneSample ( 15 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountLowerBound" ) , HasOneSample ( 11 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountNoLimit" ) , HasOneSample ( 15 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateHttpsSitesProcessCountEstimate" ) , HasOneSample ( 3 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateHttpsSitesProcessCountLowerBound" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateHttpsSitesProcessCountNoLimit" ) , HasOneSample ( 3 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountEstimate" ) , HasOneSample ( 3 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountLowerBound" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountNoLimit" ) , HasOneSample ( 3 ) ) ;
 EXPECT_THAT ( GetRenderProcessCount ( ) , DependingOnPolicy ( 3 , 3 , 12 ) ) ;
 EXPECT_THAT ( details -> GetOutOfProcessIframeCount ( ) , DependingOnPolicy ( 0 , 0 , 17 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.ProxyCount" ) , HasOneSample ( DependingOnPolicy ( 0 , 0 , 96 ) ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.ProxyCountPerBrowsingInstance" ) , DependingOnPolicy ( ElementsAre ( Bucket ( 0 , 3 ) ) , ElementsAre ( Bucket ( 0 , 3 ) ) , ElementsAre ( Bucket ( 12 , 2 ) , Bucket ( 68 , 1 ) ) ) ) ;
 GURL dcbae_url = embedded_test_server ( ) -> GetURL ( "a.com" , "/cross_site_iframe_factory.html?d(c(b(a(e))))" ) ;
 ui_test_utils : : UrlLoadObserver load_complete ( dcbae_url , content : : NotificationService : : AllSources ( ) ) ;
 ASSERT_EQ ( 3 , browser ( ) -> tab_strip_model ( ) -> count ( ) ) ;
 ASSERT_TRUE ( content : : ExecuteScript ( browser ( ) -> tab_strip_model ( ) -> GetActiveWebContents ( ) , "window.open('" + dcbae_url . spec ( ) + "');
" ) ) ;
 ASSERT_EQ ( 4 , browser ( ) -> tab_strip_model ( ) -> count ( ) ) ;
 load_complete . Wait ( ) ;
 details = new TestMemoryDetails ( ) ;
 details -> StartFetchAndWait ( ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.BrowsingInstanceCount" ) , HasOneSample ( 3 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.CurrentRendererProcessCount" ) , HasOneSample ( GetRenderProcessCount ( ) ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateNothingProcessCountEstimate" ) , HasOneSample ( 3 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountEstimate" ) , HasOneSample ( 16 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountLowerBound" ) , HasOneSample ( 12 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateAllSitesProcessCountNoLimit" ) , HasOneSample ( 16 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateHttpsSitesProcessCountEstimate" ) , HasOneSample ( 3 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateHttpsSitesProcessCountLowerBound" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateHttpsSitesProcessCountNoLimit" ) , HasOneSample ( 3 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountEstimate" ) , HasOneSample ( 3 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountLowerBound" ) , HasOneSample ( 1 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.IsolateExtensionsProcessCountNoLimit" ) , HasOneSample ( 3 ) ) ;
 EXPECT_THAT ( GetRenderProcessCount ( ) , DependingOnPolicy ( 3 , 3 , 13 ) ) ;
 EXPECT_THAT ( details -> GetOutOfProcessIframeCount ( ) , DependingOnPolicy ( 0 , 0 , 21 ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.ProxyCount" ) , HasOneSample ( DependingOnPolicy ( 0 , 0 , 114 ) ) ) ;
 EXPECT_THAT ( details -> uma ( ) -> GetAllSamples ( "SiteIsolation.ProxyCountPerBrowsingInstance" ) , DependingOnPolicy ( ElementsAre ( Bucket ( 0 , 3 ) ) , ElementsAre ( Bucket ( 0 , 3 ) ) , ElementsAre ( Bucket ( 12 , 1 ) , Bucket ( 29 , 1 ) , Bucket ( 68 , 1 ) ) ) ) ;
 }