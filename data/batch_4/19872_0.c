static int evdns_server_request_format_response ( struct server_request * req , int err ) {
 unsigned char buf [ 1500 ] ;
 size_t buf_len = sizeof ( buf ) ;
 off_t j = 0 , r ;
 u16 _t ;
 u32 _t32 ;
 int i ;
 u16 flags ;
 struct dnslabel_table table ;
 if ( err < 0 || err > 15 ) return - 1 ;
 flags = req -> base . flags ;
 flags |= ( 0x8000 | err ) ;
 dnslabel_table_init ( & table ) ;
 APPEND16 ( req -> trans_id ) ;
 APPEND16 ( flags ) ;
 APPEND16 ( req -> base . nquestions ) ;
 APPEND16 ( req -> n_answer ) ;
 APPEND16 ( req -> n_authority ) ;
 APPEND16 ( req -> n_additional ) ;
 for ( i = 0 ;
 i < req -> base . nquestions ;
 ++ i ) {
 const char * s = req -> base . questions [ i ] -> name ;
 j = dnsname_to_labels ( buf , buf_len , j , s , strlen ( s ) , & table ) ;
 if ( j < 0 ) {
 dnslabel_clear ( & table ) ;
 return ( int ) j ;
 }
 APPEND16 ( req -> base . questions [ i ] -> type ) ;
 APPEND16 ( req -> base . questions [ i ] -> dns_question_class ) ;
 }
 for ( i = 0 ;
 i < 3 ;
 ++ i ) {
 struct server_reply_item * item ;
 if ( i == 0 ) item = req -> answer ;
 else if ( i == 1 ) item = req -> authority ;
 else item = req -> additional ;
 while ( item ) {
 r = dnsname_to_labels ( buf , buf_len , j , item -> name , strlen ( item -> name ) , & table ) ;
 if ( r < 0 ) goto overflow ;
 j = r ;
 APPEND16 ( item -> type ) ;
 APPEND16 ( item -> dns_question_class ) ;
 APPEND32 ( item -> ttl ) ;
 if ( item -> is_name ) {
 off_t len_idx = j , name_start ;
 j += 2 ;
 name_start = j ;
 r = dnsname_to_labels ( buf , buf_len , j , item -> data , strlen ( item -> data ) , & table ) ;
 if ( r < 0 ) goto overflow ;
 j = r ;
 _t = htons ( ( short ) ( j - name_start ) ) ;
 memcpy ( buf + len_idx , & _t , 2 ) ;
 }
 else {
 APPEND16 ( item -> datalen ) ;
 if ( j + item -> datalen > ( off_t ) buf_len ) goto overflow ;
 memcpy ( buf + j , item -> data , item -> datalen ) ;
 j += item -> datalen ;
 }
 item = item -> next ;
 }
 }
 if ( j > 512 ) {
 overflow : j = 512 ;
 buf [ 2 ] |= 0x02 ;
 }
 req -> response_len = j ;
 if ( ! ( req -> response = malloc ( req -> response_len ) ) ) {
 server_request_free_answers ( req ) ;
 dnslabel_clear ( & table ) ;
 return ( - 1 ) ;
 }
 memcpy ( req -> response , buf , req -> response_len ) ;
 server_request_free_answers ( req ) ;
 dnslabel_clear ( & table ) ;
 return ( 0 ) ;
 }