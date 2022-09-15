int decode_and_write_pair ( PyObject * self , buffer_t buffer , PyObject * key , PyObject * value , unsigned char check_keys , unsigned char uuid_subtype , unsigned char top_level ) {
 PyObject * encoded ;
 if ( PyUnicode_Check ( key ) ) {
 result_t status ;
 encoded = PyUnicode_AsUTF8String ( key ) ;
 if ( ! encoded ) {
 return 0 ;
 }
 # if PY_MAJOR_VERSION >= 3 status = check_string ( ( const unsigned char * ) PyBytes_AsString ( encoded ) , PyBytes_Size ( encoded ) , 0 , 1 ) ;
 # else status = check_string ( ( const unsigned char * ) PyString_AsString ( encoded ) , PyString_Size ( encoded ) , 0 , 1 ) ;
 # endif if ( status == HAS_NULL ) {
 PyObject * InvalidDocument = _error ( "InvalidDocument" ) ;
 PyErr_SetString ( InvalidDocument , "Key names must not contain the NULL byte" ) ;
 Py_DECREF ( InvalidDocument ) ;
 return 0 ;
 }
 # if PY_MAJOR_VERSION < 3 }
 else if ( PyString_Check ( key ) ) {
 result_t status ;
 encoded = key ;
 Py_INCREF ( encoded ) ;
 status = check_string ( ( const unsigned char * ) PyString_AsString ( encoded ) , PyString_Size ( encoded ) , 1 , 1 ) ;
 if ( status == NOT_UTF_8 ) {
 PyObject * InvalidStringData = _error ( "InvalidStringData" ) ;
 PyErr_SetString ( InvalidStringData , "strings in documents must be valid UTF-8" ) ;
 Py_DECREF ( InvalidStringData ) ;
 return 0 ;
 }
 else if ( status == HAS_NULL ) {
 PyObject * InvalidDocument = _error ( "InvalidDocument" ) ;
 PyErr_SetString ( InvalidDocument , "Key names must not contain the NULL byte" ) ;
 Py_DECREF ( InvalidDocument ) ;
 return 0 ;
 }
 # endif }
 else {
 PyObject * InvalidDocument = _error ( "InvalidDocument" ) ;
 PyObject * repr = PyObject_Repr ( key ) ;
 # if PY_MAJOR_VERSION >= 3 PyObject * errmsg = PyUnicode_FromString ( "documents must have only string keys, key was " ) ;
 PyObject * error = PyUnicode_Concat ( errmsg , repr ) ;
 PyErr_SetObject ( InvalidDocument , error ) ;
 Py_DECREF ( error ) ;
 # else PyObject * errmsg = PyString_FromString ( "documents must have only string keys, key was " ) ;
 PyString_ConcatAndDel ( & errmsg , repr ) ;
 PyErr_SetString ( InvalidDocument , PyString_AsString ( errmsg ) ) ;
 # endif Py_DECREF ( InvalidDocument ) ;
 Py_DECREF ( errmsg ) ;
 return 0 ;
 }
 # if PY_MAJOR_VERSION >= 3 if ( ! write_pair ( self , buffer , PyBytes_AsString ( encoded ) , PyBytes_Size ( encoded ) , value , check_keys , uuid_subtype , ! top_level ) ) {
 # else if ( ! write_pair ( self , buffer , PyString_AsString ( encoded ) , PyString_Size ( encoded ) , value , check_keys , uuid_subtype , ! top_level ) ) {
 # endif Py_DECREF ( encoded ) ;
 return 0 ;
 }
 Py_DECREF ( encoded ) ;
 return 1 ;
 }