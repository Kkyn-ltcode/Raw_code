static int check_key_name ( const char * name , const Py_ssize_t name_length ) {
 int i ;
 if ( name_length > 0 && name [ 0 ] == '$' ) {
 PyObject * InvalidDocument = _error ( "InvalidDocument" ) ;
 # if PY_MAJOR_VERSION >= 3 PyObject * errmsg = PyUnicode_FromFormat ( "key '%s' must not start with '$'" , name ) ;
 PyErr_SetObject ( InvalidDocument , errmsg ) ;
 # else PyObject * errmsg = PyString_FromFormat ( "key '%s' must not start with '$'" , name ) ;
 PyErr_SetString ( InvalidDocument , PyString_AsString ( errmsg ) ) ;
 # endif Py_DECREF ( errmsg ) ;
 Py_DECREF ( InvalidDocument ) ;
 return 0 ;
 }
 for ( i = 0 ;
 i < name_length ;
 i ++ ) {
 if ( name [ i ] == '.' ) {
 PyObject * InvalidDocument = _error ( "InvalidDocument" ) ;
 # if PY_MAJOR_VERSION >= 3 PyObject * errmsg = PyUnicode_FromFormat ( "key '%s' must not contain '.'" , name ) ;
 PyErr_SetObject ( InvalidDocument , errmsg ) ;
 # else PyObject * errmsg = PyString_FromFormat ( "key '%s' must not contain '.'" , name ) ;
 PyErr_SetString ( InvalidDocument , PyString_AsString ( errmsg ) ) ;
 # endif Py_DECREF ( errmsg ) ;
 Py_DECREF ( InvalidDocument ) ;
 return 0 ;
 }
 }
 return 1 ;
 }