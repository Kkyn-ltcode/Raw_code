static int dissect_pbb_addressblock ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , guint offset , guint maxoffset , guint8 addressType , guint8 addressSize ) {
 guint8 addr [ MAX_ADDR_SIZE ] ;
 guint8 numAddr ;
 guint8 address_flags ;
 guint8 head_length = 0 , tail_length = 0 ;
 guint block_length = 0 , midSize = 0 ;
 guint block_index = 0 , head_index = 0 , tail_index = 0 , mid_index = 0 , prefix_index = 0 ;
 proto_tree * addr_tree = NULL ;
 proto_tree * addrFlags_tree = NULL ;
 proto_tree * addrValue_tree = NULL ;
 proto_item * addr_item = NULL ;
 proto_item * addrFlags_item = NULL ;
 proto_item * addrValue_item = NULL ;
 int i = 0 ;
 if ( maxoffset - offset < 2 ) {
 proto_tree_add_expert_format ( tree , pinfo , & ei_packetbb_error , tvb , offset , maxoffset - offset , "Not enough octets for minimal addressblock header" ) ;
 return tvb_reported_length ( tvb ) ;
 }
 DISSECTOR_ASSERT ( addressSize <= MAX_ADDR_SIZE ) ;
 memset ( addr , 0 , addressSize ) ;
 block_length = 2 ;
 block_index = offset ;
 midSize = addressSize ;
 numAddr = tvb_get_guint8 ( tvb , offset ++ ) ;
 address_flags = tvb_get_guint8 ( tvb , offset ++ ) ;
 if ( ( address_flags & ADDR_HASHEAD ) != 0 ) {
 head_index = offset ;
 if ( maxoffset - offset <= 0 ) {
 proto_tree_add_expert_format ( tree , pinfo , & ei_packetbb_error , tvb , offset , maxoffset - offset , "Not enough octets for addressblock head" ) ;
 return tvb_reported_length ( tvb ) ;
 }
 head_length = tvb_get_guint8 ( tvb , offset ++ ) ;
 if ( head_length > addressSize - 1 ) {
 proto_tree_add_expert_format ( tree , pinfo , & ei_packetbb_error , tvb , offset , maxoffset - offset , "address head length is too long" ) ;
 return tvb_reported_length ( tvb ) ;
 }
 if ( maxoffset - offset < head_length ) {
 proto_tree_add_expert_format ( tree , pinfo , & ei_packetbb_error , tvb , offset , maxoffset - offset , "Not enough octets for addressblock head" ) ;
 return tvb_reported_length ( tvb ) ;
 }
 tvb_memcpy ( tvb , addr , offset , head_length ) ;
 midSize -= head_length ;
 block_length += ( head_length + 1 ) ;
 offset += head_length ;
 }
 if ( ( address_flags & ADDR_HASZEROTAIL ) != 0 ) {
 tail_index = offset ;
 if ( maxoffset - offset <= 0 ) {
 proto_tree_add_expert_format ( tree , pinfo , & ei_packetbb_error , tvb , offset , maxoffset - offset , "Not enough octets for addressblock tail" ) ;
 return tvb_reported_length ( tvb ) ;
 }
 tail_length = tvb_get_guint8 ( tvb , offset ++ ) ;
 if ( tail_length > addressSize - 1 - head_length ) {
 proto_tree_add_expert_format ( tree , pinfo , & ei_packetbb_error , tvb , offset , maxoffset - offset , "address tail length is too long" ) ;
 return tvb_reported_length ( tvb ) ;
 }
 midSize -= tail_length ;
 block_length ++ ;
 }
 else if ( ( address_flags & ADDR_HASFULLTAIL ) != 0 ) {
 tail_index = offset ;
 if ( maxoffset - offset <= 0 ) {
 proto_tree_add_expert_format ( tree , pinfo , & ei_packetbb_error , tvb , offset , maxoffset - offset , "Not enough octets for addressblock tail" ) ;
 return tvb_reported_length ( tvb ) ;
 }
 tail_length = tvb_get_guint8 ( tvb , offset ++ ) ;
 if ( tail_length > addressSize - 1 - head_length ) {
 proto_tree_add_expert_format ( tree , pinfo , & ei_packetbb_error , tvb , offset , maxoffset - offset , "address tail length is too long" ) ;
 return tvb_reported_length ( tvb ) ;
 }
 if ( maxoffset - offset < tail_length ) {
 proto_tree_add_expert_format ( tree , pinfo , & ei_packetbb_error , tvb , offset , maxoffset - offset , "Not enough octets for addressblock tail" ) ;
 return tvb_reported_length ( tvb ) ;
 }
 tvb_memcpy ( tvb , & addr [ addressSize - tail_length ] , offset , tail_length ) ;
 midSize -= tail_length ;
 block_length += ( tail_length + 1 ) ;
 offset += tail_length ;
 }
 mid_index = offset ;
 block_length += numAddr * midSize ;
 offset += numAddr * midSize ;
 if ( ( address_flags & ADDR_HASSINGLEPRELEN ) != 0 ) {
 prefix_index = offset ;
 block_length ++ ;
 }
 else if ( ( address_flags & ADDR_HASMULTIPRELEN ) != 0 ) {
 prefix_index = offset ;
 block_length += numAddr ;
 }
 if ( maxoffset < block_index + block_length ) {
 proto_tree_add_expert_format ( tree , pinfo , & ei_packetbb_error , tvb , offset , maxoffset - offset , "Not enough octets for address block" ) ;
 return maxoffset ;
 }
 addr_item = proto_tree_add_item ( tree , hf_packetbb_addr , tvb , block_index , block_length , ENC_NA ) ;
 addr_tree = proto_item_add_subtree ( addr_item , ett_packetbb_addr ) ;
 proto_item_append_text ( addr_item , " (%d addresses)" , numAddr ) ;
 proto_tree_add_item ( addr_tree , hf_packetbb_addr_num , tvb , block_index , 1 , ENC_BIG_ENDIAN ) ;
 addrFlags_item = proto_tree_add_item ( addr_tree , hf_packetbb_addr_flags , tvb , block_index + 1 , 1 , ENC_BIG_ENDIAN ) ;
 addrFlags_tree = proto_item_add_subtree ( addrFlags_item , ett_packetbb_addr_flags ) ;
 proto_tree_add_item ( addrFlags_tree , hf_packetbb_addr_flags_hashead , tvb , block_index + 1 , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( addrFlags_tree , hf_packetbb_addr_flags_hasfulltail , tvb , block_index + 1 , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( addrFlags_tree , hf_packetbb_addr_flags_haszerotail , tvb , block_index + 1 , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( addrFlags_tree , hf_packetbb_addr_flags_hassingleprelen , tvb , block_index + 1 , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( addrFlags_tree , hf_packetbb_addr_flags_hasmultiprelen , tvb , block_index + 1 , 1 , ENC_BIG_ENDIAN ) ;
 if ( ( address_flags & ADDR_HASHEAD ) != 0 ) {
 proto_tree_add_item ( addr_tree , hf_packetbb_addr_head , tvb , head_index , head_length + 1 , ENC_NA ) ;
 }
 if ( ( address_flags & ADDR_HASFULLTAIL ) != 0 ) {
 proto_tree_add_item ( addr_tree , hf_packetbb_addr_tail , tvb , tail_index , tail_length + 1 , ENC_NA ) ;
 }
 else if ( ( address_flags & ADDR_HASZEROTAIL ) != 0 ) {
 proto_tree_add_item ( addr_tree , hf_packetbb_addr_tail , tvb , tail_index , 1 , ENC_NA ) ;
 }
 for ( i = 0 ;
 i < numAddr ;
 i ++ ) {
 guint32 ipv4 = 0 ;
 guint8 prefix = addressSize * 8 ;
 tvb_memcpy ( tvb , & addr [ head_length ] , mid_index + midSize * i , midSize ) ;
 ipv4 = ( addr [ 3 ] << 24 ) + ( addr [ 2 ] << 16 ) + ( addr [ 1 ] << 8 ) + addr [ 0 ] ;
 switch ( addressType ) {
 case 0 : addrValue_item = proto_tree_add_ipv4 ( addr_tree , hf_packetbb_addr_value [ addressType ] , tvb , mid_index , block_index + block_length - mid_index , ipv4 ) ;
 break ;
 case 1 : addrValue_item = proto_tree_add_ipv6 ( addr_tree , hf_packetbb_addr_value [ addressType ] , tvb , mid_index , block_index + block_length - mid_index , ( struct e_in6_addr * ) addr ) ;
 break ;
 case 2 : addrValue_item = proto_tree_add_ether ( addr_tree , hf_packetbb_addr_value [ addressType ] , tvb , mid_index , block_index + block_length - mid_index , addr ) ;
 break ;
 case 3 : addrValue_item = proto_tree_add_bytes ( addr_tree , hf_packetbb_addr_value [ addressType ] , tvb , mid_index , block_index + block_length - mid_index , addr ) ;
 break ;
 default : break ;
 }
 addrValue_tree = proto_item_add_subtree ( addrValue_item , ett_packetbb_addr_value ) ;
 proto_tree_add_item ( addrValue_tree , hf_packetbb_addr_value_mid , tvb , mid_index + midSize * i , midSize , ENC_NA ) ;
 if ( ( address_flags & ADDR_HASSINGLEPRELEN ) != 0 ) {
 prefix = tvb_get_guint8 ( tvb , prefix_index ) ;
 proto_tree_add_item ( addrValue_tree , hf_packetbb_addr_value_prefix , tvb , prefix_index , 1 , ENC_BIG_ENDIAN ) ;
 }
 else if ( ( address_flags & ADDR_HASMULTIPRELEN ) != 0 ) {
 prefix = tvb_get_guint8 ( tvb , prefix_index + i ) ;
 proto_tree_add_item ( addrValue_tree , hf_packetbb_addr_value_prefix , tvb , prefix_index + i , 1 , ENC_BIG_ENDIAN ) ;
 }
 proto_item_append_text ( addrValue_item , "/%d" , prefix ) ;
 }
 offset = dissect_pbb_tlvblock ( tvb , pinfo , addr_tree , block_index + block_length , maxoffset , numAddr , TLV_CAT_ADDRESS ) ;
 return offset ;
 }