int filecopy ( MI_CHECK * param , File to , File from , my_off_t start , my_off_t length , const char * type ) {
 char tmp_buff [ IO_SIZE ] , * buff ;
 ulong buff_length ;
 DBUG_ENTER ( "filecopy" ) ;
 buff_length = ( ulong ) min ( param -> write_buffer_length , length ) ;
 if ( ! ( buff = my_malloc ( buff_length , MYF ( 0 ) ) ) ) {
 buff = tmp_buff ;
 buff_length = IO_SIZE ;
 }
 mysql_file_seek ( from , start , MY_SEEK_SET , MYF ( 0 ) ) ;
 while ( length > buff_length ) {
 if ( mysql_file_read ( from , ( uchar * ) buff , buff_length , MYF ( MY_NABP ) ) || mysql_file_write ( to , ( uchar * ) buff , buff_length , param -> myf_rw ) ) goto err ;
 length -= buff_length ;
 }
 if ( mysql_file_read ( from , ( uchar * ) buff , ( uint ) length , MYF ( MY_NABP ) ) || mysql_file_write ( to , ( uchar * ) buff , ( uint ) length , param -> myf_rw ) ) goto err ;
 if ( buff != tmp_buff ) my_free ( buff ) ;
 DBUG_RETURN ( 0 ) ;
 err : if ( buff != tmp_buff ) my_free ( buff ) ;
 mi_check_print_error ( param , "Can't copy %s to tempfile, error %d" , type , my_errno ) ;
 DBUG_RETURN ( 1 ) ;
 }