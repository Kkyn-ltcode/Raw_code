static char * normal_dtoa ( double d ) {
 char * buf ;
 char * pch_e ;
 char * pch_nz ;
 LIB_GETBUF ( buf ) ;
 snprintf ( buf , LIB_BUFLENGTH , "%g" , d ) ;
 pch_e = strchr ( buf , 'e' ) ;
 if ( NULL == pch_e ) {
 pch_e = strchr ( buf , 'E' ) ;
 if ( NULL == pch_e ) return buf ;
 * pch_e = 'e' ;
 }
 pch_e ++ ;
 if ( '-' == * pch_e ) pch_e ++ ;
 pch_nz = pch_e ;
 while ( '0' == * pch_nz ) pch_nz ++ ;
 if ( pch_nz == pch_e ) return buf ;
 strncpy ( pch_e , pch_nz , LIB_BUFLENGTH - ( pch_e - buf ) ) ;
 return buf ;
 }