PyObject * PyString_AsEncodedString ( PyObject * str , const char * encoding , const char * errors ) {
 PyObject * v ;
 v = PyString_AsEncodedObject ( str , encoding , errors ) ;
 if ( v == NULL ) goto onError ;
 # ifdef Py_USING_UNICODE if ( PyUnicode_Check ( v ) ) {
 PyObject * temp = v ;
 v = PyUnicode_AsEncodedString ( v , NULL , NULL ) ;
 Py_DECREF ( temp ) ;
 if ( v == NULL ) goto onError ;
 }
 # endif if ( ! PyString_Check ( v ) ) {
 PyErr_Format ( PyExc_TypeError , "encoder did not return a string object (type=%.400s)" , Py_TYPE ( v ) -> tp_name ) ;
 Py_DECREF ( v ) ;
 goto onError ;
 }
 return v ;
 onError : return NULL ;
 }