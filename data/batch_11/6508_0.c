static void srec_bad_byte ( bfd * abfd , unsigned int lineno , int c , bfd_boolean error ) {
 if ( c == EOF ) {
 if ( ! error ) bfd_set_error ( bfd_error_file_truncated ) ;
 }
 else {
 char buf [ 10 ] ;
 if ( ! ISPRINT ( c ) ) sprintf ( buf , "\\%03o" , ( unsigned int ) c ) ;
 else {
 buf [ 0 ] = c ;
 buf [ 1 ] = '\0' ;
 }
 ( * _bfd_error_handler ) ( _ ( "%B:%d: Unexpected character `%s' in S-record file\n" ) , abfd , lineno , buf ) ;
 bfd_set_error ( bfd_error_bad_value ) ;
 }
 }