void ff_h264_parse_framesize ( AVCodecParameters * par , const char * p ) {
 char buf1 [ 50 ] ;
 char * dst = buf1 ;
 while ( * p && * p == ' ' ) p ++ ;
 while ( * p && * p != ' ' ) p ++ ;
 while ( * p && * p == ' ' ) p ++ ;
 while ( * p && * p != '-' && ( dst - buf1 ) < sizeof ( buf1 ) - 1 ) * dst ++ = * p ++ ;
 * dst = '\0' ;
 par -> width = atoi ( buf1 ) ;
 par -> height = atoi ( p + 1 ) ;
 }