static void end_tee ( ) {
 my_fclose ( OUTFILE , MYF ( 0 ) ) ;
 OUTFILE = 0 ;
 opt_outfile = 0 ;
 return ;
 }