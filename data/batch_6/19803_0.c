static int cleanup_test ( void ) {
 # ifndef WIN32 close ( pair [ 0 ] ) ;
 close ( pair [ 1 ] ) ;
 # else CloseHandle ( ( HANDLE ) pair [ 0 ] ) ;
 CloseHandle ( ( HANDLE ) pair [ 1 ] ) ;
 # endif if ( test_ok ) fprintf ( stdout , "OK\n" ) ;
 else {
 fprintf ( stdout , "FAILED\n" ) ;
 exit ( 1 ) ;
 }
 test_ok = 0 ;
 return ( 0 ) ;
 }