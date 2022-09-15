static int parse_CRestriction ( tvbuff_t * tvb , packet_info * pinfo , int offset , proto_tree * parent_tree , proto_tree * pad_tree , struct CRestriction * v , const char * fmt , ... ) {
 proto_tree * tree ;
 proto_item * item ;
 const char * str , * txt ;
 va_list ap ;
 va_start ( ap , fmt ) ;
 txt = wmem_strdup_vprintf ( wmem_packet_scope ( ) , fmt , ap ) ;
 va_end ( ap ) ;
 tree = proto_tree_add_subtree ( parent_tree , tvb , offset , 0 , ett_CRestriction , & item , txt ) ;
 offset = parse_rType ( tvb , offset , tree , & v -> ulType , & str ) ;
 proto_item_append_text ( item , " Type: %s" , str ) ;
 v -> Weight = tvb_get_letohl ( tvb , offset ) ;
 proto_tree_add_uint ( tree , hf_mswsp_crestrict_weight , tvb , offset , 4 , v -> Weight ) ;
 offset += 4 ;
 switch ( v -> ulType ) {
 case RTNone : break ;
 case RTAnd : case RTOr : case RTProximity : case RTPhrase : {
 v -> u . RTAnd = EP_ALLOC ( struct CNodeRestriction ) ;
 offset = parse_CNodeRestriction ( tvb , pinfo , offset , tree , pad_tree , v -> u . RTAnd , "CNodeRestriction" ) ;
 break ;
 }
 case RTNot : {
 v -> u . RTNot = EP_ALLOC ( struct CRestriction ) ;
 offset = parse_CRestriction ( tvb , pinfo , offset , tree , pad_tree , v -> u . RTNot , "CRestriction" ) ;
 break ;
 }
 case RTProperty : {
 v -> u . RTProperty = EP_ALLOC ( struct CPropertyRestriction ) ;
 offset = parse_CPropertyRestriction ( tvb , pinfo , offset , tree , pad_tree , v -> u . RTProperty , "CPropertyRestriction" ) ;
 break ;
 }
 case RTCoerce_Add : case RTCoerce_Multiply : case RTCoerce_Absolute : {
 v -> u . RTCoerce_Add = EP_ALLOC ( struct CCoercionRestriction ) ;
 offset = parse_CCoercionRestriction ( tvb , pinfo , offset , tree , pad_tree , v -> u . RTCoerce_Add , "CCoercionRestriction" ) ;
 break ;
 }
 case RTContent : {
 v -> u . RTContent = EP_ALLOC ( struct CContentRestriction ) ;
 offset = parse_CContentRestriction ( tvb , offset , tree , pad_tree , v -> u . RTContent , "CContentRestriction" ) ;
 break ;
 }
 case RTReuseWhere : {
 v -> u . RTReuseWhere = EP_ALLOC ( struct CReuseWhere ) ;
 offset = parse_CReuseWhere ( tvb , offset , tree , pad_tree , v -> u . RTReuseWhere , "CReuseWhere" ) ;
 break ;
 }
 case RTNatLanguage : {
 v -> u . RTNatLanguage = EP_ALLOC ( struct CNatLanguageRestriction ) ;
 offset = parse_CNatLanguageRestriction ( tvb , offset , tree , pad_tree , v -> u . RTNatLanguage , "CNatLanguageRestriction" ) ;
 break ;
 }
 default : proto_item_append_text ( item , " Not supported!" ) ;
 }
 proto_item_set_end ( item , tvb , offset ) ;
 return offset ;
 }