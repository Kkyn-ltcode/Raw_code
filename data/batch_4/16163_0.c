int cpu_signal_handler ( int host_signum , void * pinfo , void * puc ) {
 siginfo_t * info = pinfo ;
 unsigned long pc ;
 # if defined ( __NetBSD__ ) || defined ( __FreeBSD__ ) || defined ( __DragonFly__ ) ucontext_t * uc = puc ;
 # elif defined ( __OpenBSD__ ) struct sigcontext * uc = puc ;
 # else struct ucontext * uc = puc ;
 # endif pc = PC_sig ( uc ) ;
 return handle_cpu_signal ( pc , ( unsigned long ) info -> si_addr , TRAP_sig ( uc ) == 0xe ? ( ERROR_sig ( uc ) >> 1 ) & 1 : 0 , & MASK_sig ( uc ) , puc ) ;
 }