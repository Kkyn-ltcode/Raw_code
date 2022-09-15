CpuInfoList * qmp_query_cpus ( Error * * errp ) {
 CpuInfoList * head = NULL , * cur_item = NULL ;
 CPUArchState * env ;
 for ( env = first_cpu ;
 env != NULL ;
 env = env -> next_cpu ) {
 CPUState * cpu = ENV_GET_CPU ( env ) ;
 CpuInfoList * info ;
 cpu_synchronize_state ( cpu ) ;
 info = g_malloc0 ( sizeof ( * info ) ) ;
 info -> value = g_malloc0 ( sizeof ( * info -> value ) ) ;
 info -> value -> CPU = cpu -> cpu_index ;
 info -> value -> current = ( env == first_cpu ) ;
 info -> value -> halted = cpu -> halted ;
 info -> value -> thread_id = cpu -> thread_id ;
 # if defined ( TARGET_I386 ) info -> value -> has_pc = true ;
 info -> value -> pc = env -> eip + env -> segs [ R_CS ] . base ;
 # elif defined ( TARGET_PPC ) info -> value -> has_nip = true ;
 info -> value -> nip = env -> nip ;
 # elif defined ( TARGET_SPARC ) info -> value -> has_pc = true ;
 info -> value -> pc = env -> pc ;
 info -> value -> has_npc = true ;
 info -> value -> npc = env -> npc ;
 # elif defined ( TARGET_MIPS ) info -> value -> has_PC = true ;
 info -> value -> PC = env -> active_tc . PC ;
 # endif if ( ! cur_item ) {
 head = cur_item = info ;
 }
 else {
 cur_item -> next = info ;
 cur_item = info ;
 }
 }
 return head ;
 }