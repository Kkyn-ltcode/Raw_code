static void security_init ( void ) {
 uintptr_t stack_chk_guard = _dl_setup_stack_chk_guard ( _dl_random ) ;
 # ifdef THREAD_SET_STACK_GUARD THREAD_SET_STACK_GUARD ( stack_chk_guard ) ;
 # else __stack_chk_guard = stack_chk_guard ;
 # endif if ( GLRO ( dl_pointer_guard ) ) {
 uintptr_t pointer_chk_guard = _dl_setup_pointer_guard ( _dl_random , stack_chk_guard ) ;
 # ifdef THREAD_SET_POINTER_GUARD THREAD_SET_POINTER_GUARD ( pointer_chk_guard ) ;
 # endif __pointer_chk_guard_local = pointer_chk_guard ;
 }
 _dl_random = NULL ;
 }