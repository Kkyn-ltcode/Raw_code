static size_t vmxnet_tx_pkt_fetch_fragment ( struct VmxnetTxPkt * pkt , int * src_idx , size_t * src_offset , struct iovec * dst , int * dst_idx ) {
 size_t fetched = 0 ;
 struct iovec * src = pkt -> vec ;
 * dst_idx = VMXNET_TX_PKT_FRAGMENT_HEADER_NUM ;
 while ( fetched < pkt -> virt_hdr . gso_size ) {
 if ( * dst_idx == VMXNET_MAX_FRAG_SG_LIST ) {
 break ;
 }
 if ( * src_idx == ( pkt -> payload_frags + VMXNET_TX_PKT_PL_START_FRAG ) ) {
 break ;
 }
 dst [ * dst_idx ] . iov_base = src [ * src_idx ] . iov_base + * src_offset ;
 dst [ * dst_idx ] . iov_len = MIN ( src [ * src_idx ] . iov_len - * src_offset , pkt -> virt_hdr . gso_size - fetched ) ;
 * src_offset += dst [ * dst_idx ] . iov_len ;
 fetched += dst [ * dst_idx ] . iov_len ;
 if ( * src_offset == src [ * src_idx ] . iov_len ) {
 * src_offset = 0 ;
 ( * src_idx ) ++ ;
 }
 ( * dst_idx ) ++ ;
 }
 return fetched ;
 }