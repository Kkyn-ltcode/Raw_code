void mi_check_print_warning ( MI_CHECK * param , const char * fmt , ... ) {
 va_list args ;
 DBUG_ENTER ( "mi_check_print_warning" ) ;
 fflush ( stdout ) ;
 if ( ! param -> warning_printed && ! param -> error_printed ) {
 if ( param -> testflag & T_SILENT ) fprintf ( stderr , "%s: MyISAM file %s\n" , my_progname_short , param -> isam_file_name ) ;
 param -> out_flag |= O_DATA_LOST ;
 }
 param -> warning_printed = 1 ;
 va_start ( args , fmt ) ;
 fprintf ( stderr , "%s: warning: " , my_progname_short ) ;
 ( void ) vfprintf ( stderr , fmt , args ) ;
 ( void ) fputc ( '\n' , stderr ) ;
 fflush ( stderr ) ;
 va_end ( args ) ;
 DBUG_VOID_RETURN ;
 }