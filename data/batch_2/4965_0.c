void vmxnet_tx_pkt_setup_vlan_header ( struct VmxnetTxPkt * pkt , uint16_t vlan ) {
 bool is_new ;
 assert ( pkt ) ;
 eth_setup_vlan_headers ( pkt -> vec [ VMXNET_TX_PKT_L2HDR_FRAG ] . iov_base , vlan , & is_new ) ;
 if ( is_new ) {
 pkt -> hdr_len += sizeof ( struct vlan_header ) ;
 pkt -> vec [ VMXNET_TX_PKT_L2HDR_FRAG ] . iov_len += sizeof ( struct vlan_header ) ;
 }
 }