IN_PROC_BROWSER_TEST_F ( PageLoadMetricsBrowserTest , PayloadSizeIgnoresDownloads ) {
 ASSERT_TRUE ( embedded_test_server ( ) -> Start ( ) ) ;
 bool prev_io_allowed = base : : ThreadRestrictions : : SetIOAllowed ( true ) ;
 {
 base : : ScopedTempDir downloads_directory ;
 ASSERT_TRUE ( downloads_directory . CreateUniqueTempDir ( ) ) ;
 browser ( ) -> profile ( ) -> GetPrefs ( ) -> SetFilePath ( prefs : : kDownloadDefaultDirectory , downloads_directory . GetPath ( ) ) ;
 content : : DownloadTestObserverTerminal downloads_observer ( content : : BrowserContext : : GetDownloadManager ( browser ( ) -> profile ( ) ) , 1 , content : : DownloadTestObserver : : ON_DANGEROUS_DOWNLOAD_FAIL ) ;
 ui_test_utils : : NavigateToURL ( browser ( ) , embedded_test_server ( ) -> GetURL ( "/page_load_metrics/download_anchor_click.html" ) ) ;
 downloads_observer . WaitForFinished ( ) ;
 }
 base : : ThreadRestrictions : : SetIOAllowed ( prev_io_allowed ) ;
 NavigateToUntrackedUrl ( ) ;
 histogram_tester_ . ExpectUniqueSample ( internal : : kHistogramPageLoadTotalBytes , 0 , 1 ) ;
 }