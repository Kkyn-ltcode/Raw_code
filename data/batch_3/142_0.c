int PEM_write_ ## name ( FILE * fp , type * x , const EVP_CIPHER * enc , unsigned char * kstr , int klen , pem_password_cb * cb , void * u ) ;
 # endif # define DECLARE_PEM_read_bio ( name , type ) type * PEM_read_bio_ ## name ( BIO * bp , type * * x , pem_password_cb * cb , void * u ) ;
 # define DECLARE_PEM_write_bio ( name , type ) int PEM_write_bio_ ## name ( BIO * bp , type * x ) ;
 # define DECLARE_PEM_write_bio_const ( name , type ) int PEM_write_bio_ ## name ( BIO * bp , const type * x ) ;
 # define DECLARE_PEM_write_cb_bio ( name , type ) int PEM_write_bio_ ## name ( BIO * bp , type * x , const EVP_CIPHER * enc , unsigned char * kstr , int klen , pem_password_cb * cb , void * u ) ;
 # define DECLARE_PEM_write ( name , type ) DECLARE_PEM_write_bio ( name , type ) DECLARE_PEM_write_fp ( name , type ) # define DECLARE_PEM_write_const ( name , type ) DECLARE_PEM_write_bio_const ( name , type ) DECLARE_PEM_write_fp_const ( name , type ) # define DECLARE_PEM_write_cb ( name , type ) DECLARE_PEM_write_cb_bio ( name , type ) DECLARE_PEM_write_cb_fp ( name , type ) # define DECLARE_PEM_read ( name , type ) DECLARE_PEM_read_bio ( name , type ) DECLARE_PEM_read_fp ( name , type ) # define DECLARE_PEM_rw ( name , type ) DECLARE_PEM_read ( name , type ) DECLARE_PEM_write ( name , type ) # define DECLARE_PEM_rw_const ( name , type ) DECLARE_PEM_read ( name , type ) DECLARE_PEM_write_const ( name , type ) # define DECLARE_PEM_rw_cb ( name , type ) DECLARE_PEM_read ( name , type ) DECLARE_PEM_write_cb ( name , type ) typedef int pem_password_cb ( char * buf , int size , int rwflag , void * userdata ) ;
 int PEM_get_EVP_CIPHER_INFO ( char * header , EVP_CIPHER_INFO * cipher ) ;
 int PEM_do_header ( EVP_CIPHER_INFO * cipher , unsigned char * data , long * len , pem_password_cb * callback , void * u ) ;
 int PEM_read_bio ( BIO * bp , char * * name , char * * header , unsigned char * * data , long * len ) ;
 # define PEM_FLAG_SECURE 0x1 # define PEM_FLAG_EAY_COMPATIBLE 0x2 # define PEM_FLAG_ONLY_B64 0x4 int PEM_read_bio_ex ( BIO * bp , char * * name , char * * header , unsigned char * * data , long * len , unsigned int flags ) ;
 int PEM_bytes_read_bio_secmem ( unsigned char * * pdata , long * plen , char * * pnm , const char * name , BIO * bp , pem_password_cb * cb , void * u ) ;
 int PEM_write_bio ( BIO * bp , const char * name , const char * hdr , const unsigned char * data , long len ) ;
 int PEM_bytes_read_bio ( unsigned char * * pdata , long * plen , char * * pnm , const char * name , BIO * bp , pem_password_cb * cb , void * u ) ;
 void * PEM_ASN1_read_bio ( d2i_of_void * d2i , const char * name , BIO * bp , void * * x , pem_password_cb * cb , void * u ) ;
 int PEM_ASN1_write_bio ( i2d_of_void * i2d , const char * name , BIO * bp , void * x , const EVP_CIPHER * enc , unsigned char * kstr , int klen , pem_password_cb * cb , void * u ) ;
 STACK_OF ( X509_INFO ) * PEM_X509_INFO_read_bio ( BIO * bp , STACK_OF ( X509_INFO ) * sk , pem_password_cb * cb , void * u ) ;
 int PEM_X509_INFO_write_bio ( BIO * bp , X509_INFO * xi , EVP_CIPHER * enc , unsigned char * kstr , int klen , pem_password_cb * cd , void * u ) ;
 # ifndef OPENSSL_NO_STDIO int PEM_read ( FILE * fp , char * * name , char * * header , unsigned char * * data , long * len ) ;
 int PEM_write ( FILE * fp , const char * name , const char * hdr , const unsigned char * data , long len ) ;
 void * PEM_ASN1_read ( d2i_of_void * d2i , const char * name , FILE * fp , void * * x , pem_password_cb * cb , void * u ) ;
 int PEM_ASN1_write ( i2d_of_void * i2d , const char * name , FILE * fp , void * x , const EVP_CIPHER * enc , unsigned char * kstr , int klen , pem_password_cb * callback , void * u ) ;
 STACK_OF ( X509_INFO ) * PEM_X509_INFO_read ( FILE * fp , STACK_OF ( X509_INFO ) * sk , pem_password_cb * cb , void * u ) ;
 # endif int PEM_SignInit ( EVP_MD_CTX * ctx , EVP_MD * type ) ;
 int PEM_SignUpdate ( EVP_MD_CTX * ctx , unsigned char * d , unsigned int cnt ) ;
 int PEM_SignFinal ( EVP_MD_CTX * ctx , unsigned char * sigret , unsigned int * siglen , EVP_PKEY * pkey ) ;
 int PEM_def_callback ( char * buf , int num , int rwflag , void * userdata ) ;
 void PEM_proc_type ( char * buf , int type ) ;
 void PEM_dek_info ( char * buf , const char * type , int len , char * str ) ;
 # include < openssl / symhacks . h > DECLARE_PEM_rw ( X509 , X509 ) DECLARE_PEM_rw ( X509_AUX , X509 ) DECLARE_PEM_rw ( X509_REQ , X509_REQ ) DECLARE_PEM_write ( X509_REQ_NEW , X509_REQ ) DECLARE_PEM_rw ( X509_CRL , X509_CRL ) DECLARE_PEM_rw ( PKCS7 , PKCS7 ) DECLARE_PEM_rw ( NETSCAPE_CERT_SEQUENCE , NETSCAPE_CERT_SEQUENCE ) DECLARE_PEM_rw ( PKCS8 , X509_SIG ) DECLARE_PEM_rw ( PKCS8_PRIV_KEY_INFO , PKCS8_PRIV_KEY_INFO ) # ifndef OPENSSL_NO_RSA DECLARE_PEM_rw_cb ( RSAPrivateKey , RSA ) DECLARE_PEM_rw_const ( RSAPublicKey , RSA ) DECLARE_PEM_rw ( RSA_PUBKEY , RSA ) # endif # ifndef OPENSSL_NO_DSA DECLARE_PEM_rw_cb ( DSAPrivateKey , DSA ) DECLARE_PEM_rw ( DSA_PUBKEY , DSA ) DECLARE_PEM_rw_const ( DSAparams , DSA ) # endif # ifndef OPENSSL_NO_EC DECLARE_PEM_rw_const ( ECPKParameters , EC_GROUP ) DECLARE_PEM_rw_cb ( ECPrivateKey , EC_KEY )