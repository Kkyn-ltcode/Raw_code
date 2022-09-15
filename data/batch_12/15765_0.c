int cpu_exec ( CPUArchState * env ) {
 CPUState * cpu = ENV_GET_CPU ( env ) ;
 # if ! ( defined ( CONFIG_USER_ONLY ) && ( defined ( TARGET_M68K ) || defined ( TARGET_PPC ) || defined ( TARGET_S390X ) ) ) CPUClass * cc = CPU_GET_CLASS ( cpu ) ;
 # endif int ret , interrupt_request ;
 TranslationBlock * tb ;
 uint8_t * tc_ptr ;
 tcg_target_ulong next_tb ;
 if ( cpu -> halted ) {
 if ( ! cpu_has_work ( cpu ) ) {
 return EXCP_HALTED ;
 }
 cpu -> halted = 0 ;
 }
 current_cpu = cpu ;
 smp_mb ( ) ;
 if ( unlikely ( exit_request ) ) {
 cpu -> exit_request = 1 ;
 }
 # if defined ( TARGET_I386 ) CC_SRC = env -> eflags & ( CC_O | CC_S | CC_Z | CC_A | CC_P | CC_C ) ;
 env -> df = 1 - ( 2 * ( ( env -> eflags >> 10 ) & 1 ) ) ;
 CC_OP = CC_OP_EFLAGS ;
 env -> eflags &= ~ ( DF_MASK | CC_O | CC_S | CC_Z | CC_A | CC_P | CC_C ) ;
 # elif defined ( TARGET_SPARC ) # elif defined ( TARGET_M68K ) env -> cc_op = CC_OP_FLAGS ;
 env -> cc_dest = env -> sr & 0xf ;
 env -> cc_x = ( env -> sr >> 4 ) & 1 ;
 # elif defined ( TARGET_ALPHA ) # elif defined ( TARGET_ARM ) # elif defined ( TARGET_UNICORE32 ) # elif defined ( TARGET_PPC ) env -> reserve_addr = - 1 ;
 # elif defined ( TARGET_LM32 ) # elif defined ( TARGET_MICROBLAZE ) # elif defined ( TARGET_MIPS ) # elif defined ( TARGET_MOXIE ) # elif defined ( TARGET_OPENRISC ) # elif defined ( TARGET_SH4 ) # elif defined ( TARGET_CRIS ) # elif defined ( TARGET_S390X ) # elif defined ( TARGET_XTENSA ) # else # error unsupported target CPU # endif env -> exception_index = - 1 ;
 for ( ;
 ;
 ) {
 if ( sigsetjmp ( env -> jmp_env , 0 ) == 0 ) {
 if ( env -> exception_index >= 0 ) {
 if ( env -> exception_index >= EXCP_INTERRUPT ) {
 ret = env -> exception_index ;
 if ( ret == EXCP_DEBUG ) {
 cpu_handle_debug_exception ( env ) ;
 }
 break ;
 }
 else {
 # if defined ( CONFIG_USER_ONLY ) # if defined ( TARGET_I386 ) cc -> do_interrupt ( cpu ) ;
 # endif ret = env -> exception_index ;
 break ;
 # else cc -> do_interrupt ( cpu ) ;
 env -> exception_index = - 1 ;
 # endif }
 }
 next_tb = 0 ;
 for ( ;
 ;
 ) {
 interrupt_request = cpu -> interrupt_request ;
 if ( unlikely ( interrupt_request ) ) {
 if ( unlikely ( env -> singlestep_enabled & SSTEP_NOIRQ ) ) {
 interrupt_request &= ~ CPU_INTERRUPT_SSTEP_MASK ;
 }
 if ( interrupt_request & CPU_INTERRUPT_DEBUG ) {
 cpu -> interrupt_request &= ~ CPU_INTERRUPT_DEBUG ;
 env -> exception_index = EXCP_DEBUG ;
 cpu_loop_exit ( env ) ;
 }
 # if defined ( TARGET_ARM ) || defined ( TARGET_SPARC ) || defined ( TARGET_MIPS ) || defined ( TARGET_PPC ) || defined ( TARGET_ALPHA ) || defined ( TARGET_CRIS ) || defined ( TARGET_MICROBLAZE ) || defined ( TARGET_LM32 ) || defined ( TARGET_UNICORE32 ) if ( interrupt_request & CPU_INTERRUPT_HALT ) {
 cpu -> interrupt_request &= ~ CPU_INTERRUPT_HALT ;
 cpu -> halted = 1 ;
 env -> exception_index = EXCP_HLT ;
 cpu_loop_exit ( env ) ;
 }
 # endif # if defined ( TARGET_I386 ) # if ! defined ( CONFIG_USER_ONLY ) if ( interrupt_request & CPU_INTERRUPT_POLL ) {
 cpu -> interrupt_request &= ~ CPU_INTERRUPT_POLL ;
 apic_poll_irq ( env -> apic_state ) ;
 }
 # endif if ( interrupt_request & CPU_INTERRUPT_INIT ) {
 cpu_svm_check_intercept_param ( env , SVM_EXIT_INIT , 0 ) ;
 do_cpu_init ( x86_env_get_cpu ( env ) ) ;
 env -> exception_index = EXCP_HALTED ;
 cpu_loop_exit ( env ) ;
 }
 else if ( interrupt_request & CPU_INTERRUPT_SIPI ) {
 do_cpu_sipi ( x86_env_get_cpu ( env ) ) ;
 }
 else if ( env -> hflags2 & HF2_GIF_MASK ) {
 if ( ( interrupt_request & CPU_INTERRUPT_SMI ) && ! ( env -> hflags & HF_SMM_MASK ) ) {
 cpu_svm_check_intercept_param ( env , SVM_EXIT_SMI , 0 ) ;
 cpu -> interrupt_request &= ~ CPU_INTERRUPT_SMI ;
 do_smm_enter ( env ) ;
 next_tb = 0 ;
 }
 else if ( ( interrupt_request & CPU_INTERRUPT_NMI ) && ! ( env -> hflags2 & HF2_NMI_MASK ) ) {
 cpu -> interrupt_request &= ~ CPU_INTERRUPT_NMI ;
 env -> hflags2 |= HF2_NMI_MASK ;
 do_interrupt_x86_hardirq ( env , EXCP02_NMI , 1 ) ;
 next_tb = 0 ;
 }
 else if ( interrupt_request & CPU_INTERRUPT_MCE ) {
 cpu -> interrupt_request &= ~ CPU_INTERRUPT_MCE ;
 do_interrupt_x86_hardirq ( env , EXCP12_MCHK , 0 ) ;
 next_tb = 0 ;
 }
 else if ( ( interrupt_request & CPU_INTERRUPT_HARD ) && ( ( ( env -> hflags2 & HF2_VINTR_MASK ) && ( env -> hflags2 & HF2_HIF_MASK ) ) || ( ! ( env -> hflags2 & HF2_VINTR_MASK ) && ( env -> eflags & IF_MASK && ! ( env -> hflags & HF_INHIBIT_IRQ_MASK ) ) ) ) ) {
 int intno ;
 cpu_svm_check_intercept_param ( env , SVM_EXIT_INTR , 0 ) ;
 cpu -> interrupt_request &= ~ ( CPU_INTERRUPT_HARD | CPU_INTERRUPT_VIRQ ) ;
 intno = cpu_get_pic_interrupt ( env ) ;
 qemu_log_mask ( CPU_LOG_TB_IN_ASM , "Servicing hardware INT=0x%02x\n" , intno ) ;
 do_interrupt_x86_hardirq ( env , intno , 1 ) ;
 next_tb = 0 ;
 # if ! defined ( CONFIG_USER_ONLY ) }
 else if ( ( interrupt_request & CPU_INTERRUPT_VIRQ ) && ( env -> eflags & IF_MASK ) && ! ( env -> hflags & HF_INHIBIT_IRQ_MASK ) ) {
 int intno ;
 cpu_svm_check_intercept_param ( env , SVM_EXIT_VINTR , 0 ) ;
 intno = ldl_phys ( env -> vm_vmcb + offsetof ( struct vmcb , control . int_vector ) ) ;
 qemu_log_mask ( CPU_LOG_TB_IN_ASM , "Servicing virtual hardware INT=0x%02x\n" , intno ) ;
 do_interrupt_x86_hardirq ( env , intno , 1 ) ;
 cpu -> interrupt_request &= ~ CPU_INTERRUPT_VIRQ ;
 next_tb = 0 ;
 # endif }
 }
 # elif defined ( TARGET_PPC ) if ( ( interrupt_request & CPU_INTERRUPT_RESET ) ) {
 cpu_reset ( cpu ) ;
 }
 if ( interrupt_request & CPU_INTERRUPT_HARD ) {
 ppc_hw_interrupt ( env ) ;
 if ( env -> pending_interrupts == 0 ) {
 cpu -> interrupt_request &= ~ CPU_INTERRUPT_HARD ;
 }
 next_tb = 0 ;
 }
 # elif defined ( TARGET_LM32 ) if ( ( interrupt_request & CPU_INTERRUPT_HARD ) && ( env -> ie & IE_IE ) ) {
 env -> exception_index = EXCP_IRQ ;
 cc -> do_interrupt ( cpu ) ;
 next_tb = 0 ;
 }
 # elif defined ( TARGET_MICROBLAZE ) if ( ( interrupt_request & CPU_INTERRUPT_HARD ) && ( env -> sregs [ SR_MSR ] & MSR_IE ) && ! ( env -> sregs [ SR_MSR ] & ( MSR_EIP | MSR_BIP ) ) && ! ( env -> iflags & ( D_FLAG | IMM_FLAG ) ) ) {
 env -> exception_index = EXCP_IRQ ;
 cc -> do_interrupt ( cpu ) ;
 next_tb = 0 ;
 }
 # elif defined ( TARGET_MIPS ) if ( ( interrupt_request & CPU_INTERRUPT_HARD ) && cpu_mips_hw_interrupts_pending ( env ) ) {
 env -> exception_index = EXCP_EXT_INTERRUPT ;
 env -> error_code = 0 ;
 cc -> do_interrupt ( cpu ) ;
 next_tb = 0 ;
 }
 # elif defined ( TARGET_OPENRISC ) {
 int idx = - 1 ;
 if ( ( interrupt_request & CPU_INTERRUPT_HARD ) && ( env -> sr & SR_IEE ) ) {
 idx = EXCP_INT ;
 }
 if ( ( interrupt_request & CPU_INTERRUPT_TIMER ) && ( env -> sr & SR_TEE ) ) {
 idx = EXCP_TICK ;
 }
 if ( idx >= 0 ) {
 env -> exception_index = idx ;
 cc -> do_interrupt ( cpu ) ;
 next_tb = 0 ;
 }
 }
 # elif defined ( TARGET_SPARC ) if ( interrupt_request & CPU_INTERRUPT_HARD ) {
 if ( cpu_interrupts_enabled ( env ) && env -> interrupt_index > 0 ) {
 int pil = env -> interrupt_index & 0xf ;
 int type = env -> interrupt_index & 0xf0 ;
 if ( ( ( type == TT_EXTINT ) && cpu_pil_allowed ( env , pil ) ) || type != TT_EXTINT ) {
 env -> exception_index = env -> interrupt_index ;
 cc -> do_interrupt ( cpu ) ;
 next_tb = 0 ;
 }
 }
 }
 # elif defined ( TARGET_ARM ) if ( interrupt_request & CPU_INTERRUPT_FIQ && ! ( env -> uncached_cpsr & CPSR_F ) ) {
 env -> exception_index = EXCP_FIQ ;
 cc -> do_interrupt ( cpu ) ;
 next_tb = 0 ;
 }
 if ( interrupt_request & CPU_INTERRUPT_HARD && ( ( IS_M ( env ) && env -> regs [ 15 ] < 0xfffffff0 ) || ! ( env -> uncached_cpsr & CPSR_I ) ) ) {
 env -> exception_index = EXCP_IRQ ;
 cc -> do_interrupt ( cpu ) ;
 next_tb = 0 ;
 }
 # elif defined ( TARGET_UNICORE32 ) if ( interrupt_request & CPU_INTERRUPT_HARD && ! ( env -> uncached_asr & ASR_I ) ) {
 env -> exception_index = UC32_EXCP_INTR ;
 cc -> do_interrupt ( cpu ) ;
 next_tb = 0 ;
 }
 # elif defined ( TARGET_SH4 ) if ( interrupt_request & CPU_INTERRUPT_HARD ) {
 cc -> do_interrupt ( cpu ) ;
 next_tb = 0 ;
 }
 # elif defined ( TARGET_ALPHA ) {
 int idx = - 1 ;
 switch ( env -> pal_mode ? 7 : env -> ps & PS_INT_MASK ) {
 case 0 ... 3 : if ( interrupt_request & CPU_INTERRUPT_HARD ) {
 idx = EXCP_DEV_INTERRUPT ;
 }
 case 4 : if ( interrupt_request & CPU_INTERRUPT_TIMER ) {
 idx = EXCP_CLK_INTERRUPT ;
 }
 case 5 : if ( interrupt_request & CPU_INTERRUPT_SMP ) {
 idx = EXCP_SMP_INTERRUPT ;
 }
 case 6 : if ( interrupt_request & CPU_INTERRUPT_MCHK ) {
 idx = EXCP_MCHK ;
 }
 }
 if ( idx >= 0 ) {
 env -> exception_index = idx ;
 env -> error_code = 0 ;
 cc -> do_interrupt ( cpu ) ;
 next_tb = 0 ;
 }
 }
 # elif defined ( TARGET_CRIS ) if ( interrupt_request & CPU_INTERRUPT_HARD && ( env -> pregs [ PR_CCS ] & I_FLAG ) && ! env -> locked_irq ) {
 env -> exception_index = EXCP_IRQ ;
 cc -> do_interrupt ( cpu ) ;
 next_tb = 0 ;
 }
 if ( interrupt_request & CPU_INTERRUPT_NMI ) {
 unsigned int m_flag_archval ;
 if ( env -> pregs [ PR_VR ] < 32 ) {
 m_flag_archval = M_FLAG_V10 ;
 }
 else {
 m_flag_archval = M_FLAG_V32 ;
 }
 if ( ( env -> pregs [ PR_CCS ] & m_flag_archval ) ) {
 env -> exception_index = EXCP_NMI ;
 cc -> do_interrupt ( cpu ) ;
 next_tb = 0 ;
 }
 }
 # elif defined ( TARGET_M68K ) if ( interrupt_request & CPU_INTERRUPT_HARD && ( ( env -> sr & SR_I ) >> SR_I_SHIFT ) < env -> pending_level ) {
 env -> exception_index = env -> pending_vector ;
 do_interrupt_m68k_hardirq ( env ) ;
 next_tb = 0 ;
 }
 # elif defined ( TARGET_S390X ) && ! defined ( CONFIG_USER_ONLY ) if ( ( interrupt_request & CPU_INTERRUPT_HARD ) && ( env -> psw . mask & PSW_MASK_EXT ) ) {
 cc -> do_interrupt ( cpu ) ;
 next_tb = 0 ;
 }
 # elif defined ( TARGET_XTENSA ) if ( interrupt_request & CPU_INTERRUPT_HARD ) {
 env -> exception_index = EXC_IRQ ;
 cc -> do_interrupt ( cpu ) ;
 next_tb = 0 ;
 }
 # endif if ( cpu -> interrupt_request & CPU_INTERRUPT_EXITTB ) {
 cpu -> interrupt_request &= ~ CPU_INTERRUPT_EXITTB ;
 next_tb = 0 ;
 }
 }
 if ( unlikely ( cpu -> exit_request ) ) {
 cpu -> exit_request = 0 ;
 env -> exception_index = EXCP_INTERRUPT ;
 cpu_loop_exit ( env ) ;
 }
 # if defined ( DEBUG_DISAS ) if ( qemu_loglevel_mask ( CPU_LOG_TB_CPU ) ) {
 # if defined ( TARGET_I386 ) log_cpu_state ( env , CPU_DUMP_CCOP ) ;
 # elif defined ( TARGET_M68K ) cpu_m68k_flush_flags ( env , env -> cc_op ) ;
 env -> cc_op = CC_OP_FLAGS ;
 env -> sr = ( env -> sr & 0xffe0 ) | env -> cc_dest | ( env -> cc_x << 4 ) ;
 log_cpu_state ( env , 0 ) ;
 # else log_cpu_state ( env , 0 ) ;
 # endif }
 # endif spin_lock ( & tcg_ctx . tb_ctx . tb_lock ) ;
 tb = tb_find_fast ( env ) ;
 if ( tcg_ctx . tb_ctx . tb_invalidated_flag ) {
 next_tb = 0 ;
 tcg_ctx . tb_ctx . tb_invalidated_flag = 0 ;
 }
 if ( qemu_loglevel_mask ( CPU_LOG_EXEC ) ) {
 qemu_log ( "Trace %p [" TARGET_FMT_lx "] %s\n" , tb -> tc_ptr , tb -> pc , lookup_symbol ( tb -> pc ) ) ;
 }
 if ( next_tb != 0 && tb -> page_addr [ 1 ] == - 1 ) {
 tb_add_jump ( ( TranslationBlock * ) ( next_tb & ~ TB_EXIT_MASK ) , next_tb & TB_EXIT_MASK , tb ) ;
 }
 spin_unlock ( & tcg_ctx . tb_ctx . tb_lock ) ;
 cpu -> current_tb = tb ;
 barrier ( ) ;
 if ( likely ( ! cpu -> exit_request ) ) {
 tc_ptr = tb -> tc_ptr ;
 next_tb = cpu_tb_exec ( cpu , tc_ptr ) ;
 switch ( next_tb & TB_EXIT_MASK ) {
 case TB_EXIT_REQUESTED : tb = ( TranslationBlock * ) ( next_tb & ~ TB_EXIT_MASK ) ;
 next_tb = 0 ;
 break ;
 case TB_EXIT_ICOUNT_EXPIRED : {
 int insns_left ;
 tb = ( TranslationBlock * ) ( next_tb & ~ TB_EXIT_MASK ) ;
 insns_left = env -> icount_decr . u32 ;
 if ( env -> icount_extra && insns_left >= 0 ) {
 env -> icount_extra += insns_left ;
 if ( env -> icount_extra > 0xffff ) {
 insns_left = 0xffff ;
 }
 else {
 insns_left = env -> icount_extra ;
 }
 env -> icount_extra -= insns_left ;
 env -> icount_decr . u16 . low = insns_left ;
 }
 else {
 if ( insns_left > 0 ) {
 cpu_exec_nocache ( env , insns_left , tb ) ;
 }
 env -> exception_index = EXCP_INTERRUPT ;
 next_tb = 0 ;
 cpu_loop_exit ( env ) ;
 }
 break ;
 }
 default : break ;
 }
 }
 cpu -> current_tb = NULL ;
 }
 }
 else {
 cpu = current_cpu ;
 env = cpu -> env_ptr ;
 }
 }
 # if defined ( TARGET_I386 ) env -> eflags = env -> eflags | cpu_cc_compute_all ( env , CC_OP ) | ( env -> df & DF_MASK ) ;
 # elif defined ( TARGET_ARM ) # elif defined ( TARGET_UNICORE32 ) # elif defined ( TARGET_SPARC ) # elif defined ( TARGET_PPC ) # elif defined ( TARGET_LM32 ) # elif defined ( TARGET_M68K ) cpu_m68k_flush_flags ( env , env -> cc_op ) ;
 env -> cc_op = CC_OP_FLAGS ;
 env -> sr = ( env -> sr & 0xffe0 ) | env -> cc_dest | ( env -> cc_x << 4 ) ;
 # elif defined ( TARGET_MICROBLAZE ) # elif defined ( TARGET_MIPS ) # elif defined ( TARGET_MOXIE ) # elif defined ( TARGET_OPENRISC ) # elif defined ( TARGET_SH4 ) # elif defined ( TARGET_ALPHA ) # elif defined ( TARGET_CRIS ) # elif defined ( TARGET_S390X ) # elif defined ( TARGET_XTENSA ) # else # error unsupported target CPU # endif current_cpu = NULL ;
 return ret ;
 }