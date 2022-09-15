static zval * row_prop_read ( zval * object , zval * member , int type , const zend_literal * key TSRMLS_DC ) {
 zval * return_value ;
 pdo_stmt_t * stmt = ( pdo_stmt_t * ) zend_object_store_get_object ( object TSRMLS_CC ) ;
 int colno = - 1 ;
 MAKE_STD_ZVAL ( return_value ) ;
 RETVAL_NULL ( ) ;
 if ( stmt ) {
 if ( Z_TYPE_P ( member ) == IS_LONG ) {
 if ( Z_LVAL_P ( member ) >= 0 && Z_LVAL_P ( member ) < stmt -> column_count ) {
 fetch_value ( stmt , return_value , Z_LVAL_P ( member ) , NULL TSRMLS_CC ) ;
 }
 }
 else {
 convert_to_string ( member ) ;
 for ( colno = 0 ;
 colno < stmt -> column_count ;
 colno ++ ) {
 if ( strcmp ( stmt -> columns [ colno ] . name , Z_STRVAL_P ( member ) ) == 0 ) {
 fetch_value ( stmt , return_value , colno , NULL TSRMLS_CC ) ;
 Z_SET_REFCOUNT_P ( return_value , 0 ) ;
 Z_UNSET_ISREF_P ( return_value ) ;
 return return_value ;
 }
 }
 if ( strcmp ( Z_STRVAL_P ( member ) , "queryString" ) == 0 ) {
 zval_ptr_dtor ( & return_value ) ;
 return std_object_handlers . read_property ( object , member , type , key TSRMLS_CC ) ;
 }
 }
 }
 Z_SET_REFCOUNT_P ( return_value , 0 ) ;
 Z_UNSET_ISREF_P ( return_value ) ;
 return return_value ;
 }