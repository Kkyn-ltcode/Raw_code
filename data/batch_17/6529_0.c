static PyObject * string_isdigit ( PyStringObject * self ) {
 register const unsigned char * p = ( unsigned char * ) PyString_AS_STRING ( self ) ;
 register const unsigned char * e ;
 if ( PyString_GET_SIZE ( self ) == 1 && isdigit ( * p ) ) return PyBool_FromLong ( 1 ) ;
 if ( PyString_GET_SIZE ( self ) == 0 ) return PyBool_FromLong ( 0 ) ;
 e = p + PyString_GET_SIZE ( self ) ;
 for ( ;
 p < e ;
 p ++ ) {
 if ( ! isdigit ( * p ) ) return PyBool_FromLong ( 0 ) ;
 }
 return PyBool_FromLong ( 1 ) ;
 }