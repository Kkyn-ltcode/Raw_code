static void qemu_cpu_kick_thread ( CPUState * cpu ) {
 # ifndef _WIN32 int err ;
 err = pthread_kill ( cpu -> thread -> thread , SIG_IPI ) ;
 if ( err ) {
 fprintf ( stderr , "qemu:%s: %s" , __func__ , strerror ( err ) ) ;
 exit ( 1 ) ;
 }
 # else if ( ! qemu_cpu_is_self ( cpu ) ) {
 CONTEXT tcgContext ;
 if ( SuspendThread ( cpu -> hThread ) == ( DWORD ) - 1 ) {
 fprintf ( stderr , "qemu:%s: GetLastError:%lu\n" , __func__ , GetLastError ( ) ) ;
 exit ( 1 ) ;
 }
 tcgContext . ContextFlags = CONTEXT_CONTROL ;
 while ( GetThreadContext ( cpu -> hThread , & tcgContext ) != 0 ) {
 continue ;
 }
 cpu_signal ( 0 ) ;
 if ( ResumeThread ( cpu -> hThread ) == ( DWORD ) - 1 ) {
 fprintf ( stderr , "qemu:%s: GetLastError:%lu\n" , __func__ , GetLastError ( ) ) ;
 exit ( 1 ) ;
 }
 }
 # endif }