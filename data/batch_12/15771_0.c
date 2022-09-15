int cpu_gen_code ( CPUArchState * env , TranslationBlock * tb , int * gen_code_size_ptr ) {
 TCGContext * s = & tcg_ctx ;
 uint8_t * gen_code_buf ;
 int gen_code_size ;
 # ifdef CONFIG_PROFILER int64_t ti ;
 # endif # ifdef CONFIG_PROFILER s -> tb_count1 ++ ;
 ti = profile_getclock ( ) ;
 # endif tcg_func_start ( s ) ;
 gen_intermediate_code ( env , tb ) ;
 gen_code_buf = tb -> tc_ptr ;
 tb -> tb_next_offset [ 0 ] = 0xffff ;
 tb -> tb_next_offset [ 1 ] = 0xffff ;
 s -> tb_next_offset = tb -> tb_next_offset ;
 # ifdef USE_DIRECT_JUMP s -> tb_jmp_offset = tb -> tb_jmp_offset ;
 s -> tb_next = NULL ;
 # else s -> tb_jmp_offset = NULL ;
 s -> tb_next = tb -> tb_next ;
 # endif # ifdef CONFIG_PROFILER s -> tb_count ++ ;
 s -> interm_time += profile_getclock ( ) - ti ;
 s -> code_time -= profile_getclock ( ) ;
 # endif gen_code_size = tcg_gen_code ( s , gen_code_buf ) ;
 * gen_code_size_ptr = gen_code_size ;
 # ifdef CONFIG_PROFILER s -> code_time += profile_getclock ( ) ;
 s -> code_in_len += tb -> size ;
 s -> code_out_len += gen_code_size ;
 # endif # ifdef DEBUG_DISAS if ( qemu_loglevel_mask ( CPU_LOG_TB_OUT_ASM ) ) {
 qemu_log ( "OUT: [size=%d]\n" , * gen_code_size_ptr ) ;
 log_disas ( tb -> tc_ptr , * gen_code_size_ptr ) ;
 qemu_log ( "\n" ) ;
 qemu_log_flush ( ) ;
 }
 # endif return 0 ;
 }