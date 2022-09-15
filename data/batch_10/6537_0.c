PyObject * PyString_FromFormatV ( const char * format , va_list vargs ) {
 va_list count ;
 Py_ssize_t n = 0 ;
 const char * f ;
 char * s ;
 PyObject * string ;
 # ifdef VA_LIST_IS_ARRAY Py_MEMCPY ( count , vargs , sizeof ( va_list ) ) ;
 # else # ifdef __va_copy __va_copy ( count , vargs ) ;
 # else count = vargs ;
 # endif # endif for ( f = format ;
 * f ;
 f ++ ) {
 if ( * f == '%' ) {
 # ifdef HAVE_LONG_LONG int longlongflag = 0 ;
 # endif const char * p = f ;
 while ( * ++ f && * f != '%' && ! isalpha ( Py_CHARMASK ( * f ) ) ) ;
 if ( * f == 'l' ) {
 if ( f [ 1 ] == 'd' || f [ 1 ] == 'u' ) {
 ++ f ;
 }
 # ifdef HAVE_LONG_LONG else if ( f [ 1 ] == 'l' && ( f [ 2 ] == 'd' || f [ 2 ] == 'u' ) ) {
 longlongflag = 1 ;
 f += 2 ;
 }
 # endif }
 else if ( * f == 'z' && ( f [ 1 ] == 'd' || f [ 1 ] == 'u' ) ) {
 ++ f ;
 }
 switch ( * f ) {
 case 'c' : ( void ) va_arg ( count , int ) ;
 case '%' : n ++ ;
 break ;
 case 'd' : case 'u' : case 'i' : case 'x' : ( void ) va_arg ( count , int ) ;
 # ifdef HAVE_LONG_LONG if ( longlongflag ) n += 2 + ( SIZEOF_LONG_LONG * 53 - 1 ) / 22 ;
 else # endif n += 20 ;
 break ;
 case 's' : s = va_arg ( count , char * ) ;
 n += strlen ( s ) ;
 break ;
 case 'p' : ( void ) va_arg ( count , int ) ;
 n += 19 ;
 break ;
 default : n += strlen ( p ) ;
 goto expand ;
 }
 }
 else n ++ ;
 }
 expand : string = PyString_FromStringAndSize ( NULL , n ) ;
 if ( ! string ) return NULL ;
 s = PyString_AsString ( string ) ;
 for ( f = format ;
 * f ;
 f ++ ) {
 if ( * f == '%' ) {
 const char * p = f ++ ;
 Py_ssize_t i ;
 int longflag = 0 ;
 # ifdef HAVE_LONG_LONG int longlongflag = 0 ;
 # endif int size_tflag = 0 ;
 n = 0 ;
 while ( isdigit ( Py_CHARMASK ( * f ) ) ) n = ( n * 10 ) + * f ++ - '0' ;
 if ( * f == '.' ) {
 f ++ ;
 n = 0 ;
 while ( isdigit ( Py_CHARMASK ( * f ) ) ) n = ( n * 10 ) + * f ++ - '0' ;
 }
 while ( * f && * f != '%' && ! isalpha ( Py_CHARMASK ( * f ) ) ) f ++ ;
 if ( * f == 'l' ) {
 if ( f [ 1 ] == 'd' || f [ 1 ] == 'u' ) {
 longflag = 1 ;
 ++ f ;
 }
 # ifdef HAVE_LONG_LONG else if ( f [ 1 ] == 'l' && ( f [ 2 ] == 'd' || f [ 2 ] == 'u' ) ) {
 longlongflag = 1 ;
 f += 2 ;
 }
 # endif }
 else if ( * f == 'z' && ( f [ 1 ] == 'd' || f [ 1 ] == 'u' ) ) {
 size_tflag = 1 ;
 ++ f ;
 }
 switch ( * f ) {
 case 'c' : * s ++ = va_arg ( vargs , int ) ;
 break ;
 case 'd' : if ( longflag ) sprintf ( s , "%ld" , va_arg ( vargs , long ) ) ;
 # ifdef HAVE_LONG_LONG else if ( longlongflag ) sprintf ( s , "%" PY_FORMAT_LONG_LONG "d" , va_arg ( vargs , PY_LONG_LONG ) ) ;
 # endif else if ( size_tflag ) sprintf ( s , "%" PY_FORMAT_SIZE_T "d" , va_arg ( vargs , Py_ssize_t ) ) ;
 else sprintf ( s , "%d" , va_arg ( vargs , int ) ) ;
 s += strlen ( s ) ;
 break ;
 case 'u' : if ( longflag ) sprintf ( s , "%lu" , va_arg ( vargs , unsigned long ) ) ;
 # ifdef HAVE_LONG_LONG else if ( longlongflag ) sprintf ( s , "%" PY_FORMAT_LONG_LONG "u" , va_arg ( vargs , PY_LONG_LONG ) ) ;
 # endif else if ( size_tflag ) sprintf ( s , "%" PY_FORMAT_SIZE_T "u" , va_arg ( vargs , size_t ) ) ;
 else sprintf ( s , "%u" , va_arg ( vargs , unsigned int ) ) ;
 s += strlen ( s ) ;
 break ;
 case 'i' : sprintf ( s , "%i" , va_arg ( vargs , int ) ) ;
 s += strlen ( s ) ;
 break ;
 case 'x' : sprintf ( s , "%x" , va_arg ( vargs , int ) ) ;
 s += strlen ( s ) ;
 break ;
 case 's' : p = va_arg ( vargs , char * ) ;
 i = strlen ( p ) ;
 if ( n > 0 && i > n ) i = n ;
 Py_MEMCPY ( s , p , i ) ;
 s += i ;
 break ;
 case 'p' : sprintf ( s , "%p" , va_arg ( vargs , void * ) ) ;
 if ( s [ 1 ] == 'X' ) s [ 1 ] = 'x' ;
 else if ( s [ 1 ] != 'x' ) {
 memmove ( s + 2 , s , strlen ( s ) + 1 ) ;
 s [ 0 ] = '0' ;
 s [ 1 ] = 'x' ;
 }
 s += strlen ( s ) ;
 break ;
 case '%' : * s ++ = '%' ;
 break ;
 default : strcpy ( s , p ) ;
 s += strlen ( s ) ;
 goto end ;
 }
 }
 else * s ++ = * f ;
 }
 end : if ( _PyString_Resize ( & string , s - PyString_AS_STRING ( string ) ) ) return NULL ;
 return string ;
 }