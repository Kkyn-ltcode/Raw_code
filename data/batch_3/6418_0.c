static int row_dim_exists ( zval * object , zval * member , int check_empty TSRMLS_DC ) {
 return row_prop_exists ( object , member , check_empty , NULL TSRMLS_CC ) ;
 }