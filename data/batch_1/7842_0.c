static int add_slave_statements ( void ) {
 if ( opt_comments ) fprintf ( md_result_file , "\n--\n-- start slave statement to make a recovery dump)\n--\n\n" ) ;
 fprintf ( md_result_file , "START SLAVE;
\n" ) ;
 return ( 0 ) ;
 }