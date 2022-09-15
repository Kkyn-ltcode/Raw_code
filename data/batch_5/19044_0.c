IN_PROC_BROWSER_TEST_F ( MessageCenterNotificationsTest , BasicDelegate ) {
 # if defined ( OS_WIN ) && defined ( USE_ASH ) if ( base : : CommandLine : : ForCurrentProcess ( ) -> HasSwitch ( switches : : kAshBrowserTests ) ) return ;
 # endif TestDelegate * delegate ;
 manager ( ) -> Add ( CreateTestNotification ( "hey" , & delegate ) , profile ( ) ) ;
 EXPECT_EQ ( "Display_" , delegate -> log ( ) ) ;
 manager ( ) -> CancelById ( "hey" , NotificationUIManager : : GetProfileID ( profile ( ) ) ) ;
 EXPECT_EQ ( "Display_Close_programmatically_" , delegate -> log ( ) ) ;
 delegate -> Release ( ) ;
 }