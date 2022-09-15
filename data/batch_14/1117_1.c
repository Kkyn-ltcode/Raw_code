static int kvm_get_supported_msrs ( KVMState * s ) {
 static int kvm_supported_msrs ;
 int ret = 0 ;
 if ( kvm_supported_msrs == 0 ) {
 struct kvm_msr_list msr_list , * kvm_msr_list ;
 kvm_supported_msrs = - 1 ;
 msr_list . nmsrs = 0 ;
 ret = kvm_ioctl ( s , KVM_GET_MSR_INDEX_LIST , & msr_list ) ;
 if ( ret < 0 && ret != - E2BIG ) {
 return ret ;
 }
 kvm_msr_list = g_malloc0 ( MAX ( 1024 , sizeof ( msr_list ) + msr_list . nmsrs * sizeof ( msr_list . indices [ 0 ] ) ) ) ;
 kvm_msr_list -> nmsrs = msr_list . nmsrs ;
 ret = kvm_ioctl ( s , KVM_GET_MSR_INDEX_LIST , kvm_msr_list ) ;
 if ( ret >= 0 ) {
 int i ;
 for ( i = 0 ;
 i < kvm_msr_list -> nmsrs ;
 i ++ ) {
 switch ( kvm_msr_list -> indices [ i ] ) {
 case MSR_STAR : has_msr_star = true ;
 break ;
 case MSR_VM_HSAVE_PA : has_msr_hsave_pa = true ;
 break ;
 case MSR_TSC_AUX : has_msr_tsc_aux = true ;
 break ;
 case MSR_TSC_ADJUST : has_msr_tsc_adjust = true ;
 break ;
 case MSR_IA32_TSCDEADLINE : has_msr_tsc_deadline = true ;
 break ;
 case MSR_IA32_SMBASE : has_msr_smbase = true ;
 break ;
 case MSR_SMI_COUNT : has_msr_smi_count = true ;
 break ;
 case MSR_IA32_MISC_ENABLE : has_msr_misc_enable = true ;
 break ;
 case MSR_IA32_BNDCFGS : has_msr_bndcfgs = true ;
 break ;
 case MSR_IA32_XSS : has_msr_xss = true ;
 break ;
 case HV_X64_MSR_CRASH_CTL : has_msr_hv_crash = true ;
 break ;
 case HV_X64_MSR_RESET : has_msr_hv_reset = true ;
 break ;
 case HV_X64_MSR_VP_INDEX : has_msr_hv_vpindex = true ;
 break ;
 case HV_X64_MSR_VP_RUNTIME : has_msr_hv_runtime = true ;
 break ;
 case HV_X64_MSR_SCONTROL : has_msr_hv_synic = true ;
 break ;
 case HV_X64_MSR_STIMER0_CONFIG : has_msr_hv_stimer = true ;
 break ;
 case HV_X64_MSR_TSC_FREQUENCY : has_msr_hv_frequencies = true ;
 break ;
 case HV_X64_MSR_REENLIGHTENMENT_CONTROL : has_msr_hv_reenlightenment = true ;
 break ;
 case MSR_IA32_SPEC_CTRL : has_msr_spec_ctrl = true ;
 break ;
 }
 }
 }
 g_free ( kvm_msr_list ) ;
 }
 return ret ;
 }