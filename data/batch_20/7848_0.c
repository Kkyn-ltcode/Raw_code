static int add_stop_slave ( void ) {
 if ( opt_comments ) fprintf ( md_result_file , "\n--\n-- stop slave statement to make a recovery dump)\n--\n\n" ) ;
 fprintf ( md_result_file , "STOP SLAVE;
\n" ) ;
 return ( 0 ) ;
 }