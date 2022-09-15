void qmp_inject_nmi ( Error * * errp ) {
 # if defined ( TARGET_I386 ) CPUArchState * env ;
 for ( env = first_cpu ;
 env != NULL ;
 env = env -> next_cpu ) {
 if ( ! env -> apic_state ) {
 cpu_interrupt ( CPU ( x86_env_get_cpu ( env ) ) , CPU_INTERRUPT_NMI ) ;
 }
 else {
 apic_deliver_nmi ( env -> apic_state ) ;
 }
 }
 # else error_set ( errp , QERR_UNSUPPORTED ) ;
 # endif }