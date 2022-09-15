static int _reload_object ( PyObject * * object , char * module_name , char * object_name ) {
 PyObject * module ;
 module = PyImport_ImportModule ( module_name ) ;
 if ( ! module ) {
 return 1 ;
 }
 * object = PyObject_GetAttrString ( module , object_name ) ;
 Py_DECREF ( module ) ;
 return ( * object ) ? 0 : 2 ;
 }