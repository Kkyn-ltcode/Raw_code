TEST_F ( ProcessUtilTest , MAYBE_GetTerminationStatusCrash ) {
 const std : : string signal_file = ProcessUtilTest : : GetSignalFilePath ( kSignalFileCrash ) ;
 remove ( signal_file . c_str ( ) ) ;
 base : : Process process = SpawnChild ( "CrashingChildProcess" ) ;
 ASSERT_TRUE ( process . IsValid ( ) ) ;
 int exit_code = 42 ;
 EXPECT_EQ ( base : : TERMINATION_STATUS_STILL_RUNNING , base : : GetTerminationStatus ( process . Handle ( ) , & exit_code ) ) ;
 EXPECT_EQ ( kExpectedStillRunningExitCode , exit_code ) ;
 SignalChildren ( signal_file . c_str ( ) ) ;
 exit_code = 42 ;
 base : : TerminationStatus status = WaitForChildTermination ( process . Handle ( ) , & exit_code ) ;
 EXPECT_EQ ( base : : TERMINATION_STATUS_PROCESS_CRASHED , status ) ;
 # if defined ( OS_WIN ) EXPECT_EQ ( 0xc0000005 , exit_code ) ;
 # elif defined ( OS_POSIX ) int signaled = WIFSIGNALED ( exit_code ) ;
 EXPECT_NE ( 0 , signaled ) ;
 int signal = WTERMSIG ( exit_code ) ;
 EXPECT_EQ ( SIGSEGV , signal ) ;
 # endif base : : debug : : EnableInProcessStackDumping ( ) ;
 remove ( signal_file . c_str ( ) ) ;
 }