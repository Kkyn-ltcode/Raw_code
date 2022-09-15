static void unicode_escape ( char * buf , UTF16 character ) {
 const char * digits = "0123456789abcdef" ;
 buf [ 2 ] = digits [ character >> 12 ] ;
 buf [ 3 ] = digits [ ( character >> 8 ) & 0xf ] ;
 buf [ 4 ] = digits [ ( character >> 4 ) & 0xf ] ;
 buf [ 5 ] = digits [ character & 0xf ] ;
 }