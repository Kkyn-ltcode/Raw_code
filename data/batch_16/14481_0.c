static void end_pager ( ) {
 # ifdef USE_POPEN if ( ! opt_nopager ) pclose ( PAGER ) ;
 # endif }