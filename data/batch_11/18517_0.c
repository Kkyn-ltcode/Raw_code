static const char * U_CALLCONV _SCSUGetName ( const UConverter * cnv ) {
 SCSUData * scsu = ( SCSUData * ) cnv -> extraInfo ;
 switch ( scsu -> locale ) {
 case l_ja : return "SCSU,locale=ja" ;
 default : return "SCSU" ;
 }
 }