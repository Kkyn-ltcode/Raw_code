static void dump_ah_combs ( struct sk_buff * skb , const struct xfrm_tmpl * t ) {
 struct sadb_prop * p ;
 int i ;
 p = ( struct sadb_prop * ) skb_put ( skb , sizeof ( struct sadb_prop ) ) ;
 p -> sadb_prop_len = sizeof ( struct sadb_prop ) / 8 ;
 p -> sadb_prop_exttype = SADB_EXT_PROPOSAL ;
 p -> sadb_prop_replay = 32 ;
 memset ( p -> sadb_prop_reserved , 0 , sizeof ( p -> sadb_prop_reserved ) ) ;
 for ( i = 0 ;
 ;
 i ++ ) {
 const struct xfrm_algo_desc * aalg = xfrm_aalg_get_byidx ( i ) ;
 if ( ! aalg ) break ;
 if ( ! aalg -> pfkey_supported ) continue ;
 if ( aalg_tmpl_set ( t , aalg ) && aalg -> available ) {
 struct sadb_comb * c ;
 c = ( struct sadb_comb * ) skb_put ( skb , sizeof ( struct sadb_comb ) ) ;
 memset ( c , 0 , sizeof ( * c ) ) ;
 p -> sadb_prop_len += sizeof ( struct sadb_comb ) / 8 ;
 c -> sadb_comb_auth = aalg -> desc . sadb_alg_id ;
 c -> sadb_comb_auth_minbits = aalg -> desc . sadb_alg_minbits ;
 c -> sadb_comb_auth_maxbits = aalg -> desc . sadb_alg_maxbits ;
 c -> sadb_comb_hard_addtime = 24 * 60 * 60 ;
 c -> sadb_comb_soft_addtime = 20 * 60 * 60 ;
 c -> sadb_comb_hard_usetime = 8 * 60 * 60 ;
 c -> sadb_comb_soft_usetime = 7 * 60 * 60 ;
 }
 }
 }