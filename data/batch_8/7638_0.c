int lock_file ( MI_CHECK * param , File file , my_off_t start , int lock_type , const char * filetype , const char * filename ) {
 if ( my_lock ( file , lock_type , start , F_TO_EOF , param -> testflag & T_WAIT_FOREVER ? MYF ( MY_SEEK_NOT_DONE ) : MYF ( MY_SEEK_NOT_DONE | MY_DONT_WAIT ) ) ) {
 mi_check_print_error ( param , " %d when locking %s '%s'" , my_errno , filetype , filename ) ;
 param -> error_printed = 2 ;
 return 1 ;
 }
 return 0 ;
 }