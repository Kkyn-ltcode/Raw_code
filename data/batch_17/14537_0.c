static void init_pager ( ) {
 # ifdef USE_POPEN if ( ! opt_nopager ) {
 if ( ! ( PAGER = popen ( pager , "w" ) ) ) {
 tee_fprintf ( stdout , "popen() failed! defaulting PAGER to stdout!\n" ) ;
 PAGER = stdout ;
 }
 }
 else # endif PAGER = stdout ;
 }