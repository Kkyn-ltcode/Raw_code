void mct_start_logging ( const char * test_case_name ) {
 const char * tmp_dir = getenv ( "MYSQL_TMP_DIR" ) ;
 if ( ! tmp_dir ) {
 printf ( "Warning: MYSQL_TMP_DIR is not set. Logging is disabled.\n" ) ;
 return ;
 }
 if ( mct_log_file ) {
 printf ( "Warning: can not start logging for test case '%s' " "because log is already open\n" , ( const char * ) test_case_name ) ;
 return ;
 }
 if ( strlen ( tmp_dir ) + strlen ( test_case_name ) + 10 > FILE_PATH_SIZE ) {
 printf ( "Warning: MYSQL_TMP_DIR is too long. Logging is disabled.\n" ) ;
 return ;
 }
 my_snprintf ( mct_log_file_path , FILE_PATH_SIZE , "%s/%s.out.log" , ( const char * ) tmp_dir , ( const char * ) test_case_name ) ;
 mct_log_file = my_fopen ( mct_log_file_path , O_WRONLY | O_BINARY , MYF ( MY_WME ) ) ;
 if ( ! mct_log_file ) {
 printf ( "Warning: can not open log file (%s): %s. Logging is disabled.\n" , ( const char * ) mct_log_file_path , ( const char * ) strerror ( errno ) ) ;
 return ;
 }
 }