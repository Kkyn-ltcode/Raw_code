guint16 elem_lv_e ( tvbuff_t * tvb , proto_tree * tree , packet_info * pinfo , gint pdu_type , int idx , guint32 offset , guint len _U_ , const gchar * name_add ) {
 guint16 parm_len ;
 guint16 consumed ;
 guint32 curr_offset ;
 proto_tree * subtree ;
 proto_item * item ;
 value_string_ext elem_names_ext ;
 gint * elem_ett ;
 const gchar * elem_name ;
 guint16 ( * * elem_funcs ) ( tvbuff_t * tvb , proto_tree * tree , packet_info * pinfo , guint32 offset , guint len , gchar * add_string , int string_len ) ;
 curr_offset = offset ;
 consumed = 0 ;
 SET_ELEM_VARS ( pdu_type , elem_names_ext , elem_ett , elem_funcs , & ei_gsm_a_unknown_pdu_type ) ;
 parm_len = tvb_get_ntohs ( tvb , curr_offset ) ;
 elem_name = try_val_to_str_ext ( idx , & elem_names_ext ) ;
 if ( elem_name == NULL ) {
 proto_tree_add_expert_format ( tree , pinfo , & ei_gsm_a_unknown_element , tvb , curr_offset , parm_len + 2 , "Unknown - aborting dissection%s" , ( name_add == NULL ) || ( name_add [ 0 ] == '\0' ) ? "" : name_add ) ;
 return consumed ;
 }
 subtree = proto_tree_add_subtree_format ( tree , tvb , curr_offset , parm_len + 2 , elem_ett [ idx ] , & item , "%s%s" , elem_name , ( name_add == NULL ) || ( name_add [ 0 ] == '\0' ) ? "" : name_add ) ;
 proto_tree_add_uint ( subtree , hf_gsm_a_length , tvb , curr_offset , 2 , parm_len ) ;
 if ( parm_len > 0 ) {
 if ( elem_funcs [ idx ] == NULL ) {
 proto_tree_add_item ( subtree , hf_gsm_a_element_value , tvb , curr_offset + 2 , parm_len , ENC_NA ) ;
 consumed = parm_len ;
 }
 else {
 gchar * a_add_string ;
 a_add_string = ( gchar * ) wmem_alloc ( wmem_packet_scope ( ) , 1024 ) ;
 a_add_string [ 0 ] = '\0' ;
 consumed = ( * elem_funcs [ idx ] ) ( tvb , subtree , pinfo , curr_offset + 2 , parm_len , a_add_string , 1024 ) ;
 if ( a_add_string [ 0 ] != '\0' ) {
 proto_item_append_text ( item , "%s" , a_add_string ) ;
 }
 }
 }
 return ( consumed + 2 ) ;
 }