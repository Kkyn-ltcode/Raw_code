void cephx_calc_client_server_challenge ( CephContext * cct , CryptoKey & secret , uint64_t server_challenge , uint64_t client_challenge , uint64_t * key , std : : string & error ) {
 CephXChallengeBlob b ;
 b . server_challenge = server_challenge ;
 b . client_challenge = client_challenge ;
 bufferlist enc ;
 if ( encode_encrypt ( cct , b , secret , enc , error ) ) return ;
 uint64_t k = 0 ;
 const uint64_t * p = ( const uint64_t * ) enc . c_str ( ) ;
 for ( int pos = 0 ;
 pos + sizeof ( k ) <= enc . length ( ) ;
 pos += sizeof ( k ) , p ++ ) k ^= mswab ( * p ) ;
 * key = k ;
 }