static void exception_action ( CPUArchState * env1 ) {
 # if defined ( TARGET_I386 ) raise_exception_err ( env1 , env1 -> exception_index , env1 -> error_code ) ;
 # else cpu_loop_exit ( env1 ) ;
 # endif }