EC_KEY * d2i_EC_PUBKEY_bio ( BIO * bp , EC_KEY * * eckey ) {
 return ASN1_d2i_bio_of ( EC_KEY , EC_KEY_new , d2i_EC_PUBKEY , bp , eckey ) ;
 }