static char * convert_string_datum ( Datum value , Oid typid ) {
 char * val ;
 switch ( typid ) {
 case CHAROID : val = ( char * ) palloc ( 2 ) ;
 val [ 0 ] = DatumGetChar ( value ) ;
 val [ 1 ] = '\0' ;
 break ;
 case BPCHAROID : case VARCHAROID : case TEXTOID : val = TextDatumGetCString ( value ) ;
 break ;
 case NAMEOID : {
 NameData * nm = ( NameData * ) DatumGetPointer ( value ) ;
 val = pstrdup ( NameStr ( * nm ) ) ;
 break ;
 }
 default : elog ( ERROR , "unsupported type: %u" , typid ) ;
 return NULL ;
 }
 if ( ! lc_collate_is_c ( DEFAULT_COLLATION_OID ) ) {
 char * xfrmstr ;
 size_t xfrmlen ;
 size_t xfrmlen2 PG_USED_FOR_ASSERTS_ONLY ;
 # if _MSC_VER == 1400 {
 char x [ 1 ] ;
 xfrmlen = strxfrm ( x , val , 0 ) ;
 }
 # else xfrmlen = strxfrm ( NULL , val , 0 ) ;
 # endif # ifdef WIN32 if ( xfrmlen == INT_MAX ) return val ;
 # endif xfrmstr = ( char * ) palloc ( xfrmlen + 1 ) ;
 xfrmlen2 = strxfrm ( xfrmstr , val , xfrmlen + 1 ) ;
 Assert ( xfrmlen2 <= xfrmlen ) ;
 pfree ( val ) ;
 val = xfrmstr ;
 }
 return val ;
 }