void cpu_resume_from_signal ( CPUArchState * env1 , void * puc ) {
 # ifdef __linux__ struct ucontext * uc = puc ;
 # elif defined ( __OpenBSD__ ) struct sigcontext * uc = puc ;
 # endif if ( puc ) {
 # ifdef __linux__ # ifdef __ia64 sigprocmask ( SIG_SETMASK , ( sigset_t * ) & uc -> uc_sigmask , NULL ) ;
 # else sigprocmask ( SIG_SETMASK , & uc -> uc_sigmask , NULL ) ;
 # endif # elif defined ( __OpenBSD__ ) sigprocmask ( SIG_SETMASK , & uc -> sc_mask , NULL ) ;
 # endif }
 env1 -> exception_index = - 1 ;
 siglongjmp ( env1 -> jmp_env , 1 ) ;
 }