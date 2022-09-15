int i2d_ ## name ( type * a , unsigned char * * out ) ;
 DECLARE_ASN1_ITEM ( itname ) # define DECLARE_ASN1_ENCODE_FUNCTIONS_const ( type , name ) type * d2i_ ## name ( type * * a , const unsigned char * * in , long len ) ;
 int i2d_ ## name ( const type * a , unsigned char * * out ) ;
 DECLARE_ASN1_ITEM ( name ) # define DECLARE_ASN1_NDEF_FUNCTION ( name ) int i2d_ ## name ## _NDEF ( name * a , unsigned char * * out ) ;
 # define DECLARE_ASN1_FUNCTIONS_const ( name ) DECLARE_ASN1_ALLOC_FUNCTIONS ( name ) DECLARE_ASN1_ENCODE_FUNCTIONS_const ( name , name ) # define DECLARE_ASN1_ALLOC_FUNCTIONS_name ( type , name ) type * name ## _new ( void ) ;
 void name ## _free ( type * a ) ;
 # define DECLARE_ASN1_PRINT_FUNCTION ( stname ) DECLARE_ASN1_PRINT_FUNCTION_fname ( stname , stname ) # define DECLARE_ASN1_PRINT_FUNCTION_fname ( stname , fname ) int fname ## _print_ctx ( BIO * out , stname * x , int indent , const ASN1_PCTX * pctx ) ;
 # define D2I_OF ( type ) type * ( * ) ( type * * , const unsigned char * * , long ) # define I2D_OF ( type ) int ( * ) ( type * , unsigned char * * ) # define I2D_OF_const ( type ) int ( * ) ( const type * , unsigned char * * ) # define CHECKED_D2I_OF ( type , d2i ) ( ( d2i_of_void * ) ( 1 ? d2i : ( ( D2I_OF ( type ) ) 0 ) ) ) # define CHECKED_I2D_OF ( type , i2d ) ( ( i2d_of_void * ) ( 1 ? i2d : ( ( I2D_OF ( type ) ) 0 ) ) ) # define CHECKED_NEW_OF ( type , xnew ) ( ( void * ( * ) ( void ) ) ( 1 ? xnew : ( ( type * ( * ) ( void ) ) 0 ) ) ) # define CHECKED_PTR_OF ( type , p ) ( ( void * ) ( 1 ? p : ( type * ) 0 ) ) # define CHECKED_PPTR_OF ( type , p ) ( ( void * * ) ( 1 ? p : ( type * * ) 0 ) ) # define TYPEDEF_D2I_OF ( type ) typedef type * d2i_of_ ## type ( type * * , const unsigned char * * , long ) # define TYPEDEF_I2D_OF ( type ) typedef int i2d_of_ ## type ( type * , unsigned char * * ) # define TYPEDEF_D2I2D_OF ( type ) TYPEDEF_D2I_OF ( type ) ;
 TYPEDEF_I2D_OF ( type ) TYPEDEF_D2I2D_OF ( void ) ;
 # ifndef OPENSSL_EXPORT_VAR_AS_FUNCTION typedef const ASN1_ITEM ASN1_ITEM_EXP ;
 # define ASN1_ITEM_ptr ( iptr ) ( iptr ) # define ASN1_ITEM_ref ( iptr ) ( & ( iptr ## _it ) ) # define ASN1_ITEM_rptr ( ref ) ( & ( ref ## _it ) ) # define DECLARE_ASN1_ITEM ( name ) OPENSSL_EXTERN const ASN1_ITEM name ## _it ;
 # else typedef const ASN1_ITEM * ASN1_ITEM_EXP ( void ) ;
 # define ASN1_ITEM_ptr ( iptr ) ( iptr ( ) ) # define ASN1_ITEM_ref ( iptr ) ( iptr ## _it ) # define ASN1_ITEM_rptr ( ref ) ( ref ## _it ( ) ) # define DECLARE_ASN1_ITEM ( name ) const ASN1_ITEM * name ## _it ( void ) ;
 # endif # define ASN1_STRFLGS_ESC_2253 1 # define ASN1_STRFLGS_ESC_CTRL 2 # define ASN1_STRFLGS_ESC_MSB 4 # define ASN1_STRFLGS_ESC_QUOTE 8 # define CHARTYPE_PRINTABLESTRING 0x10 # define CHARTYPE_FIRST_ESC_2253 0x20 # define CHARTYPE_LAST_ESC_2253 0x40 # define ASN1_STRFLGS_UTF8_CONVERT 0x10 # define ASN1_STRFLGS_IGNORE_TYPE 0x20 # define ASN1_STRFLGS_SHOW_TYPE 0x40 # define ASN1_STRFLGS_DUMP_ALL 0x80 # define ASN1_STRFLGS_DUMP_UNKNOWN 0x100 # define ASN1_STRFLGS_DUMP_DER 0x200 # define ASN1_STRFLGS_ESC_2254 0x400 # define ASN1_STRFLGS_RFC2253 ( ASN1_STRFLGS_ESC_2253 | ASN1_STRFLGS_ESC_CTRL | ASN1_STRFLGS_ESC_MSB | ASN1_STRFLGS_UTF8_CONVERT | ASN1_STRFLGS_DUMP_UNKNOWN | ASN1_STRFLGS_DUMP_DER ) DEFINE_STACK_OF ( ASN1_INTEGER ) DEFINE_STACK_OF ( ASN1_GENERALSTRING ) DEFINE_STACK_OF ( ASN1_UTF8STRING ) typedef struct asn1_type_st {
 int type ;
 union {
 char * ptr ;
 ASN1_BOOLEAN boolean ;
 ASN1_STRING * asn1_string ;
 ASN1_OBJECT * object ;
 ASN1_INTEGER * integer ;
 ASN1_ENUMERATED * enumerated ;
 ASN1_BIT_STRING * bit_string ;
 ASN1_OCTET_STRING * octet_string ;
 ASN1_PRINTABLESTRING * printablestring ;
 ASN1_T61STRING * t61string ;
 ASN1_IA5STRING * ia5string ;
 ASN1_GENERALSTRING * generalstring ;
 ASN1_BMPSTRING * bmpstring ;
 ASN1_UNIVERSALSTRING * universalstring ;
 ASN1_UTCTIME * utctime ;
 ASN1_GENERALIZEDTIME * generalizedtime ;
 ASN1_VISIBLESTRING * visiblestring ;
 ASN1_UTF8STRING * utf8string ;
 ASN1_STRING * set ;
 ASN1_STRING * sequence ;
 ASN1_VALUE * asn1_value ;
 }
 value ;
 }
 ASN1_TYPE ;
 DEFINE_STACK_OF ( ASN1_TYPE ) typedef STACK_OF ( ASN1_TYPE ) ASN1_SEQUENCE_ANY ;
 DECLARE_ASN1_ENCODE_FUNCTIONS_const ( ASN1_SEQUENCE_ANY , ASN1_SEQUENCE_ANY ) DECLARE_ASN1_ENCODE_FUNCTIONS_const ( ASN1_SEQUENCE_ANY , ASN1_SET_ANY ) typedef struct BIT_STRING_BITNAME_st {
 int bitnum ;
 const char * lname ;
 const char * sname ;
 }
 BIT_STRING_BITNAME ;
 # define B_ASN1_TIME B_ASN1_UTCTIME | B_ASN1_GENERALIZEDTIME # define B_ASN1_PRINTABLE B_ASN1_NUMERICSTRING | B_ASN1_PRINTABLESTRING | B_ASN1_T61STRING | B_ASN1_IA5STRING | B_ASN1_BIT_STRING | B_ASN1_UNIVERSALSTRING | B_ASN1_BMPSTRING | B_ASN1_UTF8STRING | B_ASN1_SEQUENCE | B_ASN1_UNKNOWN # define B_ASN1_DIRECTORYSTRING B_ASN1_PRINTABLESTRING | B_ASN1_TELETEXSTRING | B_ASN1_BMPSTRING | B_ASN1_UNIVERSALSTRING | B_ASN1_UTF8STRING # define B_ASN1_DISPLAYTEXT B_ASN1_IA5STRING | B_ASN1_VISIBLESTRING | B_ASN1_BMPSTRING | B_ASN1_UTF8STRING DECLARE_ASN1_FUNCTIONS_fname ( ASN1_TYPE , ASN1_ANY , ASN1_TYPE ) int ASN1_TYPE_get ( const ASN1_TYPE * a ) ;
 void ASN1_TYPE_set ( ASN1_TYPE * a , int type , void * value ) ;
 int ASN1_TYPE_set1 ( ASN1_TYPE * a , int type , const void * value ) ;
 int ASN1_TYPE_cmp ( const ASN1_TYPE * a , const ASN1_TYPE * b ) ;
 ASN1_TYPE * ASN1_TYPE_pack_sequence ( const ASN1_ITEM * it , void * s , ASN1_TYPE * * t ) ;
 void * ASN1_TYPE_unpack_sequence ( const ASN1_ITEM * it , const ASN1_TYPE * t ) ;
 ASN1_OBJECT * ASN1_OBJECT_new ( void ) ;
 void ASN1_OBJECT_free ( ASN1_OBJECT * a ) ;
 int i2d_ASN1_OBJECT ( const ASN1_OBJECT * a , unsigned char * * pp ) ;
 ASN1_OBJECT * d2i_ASN1_OBJECT ( ASN1_OBJECT * * a , const unsigned char * * pp , long length ) ;
 DECLARE_ASN1_ITEM ( ASN1_OBJECT ) DEFINE_STACK_OF ( ASN1_OBJECT ) ASN1_STRING * ASN1_STRING_new ( void ) ;
 void ASN1_STRING_free ( ASN1_STRING * a ) ;
 void ASN1_STRING_clear_free ( ASN1_STRING * a ) ;
 int ASN1_STRING_copy ( ASN1_STRING * dst , const ASN1_STRING * str ) ;
 ASN1_STRING * ASN1_STRING_dup ( const ASN1_STRING * a ) ;
 ASN1_STRING * ASN1_STRING_type_new ( int type ) ;
 int ASN1_STRING_cmp ( const ASN1_STRING * a , const ASN1_STRING * b ) ;
 int ASN1_STRING_set ( ASN1_STRING * str , const void * data , int len ) ;
 void ASN1_STRING_set0 ( ASN1_STRING * str , void * data , int len ) ;
 int ASN1_STRING_length ( const ASN1_STRING * x ) ;
 void ASN1_STRING_length_set ( ASN1_STRING * x , int n ) ;
 int ASN1_STRING_type ( const ASN1_STRING * x ) ;
 DEPRECATEDIN_1_1_0 ( unsigned char * ASN1_STRING_data ( ASN1_STRING * x ) ) const unsigned char * ASN1_STRING_get0_data ( const ASN1_STRING * x ) ;
 DECLARE_ASN1_FUNCTIONS ( ASN1_BIT_STRING )