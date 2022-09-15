PyMODINIT_FUNC init_cbson ( void ) # endif {
 PyObject * m ;
 PyObject * c_api_object ;
 static void * _cbson_API [ _cbson_API_POINTER_COUNT ] ;
 # if PY_MAJOR_VERSION >= 3 m = PyModule_Create ( & moduledef ) ;
 # else m = Py_InitModule ( "_cbson" , _CBSONMethods ) ;
 # endif if ( m == NULL ) {
 INITERROR ;
 }
 PyDateTime_IMPORT ;
 if ( PyDateTimeAPI == NULL ) {
 Py_DECREF ( m ) ;
 INITERROR ;
 }
 if ( _reload_python_objects ( m ) ) {
 Py_DECREF ( m ) ;
 INITERROR ;
 }
 _cbson_API [ _cbson_buffer_write_bytes_INDEX ] = ( void * ) buffer_write_bytes ;
 _cbson_API [ _cbson_write_dict_INDEX ] = ( void * ) write_dict ;
 _cbson_API [ _cbson_write_pair_INDEX ] = ( void * ) write_pair ;
 _cbson_API [ _cbson_decode_and_write_pair_INDEX ] = ( void * ) decode_and_write_pair ;
 # if PY_VERSION_HEX >= 0x03010000 c_api_object = PyCapsule_New ( ( void * ) _cbson_API , "_cbson._C_API" , NULL ) ;
 # else c_api_object = PyCObject_FromVoidPtr ( ( void * ) _cbson_API , NULL ) ;
 # endif if ( c_api_object != NULL ) {
 PyModule_AddObject ( m , "_C_API" , c_api_object ) ;
 }
 # if PY_MAJOR_VERSION >= 3 return m ;
 # endif }