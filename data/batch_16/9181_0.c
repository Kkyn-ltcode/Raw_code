static const char * cmd_unicode_codepage ( cmd_parms * cmd , void * _dcfg , const char * p1 ) {
 long val ;
 val = atol ( p1 ) ;
 if ( val <= 0 ) {
 return apr_psprintf ( cmd -> pool , "ModSecurity: Invalid setting for " "SecUnicodeCodePage: %s" , p1 ) ;
 }
 unicode_codepage = ( unsigned long int ) val ;
 return NULL ;
 }