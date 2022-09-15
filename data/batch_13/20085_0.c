int main ( int argc , char * * argv ) {
 struct event evfifo ;
 # ifdef WIN32 HANDLE socket ;
 socket = CreateFileA ( "test.txt" , GENERIC_READ , 0 , NULL , OPEN_EXISTING , FILE_ATTRIBUTE_NORMAL , NULL ) ;
 if ( socket == INVALID_HANDLE_VALUE ) return 1 ;
 # else struct stat st ;
 const char * fifo = "event.fifo" ;
 int socket ;
 if ( lstat ( fifo , & st ) == 0 ) {
 if ( ( st . st_mode & S_IFMT ) == S_IFREG ) {
 errno = EEXIST ;
 perror ( "lstat" ) ;
 exit ( 1 ) ;
 }
 }
 unlink ( fifo ) ;
 if ( mkfifo ( fifo , 0600 ) == - 1 ) {
 perror ( "mkfifo" ) ;
 exit ( 1 ) ;
 }
 # ifdef __linux socket = open ( fifo , O_RDWR | O_NONBLOCK , 0 ) ;
 # else socket = open ( fifo , O_RDONLY | O_NONBLOCK , 0 ) ;
 # endif if ( socket == - 1 ) {
 perror ( "open" ) ;
 exit ( 1 ) ;
 }
 fprintf ( stderr , "Write data to %s\n" , fifo ) ;
 # endif event_init ( ) ;
 # ifdef WIN32 event_set ( & evfifo , ( int ) socket , EV_READ , fifo_read , & evfifo ) ;
 # else event_set ( & evfifo , socket , EV_READ , fifo_read , & evfifo ) ;
 # endif event_add ( & evfifo , NULL ) ;
 event_dispatch ( ) ;
 # ifdef WIN32 CloseHandle ( socket ) ;
 # endif return ( 0 ) ;
 }