my_bool match_delimiter ( int c , const char * delim , uint length ) {
 uint i ;
 char tmp [ MAX_DELIMITER_LENGTH ] ;
 if ( c != * delim ) return 0 ;
 for ( i = 1 ;
 i < length && ( c = my_getc ( cur_file -> file ) ) == * ( delim + i ) ;
 i ++ ) tmp [ i ] = c ;
 if ( i == length ) return 1 ;
 my_ungetc ( c ) ;
 while ( i > 1 ) my_ungetc ( tmp [ -- i ] ) ;
 return 0 ;
 }