static void delete_pid_file ( myf flags ) {
 # ifndef EMBEDDED_LIBRARY if ( pid_file_created ) {
 mysql_file_delete ( key_file_pid , pidfile_name , flags ) ;
 pid_file_created = false ;
 }
 # endif return ;
 }