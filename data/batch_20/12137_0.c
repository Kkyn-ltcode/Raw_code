X509_REQ * d2i_X509_REQ_bio ( BIO * bp , X509_REQ * * req ) {
 return ASN1_item_d2i_bio ( ASN1_ITEM_rptr ( X509_REQ ) , bp , req ) ;
 }