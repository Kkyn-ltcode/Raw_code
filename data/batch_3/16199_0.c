void vmmouse_set_data ( const uint32_t * data ) {
 X86CPU * cpu = X86_CPU ( current_cpu ) ;
 CPUX86State * env = & cpu -> env ;
 env -> regs [ R_EAX ] = data [ 0 ] ;
 env -> regs [ R_EBX ] = data [ 1 ] ;
 env -> regs [ R_ECX ] = data [ 2 ] ;
 env -> regs [ R_EDX ] = data [ 3 ] ;
 env -> regs [ R_ESI ] = data [ 4 ] ;
 env -> regs [ R_EDI ] = data [ 5 ] ;
 }