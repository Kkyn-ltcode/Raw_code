static int get_current_cpu ( void ) {
 if ( ! current_cpu ) {
 return - 1 ;
 }
 return current_cpu -> cpu_index ;
 }