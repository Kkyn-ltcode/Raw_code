static inline void set_myanmar_properties ( hb_glyph_info_t & info ) {
 hb_codepoint_t u = info . codepoint ;
 unsigned int type = hb_indic_get_categories ( u ) ;
 indic_category_t cat = ( indic_category_t ) ( type & 0x7Fu ) ;
 indic_position_t pos = ( indic_position_t ) ( type >> 8 ) ;
 if ( unlikely ( hb_in_range ( u , 0xFE00u , 0xFE0Fu ) ) ) cat = ( indic_category_t ) OT_VS ;
 switch ( u ) {
 case 0x104Eu : cat = ( indic_category_t ) OT_C ;
 break ;
 case 0x002Du : case 0x00A0u : case 0x00D7u : case 0x2012u : case 0x2013u : case 0x2014u : case 0x2015u : case 0x2022u : case 0x25CCu : case 0x25FBu : case 0x25FCu : case 0x25FDu : case 0x25FEu : cat = ( indic_category_t ) OT_GB ;
 break ;
 case 0x1004u : case 0x101Bu : case 0x105Au : cat = ( indic_category_t ) OT_Ra ;
 break ;
 case 0x1032u : case 0x1036u : cat = ( indic_category_t ) OT_A ;
 break ;
 case 0x103Au : cat = ( indic_category_t ) OT_As ;
 break ;
 case 0x1041u : case 0x1042u : case 0x1043u : case 0x1044u : case 0x1045u : case 0x1046u : case 0x1047u : case 0x1048u : case 0x1049u : case 0x1090u : case 0x1091u : case 0x1092u : case 0x1093u : case 0x1094u : case 0x1095u : case 0x1096u : case 0x1097u : case 0x1098u : case 0x1099u : cat = ( indic_category_t ) OT_D ;
 break ;
 case 0x1040u : cat = ( indic_category_t ) OT_D ;
 break ;
 case 0x103Eu : case 0x1060u : cat = ( indic_category_t ) OT_MH ;
 break ;
 case 0x103Cu : cat = ( indic_category_t ) OT_MR ;
 break ;
 case 0x103Du : case 0x1082u : cat = ( indic_category_t ) OT_MW ;
 break ;
 case 0x103Bu : case 0x105Eu : case 0x105Fu : cat = ( indic_category_t ) OT_MY ;
 break ;
 case 0x1063u : case 0x1064u : case 0x1069u : case 0x106Au : case 0x106Bu : case 0x106Cu : case 0x106Du : case 0xAA7Bu : cat = ( indic_category_t ) OT_PT ;
 break ;
 case 0x1038u : case 0x1087u : case 0x1088u : case 0x1089u : case 0x108Au : case 0x108Bu : case 0x108Cu : case 0x108Du : case 0x108Fu : case 0x109Au : case 0x109Bu : case 0x109Cu : cat = ( indic_category_t ) OT_SM ;
 break ;
 case 0x104Au : case 0x104Bu : cat = ( indic_category_t ) OT_P ;
 break ;
 }
 if ( cat == OT_M ) {
 switch ( ( int ) pos ) {
 case POS_PRE_C : cat = ( indic_category_t ) OT_VPre ;
 pos = POS_PRE_M ;
 break ;
 case POS_ABOVE_C : cat = ( indic_category_t ) OT_VAbv ;
 break ;
 case POS_BELOW_C : cat = ( indic_category_t ) OT_VBlw ;
 break ;
 case POS_POST_C : cat = ( indic_category_t ) OT_VPst ;
 break ;
 }
 }
 info . myanmar_category ( ) = ( myanmar_category_t ) cat ;
 info . myanmar_position ( ) = pos ;
 }