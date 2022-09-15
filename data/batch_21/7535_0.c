void append_info ( DYNAMIC_STRING * ds , ulonglong affected_rows , const char * info ) {
 char buf [ 40 ] , buff2 [ 21 ] ;
 sprintf ( buf , "affected rows: %s\n" , llstr ( affected_rows , buff2 ) ) ;
 dynstr_append ( ds , buf ) ;
 if ( info ) {
 dynstr_append ( ds , "info: " ) ;
 dynstr_append ( ds , info ) ;
 dynstr_append_mem ( ds , "\n" , 1 ) ;
 }
 }