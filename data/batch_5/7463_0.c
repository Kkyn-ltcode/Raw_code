void init_re_comp ( my_regex_t * re , const char * str ) {
 int err = my_regcomp ( re , str , ( REG_EXTENDED | REG_ICASE | REG_NOSUB ) , & my_charset_latin1 ) ;
 if ( err ) {
 char erbuf [ 100 ] ;
 int len = my_regerror ( err , re , erbuf , sizeof ( erbuf ) ) ;
 die ( "error %s, %d/%d `%s'\n" , re_eprint ( err ) , ( int ) len , ( int ) sizeof ( erbuf ) , erbuf ) ;
 }
 }