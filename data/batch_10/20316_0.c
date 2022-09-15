IN_PROC_BROWSER_TEST_F ( AvatarMenuButtonTest , MAYBE_HideOnSecondClick ) {
 # if defined ( OS_WIN ) && defined ( USE_ASH ) if ( base : : CommandLine : : ForCurrentProcess ( ) -> HasSwitch ( switches : : kAshBrowserTests ) ) return ;
 # endif if ( ! profiles : : IsMultipleProfilesEnabled ( ) ) return ;
 CreateTestingProfile ( ) ;
 ASSERT_NO_FATAL_FAILURE ( StartAvatarMenu ( ) ) ;
 AvatarMenuButton * button = GetAvatarMenuButton ( ) ;
 static_cast < views : : MenuButtonListener * > ( button ) -> OnMenuButtonClicked ( NULL , gfx : : Point ( ) ) ;
 AvatarMenuBubbleView : : Hide ( ) ;
 base : : MessageLoop : : current ( ) -> RunUntilIdle ( ) ;
 EXPECT_FALSE ( AvatarMenuBubbleView : : IsShowing ( ) ) ;
 }