int tls1_enc ( SSL * s , int send ) {
 SSL3_RECORD * rec ;
 EVP_CIPHER_CTX * ds ;
 unsigned long l ;
 int bs , i , j , k , pad = 0 , ret , mac_size = 0 ;
 const EVP_CIPHER * enc ;
 if ( send ) {
 if ( EVP_MD_CTX_md ( s -> write_hash ) ) {
 int n = EVP_MD_CTX_size ( s -> write_hash ) ;
 OPENSSL_assert ( n >= 0 ) ;
 }
 ds = s -> enc_write_ctx ;
 rec = & ( s -> s3 -> wrec ) ;
 if ( s -> enc_write_ctx == NULL ) enc = NULL ;
 else {
 int ivlen ;
 enc = EVP_CIPHER_CTX_cipher ( s -> enc_write_ctx ) ;
 if ( s -> version >= TLS1_1_VERSION && EVP_CIPHER_mode ( enc ) == EVP_CIPH_CBC_MODE ) ivlen = EVP_CIPHER_iv_length ( enc ) ;
 else ivlen = 0 ;
 if ( ivlen > 1 ) {
 if ( rec -> data != rec -> input ) fprintf ( stderr , "%s:%d: rec->data != rec->input\n" , __FILE__ , __LINE__ ) ;
 else if ( RAND_bytes ( rec -> input , ivlen ) <= 0 ) return - 1 ;
 }
 }
 }
 else {
 if ( EVP_MD_CTX_md ( s -> read_hash ) ) {
 int n = EVP_MD_CTX_size ( s -> read_hash ) ;
 OPENSSL_assert ( n >= 0 ) ;
 }
 ds = s -> enc_read_ctx ;
 rec = & ( s -> s3 -> rrec ) ;
 if ( s -> enc_read_ctx == NULL ) enc = NULL ;
 else enc = EVP_CIPHER_CTX_cipher ( s -> enc_read_ctx ) ;
 }
 # ifdef KSSL_DEBUG printf ( "tls1_enc(%d)\n" , send ) ;
 # endif if ( ( s -> session == NULL ) || ( ds == NULL ) || ( enc == NULL ) ) {
 memmove ( rec -> data , rec -> input , rec -> length ) ;
 rec -> input = rec -> data ;
 ret = 1 ;
 }
 else {
 l = rec -> length ;
 bs = EVP_CIPHER_block_size ( ds -> cipher ) ;
 if ( EVP_CIPHER_flags ( ds -> cipher ) & EVP_CIPH_FLAG_AEAD_CIPHER ) {
 unsigned char buf [ 13 ] , * seq ;
 seq = send ? s -> s3 -> write_sequence : s -> s3 -> read_sequence ;
 if ( s -> version == DTLS1_VERSION || s -> version == DTLS1_BAD_VER ) {
 unsigned char dtlsseq [ 9 ] , * p = dtlsseq ;
 s2n ( send ? s -> d1 -> w_epoch : s -> d1 -> r_epoch , p ) ;
 memcpy ( p , & seq [ 2 ] , 6 ) ;
 memcpy ( buf , dtlsseq , 8 ) ;
 }
 else {
 memcpy ( buf , seq , 8 ) ;
 for ( i = 7 ;
 i >= 0 ;
 i -- ) {
 ++ seq [ i ] ;
 if ( seq [ i ] != 0 ) break ;
 }
 }
 buf [ 8 ] = rec -> type ;
 buf [ 9 ] = ( unsigned char ) ( s -> version >> 8 ) ;
 buf [ 10 ] = ( unsigned char ) ( s -> version ) ;
 buf [ 11 ] = rec -> length >> 8 ;
 buf [ 12 ] = rec -> length & 0xff ;
 pad = EVP_CIPHER_CTX_ctrl ( ds , EVP_CTRL_AEAD_TLS1_AAD , 13 , buf ) ;
 if ( send ) {
 l += pad ;
 rec -> length += pad ;
 }
 }
 else if ( ( bs != 1 ) && send ) {
 i = bs - ( ( int ) l % bs ) ;
 j = i - 1 ;
 if ( s -> options & SSL_OP_TLS_BLOCK_PADDING_BUG ) {
 if ( s -> s3 -> flags & TLS1_FLAGS_TLS_PADDING_BUG ) j ++ ;
 }
 for ( k = ( int ) l ;
 k < ( int ) ( l + i ) ;
 k ++ ) rec -> input [ k ] = j ;
 l += i ;
 rec -> length += i ;
 }
 # ifdef KSSL_DEBUG {
 unsigned long ui ;
 printf ( "EVP_Cipher(ds=%p,rec->data=%p,rec->input=%p,l=%ld) ==>\n" , ds , rec -> data , rec -> input , l ) ;
 printf ( "\tEVP_CIPHER_CTX: %d buf_len, %d key_len [%d %d], %d iv_len\n" , ds -> buf_len , ds -> cipher -> key_len , DES_KEY_SZ , DES_SCHEDULE_SZ , ds -> cipher -> iv_len ) ;
 printf ( "\t\tIV: " ) ;
 for ( i = 0 ;
 i < ds -> cipher -> iv_len ;
 i ++ ) printf ( "%02X" , ds -> iv [ i ] ) ;
 printf ( "\n" ) ;
 printf ( "\trec->input=" ) ;
 for ( ui = 0 ;
 ui < l ;
 ui ++ ) printf ( " %02x" , rec -> input [ ui ] ) ;
 printf ( "\n" ) ;
 }
 # endif if ( ! send ) {
 if ( l == 0 || l % bs != 0 ) return 0 ;
 }
 i = EVP_Cipher ( ds , rec -> data , rec -> input , l ) ;
 if ( ( EVP_CIPHER_flags ( ds -> cipher ) & EVP_CIPH_FLAG_CUSTOM_CIPHER ) ? ( i < 0 ) : ( i == 0 ) ) return - 1 ;
 if ( EVP_CIPHER_mode ( enc ) == EVP_CIPH_GCM_MODE && ! send ) {
 rec -> data += EVP_GCM_TLS_EXPLICIT_IV_LEN ;
 rec -> input += EVP_GCM_TLS_EXPLICIT_IV_LEN ;
 rec -> length -= EVP_GCM_TLS_EXPLICIT_IV_LEN ;
 }
 # ifdef KSSL_DEBUG {
 unsigned long i ;
 printf ( "\trec->data=" ) ;
 for ( i = 0 ;
 i < l ;
 i ++ ) printf ( " %02x" , rec -> data [ i ] ) ;
 printf ( "\n" ) ;
 }
 # endif ret = 1 ;
 if ( EVP_MD_CTX_md ( s -> read_hash ) != NULL ) mac_size = EVP_MD_CTX_size ( s -> read_hash ) ;
 if ( ( bs != 1 ) && ! send ) ret = tls1_cbc_remove_padding ( s , rec , bs , mac_size ) ;
 if ( pad && ! send ) rec -> length -= pad ;
 }
 return ret ;
 }