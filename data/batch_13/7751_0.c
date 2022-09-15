static int _write_element_to_buffer ( PyObject * self , buffer_t buffer , int type_byte , PyObject * value , unsigned char check_keys , unsigned char uuid_subtype , unsigned char first_attempt ) {
 struct module_state * state = GETSTATE ( self ) ;
 if ( PyBool_Check ( value ) ) {
 # if PY_MAJOR_VERSION >= 3 const long bool = PyLong_AsLong ( value ) ;
 # else const long bool = PyInt_AsLong ( value ) ;
 # endif const char c = bool ? 0x01 : 0x00 ;
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x08 ;
 return buffer_write_bytes ( buffer , & c , 1 ) ;
 }
 # if PY_MAJOR_VERSION >= 3 else if ( PyLong_Check ( value ) ) {
 const long long_value = PyLong_AsLong ( value ) ;
 # else else if ( PyInt_Check ( value ) ) {
 const long long_value = PyInt_AsLong ( value ) ;
 # endif const int int_value = ( int ) long_value ;
 if ( PyErr_Occurred ( ) || long_value != int_value ) {
 long long long_long_value ;
 PyErr_Clear ( ) ;
 long_long_value = PyLong_AsLongLong ( value ) ;
 if ( PyErr_Occurred ( ) ) {
 PyErr_SetString ( PyExc_OverflowError , "MongoDB can only handle up to 8-byte ints" ) ;
 return 0 ;
 }
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x12 ;
 return buffer_write_bytes ( buffer , ( const char * ) & long_long_value , 8 ) ;
 }
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x10 ;
 return buffer_write_bytes ( buffer , ( const char * ) & int_value , 4 ) ;
 # if PY_MAJOR_VERSION < 3 }
 else if ( PyLong_Check ( value ) ) {
 const long long long_long_value = PyLong_AsLongLong ( value ) ;
 if ( PyErr_Occurred ( ) ) {
 PyErr_SetString ( PyExc_OverflowError , "MongoDB can only handle up to 8-byte ints" ) ;
 return 0 ;
 }
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x12 ;
 return buffer_write_bytes ( buffer , ( const char * ) & long_long_value , 8 ) ;
 # endif }
 else if ( PyFloat_Check ( value ) ) {
 const double d = PyFloat_AsDouble ( value ) ;
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x01 ;
 return buffer_write_bytes ( buffer , ( const char * ) & d , 8 ) ;
 }
 else if ( value == Py_None ) {
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x0A ;
 return 1 ;
 }
 else if ( PyDict_Check ( value ) ) {
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x03 ;
 return write_dict ( self , buffer , value , check_keys , uuid_subtype , 0 ) ;
 }
 else if ( PyList_Check ( value ) || PyTuple_Check ( value ) ) {
 int start_position , length_location , items , length , i ;
 char zero = 0 ;
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x04 ;
 start_position = buffer_get_position ( buffer ) ;
 length_location = buffer_save_space ( buffer , 4 ) ;
 if ( length_location == - 1 ) {
 PyErr_NoMemory ( ) ;
 return 0 ;
 }
 items = PySequence_Size ( value ) ;
 for ( i = 0 ;
 i < items ;
 i ++ ) {
 int list_type_byte = buffer_save_space ( buffer , 1 ) ;
 char * name ;
 PyObject * item_value ;
 if ( list_type_byte == - 1 ) {
 PyErr_NoMemory ( ) ;
 return 0 ;
 }
 if ( INT2STRING ( & name , i ) < 0 || ! name ) {
 PyErr_NoMemory ( ) ;
 return 0 ;
 }
 if ( ! buffer_write_bytes ( buffer , name , strlen ( name ) + 1 ) ) {
 free ( name ) ;
 return 0 ;
 }
 free ( name ) ;
 item_value = PySequence_GetItem ( value , i ) ;
 if ( ! write_element_to_buffer ( self , buffer , list_type_byte , item_value , check_keys , uuid_subtype , 1 ) ) {
 Py_DECREF ( item_value ) ;
 return 0 ;
 }
 Py_DECREF ( item_value ) ;
 }
 if ( ! buffer_write_bytes ( buffer , & zero , 1 ) ) {
 return 0 ;
 }
 length = buffer_get_position ( buffer ) - start_position ;
 memcpy ( buffer_get_buffer ( buffer ) + length_location , & length , 4 ) ;
 return 1 ;
 }
 else if ( PyObject_IsInstance ( value , state -> Binary ) ) {
 PyObject * subtype_object ;
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x05 ;
 subtype_object = PyObject_GetAttrString ( value , "subtype" ) ;
 if ( ! subtype_object ) {
 return 0 ;
 }
 {
 # if PY_MAJOR_VERSION >= 3 const long long_subtype = PyLong_AsLong ( subtype_object ) ;
 const char subtype = ( const char ) long_subtype ;
 const int length = PyBytes_Size ( value ) ;
 # else const long long_subtype = PyInt_AsLong ( subtype_object ) ;
 const char subtype = ( const char ) long_subtype ;
 const int length = PyString_Size ( value ) ;
 # endif Py_DECREF ( subtype_object ) ;
 if ( subtype == 2 ) {
 const int other_length = length + 4 ;
 if ( ! buffer_write_bytes ( buffer , ( const char * ) & other_length , 4 ) ) {
 return 0 ;
 }
 if ( ! buffer_write_bytes ( buffer , & subtype , 1 ) ) {
 return 0 ;
 }
 }
 if ( ! buffer_write_bytes ( buffer , ( const char * ) & length , 4 ) ) {
 return 0 ;
 }
 if ( subtype != 2 ) {
 if ( ! buffer_write_bytes ( buffer , & subtype , 1 ) ) {
 return 0 ;
 }
 }
 {
 # if PY_MAJOR_VERSION >= 3 const char * string = PyBytes_AsString ( value ) ;
 # else const char * string = PyString_AsString ( value ) ;
 # endif if ( ! string ) {
 return 0 ;
 }
 if ( ! buffer_write_bytes ( buffer , string , length ) ) {
 return 0 ;
 }
 }
 }
 return 1 ;
 }
 else if ( state -> UUID && PyObject_IsInstance ( value , state -> UUID ) ) {
 PyObject * bytes ;
 const char * binarr ;
 int length = 16 ;
 char subtype ;
 if ( uuid_subtype == JAVA_LEGACY || uuid_subtype == CSHARP_LEGACY ) {
 subtype = 3 ;
 }
 else {
 subtype = ( char ) uuid_subtype ;
 }
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x05 ;
 if ( ! buffer_write_bytes ( buffer , ( const char * ) & length , 4 ) ) {
 return 0 ;
 }
 if ( ! buffer_write_bytes ( buffer , & subtype , 1 ) ) {
 return 0 ;
 }
 if ( uuid_subtype == CSHARP_LEGACY ) {
 bytes = PyObject_GetAttrString ( value , "bytes_le" ) ;
 }
 else {
 bytes = PyObject_GetAttrString ( value , "bytes" ) ;
 }
 if ( ! bytes ) {
 return 0 ;
 }
 # if PY_MAJOR_VERSION >= 3 if ( PyByteArray_Check ( bytes ) ) {
 binarr = PyByteArray_AsString ( bytes ) ;
 }
 else {
 binarr = PyBytes_AsString ( bytes ) ;
 }
 # else binarr = PyString_AsString ( bytes ) ;
 # endif if ( uuid_subtype == JAVA_LEGACY ) {
 char as_legacy_java [ 16 ] ;
 _fix_java ( binarr , as_legacy_java ) ;
 if ( ! buffer_write_bytes ( buffer , as_legacy_java , length ) ) {
 Py_DECREF ( bytes ) ;
 return 0 ;
 }
 }
 else {
 if ( ! buffer_write_bytes ( buffer , binarr , length ) ) {
 Py_DECREF ( bytes ) ;
 return 0 ;
 }
 }
 Py_DECREF ( bytes ) ;
 return 1 ;
 }
 else if ( PyObject_IsInstance ( value , state -> Code ) ) {
 int start_position , length_location , length ;
 PyObject * scope = PyObject_GetAttrString ( value , "scope" ) ;
 if ( ! scope ) {
 return 0 ;
 }
 if ( ! PyDict_Size ( scope ) ) {
 Py_DECREF ( scope ) ;
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x0D ;
 return write_string ( buffer , value ) ;
 }
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x0F ;
 start_position = buffer_get_position ( buffer ) ;
 length_location = buffer_save_space ( buffer , 4 ) ;
 if ( length_location == - 1 ) {
 PyErr_NoMemory ( ) ;
 Py_DECREF ( scope ) ;
 return 0 ;
 }
 if ( ! write_string ( buffer , value ) ) {
 Py_DECREF ( scope ) ;
 return 0 ;
 }
 if ( ! write_dict ( self , buffer , scope , 0 , uuid_subtype , 0 ) ) {
 Py_DECREF ( scope ) ;
 return 0 ;
 }
 Py_DECREF ( scope ) ;
 length = buffer_get_position ( buffer ) - start_position ;
 memcpy ( buffer_get_buffer ( buffer ) + length_location , & length , 4 ) ;
 return 1 ;
 # if PY_MAJOR_VERSION >= 3 }
 else if ( PyBytes_Check ( value ) ) {
 Py_ssize_t length = PyBytes_Size ( value ) ;
 const char subtype = 0 ;
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x05 ;
 if ( ! buffer_write_bytes ( buffer , ( const char * ) & length , 4 ) ) {
 return 0 ;
 }
 if ( ! buffer_write_bytes ( buffer , & subtype , 1 ) ) {
 return 0 ;
 }
 if ( ! buffer_write_bytes ( buffer , PyBytes_AsString ( value ) , length ) ) {
 return 0 ;
 }
 return 1 ;
 # else }
 else if ( PyString_Check ( value ) ) {
 int result ;
 result_t status ;
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x02 ;
 status = check_string ( ( const unsigned char * ) PyString_AsString ( value ) , PyString_Size ( value ) , 1 , 0 ) ;
 if ( status == NOT_UTF_8 ) {
 PyObject * InvalidStringData = _error ( "InvalidStringData" ) ;
 PyErr_SetString ( InvalidStringData , "strings in documents must be valid UTF-8" ) ;
 Py_DECREF ( InvalidStringData ) ;
 return 0 ;
 }
 result = write_string ( buffer , value ) ;
 return result ;
 # endif }
 else if ( PyUnicode_Check ( value ) ) {
 PyObject * encoded ;
 int result ;
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x02 ;
 encoded = PyUnicode_AsUTF8String ( value ) ;
 if ( ! encoded ) {
 return 0 ;
 }
 result = write_string ( buffer , encoded ) ;
 Py_DECREF ( encoded ) ;
 return result ;
 }
 else if ( PyDateTime_Check ( value ) ) {
 long long millis ;
 PyObject * utcoffset = PyObject_CallMethod ( value , "utcoffset" , NULL ) ;
 if ( utcoffset != Py_None ) {
 PyObject * result = PyNumber_Subtract ( value , utcoffset ) ;
 Py_DECREF ( utcoffset ) ;
 if ( ! result ) {
 return 0 ;
 }
 millis = millis_from_datetime ( result ) ;
 Py_DECREF ( result ) ;
 }
 else {
 millis = millis_from_datetime ( value ) ;
 }
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x09 ;
 return buffer_write_bytes ( buffer , ( const char * ) & millis , 8 ) ;
 }
 else if ( PyObject_IsInstance ( value , state -> ObjectId ) ) {
 PyObject * pystring = PyObject_GetAttrString ( value , "_ObjectId__id" ) ;
 if ( ! pystring ) {
 return 0 ;
 }
 {
 # if PY_MAJOR_VERSION >= 3 const char * as_string = PyBytes_AsString ( pystring ) ;
 # else const char * as_string = PyString_AsString ( pystring ) ;
 # endif if ( ! as_string ) {
 Py_DECREF ( pystring ) ;
 return 0 ;
 }
 if ( ! buffer_write_bytes ( buffer , as_string , 12 ) ) {
 Py_DECREF ( pystring ) ;
 return 0 ;
 }
 Py_DECREF ( pystring ) ;
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x07 ;
 }
 return 1 ;
 }
 else if ( PyObject_IsInstance ( value , state -> DBRef ) ) {
 PyObject * as_doc = PyObject_CallMethod ( value , "as_doc" , NULL ) ;
 if ( ! as_doc ) {
 return 0 ;
 }
 if ( ! write_dict ( self , buffer , as_doc , 0 , uuid_subtype , 0 ) ) {
 Py_DECREF ( as_doc ) ;
 return 0 ;
 }
 Py_DECREF ( as_doc ) ;
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x03 ;
 return 1 ;
 }
 else if ( PyObject_IsInstance ( value , state -> Timestamp ) ) {
 PyObject * obj ;
 long i ;
 obj = PyObject_GetAttrString ( value , "inc" ) ;
 if ( ! obj ) {
 return 0 ;
 }
 # if PY_MAJOR_VERSION >= 3 i = PyLong_AsLong ( obj ) ;
 # else i = PyInt_AsLong ( obj ) ;
 # endif Py_DECREF ( obj ) ;
 if ( ! buffer_write_bytes ( buffer , ( const char * ) & i , 4 ) ) {
 return 0 ;
 }
 obj = PyObject_GetAttrString ( value , "time" ) ;
 if ( ! obj ) {
 return 0 ;
 }
 # if PY_MAJOR_VERSION >= 3 i = PyLong_AsLong ( obj ) ;
 # else i = PyInt_AsLong ( obj ) ;
 # endif Py_DECREF ( obj ) ;
 if ( ! buffer_write_bytes ( buffer , ( const char * ) & i , 4 ) ) {
 return 0 ;
 }
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x11 ;
 return 1 ;
 }
 else if ( PyObject_TypeCheck ( value , state -> REType ) ) {
 PyObject * py_flags = PyObject_GetAttrString ( value , "flags" ) ;
 PyObject * py_pattern ;
 PyObject * encoded_pattern ;
 long int_flags ;
 char flags [ FLAGS_SIZE ] ;
 char check_utf8 = 0 ;
 int pattern_length , flags_length ;
 result_t status ;
 if ( ! py_flags ) {
 return 0 ;
 }
 # if PY_MAJOR_VERSION >= 3 int_flags = PyLong_AsLong ( py_flags ) ;
 # else int_flags = PyInt_AsLong ( py_flags ) ;
 # endif Py_DECREF ( py_flags ) ;
 py_pattern = PyObject_GetAttrString ( value , "pattern" ) ;
 if ( ! py_pattern ) {
 return 0 ;
 }
 if ( PyUnicode_Check ( py_pattern ) ) {
 encoded_pattern = PyUnicode_AsUTF8String ( py_pattern ) ;
 Py_DECREF ( py_pattern ) ;
 if ( ! encoded_pattern ) {
 return 0 ;
 }
 }
 else {
 encoded_pattern = py_pattern ;
 check_utf8 = 1 ;
 }
 # if PY_MAJOR_VERSION >= 3 status = check_string ( ( const unsigned char * ) PyBytes_AsString ( encoded_pattern ) , PyBytes_Size ( encoded_pattern ) , check_utf8 , 1 ) ;
 # else status = check_string ( ( const unsigned char * ) PyString_AsString ( encoded_pattern ) , PyString_Size ( encoded_pattern ) , check_utf8 , 1 ) ;
 # endif if ( status == NOT_UTF_8 ) {
 PyObject * InvalidStringData = _error ( "InvalidStringData" ) ;
 PyErr_SetString ( InvalidStringData , "regex patterns must be valid UTF-8" ) ;
 Py_DECREF ( InvalidStringData ) ;
 Py_DECREF ( encoded_pattern ) ;
 return 0 ;
 }
 else if ( status == HAS_NULL ) {
 PyObject * InvalidDocument = _error ( "InvalidDocument" ) ;
 PyErr_SetString ( InvalidDocument , "regex patterns must not contain the NULL byte" ) ;
 Py_DECREF ( InvalidDocument ) ;
 Py_DECREF ( encoded_pattern ) ;
 return 0 ;
 }
 {
 # if PY_MAJOR_VERSION >= 3 const char * pattern = PyBytes_AsString ( encoded_pattern ) ;
 # else const char * pattern = PyString_AsString ( encoded_pattern ) ;
 # endif pattern_length = strlen ( pattern ) + 1 ;
 if ( ! buffer_write_bytes ( buffer , pattern , pattern_length ) ) {
 Py_DECREF ( encoded_pattern ) ;
 return 0 ;
 }
 }
 Py_DECREF ( encoded_pattern ) ;
 flags [ 0 ] = 0 ;
 if ( int_flags & 2 ) {
 STRCAT ( flags , FLAGS_SIZE , "i" ) ;
 }
 if ( int_flags & 4 ) {
 STRCAT ( flags , FLAGS_SIZE , "l" ) ;
 }
 if ( int_flags & 8 ) {
 STRCAT ( flags , FLAGS_SIZE , "m" ) ;
 }
 if ( int_flags & 16 ) {
 STRCAT ( flags , FLAGS_SIZE , "s" ) ;
 }
 if ( int_flags & 32 ) {
 STRCAT ( flags , FLAGS_SIZE , "u" ) ;
 }
 if ( int_flags & 64 ) {
 STRCAT ( flags , FLAGS_SIZE , "x" ) ;
 }
 flags_length = strlen ( flags ) + 1 ;
 if ( ! buffer_write_bytes ( buffer , flags , flags_length ) ) {
 return 0 ;
 }
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x0B ;
 return 1 ;
 }
 else if ( PyObject_IsInstance ( value , state -> MinKey ) ) {
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0xFF ;
 return 1 ;
 }
 else if ( PyObject_IsInstance ( value , state -> MaxKey ) ) {
 * ( buffer_get_buffer ( buffer ) + type_byte ) = 0x7F ;
 return 1 ;
 }
 else if ( first_attempt ) {
 if ( WARN ( PyExc_RuntimeWarning , "couldn't encode - reloading python " "modules and trying again. if you see this without getting " "an InvalidDocument exception please see http://api.mongodb" ".org/python/current/faq.html#does-pymongo-work-with-mod-" "wsgi" ) == - 1 ) {
 return 0 ;
 }
 if ( _reload_python_objects ( self ) ) {
 return 0 ;
 }
 return write_element_to_buffer ( self , buffer , type_byte , value , check_keys , uuid_subtype , 0 ) ;
 }
 {
 PyObject * repr = PyObject_Repr ( value ) ;
 PyObject * InvalidDocument = _error ( "InvalidDocument" ) ;
 # if PY_MAJOR_VERSION >= 3 PyObject * errmsg = PyUnicode_FromString ( "Cannot encode object: " ) ;
 PyObject * error = PyUnicode_Concat ( errmsg , repr ) ;
 PyErr_SetObject ( InvalidDocument , error ) ;
 Py_DECREF ( error ) ;
 Py_DECREF ( repr ) ;
 # else PyObject * errmsg = PyString_FromString ( "Cannot encode object: " ) ;
 PyString_ConcatAndDel ( & errmsg , repr ) ;
 PyErr_SetString ( InvalidDocument , PyString_AsString ( errmsg ) ) ;
 # endif Py_DECREF ( errmsg ) ;
 Py_DECREF ( InvalidDocument ) ;
 return 0 ;
 }
 }