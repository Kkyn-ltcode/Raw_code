static int virtio_net_init_pci ( PCIDevice * pci_dev ) {
 VirtIOPCIProxy * proxy = DO_UPCAST ( VirtIOPCIProxy , pci_dev , pci_dev ) ;
 VirtIODevice * vdev ;
 vdev = virtio_net_init ( & pci_dev -> qdev , & proxy -> nic ) ;
 vdev -> nvectors = proxy -> nvectors ;
 virtio_init_pci ( proxy , vdev , PCI_VENDOR_ID_REDHAT_QUMRANET , PCI_DEVICE_ID_VIRTIO_NET , PCI_CLASS_NETWORK_ETHERNET , 0x00 ) ;
 proxy -> nvectors = vdev -> nvectors ;
 return 0 ;
 }