static size_t my_setstacksize ( pthread_attr_t * attr , size_t stacksize ) {
 size_t guard_size __attribute__ ( ( unused ) ) = 0 ;
 # if defined ( __ia64__ ) || defined ( __ia64 ) stacksize *= 2 ;
 # endif # ifdef HAVE_PTHREAD_ATTR_GETGUARDSIZE if ( pthread_attr_getguardsize ( attr , & guard_size ) ) guard_size = 0 ;
 # endif pthread_attr_setstacksize ( attr , stacksize + guard_size ) ;
 # ifdef HAVE_PTHREAD_ATTR_GETSTACKSIZE {
 size_t real_stack_size = 0 ;
 if ( pthread_attr_getstacksize ( attr , & real_stack_size ) == 0 && real_stack_size > guard_size ) {
 real_stack_size -= guard_size ;
 if ( real_stack_size < stacksize ) {
 if ( global_system_variables . log_warnings ) sql_print_warning ( "Asked for %zu thread stack, but got %zu" , stacksize , real_stack_size ) ;
 stacksize = real_stack_size ;
 }
 }
 }
 # endif # if defined ( __ia64__ ) || defined ( __ia64 ) stacksize /= 2 ;
 # endif return stacksize ;
 }