static void generate_preamble ( void ) {
 time_t now ;
 char timestamp [ 128 ] ;
 char preamble [ ] = "/*\n" " * ntp_keyword.h\n" " * \n" " * NOTE: edit this file with caution, it is generated by keyword-gen.c\n" " *\t Generated %s UTC diff_ignore_line\n" " *\n" " */\n" "#include \"ntp_scanner.h\"\n" "#include \"ntp_parser.h\"\n" "\n" ;
 time ( & now ) ;
 if ( ! strftime ( timestamp , sizeof ( timestamp ) , "%Y-%m-%d %H:%M:%S" , gmtime ( & now ) ) ) timestamp [ 0 ] = '\0' ;
 printf ( preamble , timestamp ) ;
 }