static bool avx512_needed ( void * opaque ) {
 X86CPU * cpu = opaque ;
 CPUX86State * env = & cpu -> env ;
 unsigned int i ;
 for ( i = 0 ;
 i < NB_OPMASK_REGS ;
 i ++ ) {
 if ( env -> opmask_regs [ i ] ) {
 return true ;
 }
 }
 for ( i = 0 ;
 i < CPU_NB_REGS ;
 i ++ ) {
 # define ENV_XMM ( reg , field ) ( env -> xmm_regs [ reg ] . ZMM_Q ( field ) ) if ( ENV_XMM ( i , 4 ) || ENV_XMM ( i , 6 ) || ENV_XMM ( i , 5 ) || ENV_XMM ( i , 7 ) ) {
 return true ;
 }
 # ifdef TARGET_X86_64 if ( ENV_XMM ( i + 16 , 0 ) || ENV_XMM ( i + 16 , 1 ) || ENV_XMM ( i + 16 , 2 ) || ENV_XMM ( i + 16 , 3 ) || ENV_XMM ( i + 16 , 4 ) || ENV_XMM ( i + 16 , 5 ) || ENV_XMM ( i + 16 , 6 ) || ENV_XMM ( i + 16 , 7 ) ) {
 return true ;
 }
 # endif }
 return false ;
 }