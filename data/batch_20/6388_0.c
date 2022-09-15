static zend_object_value dbstmt_clone_obj ( zval * zobject TSRMLS_DC ) {
 zend_object_value retval ;
 pdo_stmt_t * stmt ;
 pdo_stmt_t * old_stmt ;
 zend_object_handle handle = Z_OBJ_HANDLE_P ( zobject ) ;
 stmt = ecalloc ( 1 , sizeof ( * stmt ) ) ;
 zend_object_std_init ( & stmt -> std , Z_OBJCE_P ( zobject ) TSRMLS_CC ) ;
 object_properties_init ( & stmt -> std , Z_OBJCE_P ( zobject ) ) ;
 stmt -> refcount = 1 ;
 old_stmt = ( pdo_stmt_t * ) zend_object_store_get_object ( zobject TSRMLS_CC ) ;
 retval . handle = zend_objects_store_put ( stmt , ( zend_objects_store_dtor_t ) zend_objects_destroy_object , ( zend_objects_free_object_storage_t ) pdo_dbstmt_free_storage , ( zend_objects_store_clone_t ) dbstmt_clone_obj TSRMLS_CC ) ;
 retval . handlers = Z_OBJ_HT_P ( zobject ) ;
 zend_objects_clone_members ( ( zend_object * ) stmt , retval , ( zend_object * ) old_stmt , handle TSRMLS_CC ) ;
 zend_objects_store_add_ref ( & old_stmt -> database_object_handle TSRMLS_CC ) ;
 stmt -> database_object_handle = old_stmt -> database_object_handle ;
 return retval ;
 }