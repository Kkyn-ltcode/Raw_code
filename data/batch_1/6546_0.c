static PyObject * string_rstrip ( PyStringObject * self , PyObject * args ) {
 if ( PyTuple_GET_SIZE ( args ) == 0 ) return do_strip ( self , RIGHTSTRIP ) ;
 else return do_argstrip ( self , RIGHTSTRIP , args ) ;
 }