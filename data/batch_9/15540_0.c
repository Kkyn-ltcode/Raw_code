int proto_item_get_len ( const proto_item * pi ) {
 field_info * fi = PITEM_FINFO ( pi ) ;
 return fi ? fi -> length : - 1 ;
 }