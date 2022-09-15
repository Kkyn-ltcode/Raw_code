void qemu_cpu_kick_self ( void ) {
 # ifndef _WIN32 assert ( current_cpu ) ;
 if ( ! current_cpu -> thread_kicked ) {
 qemu_cpu_kick_thread ( current_cpu ) ;
 current_cpu -> thread_kicked = true ;
 }
 # else abort ( ) ;
 # endif }