int authreadkeys ( const char * file ) {
 FILE * fp ;
 char * line ;
 char * token ;
 keyid_t keyno ;
 int keytype ;
 char buf [ 512 ] ;
 u_char keystr [ 32 ] ;
 size_t len ;
 size_t j ;
 fp = fopen ( file , "r" ) ;
 if ( fp == NULL ) {
 msyslog ( LOG_ERR , "authreadkeys: file %s: %m" , file ) ;
 return ( 0 ) ;
 }
 INIT_SSL ( ) ;
 auth_delkeys ( ) ;
 while ( ( line = fgets ( buf , sizeof buf , fp ) ) != NULL ) {
 token = nexttok ( & line ) ;
 if ( token == NULL ) continue ;
 keyno = atoi ( token ) ;
 if ( keyno == 0 ) {
 msyslog ( LOG_ERR , "authreadkeys: cannot change key %s" , token ) ;
 continue ;
 }
 if ( keyno > NTP_MAXKEY ) {
 msyslog ( LOG_ERR , "authreadkeys: key %s > %d reserved for Autokey" , token , NTP_MAXKEY ) ;
 continue ;
 }
 token = nexttok ( & line ) ;
 if ( token == NULL ) {
 msyslog ( LOG_ERR , "authreadkeys: no key type for key %d" , keyno ) ;
 continue ;
 }
 # ifdef OPENSSL keytype = keytype_from_text ( token , NULL ) ;
 if ( keytype == 0 ) {
 msyslog ( LOG_ERR , "authreadkeys: invalid type for key %d" , keyno ) ;
 continue ;
 }
 if ( EVP_get_digestbynid ( keytype ) == NULL ) {
 msyslog ( LOG_ERR , "authreadkeys: no algorithm for key %d" , keyno ) ;
 continue ;
 }
 # else if ( ! ( * token == 'M' || * token == 'm' ) ) {
 msyslog ( LOG_ERR , "authreadkeys: invalid type for key %d" , keyno ) ;
 continue ;
 }
 keytype = KEY_TYPE_MD5 ;
 # endif token = nexttok ( & line ) ;
 if ( token == NULL ) {
 msyslog ( LOG_ERR , "authreadkeys: no key for key %d" , keyno ) ;
 continue ;
 }
 len = strlen ( token ) ;
 if ( len <= 20 ) {
 MD5auth_setkey ( keyno , keytype , ( u_char * ) token , len ) ;
 }
 else {
 char hex [ ] = "0123456789abcdef" ;
 u_char temp ;
 char * ptr ;
 size_t jlim ;
 jlim = min ( len , 2 * sizeof ( keystr ) ) ;
 for ( j = 0 ;
 j < jlim ;
 j ++ ) {
 ptr = strchr ( hex , tolower ( ( unsigned char ) token [ j ] ) ) ;
 if ( ptr == NULL ) break ;
 temp = ( u_char ) ( ptr - hex ) ;
 if ( j & 1 ) keystr [ j / 2 ] |= temp ;
 else keystr [ j / 2 ] = temp << 4 ;
 }
 if ( j < jlim ) {
 msyslog ( LOG_ERR , "authreadkeys: invalid hex digit for key %d" , keyno ) ;
 continue ;
 }
 MD5auth_setkey ( keyno , keytype , keystr , jlim / 2 ) ;
 }
 }
 fclose ( fp ) ;
 return ( 1 ) ;
 }