void qemu_cpu_kick_self ( void ) {
 # ifndef _WIN32 assert ( cpu_single_env ) ;
 CPUState * cpu_single_cpu = ENV_GET_CPU ( cpu_single_env ) ;
 if ( ! cpu_single_cpu -> thread_kicked ) {
 qemu_cpu_kick_thread ( cpu_single_cpu ) ;
 cpu_single_cpu -> thread_kicked = true ;
 }
 # else abort ( ) ;
 # endif }