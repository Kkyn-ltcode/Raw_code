static void pdo_stmt_iter_move_forwards ( zend_object_iterator * iter TSRMLS_DC ) {
 struct php_pdo_iterator * I = ( struct php_pdo_iterator * ) iter -> data ;
 if ( I -> fetch_ahead ) {
 zval_ptr_dtor ( & I -> fetch_ahead ) ;
 I -> fetch_ahead = NULL ;
 }
 MAKE_STD_ZVAL ( I -> fetch_ahead ) ;
 if ( ! do_fetch ( I -> stmt , TRUE , I -> fetch_ahead , PDO_FETCH_USE_DEFAULT , PDO_FETCH_ORI_NEXT , 0 , 0 TSRMLS_CC ) ) {
 pdo_stmt_t * stmt = I -> stmt ;
 PDO_HANDLE_STMT_ERR ( ) ;
 I -> key = ( ulong ) - 1 ;
 FREE_ZVAL ( I -> fetch_ahead ) ;
 I -> fetch_ahead = NULL ;
 return ;
 }
 I -> key ++ ;
 }