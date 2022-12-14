static guint8 * get_value ( packet_info * pinfo , guint32 handle , bluetooth_data_t * bluetooth_data , guint * length ) {
 wmem_tree_key_t key [ 4 ] ;
 guint32 frame_number ;
 fragment_data_t * fragment_data ;
 wmem_tree_t * sub_wmemtree ;
 guint last_offset = G_MAXUINT ;
 guint size ;
 gboolean first = TRUE ;
 guint8 * data = NULL ;
 frame_number = pinfo -> num ;
 key [ 0 ] . length = 1 ;
 key [ 0 ] . key = & bluetooth_data -> interface_id ;
 key [ 1 ] . length = 1 ;
 key [ 1 ] . key = & bluetooth_data -> adapter_id ;
 key [ 2 ] . length = 1 ;
 key [ 2 ] . key = & handle ;
 key [ 3 ] . length = 0 ;
 key [ 3 ] . key = NULL ;
 sub_wmemtree = ( wmem_tree_t * ) wmem_tree_lookup32_array ( fragments , key ) ;
 while ( 1 ) {
 fragment_data = ( sub_wmemtree ) ? ( fragment_data_t * ) wmem_tree_lookup32_le ( sub_wmemtree , frame_number ) : NULL ;
 if ( ! fragment_data || ( fragment_data && fragment_data -> offset >= last_offset ) ) break ;
 if ( first ) {
 size = fragment_data -> offset + fragment_data -> length ;
 data = ( guint8 * ) wmem_alloc ( pinfo -> pool , size ) ;
 if ( length ) * length = size ;
 first = FALSE ;
 }
 else if ( fragment_data -> offset + fragment_data -> length != last_offset ) {
 break ;
 }
 memcpy ( data + fragment_data -> offset , fragment_data -> data , fragment_data -> length ) ;
 if ( fragment_data -> offset == 0 ) return data ;
 frame_number = fragment_data -> data_in_frame - 1 ;
 last_offset = fragment_data -> offset ;
 }
 if ( length ) * length = 0 ;
 return NULL ;
 }