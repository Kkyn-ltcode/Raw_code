static PyObject * authGSSServerClean ( PyObject * self , PyObject * args ) {
 gss_server_state * state ;
 PyObject * pystate ;
 int result = 0 ;
 if ( ! PyArg_ParseTuple ( args , "O" , & pystate ) ) return NULL ;
 # if PY_MAJOR_VERSION >= 3 if ( ! PyCapsule_CheckExact ( pystate ) ) {
 # else if ( ! PyCObject_Check ( pystate ) ) {
 # endif PyErr_SetString ( PyExc_TypeError , "Expected a context object" ) ;
 return NULL ;
 }
 # if PY_MAJOR_VERSION >= 3 state = PyCapsule_GetPointer ( pystate , NULL ) ;
 # else state = ( gss_client_state * ) PyCObject_AsVoidPtr ( pystate ) ;
 # endif if ( state != NULL ) {
 result = authenticate_gss_server_clean ( state ) ;
 free ( state ) ;
 # if PY_MAJOR_VERSION >= 3 PyCapsule_SetPointer ( pystate , NULL ) ;
 # else PyCObject_SetVoidPtr ( pystate , NULL ) ;
 # endif }
 return Py_BuildValue ( "i" , result ) ;
 }