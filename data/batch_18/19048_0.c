IN_PROC_BROWSER_TEST_F ( MessageCenterNotificationsTest , ButtonClickedDelegate ) {
 # if defined ( OS_WIN ) && defined ( USE_ASH ) if ( base : : CommandLine : : ForCurrentProcess ( ) -> HasSwitch ( switches : : kAshBrowserTests ) ) return ;
 # endif TestDelegate * delegate ;
 manager ( ) -> Add ( CreateTestNotification ( "n" , & delegate ) , profile ( ) ) ;
 const std : : string notification_id = manager ( ) -> GetMessageCenterNotificationIdForTest ( "n" , profile ( ) ) ;
 message_center ( ) -> ClickOnNotificationButton ( notification_id , 1 ) ;
 EXPECT_EQ ( "Display_ButtonClick_1_" , delegate -> log ( ) ) ;
 delegate -> Release ( ) ;
 }