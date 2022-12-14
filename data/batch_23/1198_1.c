static void process_packet_data ( struct wtap_pkthdr * phdr , Buffer * target , guint8 * buffer , gint len , k12_t * k12 ) {
 guint32 type ;
 guint buffer_offset ;
 guint64 ts ;
 guint32 length ;
 guint32 extra_len ;
 guint32 src_id ;
 k12_src_desc_t * src_desc ;
 phdr -> rec_type = REC_TYPE_PACKET ;
 phdr -> presence_flags = WTAP_HAS_TS ;
 ts = pntoh64 ( buffer + K12_PACKET_TIMESTAMP ) ;
 phdr -> ts . secs = ( guint32 ) ( ( ts / 2000000 ) + 631152000 ) ;
 phdr -> ts . nsecs = ( guint32 ) ( ( ts % 2000000 ) * 500 ) ;
 length = pntoh32 ( buffer + K12_RECORD_FRAME_LEN ) & 0x00001FFF ;
 phdr -> len = phdr -> caplen = length ;
 type = pntoh32 ( buffer + K12_RECORD_TYPE ) ;
 buffer_offset = ( type == K12_REC_D0020 ) ? K12_PACKET_FRAME_D0020 : K12_PACKET_FRAME ;
 ws_buffer_assure_space ( target , length ) ;
 memcpy ( ws_buffer_start_ptr ( target ) , buffer + buffer_offset , length ) ;
 extra_len = len - buffer_offset - length ;
 ws_buffer_assure_space ( & ( k12 -> extra_info ) , extra_len ) ;
 memcpy ( ws_buffer_start_ptr ( & ( k12 -> extra_info ) ) , buffer + buffer_offset + length , extra_len ) ;
 phdr -> pseudo_header . k12 . extra_info = ( guint8 * ) ws_buffer_start_ptr ( & ( k12 -> extra_info ) ) ;
 phdr -> pseudo_header . k12 . extra_length = extra_len ;
 src_id = pntoh32 ( buffer + K12_RECORD_SRC_ID ) ;
 K12_DBG ( 5 , ( "process_packet_data: src_id=%.8x" , src_id ) ) ;
 phdr -> pseudo_header . k12 . input = src_id ;
 if ( ! ( src_desc = ( k12_src_desc_t * ) g_hash_table_lookup ( k12 -> src_by_id , GUINT_TO_POINTER ( src_id ) ) ) ) {
 src_desc = ( k12_src_desc_t * ) g_hash_table_lookup ( k12 -> src_by_id , GUINT_TO_POINTER ( src_id & K12_RECORD_SRC_ID_MASK ) ) ;
 }
 if ( src_desc ) {
 K12_DBG ( 5 , ( "process_packet_data: input_name='%s' stack_file='%s' type=%x" , src_desc -> input_name , src_desc -> stack_file , src_desc -> input_type ) ) ;
 phdr -> pseudo_header . k12 . input_name = src_desc -> input_name ;
 phdr -> pseudo_header . k12 . stack_file = src_desc -> stack_file ;
 phdr -> pseudo_header . k12 . input_type = src_desc -> input_type ;
 switch ( src_desc -> input_type ) {
 case K12_PORT_ATMPVC : if ( ( long ) ( buffer_offset + length + K12_PACKET_OFFSET_CID ) < len ) {
 phdr -> pseudo_header . k12 . input_info . atm . vp = pntoh16 ( buffer + buffer_offset + length + K12_PACKET_OFFSET_VP ) ;
 phdr -> pseudo_header . k12 . input_info . atm . vc = pntoh16 ( buffer + buffer_offset + length + K12_PACKET_OFFSET_VC ) ;
 phdr -> pseudo_header . k12 . input_info . atm . cid = * ( ( unsigned char * ) ( buffer + buffer_offset + length + K12_PACKET_OFFSET_CID ) ) ;
 break ;
 }
 default : memcpy ( & ( phdr -> pseudo_header . k12 . input_info ) , & ( src_desc -> input_info ) , sizeof ( src_desc -> input_info ) ) ;
 break ;
 }
 }
 else {
 K12_DBG ( 5 , ( "process_packet_data: NO SRC_RECORD FOUND" ) ) ;
 memset ( & ( phdr -> pseudo_header . k12 ) , 0 , sizeof ( phdr -> pseudo_header . k12 ) ) ;
 phdr -> pseudo_header . k12 . input_name = "unknown port" ;
 phdr -> pseudo_header . k12 . stack_file = "unknown stack file" ;
 }
 phdr -> pseudo_header . k12 . input = src_id ;
 phdr -> pseudo_header . k12 . stuff = k12 ;
 }