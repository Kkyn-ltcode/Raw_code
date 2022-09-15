static void create_pid_file ( ) {
 File file ;
 if ( ( file = mysql_file_create ( key_file_pid , pidfile_name , 0664 , O_WRONLY | O_TRUNC , MYF ( MY_WME ) ) ) >= 0 ) {
 char buff [ MAX_BIGINT_WIDTH + 1 ] , * end ;
 end = int10_to_str ( ( long ) getpid ( ) , buff , 10 ) ;
 * end ++ = '\n' ;
 if ( ! mysql_file_write ( file , ( uchar * ) buff , ( uint ) ( end - buff ) , MYF ( MY_WME | MY_NABP ) ) ) {
 mysql_file_close ( file , MYF ( 0 ) ) ;
 pid_file_created = true ;
 return ;
 }
 mysql_file_close ( file , MYF ( 0 ) ) ;
 }
 sql_perror ( "Can't start server: can't create PID file" ) ;
 exit ( 1 ) ;
 }