static struct sock * udp6_lib_lookup2 ( struct net * net , const struct in6_addr * saddr , __be16 sport , const struct in6_addr * daddr , unsigned int hnum , int dif , struct udp_hslot * hslot2 , unsigned int slot2 ) {
 struct sock * sk , * result ;
 struct hlist_nulls_node * node ;
 int score , badness ;
 begin : result = NULL ;
 badness = - 1 ;
 udp_portaddr_for_each_entry_rcu ( sk , node , & hslot2 -> head ) {
 score = compute_score2 ( sk , net , saddr , sport , daddr , hnum , dif ) ;
 if ( score > badness ) {
 result = sk ;
 badness = score ;
 if ( score == SCORE2_MAX ) goto exact_match ;
 }
 }
 if ( get_nulls_value ( node ) != slot2 ) goto begin ;
 if ( result ) {
 exact_match : if ( unlikely ( ! atomic_inc_not_zero ( & result -> sk_refcnt ) ) ) result = NULL ;
 else if ( unlikely ( compute_score2 ( result , net , saddr , sport , daddr , hnum , dif ) < badness ) ) {
 sock_put ( result ) ;
 goto begin ;
 }
 }
 return result ;
 }