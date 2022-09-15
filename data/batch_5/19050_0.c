IN_PROC_BROWSER_TEST_F ( MessageCenterNotificationsTest , BasicAddCancel ) {
 # if defined ( OS_WIN ) && defined ( USE_ASH ) if ( base : : CommandLine : : ForCurrentProcess ( ) -> HasSwitch ( switches : : kAshBrowserTests ) ) return ;
 # endif manager ( ) -> CancelAll ( ) ;
 manager ( ) -> Add ( CreateTestNotification ( "hey" ) , profile ( ) ) ;
 EXPECT_EQ ( 1u , message_center ( ) -> NotificationCount ( ) ) ;
 manager ( ) -> CancelById ( "hey" , NotificationUIManager : : GetProfileID ( profile ( ) ) ) ;
 EXPECT_EQ ( 0u , message_center ( ) -> NotificationCount ( ) ) ;
 }