static bool qemu_in_vcpu_thread ( void ) {
 return current_cpu && qemu_cpu_is_self ( current_cpu ) ;
 }