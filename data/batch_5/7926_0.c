static void print_xml_null_tag ( FILE * xml_file , const char * sbeg , const char * stag_atr , const char * sval , const char * line_end ) {
 fputs ( sbeg , xml_file ) ;
 fputs ( "<" , xml_file ) ;
 fputs ( stag_atr , xml_file ) ;
 fputs ( "\"" , xml_file ) ;
 print_quoted_xml ( xml_file , sval , strlen ( sval ) , 0 ) ;
 fputs ( "\" xsi:nil=\"true\" />" , xml_file ) ;
 fputs ( line_end , xml_file ) ;
 check_io ( xml_file ) ;
 }