static bool qemu_in_vcpu_thread ( void ) {
 return cpu_single_env && qemu_cpu_is_self ( ENV_GET_CPU ( cpu_single_env ) ) ;
 }