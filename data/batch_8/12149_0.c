int i2d_X509_CRL_fp ( FILE * fp , X509_CRL * crl ) {
 return ASN1_item_i2d_fp ( ASN1_ITEM_rptr ( X509_CRL ) , fp , crl ) ;
 }