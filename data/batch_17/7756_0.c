static int write_string ( buffer_t buffer , PyObject * py_string ) {
 Py_ssize_t string_length ;
 const char * string ;
 # if PY_MAJOR_VERSION >= 3 if ( PyUnicode_Check ( py_string ) ) {
 return write_unicode ( buffer , py_string ) ;
 }
 string = PyBytes_AsString ( py_string ) ;
 # else string = PyString_AsString ( py_string ) ;
 # endif if ( ! string ) {
 return 0 ;
 }
 # if PY_MAJOR_VERSION >= 3 string_length = PyBytes_Size ( py_string ) + 1 ;
 # else string_length = PyString_Size ( py_string ) + 1 ;
 # endif if ( ! buffer_write_bytes ( buffer , ( const char * ) & string_length , 4 ) ) {
 return 0 ;
 }
 if ( ! buffer_write_bytes ( buffer , string , string_length ) ) {
 return 0 ;
 }
 return 1 ;
 }