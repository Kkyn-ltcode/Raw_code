static inline void allow_coredumps ( ) {
 # ifdef PR_SET_DUMPABLE if ( test_flags & TEST_CORE_ON_SIGNAL ) {
 ( void ) prctl ( PR_SET_DUMPABLE , 1 ) ;
 }
 # endif }