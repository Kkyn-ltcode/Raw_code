static void hmac_md5 ( const char * password , char * challenge , unsigned char * response ) {
 struct Md5Ctx ctx ;
 unsigned char ipad [ MD5_BLOCK_LEN ] = {
 0 }
 ;
 unsigned char opad [ MD5_BLOCK_LEN ] = {
 0 }
 ;
 unsigned char secret [ MD5_BLOCK_LEN + 1 ] ;
 size_t secret_len ;
 secret_len = strlen ( password ) ;
 if ( secret_len > MD5_BLOCK_LEN ) {
 unsigned char hash_passwd [ MD5_DIGEST_LEN ] ;
 mutt_md5_bytes ( password , secret_len , hash_passwd ) ;
 mutt_str_strfcpy ( ( char * ) secret , ( char * ) hash_passwd , MD5_DIGEST_LEN ) ;
 secret_len = MD5_DIGEST_LEN ;
 }
 else mutt_str_strfcpy ( ( char * ) secret , password , sizeof ( secret ) ) ;
 memcpy ( ipad , secret , secret_len ) ;
 memcpy ( opad , secret , secret_len ) ;
 for ( int i = 0 ;
 i < MD5_BLOCK_LEN ;
 i ++ ) {
 ipad [ i ] ^= 0x36 ;
 opad [ i ] ^= 0x5c ;
 }
 mutt_md5_init_ctx ( & ctx ) ;
 mutt_md5_process_bytes ( ipad , MD5_BLOCK_LEN , & ctx ) ;
 mutt_md5_process ( challenge , & ctx ) ;
 mutt_md5_finish_ctx ( & ctx , response ) ;
 mutt_md5_init_ctx ( & ctx ) ;
 mutt_md5_process_bytes ( opad , MD5_BLOCK_LEN , & ctx ) ;
 mutt_md5_process_bytes ( response , MD5_DIGEST_LEN , & ctx ) ;
 mutt_md5_finish_ctx ( & ctx , response ) ;
 }