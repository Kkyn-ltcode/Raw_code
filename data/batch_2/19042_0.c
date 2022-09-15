IN_PROC_BROWSER_TEST_F ( MessageCenterNotificationsTest , UpdateExistingNotification ) {
 # if defined ( OS_WIN ) && defined ( USE_ASH ) if ( base : : CommandLine : : ForCurrentProcess ( ) -> HasSwitch ( switches : : kAshBrowserTests ) ) return ;
 # endif TestDelegate * delegate ;
 manager ( ) -> Add ( CreateTestNotification ( "n" , & delegate ) , profile ( ) ) ;
 TestDelegate * delegate2 ;
 manager ( ) -> Add ( CreateRichTestNotification ( "n" , & delegate2 ) , profile ( ) ) ;
 manager ( ) -> CancelById ( "n" , NotificationUIManager : : GetProfileID ( profile ( ) ) ) ;
 EXPECT_EQ ( "Display_" , delegate -> log ( ) ) ;
 EXPECT_EQ ( "Close_programmatically_" , delegate2 -> log ( ) ) ;
 delegate -> Release ( ) ;
 delegate2 -> Release ( ) ;
 }