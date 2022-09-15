int compare_files ( const char * filename1 , const char * filename2 ) {
 File fd ;
 int error ;
 if ( ( fd = my_open ( filename1 , O_RDONLY , MYF ( 0 ) ) ) < 0 ) die ( "Failed to open first file: '%s'" , filename1 ) ;
 error = compare_files2 ( fd , filename2 ) ;
 my_close ( fd , MYF ( 0 ) ) ;
 return error ;
 }