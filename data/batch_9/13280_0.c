static PyObject * authGSSServerStep ( PyObject * self , PyObject * args ) {
 gss_server_state * state ;
 PyObject * pystate ;
 char * challenge = NULL ;
 int result = 0 ;
 if ( ! PyArg_ParseTuple ( args , "Os" , & pystate , & challenge ) ) return NULL ;
 # if PY_MAJOR_VERSION >= 3 if ( ! PyCapsule_CheckExact ( pystate ) ) {
 # else if ( ! PyCObject_Check ( pystate ) ) {
 # endif PyErr_SetString ( PyExc_TypeError , "Expected a context object" ) ;
 return NULL ;
 }
 # if PY_MAJOR_VERSION >= 3 state = PyCapsule_GetPointer ( pystate , NULL ) ;
 # else state = ( gss_client_state * ) PyCObject_AsVoidPtr ( pystate ) ;
 # endif if ( state == NULL ) return NULL ;
 result = authenticate_gss_server_step ( state , challenge ) ;
 if ( result == AUTH_GSS_ERROR ) return NULL ;
 return Py_BuildValue ( "i" , result ) ;
 }