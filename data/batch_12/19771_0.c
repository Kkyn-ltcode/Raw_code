static int setup_test ( const char * name ) {
 fprintf ( stdout , "%s" , name ) ;
 if ( evutil_socketpair ( AF_UNIX , SOCK_STREAM , 0 , pair ) == - 1 ) {
 fprintf ( stderr , "%s: socketpair\n" , __func__ ) ;
 exit ( 1 ) ;
 }
 # ifdef HAVE_FCNTL if ( fcntl ( pair [ 0 ] , F_SETFL , O_NONBLOCK ) == - 1 ) fprintf ( stderr , "fcntl(O_NONBLOCK)" ) ;
 if ( fcntl ( pair [ 1 ] , F_SETFL , O_NONBLOCK ) == - 1 ) fprintf ( stderr , "fcntl(O_NONBLOCK)" ) ;
 # endif test_ok = 0 ;
 called = 0 ;
 return ( 0 ) ;
 }