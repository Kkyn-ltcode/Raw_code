proto_item * proto_tree_add_oid_format ( proto_tree * tree , int hfindex , tvbuff_t * tvb , gint start , gint length , const guint8 * value_ptr , const char * format , ... ) {
 proto_item * pi ;
 va_list ap ;
 pi = proto_tree_add_oid ( tree , hfindex , tvb , start , length , value_ptr ) ;
 if ( pi != tree ) {
 TRY_TO_FAKE_THIS_REPR ( pi ) ;
 va_start ( ap , format ) ;
 proto_tree_set_representation ( pi , format , ap ) ;
 va_end ( ap ) ;
 }
 return pi ;
 }