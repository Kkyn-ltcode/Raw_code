static void print_xml_cdata ( FILE * xml_file , const char * str , ulong len ) {
 const char * end ;
 fputs ( "<![CDATA[\n" , xml_file ) ;
 for ( end = str + len ;
 str != end ;
 str ++ ) {
 switch ( * str ) {
 case ']' : if ( ( * ( str + 1 ) == ']' ) && ( * ( str + 2 ) == '>' ) ) {
 fputs ( "]]]]><![CDATA[>" , xml_file ) ;
 str += 2 ;
 continue ;
 }
 default : fputc ( * str , xml_file ) ;
 break ;
 }
 }
 fputs ( "\n]]>\n" , xml_file ) ;
 check_io ( xml_file ) ;
 }