static void dissect_rtp_data ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , proto_tree * rtp_tree , int offset , unsigned int data_len , unsigned int data_reported_len , unsigned int payload_type ) {
 tvbuff_t * newtvb ;
 struct _rtp_conversation_info * p_conv_data = NULL ;
 gboolean must_desegment = FALSE ;
 rtp_private_conv_info * finfo = NULL ;
 rtp_multisegment_pdu * msp = NULL ;
 guint32 seqno ;
 p_conv_data = ( struct _rtp_conversation_info * ) p_get_proto_data ( wmem_file_scope ( ) , pinfo , proto_rtp , 0 ) ;
 if ( p_conv_data != NULL ) finfo = p_conv_data -> rtp_conv_info ;
 if ( finfo == NULL || ! desegment_rtp ) {
 newtvb = tvb_new_subset ( tvb , offset , data_len , data_reported_len ) ;
 process_rtp_payload ( newtvb , pinfo , tree , rtp_tree , payload_type ) ;
 return ;
 }
 seqno = p_conv_data -> extended_seqno ;
 pinfo -> can_desegment = 2 ;
 pinfo -> desegment_offset = 0 ;
 pinfo -> desegment_len = 0 ;
 # ifdef DEBUG_FRAGMENTS g_debug ( "%d: RTP Part of convo %d(%p);
 seqno %d" , pinfo -> fd -> num , p_conv_data -> frame_number , p_conv_data , seqno ) ;
 # endif msp = ( rtp_multisegment_pdu * ) wmem_tree_lookup32_le ( finfo -> multisegment_pdus , seqno - 1 ) ;
 if ( msp && msp -> startseq < seqno && msp -> endseq >= seqno ) {
 guint32 fid = msp -> startseq ;
 fragment_head * fd_head ;
 # ifdef DEBUG_FRAGMENTS g_debug ( "\tContinues fragment %d" , fid ) ;
 # endif fd_head = fragment_add_seq ( & rtp_reassembly_table , tvb , offset , pinfo , fid , NULL , seqno - msp -> startseq , data_len , FALSE , 0 ) ;
 newtvb = process_reassembled_data ( tvb , offset , pinfo , "Reassembled RTP" , fd_head , & rtp_fragment_items , NULL , tree ) ;
 # ifdef DEBUG_FRAGMENTS g_debug ( "\tFragment Coalesced;
 fd_head=%p, newtvb=%p (len %d)" , fd_head , newtvb , newtvb ? tvb_reported_length ( newtvb ) : 0 ) ;
 # endif if ( newtvb != NULL ) {
 process_rtp_payload ( newtvb , pinfo , tree , rtp_tree , payload_type ) ;
 if ( pinfo -> desegment_len && pinfo -> desegment_offset == 0 ) {
 # ifdef DEBUG_FRAGMENTS g_debug ( "\tNo complete pdus in payload" ) ;
 # endif fragment_set_partial_reassembly ( & rtp_reassembly_table , pinfo , fid , NULL ) ;
 msp -> endseq = MIN ( msp -> endseq , seqno ) + 1 ;
 }
 else {
 if ( pinfo -> desegment_len ) {
 must_desegment = TRUE ;
 }
 }
 }
 }
 else {
 # ifdef DEBUG_FRAGMENTS g_debug ( "\tRTP non-fragment payload" ) ;
 # endif newtvb = tvb_new_subset ( tvb , offset , data_len , data_reported_len ) ;
 process_rtp_payload ( newtvb , pinfo , tree , rtp_tree , payload_type ) ;
 if ( pinfo -> desegment_len ) {
 must_desegment = TRUE ;
 }
 }
 if ( must_desegment ) {
 guint32 deseg_offset = pinfo -> desegment_offset ;
 guint32 frag_len = tvb_reported_length_remaining ( newtvb , deseg_offset ) ;
 fragment_head * fd_head = NULL ;
 # ifdef DEBUG_FRAGMENTS g_debug ( "\tRTP Must Desegment: tvb_len=%d ds_len=%d %d frag_len=%d ds_off=%d" , tvb_reported_length ( newtvb ) , pinfo -> desegment_len , pinfo -> fd -> flags . visited , frag_len , deseg_offset ) ;
 # endif msp = wmem_new ( wmem_file_scope ( ) , rtp_multisegment_pdu ) ;
 msp -> startseq = seqno ;
 msp -> endseq = seqno + 1 ;
 wmem_tree_insert32 ( finfo -> multisegment_pdus , seqno , msp ) ;
 fd_head = fragment_add_seq ( & rtp_reassembly_table , newtvb , deseg_offset , pinfo , seqno , NULL , 0 , frag_len , TRUE , 0 ) ;
 if ( fd_head != NULL ) {
 if ( fd_head -> reassembled_in != 0 && ! ( fd_head -> flags & FD_PARTIAL_REASSEMBLY ) ) {
 proto_item * rtp_tree_item ;
 rtp_tree_item = proto_tree_add_uint ( tree , hf_rtp_reassembled_in , newtvb , deseg_offset , tvb_reported_length_remaining ( newtvb , deseg_offset ) , fd_head -> reassembled_in ) ;
 PROTO_ITEM_SET_GENERATED ( rtp_tree_item ) ;
 # ifdef DEBUG_FRAGMENTS g_debug ( "\tReassembled in %d" , fd_head -> reassembled_in ) ;
 # endif }
 else {
 # ifdef DEBUG_FRAGMENTS g_debug ( "\tUnfinished fragment" ) ;
 # endif proto_tree_add_text ( tree , tvb , deseg_offset , - 1 , "RTP fragment, unfinished" ) ;
 }
 }
 else {
 # ifdef DEBUG_FRAGMENTS g_debug ( "\tnew pdu" ) ;
 # endif }
 if ( pinfo -> desegment_offset == 0 ) {
 col_set_str ( pinfo -> cinfo , COL_PROTOCOL , "RTP" ) ;
 col_set_str ( pinfo -> cinfo , COL_INFO , "[RTP segment of a reassembled PDU]" ) ;
 }
 }
 pinfo -> can_desegment = 0 ;
 pinfo -> desegment_offset = 0 ;
 pinfo -> desegment_len = 0 ;
 }