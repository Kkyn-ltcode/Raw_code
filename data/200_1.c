SPL_METHOD ( SplFileObject , key ) {
 spl_filesystem_object * intern = ( spl_filesystem_object * ) zend_object_store_get_object ( getThis ( ) TSRMLS_CC ) ;
 if ( zend_parse_parameters_none ( ) == FAILURE ) {
 return ;
 }
 RETURN_LONG ( intern -> u . file . current_line_num ) ;
 }