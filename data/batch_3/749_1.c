static int parse_CTableColumn ( tvbuff_t * tvb , int offset , proto_tree * parent_tree , proto_tree * pad_tree , struct CTableColumn * col , const char * fmt , ... ) {
 static const value_string DBAGGTTYPE [ ] = {
 {
 0x0 , "DBAGGTTYPE_BYNONE" }
 , {
 0x1 , "DBAGGTTYPE_SUM" }
 , {
 0x2 , "DBAGGTTYPE_MAX" }
 , {
 0x3 , "DBAGGTTYPE_MIN" }
 , {
 0x4 , "DBAGGTTYPE_AVG" }
 , {
 0x5 , "DBAGGTTYPE_COUNT" }
 , {
 0x6 , "DBAGGTTYPE_CHILDCOUNT" }
 , {
 0x7 , "DBAGGTTYPE_BYFREQ" }
 , {
 0x8 , "DBAGGTTYPE_FIRST" }
 , {
 0x9 , "DBAGGTTYPE_DATERANGE" }
 , {
 0xA , "DBAGGTTYPE_REPRESENTATIVEOF" }
 , {
 0xB , "DBAGGTTYPE_EDITDISTANCE" }
 , {
 0 , NULL }
 }
 ;
 proto_item * item ;
 proto_tree * tree ;
 va_list ap ;
 struct vtype_data * type ;
 enum vType vtype_val = VT_EMPTY ;
 enum vType vtype_valhi = VT_EMPTY ;
 struct CFullPropSpec v ;
 const char * txt ;
 guint8 used ;
 const char * modifier = "" ;
 va_start ( ap , fmt ) ;
 txt = wmem_strdup_vprintf ( wmem_packet_scope ( ) , fmt , ap ) ;
 va_end ( ap ) ;
 tree = proto_tree_add_subtree ( parent_tree , tvb , offset , 0 , ett_CTableColumn , & item , txt ) ;
 offset = parse_CFullPropSpec ( tvb , offset , tree , pad_tree , & v , "PropSpec" ) ;
 get_name_from_fullpropspec ( & v , col -> name , PROP_LENGTH ) ;
 col -> vtype = tvb_get_letohl ( tvb , offset ) ;
 vtype_val = ( enum vType ) col -> vtype ;
 vtype_valhi = ( enum vType ) ( col -> vtype & 0xFF00 ) ;
 if ( vtype_valhi ) {
 if ( vtype_valhi == VT_VECTOR ) {
 modifier = "|VT_VECTOR" ;
 }
 else if ( vtype_valhi == VT_ARRAY ) {
 modifier = "|VT_ARRAY" ;
 }
 else {
 modifier = "|(Unknown, possibly error)" ;
 }
 }
 type = vType_get_type ( vtype_val ) ;
 DISSECTOR_ASSERT ( type != NULL ) ;
 proto_tree_add_string_format_value ( tree , hf_mswsp_ctablecolumn_vtype , tvb , offset , 4 , type -> str , "%s%s" , type -> str , modifier ) ;
 offset += 4 ;
 used = tvb_get_guint8 ( tvb , offset ) ;
 col -> aggregateused = used ;
 proto_tree_add_uint ( tree , hf_mswsp_ctablecolumn_aggused , tvb , offset , 1 , used ) ;
 offset += 1 ;
 if ( used ) {
 col -> aggregatetype = tvb_get_guint8 ( tvb , offset ) ;
 proto_tree_add_string ( tree , hf_mswsp_ctablecolumn_aggtype , tvb , offset , 1 , val_to_str ( col -> aggregatetype , DBAGGTTYPE , "(Unknown: 0x%x)" ) ) ;
 offset += 1 ;
 }
 col -> valueused = tvb_get_guint8 ( tvb , offset ) ;
 used = col -> valueused ;
 proto_tree_add_uint ( tree , hf_mswsp_ctablecolumn_valused , tvb , offset , 1 , used ) ;
 offset += 1 ;
 if ( used ) {
 offset = parse_padding ( tvb , offset , 2 , pad_tree , "padding_Value" ) ;
 col -> valueoffset = tvb_get_letohs ( tvb , offset ) ;
 proto_tree_add_uint ( tree , hf_mswsp_ctablecolumn_valoffset , tvb , offset , 2 , col -> valueoffset ) ;
 offset += 2 ;
 col -> valuesize = tvb_get_letohs ( tvb , offset ) ;
 proto_tree_add_uint ( tree , hf_mswsp_ctablecolumn_valsize , tvb , offset , 2 , col -> valuesize ) ;
 offset += 2 ;
 }
 used = tvb_get_guint8 ( tvb , offset ) ;
 col -> statusused = used ;
 proto_tree_add_uint ( tree , hf_mswsp_ctablecolumn_statused , tvb , offset , 1 , used ) ;
 offset += 1 ;
 if ( used ) {
 offset = parse_padding ( tvb , offset , 2 , pad_tree , "padding_Status" ) ;
 col -> statusoffset = tvb_get_letohs ( tvb , offset ) ;
 proto_tree_add_uint ( tree , hf_mswsp_ctablecolumn_statoffset , tvb , offset , 2 , col -> statusoffset ) ;
 offset += 2 ;
 }
 used = tvb_get_guint8 ( tvb , offset ) ;
 proto_tree_add_uint ( tree , hf_mswsp_ctablecolumn_lenused , tvb , offset , 1 , used ) ;
 col -> lengthused = used ;
 offset += 1 ;
 if ( used ) {
 offset = parse_padding ( tvb , offset , 2 , pad_tree , "padding_Length" ) ;
 col -> lengthoffset = tvb_get_letohs ( tvb , offset ) ;
 proto_tree_add_uint ( tree , hf_mswsp_ctablecolumn_lenoffset , tvb , offset , 2 , col -> lengthoffset ) ;
 offset += 2 ;
 }
 proto_item_set_end ( item , tvb , offset ) ;
 return offset ;
 }