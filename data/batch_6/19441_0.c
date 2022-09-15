MULTIPROCESS_TEST_MAIN ( KilledChildProcess ) {
 WaitToDie ( ProcessUtilTest : : GetSignalFilePath ( kSignalFileKill ) . c_str ( ) ) ;
 # if defined ( OS_WIN ) HANDLE handle = : : OpenProcess ( PROCESS_ALL_ACCESS , 0 , : : GetCurrentProcessId ( ) ) ;
 : : TerminateProcess ( handle , kExpectedKilledExitCode ) ;
 # elif defined ( OS_POSIX ) : : kill ( getpid ( ) , SIGKILL ) ;
 # endif return 1 ;
 }