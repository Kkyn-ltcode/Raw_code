static ossl_inline sk_ ## t1 ## _compfunc sk_ ## t1 ## _set_cmp_func ( STACK_OF ( t1 ) * sk , sk_ ## t1 ## _compfunc compare ) {
 return ( sk_ ## t1 ## _compfunc ) OPENSSL_sk_set_cmp_func ( ( OPENSSL_STACK * ) sk , ( OPENSSL_sk_compfunc ) compare ) ;
 }
 # define DEFINE_SPECIAL_STACK_OF ( t1 , t2 ) SKM_DEFINE_STACK_OF ( t1 , t2 , t2 ) # define DEFINE_STACK_OF ( t ) SKM_DEFINE_STACK_OF ( t , t , t ) # define DEFINE_SPECIAL_STACK_OF_CONST ( t1 , t2 ) SKM_DEFINE_STACK_OF ( t1 , const t2 , t2 ) # define DEFINE_STACK_OF_CONST ( t ) SKM_DEFINE_STACK_OF ( t , const t , t ) typedef char * OPENSSL_STRING ;
 typedef const char * OPENSSL_CSTRING ;
 DEFINE_SPECIAL_STACK_OF ( OPENSSL_STRING , char ) DEFINE_SPECIAL_STACK_OF_CONST ( OPENSSL_CSTRING , char )