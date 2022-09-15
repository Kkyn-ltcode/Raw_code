static PyObject * _error ( char * name ) {
 PyObject * error ;
 PyObject * errors = PyImport_ImportModule ( "bson.errors" ) ;
 if ( ! errors ) {
 return NULL ;
 }
 error = PyObject_GetAttrString ( errors , name ) ;
 Py_DECREF ( errors ) ;
 return error ;
 }