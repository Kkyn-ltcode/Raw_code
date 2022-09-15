static PyObject * string_rindex ( PyStringObject * self , PyObject * args ) {
 Py_ssize_t result = string_find_internal ( self , args , - 1 ) ;
 if ( result == - 2 ) return NULL ;
 if ( result == - 1 ) {
 PyErr_SetString ( PyExc_ValueError , "substring not found" ) ;
 return NULL ;
 }
 return PyInt_FromSsize_t ( result ) ;
 }