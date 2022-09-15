char * ksba_oid_to_str ( const char * buffer , size_t length ) {
 const unsigned char * buf = buffer ;
 char * string , * p ;
 int n = 0 ;
 unsigned long val , valmask ;
 valmask = ( unsigned long ) 0xfe << ( 8 * ( sizeof ( valmask ) - 1 ) ) ;
 string = p = xtrymalloc ( length * ( 1 + 3 ) + 2 + 1 ) ;
 if ( ! string ) return NULL ;
 if ( ! length ) {
 * p = 0 ;
 return string ;
 }
 if ( buf [ 0 ] < 40 ) p += sprintf ( p , "0.%d" , buf [ n ] ) ;
 else if ( buf [ 0 ] < 80 ) p += sprintf ( p , "1.%d" , buf [ n ] - 40 ) ;
 else {
 val = buf [ n ] & 0x7f ;
 while ( ( buf [ n ] & 0x80 ) && ++ n < length ) {
 if ( ( val & valmask ) ) goto badoid ;
 val <<= 7 ;
 val |= buf [ n ] & 0x7f ;
 }
 val -= 80 ;
 sprintf ( p , "2.%lu" , val ) ;
 p += strlen ( p ) ;
 }
 for ( n ++ ;
 n < length ;
 n ++ ) {
 val = buf [ n ] & 0x7f ;
 while ( ( buf [ n ] & 0x80 ) && ++ n < length ) {
 if ( ( val & valmask ) ) goto badoid ;
 val <<= 7 ;
 val |= buf [ n ] & 0x7f ;
 }
 sprintf ( p , ".%lu" , val ) ;
 p += strlen ( p ) ;
 }
 * p = 0 ;
 return string ;
 badoid : xfree ( string ) ;
 return xtrystrdup ( "1.3.6.1.4.1.11591.2.12242973" ) ;
 }