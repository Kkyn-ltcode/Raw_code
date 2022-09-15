static int string_print ( PyStringObject * op , FILE * fp , int flags ) {
 Py_ssize_t i , str_len ;
 char c ;
 int quote ;
 if ( ! PyString_CheckExact ( op ) ) {
 int ret ;
 op = ( PyStringObject * ) PyObject_Str ( ( PyObject * ) op ) ;
 if ( op == NULL ) return - 1 ;
 ret = string_print ( op , fp , flags ) ;
 Py_DECREF ( op ) ;
 return ret ;
 }
 if ( flags & Py_PRINT_RAW ) {
 char * data = op -> ob_sval ;
 Py_ssize_t size = Py_SIZE ( op ) ;
 Py_BEGIN_ALLOW_THREADS while ( size > INT_MAX ) {
 const int chunk_size = INT_MAX & ~ 0x3FFF ;
 fwrite ( data , 1 , chunk_size , fp ) ;
 data += chunk_size ;
 size -= chunk_size ;
 }
 # ifdef __VMS if ( size ) fwrite ( data , ( size_t ) size , 1 , fp ) ;
 # else fwrite ( data , 1 , ( size_t ) size , fp ) ;
 # endif Py_END_ALLOW_THREADS return 0 ;
 }
 quote = '\'' ;
 if ( memchr ( op -> ob_sval , '\'' , Py_SIZE ( op ) ) && ! memchr ( op -> ob_sval , '"' , Py_SIZE ( op ) ) ) quote = '"' ;
 str_len = Py_SIZE ( op ) ;
 Py_BEGIN_ALLOW_THREADS fputc ( quote , fp ) ;
 for ( i = 0 ;
 i < str_len ;
 i ++ ) {
 c = op -> ob_sval [ i ] ;
 if ( c == quote || c == '\\' ) fprintf ( fp , "\\%c" , c ) ;
 else if ( c == '\t' ) fprintf ( fp , "\\t" ) ;
 else if ( c == '\n' ) fprintf ( fp , "\\n" ) ;
 else if ( c == '\r' ) fprintf ( fp , "\\r" ) ;
 else if ( c < ' ' || c >= 0x7f ) fprintf ( fp , "\\x%02x" , c & 0xff ) ;
 else fputc ( c , fp ) ;
 }
 fputc ( quote , fp ) ;
 Py_END_ALLOW_THREADS return 0 ;
 }